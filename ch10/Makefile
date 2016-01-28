CFLAG = -Wall -std=c++11
BIN   = sort1 sequence1 sequence2 foreach3 removeif1 bind1 \
	compose3 bind2 test fopow1 deprecated \
	lambda1 lambda2 lambda3 lambda4 lambda5

all: $(BIN)

lambda5 : lambda5.cpp
	g++ $(CFLAG) $^ -o $@

lambda4 : lambda4.cpp
	g++ $(CFLAG) $^ -o $@

lambda3 : lambda3.cpp
	g++ $(CFLAG) $^ -o $@

lambda2 : lambda2.cpp
	g++ $(CFLAG) $^ -o $@

lambda1 : lambda1.cpp
	g++ $(CFLAG) $^ -o $@

deprecated : deprecated.cpp
	g++ $(CFLAG) $^ -o $@

fopow1 : fopow1.cpp
	g++ $(CFLAG) $^ -o $@

test : test.cpp
	g++ $(CFLAG) $^ -o $@

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
