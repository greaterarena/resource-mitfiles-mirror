#!/bin/bash

v1=name
v2="name tree"
echo $v1" | " ${v2}s are green
sdate=${sdate-`date`}
echo $sdate

echo Parameters - $@
echo Parameter Count - $#
sleep 2 &
echo Process ID - $!

echo Read Only Vars
tre=treee
readonly tre
tre="trtr"  | echo "error lol"

echo List Vars
declare -a listy
listy[0]="I"
listy[1]="like"
listy[2]="Linux"
echo Total elements in list - ${#listy[*]}
echo Elements in list - ${listy[*]}

