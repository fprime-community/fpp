package fpp.compiler

import fpp.compiler.analysis._
import fpp.compiler.ast._
import fpp.compiler.codegen._
import fpp.compiler.syntax._
import fpp.compiler.transform._
import fpp.compiler.util._
import scopt.OParser

object FPPtoJson {
  case class Options(
      syntax: Boolean = false,
      dir: Option[String] = None,
      files: List[File] = List()
  )

  def command(options: Options) = {
    fpp.compiler.util.Error.setTool(Tool(name))
    val files = options.files.reverse match {
      case Nil  => List(File.StdIn)
      case list => list
    }
    val result = Result.seq(
      Result.map(files, Parser.parseFile(Parser.transUnit)(None) _),
      List(resolveIncludes _, writeJson(options) _, writeAnalysis(options) _)
    )
    result match {
      case Left(error) => {
        error.print
        System.exit(1)
      }
      case Right(_) => ()
    }
  }

  def main(args: Array[String]) = {
    val options = OParser.parse(oparser, args, Options())
    options match {
      case Some(options) => command(options)
      case None          => ()
    }
  }

  def writeJson(
      options: Options
  )(tul: List[Ast.TransUnit]): Result.Result[List[Ast.TransUnit]] = {
    val encoder = JsonEncoder(tul = tul)
    val astPath =
      java.nio.file.Paths.get(options.dir.getOrElse("."), "fpp-ast.json")
    val locPath =
      java.nio.file.Paths.get(options.dir.getOrElse("."), "fpp-loc-map.json")
    val astFile = File.Path(astPath)
    val locFile = File.Path(locPath)
    for {
      astWriter <- astFile.openWrite()
      locWriter <- locFile.openWrite()
    } yield {
      astWriter.println(encoder.printAstJson())
      locWriter.println(encoder.printLocationsMapJson())
      astWriter.close()
      locWriter.close()
    }

    Right(tul)
  }

  def writeAnalysis(options: Options)(tul: List[Ast.TransUnit]): Result.Result[List[Ast.TransUnit]] = {

    val analysisPath =
      java.nio.file.Paths.get(options.dir.getOrElse("."), "fpp-analysis.json")

    val analysis = Analysis(inputFileSet = options.files.toSet)
    val files = options.files.reverse match {
      case Nil  => List(File.StdIn)
      case list => list
    }

    val result: Either[fpp.compiler.util.Error, fpp.compiler.analysis.Analysis] =
      for {
        analysis <- CheckSemantics.tuList(analysis, tul)
      } yield analysis

    result match {
      case Right(a)   => {
        val encoder: JsonEncoder = JsonEncoder(analysis = a)
        options.syntax match {
          case false => {
            val analysisFile = File.Path(analysisPath)
            for {
              writer <- analysisFile.openWrite()
            } yield {
              writer.println(encoder.printAnalysisJson())
              writer.close()
            }

          }
          case true => ()
        }
        Right(tul)
      }
      case Left(error) => {
        Left(error)
      }
    }
    
  }

  def resolveIncludes(
      tul: List[Ast.TransUnit]
  ): Result.Result[List[Ast.TransUnit]] = {
    for {
      result <- ResolveSpecInclude.transformList(
        Analysis(),
        tul,
        ResolveSpecInclude.transUnit
      )
    } yield result._2

  }

  val builder = OParser.builder[Options]

  val name = "fpp-to-json"

  val oparser = {
    import builder._
    OParser.sequence(
      programName(name),
      head(name, Version.v),
      opt[Unit]('s', "syntax")
        .action((_, c) => c.copy(syntax = true))
        .text("omit the analysis data structure"),
      opt[String]('d', "directory")
        .valueName("<dir>")
        .action((d, c) => c.copy(dir = Some(d)))
        .text("output directory"),
      help('h', "help").text("print this message and exit"),
      arg[String]("file ...")
        .unbounded()
        .optional()
        .action((f, c) => c.copy(files = File.fromString(f) :: c.files))
        .text("input files")
    )
  }

}