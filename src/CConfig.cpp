#include "CConfig.h"

#include "Common.h"
#include <string.h>

#include <memory>

#include <iostream>
#include <sstream>

namespace Infra {
    CConfig::CConfig(const std::string& path)
        : config_(Json::Value::null),
          path_(path),
          config_file_(new CFile()) {

    }

    CConfig::~CConfig() {
        delete config_file_;
        config_file_ = nullptr;
    }

    Json::Value CConfig::get() {
        return config_;
    }

    bool CConfig::set(const Json::Value &config) {
        bool ret = false;

        if (config_file_->open(path_.c_str(), "w+")) {
            const char* str_config = config.asCString();
            size_t config_len = strlen(str_config);
            if (config_file_->write(str_config, config_len, 1) == config_len) {
                config_ = config;
                ret = true;
            }
            config_file_->close();
        }

        return ret;
    }

    bool CConfig::init() {
        bool ret = false;
        if (CFile::is_exist(path_)) {
            if (config_file_->open(path_.c_str(), "r")) {
                int file_size = CFile::get_file_size(path_);
                char *file_buf = new char[file_size];
                if (config_file_->read(file_buf, file_size, 1) == file_size) {
                    Json::CharReaderBuilder readerBuilder;
                    std::unique_ptr<Json::CharReader> const jsonReader(readerBuilder.newCharReader());
                    JSONCPP_STRING errs;
                    bool parse_ret = jsonReader->parse(file_buf, file_buf + file_size, &config_, &errs);
                    if (parse_ret && errs.empty()) {
                        ret = true;
                    }
                }
                safe_freepa(file_buf);
                config_file_->close();
            }
        } else {
            config_["version"] = "0.0.0";
            std::ostringstream os;
            Json::StreamWriterBuilder writerBuilder;
            std::unique_ptr<Json::StreamWriter> jsonWriter(writerBuilder.newStreamWriter());
            jsonWriter->write(config_, &os);
            const char* str_config = os.str().data();
            std::cout << os.str().data() << std::endl;
            size_t config_len = strlen(str_config);
            if (config_file_->open(path_.c_str(), "w+")) {
                if (config_file_->write(str_config, config_len, 1) == config_len) {
                    ret = true;
                }
                config_file_->close();
            }

            config_.clear();
            config_ = Json::Value::null;
        }

        return ret;
    }
}