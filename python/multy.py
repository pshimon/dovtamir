#!/usr/bin/python
import random
run=True
wc=0 # win counter
while run :
    a=random.randint(0,9)
    b=random.randint(0,9)
    print("how much is "+str(a)+"*"+str(b)+" ? ")
    c=int(input())
    if c<0 :
        run=False
        break
    
    if c==a*b:
        wc=wc+1
        print("you win!")
    else:
        print("wrong: "+str(c)+" correct is "+str(a*b))

print("Game over score:"+str(wc))
