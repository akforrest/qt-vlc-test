#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>

#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>
#include <VLCQtWidgets/WidgetVideo.h>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QGraphicsRectItem>
#include <QHBoxLayout>

#include <QFileDialog>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	/*

    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 500, 500);

    QGraphicsView * view = new QGraphicsView(scene);

    this->setCentralWidget(view);

    ////////////////////////////////////////////////////////////////////////////

    VlcInstance * vlcInstance = new VlcInstance(VlcCommon::args(), this);

    ////////////////////////////////////////////////////////////////////////////

    QGraphicsProxyWidget * proxy = new QGraphicsProxyWidget();

    VlcWidgetVideo * video = new VlcWidgetVideo();
    video->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    proxy->setWidget(video);

    scene->addItem(proxy);

    proxy->setZValue(1000); // higher is higher
    proxy->setPos(10, 10);
    proxy->resize(400, 400);

    VlcMediaPlayer * player = new VlcMediaPlayer(vlcInstance);

    // do you need to do both these calls?
    player->setVideoWidget(video);
    video->setMediaPlayer(player);

    ////////////////////////////////////////////////////////////////////////////

	VlcMedia * vlcMedia = new VlcMedia("C:/dev/test.avi", true, vlcInstance);
    player->open(vlcMedia);

    //QTimer::singleShot(1000, [video, player](){
    //    qDebug() << video->geometry();
    //    qDebug() << video->isVisible();
    //});
	*/

	VlcInstance * vlcInstance = new VlcInstance(VlcCommon::args(), this);

	VlcWidgetVideo * video = new VlcWidgetVideo(this);
	this->setCentralWidget(video);

	VlcMediaPlayer * player = new VlcMediaPlayer(vlcInstance);

	// do you need to do both these calls?
	player->setVideoWidget(video);
	video->setMediaPlayer(player);

	QString url = QFileDialog::getOpenFileName(this);

	VlcMedia * vlcMedia = new VlcMedia(url, true, vlcInstance);
	player->open(vlcMedia);
}

MainWindow::~MainWindow()
{
    delete ui;
}
