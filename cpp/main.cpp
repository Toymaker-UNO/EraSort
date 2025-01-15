#include "Directory.hpp"

void make_file_list(std::list<std::string>& a_file_list, 
                   const std::string& a_path, 
                   const std::list<std::string>& a_extensions) {
    if (true == era_sort::Directory::is_directory(a_path)) {
        era_sort::Directory::get_file_list(a_file_list, a_path, a_extensions);
    }
}

bool filter(const std::string& a_file_name) {
    if(std::string::npos != a_file_name.find("/$RECYCLE.BIN/")) {
        return false;
    }
    else if (std::string::npos != a_file_name.find("/boost_")) {
        return false;
    }
    else if (std::string::npos != a_file_name.find("/Program Files/")) {
        return false;
    }
    else if (std::string::npos != a_file_name.find("/Program Files (x86)/")) {
        return false;
    }
    else if (std::string::npos != a_file_name.find("/Windows/")) {
        return false;
    }
    else if (std::string::npos != a_file_name.find("/Emojis/")) {
        return false;
    }
    else if (std::string::npos != a_file_name.find("/Microsoft/")) {
        return false;
    }
    else if (std::string::npos != a_file_name.find("/Office/")) {
        return false;
    }
    else if (std::string::npos != a_file_name.find("AI Essential")) {
        return false;
    }
    else if (std::string::npos != a_file_name.find("/Autodesk/")) {
        return false;
    }
    else if (std::string::npos != a_file_name.find("/.vscode/")) {
        return false;
    }
    else if (std::string::npos != a_file_name.find("/Chrome/")) {
        return false;
    }
    else if (std::string::npos != a_file_name.find("/Python/")) {
        return false;
    }
    else if (std::string::npos != a_file_name.find("/AppData/")) {
        return false;
    }
    return true;
}

int main(void) {
    std::list<std::string> extensions;
    extensions.push_back(".jpg");
    extensions.push_back(".jpeg");
    extensions.push_back(".png");
    extensions.push_back(".gif");
    extensions.push_back(".bmp");
    extensions.push_back(".tiff");
    extensions.push_back(".tif");
    extensions.push_back(".svg");
    extensions.push_back(".mp4");
    extensions.push_back(".avi");
    extensions.push_back(".mov");
    extensions.push_back(".wmv");
    extensions.push_back(".mkv");
    extensions.push_back(".flv");
    
    std::list<std::string> file_list;
    make_file_list(file_list, "c:/", extensions);
    make_file_list(file_list, "d:/", extensions);
    make_file_list(file_list, "e:/", extensions);
    make_file_list(file_list, "f:/", extensions);
    make_file_list(file_list, "g:/", extensions);
    make_file_list(file_list, "h:/", extensions);
    make_file_list(file_list, "i:/", extensions);
    make_file_list(file_list, "j:/", extensions);
    make_file_list(file_list, "k:/", extensions);
    make_file_list(file_list, "l:/", extensions);
    make_file_list(file_list, "m:/", extensions);
    make_file_list(file_list, "n:/", extensions);

    FILE* p_file = fopen("./era_sort_file_list.txt", "w+");
    for (const auto& file : file_list) {
        if(false == filter(file)) {
            continue;
        }
        fprintf(p_file, "%s\n", file.c_str());
    }
    fclose(p_file); 

    return 0;
}