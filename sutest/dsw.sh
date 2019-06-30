#!/bin/bash
#
export ROOTSYS=/cvmfs/sft.cern.ch/lcg/app/releases/ROOT/6.10.08/x86_64-centos7-gcc48-opt/root
export ROOT_DIR=$ROOTSYS
export PATH=$ROOTSYS/bin:$PATH
export LIBRARY_PATH=$ROOTSYS/lib:$LIBRARY_PATH
export LD_LIBRARY_PATH=$ROOTSYS/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$ROOTSYS/lib:$PYTHONPATH
export CPATH=$ROOTSYS/include:$CPATH:$LD_LIBRARY
#
