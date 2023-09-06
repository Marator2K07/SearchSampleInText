
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

signals:
    ///
    /// \brief stop сигнал окончания поиска образа
    void stop();
    ///
    /// \brief resultIsReady сигнал о готовности результата поиска
    /// \param result - результат поиска
    void resultIsReady(QString result);
    ///
    /// \brief timeIsReady сигнал подсчета времени, затраченного на поиск образа
    /// \param timeElapsed - количество затраченного времени
    void timeIsReady(QString result);

};

#endif // BMHSEARCH_H