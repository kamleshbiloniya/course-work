import sys
import bisect
import string

k=raw_input().split()

n=int(k[0])
op=int(k[1])
d={}

# for i in range(0,n):
#     d[i]=l
for j in range(0,op):
    l=[]
    s=raw_input().split()
    #print s[0]
    if(s[0]=="addnode"):
        x=int(s[1])
        d[x]=l
    elif(s[0]=="delnode"):
        x=int(s[1])
        del d[x]
        for i in d.keys():
            for t in d[i]:
                if(x==t):
                    d[i].remove(x)
    elif(s[0]=="addlink"):
        x=int(s[1])
        y=int(s[2])
        d[x].append(y)
        d[y].append(x)
    else:
        x=int(s[1])
        y=int(s[2])
        d[x].remove(y)
        d[y].remove(x)
    #print d
q=input()
for i in range(0,q):
    f=input()
    flag=0
    for j in d.keys():
        if(j==f):
            flag=1
    if(flag==0):
        print ('not in network')
    else:
        if(len(d[f])==0):
            print ('no connections')
        else:
            for a in d[f]:
                print (a)
