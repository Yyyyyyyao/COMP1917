#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Dicevalue(char value[]);//function use to display the dice entered.
int Format(char num[], int *pri);//get the dice value and check the format.
void Range(char num[], int *pri, int len);//check whether the dice value is over the range 1 to 6.
void NumberOfValue(int num, int *pri);//check the number of dice values; whether it is over 5.
int Check(int a, int b, int c);//to display the error menssages that in priority order. 
int Valuation(char value[], int score[]);// to judge the score type.
int Rollalldice(char dicebox[]);
int Rollsomedice(char dicebox[]);
void Choice(int choose, char array2[]);//get the number of the choice number.

int main(int argc, char *argv[]){

   char dicebox[200];//the array to store the valid  dice values.
   int check;//whether there is error menssage returned.
   check = Rollalldice(dicebox);
   if(check != 1){
        printf("\n");
        Dicevalue(dicebox);//display the dice values.
        printf("\n");
        int times = 2;//because the reroll some dice and reroll all dice cannot run more than twice.
        int check2 = 0;
        int check3 = 0;
        int check4 = 0;
     //start from times = 2. after one reroll, times will minus 1.
     while(times > 0){
     		  //display the choice board.
              printf("Please choose:\n");
              printf(" 1 -> Reroll some dice\n");
              printf(" 2 -> Reroll all dice\n");
              printf(" 3 -> Keep dice\n");
              char array2[200];//to store the choice.
              int d = 0;//define a number and use as a pointer below. in order to point the error menssage.
              Format(array2, &d);//check format.
              int e =(int)array2[0];//get the first number as the choice.
              if(e != '1' && e != '2' && e != '3'){//because there are only 3 choices; e cannot exceed {1,2,3}.
                 printf("Invalid Choice.\n");
                 check4 = 1;//if there is error menssage, check4 will equal 1.
                 times= 0;//when there is error, jump out of the while loop.
              }
         if(check4 != 1){//check4 != 1 means the program can run downwards.
               if(e == '1'){
                  printf("\n");
                  check2 = Rollsomedice(dicebox);//check2 is used to receive the error menssage.
                  if(check2 == 1){
                     times = 0;
                  }else {
                     times = times  -1;
                  }

               }
               if(e == '2'){
                  printf("\n");
                  check3 = Rollalldice(dicebox);//check3 is used to receive the error menssage.
                  if(check3 == 1){
                     times = 0;
                  }else{
                   printf("\n");
                   Dicevalue(dicebox);
                   printf("\n");
                   times = times - 1;
                  }
               }
               if(e == '3'){//e = 3 is 'keep dicing'; so it will go straight to valuation.
                  times = 0;
               }
         }
         

     }
     if(check2 != 1 && check3 != 1 && check4 != 1){ //if there is any error menssage from above, it will not run the valuation.
        int score[200]; //to store the points that it gets.
        int y = 0;//the number of the valuation choices.
        int check5 = 0;
        y = Valuation(dicebox, score);
    	char array5[200];//to store the number we enter to choose the valuation.
        int f = 0;//the pointer for error menssage.
     	Format(array5, &f);
        int g =(int)array5[0];//take the first number we enter.
        g = g - 48;//because g is the value of ASCII number; we need to minus 48.
       if(g > y || g  == 0){
            printf("Invalid Choice.\n");
            check5 = 1;
        }
        if(check5 != 1){
            printf("\n");
            printf("Your score is: %d points\n", score[array5[0] - 48]);
        }
     }
  }
  return EXIT_SUCCESS;
}

int Rollalldice(char dicebox[]){

   printf("Please enter dice values:\n");
   int a = 0;//priority 1
   int b = 0;//priority 2
   int c = 0;//priority 3
   int check;// to receive the error menssage returned from Check(function).
   int number = Format(dicebox, &a);//number is the number of dice values we entered.
   Range(dicebox, &b, number);
   NumberOfValue(number, &c);
   check = Check(a, b, c);
   return check;
}

