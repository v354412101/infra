#include "CFile.h"

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
}

