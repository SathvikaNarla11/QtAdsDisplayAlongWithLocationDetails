#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QTimer>
#include <QStringList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
//    void on_pushButton_clicked();
    void pauseAndShowImage();
    void resumeVideo();
    void mediaFinished();
    void resizeEvent(QResizeEvent *event);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    QTimer *playTimer;
    QTimer *pauseTimer;

    QStringList videoPaths;
    QStringList imagePaths;
    int currentVideoIndex;
    int currentImageIndex;

    void loadMediaFiles();
    void playNextVideo();
};

#endif // MAINWINDOW_H

































//#ifndef MAINWINDOW_H
//#define MAINWINDOW_H

//#include <QMainWindow>
//#include <QMediaPlayer>
//#include <QVideoWidget>
//#include <QTimer>

//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

//class MainWindow : public QMainWindow
//{
//    Q_OBJECT

//public:
//    MainWindow(QWidget *parent = nullptr);
//    ~MainWindow();

//private slots:
//    void on_pushButton_clicked();
//    void pauseAndShowImage();
//    void resumeVideo();
//    void resizeEvent(QResizeEvent *event);

//private:
//    Ui::MainWindow *ui;
//    QMediaPlayer *player;
//    QVideoWidget *videoWidget;  // QVideoWidget to show video in QLabel
//    QTimer *playTimer;          // Timer for 10 seconds of video play
//    QTimer *pauseTimer;         // Timer for 5 seconds of image display
//};

//#endif // MAINWINDOW_H


