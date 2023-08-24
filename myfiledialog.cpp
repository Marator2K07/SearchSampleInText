
#include "myfiledialog.h"

MyFileDialog::MyFileDialog(QTextEdit *textField,
                           QWidget *parent)
    : QFileDialog(parent)
    , textField{textField}
{
}

void MyFileDialog::loadTxtFileInField()
{
    // определяем местную функцию
    auto fileContentReady = [&](const QString &fileName,
                                const QByteArray &fileContent) {
        if (fileName.isEmpty()) {
            textField->setText("File no found or selected");
        } else {
            textField->setText(fileContent);
        }
    };
    // используем функцию выше для открытия текстовых файлов
    getOpenFileContent("Text files (*.txt)", fileContentReady);
}

