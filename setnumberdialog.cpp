#include "setnumberdialog.h"
#include "ui_setnumberdialog.h"

SetNumberDialog::SetNumberDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SetNumberDialog)
{
    ui->setupUi(this);
}

SetNumberDialog::~SetNumberDialog()
{
    delete ui;
}

int SetNumberDialog::getValue() {
    return ui->spinBox->value();
}

void SetNumberDialog::setValue(unsigned value) {
    ui->spinBox->setValue(value);
}

void SetNumberDialog::setText(QString text) {
    ui->label->setText(text);
}
