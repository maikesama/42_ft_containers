#!/bin/sh

g++ -Wall -Werror -Wextra mySTL.cpp && ./a.out > mySTL_output.txt
g++ -Wall -Werror -Wextra realSTL.cpp && ./a.out > realSTL_output.txt
rm a.out
$(diff mySTL_output.txt realSTL_output.txt)
if [ $? == 0 ]
then
	echo "* STL Test OK *"
else
	echo "* STL Test KO *"
fi
