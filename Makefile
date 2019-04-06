all:  assembler

assembler:  assembler.o
  g++ assembler.o -o assembler

assembler.o:  assembler.cpp
  g++ -g -c assembler.cpp


clean:
  rm -rf *.o assembler
  
