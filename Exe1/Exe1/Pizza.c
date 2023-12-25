#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//Elinor Zalogin
//id: 208324863

//input: id= num of maximum 9 digits, number of pizza, length and width of pizza, dough type, part of olives and mushrroms in pizza, delivery, money to pay
//output: print logo, menu, number of pizza to order, order details includes: id of customer, size of ordered pizza, total price of order per pizza (2 digits after point ), total price of all pizza and
//total price with tax, and number of change in coints.

#define BASIC_PIZZA_SIZE 1600.0//surface of basic pizza
#define BASIC_PIZZA_PRICE 60//price of a basic pizza
#define OLIVES_TOPPING_PRICE 10//price of olives topping
#define MUSHROOMS_TOPPING_PRICE 12//price of mushrooms topping
//#define DOUGH_TYPE_PRICE 3;// price of unregular dough;
#define TAX 0.17//tax percent
#define TWO_COIN 2//2 coin
#define FIVE_COIN 5//5 coin
#define TEN_COIN 10//10 coin

typedef struct pizza {
	int length;//length of  pizza
	int width;//width of pizza;
	char dough_type;// type of pizza dough
	int dough_type_price; //price for each dough
	double olives_part;//part of olives in pizza
	double mushrooms_part;//part of mushrooms in pizza
	double price_per_pizza;//price for single pizza

}PIZZA;

