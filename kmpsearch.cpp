
#include "kmpsearch.h"

KMPSearch::KMPSearch(QTextEdit *text,
                     QLineEdit *sample)
{
    this->text = text;
    this->sample = sample;
}

void KMPSearch::start()
{
    QString txt = text->toPlainText();
    QString smpl = sample->text();

    // сначала стоит проверить, а заполнены ли поля
    if(txt.length() == 0 || smpl.length() == 0) {
        emit timeIsReady(QString::number(0));
        emit resultIsReady(QString("Недостаточно информации"));
        emit stop();
        return;
    }

    // определяем массив сдвигов
    int *shift = new int[smpl.length()]{0};
    int preI = 0; // индекс для префиксов
    int sufI = 1; // индекс для суффиксов
    timer.start();
    while(sufI != smpl.length()) {
        if(smpl[preI] == smpl[sufI]) {
            shift[sufI] = preI + 1;
            preI++;
            sufI++;
        }
        else if (preI == 0) {
            shift[sufI] = 0;
            sufI++;
        }
        else {
            preI = shift[preI-1];
        }
    }
    // теперь приступаем к самому поиску
    int i = 0;
    int j = 0;
    while(i != txt.length() && j != smpl.length()) {
        if(txt[i] == smpl[j]) {
            i++;
            j++;
        }
        else if(j == 0) {
            i++;
        }
        else {
            j = shift[j-1];
        }
    }
    // смотрим результаты
    emit timeIsReady(QString::number(timer.nsecsElapsed()));
    if (j == smpl.length()) {;
        emit resultIsReady(QString("Образ найден на позиции: %1").arg(i-j));
    }
    else {
        emit resultIsReady(QString("Образ не был найден"));
    }
    emit stop();
}

