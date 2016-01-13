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
