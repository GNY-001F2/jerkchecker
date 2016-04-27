CC = g++
CFLAGS = -std=c++14 -Wall -Werror -Wextra -Weffc++

all: jerkchecker

%: %.cxx
	$(CC) $(CFLAGS) -g -O3 -o $@ $^

clean:
	rm -f jerkchecker *~
