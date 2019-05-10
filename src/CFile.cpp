#include "CFile.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

namespace Infra {
    CFile::CFile()
        : fp_(nullptr) {}

    CFile::~CFile() {}

    bool CFile::open(const char *path, const char *mode) {
        fp_ = ::fopen(path, mode);
        if (fp_ == nullptr) {
            return false;
        }
        return true;
    }

    size_t CFile::read(void *ptr, size_t size, size_t nmemb) {
        return ::fread(ptr, size, nmemb, fp_);
    }

    size_t CFile::write(const void *ptr, size_t size, size_t nmemb) {
        return ::fwrite(ptr, size, nmemb, fp_);
    }

    int CFile::seek(long offset, int whence) {
        return ::fseek(fp_, offset, whence);
    }

    bool CFile::close() {
        fclose(fp_);
        fp_ = nullptr;
        return true;
    }

    bool CFile::is_exist(const std::string& path) {
        if (path.empty()) {
            return false;
        }

        return (access(path.c_str(), F_OK) == 0);
    }

    int CFile::get_file_size(const std::string& path) {
        struct stat file_info;
        memset(&file_info, 0, sizeof(file_info));

        if (stat(path.c_str(), &file_info) == 0) {
            return file_info.st_size;
        }

        return -1;
    }
}

