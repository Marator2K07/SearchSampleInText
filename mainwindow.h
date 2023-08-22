
#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "linearsearch.h"

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QThread>


class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    LinearSearch *linearSearch;

private:
    void threadsInitialization(QPushButton *startSearch);

public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:

};

#endif // MAINWINDOW_H
