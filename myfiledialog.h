
#ifndef MYFILEDIALOG_H
#define MYFILEDIALOG_H

#include <QFileDialog>
#include <QWidget>
#include <QTextEdit>
#include <QByteArray>

class MyFileDialog : public QFileDialog
{
    Q_OBJECT

private:
    QTextEdit *textField;

public:
    MyFileDialog(QTextEdit *textField,
                 QWidget *parent = 0);

public slots:
    ///
    /// \brief loadTxtFileInField
    /// слот-метод загрузки данных текстового файла в поле
    void loadTxtFileInField();
};

#endif // MYFILEDIALOG_H
