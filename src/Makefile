CC = g++

all: out out/Main

out:
	[ -d out ] || mkdir out
	[ -d out/model ] || mkdir out/model

out/model/Actor.o: model/Actor.cpp model/Actor.h
	$(CC) -c model/Actor.cpp
	mv Actor.o out/model/

out/Main: Main.cpp out/model/Actor.o
	$(CC) -o out/Main Main.cpp out/model/Actor.o
	mv out ../out

clean:
	$(RM) out/*/*.o

mrproper: clean
	$(RM) -r out
