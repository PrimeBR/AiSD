#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream> 
#include "lisp_func.h"

lisp reverse(const lisp s, const lisp z) {                              //Рекурсивная функция для создания обратного иерарх. списка
    if(isNull(s)) 
        return(z);
    else if(isAtom(head(s)))
        return (reverse(tail(s), cons(head(s), z)));                    //Если элемент атом, то вызывается reverse и выполняется cons для текущего атома и подсписка
    else 
        return (reverse(tail(s), cons(reverse(head(s), NULL), z)));     //Если элемент не атом, то вызывается reverse и выполняется cons для                                                                        //'(' или ')' и списка послдующих элементов
}                                                                       //'(' или ')' и списка последующих элементов

int main () {
    std::stringbuf buffer;                 //Буфер потока для чтения и записи строк
    std::string list;                   
    char ch;

    getline(std::cin, list);            //Считывание строки из потока ввода в list
    std::istream str(&buffer);             //Связывание буффера потока с входным потоком
    buffer.str(list);                      //Установка содержимого строки
    
    if(!list.length()){
        std::cout << "List is empty!" << std::endl;
        return 0;
    }
    lisp s1;
    read_lisp (s1, str);

    if(str >> ch){                                     //Проверка на то, осталось ли что в str после выполнения функции read_lisp
        std::cout<<"Extra characters!"<< std::endl;
        return 0;
    }

    std::cout << "Entered list: " << std::endl;
    write_lisp (s1);
    std::cout << std::endl;

    std::cout << "Reversed list:" << std::endl;
    write_lisp (reverse(s1, NULL)); 
    std::cout << std::endl;

    destroy (s1);
    return 0;
}