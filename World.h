#ifndef WORLD_H_
#define WORLD_H_
#include <iostream>
#include <fstream>
using namespace std;

//Миниатюрная версия "Змейки"

//Проект создан 11.04.2019 пользователем Евгений Кикало 

/*Файлы: World.h - заголовок с классом игрока и мира
 * World.cpp - исходный файл с реализациями некоторых функций класса World
 * Main.cpp - главный исходный файл
*/

class Player //класс игрока(змейка)
{
public:
     int _x,_y; //координаты игрока
     char ch; //игрок в виде символа
     Player() : _x(0),_y(0),ch('0') {} //конструктор по умолчанию 
     inline void DownX() //перемещение вниз(x) на 1 
     {
           ++_x;
     }
     inline void DownY() //перемещение вправо(y) на 1
     {
          ++_y;
     }
     void Down() //перемещение по x и y на 1
     { 
         DownX();
         DownY();
     }
     inline void UpX() //перемещение вверх(x) на 1
     {
          --_x;
     }
     inline void UpY() //перемещение влево(y) на 1
     {
           --_y;
     }
     void Up() //перемещение по x и y на 1 в обратную сьрону функции Down
     { 
           UpX();
           UpY();
      }
};
    
template <int x = 10,int y = 10>
class World //класс самого мира
{
   mutable int cnt = 0; //мутабельная переменная(всегда изменяется)
   char field; //символы,из которых состоит мир
   char word[x][y]; //мир x на y символов 
public:
   Player obj; //игрок
   ofstream logss; //лог
public:
    World() : field('#') //конструктор по умолчанию
    {
         for (int i = 0;i < x;++i)
         {
             for (int j = 0;j < y;++j)
             {
                 word[i][j] = field;
             }
         }
         logss.open("log.txt",ios_base::app);
         logss<<"[WORLD_LOG]: World default constructor is worked\n";
         logss.close();
     }
    World(char _field) : field(_field) //явный конструктор 
     {
         for (int i = 0;i < x;++i)
         {
             for (int j = 0;j < y;++j)
             {
                 word[i][j] = field;
             }
         }
         logss.open("log.txt",ios_base::app); //открытие файла с режимом до записи для логов
         logss<<"[WORLD_LOG]: World constructor #2 is worked\n"; //логирование в файл
         logss.close(); //закрытие файла
     }
     void render(); //функция рендера мира 
     void summon_object(int _x,int _y); //призыв объекта 
     inline void clear() {system("clear");} //очистка экрана
     inline int getCnt() {return cnt;} //получение кол-во созданных объектов 
     void moveDownX() 
     {
         obj.DownX();
         word[obj._x][obj._y] = obj.ch;
     }
     void moveUpX()
     { 
         obj.UpX();
         word[obj._x][obj._y] = obj.ch;
     }
     void moveDownY()
     {
         obj.DownY();
         word[obj._x][obj._y] = obj.ch;
     }
     void moveUpY()
     {
         obj.UpY();
         word[obj._x][obj._y] = obj.ch;
     }
    ~World() //явный деструктор 
    {
        logss.open("log.txt",ios_base::app);
        logss<<"[WORLD_LOG]: World destructor is worked\n";
        logss.close();
    }
};
#endif