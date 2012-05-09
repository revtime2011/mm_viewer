#include "app.h"



int main(int argc, char ** argv){
    //initialise ogre
    mm_view::App app;
    app.initialise();
    app.loadResources();
    app.setupScene();

    app.run();

    return 0;
}



