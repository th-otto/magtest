#!/bin/sh

echo rvm_autoupdate_flag=0 >> ~/.rvmrc

sudo apt-get update
sudo apt-get install -y \
	curl \
	mtools \

curl --get https://tho-otto.de/download/mag-hdd.tar.bz2 --output mag-hdd.tar.bz2
curl --get https://tho-otto.de/download/aranym-1.0.2-trusty-x86_64-a9de1ec.tar.xz --output aranym.tar.xz

tar xvf mag-hdd.tar.bz2
test -f config-hdd || exit 1

aranym="${PWD}/.travis/aranym"
mkdir "$aranym"
cd "$aranym"
tar xvf ../../aranym.tar.xz
cd ../..

image=hdd.img
offset=1024

echo "drive c: file=\"$PWD/$image\" offset=$offset" > ~/.mtoolsrc
echo "mtools_skip_check=1" >> ~/.mtoolsrc
