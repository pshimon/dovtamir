#!/usr/bin/python
# dov panfil ball animation 2020-07-26
import pygame, sys
from pygame.locals import *

W=640 #window width
H=480 #window height
FPS = 30 # frames per second setting
BG = (0, 0, 180) #background color
CLR= (0,200,200) # obj color
R=20 # radius
pygame.init()

fpsClock = pygame.time.Clock()
# set up the window
s = pygame.display.set_mode((W, H), 0, 32)
pygame.display.set_caption('Ball Animation')

def draw_obj(x,y):
    pygame.draw.circle(s,CLR,(int(x),int(y)),R,0)


#initial position
x = W/2
y = H/2 
vx=0
vy=0
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
                vy=-3
            if event.key==K_DOWN:
                vy=3
            if event.key==K_RIGHT:
                vx=4
            if event.key==K_LEFT:
                vx=-4

        if event.type==KEYUP:
            if event.key==K_UP:
                vy=0
            if event.key==K_DOWN:
                vy=0
            if event.key==K_RIGHT:
                vx=0
            if event.key==K_LEFT:
                vx=0
    if x>=W-R or x<R:
        vx=-vx
    if y>=H-R or y<R:
        vy=-vy

    x=x+vx
    y=y+vy              
    draw_obj(x,y)
    pygame.display.update()
    fpsClock.tick(FPS)

pygame.quit()
sys.exit()

