#

CPPFLAGS = -O

#LFLAGS = -lm -lglut32 -lglu32 -lopengl32 -lwinmm -lgdi32 -lstdc++
LFLAGS = -lm -lglut -lstdc++

$DEFUALT:   sunflower gvectorTest

sunflower : sunflower.o main.o drawUtil.o
	gcc -o $@ $^ $(LFLAGS)

gvectorTest : gvectorTest.o gvector.o
	gcc -o $@ $^ $(LFLAGS) -lcppunit

sunflower.o : sunflower.cpp drawUtil.h
gvectorTest.o : gvectorTest.cpp gvector.h

gvector.o : gvector.cpp gvector.h

clean:
	rm -f *.o *~
