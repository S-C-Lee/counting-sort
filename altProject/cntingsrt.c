// 8888ba.88ba                                      dP       888888ba                    dP                                        dP          
// 88  `8b  `8b                                     88       88    `8b                   88                                        88          
// 88   88   88 .d8888b. dP    dP .d8888b. 88d888b. 88  .dP  88     88 .d8888b. .d8888b. 88d888b. 88d888b. .d8888b. 88d888b. .d888b88 .d8888b. 
// 88   88   88 88'  `88 88    88 88'  `88 88'  `88 88888"   88     88 88ooood8 Y8ooooo. 88'  `88 88'  `88 88'  `88 88'  `88 88'  `88 88ooood8 
// 88   88   88 88.  .88 88.  .88 88.  .88 88    88 88  `8b. 88    .8P 88.  ...       88 88    88 88.  .88 88.  .88 88    88 88.  .88 88.  ... 
// dP   dP   dP `88888P8 `8888P88 `88888P8 dP    dP dP   `YP 8888888P  `88888P' `88888P' dP    dP 88Y888P' `88888P8 dP    dP `88888P8 `88888P' 
//                            .88                                                                 88                                           
//                        d8888P                                                                  dP                                           

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

//defining variables
#define tenThousand 10000
#define aMillion 1000000
#define hundredThousand 100000

//Functions
void countingSort(int array[], int size, int max)
{
    int k;

    int *count;
    count = malloc(sizeof(int) * size);
    
    for (int i = 0; i < size; ++i)
    {
        count[i] = 0;
    }
    
    for (int i = 0; i < size; ++i)
    {
        count[array[i]] = count[array[i]] + 1;
    }

    k = 0;
    for (int i = 0; i <= max; ++i)
    {
        for (int j = 1; j <= count[i]; ++j)
        {
            array[k] = i;
            ++k;
            //printf("%d ", i);
        }
    }
    printf("\n\n\nSUCCESS!\n\n\n");
    free(count);
}

int maxValue(int array[], size_t size)
{
    //making sure of the proper size to avoid overflow:
    assert(array && size);
    size_t i;
    int maxValue = array[0];

    for (i = 1; i < size; ++i)
    {
        if (array[i] > maxValue)
        {
            maxValue = array[i];
        }
    }
    return maxValue;
}

//Main
int main(int argc, char const *argv[])
{
    srand(time(0)); //Time dependent seed
    //allocating heap memory for arrays:

    int *arrTT;
    arrTT = malloc(sizeof(int) * tenThousand);

    int *arraM;
    arraM = malloc(sizeof(int) * aMillion);

    int *arrhT;
    arrhT = malloc(sizeof(int) * hundredThousand);

    //initialising random arrays to sort them later
    for (int i = 0; i < tenThousand; i++)
    {
        arrTT[i] = rand() % 201;
        //printf("%d\t", arrTT[i]);
    }
    for (int i = 0; i < aMillion; i++)
    {
        arraM[i] = rand() % 201;
        //printf("%d\t", arraM[i]);
    }
    for (int i = 0; i < hundredThousand; i++)
    {
        arrhT[i] = rand() % 201;
        //printf("%d\t", arrhT[i]);
    }

    //finding the max value for each array

    int maxTT = maxValue(arrTT, sizeof(arrTT) / sizeof(arrTT[0]));
    //printf("\n\nMax Values: \n\n\n\n\n\n%d", maxTT);
    int maxaM = maxValue(arraM, sizeof(arraM) / sizeof(arraM[0]));
    //printf("\n%d", maxaM);
    int maxhT = maxValue(arrhT, sizeof(arrhT) / sizeof(arrhT[0]));
    //printf("\n%d", maxhT);
    //sorting them using the above function

    countingSort(arrTT, tenThousand, maxTT);
    free(arrTT);
    
    countingSort(arraM, aMillion, maxaM);
    free(arraM);
    
    countingSort(arrhT, hundredThousand, maxhT);
    free(arrhT);
    
    return 0;
}
