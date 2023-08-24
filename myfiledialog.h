
#ifndef MYFILEDIALOG_H
#define MYFILEDIALOG_H

#include <QFileDialog>
#include <QWidget>

class MyFileDialog : public QFileDialog
{
    Q_OBJECT
public:
    MyFileDialog(QWidget *parent = 0);
};

#endif // MYFILEDIALOG_H
