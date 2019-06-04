#pragma once

#include <stdio.h>

#include <cstddef>
#include <string>

namespace Infra {
    class CFile {
    public:
        CFile();
        ~CFile();
        bool open(const char *path, const char *mode);
        size_t read(void *ptr, size_t size, size_t nmemb);
        size_t write(const void *ptr, size_t size, size_t nmemb);
        int seek(long offset, int whence);
        bool close();
        static bool is_exist(const std::string& path);
        static int get_file_size(const std::string& path);

    private:
        FILE *fp_;
    };
}