CC:=gcc
COPT:=-Ofast -g   -Wall 
CLOPT:=$(COPT) 

%.o: %.c
	$(CC) -c $(COPT)   $< -o $@ 
%: %.c
	$(CC) $(CLOPT)  -o $@ $^   -lm 
LSTBC:=hello1.c hello2.c hello2a.c hello3.c hello4.c hello5.c hello6.c hello7.c hello8.c hello9.c f2c.c
TRG:=$(LSTBC:.c=)
all:  $(TRG)  

$(TRG):
clean:	
	rm -f  $(TRG)  *.o
	

