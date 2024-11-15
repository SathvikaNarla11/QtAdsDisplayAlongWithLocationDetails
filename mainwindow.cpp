#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer();
    videoWidget = new QVideoWidget(this);
    videoWidget->setGeometry(ui->imageLabel->geometry());
    player->setVideoOutput(videoWidget);

    playTimer = new QTimer(this);
    pauseTimer = new QTimer(this);

    connect(playTimer, &QTimer::timeout, this, &MainWindow::pauseAndShowImage);
    connect(pauseTimer, &QTimer::timeout, this, &MainWindow::resumeVideo);

    loadMediaFiles();
    currentVideoIndex = 0;
    currentImageIndex = 0;

    // Start playing video automatically when the application is launched
    playNextVideo();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadMediaFiles()
{
    // Populate video and image file paths
    videoPaths << "C:/Users/DT_Server/Documents/QT-Tasks/QtVideoWidget/videoWidget/xyz/Videos/1.mpg"
               << "C:/Users/DT_Server/Documents/QT-Tasks/QtVideoWidget/videoWidget/xyz/Videos/2.mpg"
               << "C:/Users/DT_Server/Documents/QT-Tasks/QtVideoWidget/videoWidget/xyz/Videos/samsung.mpg";
    imagePaths << "C:/Users/DT_Server/Documents/QT-Tasks/QtVideoWidget/videoWidget/xyz/images/1.png"
               << "C:/Users/DT_Server/Documents/QT-Tasks/QtVideoWidget/videoWidget/xyz/images/2.png"
               << "C:/Users/DT_Server/Documents/QT-Tasks/QtVideoWidget/videoWidget/xyz/images/3.png";
}

void MainWindow::playNextVideo()
{
    if (currentVideoIndex >= videoPaths.size())
    {
        // End of playlist, reset counters or stop playback as needed
        currentVideoIndex = 0;
        return;
    }

    QString fileName = videoPaths[currentVideoIndex];
    videoWidget->show();
    player->setMedia(QUrl::fromLocalFile(fileName));
    player->play();

    playTimer->start(10000);
}

void MainWindow::pauseAndShowImage()
{
    player->pause();
    videoWidget->hide();

    // Display the corresponding image
    if (currentImageIndex < imagePaths.size())
    {
        QPixmap pixmap(imagePaths[currentImageIndex]);
        ui->imageLabel->setPixmap(pixmap);
        ui->imageLabel->setScaledContents(true);
        ui->imageLabel->show();
    }

    playTimer->stop();
    pauseTimer->start(5000);
}

void MainWindow::resumeVideo()
{
    ui->imageLabel->clear();
    videoWidget->show();
    player->play();

    pauseTimer->stop();
    playTimer->start(10000);

    currentImageIndex++;
    if (currentImageIndex >= imagePaths.size())
    {
        currentImageIndex = 0;
    }
}

void MainWindow::mediaFinished()
{
    currentVideoIndex++;
    playNextVideo();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    videoWidget->setGeometry(ui->imageLabel->geometry());
}





















//#include "mainwindow.h"
//#include "ui_mainwindow.h"
//#include <QFileDialog>
//#include <QPixmap>

//MainWindow::MainWindow(QWidget *parent)
//    : QMainWindow(parent)
//    , ui(new Ui::MainWindow)
//{
//    ui->setupUi(this);

//    player = new QMediaPlayer();
//    videoWidget = new QVideoWidget(this);
//    videoWidget->setGeometry(ui->imageLabel->geometry());
//    player->setVideoOutput(videoWidget);

//    playTimer = new QTimer(this);
//    pauseTimer = new QTimer(this);

//    connect(playTimer, &QTimer::timeout, this, &MainWindow::pauseAndShowImage);
//    connect(pauseTimer, &QTimer::timeout, this, &MainWindow::resumeVideo);

//    loadMediaFiles();
//    currentVideoIndex = 0;
//    currentImageIndex = 0;
//}

//MainWindow::~MainWindow()
//{
//    delete ui;
//}

//void MainWindow::loadMediaFiles()
//{
//    // Populate video and image file paths
//    videoPaths << "C:/Users/DT_Server/Documents/QT-Tasks/QtVideoWidget/videoWidget/xyz/Videos/1.mpg" << "C:/Users/DT_Server/Documents/QT-Tasks/QtVideoWidget/videoWidget/xyz/Videos/2.mpg" << "C:/Users/DT_Server/Documents/QT-Tasks/QtVideoWidget/videoWidget/xyz/Videos/samsung.mpg";
//    imagePaths << "C:/Users/DT_Server/Documents/QT-Tasks/QtVideoWidget/videoWidget/xyz/images/1.png" << "C:/Users/DT_Server/Documents/QT-Tasks/QtVideoWidget/videoWidget/xyz/images/2.png" << "C:/Users/DT_Server/Documents/QT-Tasks/QtVideoWidget/videoWidget/xyz/images/3.png";
//}

//void MainWindow::on_pushButton_clicked()
//{
//    playNextVideo();
//}

//void MainWindow::playNextVideo()
//{
//    if (currentVideoIndex >= videoPaths.size()) {
//        // End of playlist, reset counters or stop playback as needed
//        currentVideoIndex = 0;
//        return;
//    }

//    QString fileName = videoPaths[currentVideoIndex];
//    videoWidget->show();
//    player->setMedia(QUrl::fromLocalFile(fileName));
//    player->play();

//    playTimer->start(10000); // Start the timer to pause every 10 seconds
//}

//void MainWindow::pauseAndShowImage()
//{
//    player->pause();
//    videoWidget->hide();

//    // Display the corresponding image
//    if (currentImageIndex < imagePaths.size()) {
//        QPixmap pixmap(imagePaths[currentImageIndex]);
//        ui->imageLabel->setPixmap(pixmap);
//        ui->imageLabel->setScaledContents(true);
//        ui->imageLabel->show();
//    }

//    playTimer->stop();
//    pauseTimer->start(5000); // Pause for 5 seconds to display the image
//}

//void MainWindow::resumeVideo()
//{
//    ui->imageLabel->clear(); // Clear the image
//    videoWidget->show();
//    player->play();

//    pauseTimer->stop();
//    playTimer->start(10000); // Restart play timer

//    currentImageIndex++; // Move to the next image for the next pause
//    if (currentImageIndex >= imagePaths.size()) {
//        currentImageIndex = 0; // Reset or loop back
//    }
//}

//void MainWindow::mediaFinished()
//{
//    currentVideoIndex++; // Move to the next video
//    playNextVideo(); // Play the next video in the list
//}
//void MainWindow::resizeEvent(QResizeEvent *event)
//{
//    QMainWindow::resizeEvent(event);

//    // Set the geometry of the video widget to match the image label
//    videoWidget->setGeometry(ui->imageLabel->geometry());
//}

