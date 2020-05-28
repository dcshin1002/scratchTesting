#include "BuisinessLogic.h"
#include <json/json.h>
#include <iostream>
#include <stdexcept>
#include <string>

Producer::Producer(Province* aProvince, Json::Value const& data) {
    province = aProvince;
    cost = data["cost"].asInt();
    name = data["name"].asString();
    production = data["production"].empty() ? 0 : data["production"].asInt();
}

std::string Producer::getName() {
    return name;
}
int Producer::getCost() {
    return cost;
}
void Producer::setCost(int cost) {
    this->cost = cost;
}
int Producer::getProduction() {
    return production;
}
void Producer::setProduction(std::string const& amountStr) {
    int amount = 0;
    int newProduction = 0;
    try {
        amount = std::stoi(amountStr);
        newProduction = amount;
    } catch (std::exception const& e) {
        std::cout << e.what() << std::endl;
    }
    province->totalProduction += newProduction - production;
    production = newProduction;
}

Province::Province(Json::Value const& doc) {
    name = doc["name"].asString();
    totalProduction = 0;
    demand = doc["demand"].asInt();
    price = doc["price"].asInt();
    for (Json::Value const& each : doc["producers"]) {
        addProducer(new Producer(this, each));
    }
}

Province::~Province() {
    for (Producer* each : producers) {
        delete each;
        each = NULL;
    }
}

void Province::addProducer(Producer* p) {
    producers.push_back(p);
    totalProduction += p->getProduction();
}

std::string Province::getName() {
    return name;
}
std::vector<Producer*> Province::getProducer() {
    return producers;
}
int Province::getTotalProduction() {
    return totalProduction;
}
void Province::setTotalProduction(int arg) {
    totalProduction = arg;
}
int Province::getDemand() {
    return demand;
}
void Province::setDemand(std::string const& arg) {
    demand = std::stoi(arg);
}
int Province::getPrice() {
    return price;
}
void Province::setPrice(std::string const& arg) {
    price = std::stoi(arg);
}

/* 생산 부족분 계산 */
int Province::getShortFall() {
    return demand - totalProduction;
}

/* 수익 계산 */
int Province::getProfit() {
    return getDemandValue() - getDemandCost();
}
int Province::getDemandValue() {
    return getSatisfiedDemand() * price;
}
int Province::getSatisfiedDemand() {
    return std::min(demand, totalProduction);
}
int Province::getDemandCost() {
    int remainingDemand = demand;
    int result = 0;
    // sort producers
    // contribution 계산
    return result;
}
