#

CPPFLAGS = -g

#LFLAGS = -lm -lglut32 -lglu32 -lopengl32 -lwinmm -lgdi32 -lstdc++
LFLAGS = -lm -lglut -lstdc++

$DEFUALT:   gvectorTest gvt

gvectorTest : gvectorTest.o gvector.o
	gcc -o $@ $^ $(LFLAGS) -lcppunit

gvt : gvt.o gvector.o
	gcc -o $@ $^ $(LFLAGS)

gvectorTest.o : gvectorTest.cpp gvector.h
gvt.o : gvt.cpp gvector.h

gvector.o : gvector.cpp gvector.h

clean:
	rm -f *.o *~
