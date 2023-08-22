
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
    /// \param result - реузльтат поиска
    void stop(QString result);
};

#endif // LINEARSEARCH_H
