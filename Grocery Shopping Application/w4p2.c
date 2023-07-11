#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int want_more, apple, oranges, pears, tomatoes, cabbages, picked_apple = 0,
        picked_oranges = 0, picked_pears = 0, picked_tomatoes = 0, picked_cabbages = 0;

    do   //1

    {
        printf("Grocery Shopping\n");
        printf("================\n");
        do
        {
            printf("How many APPLES do you need? :");
            scanf(" %d", &apple);
            if (apple < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                printf("\n");
            }
        } while (apple < 0);


        do
        {
            printf("How many ORANGES do you need? :");
            scanf(" %d", &oranges);
            if (oranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                printf("\n");
            }
        } while (oranges < 0);

        do
        {
            printf("How many PEARS do you need? :");
            scanf(" %d", &pears);
            if (pears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                printf("\n");
            }
        } while (pears < 0);


        do
        {
            printf("How many TOMATOES do you need? :");
            scanf(" %d", &tomatoes);
            if (tomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                printf("\n");
            }
        } while (tomatoes < 0);


        do
        {
            printf("How many CABBAGES do you need? :");
            scanf(" %d", &cabbages);
            if (cabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                printf("\n");
            }
        } while (cabbages < 0);

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n");
        if (apple != 0)
        {
            do
            {
                printf("\nPick some APPLES... how many did you pick? :");
                scanf(" %d", &picked_apple);

                if (picked_apple < apple && picked_apple > 0)
                {
                    printf("Looks like we still need some APPLES... \n");
                    apple -= picked_apple;
                }
                else if (picked_apple > apple && picked_apple > 0)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", apple);
                }
                else if (picked_apple <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else
                {
                    printf("Great, that's the apples done!\n");
                    apple -= picked_apple;
                }
            } while (apple > 0);
        }

        if (oranges != 0)
        {
            do
            {
                printf("\nPick some APPLES... how many did you pick? :");
                scanf(" %d", &picked_oranges);

                if (picked_oranges < oranges && picked_oranges > 0)
                {
                    printf("Looks like we still need some APPLES... \n");
                    oranges -= picked_oranges;
                }
                else if (picked_oranges > oranges && picked_oranges > 0)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", oranges);
                }
                else if (picked_oranges <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else
                {
                    printf("Great, that's the orpears done!\n");
                    oranges -= picked_oranges;
                }
            } while (oranges > 0);
        }

        if (pears != 0)
        {
            do
            {
                printf("\nPick some PEARS... how many did you pick? :");
                scanf(" %d", &picked_pears);

                if (picked_pears < pears && picked_pears > 0)
                {
                    printf("Looks like we still need some PEARS... \n");
                    apple -= picked_apple;
                }
                else if (picked_pears > pears && picked_pears > 0)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
                }
                else if (picked_pears <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else
                {
                    printf("Great, that's the pears done!\n");
                    pears -= picked_pears;
                }
            } while (pears > 0);
        }

        if (tomatoes != 0)
        {
            do
            {
                printf("\nPick some TOMATOES... how many did you pick? :");
                scanf(" %d", &picked_tomatoes);

                if (picked_tomatoes < tomatoes && picked_tomatoes > 0)
                {
                    printf("Looks like we still need some TOMATOES... \n");
                    tomatoes -= picked_tomatoes;
                }
                else if (picked_tomatoes > tomatoes && picked_tomatoes > 0)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
                }
                else if (picked_tomatoes <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else
                {
                    printf("Great, that's the tomatoes done!\n");
                    tomatoes -= picked_tomatoes;
                }
            } while (tomatoes > 0);
        }

        if (cabbages != 0)
        {
            do
            {
                printf("\nPick some CABBAGES... how many did you pick? :");
                scanf(" %d", &picked_cabbages);

                if (picked_cabbages < cabbages && picked_cabbages > 0)
                {
                    printf("Looks like we still need some CABBAGES... \n");
                    cabbages -= picked_cabbages;
                }
                else if (picked_cabbages > cabbages && picked_cabbages > 0)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
                }
                else if (picked_cabbages <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else
                {
                    printf("Great, that's the cabbages done!\n");
                    cabbages -= picked_cabbages;
                }
            } while (cabbages > 0);
        }

        printf("\nAll the items are picked!\n");

        printf("Do another shopping? (0=NO):");
        scanf(" %d", &want_more);

    } while (want_more != 0);           //do


       //1*


    return 0;
}