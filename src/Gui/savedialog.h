#ifndef SAVEDIALOG_H
#define SAVEDIALOG_H

#include <QDialog>

namespace Ui {
class SaveDialog;
}

class SaveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SaveDialog(QWidget *parent = 0);
    ~SaveDialog();

private slots:
    void on_saveButtonBox_rejected();

    void on_saveButtonBox_accepted();

private:
    Ui::SaveDialog *ui;
};

#endif // SAVEDIALOG_H
