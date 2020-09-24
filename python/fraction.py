#!/usr/bin/python
import pygame
from pygame.locals import *

BLACK = (0, 0, 0)
GRAY = (127, 127, 127)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
YELLOW = (255, 255, 0)
CYAN = (0, 255, 255)
MAGENTA = (255, 0, 255)
LM=10 #left margin
W=800 #witdth
RM=10 #right margin
TM=10 #top margin
H=20 #height
BM=10 #bottom margin

pygame.init()
screen = pygame.display.set_mode((LM+W+RM, TM+H+BM))
pygame.display.set_caption('Fractions')
run=True
while run : 
    print("insert numerator" +" ? ")
    a=input()
    if a==0.0 :
        run=False
        break
    print("insert denomerator" +" ? ")
    b=input()
    c=float(a)/float(b)
    print(str(a)+"/"+str(b)+"="+str(c))
    if c<0.0 :
        print("negative fractions not allowed")
    elif c>1.0 :
        print("numerator should be less than denominator")
    else :
        screen.fill(GRAY)
        f=int(c*W)
        pygame.draw.rect(screen,RED,(LM,TM,f,H))
        pygame.draw.rect(screen,BLUE,(LM+f,TM,W-f,H))
        pygame.display.update()

pygame.quit()

