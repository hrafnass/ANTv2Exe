#include "savedialog.h"
#include "ui_savedialog.h"

SaveDialog::SaveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveDialog)
{
    ui->setupUi(this);
}

SaveDialog::~SaveDialog()
{
    delete ui;
}


// The cancel-button("Abbrechen") quits the game. No data will be saved.
void SaveDialog::on_saveButtonBox_rejected()
{
    // Dialogwindow closed
    this->close();
}

// The save-button("OK") quits the game. All measured data will be saved.
void SaveDialog::on_saveButtonBox_accepted()
{
    /*
    Save all measured Data
    */
    this->close();
}
