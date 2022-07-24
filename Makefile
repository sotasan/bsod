.PHONY: all clean

all: clean bin\BSOD.exe

bin\BSOD.exe:
	if not exist bin mkdir bin
	if not exist obj mkdir obj
	windres assets\assets.rc obj\assets.o
	gcc -c src\main.c -o obj\main.o
	gcc -mwindows obj\main.o obj\assets.o -o bin\BSOD.exe

clean:
	if exist bin rmdir /s /q bin
	if exist obj rmdir /s /q obj