//
//  main.c
//  scope
//
//  Created by Andrei Cristea on 2020. 04. 03..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <stdio.h>


#include <stdio.h>

int main(){
//    int numbers[5];
//    numbers[0] = 20;
//    numbers[1] = 1;
//    numbers[2] = 14;
//    numbers[3] = 41;
//    numbers[4] = 11;
    int n = 0;
    printf("Напишите количество чисел, которые надо отсортировать\n(n > 0)\n");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Ты че дядь. Напиши число больше нуля\n");
        scanf("%d", &n);
    }
    int numbers[n];
    printf("Напишите числа для сортировки\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i <= (sizeof(numbers) /4)-1 ; i++) {
        int j = 1;
        for (int i = 0; i < sizeof(numbers)/4; i++) {
          int numberOne = numbers[i];
          int numberTwo = numbers[j];
          if((numbers[i] > numbers[j]) && (j < sizeof(numbers)/4)){
              numbers[i] =  numberTwo;
              numbers[j] = numberOne;
          }else{
              numbers[i] = numberOne;
              numbers[j] = numberTwo;
          }
          j++;
        }
    }
    printf("По возврастанию\n");
    for (int i = 0; i < sizeof(numbers)/4; i++) {
        printf("%d ", numbers[i]) ;
    }
    printf("\nПо убыванию\n");
    for (long i = sizeof(numbers)/4 - 1; i >= 0 ; i--) {
        printf("%d ", numbers[i]) ;
    }
}
