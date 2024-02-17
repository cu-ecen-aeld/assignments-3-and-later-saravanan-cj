#!/bin/bash


if [ $# -ne 2 ]; then
	echo "Need to pass 2 arguments path and the content"
	exit 1
fi

filesdir=$1
searchstr=$2

if [ -d $filedir ]; then
	X=$(ls "$filesdir" | wc -l)
	Y=$(grep -r "$searchstr" "$filesdir" | wc -l)
	echo "The number of files are $X and the number of matching lines are $Y"

else
	echo "The input is not a directory on the filesystem"
	exit 1
fi
