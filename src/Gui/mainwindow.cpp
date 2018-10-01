#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutgamedialog.h"
#include "helpdialog.h"
#include "gamewindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(width(), height());    // disables the maximization button in the MainWindow (fixed size: 640x476)
    run.initRun(2);                     // initialize the run object - 2 stands for the number the arrow-star combinations are shown in a run
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAddDatabase_triggered()
{
    // at the Moment without a window
}

// open the Helpwindow dialog
void MainWindow::on_actionHelp_triggered()
{
    HelpDialog help_dialog;
    // Helpwindow is everytime in foreground
    help_dialog.setModal(true);
    help_dialog.exec();
}

// open the About Game dialog
void MainWindow::on_actionAboutReactiongame_triggered()
{
    AboutGameDialog about_game;
    // AboutGamewindow is everytime in foreground
    about_game.setModal(true);
    about_game.exec();
}

// open the Gaming window
void MainWindow::on_startGamePushButton_clicked()
{
    // save if the savePersonalData succeeded
    bool saveData;
    // TODO: only start the Game, if all needed user datas specified.
    // it also need a destructor (keyReciever recieves the ESC-Key)
    // load all QStrings of the Edit Objects for game_window->savePersonalData
    QString name = ui->nameLineEdit->text();
    QString forename = ui->forenameLineEdit->text();
    QString notice = ui->noticeTextEdit->toPlainText();
    QString year = ui->yearLineEdit->text();
    QString month = ui->monthLineEdit->text();
    QString day = ui->dayLineEdit->text();

    // construct game_window object
    MainWindow::game_window = new GameWindow(0, &run);
    // save the personal data
    /*saveData = MainWindow::game_window->savePersonalData(name, forename, notice, day, month, year);
    if(!saveData){
        // destroyes the GameWindow object, else every false input will create a new Object
        delete MainWindow::game_window;
        return;
    }*/

    MainWindow::game_window->setWindowState(Qt::WindowFullScreen);
    /* TODO:
    exec() or show() -> exec() opens a new loop
                     -> show() opens no new loop
                     (What is better for the gaming window)

    */
    MainWindow::game_window->show();
}
