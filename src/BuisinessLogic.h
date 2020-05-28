#include <json/json.h>
#include <string>

struct Province;
struct Producer {
    Province* province;
    int cost;
    std::string name;
    int production;

    Producer(Province* aProvince, Json::Value const& data);
    std::string getName();
    int getCost();
    void setCost(int cost);
    int getProduction();
    void setProduction(std::string const& amountStr);
};

struct Province {
    std::string name;
    std::vector<Producer*> producers;
    int totalProduction;
    int demand;
    int price;

    Province(Json::Value const& doc);
    virtual ~Province();

    void addProducer(Producer* p);

    std::string getName();
    std::vector<Producer*> getProducer();
    int getTotalProduction();
    void setTotalProduction(int arg);
    int getDemand();
    void setDemand(std::string const& arg);
    int getPrice();
    void setPrice(std::string const& arg);

    /* 생산 부족분 계산 */
    int getShortFall();

    /* 수익 계산 */
    int getProfit();
    int getDemandValue();
    int getSatisfiedDemand();
    int getDemandCost();
};