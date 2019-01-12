#!/bin/sh

#
# This script uses a pre-build image for ARAnyM,
# where Pure-C, GEMINI and a few other tools are installed,
# a custom pcmake tool to build a Pure-C project file from the
# command line, and mtools to access the image
#
export BUILDROOT="${PWD}/.travis/tmp"
export OUT="${PWD}/.travis/out"

mkdir -p "${BUILDROOT}"
mkdir -p "${OUT}"

aranym="${PWD}/.travis/aranym"
aranym="$aranym/usr/bin/aranym-jit"

unset CC CXX

SRCDIR=c:/src/magicmac

clash_option="-D s"
mmd $clash_option $SRCDIR
mcopy $clash_option -bso apps auto doc extensio inc_as inc_c kernel lib non-tos pc test tools $SRCDIR

export SDL_VIDEODRIVER=dummy
export SDL_AUDIODRIVER=dummy

#
# For some unknown reason, linking sometimes
# fails if we do it all in one go,
# so the scripts are split in two parts
#
mdel C:/status.txt
mcopy -o .travis/autobld.sh C:/autobld.sh
"$aranym" -c config-hdd
echo ""
echo "##################################"
echo "error output from emulator run:"
echo "##################################"
mtype C:/errors.txt | grep -v "entering directory"
echo ""
status=`mtype -t C:/status.txt`
test "$status" != "0" && exit 1

#mdel C:/status.txt
#mcopy -o .travis/autobldk.sh C:/autobld.sh
#"$aranym" -c config-hdd
#echo ""
#echo "##################################"
#echo "error output from emulator run:"
#echo "##################################"
#mtype C:/errors.txt | grep -v "entering directory"
#echo ""
#status=`mtype -t C:/status.txt`
#test "$status" != "0" && exit 1

. .travis/mkbindist.sh


isrelease=false
export isrelease

VERSION=`date +%Y%m%d`
ATAG=${VERSION}
BINARCHIVE="${PROJECT_LOWER}-${ATAG}-bin.zip"
SRCARCHIVE="${PROJECT_LOWER}-${ATAG}-src.zip"

export BINARCHIVE
export SRCARCHIVE


(
cd "${BUILDROOT}"
zip -r "${OUT}/${BINARCHIVE}" .
)
git archive --format=zip --prefix=${PROJECT_LOWER}/ HEAD > "${OUT}/${SRCARCHIVE}"
ls -l "${OUT}"
