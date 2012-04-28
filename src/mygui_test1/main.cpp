#include "MyGUI.h"
#include "MyGUI_OgrePlatform.h"
#include <OgreRoot.h>
#include <OgreSceneManager.h>
#include <OgreCamera.h>
#include <OgreRenderWindow.h>



int main(int argc, char ** argv){
    //initialise ogre
    Ogre::Root * ogre_root = new Ogre::Root();
    ogre_root->showConfigDialog();

    Ogre::ResourceGroupManager::getSingleton().addResourceLocation("../data/Media/MyGUI_Media", "FileSystem",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, false);
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation("../data/Media/MyGUI_Media/Common/Base","FileSystem", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,  false);
    ogre_root->initialise(true);
    Ogre::RenderWindow * render_wnd = ogre_root->getAutoCreatedWindow();

    Ogre::SceneManager * smgr = 0;
    Ogre::SceneManagerEnumerator::MetaDataIterator itr1 = ogre_root->getSceneManagerMetaDataIterator();
    smgr = ogre_root->createSceneManager(itr1.peekNext()->typeName, "my_smgr");
    if(!smgr){
        std::cout<<"there is no available scenemanager here"<<std::endl;
        return 1;
    }

    Ogre::Camera * camera = smgr->createCamera("my_camera1");
    Ogre::Viewport * vp = render_wnd->addViewport(camera);

   //

    MyGUI::Gui * ui = new MyGUI::Gui();
    MyGUI::OgrePlatform * platform = new MyGUI::OgrePlatform();
    platform->initialise(render_wnd,smgr);
    ui->initialise();



    MyGUI::Button *  button = ui->createWidget<MyGUI::Button>("Button",10,10,300,26,MyGUI::Align::Default,"Main");

    ogre_root->startRendering();




    return 0;
}
