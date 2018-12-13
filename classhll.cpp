/*Задача - стандартная 4. Класс File.*/
#include <iostream>
#define LEN 100
#define NUM_OF_OBJECTS 100
using namespace std;
class File
{
    /*Описание скрыиых элементов класса*/
    char name[LEN];
    char createDate[LEN];
    int volByte;
    int numCalling;
    /*Открытые функции-члены класса для доступа к закрытым членам*/
    public:
    void set();
    void get();
    void show();
    char * forSort();
    int forCheckSize();
    int forCheckCall();
};
/*Функция отображения объекта на экране*/
void File::show()
{
    cout<<"File name: "<<name<<"\n"<<"Date of create: "<<createDate<<"\n"<<"Size in bytes: "<<volByte<<"\n"<<"Number of callings: "<<numCalling<<"\n";
}
/*Функция изменения данных в объекте*/
void File::set()
{
    show();
    cout<<"Enter new name:\n";
    cin>>name;
    numCalling++;
}
/*Функция введения данных в объект*/
void File::get()
{
    cout<<"Enter name:\n";
    cin>>name;
    cout<<"Enter date of create:\n";
    cin>>createDate;
    cout<<"Enter size in bytes:\n";
    cin>>volByte;
    cout<<"Enter number of callings:\n";
    cin>>numCalling;
}
/*Функция доступа к имени файла*/
char * File:: forSort()
{
    return name;
}
/*Функция доступа к размеру файла*/
int File::forCheckSize()
{
    return volByte;
}
/*Функция доступа к числу обращений к файлу*/
int File::forCheckCall()
{
   return numCalling;
}
/*Основная функция*/
int main()
{
    File array[NUM_OF_OBJECTS];//Массив элементов
    int i;
    int want;//Маячок для выбора исполнять-не исполнять функцию
    int check;//Заданное значение размера и числа обращений
    int counter = 0;//Счетчик реальных записей в массиве
    /*Заполнение массива*/
    cout<<"Fill the array\n";
    for (i = 0;i<NUM_OF_OBJECTS;i++)
    {
        array[i].get();
        counter++;
        cout<<"Want to continue?\n"<<"1-Yes\n2-No\n";
        cin>>want;
        if (want == 1)
        {
            continue;
        }
        else{
            if (want == 2)
                break;
            else
            {
                cout<<"Error: no command\n";
            }
        }
    }
    cout<<"Want to change something? 1 - Yes 2 - No\n";
    cin>>want;
    if (want == 1)
    {
        cout<<"Enter number of item\n";
        cin>>i;
        array[i].set();
    }
    /*Вывод списка файлов в алфавитном порядке*/
    cout<<"Alphabetical listing of files\n";
    for(i = 0 ; i < counter-1; i++)
    {
        for(int j = i+1; j < counter; j++)
        {
            if (strcmp(array[i].forSort(), array[j].forSort())>0)
            {
                File tmp;
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
    for (i = 0;i<counter;i++)
    {
        array[i].show();
        cout<<"\n";
    }
    cout<<"Want to change something? 1 - Yes 2 - No\n";
    cin>>want;
    if (want == 1)
    {
        cout<<"Enter number of item\n";
        cin>>i;
        array[i].set();
    }
    /*Вывод списка файлов, размер которых выше заданного*/
    cout<<"List of files larger than specified\n";
    cin>>check;
    for (i = 0;i<counter;i++)
    {
        if(array[i].forCheckSize()>check)
        {
            array[i].show();
            cout<<"\n";
        }
        else continue;
    }
    cout<<"Want to change something? 1 - Yes 2 - No\n";
    cin>>want;
    if (want == 1)
    {
        cout<<"Enter number of item\n";
        cin>>i;
        array[i].set();
    }
    /*Вывод списка файлов, число обращений к которому выше заданного*/
    cout<<"List of files, the number of calls to which is higher than the specified\n";
    cin>>check;
    for (i = 0;i<counter;i++)
    {
        if(array[i].forCheckCall()>check)
        {
            array[i].show();
            cout<<"\n";
        }
        else continue;
    }
    cout<<"Want to change something? 1 - Yes 2 - No\n";
    cin>>want;
    if (want == 1)
    {
        cout<<"Enter number of item\n";
        cin>>i;
        array[i].set();
    }
    return 0;
}
