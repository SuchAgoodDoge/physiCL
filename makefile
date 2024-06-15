# add the src and src/out folders
VPATH = src:src/out

physiCL: out/main.o out/particle.o
	g++ -o physiCL out/main.o out/particle.o

out/main.o: main.cpp
	g++ -c src/main.cpp -o out/main.o

out/particle.o: particle.cpp particle.h
	g++ -c src/particle.cpp -o out/particle.o




clean:
	rm -f out/*.o physiCL