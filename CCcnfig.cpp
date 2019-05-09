#include "CCcnfig.h"



namespace Infra {
    CCcnfig::CCcnfig(const std::string& path)
        : config_(Json::Value::null),
          path_(path),
          config_file_(new CFile()) {

    }

    CCcnfig::~CCcnfig() {
        delete config_file_;
        config_file_ = nullptr;
    }

    Json::Value CCcnfig::get() {
        return Json::Value();
    }

    bool CCcnfig::set(const Json::Value &config) {
        return false;
    }

    bool CCcnfig::init() {
        if (CFile::is_exist(path_)) {
            if (config_file_->open(path_.c_str(), "r")) {

            } else {

            }

        }
        return false;
    }
}