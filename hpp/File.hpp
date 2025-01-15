#ifndef ERA_SORT_FILE_H
#define ERA_SORT_FILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <ctime>

namespace era_sort {

class FileDate {
public:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;

    FileDate(void) : year(0), month(0), day(0), hour(0), minute(0), second(0) {}

    void print(FILE* a_file) const {
        fprintf(a_file, "%d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second);
    }
};

class File {
public:
    static long get_size(const std::string& a_file_path) {
        std::ifstream file(a_file_path, std::ios::binary | std::ios::ate);
        if (!file.is_open()) {
            std::cerr << "Could not open the file!" << std::endl;
            return -1;
        }
        return file.tellg();
    }

    static FileDate get_file_create_time(const std::string& a_file_name) {
        struct stat file_info;
        FileDate file_date;

        if (stat(a_file_name.c_str(), &file_info) != 0) {
            std::cerr << "Error: Unable to access file " << a_file_name << std::endl;
            return file_date;
        }

        std::tm* create_time = std::localtime(&file_info.st_ctime);
        file_date.year   = create_time->tm_year + 1900;
        file_date.month  = create_time->tm_mon + 1;
        file_date.day    = create_time->tm_mday;
        file_date.hour   = create_time->tm_hour;
        file_date.minute = create_time->tm_min;
        file_date.second = create_time->tm_sec;

        return file_date;
    }

    static bool copy(const std::string& a_source_path, const std::string& a_destination_path) {
        std::ifstream sourceFile(a_source_path, std::ios::binary);
        std::ofstream destinationFile(a_destination_path, std::ios::binary);
        if (!sourceFile.is_open() || !destinationFile.is_open()) {
            std::cerr << "Error opening files!" << std::endl;
            return false;
        }
        destinationFile << sourceFile.rdbuf();
        sourceFile.close();
        destinationFile.close();
        return true;
    }
};

}   // namespace era_sort

#endif // ERA_SORT_FILE_H