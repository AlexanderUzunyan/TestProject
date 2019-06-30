#!/bin/bash
#

module load root/root-6.10.08-SL7-x64-cuda-7.5

if [ "0$(echo $LD_LIBRARY_PATH | grep $PWD/lib)" == "0" ]; then
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/lib 
export PATH=$PATH:$PWD/bin  
fi
