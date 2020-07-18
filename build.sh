#!/bin/sh
set -e
. ./header.sh

for PROJECT in $PROJECT; do
    (cd $PROJECT && DESTDIR="$SYSROOT" $MAKE install)
done
