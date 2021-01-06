#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main()
{
  cout << "to demonstrate the function of file system" << endl;
  //1) std::filesystem::path
  auto p = fs::current_path();
  std::cout << "Current path is " << fs::current_path() << '\n';
  fs::path pathToShow("\0");
  cout << "exists() = " << fs::exists(pathToShow) << "\n"
       << "root_name() = " << pathToShow.root_name() << "\n"
       << "root_path() = " << pathToShow.root_path() << "\n"
       << "relative_path() = " << pathToShow.relative_path() << "\n"
       << "parent_path() = " << pathToShow.parent_path() << "\n"
       << "filename() = " << pathToShow.filename() << "\n"
       << "stem() = " << pathToShow.stem() << "\n"
       << "extension() = " << pathToShow.extension() << "\n";

  //2) std::filesystem::directory_iterator
  fs::create_directories("dir01/x/y");
  std::ofstream("dir01/file1.txt");
  std::ofstream("dir01/file2.txt");
  for (auto &p : fs::directory_iterator("dir01"))
    std::cout << p.path() << '\n';
  fs::remove_all("dir01");

  return EXIT_SUCCESS;
};
