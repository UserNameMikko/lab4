/*Вариант 10
*Задание 1
Написать функцию-шаблон, которая выполняет сортировку выбором как для сортировки по
возрастанию, так и по убыванию.
*Задание 2
Создать параметризованный список, перегрузить оператор потокового ввода/вывода, [] для
доступа к элементу заданной позиции, + для объединения двух списков.
*/

#include "List.h"
template<class T> struct Data{
    T value;
    T* ptr = &value;
};

void menu(){
    std::cout<<"1 - add new element push_back()\n2 - add new element push_front()\n3 - erase an element pop_back()\n"\
    "4 - erase an element pop_front()\n5 - define size of the list\n6 - is the list empty?\n"\
    "7 - print()\n8 - sort\n9 - search by index\n0 - exit"<<std::endl;
}
int main() {

    //initializing of variables

    List<double> list;
    int sizeOfList = 0;
    int choose = 0;

    std::cout << "-------LIST------\n\ninput size of list->";
    std::cin >> sizeOfList;

    // fill the list

    for (int i = 0; i < sizeOfList; i++) {
        Data<double> *data = new Data<double>;
        std::cout << "input a value->";
        std::cin >> data->value;
        std::cout << "choose how do you want to fill the list:\n1-push_front\n2-push_back\n-->";
        std::cin >> choose;
        switch (choose) {
            case 1:
                list.push_front(data->ptr);
                break;
            case 2:
                list.push_back(data->ptr);
                break;
            default://exception
                std::cout << ("Incorrect input!") << std::endl;
                i--;
                break;
        }
    }
    //the first part of the program

    std::cout << "Your list:\n" << list << "\n";
    std::cout << "what do you want to do in the next step?\n";

    int ch;
    do {
        Data<double> *data = new Data<double>;
        menu();
        std::cin >> ch;
        switch (ch) {
            case 1:
                std::cout << "input a value->" << std::endl;
                std::cin >> data->value;
                list.push_back(data->ptr);
                std::cout << "success!" << std::endl;
                break;
            case 2:
                std::cout << "input a value->" << std::endl;
                std::cin >> data->value;
                list.push_front(data->ptr);
                std::cout << "success!" << std::endl;
                break;
            case 3:
                list.pop_back();
                std::cout << "success!" << std::endl;
                break;
            case 4:
                list.pop_front();
                std::cout << "success!" << std::endl;
                break;
            case 5:
                std::cout << "size of the list: " << list.size_list() << std::endl;
                break;
            case 6:
                std::cout << list.isEmpty() << std::endl;
                break;
            case 7:
                std::cout << "Your list:\n" << list << std::endl;
                break;
            case 8:
                list.sort();
                break;
            case 9:
                int x;
                std::cout<<"input index:\n";
                std::cin>>x;
                std::cout<<list[x]<<std::endl;
                break;
            default:
                if (ch != 0)
                    std::cout << "incorrect input!" << std::endl;
        }
    } while (ch != 0);
}