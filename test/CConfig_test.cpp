#include "CConfig.h"

#include "glog/logging.h"
#include "gtest/gtest.h"

class TestCConfig : public ::testing::Test
{
public:
    virtual void SetUp() {
        std::cout << "SetUp" << std::endl;
    }

    virtual void TearDown() {
        std::cout << "TearDown" << std::endl;
    }

    Infra::CConfig *config;
};


TEST_F(TestCConfig, PushBack) {
    //LOG(INFO) << "TEST_F test";
}

