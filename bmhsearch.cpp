
#include "bmhsearch.h"

BMHSearch::BMHSearch(QTextEdit* text,
                     QLineEdit* sample)
{
    this->text = text;
    this->sample = sample;
    arrayShiftSize = 256;
    shift = new int[arrayShiftSize];
}

void BMHSearch::start()
{
    // подготовление нужных для алгоритма переменных
    QByteArray txtBytes;
    txtBytes = text->toPlainText().toUtf8();
    int txtLenght = txtBytes.length();
    QByteArray smplBytes;
    smplBytes = sample->text().toUtf8();
    int smplLenght = smplBytes.length();

    // стоит проверить, а заполнены ли поля
    if(txtLenght == 0 || smplLenght == 0) {
        emit timeIsReady(QString::number(0));
        emit resultIsReady(QString("Недостаточно информации"));
        emit stop();
        return;
    }
    timer.start();
    // для начала проинициализируем массив сдвигов
    for(int i = 0; i < arrayShiftSize; i++) {
        shift[i] = smplLenght;
    }
    // а теперь заполним его нужными значениями сдвигов
    for(int i = 0; i <= smplLenght - 2; i++) {
        shift[(int) smplBytes[i]] = smplLenght - i - 1;
    }
    // подготовления к основному алгоритму
    int i = smplLenght;
    int j = smplLenght;
    int k = i;
    // сам алгоритм
    while(j > 0 && i <= txtLenght) {
        if (txtBytes[k-1] == smplBytes[j-1]) {
            k--;
            j--;
        }
        else  {
            i += shift[(int) txtBytes[i-1]];
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
