import sys
import string
a=[]
def func(s1,s2):
    if s1=="learn":
        a.append(s2)
        a.sort()
    elif s1=="forgetsmallest":
        print(a[0])
        a.pop(0)
    else:
        print(a[0])
n=input()
for i in range(0,n):
    s1=raw_input()
    if s1[0]=='l':
        s1,s2=s1.split(" ")
        func(s1,s2)
    else:
        func(s1,"NOP")
