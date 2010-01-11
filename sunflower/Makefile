#

CPPFLAGS = -O

LFLAGS = -lm -lglut32 -lglu32 -lopengl32 -lwinmm -lgdi32 -lstdc++

sunflower.exe : sunflower.o main.o drawUtil.o coord.o
	gcc -o $@ $^ $(LFLAGS)

sunflower.o : sunflower.cpp drawUtil.h coord.h
coord.o : coord.cpp coord.h

clean:
	rm *.o *~
