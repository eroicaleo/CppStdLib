<!-- TOC depth:6 withLinks:1 updateOnSave:1 orderedList:0 -->

- [chapter 10 STL Function Objects and Using Lambdas](#chapter-10-stl-function-objects-and-using-lambdas)
	- [10.2 Predefined Function Objects and Binders](#102-predefined-function-objects-and-binders)
		- [10.2.2. Function Adapters and Binders](#1022-function-adapters-and-binders)
<!-- /TOC -->

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

The most important adapter is `binder()`, it allows you:
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

**Calling member functions**

Here, `bind(&Person::print, _1)` defines a function object that calls `param1.print()`
for a passed `Person`. That is, because the first argument is a member function,
the next argument defines the object for which this member function gets called.
Any additional argument is passed to the member function, i.e.:
`bind(&Person::print2, _1, "This is: ")`
defines a function object that calls `param1.print2("This is: ")` for any passed `Person`.
