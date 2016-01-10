CFLAG = -Wall -std=c++11
BIN   = sort1 sequence1

all: $(BIN)

sort1 : sort1.cpp
	g++ $(CFLAG) $^ -o $@

sequence1 : sequence1.cpp
	g++ $(CFLAG) $^ -o $@

clean :
	rm -rf $(BIN)
