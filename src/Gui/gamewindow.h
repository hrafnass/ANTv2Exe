#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QLabel>
#include <QString>
#include <QTime>
#include <QTimer>
#include <string>

// widgets
#include "savedialog.h"
// static libs
#include "run.h"

// TODO: HERAUSFINDEN WARUM QLABEL PROBLEME HAT 2 BILDER UNTERSCHIEDLICHER GRÖßE NACHEINANDER ZU LADEN
// AW: die label hatten bei der Einstellung allignment Linksbündig und nicht zentriert

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    // get the personal data from mainwindow
    explicit GameWindow(QWidget *parent = 0, Run *loaded_run = nullptr);
    ~GameWindow();
    // if the return is false, not all personal data are right
    bool savePersonalData(QString name, QString forename, QString notice, QString birth_day, QString birth_month, QString birth_year);
protected:
    void keyPressEvent(QKeyEvent *event);
private:
    // Methods
    void loadImages();
    // Variables
    Ui::GameWindow *ui;
    SaveDialog save_dialog;
    // QTime object to measure the reactiontime
    QTime measure_reactiontime;
    // saves the picture names
    //const std::vector<std::string> starnames {":/double.svg", ":/mid.svg", ":/up_or_down.svg"};
    const std::string star_image_mid = ":/star.svg";
    const std::string star_image_up_down = ":/star_u_d.svg";
    const std::vector<std::string> filenames {":/lllll.svg", ":/rrlrr.svg", ":/sslss.svg", ":/rrrrr.svg", ":/llrll.svg", ":/ssrss.svg"};    // arrow names
    const std::string free_image = ":/free_space.svg";
    // load the run
    Run *run = nullptr;
    // read variable for run
    bool read = true;
};

#endif // GAMEWINDOW_H
