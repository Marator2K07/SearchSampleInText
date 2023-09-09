
#include "bmhsearch.h"

BMHSearch::BMHSearch(QTextEdit* text,
                     QLineEdit* sample)
{
    this->text = text;
    this->sample = sample;    
}

void BMHSearch::start()
{
    // подготовление нужных для алгоритма переменных
    QString txt = text->toPlainText();
    int txtLenght = txt.length();
    QString smpl = sample->text();
    int smplLenght = smpl.length();

    // стоит проверить, а заполнены ли поля
    if(txtLenght == 0 || smplLenght == 0) {
        emit timeIsReady(QString::number(0));
        emit resultIsReady(QString("Недостаточно информации"));
        emit stop();
        return;
    }
    shift.clear();
    timer.start();
    // а теперь заполним его нужными значениями сдвигов
    for(int i = 0; i <= smplLenght - 2; i++) {
        shift[smpl[i].unicode()] = smplLenght - i - 1;
    }
    shift[404] = smplLenght;
    // подготовления к основному алгоритму
    int i = smplLenght;
    int j = smplLenght;
    int k = i;
    // сам алгоритм
    while(j > 0 && i <= txtLenght) {
        if (txt[k-1] == smpl[j-1]) {
            k--;
            j--;
        }
        else if (shift.contains(txt[i-1].unicode())) {
            i += shift[txt[i-1].unicode()];
            j = smplLenght;
            k = i;
        }
        else {
            i += shift[404];
            j = smplLenght;
            k = i;
        }
    }
    // смотрим результаты
    emit timeIsReady(QString::number(timer.nsecsElapsed()));
    if (j <= 0) {
        emit resultIsReady(QString("Образ найден на позиции: %1").arg(k));
    }
    else {
        emit resultIsReady(QString("Образ не был найден"));
    }
    emit stop();
}
