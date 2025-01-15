#ifndef ERA_SORT_FILE_FINDER_H
#include <iostream>
#include <string>
#include <list>
#include <dirent.h>
#include <sys/types.h>

namespace era_sort {

class Directory {
public:
    static std::list<std::string> get_file_list(const std::string& a_path,
                                                 const std::list<std::string>& extensions = m_empty_extensions) {
        std::list<std::string> file_list;
        get_file_list(file_list, a_path, extensions);
        return file_list;
    }
    
    static void get_file_list(std::list<std::string>& a_file_list,
                              const std::string& a_path,
                              const std::list<std::string>& extensions = Directory::m_empty_extensions) {
        DIR* dir = opendir(a_path.c_str());
        if (dir == nullptr) {
            std::cerr << "Error opening directory: " << a_path << std::endl;
            return;
        }

        struct dirent* entry;
        while ((entry = readdir(dir)) != nullptr) {
            if (entry->d_type == DT_REG) { // If the entry is a regular file
                std::string file_name = entry->d_name;
                if(0 == extensions.size()) {
                    a_file_list.push_back(a_path + "/" + file_name);
                }
                else {
                    for (const auto& extension : extensions) {
                        if (file_name.size() >= extension.size() && 
                            file_name.compare(file_name.size() - extension.size(), extension.size(), extension) == 0) {
                            a_file_list.push_back(a_path + "/" + file_name);
                            break; // No need to check other extensions if one matches
                        }
                    }
                }
            } else if (entry->d_type == DT_DIR) { // If the entry is a directory
                std::string dirName = entry->d_name;
                if (dirName != "." && dirName != "..") {
                    get_file_list(a_file_list, a_path + "/" + dirName, extensions); // Recursively call for subdirectories
                }
            }
        }
        closedir(dir);
    }
private:
    static const std::list<std::string> m_empty_extensions;
};

} // namespace era_sort

#endif // ERA_SORT_FILE_FINDER_H