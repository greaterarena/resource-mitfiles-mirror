#!/bin/bash

alpha=+
tester=tree


checker() {
	case $tester in
		[rR][eE][aA][dD])
			alpha="$alpha"r
			;;
		[wW][rR][iI][tT][eE])
			alpha="$alpha"w
			;;
		[eE][xX][eE][cC][uU][tT][eE])
			alpha="$alpha"x
			;;
		*)
			echo "ERR::Invalid Permission use - read/write/execute expected"
			exit 0;
		esac
}

if [ $# -lt 3 ]; then
	echo "ERR::Too few arguments"
	exit 0;
fi

case "$1" in
	[aA][dD][dD])
		alpha=+
		;;
	[rR][eE][mM][oO][vV][eE])
		alpha=-
		;;
	*)
		echo "ERR::Invalid parameter \"$1\" add/remove expected"
		exit 0
		;;
esac

case "$#" in
	3)
		tester="$2"
		checker
		chmod $alpha $3 || echo "ERR::File not found"
		;;
	4)	
		if [ $2 = $3 ]; then
			echo "ERR::Same Arguments passed";
			exit 0;
		fi
		tester="$2"
		checker
		tester="$3"
		checker
		chmod $alpha $4 || echo "ERR::File not found"
		;;
	5)	
		if [ $2 = $3 -o $3 = $4 -o $4 = $2 ]; then
			echo "ERR::Same Arguments passed";
			exit 0;
		fi
		tester="$2"
		checker
		tester="$3"
		checker
		tester="$4"
		checker
		chmod $alpha $5 || echo "ERR::File not found"
		;;
	*)
		echo "ERR::Too Many Arguments"
		exit 0
		;;
esac
