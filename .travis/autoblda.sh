#!mupfel

#
# a mupfel script, executed inside ARAnyM
#

set -e

cd C:\src\magicmac
export PATH="${PWD}\pc,${PATH}"
echo "%033v%c"

pcmake -B -F tools/all.prj
pcmake -B -F test/all.prj
pcmake -B -F apps/all.prj
pcmake -B -F extensio/all.prj

#
# pdlg currently has to be build separately, because
# we need different localizations for it
#
cd extensio\pdlg_slb
# english
export PCCFLAGS=-DCOUNTRY=0
pcmake -B -F pdlg_slb.prj
mv pdlg.slb en
# french
export PCCFLAGS=-DCOUNTRY=2
pcmake -B -F pdlg_slb.prj
mv pdlg.slb fr
# german
export PCCFLAGS=-DCOUNTRY=1
pcmake -B -F pdlg_slb.prj
mv pdlg.slb de
unset PCCFLAGS

cd ..\..

#
# now wdialog
#
cd kernel\aes\wdialog

# english
export PCCFLAGS=-DCOUNTRY=0
pcmake -B -F wdialog.prj
mv wdialog.prg en

# french
export PCCFLAGS=-DCOUNTRY=2
pcmake -B -F wdialog.prj
mv wdialog.prg fr

# german
export PCCFLAGS=-DCOUNTRY=1
pcmake -B -F wdialog.prj
mv wdialog.prg de

unset PCCFLAGS

cd ..\..\..

set +e
