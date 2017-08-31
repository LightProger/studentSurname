#include <stdio.h>

/* 
   Эта программа просит пользователя ввести фамилию
   латинскими буквами, и если фамилия пользователя
   начинается с букв, находящихся в диапазоне от P до S,
   его попросят пройти в отдельный кабинет для получения
   билетов */

/* глобальные переменные */
char name[30];                  // массив для фвмилии пользователя

/* Прототип функции */
int Surname(int * x, int * y);

int main ()
{
  /* запросить ввод имени пользователя */
  int countStudent = 0, countNostudent = 0, go = 0;

  printf("\n");
  printf("Program to count the number of students admitted to the exam.\n");
  printf("To exit the program and print the result, press \"0\"\n");

  while(go == 0)
  {
    printf("\nEnter please Your Surname:\n");
    scanf("%s", name);                          // для символьного массива & не нужен         
    getchar();  
    Surname (&countStudent, &countNostudent);
    printf("\n");

    if(name[0] == '0')
    {
      go = 1; // выходим из программы
    } 
  }

  if(go == 1)
  {
    printf("Students admitted to the exam: %i\n", countStudent);
    printf("Students not admitted to the exams: %i\n", countNostudent);
  }
  
  return 0;
}


/* Функция запроса у пользователя фамиллии, если первая буква фамилии находится в диапазоне между буквами "P" и "S"
 * его попросят пройти в отдельный кабинет для получения билетов */

int Surname(int * x, int * y)
{
char message1[] = { "To obtain tickets go to the office 2413." };
char message2[] = { "The results of the preliminary test, You are not admitted to the exam." };
int flag = 0;

while(flag == 0)
{
  if(name[0] == '0')
  {
    flag = 3;
  }
  else
  {
    if(((name[0] >= 'P') && (name[0] <= 'S')) || ((name[0] >= 'p') && (name[0] <= 's'))) 
    { 
      *x = *x + 1;
      flag = 1; 
    }
    else 
    { 
      *y = *y + 1;
      flag = 2;
    }
  }
}

if(flag == 1) { printf("%s", message1); }
if(flag == 2) { printf("%s", message2); }
if(flag == 3) { return 0; }
   
  return *x, *y;
}
  
