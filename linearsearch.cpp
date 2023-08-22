
#include "linearsearch.h"

LinearSearch::LinearSearch()
{
    text = "";
    sample = "";
    isFound = false;
    foundPosition = -1;
}

int LinearSearch::Start()
{
    int i = 0;
    int j = 0;
    while (i < text.length()) {
        if(text[i] == sample[j]) {
            i++;
            j++;
        }
        else {
            j = 0;
        }
        // в случае нахождения образа в тексте
        if(j == sample.length() - 1) {
            return 0;
        }
    }
    // если ничего не нашли
    return -1;
}
