#!/bin/bash
# This script is used by Travis to setup protobuf
# Thanks to https://github.com/mapbox/carmen-cache/blob/master/test/travis-protobuf.sh

set -e

build_dir="$(pwd)"

export PATH="/usr/local/bin:$PATH"
export CXXFLAGS="$CXXFLAGS -fPIC"

PROTOBUF_VERSION=2.6.1
echo 'mkdir'
mkdir protobuf-${PROTOBUF_VERSION}
echo 'wget'
wget https://github.com/google/protobuf/releases/download/v${PROTOBUF_VERSION}/protobuf-${PROTOBUF_VERSION}.tar.bz2 -O protobuf-${PROTOBUF_VERSION}/protobuf-${PROTOBUF_VERSION}.tar.bz2
echo 'tar'
tar xf protobuf-${PROTOBUF_VERSION}/protobuf-${PROTOBUF_VERSION}.tar.bz2 -C protobuf-${PROTOBUF_VERSION}/
echo 'cd'
cd protobuf-${PROTOBUF_VERSION}
echo 'configure'
./configure --enable-static --disable-shared --disable-dependency-tracking
echo 'make'
make -j8
echo 'make install'
sudo make install
echo 'cd'
cd $build_dir