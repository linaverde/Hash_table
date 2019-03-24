#include <iostream>
#include "lib_dir/hash_lib.h"

int main() {
    Hash_table MyTable(42, 6);
    std::cout << "Размер таблицы: " << MyTable.getSize() << std::endl;
    MyTable.pringAll();
    Rec MyRec;
    MyRec.value = "a_Журнал";
    //добавление элементов
    for (unsigned int i = 1 ; i <10; i++) {
        MyRec.key =10000+ 3*i;
        MyRec.value[0]++;
        MyTable.add(MyRec);
        MyRec.key =10000+ 2*i;
      //  MyRec.value[0]++;
        MyTable.add(MyRec);
    }
    std::cout << "Размер таблицы: " << MyTable.getSize() << std::endl;
    MyTable.pringAll();
    MyRec.value = "a_Журнал";
    //удаление элементов
    for (unsigned int i = 1; i < 10; i++) {
       MyRec.key =10000+ 3*i;
        MyRec.value[0]++;
       MyTable.del(MyRec);
        MyRec.key =10000+ 2*i;
        //  MyRec.value[0]++;
      //  MyTable.del(MyRec);
    }
    std::cout << "Размер таблицы: " << MyTable.getSize() << std::endl;
    MyTable.pringAll();

    MyRec.value = "a_Журнал";
    //добавление элементов
    for (unsigned int i = 1 ; i <10; i++) {
        MyRec.key =10000+ 5*i;
        MyRec.value[0]++;
        MyTable.add(MyRec);
        MyRec.key =10000+ 2*i;
        //  MyRec.value[0]++;
        MyTable.add(MyRec);
    }
    std::cout << "Размер таблицы: " << MyTable.getSize() << std::endl;
    MyTable.pringAll();

}