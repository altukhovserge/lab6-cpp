// lab6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
using namespace std;
class good{
public:
  char *name;
  short int code;
  char *unit;
  float cost;
  good(){*name=' '; code=0; *unit=' ';cost=0; };
};
  void change(good &a, char *name_, short int code_, char *unit_, float cost_);
  void show();
  void sort();

good obj[7];

void change(good &a, char *name_, short int code_, char *unit_, float cost_)
{
  a.name = new char[strlen(name_)+1];
  strcpy(a.name,name_);
  a.code = code_; 
  a.unit = new char[strlen(unit_)+1];
  strcpy(a.unit,unit_);
  a.cost = cost_;
}

void sort()
{
 int i,j;
 good temp;
  for (i=0; i<7; i++)
   for (j=i+1; j<7; j++)
   if (obj[i].name > obj[j].name) {
    temp = obj[i];
    obj[i] = obj[j];
    obj[j] = temp;
   }
}
void show()
 {
  int i,j;
 cout << "                            Товар : \n";
 cout << "----------------------------------------------------------------\n";
 cout << " название   код товара  единица измерения  продажная стоим. ед. \n";
 cout << "----------------------------------------------------------------\n";

char s[10];
for (i=0; i<7; i++) {
 strcpy(s, obj[i].name);
 if (strlen(s)==6){
 cout <<' '<<s[0]<<s[1]<<"-"<<s[2]<<s[3]<<"-"<<s[4]<<s[5];}
 else if (strlen(s)==7){
 cout << s[0]<<s[1]<<s[2]<<"-"<<s[3]<<s[4]<<"-"<<s[5]<<s[6];}
 cout << setw(15) <<  obj[i].unit;  
 cout << setw(25) << obj[i].cost;
 cout << "\n";
}
cout << "----------------------------------------------------------------\n";
}

int _tmain(int argc, _TCHAR* argv[])
{
 int r = 0;

 for (int a=0; !a;){
//  clrscr();
  cout <<"1. Добавить записи\n"  ;
  cout <<"2. Сортировать базу\n";
  cout <<"3. Вывести базу\n";
  cout <<"4. Выход\n";
  cout <<"> ";
  int p;
  cin>>p;
   switch(p) {
     case 1: {
      change(obj[0],"Стиральный порошок",1,"кг.",100);
      change(obj[0],"Зубная паста",1,"шт.",100);

      r = 1;
     break;
    }

    case 2: {
     if (r == 0) {cout<<"В базе нет записей."; getch();}
     else if (r == 1) sort();
    break;
    }

    case 3: {
     if (r == 0) {cout<<"В базе нет записей."; getch();}
    else if (r == 1)show();
    getch();
    break;
    }

    case 4: {
    a=1;
    break;
    }

    default :{
    cout << "Неверный вызов";
    getch();
    break;
    }
  }
}
	return 0;
}

