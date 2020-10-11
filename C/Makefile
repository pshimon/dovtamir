CC:=gcc
COPT:=-Ofast -g   -Wall 
CLOPT:=$(COPT) 

%.o: %.c
	$(CC) -c $(COPT)   $< -o $@ 
%: %.c
	$(CC) $(CLOPT)  -o $@ $^   -lm 
LSTC:=state.c
SLST:=$(LSTC:.c=.o)
SLIB:=libdov.a
#LSTBC:=hello1.c hello2.c hello2a.c hello3.c hello4.c hello5.c hello6.c hello7.c hello8.c hello9.c 
LSTBC:=f2c.c state-main.c
TRG:=$(LSTBC:.c=)
all: $(SLIB) $(TRG)  

$(SLIB): $(SLST) 
	ar crv $(SLIB) $(SLST) 
$(TRG):$(SLIB)
clean:	
	rm -f  $(TRG) $(SLIB)
	
state-main.o: state-main.c state.h cdefs.h
state.o: state.c state.h cdefs.h

