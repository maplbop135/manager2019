CC = gcc -DDEBUG -c -o

manager : menu.o user.o main.c
	gcc -DDEBUG -o manager menu.o user.o main.c

user.o : user.c
	$(CC) user.o user.c

menu.o : menu.c
	$(CC) menu.o menu.c

clean :
	rm *.o manager
