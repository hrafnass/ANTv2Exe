#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "savedialog.h"
#include "stdio.h"
#include <iostream>

GameWindow::GameWindow(QWidget *parent, Run *loaded_run) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    ui->mid->setScaledContents(true);
    ui->mid->setPixmap(QPixmap(QString::fromUtf8(":/plus.svg")));
    // saves the run object, shuffel it and then load the images
    run = loaded_run;
    run->shuffelRun();
    loadImages();
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::loadImages(){ // first loadImages version. The eventloops have to be better
    // exit if the run object is null
    if(run == nullptr)
        return;
    Trial trial = run->readRun(read); // saves the readed trial of run
    QEventLoop loop1;
    QTimer::singleShot(500, &loop1, SLOT(quit()));
    loop1.exec();
    // deletes every image over and under the plussign and loads the plus sign in the mid
    ui->arrowUp1->setPixmap(QPixmap(QString::fromStdString(free_image)));
    ui->arrowDown1->setPixmap(QPixmap(QString::fromStdString(free_image)));
    ui->mid->setPixmap(QPixmap(QString::fromStdString(":/plus.svg")));
    switch (trial.getTrialStar()) { // has to create better
    case StarImage::both:
        ui->arrowUp1->setPixmap(QPixmap(QString::fromStdString(star_image_up_down)));
        ui->arrowUp1->setScaledContents(true);
        //ui->arrowUp1->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        ui->arrowDown1->setPixmap(QPixmap(QString::fromStdString(star_image_up_down)));
        ui->arrowDown1->setScaledContents(true);
        //ui->arrowDown1->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        break;
    case StarImage::mid:
        ui->mid->setPixmap(QPixmap(QString::fromStdString(star_image_mid)));
        ui->mid->setScaledContents(true);
        //ui->mid->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        break;
    case StarImage::up_or_down:
        if(trial.getTrialImagePos() == ImagePos::arrow_down){
            ui->arrowDown1->setPixmap(QPixmap(QString::fromStdString(star_image_up_down)));
            ui->arrowDown1->setScaledContents(true);
            //ui->arrowDown1->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        }else {
            ui->arrowUp1->setPixmap(QPixmap(QString::fromStdString(star_image_up_down)));
            ui->arrowUp1->setScaledContents(true);
            //ui->arrowUp1->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        }
        break;
    default:
        break;
    }
    // creates a loop, which waits a second and than load a new image ( arrows)
    QTimer::singleShot(1000, &loop1, SLOT(quit()));
    loop1.exec();
    // checks if the image position is over or under the plus sign
    ui->mid->setPixmap(QPixmap(QString::fromStdString(":/plus.svg")));
    ui->mid->setScaledContents(true);
    if(trial.getTrialImagePos() == ImagePos::image_pos::arrow_up){   // loads the image in the label over the plus
        ui->arrowUp1->setPixmap(QPixmap(QString::fromStdString(trial.getArrowImage())));
        //ui->arrowUp1->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        ui->arrowUp1->setScaledContents(true);
        ui->arrowDown1->setPixmap(QPixmap(QString::fromStdString(":/free_space.svg")));
        ui->arrowDown1->setScaledContents(true);
        //ui->arrowDown1->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );


    }else {                                         // loads the image in the label under the plus
        ui->arrowDown1->setPixmap(QPixmap(QString::fromStdString(trial.getArrowImage())));
        ui->arrowDown1->setScaledContents(true);
        //ui->arrowDown1->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        ui->arrowUp1->setPixmap(QPixmap(QString::fromStdString(":/free_space.svg")));
        ui->arrowUp1->setScaledContents(true);
        //ui->arrowUp1->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    }
}

// Public Methods
void GameWindow::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_Escape:
        save_dialog.setModal(true);
        save_dialog.exec();
        // Hier muss noch überprüft werden ob qt::KeyEscape nicht deprivated o.ä. ist
        this->close();
        // TEST IF I HAVE TO DELETE THE OBJECT - MAYBE I DON'T NEED IT 'CAUSE OF THE MAINWINDOW.CPP
        // delete this;
        break;
    case Qt::Key_Left:
        // Abfangen des Linken Pfeil
        //printf("Linker Pfeil %d\n", GameWindow::measure_reactiontime.restart());
        loadImages();
        break;
    case Qt::Key_Right:
        // Abfangen des Rechten Pfeil
        //printf("Rechter Pfeil %d\n", GameWindow::measure_reactiontime.restart());
        loadImages();
        break;
    default:
        // Jede andere Taste
        printf("andere Taste\n");
        break;
    }
}
