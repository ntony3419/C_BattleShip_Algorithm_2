CC = gcc 
CFLAGS = -Wall -ansi -pedantic -Werror -std=c89 -g
OBJA = main.o Field.o  menu.o shiplist.o gameplay.o misslelist.o
OBJB = main.o FieldB.o  menu.o shiplist.o gameplay.o misslelist.o
OBJC = mainC.o FieldC.o  menu.o shiplist.o gameplayC.o misslelist.o
EXECA = BattleShip
EXECB = BattleShipMono
EXECC = BattleShipDebug


all: $(EXECA) $(EXECB) $(EXECC)

$(EXECA): $(OBJA)
		$(CC) $(CFLAGS) $(OBJA) -o $(EXECA) 
$(EXECB): $(OBJB)
		$(CC) $(CFLAGS) $(OBJB) -o $(EXECB) 
$(EXECC): $(OBJC)
		$(CC) $(CFLAGS) $(OBJC) -o $(EXECC) 
		
main.o: main.c 
	$(CC) -c main.c $(CFLAGS) -g
mainC.o: main.c
	$(CC) -c main.c $(CFLAGS) -o mainC.o -D DEBUG 
Field.o: Field.c Field.h
	$(CC) -c Field.c $(CFLAGS) 
FieldB.o: Field.c Field.h
	$(CC) -c Field.c $(CFLAGS) -o FieldB.o  -D MONO
FieldC.o: Field.c Field.h
	$(CC) -c Field.c $(CFLAGS) -o FieldC.o -D DEBUG
Menu.o: menu.c menu.h
	$(CC) -c menu.c $(CFLAGS) 
shiplist.o: shiplist.c shiplist.h
	$(CC) -c shiplist.c $(CFLAGS)
misslelist.o: misslelist.c misslelist.h
	$(CC) -c misslelist.c $(CFLAGS)
gameplay.o: gameplay.c gameplay.h
	$(CC) -c gameplay.c $(CFLAGS) 
gameplayC.o: gameplay.c gameplay.h
	$(CC) -c gameplay.c $(CFLAGS) -o gameplayC.o -D DEBUG
	
	
clean:
		rm -f $(OBJA) $(OBJB) $(OBJC) $(EXECA) $(OBJB) $(EXECB) $(EXECC) 

