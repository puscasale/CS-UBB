#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>
#include "tests.h"
#include "Repo.h"
#include "ui.h"
#include "Validator.h"
void start_app() {
    //Repo rep;
    RepoLab rep;
    //RepoInFile rep(R"(C:\Users\Ale\Desktop\oop\lab6_7\file.txt)");
    Validator valid;
    Service srv{rep, valid};
    UI ui{srv};
    ui.start();
}

int main() {
    test_all();
    start_app();
    _CrtDumpMemoryLeaks();
    return 0;
}
