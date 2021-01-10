
C++ nLambda function
[ capture list ] (parameters) -> return-type  
{  function definition
} (invoke operator);

//capture methods in 11 and 14
[ ] ( ) { } 	no captures
[=] ( ) { } 	captures everything by copy(not recommendded)
[&] ( ) { } 	captures everything by reference(not recommendded)
[x] ( ) { } 	captures x by copy
[&x] ( ) { } 	captures x by reference
[&, x] ( ) { } 	captures x by copy, everything else by reference
[=, &x] ( ) { } 	captures x by reference, everything else by copy

//In C++17, there is no ambiguity when it comes to the reference-capture-default 
[&]. The [&] captures this implicitly, 
[&, this] is redundant, and 
[&, *this] is allowed. 
[=, *this] is by reference

[this, *this] is not allowed
[=, this] is not allowed
