#pragma once

#include "json/json.h"

namespace Infra {
    class CConfig {
    public:
        CConfig();
        ~CConfig();
        bool init(const std::string& path);
        Json::Value get() const;
        bool set(const Json::Value& config);
    private:
        Json::Value config_;
        std::string path_;
    };
}
