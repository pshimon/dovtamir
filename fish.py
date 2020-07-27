#!/usr/bin/python
# dov panfil fish animation 2020-07-16
import pygame, sys
from pygame.locals import *

W=800 #window width
H=600 #window height
FPS = 30 # frames per second setting
BG = (0, 0, 180) #background color

pygame.init()

fpsClock = pygame.time.Clock()

# set up the window
s = pygame.display.set_mode((W, H), 0, 32)
pygame.display.set_caption('Fish Animation')

#img = pygame.image.load('fugu.png')
img = pygame.image.load('fish.png')
img1=pygame.transform.flip(img,True,False)
wimg=img.get_rect().right-img.get_rect().left
himg=img.get_rect().bottom-img.get_rect().top
print(wimg,himg)
#initial position
x = 0.0
y = 0.0 
direction = 'zero'
run=True
while run: # the main game loop
    s.fill(BG)
    for event in pygame.event.get():
        key_pressed = pygame.key.get_pressed()
        if event.type == QUIT or key_pressed[K_ESCAPE] :
            run=False
            break
        if  key_pressed[K_RIGHT] :
            direction = 'right'
        elif key_pressed[K_LEFT] :
            direction = 'right'
#        else :

    if direction == 'left':
        x += 5
        s.blit(img1, (x, y))
        if x+wimg >= W:
            direction = 'down'
    elif direction == 'down':
        y += 5
        s.blit(img1, (x, y))
        if y+himg >= H:
            direction = 'left'
    elif direction == 'left':
        x -= 5
        s.blit(img, (x, y))
        if x <= 0:
            direction = 'up'
    elif direction == 'up':
        y -= 5
        s.blit(img, (x, y))
        if y <= 0:
            direction = 'right'

    

    pygame.display.update()
    fpsClock.tick(FPS)

pygame.quit()
sys.exit()

