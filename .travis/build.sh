#!/bin/sh

#
# actual build script
#
export BUILDROOT="${PWD}/.travis/tmp"
export OUT="${PWD}/.travis/out"

mkdir -p "${BUILDROOT}"
mkdir -p "${OUT}"

aranym="${PWD}/.travis/aranym"
aranym="$aranym/usr/bin/aranym-jit"

unset CC CXX

clash_option="-D s"
mcopy .travis/autobld.sh C:/
mmd $clash_option c:/src/magicmac
mcopy $clash_option -bso apps extensio inc_as inc_c kernel lib non-tos pc test tools c:/src/magicmac

export SDL_VIDEODRIVER=dummy
export SDL_AUDIODRIVER=dummy

"$aranym" -c config-hdd

export ARCHIVE
