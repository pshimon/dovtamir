CC:=gcc
COPT:=-Ofast -g   -Wall 
CLOPT:=$(COPT) 

%.o: %.c
	$(CC) -c $(COPT)   $< -o $@ 
%: %.c
	$(CC) $(CLOPT)  -o $@ $^   -lm 
LSTC:=state.c
SLST:=$(LSTC:.c=.o)
SLIB:=libstate.a
LSTBC:= state-main.c
TRG:=$(LSTBC:.c=)
all: $(SLIB) $(TRG)  

$(SLIB): $(SLST) 
	ar crv $(SLIB) $(SLST) 
$(TRG):$(SLIB)
clean:	
	rm -f  $(TRG) $(SLIB) *.o
	
state-main.o: state-main.c state.h cdefs.h
state.o: state.c state.h cdefs.h

