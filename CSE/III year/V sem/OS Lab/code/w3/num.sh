#!/bin/bash

num=0
echo "Enter a Number"
read num
val=`expr $num \% 2`
if [ $val = 0 ]; then
	echo "The entered number is even"
else
	echo "The entered number is odd"
fi

