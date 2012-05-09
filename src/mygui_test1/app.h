#include "MyGUI.h"
#include "MyGUI_OgrePlatform.h"
#include <OgreRoot.h>
#include <OgreSceneManager.h>
#include <OgreCamera.h>
#include <OgreRenderWindow.h>
#include "InputManager.h"


namespace mm_view{

class App : public Ogre::FrameListener{
public:
      bool frameStarted(const Ogre::FrameEvent& evt){
            input_manager->update(0);
            return true;
      }

      App(){
      }

      void initialise(){
            ogre_root = new Ogre::Root();
            ogre_root->showConfigDialog();
            ogre_root->initialise(true);
            render_wnd = ogre_root->getAutoCreatedWindow();
            ogre_root->addFrameListener(this);

            input_manager = new input::InputManager(render_wnd);

      }

      void loadResources(){
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation("../data/Media/MyGUI_Media", "FileSystem",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, false);
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation("../data/Media/MyGUI_Media/Common/Base","FileSystem", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,  false);
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation("../data/Media/Demos/Demo_Themes","FileSystem", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,  false);
            Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
      }

      void setupScene(){
            Ogre::SceneManager * smgr = 0;
            Ogre::SceneManagerEnumerator::MetaDataIterator itr1 = ogre_root->getSceneManagerMetaDataIterator();
            smgr = ogre_root->createSceneManager(itr1.peekNext()->typeName, "my_smgr");
            if(!smgr){
                std::cout<<"there is no available scenemanager here"<<std::endl;
                return ;
            }

            Ogre::Camera * camera = smgr->createCamera("my_camera1");
            Ogre::Viewport * vp = render_wnd->addViewport(camera);

        //

            MyGUI::Gui * ui = new MyGUI::Gui();
            MyGUI::OgrePlatform * platform = new MyGUI::OgrePlatform();
            platform->initialise(render_wnd,smgr);
            ui->initialise("MyGUI_Core.xml");
            std::cout<<"ui is "<<ui<<std::endl;

            loadGuiResources();

            //MyGUI::LayoutManager::getInstance().loadLayout("Themes.layout");
            MyGUI::Button *  button = ui->createWidget<MyGUI::Button>("Button",10,10,300,26,MyGUI::Align::Default,"Main");
            std::cout<<"button is "<<button<<std::endl;
            std::cout<<"setupScene finished"<<std::endl;

      }

      void run(){
            std::cout<<"start rendering "<<ogre_root<<std::endl;
            ogre_root->startRendering();
      }

    private:

        void loadGuiResources();
        input::InputManager * input_manager;
        Ogre::Root * ogre_root;
        Ogre::RenderWindow * render_wnd;






};






}
