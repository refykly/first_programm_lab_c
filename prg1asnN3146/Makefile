.PHONY: all clean debug 

APP=prg1asnN3146
CFLAGS=-Wall -Wextra -Werror

all: $(APP) 

$(APP): $(APP).c
	gcc -o $(APP) $(CFLAGS) $(APP).c

debug: $(APP).c
	gcc -o $(APP) $(CFLAGS) -g $(APP).c

clean: 
	rm $(APP) 


