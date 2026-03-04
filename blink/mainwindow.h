#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QLabel"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLabel* get_labels(QString name);
    void init_elemenets_GUI();

private slots:
    void on_update_color_value_clicked();

    //void on_pushButton_clicked();
    void update_color_label(int rValue);

    void on_enter_network_data_clicked();

private:
    Ui::MainWindow *ui;
    bool eventFilter(QObject *object, QEvent *event) override;
};
#endif // MAINWINDOW_H
