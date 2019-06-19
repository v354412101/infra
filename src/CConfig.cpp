#include "CConfig.h"

#include <fstream>

namespace Infra {
    CConfig::CConfig()
        : config_(Json::Value::null) {
    }

    CConfig::~CConfig() {
    }

    bool CConfig::init(const std::string& path) {
        path_ = path;

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
}