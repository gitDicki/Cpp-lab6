#include "HashSet.h"
#include <iostream>

bool HashSet::Contains(std::string item) const {
    for (int i = 0; i < elements.size(); i++) {
        if (elements[i] == item) {
            return true;
        }
    }
    return false;
}

void HashSet::Add(std::string item) {
    if (Contains(item) == false) {
        elements.push_back(item);
    }
}

void HashSet::Remove(std::string item) {
    for (int i = 0; i < elements.size(); i++) {
        if (elements[i] == item) {
            elements.erase(elements.begin() + i);
            break; 
        }
    }
}

HashSet HashSet::Union(HashSet list) const {
    HashSet result = *this;
    for (int i = 0; i < list.elements.size(); i++) {
        result.Add(list.elements[i]);
    }
    return result;
}

HashSet HashSet::Except(HashSet list) const {
    HashSet result;
    for (int i = 0; i < elements.size(); i++) {
        if (list.Contains(elements[i]) == false) {
            result.Add(elements[i]);
        }
    }
    return result;
}

HashSet HashSet::Intersect(HashSet list) const {
    HashSet result;
    for (int i = 0; i < elements.size(); i++) {
        if (list.Contains(elements[i]) == true) {
            result.Add(elements[i]);
        }
    }
    return result;
}

void HashSet::Print() const {
    if (elements.size() == 0) {
        std::cout << "Пустой";
    } else {
        for (int i = 0; i < elements.size(); i++) {
            std::cout << elements[i] << " ";
        }
    }
    std::cout << std::endl;
}
