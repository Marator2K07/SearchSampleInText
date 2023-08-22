
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
            emit stop(QString("Слово найдено на позиции: %1").arg(i-j));
        }
    }
    // если ничего не нашли
    emit stop(QString("Слово не найдено на позиции"));
}
