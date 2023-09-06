
#ifndef BMHSEARCH_H
#define BMHSEARCH_H

#include "searchengine.h"



class BMPSearch : public SearchEngine
{
    Q_OBJECT

private:
    QTextEdit* text;
    QLineEdit* sample;
    QElapsedTimer timer;

public:
    BMPSearch(QTextEdit* text,
              QLineEdit* sample);

public slots:
    // SearchEngine interface
    void start();
};

#endif // BMHSEARCH_H
