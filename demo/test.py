import sys
import bisect
import string
a=[]
def func(s1,s2):
    if s1=="learn":
        a.append(s2)
        bisect.insort(a,s2)
        #a.sort()
    elif s1=="forget":
        print(a.index(s2)+1)
        a.remove(s2)
    else:
        print(a.index(s2)+1)
n=input()
for i in range(0,n):
    s1=raw_input()
    s1,s2=s1.split(" ")
    func(s1,s2)
#
# 10
# learn monhdjaecg
# learn aelakggcfe
# learn mhbmldlcim
# learn ahlidlmdlj
# learn dlneeklean
# forget mhbmldlcim
# findrank ahlidlmdlj
# findrank monhdjaecg
# forget ahlidlmdlj
# findrank monhdjaecg
