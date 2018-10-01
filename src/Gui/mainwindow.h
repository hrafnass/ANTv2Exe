#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "gamewindow.h"
#include "run.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAddDatabase_triggered();

    void on_actionHelp_triggered();

    void on_actionAboutReactiongame_triggered();

    void on_startGamePushButton_clicked();

private:
    Ui::MainWindow *ui;
    GameWindow *game_window;
    Run run;    // needed to create the runs and shuffel them, else i have every time the same shuffel
};

#endif // MAINWINDOW_H
