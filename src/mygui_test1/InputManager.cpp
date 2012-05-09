#include "InputManager.h"



namespace input{

InputManager::InputManager(Ogre::RenderWindow * rnd){
    std::cout<<"input::InputManager instruct!!"<<std::endl;
    OIS::ParamList pl;
    size_t windowHnd = 0 ;
    std::ostringstream stream1 ;
    rnd->getCustomAttribute("WINDOW", &windowHnd);
    stream1 << windowHnd;
    std::cout<<"windowHnd : "<<stream1.str()<<std::endl;

    pl.insert(std::make_pair(std::string("WINDOW"), stream1.str()));

    ois_manager = OIS::InputManager::createInputSystem(pl);
    int wnd_width;
    int wnd_height;
    wnd_width = rnd->getWidth();
    wnd_height = rnd->getHeight();



    mouse = static_cast<OIS::Mouse *> (ois_manager->createInputObject(OIS::OISMouse, true));
    mouse->getMouseState().width = wnd_width;
    mouse->getMouseState().height = wnd_height;
    mouse->setEventCallback(this);

    std::cout<<"input::InputManager instruct finished!!"<<std::endl;
}


InputManager::~InputManager(){
    ois_manager->destroyInputObject(mouse);
    OIS::InputManager::destroyInputSystem(ois_manager);
    std::cout<<"Input Manager destroyed"<<std::endl;
}

bool InputManager::mouseMoved(const OIS::MouseEvent &arg){
    MyGUI::InputManager::getInstance().injectMouseMove(arg.state.X.abs, arg.state.Y.abs,arg.state.Z.abs);
    return true;
}


bool InputManager::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id){
    MyGUI::InputManager::getInstance().injectMousePress(arg.state.X.abs, arg.state.Y.abs,MyGUI::MouseButton::Enum(id));
    std::cout<<"mouse pressed : "<<arg.state.X.abs<<"  "<<arg.state.Y.abs<<"  "<<id<<std::endl;
    return true;
}

bool InputManager::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id ){
    MyGUI::InputManager::getInstance().injectMouseRelease(arg.state.X.abs, arg.state.Y.abs,MyGUI::MouseButton::Enum(id));
    return true;
}


void InputManager::update(int dt){
    mouse->capture();
    //std::cout<<mouse->getMouseState().X.abs<< "    &   "<<mouse->getMouseState().Y.abs<<std::endl;
}



}
