SDL_LIBS:= -lSDL2 -lSDL2_image -lSDL2_ttf  -lSDL2_mixer -lSDL2_net
SDL_INC:= /usr/include/SDL2


CC:=gcc
COPT:=-Ofast -g   -Wall -I$(SDL_INC)
CLOPT:=$(COPT) 

%.o: %.c
	$(CC) -c $(COPT)   $< -o $@ 
%: %.c
	$(CC) $(CLOPT)  -o $@ $^ $(SDL_LIBS)  -lm 
LSTC:=sdl.c
SLST:=$(LSTC:.c=.o)
LSTBC:=hello_win.c hello_sound.c doom_fire.c simple_net.c 02.c 04.c 05.c 06.c 07.c 08.c 09.c 10.c 11.c 12.c 13.c 14.c
TRG:=$(LSTBC:.c=)

SLIB:=mysdllib.a
all: $(SLIB) $(TRG)  
$(SLIB): $(SLST) 
	ar crv $(SLIB) $(SLST) 
$(TRG):$(SLIB)
clean:	
	rm -f  $(TRG) $(SLIB)

