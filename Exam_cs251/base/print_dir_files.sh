#!/bin/bash

#head=exercise-1B/
#path=$(pwd)
#path+="/"$head
echo Enter Absolute Path:
read path
ln -s $path pt
cd pt

find $pwd | grep "./" > paths

n=$(cat paths | wc -l)
for((i=1; i<=n;i++))
do
cmd=$(sed -n "$i p" paths)
j=$((i+1))
cmd1=$(sed -n "$j p" paths)

total=`grep -Eo "[0-9]{1,10}[.0123456789]*" $cmd 2> /dev/null | wc -l` 
decimal=`grep -Eo "[0-9]{1,10}[.0123456789]*" $cmd 2> /dev/null | grep -Eo "[0-9]{1,9}[.][0-9]{1,10}" 2> /dev/null | wc -l` 
#sentence=$(echo `cat $cmd &> /dev/null | wc -l`)
s1=$(echo `cat $cmd 2> /dev/null | grep -Eo "[\.\?\!]*" | wc -l`) 

n1=$(echo `cat  $cmd 2> /dev/null | grep -Eo "[0-9][\.][0-9]" | wc -l`) 
sentence=$(("$s1-$n1" | bc))
out=$(("$total-$decimal" | bc))
if [[ "$cmd" == "./paths" ]]
then
	continue
fi

if [[ "$cmd" == "./pt" ]]
then
	        continue
fi




if [[ -d $cmd ]] 
then

	echo "(D\)"$cmd-$sentence-$out >> output
else

	echo "(F\)" $cmd-$sentence-$out >> output
fi
done
cat output | sed 's|[^\/]*\/|     |g' >out 
sed 's|[\]|)|g' out >output2

cat output2
rm out
rm output2
rm output
rm paths
cd ..
rm -r pt
