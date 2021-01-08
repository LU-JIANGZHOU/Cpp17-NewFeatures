Changes to auto deduction when used with the uniform initialization syntax.
Previously, auto a{1}; deduces a std::initializer_list<int> , which now deduces to int .