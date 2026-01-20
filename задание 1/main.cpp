#include <iostream>
#include <vector>
#include "HashSet.h"

int main() {

    HashSet TRC;
    TRC.Add("1");
    TRC.Add("2");
    TRC.Add("3");
    TRC.Add("4");
    TRC.Add("5");

    std::vector<HashSet> students(3);
    
    students[0].Add("1");
    students[0].Add("2");
    
    students[1].Add("2");
    students[1].Add("4");
    students[1].Add("1");

    students[2].Add("1");
    students[2].Add("5");
    students[2].Add("2");

    HashSet all = students[0];
    for (int i = 1; i < students.size(); i++) {
        HashSet nextStudent = students[i];
        all = all.Intersect(nextStudent);
    }

    HashSet some;
    for (int i = 0; i < students.size(); i++) {
        HashSet currentStudent = students[i];
        some = some.Union(currentStudent);
    }

    HashSet none = TRC.Except(some);

    std::cout << "Посетили все: ";
    all.Print();

    std::cout << "Посетил хотя бы один студент: ";
    some.Print();

    std::cout << "Никто не посетил: ";
    none.Print();
}
