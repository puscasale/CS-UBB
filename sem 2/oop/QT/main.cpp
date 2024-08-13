#include <QApplication>
#include <QPushButton>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlistwidget.h>
#include "GUI.h"
#include "Service.h"
#include "tests.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    test_all();
    RepoInFile activity(R"(C:\Users\Ale\Desktop\QT\file.txt)");
    Validator valid;
    Service srv(activity, valid);

    GUI gui(srv);
    gui.show();
    return a.exec();
}
