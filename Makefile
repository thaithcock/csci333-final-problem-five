CC = g++
CFLAGS = -Wextra

nice: naughtyNice.cpp
	$(CC) $(CFLAGS) -o nice -c $< 

clean:
	rm -f *.o
	rm -f *.gch
