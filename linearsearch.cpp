
#include "linearsearch.h"

LinearSearch::LinearSearch(QTextEdit *text,
                           QLineEdit *sample)
{
    this->text = text;
    this->sample = sample;
    result = "";
}

void LinearSearch::start()
{

    QString txt = text->toPlainText();
    QString smpl = sample->text();
    int i = 0;
    int j = 0;

    // сначала стоит проверить, а заполнены ли поля
    if(txt.length() == 0 || smpl.length() == 0) {
        emit timeIsReady(QString::number(0));
        emit resultIsReady(QString("Недостаточно информации"));
        emit stop();
        return;
    }

    timer.start(); // начинаем считать время
    while (i < txt.length()) {
        if(txt[i] == smpl[j]) {
            i++;
            j++;
        }
        else {
            j = 0;
            i++;
        }
        // в случае нахождения образа в тексте
        if(j == smpl.length()) {
            emit timeIsReady(QString::number(timer.nsecsElapsed()));
            emit resultIsReady(QString("Образ найден на позиции: %1").arg(i-j));
            emit stop();
            return;
        }
    }
    // если ничего не нашли
    emit timeIsReady(QString::number(timer.nsecsElapsed()));
    emit resultIsReady(QString("Образ не был найден"));
    emit stop();
}
