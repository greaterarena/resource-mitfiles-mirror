#!/bin/bash

v=`ps -A | grep bash`

w=`expr substr "$v" 1 5`

echo $w

exit 0
