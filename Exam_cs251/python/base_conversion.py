from decimal import Decimal
import sys
import string
def val(c):
    if c >= ord('0') and c <= ord('9'):
        return c - ord('0')
    elif c>=ord('a') and c<= ord('z'):
        return c - ord('a') + 10

    else:
        return c - ord('A') + 10

def checkInput(strr,b,l,i):
    for x in range(i, l):
        p=ord(strr[x])
        if val(p)>=b:
            return 0
    return 1


def printNumber(s,b,l,i):
    n=0
    while(n<l):
        if(ord(s[n])==ord('.')):
            break
        n+=1
    summ=0
    m=l-n-1
    for x in range(i,l):
        if n> 0 and i==0:
            summ=summ+val(ord(s[x]))*(b)**(n-1)
            n-=1
        elif n>1 and i==1:
            summ=summ+val(ord(s[x]))*(b)**(n-2)
            n-=1

        elif n==0 :
            n-=1
            continue
        elif n==1 and i==1 :
            n=n-2
            continue
        elif n<0 and m>0:
            summ=summ+val(ord(s[x]))*(b)**(n)
            n-=1
            m-=1
    if summ >999999999 or summ <-999999999:
        print("Invalid Input")
    else:
        if i==0:
            print("%.6f" %summ)
        else:
            print("%.6f"%-summ)




#def main():
 #  print("Welcome in string to decimal converter programm")
#if __name__ =="__main__":
 #   main()


name=sys.argv[1]
# name=raw_input("Enter String ")
b=sys.argv[2]
# base=input("Enter base : ")
base=0
lb=len(b)
i=0
while lb>0:
   base=base*10+val(ord(b[i]))
   lb-=1
   i+=1
if base<2 or base >36:
    print("Invalid base")

else:
    length=len(name)
    if ord(name[0])==ord("-"):
        if checkInput(name,base,length,1) == 0:
            print("Invalid Input")

        else:
            printNumber(name,base,length,1)

    else:
        if checkInput(name,base,length,0) == 0:
            print("Invalid Input")
        else:
            printNumber(name,base,length,0)
