# chapter 10 STL Function Objects and Using Lambdas

A function object or a *functor* is an object that has `operator()` defined.
It has three important advantages:
1. It maybe smarter because it has state. You may have two instances of same type,
  and they have different states.
2. Each functor has its own type. You can pass the type of a functor to a template
  to specify certain behavior.
3. It's usually faster than a function pointer.

Functor can be used as sorting criterion.
