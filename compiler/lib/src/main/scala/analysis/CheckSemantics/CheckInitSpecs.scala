package fpp.compiler.analysis

import fpp.compiler.ast._
import fpp.compiler.util._

/** Check init specifiers */
object CheckInitSpecs
  extends Analyzer 
  with ModuleAnalyzer
{

  override def specInitAnnotatedNode(
    a: Analysis,
    aNode: Ast.Annotated[AstNode[Ast.SpecInit]]
  ) = for {
    is <- InitSpecifier.fromNode(a, aNode)
    map <- {
      val map1 = a.initSpecifierMap.getOrElse(is.instance, Map())
      map1.get(is.phase) match {
        case Some(prevIs) =>
          val loc = is.getLoc
          val prevLoc = prevIs.getLoc
          Left(
            SemanticError.DuplicateInitSpecifier(
              is.phase,
              loc,
              prevLoc
            )
          )
        case None => {
          val map2 = map1 + (is.phase -> is)
          Right(a.initSpecifierMap + (is.instance -> map2))
        }
      }
    }
  }
  yield a.copy(initSpecifierMap = map)

}
