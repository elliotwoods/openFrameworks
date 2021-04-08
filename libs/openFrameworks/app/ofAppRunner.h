#pragma once

#include "ofConstants.h"
#include "ofWindowSettings.h"
#include "ofMainLoop.h"
#include "ofRectangle.h"

class ofAppBaseWindow;
class ofAppBaseGLWindow;
class ofAppBaseGLESWindow;
class ofAppGLFWWindow;
class ofBaseApp;
class ofBaseRenderer;
class ofCoreEvents;


void OF_API_ENTRY ofInit();
void OF_API_ENTRY ofSetupOpenGL(int w, int h, ofWindowMode screenMode);	// sets up the opengl context!
std::shared_ptr<ofAppBaseWindow> OF_API_ENTRY ofCreateWindow(const ofWindowSettings & settings);	// sets up the opengl context!
std::shared_ptr<ofMainLoop> OF_API_ENTRY ofGetMainLoop();
void OF_API_ENTRY ofSetMainLoop(std::shared_ptr<ofMainLoop> mainLoop);

template<typename Window>
void ofSetupOpenGL(std::shared_ptr<Window> windowPtr, int w, int h, ofWindowMode screenMode){
	ofInit();
	ofWindowSettings settings;
	settings.setSize(w, h);
	settings.windowMode = screenMode;
	ofGetMainLoop()->addWindow(windowPtr);
	windowPtr->setup(settings);
}

//special case so we preserve supplied settngs
//TODO: remove me when we remove the ofSetupOpenGL legacy approach.
void OF_API_ENTRY ofSetupOpenGL(std::shared_ptr<ofAppGLFWWindow> windowPtr, int w, int h, ofWindowMode screenMode);

template<typename Window>
static void noopDeleter(Window*){}

template<typename Window>
void ofSetupOpenGL(Window * windowPtr, int w, int h, ofWindowMode screenMode){
	std::shared_ptr<Window> window = std::shared_ptr<Window>(windowPtr, std::function<void(Window *)>(noopDeleter<Window>));
	ofSetupOpenGL(window,w,h,screenMode);
}


int OF_API_ENTRY ofRunApp(std::shared_ptr<ofBaseApp> && OFSA);
int OF_API_ENTRY ofRunApp(ofBaseApp * OFSA = nullptr); // will be deprecated
void OF_API_ENTRY ofRunApp(std::shared_ptr<ofAppBaseWindow> window, std::shared_ptr<ofBaseApp> && app);
int OF_API_ENTRY ofRunMainLoop();


ofBaseApp * OF_API_ENTRY ofGetAppPtr();

void		OF_API_ENTRY ofExit(int status=0);

//-------------------------- time
float 		OF_API_ENTRY ofGetFrameRate();
float 		OF_API_ENTRY ofGetTargetFrameRate();
uint64_t	OF_API_ENTRY ofGetFrameNum();
void 		OF_API_ENTRY ofSetFrameRate(int targetRate);
double		OF_API_ENTRY ofGetLastFrameTime();
void		OF_API_ENTRY ofSetTimeModeSystem();
uint64_t	OF_API_ENTRY ofGetFixedStepForFps(double fps);
void		OF_API_ENTRY ofSetTimeModeFixedRate(uint64_t stepNanos = ofGetFixedStepForFps(60)); //default nanos for 1 frame at 60fps
void		OF_API_ENTRY ofSetTimeModeFiltered(float alpha = 0.9);

void		OF_API_ENTRY ofSetOrientation(ofOrientation orientation, bool vFlip=true);
ofOrientation OF_API_ENTRY ofGetOrientation();

//-------------------------- cursor
void 		OF_API_ENTRY ofHideCursor();
void 		OF_API_ENTRY ofShowCursor();
//-------------------------- window / screen
int 		OF_API_ENTRY ofGetWindowPositionX();
int 		OF_API_ENTRY ofGetWindowPositionY();
int 		OF_API_ENTRY ofGetScreenWidth();
int 		OF_API_ENTRY ofGetScreenHeight();
int			OF_API_ENTRY ofGetWindowMode();
int 		OF_API_ENTRY ofGetWidth();			// ofGetWidth is correct for orientation
int 		OF_API_ENTRY ofGetHeight();
int 		OF_API_ENTRY ofGetWindowWidth();			// ofGetWindowWidth is correct for actual window coordinates - so doesn't change with orientation.
int 		OF_API_ENTRY ofGetWindowHeight();

std::string OF_API_ENTRY ofGetClipboardString();
void		OF_API_ENTRY ofSetClipboardString(const std::string & str);

/// \returns a random number between 0 and the width of the window.
float OF_API_ENTRY ofRandomWidth();

/// \returns a random number between 0 and the height of the window.
float OF_API_ENTRY ofRandomHeight();
bool		OF_API_ENTRY ofDoesHWOrientation();
glm::vec2	OF_API_ENTRY ofGetWindowSize();
ofRectangle	OF_API_ENTRY ofGetWindowRect();
ofAppBaseWindow * OF_API_ENTRY ofGetWindowPtr();
std::shared_ptr<ofAppBaseWindow> OF_API_ENTRY ofGetCurrentWindow();

void 		OF_API_ENTRY ofSetWindowPosition(int x, int y);
void 		OF_API_ENTRY ofSetWindowShape(int width, int height);
void 		OF_API_ENTRY ofSetWindowTitle(std::string title);
void		OF_API_ENTRY ofEnableSetupScreen();
void		OF_API_ENTRY ofDisableSetupScreen();
void		OF_API_ENTRY ofSetFullscreen(bool fullscreen);
void		OF_API_ENTRY ofToggleFullscreen();
//-------------------------- sync
void 		OF_API_ENTRY ofSetVerticalSync(bool bSync);

ofCoreEvents & OF_API_ENTRY ofEvents();
void OF_API_ENTRY ofSetCurrentRenderer(std::shared_ptr<ofBaseRenderer> renderer,bool setDefaults=false);
std::shared_ptr<ofBaseRenderer> & OF_API_ENTRY ofGetCurrentRenderer();
void OF_API_ENTRY ofSetEscapeQuitsApp(bool bQuitOnEsc);

//-------------------------- native window handles
#if defined(TARGET_LINUX) && !defined(TARGET_RASPBERRY_PI_LEGACY)
typedef unsigned long Window;
struct _XDisplay;
typedef struct _XDisplay Display;
Display* ofGetX11Display();
Window  ofGetX11Window();
#endif

#if defined(TARGET_LINUX) && !defined(TARGET_OPENGLES)
struct __GLXcontextRec;
typedef __GLXcontextRec * GLXContext;
GLXContext ofGetGLXContext();
#endif

#if defined(TARGET_LINUX) && defined(TARGET_OPENGLES)
EGLDisplay ofGetEGLDisplay();
EGLContext ofGetEGLContext();
EGLSurface ofGetEGLSurface();
#endif

#if defined(TARGET_OSX)
	void * ofGetNSGLContext();
	void * ofGetCocoaWindow();
#endif

#if defined(TARGET_WIN32)
	HGLRC OF_API_ENTRY ofGetWGLContext();
	HWND OF_API_ENTRY ofGetWin32Window();
#endif
