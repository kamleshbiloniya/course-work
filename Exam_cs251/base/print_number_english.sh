#!/bin/bash

echo Enter a valid Number:
print_case(){
digit=$1
case "$digit" in
	00)echo -n " ";;
0)echo -n " ";;
01 | 1) echo -n "one ";;
02 | 2) echo -n "two ";;
03 | 3) echo -n "three ";;
04 | 4) echo -n "four ";;
05 | 5) echo -n "five ";;
06 | 6) echo -n "six ";;
07 | 7)echo -n "seven ";;
08 | 8)echo -n "eight ";;
09 | 9)echo -n "nine ";;
10)echo -n "ten ";;
11)echo -n "elven ";;
12)echo -n "twelve ";; 	
13)echo -n "thirteen ";;
14)echo -n "fourteen ";;
15)echo -n "fifteen ";;
16)echo -n "sixteen ";;
17)echo -n "seventeen ";;
18)echo -n "eignteen ";;
19)echo -n "nineteen ";;
20)echo -n "twienty ";;
30)echo -n "thirty ";;
40)echo -n "fourty ";;
50)echo -n "fifty ";;
60)echo -n "sixty ";;
70)echo -n "seventy ";;
80)echo -n "eighty ";;
90)echo -n "ninety ";;
100)echo -n "hundered ";;
1000)echo -n "thousand ";;
100000)echo -n "lakh ";;
10000000)echo -n "crore ";;
esac
}

ln_one(){
num1=$1
if [[ $num1 -ne 0 ]]
then
print_case $num1
else
	echo " "
fi
}

ln_two(){
num2=$1
a=$(($num2/10))
b=$(($num2%10))
if [[ $num2 -eq 00 ]]   # & [[ $b -eq 0 ]]
then
 echo " "
 
elif [[ $a -eq 0 ]] 
then
	print_case $b
elif [[ $b -eq 0 ]] 
then 
	print_case $num2

elif [[ $a -lt 2 ]]
then print_case $num2
else
	a=$(($a*10))
	print_case $a
	print_case $b
fi
}

ln_three(){
num3=$1
	c=$(($num3/100))
	d=$(($num3%100))
	if [[ $c -ne 0 ]]
	then
	ln_one $c
	print_case 100
	ln_two $d
else
	ln_two $d
fi
}

ln_four(){
num4=$1
	e=$(($num4/1000))
	f=$(($num4%1000))
	if [[ $e -ne 0 ]]
	then
	ln_one $e
	print_case 1000
	ln_three $f
else
	ln_three $f
fi
}

ln_five(){
num5=$1
 	g=$(($num5/1000))
	h=$(($num5%1000))
	if [[ $g -ne 00 ]]
	then
	ln_two $g
	print_case 1000
	ln_three $h
else
	ln_three $h
fi
}
ln_six(){
	num6=$1
	i=$(($num6/100000))
	j=$(($num6%100000))
	if [[ $i -ne 0 ]]
	then
	ln_one $i
	print_case 100000
	ln_five $j
else
	ln_five $j
fi
}
ln_seven(){
num7=$1
	k=$(($num7/100000))
	l=$(($num7%100000))
	if [[ $k -ne 00 ]]
	then
	ln_two $k
	print_case 100000
	ln_five $l
else
	ln_five $l
fi

}
ln_gt_seven(){
num=$1

	x=$(($num/10000000))
	y=$(($num%10000000))
	
	
       
len1=$(echo $x | wc -c)
len1=$(($len1-1))
          case "$len1" in
		 1) ln_one $x;;
	 	 2) ln_two $x;;
		 3) ln_three $x;;
		  4) ln_four $x;;
		 5) ln_five $x;;
		 6) ln_six $x;;
		 7) ln_seven $x;;																	   *) echo number is too big !!!
 	esac
	print_case 10000000
	ln_seven $y
}

read n

if [[ $n = *[!0-9]* ]]; then

	   echo "Invalid Input"
   else 
	  len=$(echo $n | wc -c)
	  len=$(($len-1))
	  case "$len" in
		  1) ln_one $n;;
		  2) ln_two $n;;
		  3) ln_three $n;;
		  4) ln_four $n;;
		  5) ln_five $n;;
		  6) ln_six $n;;
		  7) ln_seven $n;;
		  *) ln_gt_seven $n;;
  esac
  fi






