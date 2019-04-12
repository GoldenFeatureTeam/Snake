#include "World.h"
#include "World.cpp"

void NewGame(); //функция создания нового мира

void Load() //функция эмуляции экрана загрузки мира
{
    int i = 0;
    cout<<"Loading world";
    for (;i < 1000;i+=10)
        cout<<".";
    cout<<endl;
}

void Menu(); //функция меню

int main() //главная функция
{
   Menu();
   return 0;
}

void NewGame()
{
   World<30,30> world; //Первые 3 строчки отвечают за создание мира,и 2 объектов в нем 
   world.summon_object(7,9);
   world.summon_object(12,23);
   int ch; //переменная,которая используется для движения 
   int i = 0; //кол-во поглощённых игроком объектов 
   cout<<"\nПередвижение(1 - вниз,2 - вправа,3 - вверх,4 - влево): ";
   while (cin>>ch) 
   {
      switch (ch)
      {
         case 1:
         {
             world.moveDownX();
             world.render();
             cout<<endl;
         }
         break;
         case 2: 
         {
            world.moveDownY();
            cout<<endl;
            world.render();
            cout<<endl;
         }
         break;
         case 3:
         {
            world.moveUpX();
            cout<<endl;
            world.render();
            cout<<endl;
         }
         break;
         case 4:
         {
            world.moveUpY();
            cout<<endl;
            world.render();
            cout<<endl;
         }
      }
      if ((world.obj._x == 7 && world.obj._y == 9) || (world.obj._x == 12 && world.obj._y == 23)) //в данном случае если координаты объекта и игрока совпали,увеличиваем наш счётчик i на 1
        ++i;
      if (i == world.getCnt()) //если i = кол-ву объектов,выходим из игры с сообщением "Game Over"
        break;
   }
   cout<<"Game Over.\n";
}

void Menu() 
{
    int ch; //переменеая для выбора пункта меню
    cout<<"\t\tМеню: ";
    cout<<" \t\t\n 1.Новая игра ";
    cout<<" \t\t\n 2.Информация ";
    cout<<" \t\t\n 3.Выход ";
    cout<<"\n\nВведите ваш выбор: ";
    cin>>ch;
    switch (ch)
    {
        case 1:
        {
            Load();
            NewGame();
        }
        break;
        case 2:
            cout<<"Snake Demo 1.0\n";
        break;
        case 3:
            exit(0);
     }
}