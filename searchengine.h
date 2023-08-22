
#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <QString>
#include <QTextEdit>
#include <QLineEdit>
#include <QObject>

class SearchEngine : public QObject
{
    Q_OBJECT

public:
    ///
    /// \brief Start метод поиска образца в тексте
    virtual void start() = 0;
};

#endif // SEARCHENGINE_H
