#!/bin/bash
for i in $(cat params.txt)
do
  for j in $(cat threads.txt)
  do
    for k in {1..100};
    do
      echo $i" "$j `./app $i $j`
    done
  done
done > file.txt

gnuplot plot.gp
awk 'BEGIN {FS = " "; n=1;m=1; avg=0; sum=0;}; {
  if(NR==1){n=$1;m=$2;sum=$6;}
else if(m!=$2){
    avg=sum/100;

    sum=$6;
     print avg " "n" "m;
     n=$1;
     m=$2;
  }
else{
  sum+=$6;
}
} END {avg=sum/100;
print avg " "n" "m; }' file.txt > avgfile
gnuplot avgplot.gp
