# list/Makefile
#
# Makefile for list implementation and test file.
#
# <Daniel Hart>

list: main.c
	gcc -o main main.c list.c
