#include "mainwindow.h"
#include <QWidget>
#include <QLabel>
#include <QIcon>
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>
#include <QLineEdit>
#include <vector>       // Not needed
#include <QGroupBox>
#include <QRadioButton> //Needed
#include <QString>
#include <QObject>
// XML AREA
#include <QDomNode>
#include <QDebug>
#include <QtXml>
#include <QTranslator> // Not needed


static void insert()
{
    qDebug() << "pressed left button from static context";
    MainWindow hex = new MainWindow(); // a.k.a HelperUtil (Java);
    hex.on_pushButton_clicked();
}
static void progress()
{
    qDebug() << "pressed right button from static context";
    MainWindow hex = new MainWindow();
    hex.on_rightBtn_clicked();
}
int main(int argc, char *argv[])
{
    //declare qt main application class with arguments
    QApplication a(argc, argv);
    /*
     * The QGroupBox instances in ui are pointers,
     * so you must assign them to a QGroupBox* (pointer), not a QGroupBox
     * (object on the stack).
    */

       // Translator approach

    QTranslator qtTranslator;
    if (qtTranslator.load(QLocale::system(),
                          "qt", "_",
                          QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
    {
        qDebug() << "qtTranslator ok";
        a.installTranslator(&qtTranslator);
    }


    QPushButton *mary ; // NoAction Cast Away
    QLabel      *pointer ;
    // Create a document to write XML
    QDomDocument document;

    // Making the root element
    QDomElement root = document.createElement("Outer Element");

    // Adding the root element to the docuemnt
    document.appendChild(root);
    // Making the root element
    QDomElement router = document.createElement("Inner Element");

    QDomElement router2 = document.createElement("Magic Element");
    root.appendChild(router);


    // Writing to a file
    QFile file("people.xml"); // Or QFile file ("C:/Test/people.xml")
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Open the file for writing failed you fool!";
    }
    else
    {
        QTextStream stream(&file);
        stream << document.toString();
        mary  = new QPushButton(document.toString());

        // Save from Stackoverflow
        QDomDocument current;
        current = document;

        QDomNode domo = (QDomNode) current.removeChild(router);

        domo.appendChild(router2);
        QDomDocument ddd = domo.toDocument();
        pointer = new QLabel("Terminator 2 is a good movie I think");
        pointer->setStyleSheet("background-color:yellow;font-size:22px");

        file.close();
        qDebug() << "Closing write process";
    }
    QGroupBox *groupBox = new QGroupBox ("Item Selection");
    QGroupBox *groupBox2 = new QGroupBox("Inclusive Radio Buttons");

    QRadioButton *radio1 = new QRadioButton("Item 1");
    QRadioButton *radio2 = new QRadioButton("Item 2");
    QRadioButton *radio3 = new QRadioButton("Item Ratio 3");
    QRadioButton *radio4 = new QRadioButton("Item Ratio 4");
    QRadioButton *radio5 = new QRadioButton("Item Ratio 5");

    radio1->setChecked(true);



    QLineEdit *nameEdit = new QLineEdit();
    //nameEdit->setProperty("mandatoryField", true);

    QLineEdit *emailEdit = new QLineEdit();
    //emailEdit->setProperty("mandatoryField", true);

    QVBoxLayout *vbox       =   	new QVBoxLayout;
    QVBoxLayout *layoutOld  =       new QVBoxLayout;
    QVBoxLayout *layoutNew  =       new QVBoxLayout;
    QHBoxLayout *layoutHorrer  =    new QHBoxLayout;

    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    vbox->addWidget(radio4);
    vbox->addWidget(radio5);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);
    groupBox->setStyleSheet("font-size:14pt;"

                              "background-color: lightgray;"
                              "selection-color: yellow;"
                              "selection-background-color: blue;");

    //attempt to gain height: vector<int> alpha = {1,2,4,5,9};
    //create a window widget object
    QWidget *window = new QWidget();

    //declare a size object for size of window
    QSize window_size;
    window_size.setWidth(910);
    window_size.setHeight(800);
    //faehigkeitsluecke


    //declare a point and win safety prize
    QPoint window_lo;
    window_lo.setX(100);
    window_lo.setY(80);

    //set all properties to window
    window->resize(window_size);
    window->move(window_lo);
    window->setWindowTitle("Qt nice Demo");


    // Top Left Button (No function yet)
    QPushButton *sly = new QPushButton(); //
    sly->resize(200,45);
    sly->setText("Chose Item");

    sly->setStyleSheet("font-size:14pt;"

                                "background-color: lightgray;"
                                "selection-color: yellow;"
                                "selection-background-color: blue;");

    //sly->setStyleSheet('{background-color:lightgreen;color:black;}');

    sly->move(30,30);
    layoutNew->addWidget(sly);
    layoutNew->addWidget(groupBox);
    QHBoxLayout *quer = new QHBoxLayout();
    QPushButton *leftBtn  = new QPushButton("");
    QObject::connect(leftBtn, &QPushButton::pressed,[](){qDebug("They pressed me!");});
    QObject::connect(leftBtn, &QPushButton::pressed,insert);
    leftBtn->setStyleSheet("background-color:lightgreen;color:black;font-size:33px");
    /*like this
     * QPixmap pixmap("image_path");
        QIcon ButtonIcon(pixmap);
        button->setIcon(ButtonIcon);
        button->setIconSize(pixmap.rect().size());*/
    //    leftBtn->setIcon('info.png');
    QPixmap pixelMap ("C:\\Users\\tette\\Desktop\\QTBasic\\A400M\\info.png");
    QIcon ButtonIcon(pixelMap);
    leftBtn->setIcon(QIcon("C:\\Users\\tette\\Desktop\\QTBasic\\A400M\\info.png"));
    leftBtn->setIconSize(pixelMap.rect().size());

    QPushButton *rightBtn = new QPushButton("");
    QObject::connect(rightBtn, &QPushButton::pressed,progress);

    rightBtn->setStyleSheet("background-color:lightgreen;color:black;font-size:33px");
    rightBtn->setIcon(QIcon("C:\\Users\\tette\\Desktop\\QTBasic\\A400M\\question.png"));
    rightBtn->setIconSize(pixelMap.rect().size());

    quer->addWidget(leftBtn);
    quer->addWidget(rightBtn);
    layoutOld->addLayout(quer);
    layoutOld->addWidget(mary);
    layoutOld->addWidget(pointer);
    layoutOld->addWidget(groupBox2);

    layoutHorrer->addLayout(layoutNew); // Transformation
    layoutHorrer->addLayout(layoutOld);
    window->setLayout(layoutHorrer);
    window->show();
    return a.exec();
}
