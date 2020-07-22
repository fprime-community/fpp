#!/bin/sh -e

# ----------------------------------------------------------------------
# fpp-users-guide.adoc.do
# ----------------------------------------------------------------------

. ./defs.sh

redo-ifchange $FILES

echo "= The F Prime Prime (FPP) User's Guide
:toc: left
:toclevels: 3
:stem:
:source-highlighter: prettify"
for file in $FILES
do
  echo
  cat $file
done | awk -f tags.awk
