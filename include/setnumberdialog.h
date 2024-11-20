#ifndef SETNUMBERDIALOG_H
#define SETNUMBERDIALOG_H

#include <QDialog>

namespace Ui {
class SetNumberDialog;
}

class SetNumberDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetNumberDialog(QWidget *parent = nullptr);
    ~SetNumberDialog();
    int getValue();
    void setText(QString text);
    void setValue(unsigned int value);
private:
    Ui::SetNumberDialog *ui;
};

#endif // SETNUMBERDIALOG_H
