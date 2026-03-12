#include "ui_mainwindow.h"
#include "QPixmap"
#include <mainwindow.h>
#include <leds.h>
#include <QColor>
#include <QPalette>
#include <communication.h>
#include <QIntValidator>
#include "udpsocket.h"

QColor Gcurrent_color;
std::vector<LED_MODULE> leds;
CONNECTION con;
UdpSocket OwnNetwork;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmap(":/img/led.png");
    pixmap = pixmap.scaled(ui->image->height(), ui->image->width(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->image->setPixmap(pixmap);
    connect(ui->Rcolor, &QSlider::valueChanged, this, &MainWindow::update_color_label);
    connect(ui->Gcolor, &QSlider::valueChanged, this, &MainWindow::update_color_label);
    connect(ui->Bcolor, &QSlider::valueChanged, this, &MainWindow::update_color_label);
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
    ui->viewColor->setStyleSheet(QString("background-color: rgba(0, 0, 0, 1);"));
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
    int Rvalue = ui->Rcolor->value();
    int Gvalue = ui->Gcolor->value();
    int Bvalue = ui->Bcolor->value();
    Gcurrent_color.setRgb(Rvalue, Gvalue, Bvalue);

    for(int i=0;i<LED_MODULE::NUM_OF_LEDS;i++){
        if(leds[i].get_active_status()){
            leds[i].set_active(0);
            leds[i].set_rgb_color(Gcurrent_color);
            leds[i].get_qlabel_ptr()->setStyleSheet(QString("border-radius: 35px; background-color: rgb(%1, %2, %3);").arg(Gcurrent_color.red()).arg(Gcurrent_color.green()).arg(Gcurrent_color.blue()));
        }
    }
    if(con.get_data_status()){
        con.send_message(leds);
    }
}


void MainWindow::on_enter_network_data_clicked()
{
    //con.set_host(ui->ipv4addr->text());
    //con.set_port((ui->ipHost->text().toInt()));
    //con.set_data(true);
    OwnNetwork.create_socket();
    OwnNetwork.set_sockaddr(ui->ipv4addr->text(), ui->ipHost->text().toInt());
}

void MainWindow::update_color_label(int redValue){
    QSlider *slider = qobject_cast<QSlider*>(sender());
    if(slider == nullptr) return;

    if(slider == ui->Rcolor){
        ui->Rvalue->setText(QString::number(redValue));
    } else if(slider == ui->Gcolor){
        ui->Gvalue->setText(QString::number(redValue));
    } else if(slider == ui->Bcolor){
        ui->Bvalue->setText(QString::number(redValue));
    }
    ui->viewColor->setStyleSheet(QString("background-color: rgba(%1, %2, %3, 1);").arg((ui->Rvalue->text()).toInt()).arg((ui->Gvalue->text()).toInt()).arg((ui->Bvalue->text()).toInt()));
}
