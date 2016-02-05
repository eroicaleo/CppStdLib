CFLAG = -Wall -std=c++11
BIN   = vector1 deque1 array1 list1 list2 forward_list1 \
	multiset1 multimap1

all: $(BIN)

multimap1 : multimap1.cpp
	g++ $(CFLAG) $^ -o $@

multiset1 : multiset1.cpp
	g++ $(CFLAG) $^ -o $@

forward_list1 : forward_list1.cpp
	g++ $(CFLAG) $^ -o $@

list2 : list2.cpp
	g++ $(CFLAG) $^ -o $@

list1 : list1.cpp
	g++ $(CFLAG) $^ -o $@

array1 : array1.cpp
	g++ $(CFLAG) $^ -o $@

vector1 : vector1.cpp
	g++ $(CFLAG) $^ -o $@

deque1 : deque1.cpp
	g++ $(CFLAG) $^ -o $@

clean :
	rm -rf $(BIN)
