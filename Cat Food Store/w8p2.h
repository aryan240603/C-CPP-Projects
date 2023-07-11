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

#define MAX_NUM_PRODUCTS 3
#define GRAMS_PER_SERVING 64
#define LBS_TO_KG 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo 
{
	int sku;
	double prices;
	int calories;
	double weight;
};
struct ReportData 
{
	int sku;
	double prices;
	int calories;
	double weight;
	double kilograms;
	int grams;
	double servings;
	double cost_per_serving;
	double cost_cal_per_serving;
};

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* i);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* d);


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int);


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int);



// 5. Display the formatted table header
void displayCatFoodHeader();


//// 6. Display a formatted record of cat food data
void DisplayCatFoodData(const int , const double* , const double* , const int );




// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg

double convertLbsKg(const double* kg, double* lbs);

// 9. convert lbs: g
int convertLbsG(const double* lbs, int* g);


// 10. convert lbs: kg / g
void convertLbs(const double* lbs, double* kg, int* g);


// 11. calculate: servings based on gPerServ
double calculateServings(const int, const int, double*);

// 12. calculate: cost per serving

double calculateCostPerServing(const double* product_price, const double* total_no_of_serving, double* cost_per_serve);

// 13. calculate: cost per calorie

double calculateCostPerCal(const double* prices, const double* total_calories, double* cost_per_cal);

// 14. Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(const struct CatFoodInfo cat_food_info);


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table

void displayReportData(struct ReportData catfoodpricereport, const int convenient_product);


// 17. Display the findings (cheapest)

void displayFinalAnalysis(const struct CatFoodInfo catfoodpricereport);


// ----------------------------------------------------------------------------

// 7. Logic entry point

void start();