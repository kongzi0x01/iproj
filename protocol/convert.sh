#!/bin/sh
file_list=`ls|grep ".proto"`
for file in $file_list
do
	echo protoc $file
	protoc -I./ --cpp_out=./inc/ $file
	protoc -I./ --python_out=./python_inc/ $file
done
