#!/bin/sh -e

# ----------------------------------------------------------------------
# clean.do
# ----------------------------------------------------------------------

rm -f fpp-spec.adoc *.html *.pdf *~ *.bak \
  defined-tags.txt used-tags.txt \
  undefined-tags.txt undefined-tags.annotated.txt \
  keywords.txt
rm -rf code-prettify
targets=`find . -mindepth 2 -name clean.do | sed 's/\.do$//'`
redo $targets
