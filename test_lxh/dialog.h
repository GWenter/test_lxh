#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtMultimedia>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    QMediaPlayer *player;
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_btn_p_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
