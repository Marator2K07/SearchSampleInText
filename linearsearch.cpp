
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

    while (i < txt.length()) {
        if(txt[i] == smpl[j]) {
            i++;
            j++;
        }
        else {
            j = 0;
        }
        // в случае нахождения образа в тексте
        if(j == smpl.length() - 1) {
            emit resultIsReady(QString("Образ найден на позиции: %1").arg(i-j));
            emit stop();
        }
    }
    // если ничего не нашли
    emit resultIsReady(QString("Образ не был найден"));
    emit stop();
}
