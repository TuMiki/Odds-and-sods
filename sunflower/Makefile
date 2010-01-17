#

CPPFLAGS = -O

#LFLAGS = -lm -lglut32 -lglu32 -lopengl32 -lwinmm -lgdi32 -lstdc++
LFLAGS = -lm -lglut -lstdc++

$DEFUALT:   sunflower coordTest

sunflower : sunflower.o main.o drawUtil.o
	gcc -o $@ $^ $(LFLAGS)

coordTest : coordTest.o coord.o
	gcc -o $@ $^ $(LFLAGS) -lcppunit

sunflower.o : sunflower.cpp drawUtil.h
coordTest.o : coordTest.cpp

coord.o : coord.cpp coord.h

clean:
	rm *.o *~
