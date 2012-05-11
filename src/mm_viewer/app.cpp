#include "app.h"
namespace mm_view{

    void App::loadGuiResources(){
            std::cout<<"loadGuiResources now"<<std::endl;
	    if(! MyGUI::ResourceManager::getInstance().load("EnglishTag.xml")){
		    std::cout<<"load EnglishTag.xml failed"<<std::endl;
	    }


            //MyGUI::ResourceManager::getInstance().load("MyGUI_BlueWhiteTheme.xml");
            std::cout<<"loadGuiResources finished"<<std::endl;
    }
    void App::onButtonClick(MyGUI::Widget * _sender){
	    std::cout<<"I click the button"<<std::endl;
    }



}
