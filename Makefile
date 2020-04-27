CC = g++
cflags = -I. -g #-std=c++11 
lflags =
objs = main.o test_static.o

main: $(objs)
	$(CC) -o main $(objs) $(lflags)
	#$(CC) -o main $(objs) $(lflags) 
%.o: %.cc
	$(CC) -c $^ -o $@

clean:
	rm *.o main
