
#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include "searchengine.h"



class LinearSearch : public SearchEngine
{
    Q_OBJECT

private:
    QTextEdit* text;
    QLineEdit* sample;
    QString result;

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
};

#endif // LINEARSEARCH_H
