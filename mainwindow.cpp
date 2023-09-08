
#include "mainwindow.h"

void MainWindow::threadsInitialization(QPushButton *startSearch)
{
    // обработка потока линейного поиска
    QThread *linearSThread = new QThread;
    connect(linearSThread, SIGNAL(started()), linearSearch, SLOT(start()));
    connect(linearSearch, SIGNAL(stop()), linearSThread, SLOT(quit()));
    linearSearch->moveToThread(linearSThread);
    connect(startSearch, SIGNAL(pressed()), linearSThread, SLOT(start()));
    // обработка потока КПМ поиска
    QThread *kMPSThread = new QThread;
    connect(kMPSThread, SIGNAL(started()), kMPSearch, SLOT(start()));
    connect(kMPSearch, SIGNAL(stop()), kMPSThread, SLOT(quit()));
    kMPSearch->moveToThread(kMPSThread);
    connect(startSearch, SIGNAL(pressed()), kMPSThread, SLOT(start()));
    // обработка потока БМХ поиска
    QThread *bMHSThread = new QThread;
    connect(bMHSThread, SIGNAL(started()), bMHSearch, SLOT(start()));
    connect(bMHSearch, SIGNAL(stop()), bMHSThread, SLOT(quit()));
    bMHSearch->moveToThread(bMHSThread);
    connect(startSearch, SIGNAL(pressed()), bMHSThread, SLOT(start()));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    // виджеты для основного вертикального компоновщика
    QLabel *textFieldLabel = new QLabel("Поле основного текста:");
    textFieldLabel->setAlignment(Qt::AlignHCenter);
    QTextEdit *textField = new QTextEdit;
    QPushButton *loadFile = new QPushButton("Загрузить текст из файла");
    QLabel *sampleFieldLabel = new QLabel("Поле образа для поиска:");
    sampleFieldLabel->setAlignment(Qt::AlignHCenter);
    QLineEdit *sampleField = new QLineEdit;
    QPushButton *startSearch = new QPushButton("Начать поиск");
    // подвиджеты названий поиска и компоновщик для них
    QHBoxLayout *namesSearchLayout = new QHBoxLayout;
    QLabel *linearSearchName = new QLabel("Линейный");
    QLabel *kMPSearchName = new QLabel("Кнут-Моррис-Пратт");
    QLabel *bMHSearchName = new QLabel("Бойера-Мура-Хорпспула");
    // подвиджеты для результата поиска и компоновщик для них
    QLabel *resultsLabel = new QLabel("Результаты поиска образа:");
    resultsLabel->setAlignment(Qt::AlignHCenter);
    QHBoxLayout *resultsLayout = new QHBoxLayout;
    QLabel *linearSearchResult = new QLabel("0");
    QLabel *kMPSearchResult = new QLabel("0");
    QLabel *bMHSearchResult = new QLabel("0");
    // подвиджеты для времени поиска и компоновщик для них
    QLabel *timesLabel = new QLabel("*Время поиска образа (в наносекундах):*");
    timesLabel->setAlignment(Qt::AlignHCenter);
    QHBoxLayout *timesLayout = new QHBoxLayout;
    QLabel *linearTimeResult = new QLabel("0");
    QLabel *kMPTimeResult = new QLabel("0");
    QLabel *bMHTimeResult = new QLabel("0");
    // добавление виджетов в подкомпоновщик имен алгоритмов поиска
    namesSearchLayout->addWidget(linearSearchName, 1, Qt::AlignHCenter);
    namesSearchLayout->addWidget(kMPSearchName, 1, Qt::AlignHCenter);
    namesSearchLayout->addWidget(bMHSearchName, 1, Qt::AlignHCenter);
    // добавление виджетов в подкомпоновщик результатов поиска
    resultsLayout->addWidget(linearSearchResult, 1, Qt::AlignHCenter);
    resultsLayout->addWidget(kMPSearchResult, 1, Qt::AlignHCenter);
    resultsLayout->addWidget(bMHSearchResult, 1, Qt::AlignHCenter);
    // добавление виджетов в подкомпоновщик времени поиска
    timesLayout->addWidget(linearTimeResult, 1, Qt::AlignHCenter);
    timesLayout->addWidget(kMPTimeResult, 1, Qt::AlignHCenter);
    timesLayout->addWidget(bMHTimeResult, 1, Qt::AlignHCenter);
    // добавление основных виджетов и подкомпоновщиков в основной компоновщик
    mainLayout->addWidget(textFieldLabel);
    mainLayout->addWidget(textField);
    mainLayout->addWidget(loadFile, 0, Qt::AlignRight);
    mainLayout->addWidget(sampleFieldLabel);
    mainLayout->addWidget(sampleField);
    mainLayout->addWidget(startSearch, 0, Qt::AlignRight);
    mainLayout->addWidget(resultsLabel);
    mainLayout->addItem(namesSearchLayout);
    mainLayout->addItem(resultsLayout);
    mainLayout->addWidget(timesLabel);
    mainLayout->addItem(timesLayout);
    // создание и инициализация основного виджета окна у установка в нем нашего компоновщика
    QWidget *mainWidget = new QWidget;
    setCentralWidget(mainWidget);
    mainWidget->setLayout(mainLayout);
    setFixedSize(600,500);
    // инициализация собственного класса файлового менеджера и связывание
    // его слота с сигналом нажатия кнопки
    fileDialog = new MyFileDialog(textField);
    connect(loadFile, SIGNAL(pressed()), fileDialog, SLOT(loadTxtFileInField()));
    // начальная инициализация поисковиков(теперь всех)
    linearSearch = new LinearSearch(textField, sampleField);
    connect(linearSearch, SIGNAL(resultIsReady(QString)), linearSearchResult, SLOT(setText(QString)));
    connect(linearSearch, SIGNAL(timeIsReady(QString)), linearTimeResult, SLOT(setText(QString)));
    kMPSearch = new KMPSearch(textField, sampleField);
    connect(kMPSearch, SIGNAL(resultIsReady(QString)), kMPSearchResult, SLOT(setText(QString)));
    connect(kMPSearch, SIGNAL(timeIsReady(QString)), kMPTimeResult, SLOT(setText(QString)));
    bMHSearch = new BMHSearch(textField, sampleField);
    connect(bMHSearch, SIGNAL(resultIsReady(QString)), bMHSearchResult, SLOT(setText(QString)));
    connect(bMHSearch, SIGNAL(timeIsReady(QString)), bMHTimeResult, SLOT(setText(QString)));
    // завершающая инициализация потоков для поисковиков вместе с сигнально-слотовыми соединениями;
    // теперь при нажатии на "Начать поиск" будут запускаться потоки для всех
    // написанных алгоритмов поиска
    threadsInitialization(startSearch);
}

