
#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <QString>

class SearchEngine
{
public:
    ///
    /// \brief Start метод поиска образца в тексте
    virtual int Start() = 0;
};

#endif // SEARCHENGINE_H
