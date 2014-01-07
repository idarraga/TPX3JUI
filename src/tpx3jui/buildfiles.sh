#!/bin/bash
cd ..
echo "--- javac -----------------------------------------------------------"
echo $PWD
javac -verbose ./tpx3jui/SpidrDaqJ.java
ls -lrth tpx3jui
date
echo "--- javah -----------------------------------------------------------"
javah -verbose tpx3jui.SpidrDaqJ
mv *_SpidrDaqJ.h ./tpx3jui

# Stubs not required
#echo "--- javah -stubs ----------------------------------------------------"
#javah -verbose -stubs my.dacs.SpidrDaqJ
#ls -lrth
