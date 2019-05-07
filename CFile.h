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

        bool open(const std::string& path, const char *mode);

        size_t read(void *ptr, size_t size, size_t nmemb);

        size_t write(const void *ptr, size_t size, size_t nmemb);

        int seek(long offset, int whence);

        bool close();

    private:
        FILE *fp_;
        int fd_;
    };
}