// FrancescaBlidarCodingChallenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "UnidaysDiscountChallenge.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	UnidaysDiscountChallenge order; //creating an instance of the class

	int addMore = 1; //variable used to check if the user wants to add more items to the basket or not
	char itemAdded;
	float result = 0; //stores the final price of the basket

	while (addMore != 0)
	{
		cout << "Add item to basket: "; cin >> itemAdded;
		itemAdded = toupper(itemAdded); //capitalize the user input

		while ((itemAdded < 65) || (itemAdded > 69)) //check if the user input is valid using ASCII codes
		{
			cout << "Please insert a valid item name." << endl;
			cout << "Add item to basket: "; cin >> itemAdded;
			itemAdded = toupper(itemAdded);
		}
		cout << endl;
		order.AddToBasket(itemAdded);
		cout << "To finish order, press 0. To continue, press 1."; cin >> addMore;
		cout << endl;
	}

	result = order.CalculateTotalPrice();
	cout << "Overal total:" << result;

	return 0;
}

UnidaysDiscountChallenge::UnidaysDiscountChallenge(float priceA, float priceB, float priceC, float priceD, float priceE)
{
	PriceItemA = priceA;
	PriceItemB = priceB;
	PriceItemC = priceC;
	PriceItemD = priceD;
	PriceItemE = priceE;
}

UnidaysDiscountChallenge::UnidaysDiscountChallenge()
{
}

void UnidaysDiscountChallenge::AddToBasket(char item)
{
	//storing the number of each item in the variable item[itemName]Number (initially set to 0)
	if (item == 'A')
	{
		itemANumber++;
	}
	else
		if (item == 'B')
		{
			itemBNumber++;
		}
		else
			if (item == 'C')
			{
				itemCNumber++;
			}
			else
				if (item == 'D')
				{
					itemDNumber++;
				}
				else
					if (item == 'E')
					{
						itemENumber++;
					}
}

float UnidaysDiscountChallenge::CalculateTotalPrice()
{
	DiscountPriceItemA = itemANumber * PriceItemA; //item A does not have any discount

	//Pricing rule: 2 for £20.00 
	if (itemBNumber % PricingRuleB == 0) 
	{
		DiscountPriceItemB = (itemBNumber / PricingRuleB)*StandardDiscountB;
	}
	else
		if ((itemBNumber - 1) % PricingRuleB == 0)
		{
			DiscountPriceItemB = (itemBNumber / PricingRuleB)*StandardDiscountB + PriceItemB;
		}

	//Pricing rule: 3 for £10.00
	if (itemCNumber % PricingRuleC == 0)
	{
		DiscountPriceItemC = (itemCNumber / PricingRuleC)*StandardDiscountC;
	}
	else
		if ((itemCNumber - 1) % PricingRuleC == 0)
		{
			DiscountPriceItemC = (itemCNumber / PricingRuleC)*StandardDiscountC + PriceItemC;
		}
		else
			if ((itemCNumber - 2) % PricingRuleC == 0)
			{
				DiscountPriceItemC = (itemCNumber / PricingRuleC)*StandardDiscountC + 2 * PriceItemC;
			}

	//Pricing rule: Buy 1 get 1 free 
	if (itemDNumber % PricingRuleD == 0)
	{
		DiscountPriceItemD = (itemDNumber / PricingRuleD)*PriceItemD;
	}
	else
	{
		DiscountPriceItemD = (itemDNumber / PricingRuleD)*PriceItemD + PriceItemD;
	}

	//Pricing rule: 3 for the price of 2
	if (itemENumber % PricingRuleE == 0)
	{
		DiscountPriceItemE = (itemENumber / PricingRuleE)*(2*PriceItemE);
	}
	else
		if ((itemENumber - 1) % PricingRuleE == 0)
		{
			DiscountPriceItemE = (itemENumber / PricingRuleE)*(2 * PriceItemE) + PriceItemE;
		}
		else
			if ((itemENumber - 2) % PricingRuleE == 0)
			{
				DiscountPriceItemE = (itemENumber / PricingRuleE)*(2 * PriceItemE) + 2 * PriceItemE;
			}

	Total = DiscountPriceItemA + DiscountPriceItemB + DiscountPriceItemC + DiscountPriceItemD + DiscountPriceItemE;
	
	if (Total >= 50.00)
	{
		DeliveryCharge = 0.00;
	}

	return Total + DeliveryCharge;

}

