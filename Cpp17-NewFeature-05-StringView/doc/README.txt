C++17 introduces another way of using strings, std::string_view, 
which lives in the <string_view> header.
Unlike std::string, which keeps its own copy of the string, 
std::string_view provides a view of a string that is defined elsewhere.
