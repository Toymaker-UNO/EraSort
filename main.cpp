#include "Directory.hpp"
int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <path> <extension1> [<extension2> ... <extensionN>]" << std::endl;
        return 1;
    }

    std::string path = argv[1];
    std::list<std::string> extensions;
    for (int i = 2; i < argc; ++i) {
        extensions.push_back(argv[i]);
    }

    std::list<std::string> file_list;
    era_sort::Directory::get_file_list(file_list, path, extensions);

    for (const auto& file : file_list) {
        std::cout << file << std::endl;
    }

    return 0;
}