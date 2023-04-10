
#ifndef A_H
#define A_H

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



private:
    Ui::app *ui;

};

#endif // A_H
