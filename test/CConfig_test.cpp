#include "CConfig.h"

#include "glog/logging.h"
#include "gtest/gtest.h"


TEST(CConfig, get) {
    auto config = new Infra::CConfig();
    ASSERT_TRUE(config->init("/home/user1/config/url.config")) << "config->init";
    LOG(INFO) << config->get().toStyledString();
    delete config;
    config = nullptr;
}


TEST(CConfig, set) {
    auto config = new Infra::CConfig();
    ASSERT_TRUE(config->init("/home/user1/config/url.config")) << "config->init";
    auto cfg = config->get();
    LOG(INFO) << cfg.toStyledString();
    cfg["IPCInfo"][0u]["password"] = "abc";
    bool bRet = config->set(cfg);
    if (!bRet) {
        LOG(ERROR) << "config->set bRet = " << bRet;
        return ;
    }

    auto cfg_new = config->get();
    LOG(INFO) << cfg_new.toStyledString();

    delete config;
    config = nullptr;
}

