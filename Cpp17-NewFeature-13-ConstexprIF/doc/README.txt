In C++17, the new feature if constexpr allows you to discard branches of an if statement at compile-time based on a constant expression condition.
if constexpr(condition)
     statement true; // Discarded if condition is false
else
     statement false; // Discarded if condition is true