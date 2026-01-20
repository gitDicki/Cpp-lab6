#ifndef HASHSET_H
#define HASHSET_H

#include <vector>
#include <string>
#include <iostream>

class HashSet {
private:
    std::vector<std::string> elements;

public:

    void Add(std::string item);
    void Remove(std::string item);
    void Print() const;

    HashSet Union(HashSet other) const;
    HashSet Except(HashSet other) const;
    HashSet Intersect(HashSet other) const;
    bool Contains(std::string item) const;
};

#endif

