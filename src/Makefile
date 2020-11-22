CC = clang++
CFLAGS = -std=c++11
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lGL

all: out out/Main

out:
	[ -d out ] || mkdir out
	[ -d out/model ] || mkdir out/model
	[ -d out/view ] || mkdir out/view

out/model/Actor.o: model/Actor.cpp model/Actor.h
	$(CC) $(CFLAGS) -c model/Actor.cpp
	mv Actor.o out/model/

out/view/GameWindow.o: view/GameWindow.cpp view/GameWindow.h
	$(CC) $(CFLAGS) -c view/GameWindow.cpp
	mv GameWindow.o out/view/

out/Main: Main.cpp out/model/Actor.o out/view/GameWindow.o
	$(CC) $(CFLAGS) -o out/Main Main.cpp out/model/Actor.o out/view/GameWindow.o $(LDFLAGS)
	mv -fu out ../out
	$(RM) -r out

clean:
	$(RM) ../out/*/*.o

mrproper: clean
	$(RM) -r ../out
