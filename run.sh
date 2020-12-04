#!/bin/sh

[ -f ./build/head-sim ] || ./build.sh
./build/head-sim
