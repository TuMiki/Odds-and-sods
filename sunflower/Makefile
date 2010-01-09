#
LFLAGS = -lm -lglut32 -lglu32 -lopengl32 -lwinmm -lgdi32

sunflower.exe : sunflower.o main.o drawUtil.o
	gcc -o $@ $^ $(LFLAGS)

sunflower.o : sunflower.cpp drawUtil.h

clean:
	rm *.o *~
