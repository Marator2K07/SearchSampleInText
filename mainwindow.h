
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "myfiledialog.h"
#include "linearsearch.h"
#include "kmpsearch.h"

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
    MyFileDialog *fileDialog;
    LinearSearch *linearSearch;
    KMPSearch *kMPSearch;

private:
    void threadsInitialization(QPushButton *startSearch);

public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:

};

#endif // MAINWINDOW_H
