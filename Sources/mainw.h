#ifndef MAINW_H
#define MAINW_H

#include <QMainWindow>

namespace Ui {
class mainw;
}

class mainw : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainw(QWidget *parent = 0);
    ~mainw();

private slots:
    void on_speedtestbutton_clicked();

private:
    Ui::mainw *ui;
};

#endif // MAINW_H
