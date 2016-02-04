<!-- TOC depth:6 withLinks:1 updateOnSave:1 orderedList:0 -->

- [chapter 06 The Standard Template Library](#chapter-06-the-standard-template-library)
	- [6.1 STL components](#61-stl-components)
	- [6.2 Containers](#62-containers)
		- [6.2.1 Sequence Containers](#621-sequence-containers)
- [chapter 10 STL Function Objects and Using Lambdas](#chapter-10-stl-function-objects-and-using-lambdas)
	- [10.2 Predefined Function Objects and Binders](#102-predefined-function-objects-and-binders)
		- [10.2.2. Function Adapters and Binders](#1022-function-adapters-and-binders)
		- [10.2.4 deprecated adapters](#1024-deprecated-adapters)
	- [10.4 Using Lambdas](#104-using-lambdas)
		- [10.4.3 Calling member functions and global functions](#1043-calling-member-functions-and-global-functions)
		- [10.4.4 Lambda as Hash Function, Sorting or Equivalence Criterion](#1044-lambda-as-hash-function-sorting-or-equivalence-criterion)
<!-- /TOC -->

# chapter 06 The Standard Template Library

## 6.1 STL components

The STL consists of containers, iterators and algorithms.
* **Containers**: manage collections of objects of a certain kind. Different
 	container types reflects different requirements for collections in programs.
* **Iterators**: step through the elements of collections of objects. They offer
	a small but common interface for any arbitrary container type. For example,
	one operation lets iterators step to the next element in the collection, regardless
	what type of the container is. Because the every container class provides its
	own iterator type which does the right thing.
* **Algorithms**: use to process the elements of the collection, e.g. search, sort.

The concept of the STL is based on separation of data and operation. The data is managed by
container classes, and the operations are defined by configurable algorithms. Iterators are the glue
between these two components. They let any algorithm interact with any container

## 6.2 Containers

* **Sequence containers**: ordered collections, meaning every element has a
	certain position, depends on the time and place of the insertion. There are
	five of them: `array`, `vector`, `deque`, `list`, and `forward_list`.
* **Associative containers**: sorted collections, meaning element position depends
	on its value or its key. The order of insertion doesn't matter. There are 4 of
	them: `set`, `multiset`, `map`, and `multimap`.
* **Unordered containers**: Unordered collections, meaning position doesn't matter.
	Neither the order of insertion of the value of the inserted element has an influence
	on the position. There are 4 of them: `unordered_set`, `unordered_multiset`,
	`unordered_map`, and `unordered_multimap`.

* Sequence containers are usually implemented as arrays or linked lists.
* Associative containers are usually implemented as binary trees.
* Unordered containers are usually implemented as hash tables.

### 6.2.1 Sequence Containers

**`vector`**
* Implemented as dynamic array
* Support random access with index
* Appending and removing end elements very fast
* Insert at beginning or middle takes time.

**`deque`**
* Implemented as dynamic array
* Support random access with index
* Appending and removing begin and end elements very fast, `push_back` and
 `push_front`
* Insert at middle takes time.

**`array`**
* fixed size, has to decide at creation time, e.g. `array<string, 5>`.
* Support random access with index.
* The number of elements is a part of the type of an array. `array<int, 5>` and
	`array<int, 10>` are two different types, you can't assign or compare them as
	whole.

**`list`**
* Implemented as double linked list.
* Do not provide random access.
* Removal and insertion is fast at any position.
* Various ways to iterate over list:
	```c++
	for (auto elem: coll) {} // Make a copy of element processed
	for (auto &elem: coll) {} // If we want to modify the elem
	for (const auto &elem: coll) {} // avoid a copy operation
	```
* Common member functions: `empty()`, `push_back()`, `front()` and `pop_front()`.

**`forward_list`**
* Implemented as single linked list.
* `push_back()` and `size()` are not implemented.
* `resize()` is expensive, it has linear complexity.

# chapter 10 STL Function Objects and Using Lambdas

A function object or a *functor* is an object that has `operator()` defined.
It has three important advantages:
1. It maybe smarter because it has state. You may have two instances of same type,
  and they have different states.
2. Each functor has its own type. You can pass the type of a functor to a template
  to specify certain behavior.
3. It's usually faster than a function pointer.

* Functor can be used as sorting criterion.
* Functor can be used as with internal states.

Function objects are passed by value instead of reference, which has the advantage
that you can pass constant and temporary objects.

Disadvantage is can't benefit from modifications of state of the function objects.
Sometimes, access the final state might be necessary.

There are 3 ways we can achieve this:

1. Keep the state external and let the function object to refer it.
2. You can pass the functor by reference:

  ```
  generate_n<back_insert_iterator<list<int>>, int, IntSequence&> (back_inserter(coll), 4, seq);
  ```
3. You can use the return value of `for_each()` algorithm.  
    * `for_each()` has the unique ability to return its function object. No other
      algorithms can do this.

**_A predicate should always be stateless._** That is, a predicate should not change
its state due to a call, and a copy of a predicate should have the same state as the original. To ensure
that you can’t change the state of a predicate due to a function call, you should declare `operator ()`
as a constant member function.

## 10.2 Predefined Function Objects and Binders

### 10.2.2. Function Adapters and Binders

The most important adapter is `bind()`, it allows you:
1. Adapt and compose new function objects out of existing or predefined function
	objects.
2. Call global functions.
3. Call member functions for objects, pointers to objects, and smarter pointer to
  objects.

```c++
std::bind(std::plus<int>(), std::placeholders::_1, 10)
```

The above code generates a function object, which internally calls `plus<>`, with
a placeholder `_1` as first parameter and `10` as second parameter. **The placeholder
`_1` represents the first argument passed to the expression as a whole.**

We can nest binders to compose even more complicated function objects.

```c++
auto plus10times2 = bind(multiplies<int>(),
                         bind(plus<int>(), _1, 10
                         2);

auto pow3 = bind(multiplies<int>(),
                 bind(multiplies<int>(),
                      _1,
                      _1),
                 _1);
```

Note that `bind` make a copy of the passed arguments. To let the function object
use a reference to pass argument, use `ref()` or `cref()`.

```c++
void incr(int &i) {
    ++i;
}

int i = 0;
bind(incr, i)(); // output 0
bind(incr, ref(i))(); // output 1
```

This is particular important when some functions has to take an reference, not a
copy, because the object cannot be copied, e.g. `cout`. In the following example,
we have to use `ref(cout)`. Otherwise, won't compile.

```c++
class Base {
private:
    int b;

public:
    Base(int b) : b {b} {
    }

    virtual void print(ostream& os) const {
        os << "This is Base: " << b << endl;
    }

};

for_each(coll.begin(), coll.end(), bind(&Base::print, placeholders::_ 1, ref(cout)));

```

**Calling member functions**

Here, `bind(&Person::print, _1)` defines a function object that calls `param1.print()`
for a passed `Person`. That is, because the first argument is a member function,
the next argument defines the object for which this member function gets called.
Any additional argument is passed to the member function, i.e.:
`bind(&Person::print2, _1, "This is: ")`
defines a function object that calls `param1.print2("This is: ")` for any passed `Person`.

We can even also pass pointers to objects and even smart pointers to bind(). Here
is an example:

```c++
shared_ptr<Person> p1{new Person{"Yang"}};
shared_ptr<Person> p2{new Person{"Yukan"}};

vector<shared_ptr<Person>> sp;
sp.push_back(p1);
sp.push_back(p2);

for_each(sp.begin(), sp.end(), bind(&Person::print, _ 1));
```

We can also call the member function which modify the object. Don't get confused
here,  "`bind` make a copy of the passed arguments", not the object, so the object
can be modified.

**`mem_fn` Adapter**

`mem_fn()` simply calls an initialized member function for a passed argument while additional
arguments are passed as parameters to the member function.
If a member function takes no argument, it is good to use this adapter. Otherwise
if we use it with `bind`, doesn't save much typing.

```c++
for_each(sp.begin(), sp.end(), mem_fn(&Person::print));
for_each(sp.begin(), sp.end(), bind(mem_fn(&Person::print2), _1, "Melon: "));
```

**Binding to a data member**

A cool and complex example. Note that the member is `map<string, int>::value_type::second`
in this case.

```c++
map<string, int> mapColl;
mapColl.insert(pair<string, int>("lala", 1));
mapColl.insert(pair<string, int>("haha", 2));
mapColl.insert(pair<string, int>("hehe", 3));
int sum = accumulate(mapColl.begin(), mapColl.end(),
										0,
										bind(plus<int>(),
												_1,
												bind(&map<string, int>::value_type::second,
														_ 2)
												)
				);

```

### 10.2.4 deprecated adapters

The difference between `mem_func` and `mem_func_ref` is shown in the following
example. `mem_func_ref` is the reference version and `mem_func` is the pointer
version.

```c++
// mem_fun_ref
vector<Person> coll1
		= { Person("Tick"), Person("Trick"), Person("Track") };

for_each(coll1.begin(), coll1.end(), mem_fun_ref(&Person::print));

// mem_fun
cout << "mem_fun example:" << endl;
Person* p1 = new Person{"Yang"};
Person* p2 = new Person{"Yukan"};

vector<Person *> coll2 {p1, p2};

for_each(coll2.begin(), coll2.end(), mem_fun(&Person::print));
```

The `bind1st` and `bind2nd` doesn't work well for `mem_fun_ref` and `mem_fun`.

```c++
// doesn't compile
bind1st(mem_fun_ref(&Person::print2), *coll1.begin())("Person: ");                                                                                                // compile but doesn't work.
 bind2nd(mem_fun_ref(&Person::print2), "Person: ")(* coll1.begin());
```

See 2 stackoverflow questions [here](http://stackoverflow.com/questions/7822652/using-bind1st-for-a-method-that-takes-argument-by-reference)
and [here](http://stackoverflow.com/questions/9180799/an-old-issue-on-bind1st-with-men-fun-in-c-stl).

## 10.4 Using Lambdas

Here are two examples, one is with state and another without state:

```c++
auto plus10 = [](int i) {
										return i+10;
								};

cout << "+10:    " << plus10(7) << endl;

for_each(coll.begin(), coll.end()                                           
				 [&sum] (int elem) {
						 sum += elem;
				 });
```

When we use stateful lambda object, be careful about the `mutable`. Here are two
examples, one with `mutable` and one with `reference`. The reason `mutable` will
give wrong behavior is because again, the `remove_if` internally makes a copy
of the `lambda` object. So in this case, it's better to use reference. We can do
the similar thing if we don't use `lambda` object but use normal function object
with state. See the code at end.

```c++
coll = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
count = 0;                                                                                                                                                            
pos = remove_if(coll.begin(), coll.end(),
								[count] (int) mutable {
										return ++count == 3;
								});
coll.erase(pos, coll.end());
PRINT_ELEMENT(coll); // wrong behavior: 1 2 4 5 7 8 9 10

coll = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
count = 0;                                                                                                                                                            
pos = remove_if(coll.begin(), coll.end(),
								[&count] (int) {
										return ++count == 3;
								});
coll.erase(pos, coll.end());
PRINT_ELEMENT(coll); // right behavior: 1 2 4 5 6 7 8 9 10

// Normal function object
// #include <functional>
Nth n(3);
pos = remove_if(coll.begin(), coll.end(), ref(n));
coll.erase(pos, coll.end());
PRINT_ELEMENT(coll); // right behavior: 1 2 4 5 6 7 8 9 10
```

### 10.4.3 Calling member functions and global functions

Actually, I personally think using lambda function here is clearer than `bind`

```c++
// Global function
pos = search(s.begin(), s.end(),
						sub.begin(), sub.end(),
						[] (char c1, char c2) {
								return myToupper(c1) == myToupper(c2);
						});
// Member function
for_each(coll.begin(), coll.end(),
				[] (const Person& p) {
						p.print();
				});
for_each(coll.begin(), coll.end(),
				[] (const Person& p) {
						p.print2("Person: ");                                            
				});
```

### 10.4.4 Lambda as Hash Function, Sorting or Equivalence Criterion

Note here, we have to use `decltype`. The author suggests specifying a class for
the function objects here would be more readable and convenient.

```c++
class Person {
	// code goes here
};
auto hash = [] (const Person &p) {
  // code goes here
}
auto eq = [] (const Person& p1, const Person &p2) {
	// code goes here
}
unordered_set<Person, decltype(hash), decltype(eq)> pset(10, hash, eq);
```
