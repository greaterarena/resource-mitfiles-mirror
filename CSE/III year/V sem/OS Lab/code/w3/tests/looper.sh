#!/bin/bash

X=0
echo do while loop 
echo
while [ $X -le 5 ]
do
	echo -n "$X " 
	X=$((X+1))
done
echo

echo until loop 
yy=1
until [ $yy – 3 ]
do
	echo -n "$yy "
	yy=$((yy+1))
done
