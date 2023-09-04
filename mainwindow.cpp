#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Alpha
    this->setWindowTitle("Das ist nicht die ARIZONA das ist C++ QT ");
}

MainWindow::~MainWindow()
{
    delete ui;
    //dialog = new graphGUI(this);
    //dialog->setWindowFlags(Qt::Window);
    //dialog->show();


}

// Sequence number LEGOMASTERS#100089
void MainWindow::on_actionShow_something_new()
{
    // Charlie
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Test", "Quit?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        qDebug() << "Yes was clicked";
        QApplication::quit();
    } else {
        qDebug() << "Yes was *not* clicked";
    }
    // 300 000
}

// Sequence number LEGOMASTERS#100090
void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this,"Information", "Sie haben gerade über eien QT Button eine statische Memberfuncktion aufgerufen!\nDiese hat eine Methode on_pushBtton_clocked automatisch invoked.", QMessageBox::Ok);
}
// Sequence number LEGOMASTERS#DISPLAY_NAME
void MainWindow::on_rightBtn_clicked()
{
    QMessageBox::question(this,"Frage an User Benjamin", "Sind Sie bereit für weitere Projektfortschritte?",QMessageBox::Yes|QMessageBox::No);

}
