#include <gtest/gtest.h>

#include "BuisinessLogic.h"

struct BuisinessLogicTest : public testing::Test {
    Province* aProvince;
    Json::Value sampleProvinceData() {
        std::string const sample = R"(
            {
                "name": "Asia",
                "producers": [
                    { "name": "Byzantium", "cost": 10, "production": 9 },
                    { "name": "Attalia", "cost": 12, "production": 10 },
                    { "name": "Sinope", "cost": 10, "production": 6 },
                ],
                "demand": 30,
                "price": 20
            }
        )";
        Json::Value result;
        Json::CharReaderBuilder builder;
        Json::CharReader* reader = builder.newCharReader();
        JSONCPP_STRING errs;
        bool parsed = reader->parse(sample.c_str(), sample.c_str() + sample.size(), &result, &errs);
        delete reader;

        return result;
    }

    void SetUp() override {
        aProvince = new Province(sampleProvinceData());
    }
    void TearDown() override {
        delete aProvince;
    }
};



TEST_F(BuisinessLogicTest, JustRun) {
    std::cout << "first test" << std::endl;
}

TEST_F(BuisinessLogicTest, FirstTest) {
    std::cout << "second test" << std::endl;
    EXPECT_EQ(aProvince->getShortFall(), 5);
}

// PATH_TO_JSON : exported path from pre-definition
int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}