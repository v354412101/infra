#pragma once

#include "json/json.h"
#include "CFile.h"

namespace Infra {
    class CConfig {
    public:
        CConfig(const std::string& path);
        ~CConfig();
        bool init();

        Json::Value get();
        bool set(const Json::Value& config);

    private:
        Json::Value config_;
        std::string path_;
        CFile *config_file_;
    };
}
