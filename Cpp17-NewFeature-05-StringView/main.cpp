#include <iostream>
#include <string>
#include <string_view>

int main()
{
  std::cout << "to demonstrate the string view and string remove" << std::endl;
  char text[]{"std string! "};
  std::string str{text}; //standard string copy
  std::string more{str};
  std::cout << text << ' ' << str << ' ' << more << '\n';
  std::cout << reinterpret_cast<uintptr_t>(str.data()) << '\n'; //check the address
  std::cout << reinterpret_cast<uintptr_t>(more.data()) << '\n';//it shoule be different

  std::string_view text_vw{"std string view! "}; // view of the same "hello"
  std::string_view str_vw{text_vw};              // view of the same
  std::string_view more_vw{str_vw};              // view of the same
  std::cout << text_vw << ' ' << str_vw << ' ' << more_vw << '\n';

  std::string f_str = std::to_string(123.456);
  std::string_view str_fvw{f_str}; // view of the same
  std::cout << f_str << ' ' << str_fvw << '\n';
  std::cout << reinterpret_cast<uintptr_t>(f_str.data()) << '\n'; //check the data address of the two string
  std::cout << reinterpret_cast<uintptr_t>(str_fvw.data()) << '\n';// it should be the same

  return EXIT_SUCCESS;
};
