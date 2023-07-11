/*
*****************************************************************************
						  Workshop - #8 (P1)
Full Name  : Aryankumar Niteshkumar Patel
Student ID#: 103094215
Email      : anpatel34@myseneca.ca
Section    : NNN

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

// User Libraries
#include "w8p2.h"




// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* n)
{
	int i;
	do {
		scanf("%d", &i);
		if (i <= 0)
			printf("ERROR: Enter a positive value: ");
	} while (i <= 0);
	if (n != NULL)
		*n = i;
	return i;
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* d) {
	double x;
	do
	{
		scanf("%lf", &x);
		if (x <= 0)
			printf("ERROR: Enter a positive value: ");
	} while (x <= 0);
	if (d != NULL)
		*d = x;
	return x;
}


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int dry_food_bags)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", dry_food_bags);
	printf("NOTE: A 'serving' is %dg\n", GRAMS_PER_SERVING);
	return;
}


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int n)
{
	struct CatFoodInfo cat_food;
	printf("\nCat Food Product #%d\n", n + 1);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&cat_food.sku);
	printf("PRICE         : $");
	getDoublePositive(&cat_food.prices);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&cat_food.weight);
	printf("CALORIES/SERV.: ");
	getIntPositive(&cat_food.calories);
	return cat_food;
}



// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void DisplayCatFoodData(const int sku, const double* prices, const double* weight, const int calories) 
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *prices, *weight, calories);
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* wt_in_lbs, double* wt_in_kg) 
{
	double final_wt_kg;
	final_wt_kg = *wt_in_lbs / LBS_TO_KG;
	if (wt_in_kg != 0) 
	{
		*wt_in_kg = final_wt_kg;
	}
	return final_wt_kg;
}



// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbs, int* kg) 
{
	double wt_in_lbs = *lbs, wt_in_kg;
	convertLbsKg(&wt_in_lbs, &wt_in_kg);
	if (kg != 0) 
	{
		*kg = wt_in_kg * 1000;
	}
	return wt_in_kg * 1000;
}


// 10. convert lbs: kg and g
void convertLbs(const double* con_to_g_kg, double* con_to_kg, int* con_to_g)
{
	convertLbsKg(con_to_g_kg, con_to_kg);
	convertLbsG(con_to_g_kg, con_to_g);
}



// 11. calculate: servings based on gPerServ
double calculateServings(const int serving_wt_in_gms, const int total_gms, double* result_serving_in_gms)
{
	double serving;
	serving = (double)total_gms / serving_wt_in_gms;
	/*if (result_serving_in_gms != 0)*/
	//{
		*result_serving_in_gms = serving;
	//}
	return serving;
}


// 12. calculate: cost per serving
//double calculateCostPerServing(const double* product_price, const double* total_serves, double* cost_per_serve) {
double calculateCostPerServing(const double* product_price, const double* total_serves, double* cost_per_serve) {
	double cost;
	cost = *product_price / *total_serves;
	if (product_price != NULL && total_serves != NULL) 
	{
		*cost_per_serve = cost;

	}
	return cost;

}



// 13. calculate: cost per calorie
double calculateCostPerCal(const double* prices, const double* total_calories, double* cost_per_cal) 
{
	double result;
	result = *prices / *total_calories;
	if (prices != NULL && cost_per_cal != NULL)
	{
		*cost_per_cal = result;
	}
	return result;
}


// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo cat_food_info)
{
	struct ReportData report = { 0 };
	double total_cal;
	report.sku = cat_food_info.sku;
	report.prices = cat_food_info.prices;
	report.weight = cat_food_info.weight;
	convertLbs(&report.weight, &report.kilograms, &report.grams);
	report.calories = cat_food_info.calories;
	calculateServings(GRAMS_PER_SERVING, report.grams, &report.servings);
	calculateCostPerServing(&report.prices, &report.servings, &report.cost_per_serving);
	total_cal = report.servings * report.calories;
	calculateCostPerCal(&report.prices, &total_cal, &report.cost_cal_per_serving);

	return report;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", GRAMS_PER_SERVING);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(struct ReportData catfoodpricereport, const int convenient_product)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", catfoodpricereport.sku, catfoodpricereport.prices, catfoodpricereport.weight, catfoodpricereport.kilograms, catfoodpricereport.grams, catfoodpricereport.calories, catfoodpricereport.servings, catfoodpricereport.cost_per_serving, catfoodpricereport.cost_cal_per_serving);

	if (convenient_product)
	{
		printf(" ***");
	}
	printf("\n");
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catfoodpricereport)
{
	printf("\nFinal Analysis\n--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n", catfoodpricereport.sku, catfoodpricereport.prices);
	printf("\nHappy shopping!\n");

}


// ----------------------------------------------------------------------------
// 7. Logic entry point

void start()
{
	struct CatFoodInfo catfoodinfo[MAX_NUM_PRODUCTS] = { {0} };
	struct ReportData reportData[MAX_NUM_PRODUCTS] = { { 0 } };
	int i, j, cheapest_option_index = 0;
	openingMessage(MAX_NUM_PRODUCTS);
	for (i = 0; i < MAX_NUM_PRODUCTS; i++)
	{
		catfoodinfo[i] = getCatFoodInfo(i);
		reportData[i] = calculateReportData(catfoodinfo[i]);

		if (reportData[i].cost_cal_per_serving < reportData[cheapest_option_index].cost_cal_per_serving)
		{
			cheapest_option_index = i;
		}
	}
	printf("\n");
	displayCatFoodHeader();

	for (i = 0; i < MAX_NUM_PRODUCTS; i++)
	{
		DisplayCatFoodData(catfoodinfo[i].sku, &catfoodinfo[i].prices, &catfoodinfo[i].weight, catfoodinfo[i].calories);
	}
	printf("\n");

	displayReportHeader();
	for (i = 0; i < MAX_NUM_PRODUCTS; i++)
	{
		int cheaper = 0;
		if (i == cheapest_option_index)
		{
			cheaper++;
		}

			

		
		displayReportData(reportData[i], cheaper);
		
	}
	displayFinalAnalysis(catfoodinfo[cheapest_option_index]);
}

