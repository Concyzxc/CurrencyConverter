/*
=============================================================================================
FILE		:CurrencyConverter
AUTHOR		: Conrad Nestor B. Mativo, Dhan Jacob Olmilla, Railey Escandor, Gabriel Jret Ouano
DESCRIPTION	: Program Computes Pesos to Dollar, Peso to Won, Peso to Euro, Peso to Pounds
COPYRIGHT	: November 29 2022
=============================================================================================
*/
#include <stdio.h>
#include <string.h>

void ToDollars(double amount, float rate[]); // declaration of the subfunction ToDollars
void ToYen(double amount, float rate[]); // declaration of the subfunction ToYen
void ToWon(double amount, float rate[]); // declaration of the subfunction ToWon
void ToEuro(double amount, float rate[]); // declaration of the subfunction ToEuro
void ToPounds(double amount, float rate[]); // declaration of the subfunction ToPounds

int main(){
    
  double amount; // the user's money
  double dollars, yen, won, euro, pounds; // the currencies 
  int limit; // only applies when you have an amount over 5,700 and above
  int choice; // the user selects what conversion is going to happen
  char retry[20]; // choices for the user to retry the program or not
  float rate[5] = {0.017, 2.47, 23.62, 0.017, 0.015}; // the conversion rates
  int val1 = 0;// this stores the identifier for the strcmp function (0 for true)
  int val2 = 0;//this stores the second identifier for the strcmp function (0 for true)
  

        do{ // do while loop, it will keep on reiterating as long as the condition in while is true
        	  printf("========================================================================================================================");
        	  printf("                                        $Currency Converter$");
			  printf("\nNotice: If you enter an amount over 5,700 pesos or 100 dollars, you would only get 85 percent of the converted amount.\n"); // gives a notice that only 85 percent of the conversion will be given if the user has an amount over 5700 and above
			  printf("========================================================================================================================");
              printf("\n\nPlease select a conversion: "); // instruction for the user
              printf("\nConversion [1]: Pesos to Dollars\n"); // converts pesos to yen
              printf("\nConversion [2]: Pesos to Yen\n"); // converts pesos to yen
              printf("\nConversion [3]: Pesos to Won\n"); // converts pesos to yen
              printf("\nConversion [4]: Pesos to Euro\n"); // converts pesos to yen
              printf("\nConversion [5]: Pesos to Pounds\n"); // converts pesos to yen

              printf("\nEnter your choice: "); // prompts the user to select a conversion
              scanf("%d", &choice); // gets the input from the user
			  getchar();	//this function is used just incase an alphabet is inputted
			  
			
            	while(choice > 5 || choice < 1){ 
                      printf("You have entered an invalid choice, please try again");
                      printf("\nEnter your choice: "); // prompts the user to select a conversion
                      scanf("%d", &choice); // gets the input from the user
                      getchar();	//this function is used just incase an alphabet is inputted   
				}
					
                printf("\nEnter the amount you want to convert: \n");
                  	scanf("%lf", &amount);
    				getchar();
    				
                while(amount>999999999999999){ // if amount entered is to high it will ask for a lower amount
                      printf("\nThe amount you have entered is too high, please try again and enter a lower amount\n");
                      printf("Enter the amount you want to convert: \n");
                      scanf("%lf", &amount);
                }
    
                  switch (choice){// the cases 
                case 1:{ // pesos to dollar conversion
               	 	ToDollars(amount, rate); // calls the ToDollar subfunction
               		 break;
           		}
           		case 2:{ // pesos to yen conversion
           			ToYen(amount, rate); // calls the ToYen subfunction
					break;
				}
				case 3:{ // pesos to won conversion
					ToWon(amount, rate); // calls the ToWon subfunction
					break;
				}
				case 4:{ // pesos to euro conversion
					ToEuro(amount, rate); // calls the ToEuro subfunction
					break;
				}
				case 5:{ // pesos to pound conversion
					ToPounds(amount, rate); //calls the ToPound subfunction
					break;
				}
			}
        
    printf("\n\nDo you want to convert again?");
    printf("\nYes / No: ");// Asks the user if they want to retry again
    scanf("%s", retry);// Stores the input in the variable entry
    
    system("cls"); //clears screen for cleaner program
    
    val1 = strcmp(retry,"Yes"); // Identifer for the retry variable for the loop to keep running
    val2 = strcmp(retry,"yes"); // Second identifier for the retry variable for the loop to keep running
      
}while(val1 == 0 ||  val2==0); // Iteration for the retry variable

}

