
#ifndef KMPSEARCH_H
#define KMPSEARCH_H

#include "searchengine.h"



class KMPSearch : public SearchEngine
{
    Q_OBJECT

private:
    QTextEdit* text;
    QLineEdit* sample;
    QElapsedTimer timer;

public:
    KMPSearch(QTextEdit *text,
              QLineEdit *sample);
};

#endif // KMPSEARCH_H
