CFLAG = -Wall -std=c++11
BIN   = sort1 sequence1 sequence2 foreach3 removeif1 bind1 \
	compose3 bind2

all: $(BIN)

bind2 : bind2.cpp
	g++ $(CFLAG) $^ -o $@

compose3 : compose3.cpp
	g++ $(CFLAG) $^ -o $@

sort1 : sort1.cpp
	g++ $(CFLAG) $^ -o $@

sequence1 : sequence1.cpp
	g++ $(CFLAG) $^ -o $@

sequence2 : sequence2.cpp
	g++ $(CFLAG) $^ -o $@

foreach3 : foreach3.cpp
	g++ $(CFLAG) $^ -o $@

removeif1 : removeif1.cpp
	g++ $(CFLAG) $^ -o $@

bind1 : bind1.cpp
	g++ $(CFLAG) $^ -o $@

clean :
	rm -rf $(BIN)