void ToDollars(double amount, float rate[]){ //computes the coversion
    double limit, dollars;
  		  if (amount > 5700){ // if amount is higher than 5,700
       		 limit = amount * 0.85;    // limit will apply and the amount will only show 85 percent
       		 dollars = limit * rate[0]; // the limit will then be multiplied by the amount of won where 1 pesos = 0.017 dollars
   		 	}
   			else                           // if statement so that this part will work if the amount is lesser than 5,700
       		 dollars = amount * rate[0]; // the amount will be multiplied by 0.017
    printf("-----------------------------------------------------------------");
    printf("\n-     For %.2lf Pesos, you would get = %.2lf $       -", amount, dollars); // shows the user the conversion amount
    printf("\n-----------------------------------------------------------------");
}

void ToYen(double amount,float rate[]){ // computes the conversion
    double limit, yen;
            if(amount>5700){ // if amount is higher than 5,700
                limit = amount * 0.85; // limit will apply and the amount will only show 85 percent
                yen = limit * rate[1]; // the limit will then be multiplied by the amount of won where 1 pesos = 2.47 yen
            }
            else // if statement so that this part will work if the amount is lesser than 5,700
                yen = amount * rate[1]; // the amount will be multiplied by 2.47
        printf("-----------------------------------------------------------------");   
        printf("\n-     For %.2lf Pesos, you would get = %.2lf yen        -", amount, yen); // shows the user the conversion amount
        printf("\n-----------------------------------------------------------------");   
}

void ToWon(double amount,float rate[]){ // computes the conversion
    double limit, won;
        	if(amount>5700){ // if amount is higher than 5,700
                limit = amount * 0.85; // limit will apply and the amount will only show 85 percent
                won = limit * rate[2]; // the limit will then be multiplied by the amount of won where 1 pesos = 23.62 won
            }
            else // if statement so that this part will work if the amount is lesser than 5,700
                won = amount * rate[2]; // the amount will be multiplied by 23.62
    printf("-----------------------------------------------------------------");        
    printf("\n-       For %.2lf Pesos, you would get = %.2lf won         -", amount, won); // shows the user the conversion amount
    printf("\n-----------------------------------------------------------------");

}

void ToEuro(double amount,float rate[]){ // computes the conversion
    double limit, euro;
            if(amount>5700){ // if amount is higher than 5,700
                limit = amount * 0.85; // limit will apply and the amount will only show 85 percent
                euro = limit * rate[3]; // the limit will then be multiplied by the amount of euro where 1 pesos = 0.017 Euro
            }
            else // if statement so that this part will work if the amount is lesser than 5,700
                euro = amount * rate[3]; // the amount will be multiplied by 0.017
    printf("-----------------------------------------------------------------");
    printf("\n-        For %.2lf Pesos, you would get = %.2lf euro         -", amount, euro); // shows the user the conversion amount
    printf("\n-----------------------------------------------------------------");
}

void ToPounds(double amount, float rate[]){ // computes the conversion
    double limit, pounds;
    		if (amount > 5700){ // if amount is higher than 5,700
        		limit = amount * 0.85; // limit will apply and the amount will only show 85 percent
        		pounds = limit * rate[4]; // the limit will then be multiplied by the amount of won where 1 pesos = 0.015 pounds
    		}
    		else                        // if statement so that this part will work if the amount is lesser than 5,700
        		pounds = amount * rate[4]; // the amount will be multiplied by 0.015
    printf("-----------------------------------------------------------------");
    printf("\n-     For %.2lf Pesos, you would get = %.2lf pounds        -", amount, pounds); // shows the user the conversion amount
    printf("\n-----------------------------------------------------------------");
}
