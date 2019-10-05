#pragma once
#include "pch.h"
#include <string>
using namespace std;

class UnidaysDiscountChallenge
{
public:
	UnidaysDiscountChallenge(float priceA, float priceB, float priceC, float priceD, float priceE);
	UnidaysDiscountChallenge();
	void AddToBasket(char item);
	float CalculateTotalPrice();

private:
	float PriceItemA = 8.00;
	float PriceItemB = 12.00; 
	float PriceItemC = 4.00;
	float PriceItemD = 7.00; 
	float PriceItemE = 5.00;

	float StandardDiscountB = 20.00;
	float StandardDiscountC = 10.00;

	int PricingRuleB = 2;
	int PricingRuleC = 3;
	int PricingRuleD = 2;
	int PricingRuleE = 3;

	int itemANumber = 0;
	int itemBNumber = 0;
	int itemCNumber = 0;
	int itemDNumber = 0;
	int itemENumber = 0;

	float DiscountPriceItemA = 0.00;
	float DiscountPriceItemB = 0.00;
	float DiscountPriceItemC = 0.00;
	float DiscountPriceItemD = 0.00;
	float DiscountPriceItemE = 0.00;

	float Total = 0.00;
	float DeliveryCharge = 7.00;
};