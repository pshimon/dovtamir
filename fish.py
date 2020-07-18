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

img = pygame.image.load('fugu.png')
#initial position
x = 10.0
y = 10.0 
direction = 'right'

while True: # the main game loop
    s.fill(BG)

    if direction == 'right':
        x += 5
        if x == 280:
            direction = 'down'
    elif direction == 'down':
        y += 5
        if y == 220:
            direction = 'left'
    elif direction == 'left':
        x -= 5
        if x == 10:
            direction = 'up'
    elif direction == 'up':
        y -= 5
        if y == 10:
            direction = 'right'

    s.blit(img, (x, y))

    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()

    pygame.display.update()
    fpsClock.tick(FPS)
