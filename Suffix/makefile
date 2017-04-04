all: Suffix.exe
  
clean:
	rm Suffix.o Suffix.exe
  
Suffix.exe: Suffix.o
	g++ -g -o Suffix.exe Suffix.o
  
Suffix.o: Suffix.cpp
	g++ -c -g Suffix.cpp