void main()
{
	int id;//the id of the customer
	int i; // index of for loop
	double total_price=0.0;//total price of all ordered pizza
	double price_with_tax=0.0;//total price with tax;

	int pizza_count;//number of pizza to order
	int delivery; //delivery of pizza = 1 / 0;
	int customer_payment; //customer's amount of money to pay;
	
	PIZZA pizza;//pizza struct

	int remain_balance = 0;//the remain balace the customer needs to pay 
	int customer_change = 0;//the change for customer

	int coins_2=0, coins_5=0, coins_1=0, coins_10=0;//coins to give change
	//1
	printf("Welcome to MTA-Pizza!\n\n*****\n ***\n  *\n\n");

	//2
	printf("Please enter your ID number:\n");
	scanf("%d", &id);
	
	//3
	printf("\nOur menu:\n*********\nBasic pizza: 60.00 NIS for 40x40 size pizza\n\nToppings for basic size pizza:\nOlives: 10 NIS\nMushrooms: 12 NIS\n\n");
	printf("Dough type for basic size pizza:\nRegular: 0 NIS\nVegan: 5 NIS\nWhole wheat: 3 NIS\nGluten free: 4 NIS\n\n");

	//4
	printf("How many pizzas would you like to order? ");
	scanf("%d", &pizza_count);
	if (pizza_count <= 0)
	{
		printf("Thank you and goodbye.");
	}
	else
	{
		//5
		for (i = 1; i <= pizza_count; i++)
		{

			printf("\n*************************************************\nPizza #%d:\n\n", i);

			printf("Please enter your pizza's length (cm): ");
			scanf("%d", &pizza.length);
			if (!(pizza.length % 2 == 0 && pizza.length >= 10 && pizza.length <= 40))
			{
				printf("Invalid length! Basic length was chosen as a default.\n");
				pizza.length = 40;
			}

			printf("Please enter your pizza's width (cm): ");
			scanf("%d", &pizza.width);


			if (!(pizza.width % 2 == 0 && pizza.width >= 10 && pizza.width <= 80))
			{
				printf("Invalid width! Basic width was chosen as a default.\n");
				pizza.width = 40;
			}


			printf("\nPlease enter the pizza's dough type:\nr - for regular\nv - for vegan\nw - for whole wheat\nf - for gluten-free\n");
			scanf(" %c", &pizza.dough_type);
			if (pizza.dough_type != 'r' && pizza.dough_type != 'v' && pizza.dough_type != 'w' && pizza.dough_type != 'f')
			{
				printf("Invalid choice! Regular dough was chosen as a default.\n");
				pizza.dough_type = 'r';
			}


			printf("\nPlease choose the toppings:\n\nOlives (choose 0-3):\n0. None\n1. Whole pizza\n2. Half pizza\n3. Quarter pizza\n");
			scanf("%lf", &pizza.olives_part);



			switch ((int)pizza.olives_part)
			{

			case 0:
			{
				pizza.olives_part = 0;
				break;
			}
			case 1:
			{
				pizza.olives_part = 1;
				break;
			}
			case 2:
			{
				pizza.olives_part = 0.5;
				break;
			}
			case 3:
			{
				pizza.olives_part = 0.25;
				break;
			}


			default:
				pizza.olives_part = 0;
				printf("Invalid choice! Current topping not added.\n");
				break;
			}



			printf("\nMushrooms (choose 0-3):\n0. None\n1. Whole pizza\n2. Half pizza\n3. Quarter pizza\n");
			scanf("%lf", &pizza.mushrooms_part);

			switch ((int)pizza.mushrooms_part)
			{

			case 0:
			{
				pizza.mushrooms_part = 0;
				break;
			}
			case 1:
			{
				pizza.mushrooms_part = 1;
				break;
			}
			case 2:
			{
				pizza.mushrooms_part = 0.5;
				break;
			}
			case 3:
			{
				pizza.mushrooms_part = 0.25;
				break;
			}

			default:
				pizza.mushrooms_part = 0;
				printf("Invalid choice! Current topping not added.\n");
				break;
			}

			if (pizza.olives_part + pizza.mushrooms_part > 1)
			{
				printf("You have exceeded the maximum amount of toppings allowed on one pizza! Current topping not added.\n\n");
				pizza.mushrooms_part = 0;
			}


			switch (pizza.dough_type)
			{
			case 'v':
			{
				pizza.dough_type_price = 5;
				break;
			}

			case 'w':
			{
				pizza.dough_type_price = 3;
				break;
			}

			case 'f':
			{
				pizza.dough_type_price = 4;
				break;
			}

			default:
				pizza.dough_type_price = 0;
				break;

			}

			pizza.price_per_pizza = pizza.length * pizza.width / BASIC_PIZZA_SIZE * BASIC_PIZZA_PRICE
				+ pizza.length * pizza.width * pizza.olives_part / BASIC_PIZZA_SIZE * OLIVES_TOPPING_PRICE
				+ pizza.length * pizza.width * pizza.mushrooms_part / BASIC_PIZZA_SIZE * MUSHROOMS_TOPPING_PRICE
				+ pizza.length * pizza.width * pizza.dough_type_price / BASIC_PIZZA_SIZE;

			total_price += pizza.price_per_pizza;

			printf("\nPizza #%d details:\n*******************\nPizza size: %dx%d\nPizza price (without tax): %.2lf\n", i, pizza.length, pizza.width, pizza.price_per_pizza);
		}

		//6
		printf("\n*************************************************\nDo you want delivery for the price of 15 NIS? Enter 1 for delivery or 0 for pick-up: ");
		scanf("%d", &delivery);
		if (delivery != 1 && delivery != 0)
		{
			printf("Invalid choice! Pick-up was chosen as a default.");
			delivery = 0;
		}

		//7
		total_price += delivery * 15;
		price_with_tax = total_price + (total_price * TAX);

		printf("\nYour order details:\n*******************\nID number: %09d\nNumber of pizzas: %d\nTotal price: %.2lf\nTotal price with tax (rounded down): %d\n\n", id, pizza_count, total_price, (int)price_with_tax);

		//8
		printf("Please enter your payment: ");
		scanf("%d", &customer_payment);

		if (customer_payment == (int)price_with_tax)
		{
			printf("Thank you for your order!");
		}
		else
		{
			while (customer_payment < (int)price_with_tax)
			{
				remain_balance = price_with_tax - customer_payment;
				printf("Your remaining balance is: %d\n", remain_balance);
				price_with_tax -= customer_payment;
				printf("Please enter your payment: ");
				scanf("%d", &customer_payment);
			}

			if (customer_payment != (int)price_with_tax)
			{
				printf("Your change is %d NIS using:\n", customer_change);
			}
			customer_change = customer_payment - (int)price_with_tax;
			
			if (customer_change >= TEN_COIN && customer_change / TEN_COIN >= 0)
			{
				coins_10 = customer_change / TEN_COIN;
				customer_change = customer_change - (customer_change / TEN_COIN) * TEN_COIN;

				printf("%d coin(s) of ten\n", coins_10);
			}
			if (customer_change >= FIVE_COIN && customer_change / FIVE_COIN >= 0)
			{
				coins_5 = customer_change / FIVE_COIN;
				customer_change = customer_change - (customer_change / FIVE_COIN) * FIVE_COIN;
				printf("%d coin(s) of five\n", coins_5);
			}
			if (customer_change >= TWO_COIN && customer_change / TWO_COIN >= 0)
			{
				coins_2 = customer_change / TWO_COIN;
				customer_change = customer_change - (customer_change / TWO_COIN) * TWO_COIN;
				printf("%d coin(s) of two\n", coins_2);
			}
			if (customer_change > 0)
			{
				coins_1 = customer_change;
				printf("%d coin(s) of one\n", coins_1);
			}

			printf("Thank you for your order!");

		}
	}
	
}