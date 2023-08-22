
#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:

};

#endif // MAINWINDOW_H
