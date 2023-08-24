
#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include "searchengine.h"



class LinearSearch : public SearchEngine
{
    Q_OBJECT

private:
    QTextEdit* text;
    QLineEdit* sample;
    QElapsedTimer timer;

public:
    LinearSearch(QTextEdit* text,
                 QLineEdit* sample);

public slots:
    // SearchEngine interface
    void start() override;

signals:
    ///
    /// \brief stop сигнал окончания поиска образа
    void stop();
    ///
    /// \brief resultIsReady сигнал о готовности результата поиска
    /// \param result - реузльтат поиска
    void resultIsReady(QString result);
    ///
    /// \brief timeIsReady сигнал подсчета времени, затраченного на поиск образа
    /// \param timeElapsed - сколько было потрачено времени
    void timeIsReady(QString result);
};

#endif // LINEARSEARCH_H
