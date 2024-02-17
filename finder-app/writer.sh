#!/bin/bash

if [ $# -ne 2 ]; then
	echo "Need to pass 2 arguments path and the content"
	exit 1
fi

writefile=$1
writestr=$2

if [ -f $writefile ]; then
	echo "File already exist and can't overwrite it"
	exit 1
else
	mkdir -p "$(dirname "$writefile")"
	echo "$writestr" > $writefile
fi
