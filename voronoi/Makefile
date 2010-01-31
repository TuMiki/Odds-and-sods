#

CPPFLAGS = -g -I../gmath

#LFLAGS = -lm -lglut32 -lglu32 -lopengl32 -lwinmm -lgdi32 -lstdc++
LFLAGS = -lm -lglut -lstdc++

$DEFUALT:   voronoi

voronoi : voronoi.o
	gcc -o $@ $^ ../gmath/gvector.o ../gmath/gline.o $(LFLAGS)

clean:
	rm -f *.o *~
