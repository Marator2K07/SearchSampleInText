
#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include "searchengine.h"

class LinearSearch : public SearchEngine
{
private:
    QString text;
    QString sample;
    bool isFound;
    int foundPosition;

    // SearchEngine interface
public:
    LinearSearch();
    int Start() override;
};

#endif // LINEARSEARCH_H
