/**
 * This is an example that shows a simple Hello World example
 * with Guichan. The example uses the HGE back end.
 */


#include <guichan.hpp>
#include <hge.h>
#include <iostream>

// Here we store a global Gui object.  We make it global
// so it's easily accessable. Of course, global variables
// should normally be avioded when it comes to OOP, but
// this examples it not an example that shows how to make a 
// good and clean C++ application but merely an example
// that shows how to use Guichan.
namespace globals
{
    gcn::Gui* gui;
}


// Include code to set up an HGE application with Guichan.
// The hge.hpp file is responsible for creating and deleting
// the global Gui object.
#include "hge.hpp"
// Include code to set up a Guichan GUI with a simple Hello
// World example. The code populates the global Gui object.
#include "helloworld.hpp"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        hge::init();
        helloworld::init();
        hge::run();
        helloworld::halt();
        hge::halt();
    }
    // Catch all Guichan exceptions.
    catch (gcn::Exception e)
    {
        MessageBoxA(NULL,  
                   e.getMessage().c_str(),
                   "Guichan exception",
                   MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);
        return 1;
    }
    // Catch all Std exceptions.
    catch (std::exception e)
    {
        MessageBoxA(NULL, 
                   e.what(),
                   "Std exception",
                   MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);
        return 1;
    }
    // Catch all unknown exceptions.
    catch (...)
    {
       MessageBoxA(NULL, 
                  hge::hge->System_GetErrorMessage(), 
                  "Unknown exception", 
                  MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);
        return 1;
    }

    return 0;
}

