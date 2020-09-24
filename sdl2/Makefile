SDL_LIBS:= -lSDL2 -lSDL2_image -lSDL2_ttf  -lSDL2_mixer -lSDL2_net
SDL_INC:= -I/usr/include/SDL2


CC:=gcc
COPT:=-Ofast -g   -Wall -I$(SDL_INC)
CLOPT:=$(COPT) 

%.o: %.c
	$(CC) -c $(COPT)   $< -o $@ 
%: %.c
	$(CC) $(CLOPT)  -o $@ $^ $(SDL_LIBS)  -lm 
LSTBC:=hello_win.c hello_sound.c doom_fire.c simple_net.c

TRG:=$(LSTBC:.c=)
all: $(TRG)  
clean:	
	rm -f  $(TRG)

