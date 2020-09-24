#!/usr/bin/python
# dov panfil ball animation 2020-07-26
import pygame, sys,math
from pygame.locals import *

W=640 #window width
H=480 #window height
FPS = 30 # frames per second setting
BG = (0, 0, 180) #background color
CLR= (0,200,200) # obj color
R=20 # radius
DVX=5
DVY=5
VX0=0
VY0=0
pygame.init()
img = pygame.transform.flip(pygame.image.load('fish.png'),True,False)
fpsClock = pygame.time.Clock()
# set up the window
s = pygame.display.set_mode((W, H), 0, 32)
pygame.display.set_caption('Fish Animation')

def draw_obj(x,y,vx,vy):
    ang=180/math.pi*math.atan2(vy,vx)
    if vx<0 :
        i=pygame.transform.rotate(img,ang)
        i = pygame.transform.flip(i,False,True)
    else:
        i=pygame.transform.rotate(img,-ang)
    s.blit(i, (x, y))

#initial position
x = W/2
y = H/2 
vx=VX0
vy=VY0
run=True
while run: # the main game loop
    s.fill(BG)
    for event in pygame.event.get():
        if event.type==QUIT:
            run =False
            break
        if event.type==KEYDOWN:
            if event.key== K_ESCAPE:
                run =False
                break
            if event.key==K_UP:
                vy=vy-DVY
            if event.key==K_DOWN:
                vy=vy+DVY
            if event.key==K_RIGHT:
                vx=vx+DVX
            if event.key==K_LEFT:
                vx=vx-DVX
                
    if x>=W-R or x<R:
        vx=-vx
    if y>=H-R or y<R:
        vy=-vy

    x=x+vx
    y=y+vy              
    draw_obj(x,y,vx,vy)
    pygame.display.update()
    fpsClock.tick(FPS)

pygame.quit()
sys.exit()

