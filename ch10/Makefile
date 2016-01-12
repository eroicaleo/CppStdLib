CFLAG = -Wall -std=c++11
BIN   = sort1 sequence1 sequence2 foreach3

all: $(BIN)

sort1 : sort1.cpp
	g++ $(CFLAG) $^ -o $@

sequence1 : sequence1.cpp
	g++ $(CFLAG) $^ -o $@

sequence2 : sequence2.cpp
	g++ $(CFLAG) $^ -o $@

foreach3 : foreach3.cpp
	g++ $(CFLAG) $^ -o $@

clean :
	rm -rf $(BIN)
