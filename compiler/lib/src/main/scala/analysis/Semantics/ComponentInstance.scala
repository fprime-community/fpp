package fpp.compiler.analysis

import fpp.compiler.ast._
import fpp.compiler.util._

/** An FPP component instance */
final case class ComponentInstance(
  aNode: Ast.Annotated[AstNode[Ast.DefComponentInstance]],
  qualifiedName: Name.Qualified,
  component: Component,
  baseId: Int,
  maxId: Int,
  file: Option[String],
  queueSize: Option[Int],
  stackSize: Option[Int],
  priority: Option[Int]
) extends Ordered[ComponentInstance] {

  override def toString = qualifiedName.toString

  /** Gets the unqualified name of the component instance */
  def getUnqualifiedName = aNode._2.data.name

  /** Gets the location of the component instance */
  def getLoc: Location = Locations.get(aNode._2.id)

  override def compare(that: ComponentInstance) =
    this.qualifiedName.toString.compare(that.qualifiedName.toString)

}

object ComponentInstance {

  /** Creates a component instance from a component instance definition */
  def fromDefComponentInstance(
    a: Analysis,
    aNode: Ast.Annotated[AstNode[Ast.DefComponentInstance]]
  ): Result.Result[ComponentInstance] = {
    val node = aNode._2
    val data = node.data
    val loc = Locations.get(node.id)
    for {
      component <- a.getComponent(data.component.id)
      componentKind <- Right(component.aNode._2.data.kind)
      baseId <- a.getNonnegativeIntValue(data.baseId.id)
      file <- Right(data.file.map(getFile))
      queueSize <- getQueueSize(
        a,
        data.name,
        loc,
        componentKind,
        data.queueSize
      )
      stackSize <- getStackSizeOrPriority(
        a,
        data.name,
        loc,
        componentKind
      )("stack size", data.stackSize)
      priority <- getStackSizeOrPriority(
        a,
        data.name,
        loc,
        componentKind,
      )("priority", data.priority)
    }
    yield {
      val maxId = baseId + component.getMaxId
      val symbol = Symbol.ComponentInstance(aNode)
      val qualifiedName = a.getQualifiedName(symbol)
      ComponentInstance(
        aNode,
        qualifiedName,
        component,
        baseId,
        maxId,
        file,
        queueSize,
        stackSize,
        priority
      )
    }
  }

  /** Construct an invalid instance error */
  private def invalid(
    name: String,
    loc: Location,
    msg: String
  ) = Left(
    SemanticError.InvalidDefComponentInstance(name, loc, msg)
  )

  /** Gets the file */
  private def getFile(node: AstNode[String]): String = {
    val loc = Locations.get(node.id)
    val javaPath = loc.getRelativePath(node.data)
    File.Path(javaPath).toString
  }
  
  /** Gets the queue size */
  private def getQueueSize(
    a: Analysis,
    name: String,
    loc: Location,
    componentKind: Ast.ComponentKind,
    nodeOpt: Option[AstNode[Ast.Expr]]
  ): Result.Result[Option[Int]] = {
    (componentKind, nodeOpt) match {
      case (Ast.ComponentKind.Passive, Some(node)) => invalid(
        name,
        Locations.get(node.id),
        "passive component may not have queue size"
      )
      case (Ast.ComponentKind.Passive, None) =>
        Right(None)
      case (_, Some(_)) => a.getNonnegativeIntValueOpt(nodeOpt)
      case _ => invalid(
        name,
        loc,
        s"$componentKind component must have queue size"
      )
    }
  }

  /** Get stack size or priority */
  private def getStackSizeOrPriority(
    a: Analysis,
    name: String,
    loc: Location,
    componentKind: Ast.ComponentKind
  )
  (kind: String, nodeOpt: Option[AstNode[Ast.Expr]]):
  Result.Result[Option[Int]] =
    (componentKind, nodeOpt) match {
      case (Ast.ComponentKind.Active, None) => invalid(
        name,
        loc,
        s"active component must have $kind"
      )
      case (Ast.ComponentKind.Active, Some(_)) =>
        a.getNonnegativeIntValueOpt(nodeOpt)
      case (_, None) => Right(None)
      case (_, Some(node)) => invalid(
        name,
        Locations.get(node.id),
        s"$componentKind component may not have $kind"
      )
    }

}
