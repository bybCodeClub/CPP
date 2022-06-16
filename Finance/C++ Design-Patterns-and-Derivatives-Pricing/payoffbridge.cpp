#include "payoffbridge.hpp"

PayOffBridge::PayOffBridge(const PayOffBridge& original){
    TheyPayOffPtr = original.TheyPayOffPtr->clone();
}

PayOffBridge::PayOffBridge(const PayOff& innerPayOff) {
    TheyPayOffPtr = innerPayOff.clone();
}

PayOffBridge::~PayOffBridge() {
    delete TheyPayOffPtr;
}

PayOffBridge& PayOffBridge::operator=(const PayOffBridge& original) {
    if( this != &original) {
        delete TheyPayOffPtr;
        TheyPayOffPtr = original TheyPayOffPtr->clone();
    }

    return *this;
}