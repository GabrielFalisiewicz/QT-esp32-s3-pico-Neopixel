#include "ui_mainwindow.h"
#include "QPixmap"
#include <mainwindow.h>
#include <leds.h>
#include <QColor>
#include <QPalette>
#include <communication.h>
#include <QIntValidator>

QColor Gcurrent_color;
std::vector<LED_MODULE> leds;
CONNECTION con;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmap(":/img/led.png");
    pixmap = pixmap.scaled(ui->image->height(), ui->image->width(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->image->setPixmap(pixmap);
}

QLabel* MainWindow::get_labels(QString name){
    QLabel *search = this->findChild<QLabel*>(name);
    return search;
}

void MainWindow::init_elemenets_GUI(){
    ui->image->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    leds.reserve(LED_MODULE::NUM_OF_LEDS);
    for(int i=0; i<LED_MODULE::NUM_OF_LEDS;i++){
        LED_MODULE new_led;
        new_led.set_numer_led(i);
        QString search_label = QString("led%1").arg(i);
        QLabel* finded_label = get_labels(search_label);
        finded_label->setAutoFillBackground(1);
        finded_label->installEventFilter(this);
        new_led.set_label_ptr(finded_label);
        leds.push_back(new_led);
    }
    ui->ipHost->setValidator(new QIntValidator(0, 9999, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *object, QEvent *event){
    for(int i=0; i<LED_MODULE::NUM_OF_LEDS; i++){
        if(object == leds[i].get_qlabel_ptr() && event->type() == QEvent::MouseButtonPress){
            if(!leds[i].get_active_status()){
                leds[i].set_active(1);
                leds[i].get_qlabel_ptr()->setStyleSheet(QString("border-radius: 35px; background-color: rgba(%1, %2, %3, 0.6);").arg(leds[i].get_current_red()).arg(leds[i].get_current_green()).arg(leds[i].get_current_blue()));
            }
            return true;
        }
    }
      return false;
}

void MainWindow::on_update_color_value_clicked()
{
    QString value_color = ui->color_value->toPlainText();
    if(!value_color.isEmpty()){
        QStringList values = value_color.split(',');
        Gcurrent_color.setRgb(
            values[0].toInt(),
            values[1].toInt(),
            values[2].toInt());
    } else {
        Gcurrent_color.setRgb(0,0,0);
    }
    for(int i=0;i<LED_MODULE::NUM_OF_LEDS;i++){
        if(leds[i].get_active_status()){
            leds[i].set_active(0);
            leds[i].set_rgb_color(Gcurrent_color);
            leds[i].get_qlabel_ptr()->setStyleSheet(QString("border-radius: 35px; background-color: rgb(%1, %2, %3);").arg(Gcurrent_color.red()).arg(Gcurrent_color.green()).arg(Gcurrent_color.blue()));
        }
    }
    con.send_message(leds);
}


void MainWindow::on_enter_network_data_clicked()
{
    con.set_host(ui->ipv4addr->text());
    con.set_port((ui->ipHost->text().toInt()));
}

