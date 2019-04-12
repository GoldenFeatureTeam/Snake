#include "World.h"

template <int x,int y>
void World<x,y>::summon_object(int _x,int _y) //функция призыва объекта 
{
    word[_x][_y] = '*';   //устанавливаемые объект на позиции _x и _y
    ++cnt;
}

template<int x,int y>
void World<x,y>::render() //функция отрисовки мира
{
    for (int i = 0;i < x;++i) //через 2 цикла выводим двумерный массив char(мир) на экран
    {
         for (int j = 0;j < y;++j)
         {
              cout<<word[i][j];
         }
         cout<<endl;
     }
}