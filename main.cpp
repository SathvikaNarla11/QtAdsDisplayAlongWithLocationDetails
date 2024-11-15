#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


//#include <QApplication>
//#include <QMediaPlayer>
//#include "mainwindow.h"

//int main(int argc, char *argv[])
//{
//    // Set environment variable to use FFmpeg for multimedia playback
//    qputenv("QT_MULTIMEDIA_PREFERRED_PLUGINS", "ffmpeg");

//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
//}
