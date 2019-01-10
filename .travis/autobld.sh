#!mupfel
cd C:\src\magicmac
export PATH="${PWD}\pc,${PATH}"

pcmake -B -F apps/applicat/applicat.prj

nfapi --shutdown
