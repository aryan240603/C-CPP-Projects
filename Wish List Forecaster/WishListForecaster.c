/**********************Created by Aryan Patel*************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min_item_liked 1
#define max_item_liked 10
#define TO_ITEMS 10
int main(void) {


	const double minimum_income = 500.00, maximum_income = 400000.00;
	double total_income, total_value = 0, c, total_months;
	int total_item, priority, x = 0, first_priority[TO_ITEMS], priority_finance[TO_ITEMS], entered_priority, forecast_selection, flag_1 = 1, flag_2 = 1, flag_3, flag_4 = 0;
	double cost[TO_ITEMS], total_priority = 0, total_amount = total_value;
	char f;
	double cost_flag = 0;
	int first_priority_flag = 0;
	char priority_finance_flag = 0;
	


	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");
	do {
		flag_1 = 1;
		flag_2 = 1;

		printf("\nEnter your monthly NET income: $");
		scanf("%lf", &total_income);



		if (total_income < minimum_income) 
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n");

			flag_1 = 0;

		}
		if (total_income > maximum_income)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");

			flag_2 = 0;

		}

	} while (flag_1 == 0 || flag_2 == 0);

	do {
		flag_1 = 1;
		flag_2 = 1;

		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &total_item);

		if (total_item < min_item_liked || total_item > max_item_liked)
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
			flag_1 = 0;
		}
	} while (total_item < min_item_liked || total_item > max_item_liked);

	for (x = 0; x < total_item; x++)
	{
		printf("\nItem-%d Details:", x + 1);
		

		do {
			printf("\n   Item cost: $");
			scanf("%lf", &c);
			if (c < 100) {
				cost_flag = 0;
				printf("      ERROR: Cost must be at least $100.00");
			}
			else
			{
				cost_flag = 1;
				cost[x] = c;
			}
		} while (cost_flag == 0);

		
		do {

			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");

			scanf("%d", &priority);

			if (priority < 1 || priority > 3) 
			{
				first_priority_flag = 0;
				printf("      ERROR: Value must be between 1 and 3\n");
			}
			else 
			{
				first_priority_flag = 1;
				first_priority[x] = priority;
			}
		} while (first_priority_flag == 0);
		

		do {

			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &f);

			if (f != 'y' && f != 'n')
			{
				priority_finance_flag = 0;
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
			else
			{
				priority_finance_flag = 1;
				priority_finance[x] = f;
			}
		} while (priority_finance_flag == 0);
	}
	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");

	for (x = 0; x < total_item; x++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", x + 1, first_priority[x], priority_finance[x], cost[x]);

		total_value += cost[x];
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n", total_value);



	do
	{
		total_amount = total_value;
		total_priority = 0;
		flag_4 = 0;

		printf("\nHow do you want to forecast your wish list?");
		printf("\n 1. All items (no filter)");
		printf("\n 2. By priority");
		printf("\n 0. Quit/Exit");

		printf("\nselection: ");
		scanf("%d", &forecast_selection);

		if (forecast_selection == 0)
		{
			flag_4 = 1;
			printf("\nBest of luck in all your future endeavours!\n");
		}
		else if (forecast_selection == 1)
		{
			total_months = ((total_amount / total_income) + 1);
			printf("\n====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%1.2lf\n", total_amount);
			printf("Forecast: %d years, %d months\n", (int)total_months / 12, (int)total_months % 12);

			flag_3 = 0;
			for (x = 0; x < total_item; x++)
			{
				if (priority_finance[x] == 'y') 
				{
					flag_3 = 1;
				}
			}
			if (flag_3 == 1) 
			{
				printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.");
			}
			printf("\n====================================================\n");
		}
		else if (forecast_selection == 2)
		{
			flag_3 = 0;
			printf("\nWhat priority do you want to filter by? [1-3]: ");
			scanf("%d", &entered_priority);
			printf("\n====================================================\n");
			printf("Filter:   by priority (%d)", entered_priority);
			for (x = 0; x < total_item; x++)
			{
				if (first_priority[x] == entered_priority)
				{
					total_priority += cost[x];
					if (priority_finance[x] == 'y')

					{
						flag_3 = 1;
					}
				}

			}
			printf("\nAmount:   $%1.2lf", total_priority);
			total_months = ((total_priority / total_income) + 1);


			printf("\nForecast: %d years, %d months", (int)total_months / 12, (int)total_months % 12);
			if (flag_3 == 1)
			{
				printf("\nNOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.");
			}

			printf("\n====================================================\n");
		}
		else
		{
			printf("\nERROR: Invalid menu selection.\n");
		}
	} while (flag_4 == 0);

	return 0;
}