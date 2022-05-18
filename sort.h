#include "List.h"
template<class T>
void  sort (T array, int size){
    std::cout<<"TEMP ARRAY before sort: "<<std::endl;
    for(int i = 0; i < size;i++)
        std::cout<<array[i]<<" ";
    std::cout<<std::endl;
    int ch;
    std::cout<<"1 - ascend\n2 - descend\n->";
    std::cin>>ch;
    switch(ch){
        // ascend
        case 1:
            for (int i = 0; i != size; ++i) {
                int min = i;
                for (int k = i + 1; k != size; ++k)
                    if (array[k] < array[min])
                        min = k;

                int tmp = array[min];
                array[min] = array[i];
                array[i] = tmp;
            }
            break;
            //descend
        case 2:
            for (int i = 0; i != size; ++i) {
                int min = i;
                for (int k = i + 1; k != size; ++k)
                    if (array[k] >= array[min])
                        min = k;
                int tmp = array[min];
                array[min] = array[i];
                array[i] = tmp;
            }
            break;
    }
    for (int i = 0 ; i < size; i++)
        std::cout<<array[i]<<" ";
    std::cout<<std::endl;
}