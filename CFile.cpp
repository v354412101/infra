#include "CFile.h"

namespace Infra {
    CFile::CFile()
        : fp_(nullptr),
          fd_(-1) {}

    CFile::~CFile() {}

    bool CFile::open(const char *path, const char *mode) {
        return false;
    }

    bool CFile::open(const std::string &path, const char *mode) {
        return false;
    }

    size_t CFile::read(void *ptr, size_t size, size_t nmemb) {
        return 0;
    }

    size_t CFile::write(const void *ptr, size_t size, size_t nmemb) {
        return 0;
    }

    int CFile::seek(long offset, int whence) {
        return 0;
    }

    bool CFile::close() {
        return false;
    }
}

