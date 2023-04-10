
#ifndef APP_H
#define APP_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class app; }
QT_END_NAMESPACE

class app : public QMainWindow

{
    Q_OBJECT

public:
    app(QWidget *parent = nullptr);
    ~app();


private slots:
    void on_set_clicked();
    void decrement();
    void imageChanger();
    void nameChanger();
    void typeChanger();
    void numChanger();
    void atkChanger();
    void dfChanger();
    void speedChanger();
    void satkChanger();
    void sdfChanger();
    void hpChanger();





private:
    Ui::app *ui;

};

#endif // APP_H
