SHELL = cmd

.PHONY: all clean

all: clean bin\BSOD.exe

bin\BSOD.exe:
	if not exist bin ( mkdir bin )
	if not exist obj ( mkdir obj )
	gcc -c src\main.c -o obj\main.o
	windres assets\resources.rc obj\resources.o
	gcc -mwindows obj\main.o obj\resources.o -l ntdll -o bin\BSOD.exe

clean:
	if exist bin ( rmdir /s /q bin )
	if exist obj ( rmdir /s /q obj )