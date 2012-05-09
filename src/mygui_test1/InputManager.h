/*!
	@file
	@author		revtime
	@date		2012-4
*/

#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__


#include <OIS.h>
#include <sstream>
#include <OgreRenderWindow.h>
#include <OgreFrameListener.h>
#include "MyGUI.h"
#include "MyGUI_OgrePlatform.h"

namespace input
{


    class InputManager : public OIS::MouseListener , public Ogre::FrameEvent
    {
        public:
        InputManager(Ogre::RenderWindow * rnd);
        ~InputManager();
        bool mouseMoved( const OIS::MouseEvent &arg );
        bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
        bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
        void update(int dt);

        private:
            OIS::InputManager * ois_manager ;
            OIS::Mouse * mouse;

    };






}


#endif
