#include "CFile.h"

#include <cstdio>

namespace Infra {
    CFile::CFile()
        : fp_(nullptr) {}

    CFile::~CFile() {}

    bool CFile::open(const char *path, const char *mode) {
        fp_ = std::fopen(path, mode);
        return (fp_ != nullptr);
    }

    size_t CFile::read(void *ptr, size_t size, size_t nmemb) {
        return std::fread(ptr, size, nmemb, fp_);
    }

    size_t CFile::write(const void *ptr, size_t size, size_t nmemb) {
        return std::fwrite(ptr, size, nmemb, fp_);
    }

    int CFile::seek(long offset, int whence) {
        return std::fseek(fp_, offset, whence);
    }

    bool CFile::close() {
        std::fclose(fp_);
        fp_ = nullptr;
        return true;
    }
}

