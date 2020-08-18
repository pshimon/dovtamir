CC:=gcc
COPT:=-Ofast -g   -Wall 
CLOPT:=$(COPT) 

%.o: %.c
	$(CC) -c $(COPT)   $< -o $@ 
%: %.c
	$(CC) $(CLOPT)  -o $@ $^   -lm 
LSTBC:=hello1.c hello2.c hello3.c hello4.c hello5.c hello6.c
TRG:=$(LSTBC:.c=)
all: $(TRG)  
clean:	
	rm -f  $(TRG)

