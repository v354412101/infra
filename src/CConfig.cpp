#include "CConfig.h"

#include <fstream>

namespace Infra {
    CConfig::CConfig(const std::string& path)
        : config_(Json::Value::null),
          path_(path) {
    }

    CConfig::~CConfig() {
    }

    Json::Value CConfig::get() const {
        return config_;
    }

    bool CConfig::set(const Json::Value &config) {
        std::fstream f;
        f.open(path_, std::ios::out);
        if (!f.is_open()) {
            return false;
        }
        f << config_.toStyledString();
        f.close();

        config_ = config;

        return true;
    }

    bool CConfig::init() {
        std::fstream f;
        f.open(path_, std::ios::in);
        if (!f.is_open()) {
            return false;
        }

        Json::CharReaderBuilder rbuilder;
        JSONCPP_STRING errs;

        bool parse_ret = Json::parseFromStream(rbuilder, f, &config_, &errs);
        f.close();

        return parse_ret;
    }
}