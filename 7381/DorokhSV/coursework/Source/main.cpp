#include "BST.hpp"
#include <iostream>
#include <cstring>
#include <sstream>

int menu(BST<int> &tree) {           //Функция, представляющая из себя меню программмы.
    int value, action;
    std::cout << "Entry rules: " << std::endl;
    std::cout << "\t\t1 - Insert element;\n\t\t2 - Delete element;\n\t\t3 - Exit." << std::endl;
    while (action != 3) {
        std::cout << "Select an action for the item: " << std::endl;
        std::cin >> action;
        if(std::cin.fail()) {      //Проверка элемента на корректность                 
            std::cout << "Error! Items for search can only be of one type(digits)!" << std::endl;
            return 0;
        }
        switch(action) {
            case 1:
                std::cout << "Enter an item to work with:" << std::endl;
                std::cin >> value;
                if(std::cin.fail()) {                       
                    std::cout << "Error! Items for search can only be of one type(digits)!" << std::endl;
                    return 0;
                }
                std::cout << "<----Inserting element---->" << std::endl;
                tree.insert(value);
                tree.display();
                break;

            case 2:
                std::cout << "Enter an item to work with:" << std::endl;
                std::cin >> value;
                if(std::cin.fail()) {                       
                    std::cout << "Error! Items for search can only be of one type(digits)!" << std::endl;
                    return 0;
                }
                std::cout << "<----Deleting element---->" << std::endl;
                tree.remove(value);
                tree.display();
                break;

            case 3: 
                std::cout << "The end of program..." << std::endl;
                break;
            
            default:
                std::cout << "Error! Enter correct number of action." << std::endl;
        }
    }
    return 0;
}

int main() {
    std::string list;
    std::cout << "Enter leafs for tree:" << std::endl;
    getline(std::cin, list);
    std::cout << std::endl;
    std::stringstream ss;
    for(size_t i = 0; i < list.size(); i++)     //Проверка элемента на принадлежность к целому типу
        if(isalpha(list[i]))
            std::cout << "Error! " << list[i] << " - was not digit! Stop building the tree..." << std::endl;
    ss.str(list);
    BST<int> tree;
    int value;
    std::cout << "\t\tWork with tree..." << std::endl;
    while(ss >> value) {
        tree.insert(value);
        tree.display();
    }
    std::cout << "Tree before actions:" << std::endl;
    tree.display();
    menu(tree);
 }