int Rollsomedice(char dicebox[]){

    
     printf("Please enter dice to reroll (1 - 5):\n");
     char array3[200];
     int f = 0;//priority
     int g = 0;//priority
     int h = 0;//the number of values needed to be changed
     int p = 0;
     int check2=0;
     h = Format(array3, &f);
     Range(array3, &g, h);
     if(f == 1){
        printf("Incorrect Input Format.\n");
        check2 = 1;
      }else if(g == 1){
        printf("Dice Number Out of Range.\n");
        check2 = 1;
      }
      if(check2 != 1){
      //the same dice condition
      //place them in order.
      //compare the first to the rest, if the first one is greater, swaping them. Then from the second one.

  		int a = 0;
     	int k;
     	int temp;
     	while(a < h){
        	k = 1;                                                                                          
        	while((a + k) < h){
           		if(array3[a] > array3[a + k]){
              		temp = array3[a];
              		array3[a] = array3[a + k];
              		array3[a + k] = temp; 
              		k++;
           		}else{
              		k++;
           		}
        	}
       		a++;
     	}
       //count the same choice. such as 2 2 3 3 4. only count 2 3 and 4.
       int i = 0;
       int count = 0;
       while(i < h-1){
       	  if(array3[i] != array3[i + 1]){
       	  	count++;
       	  }
       	  i++;
       }
       p = count + 1;//p is the number of different choices.
     
      printf("\n");
      if(p == 1){
      	  printf("Please enter %d value:\n", p);//if p = 1, should be 'value'.
      }
      if(p > 1){
         printf("Please enter %d values:\n", p);//if p > 1, should be 'values'.
      }
      char array4[200]={0};
      
      int l = 0;//priority 1
      int m = 0;//priority 2
      int n = 0;
      int num = 0;//count how many choices have been entered.
	  num = Format(array4, &l);
      Range(array4, &m, num);
      //to judge whether the number of values entered is right.
      if(num!= p){
 		 n= 1;
      }
      check2 = Check(l, m ,n);//to judge whether there are error manssages.
      if(check2 != 1){
      int o = 0;
      int q = 0;
      //to swap the dice value that needed to be changed.
      while(o < h){
           if(array3[o] != array3[o + 1] && array3[o] >= '1' && array3[o] <= '6' && q < p){
              dicebox[array3[o]-'0' - 1] = array4[q]; 
               o++;
               q++;  
           }else{
             o++;
           }
      } 
      printf("\n");
      Dicevalue(dicebox); 
      printf("\n");  
      }
      }

      return check2;//return error menssages.
}

void Dicevalue(char value[]){
   int i = 0;
   printf("Your dice values are: ");
   while(i<5){
      printf("%c ", value[i]);
      i++;
   }
   printf("\n");
}

int Format(char num[], int *pri){
   int i = 0;
   int j = 0;
   int a = 0;
   int b = 0;
   int k = 0;
   char value;
   char arrtemp[200];
   //use getchar() to take in all the charactors that entered.
   while((value = getchar()) != 10){
   	k = (char)value;
   	arrtemp[i] = k;
   	i++;
   }
   
   while(b < i){
   	if(arrtemp[b] >= '0' && arrtemp[b] <= '9'){
   		num[j] = arrtemp[b];//put valid values in the dicebox[](num[]).
   		a++;//count how many numbers have been entered in dicebox;
   		j++;
   		b++;
   		if(i-1 != 1 && b!= i){//after the first two charactors and arrtemp[b] is not the last one
   			if(arrtemp[b] != ' '){//except the ' ', any charactor is wrrong; and mark the pointer equals = 1.
   				*pri = 1;
   			}
   		}
   	}
   	b++;
   }
     
   
   return a;//return the number of valid values.

}

void Choice(int choose, char array2[]){
    //use getchar() to take in the choice and 
    while(choose != EOF){
        if(choose >= '1' && choose <= '9'){
            array2[0] = choose;
        }else if(choose == ' '){
            choose = getchar();
        }else {
            choose = EOF;
        }
        choose = EOF;
    }


}

