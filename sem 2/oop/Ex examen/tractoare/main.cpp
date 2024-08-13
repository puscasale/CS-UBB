#include <QApplication>
#include <QPushButton>
#include "GUI.h"
#include "Srv.h"
#include "Repo.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Repo rep(R"(C:\Users\Ale\Desktop\tractoare\in.txt)");
    Srv srv(rep);
    GUI gui(srv);
    gui.show();
    return QApplication::exec();
}
