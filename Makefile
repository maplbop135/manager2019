CC = gcc
CFlags = -W -Wall
TARGET = manager
OBJECTS = menu.o user.o main.c
D_OBJECTS = menu_d.o user_d.o main_d.c

manager : menu.o user.o main.c
	gcc -o manager menu.o user.o main.c

manager_d : menu_d.o user_d.o main_d.c

user.o : user.c
	gcc -c -o user.o user.c

user_d.o : user.c
	gcc -c -o user_d.o user.c

menu.o : menu.c
	gcc -c -o menu.o menu.c

menu_d.o : menu.c
	gcc -c -o menu_d.o menu.c

clean :
	rm *.o manager manager_d