void Range(char num[], int *pri, int len){
   int k = 0;
   int a;

   while(k < len){
    a = (int)num[k];
     if(a >= '0' && a <= '9'){//first exclude the space.
        if(a >= '1' && a <= '6'){//to check whether it is in the range of 1 to 6.
        }else{
          *pri = 1;//not in range point to error menssage.
        }
     }else{
     }
   k = k + 1;
   }
}

void NumberOfValue(int num, int *pri){
   if(num != 5){//to check whether the number of values is correct.
  
     *pri = 1;
   }
}


int Check(int a, int b, int c){
   //print the error menssages with the priority.
   int i = 0;

   if(a == 1){
      printf("Incorrect Input Format.\n");
      i = 1;
   }else if(b == 1){
      printf("Value Out of Range.\n");
      i = 1;
   }else if(c == 1){
      printf("Incorrect Number of Values.\n");
      i = 1;
   }

   return i;
}

int Valuation(char value[], int score[]){
    //first initialise 6 int to represent the number 1 to 6.
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    int n4 = 0;
    int n5 = 0;
    int n6 = 0;
    int y = 1;
    int i = 0; 
    //count how many 1 or 2 or 3.. in the dicebox.
    while(i < 5){
       if(value[i] == '1'){
          n1 = n1 + 1;
          i++;
       }
       if(value[i] == '2'){
          n2 = n2 + 1;
          i++;
       }
       if(value[i] == '3'){
          n3 = n3 + 1;
          i++;
       }  
       if(value[i] == '4'){
          n4 = n4 + 1;
          i++;
       }
       if(value[i] == '5'){
          n5 = n5 + 1;
          i++;
       }
       if(value[i] == '6'){
          n6 = n6 + 1;
          i++;
       }
    }
    //calculate the sum of the dicebox.
     int sum = 0;
     int num = 0;
     while(num < 5){
     sum = value[num] - 48 + sum;
     num++;
     }
     //since there is no way to see sequence and same kinds at the same time.
     //so the first big case is same of a kind.
     printf("\nYour score options are:\n");
     if(n1 > 2 || n2 > 2 || n3 > 2 || n4 > 2 || n5 > 2 || n6 > 2){
        printf(" %d -> Three of a Kind (%d points)\n", y, sum);
        score[y]=sum;
        y++;
         if(n1 > 3 || n2 > 3 || n3 > 3 || n4 > 3 || n5 > 3 || n6 > 3){
            printf(" %d -> Four of a Kind (%d points)\n", y, sum);
            score[y] = sum;
            y++;
             if(n1 > 4 || n2 > 4 || n3 > 4 || n4 > 4 || n5 > 4 || n6 > 4){
               printf(" %d -> Yahtzee (50 points)\n", y);
               score[y] = 50;
               y++;
             }
         }
        if(n1 == 2 || n2 == 2 || n3 == 2 || n4 == 2 || n5 == 2 || n6 == 2){
           printf(" %d -> Full House (25 points)\n", y);
           score[y] = 25;
           y++;
        }
     }
     //place array in order
     int a = 0;
     int k;
     int temp;
     while(a < 5){
        k = 1;                                                                                          
        while((a + k) < 5){
           if(value[a] > value[a + k]){
              temp = value[a];
              value[a] = value[a + k];
              value[a + k] = temp; 
              k++;
           }else{
              k++;
           }
        }
       a++;
     }
     //to see how many numbers in sequence.
     int e = 0;
     int count = 0;
     while(e < 4){
        if(value[e] + 1 == value[e + 1]){
           count++;
        }else if(count != 3 && value[e] + 1 != value[e + 1]){//to exclude the case like 1 2 3 5 6.
        	count = 0;
        }
        
     e++;
     }
     count = count + 1;
     
     //after know the count; we could know the type of scores.
     if(count > 3){
        printf(" %d -> Small Straight (30 points)\n", y);
        score[y] = 30;
        y++;
        if(count > 4){
           printf(" %d -> Straight (40 points)\n", y);
           score[y] = 40;
           y++;
        }
     }
     
     printf(" %d -> Chance (%d points)\n",y, sum);
     score[y] = sum;
     return y;
}









