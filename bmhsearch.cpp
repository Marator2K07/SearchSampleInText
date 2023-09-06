
#include "bmhsearch.h"

BMPSearch::BMPSearch(QTextEdit* text,
                     QLineEdit* sample)
{
    this->text = text;
    this->sample = sample;
    shift = new int[arrayShiftSize];
}

void BMPSearch::start()
{
    QString txt = text->toPlainText();
    QString smpl = sample->text();

    // стоит проверить, а заполнены ли поля
    if(txt.length() == 0 || smpl.length() == 0) {
        emit timeIsReady(QString::number(0));
        emit resultIsReady(QString("Недостаточно информации"));
        emit stop();
        return;
    }
    // для начала проинициализируем массив сдвигов
    for(int i = 0; i < arrayShiftSize; i++) {
        shift[i] = txt.length();
    }
}

