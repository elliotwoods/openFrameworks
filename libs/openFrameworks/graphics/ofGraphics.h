#pragma once

#include "ofConstants.h"
#include "ofGraphicsBaseTypes.h"
#include "ofRectangle.h"
#include "glm/fwd.hpp"
//#include "ofUtils.h"

class ofVec3f;
class ofVec2f;

template<typename T>
class ofColor_;

typedef ofColor_<unsigned char> ofColor;
typedef ofColor_<float> ofFloatColor;
typedef ofColor_<unsigned short> ofShortColor;

template<typename T>
std::string ofToString(const T&);

/// \cond INTERNAL
#define  	CIRC_RESOLUTION		    22
/// \endcond

/// \name Color
/// \{

/// \brief Sets the draw color with r,g,b, 0-255. For example, red would
/// be: ofSetColor(255,0,0). This affects not only the color of shapes drawn
/// with ofDrawRectangle(), ofDrawCircle(), etc, but also the tint of images and
/// textures.
///
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofSetColor(0,0,255);    //set the color to blue
///     ofDrawRectangle(10,10,100,100);
/// }
/// ~~~~
void OF_API_ENTRY ofSetColor(int r, int g, int b);

/// \brief Sets the draw color with r,g,b,a 0-255.
///
/// For alpha (transparency), you must first enable transparent blending
/// (turned off by default for performance reasons) with
/// ofEnableAlphaBlending()
///
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofEnableAlphaBlending();    // turn on alpha blending
///     ofSetColor(255,0,0,127);    // red, 50% transparent
///     ofDrawRectangle(20,20,100,100);
///     ofDisableAlphaBlending();   // turn it back off, if you don't need it
/// }
/// ~~~~
void OF_API_ENTRY ofSetColor(int r, int g, int b, int a);
void OF_API_ENTRY ofSetColor(const ofColor & color);
void OF_API_ENTRY ofSetColor(const ofColor & color, int _a);
void OF_API_ENTRY ofSetColor(int gray);

/// Sets the draw color with r,g,b, passed in as a hex. Hex is a conventient
/// way to write colors.
///
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofSetColor(0xffffff);  // white  (255,255,255)
///     ofSetColor(0x000000);  // black  (0,0,0);
///     ofSetColor(0x00ff00);  // green  (0,255,0);
/// }
/// ~~~~
void OF_API_ENTRY ofSetHexColor( int hexColor );

/// \brief Draw shapes as outlines with the current draw color.
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofSetColor(0,0,255);
///     ofNoFill();
///     ofDrawRectangle(10,10,100,100);  //draws only the outline in blue
/// }
/// ~~~~
void OF_API_ENTRY ofNoFill();

/// \brief Draw shapes filled with the current draw color.
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofSetColor(0,0,255);
///     ofFill();
///     ofDrawRect(10,10,100,100);  //draws the rectangle filled in blue
/// }
/// ~~~~
void OF_API_ENTRY ofFill();
ofFillFlag OF_API_ENTRY ofGetFill();

/// \}
/// \name Background Color
/// \{

/// \brief Returns the current background color as an ofColor.
ofColor OF_API_ENTRY ofGetBackgroundColor();
OF_DEPRECATED_MSG("Use ofGetBackgroundColor instead",ofColor ofGetBackground());


/// \brief Sets the background color.
///
/// It takes as input r,g,b (0-255). The background is
/// cleared automatically, just before the draw() command, so if the background
/// color is not changing, you could call this inside of setup() (once, at the
/// start of the application). If the background color is changing, you can call
/// this inside of update().
///
/// ~~~~{.cpp}
/// void ofApp::setup(){
///     ofBackground(255,0,0);  // Sets the background color to red
/// }
/// ~~~~
void OF_API_ENTRY ofBackground(int r, int g, int b, int a=255);
void OF_API_ENTRY ofBackground(int brightness, int alpha = 255);
void OF_API_ENTRY ofBackground(const ofColor & c);

/// \brief Sets the background color using a hex color value.
/// ~~~~{.cpp}
/// void ofApp::setup(){
///     ofBackgroundHex(0xff0000);  // Sets the background color to red
/// }
/// ~~~~
void OF_API_ENTRY ofBackgroundHex(int hexColor, int alpha = 255);


/// \brief Sets the background color to a gradient.
///
/// It takes as input 2 ofColor() objects and a Gradient Mode.
/// Must be called in the draw() function.
///
/// Accepted modes are:
///
/// - Circular: `OF_GRADIENT_CIRCULAR`
/// - Linear: `OF_GRADIENT_LINEAR`
/// - Bar: `OF_GRADIENT_BAR`
///
/// **Background Gradient: Circular:**
/// ![Background Gradient Circular](bkgGradient_circular.png)
/// ~~~~{.cpp}
/// void ofApp::draw(){
///
///     ofColor colorOne(255, 0, 0);
///     ofColor colorTwo(0, 0, 0);
///
///     ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
///     // Sets the background to a circular gradient
/// }
/// ~~~~
///
/// **Background Gradient: Linear:**
/// ![Background Gradient Linear](bkgGradient_linear.png)
/// ~~~~{.cpp}
/// void ofApp::draw(){
///
///     ofColor colorOne(255, 0, 0);
///     ofColor colorTwo(0, 0, 0);
///
///     ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);
///       // Sets the background to a linear gradient
/// }
/// ~~~~
///
/// **Background Gradient: Bar:**
/// ![Background Gradient Bar](bkgGradient_bar.png)
/// ~~~~{.cpp}
/// void ofApp::draw(){
///
///     ofColor colorOne(255, 0, 0);
///     ofColor colorTwo(0, 0, 0);
///
///     ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_BAR);
///       // Sets the background to a bar gradient
/// }
/// ~~~~
void OF_API_ENTRY ofBackgroundGradient(const ofColor& start, const ofColor& end, ofGradientMode mode = OF_GRADIENT_CIRCULAR);

/// \brief Sets the background color. It takes as input r,g,b (0-255). The
/// background is cleared automatically, just before the draw() command, so
/// if the background color is not changing, you could call this inside
/// setup() (once, at the start of the application). If the background color
/// is changing, you can call this inside update().
///
/// ~~~~{.cpp}
/// void ofApp::setup(){
///     ofSetBackgroundColor(255,0,0);  // Sets the background color to red
/// }
/// ~~~~
void OF_API_ENTRY ofSetBackgroundColor(int r, int g, int b, int a=255);
void OF_API_ENTRY ofSetBackgroundColor(int brightness, int alpha = 255);
void OF_API_ENTRY ofSetBackgroundColor(const ofColor & c);

/// \brief Sets the background color using a hex color value.
/// ~~~~{.cpp}
/// void ofApp::setup(){
///     ofSetBackgroundColorHex(0xff0000);  // Sets the background color to red
/// }
/// ~~~~
void OF_API_ENTRY ofSetBackgroundColorHex(int hexColor, int alpha = 255);

/// \brief Sets the background clearing function to be auto (default) or not. If non-
/// auto, then background clearing will not occur per frame (at the start of
/// draw) but rather, whenever ofBackground is called.
///
/// ~~~~{.cpp}
/// void ofApp::setup(){
///     ofSetBackgroundAuto(false); //disable automatic background redraw
/// }
/// void ofApp::draw(){
///     if(ofGetFrameNum() % 10 == 0){
///         // draws a black background every 10 frames
///         ofSetBackgroundColor(0,0,0);
///     }
/// }
/// ~~~~
void OF_API_ENTRY ofSetBackgroundAuto(bool bManual);		// default is true
bool OF_API_ENTRY ofGetBackgroundAuto();

/// \brief Clears the color and depth bits of current renderer and replaces it with
/// an RGB color.
///
/// When drawing to the screen, ofClear() will clear the screen entirely.
///
/// ~~~~{.cpp}
/// void ofApp::draw() {
///     ofClear(255, 0, 0);
///     // Clears current screen and replaces it with red.
///     // Screen will render as a flat color.
/// }
/// ~~~~
///
/// When using the openGL renderer and drawing into an
/// [FBO][1], ofClear() will clear that buffer rather than the main
/// screen.
///
/// ~~~~{.cpp}
/// void ofApp::draw() {
///     ofFbo myFbo;
///     myFbo.allocate(300, 300);
///
///     myFbo.begin();
///         ofClear(255, 0, 0);
///         // Clears FBO buffer and replaces it with red.
///         // No effect in current drawing screen.
///     myFbo.end();
/// }
/// ~~~~
///
/// ofClear() is based on [glClear][2].
///
/// [1]: http://www.openframeworks.cc/documentation/gl/ofFbo.html
/// [2]: http://www.opengl.org/sdk/docs/man/xhtml/glClear.xml
void OF_API_ENTRY ofClear(float r, float g, float b, float a=0);

/// \brief Clears the color and depth bits of current renderer and replaces it with a
/// grayscale value.
///
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofClear(128);
///     // Clears current screen and replaces it with a grayscale value.
/// }
/// ~~~~
void OF_API_ENTRY ofClear(float brightness, float a=0);

/// \brief Clears the color and depth bits of current renderer and replaces it with
/// an ofColor.
///
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofColor myColor(0, 0, 255);
///     ofClear(myColor);
///     // Clears current screen and replaces it with myColor.
/// }
/// ~~~~

void OF_API_ENTRY ofClear(const ofColor & c);
void OF_API_ENTRY ofClearAlpha();

// OF's access to settings (bgAuto, origin, corner mode):
OF_DEPRECATED_MSG("Use ofGetBackgroundAuto instead",bool ofbClearBg());

/// \}
/// \name 2D Primitives Drawing
/// \{

/// \brief Draws a triangle, with the three points: (x1,y1),(x2, y2),(x3, y3).
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofDrawTriangle(50,10,10,40,90,40);
/// }
/// ~~~~
void OF_API_ENTRY ofDrawTriangle(float x1,float y1,float x2,float y2,float x3, float y3);
void OF_API_ENTRY ofDrawTriangle(float x1,float y1,float z1,float x2,float y2,float z2,float x3, float y3,float z3);
void OF_API_ENTRY ofDrawTriangle(const glm::vec3 & p1, const glm::vec3 & p2, const glm::vec3 & p3);
void OF_API_ENTRY ofDrawTriangle(const glm::vec2 & p1, const glm::vec2 & p2, const glm::vec2 & p3);

/// \brief Draws a circle, centered at x,y, with a given radius.
///
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofDrawCircle(150,150,100);
/// }
/// ~~~~
/// Please keep in mind that drawing circle with different outline color and
/// fill requires calling ofNoFill and ofSetColor for drawing stroke and
/// ofFill and again ofSetColor for filled solid color circle.
///
void OF_API_ENTRY ofDrawCircle(float x, float y, float radius);
void OF_API_ENTRY ofDrawCircle(float x, float y, float z, float radius);
void OF_API_ENTRY ofDrawCircle(const glm::vec3 & p, float radius);
void OF_API_ENTRY ofDrawCircle(const glm::vec2 & p, float radius);

/// \brief Draws an ellipse from point (x,y) with a given width (w) and height (h).
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofDrawEllipse(10,10,50,30);
/// }
/// ~~~~
void OF_API_ENTRY ofDrawEllipse(float x, float y, float width, float height);
void OF_API_ENTRY ofDrawEllipse(float x, float y, float z, float width, float height);
void OF_API_ENTRY ofDrawEllipse(const glm::vec3 & p, float width, float height);
void OF_API_ENTRY ofDrawEllipse(const glm::vec2 & p, float width, float height);

/// Draws a line between two points: (x1,y1),(x2,y2).
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofDrawLine(10,10,100,100);
/// }
/// ~~~~
void OF_API_ENTRY ofDrawLine(float x1,float y1,float x2,float y2);
void OF_API_ENTRY ofDrawLine(float x1,float y1,float z1,float x2,float y2,float z2);
void OF_API_ENTRY ofDrawLine(const glm::vec3 & p1, const glm::vec3 & p2);
void OF_API_ENTRY ofDrawLine(const glm::vec2 & p1, const glm::vec2 & p2);

/// \brief Draws a rectangle from point x,y with a given width and height.
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofDrawRect(10,10,100,100);
/// }
/// ~~~~
void OF_API_ENTRY ofDrawRectangle(float x1,float y1,float w,float h);


/// \brief Draws an rectangle from the given rectangle.
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofRectangle rect;
///     rect.x = 10;
///     rect.y = 10;
///     rect.width = 100;
///     rect.height = 100;
///
///     ofDrawRectangle(rect);
/// }
/// ~~~~
void OF_API_ENTRY ofDrawRectangle(const ofRectangle & r);


/// \brief Draws an rectangle from point p, with a given width and height.
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     glm::vec3 p;      // create a point P
///     p.x = 10;       // set the x of the point
///     p.y = 10;       // set the y of the point
///
///     ofDrawRectangle(p, 80, 80); // Draw the rectangle
/// }
/// ~~~~
void OF_API_ENTRY ofDrawRectangle(const glm::vec3 & p,float w,float h);
void OF_API_ENTRY ofDrawRectangle(const glm::vec2 & p,float w,float h);


/// Draws an rectangle from point X, Y at depth Z with a given width and height.
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofDrawRectangle(10,10,-100, 80, 80); // Draw a rectangle at 100 pixels in depth
/// }
/// ~~~~
void OF_API_ENTRY ofDrawRectangle(float x,float y,float z,float w,float h);

/// \brief Draws a rounded rectangle from the given rectangle using given
/// radius.
///
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofRectangle myRect;
///     myRect.x = 10;
///     myRect.y = 10;
///     myRect.width = 100;
///     myRect.height = 100;
///
///     ofDrawRectRounded(myRect, 10);
/// }
/// ~~~~
void OF_API_ENTRY ofDrawRectRounded(const ofRectangle & b, float r);

/// \brief Draws a rectangle from point p with a given width, height and radius of
/// rounded corners.
///
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofPoint p;
///     p.set ( 10, 10 );
///     ofDrawRectRounded( p, 100, 100, 10 );
/// }
/// ~~~~
void OF_API_ENTRY ofDrawRectRounded(const glm::vec3 & p, float w, float h, float r);
void OF_API_ENTRY ofDrawRectRounded(const glm::vec2 & p, float w, float h, float r);


/// \brief Draws a rectangle from point X, Y with a given width, height and radius of
/// rounded corners.
///
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofDrawRectRounded(10, 10, 100, 100, 10);
/// }
/// ~~~~
void OF_API_ENTRY ofDrawRectRounded(float x, float y, float w, float h, float r);


/// \brief Draws a rectangle from point X, Y, at depth Z with a given width, height and
/// radius of rounded corners.
///
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofDrawRectRounded(10, 10, 10, 100, 100, 10);
/// }
/// ~~~~
void OF_API_ENTRY ofDrawRectRounded(float x, float y, float z, float w, float h, float r);


/// \brief Draws a rounded rectangle from point X, Y, at depth Z with a given width,
/// height and radius of rounded corners.
///
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofDrawRectRounded(10, 10, 10, 100, 100, 10);
/// }
/// ~~~~
void OF_API_ENTRY ofDrawRectRounded(const glm::vec3 & p, float w, float h, float topLeftRadius,
					   float topRightRadius,
					   float bottomRightRadius,
					   float bottomLeftRadius);
void OF_API_ENTRY ofDrawRectRounded(const glm::vec2 & p, float w, float h, float topLeftRadius,
					   float topRightRadius,
					   float bottomRightRadius,
					   float bottomLeftRadius);


/// \brief Draws a rounded rectangle from the given rectangle using different given
/// radius for each of the corners.
///
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofRectangle myRect;
///     myRect.x = 10;
///     myRect.y = 10;
///     myRect.width = 100;
///     myRect.height = 100;
///
///     ofDrawRectRounded( myRect, 10, 20, 30, 40 );
/// }
/// ~~~~
void OF_API_ENTRY ofDrawRectRounded(const ofRectangle & b, float topLeftRadius,
					   float topRightRadius,
					   float bottomRightRadius,
					   float bottomLeftRadius);

/// \brief Draws a rounded rectangle from point X, Y, at depth Z with a given width,
/// height and different radius for each rounded corner.
///
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofDrawRectRounded(10, 10, 10, 100, 100, 10, 20, 30, 40);
/// }
/// ~~~~
void OF_API_ENTRY ofDrawRectRounded(float x, float y, float z, float w, float h, float topLeftRadius,
					   float topRightRadius,
					   float bottomRightRadius,
					   float bottomLeftRadius);

/// \brief Draws a curve from point (x1, y1) to point (x2, y2). The curve is shaped by
/// the two control points (x0,y0) and (x3,y3).
void OF_API_ENTRY ofDrawCurve(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3);

/// \brief Draws a 3-dimensional curve from point (x1, y1, z1) to point (x2, y2, z2).
/// The curve is shaped by the two control points (x0, y0, z0) and (x3, y3, z3).
void OF_API_ENTRY ofDrawCurve(float x0, float y0, float z0, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
void OF_API_ENTRY ofDrawBezier(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3);
void OF_API_ENTRY ofDrawBezier(float x0, float y0, float z0, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);

OF_DEPRECATED_MSG("Use ofDrawTriangle instead",void ofTriangle(float x1,float y1,float x2,float y2,float x3, float y3));
OF_DEPRECATED_MSG("Use ofDrawTriangle instead",void ofTriangle(float x1,float y1,float z1,float x2,float y2,float z2,float x3, float y3,float z3));
OF_DEPRECATED_MSG("Use ofDrawTriangle instead",void ofTriangle(const glm::vec3 & p1, const glm::vec3 & p2, const glm::vec3 & p3));

OF_DEPRECATED_MSG("Use ofDrawCircle instead",void ofCircle(float x, float y, float radius));
OF_DEPRECATED_MSG("Use ofDrawCircle instead",void ofCircle(float x, float y, float z, float radius));
OF_DEPRECATED_MSG("Use ofDrawCircle instead",void ofCircle(const glm::vec3 & p, float radius));

OF_DEPRECATED_MSG("Use ofDrawEllipse instead",void ofEllipse(float x, float y, float width, float height));
OF_DEPRECATED_MSG("Use ofDrawEllipse instead",void ofEllipse(float x, float y, float z, float width, float height));
OF_DEPRECATED_MSG("Use ofDrawEllipse instead",void ofEllipse(const glm::vec3 & p, float width, float height));

OF_DEPRECATED_MSG("Use ofDrawLine instead",void ofLine(float x1,float y1,float x2,float y2));
OF_DEPRECATED_MSG("Use ofDrawLine instead",void ofLine(float x1,float y1,float z1,float x2,float y2,float z2));
OF_DEPRECATED_MSG("Use ofDrawLine instead",void ofLine(const glm::vec3 & p1, const glm::vec3 & p2));

OF_DEPRECATED_MSG("Use ofDrawRectangle instead",void ofRect(float x1,float y1,float w,float h));
OF_DEPRECATED_MSG("Use ofDrawRectangle instead",void ofRect(const ofRectangle & r));
OF_DEPRECATED_MSG("Use ofDrawRectangle instead",void ofRect(const glm::vec3 & p,float w,float h));
OF_DEPRECATED_MSG("Use ofDrawRectangle instead",void ofRect(float x,float y,float z,float w,float h));

OF_DEPRECATED_MSG("Use ofDrawRectRounded instead",void ofRectRounded(const ofRectangle & b, float r));
OF_DEPRECATED_MSG("Use ofDrawRectRounded instead",void ofRectRounded(const glm::vec3 & p, float w, float h, float r));
OF_DEPRECATED_MSG("Use ofDrawRectRounded instead",void ofRectRounded(float x, float y, float w, float h, float r));
OF_DEPRECATED_MSG("Use ofDrawRectRounded instead",void ofRectRounded(float x, float y, float z, float w, float h, float r));

//----------------------------------------------------------
OF_DEPRECATED_MSG("Use ofDrawRectRounded instead",void ofRectRounded(const glm::vec3 & p, float w, float h, float topLeftRadius,
																	 float topRightRadius,
																	 float bottomRightRadius,
																	 float bottomLeftRadius));

OF_DEPRECATED_MSG("Use ofDrawRectRounded instead",void ofRectRounded(const ofRectangle & b, float topLeftRadius,
																	 float topRightRadius,
																	 float bottomRightRadius,
																	 float bottomLeftRadius));

OF_DEPRECATED_MSG("Use ofDrawRectRounded instead",void ofRectRounded(float x, float y, float z, float w, float h, float topLeftRadius,
																	 float topRightRadius,
																	 float bottomRightRadius,
																	 float bottomLeftRadius));

OF_DEPRECATED_MSG("Use ofDrawCurve instead",void ofCurve(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3));
OF_DEPRECATED_MSG("Use ofDrawCurve instead",void ofCurve(float x0, float y0, float z0, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3));
OF_DEPRECATED_MSG("Use ofDrawBezier instead",void ofBezier(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3));
OF_DEPRECATED_MSG("Use ofDrawBezier instead",void ofBezier(float x0, float y0, float z0, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3));


/// \}
/// \name Custom Shapes Drawing
/// \{

/// \brief Start drawing a new shape. Needs to be followed by a list of
/// vertex points and lastly a call to ofEndShape().
///
/// ~~~~{.cpp}
/// //draws a star
/// ofSetPolyMode(OF_POLY_WINDING_NONZERO);
/// ofBeginShape();
///   ofVertex(400,135);
///   ofVertex(215,135);
///   ofVertex(365,25);
///   ofVertex(305,200);
///   ofVertex(250,25);
/// ofEndShape();
/// ~~~~
///
/// \sa ofEndShape()
void OF_API_ENTRY ofBeginShape();

/// \brief Specifies a single point of a shape. To be called between ofBeginShape() and
/// ofEndShape().
void OF_API_ENTRY ofVertex(float x, float y);
void OF_API_ENTRY ofVertex(float x, float y, float z);
void OF_API_ENTRY ofVertex(const glm::vec3 & p);
void OF_API_ENTRY ofVertex(const glm::vec2 & p);
void OF_API_ENTRY ofVertices(const std::vector <glm::vec3> & polyPoints);
void OF_API_ENTRY ofVertices(const std::vector <glm::vec2> & polyPoints);
void OF_API_ENTRY ofVertices(const std::vector <ofVec3f> & polyPoints);
void OF_API_ENTRY ofVertices(const std::vector <ofVec2f> & polyPoints);

/// \brief Specifies a single point of a shape. The difference from ofVertex is that
/// the line describing the edge of the shape between two points will be a
/// curve as opposed to a straight line. The curve is automatically generated
/// using the catmull from formula.
///
/// This function has to be called between ofBeginShape() and ofEndShape().
void OF_API_ENTRY ofCurveVertex(float x, float y);
void OF_API_ENTRY ofCurveVertex(float x, float y, float z);
void OF_API_ENTRY ofCurveVertex(const glm::vec3 & p);
void OF_API_ENTRY ofCurveVertex(const glm::vec2 & p);

/// \brief Draws a curve through a series of vertices stored as a vector of
/// ofPoints. Should be called between ofBeginShape() and ofEndShape().
void OF_API_ENTRY ofCurveVertices(const std::vector <glm::vec3> & curvePoints);
void OF_API_ENTRY ofCurveVertices(const std::vector <glm::vec2> & curvePoints);
void OF_API_ENTRY ofCurveVertices(const std::vector <ofVec3f> & curvePoints);
void OF_API_ENTRY ofCurveVertices(const std::vector <ofVec2f> & curvePoints);

/// \brief Describes a bezier curve through three points of a shape. To be called
/// between ofBeginShape() and ofEndShape().
void OF_API_ENTRY ofBezierVertex(float x1, float y1, float x2, float y2, float x3, float y3);
void OF_API_ENTRY ofBezierVertex(const glm::vec3 & p1, const glm::vec3 & p2, const glm::vec3 & p3);
void OF_API_ENTRY ofBezierVertex(const glm::vec2 & p1, const glm::vec2 & p2, const glm::vec2 & p3);
void OF_API_ENTRY ofBezierVertex(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);


enum ofCloseShape{
	OF_OPEN = 0,
	OF_CLOSE = 1,
};

/// \brief This tells the program that your shape is finished and that it should now
/// draw it to the screen.
///
/// This function must be called otherwise you will not see your shape.
///
/// \param bClose If you set it to true it will automatically close your
/// shape for you. Default false.
void OF_API_ENTRY ofEndShape(bool bClose = false);

/// \brief Allows you to draw multiple contours within one shape. Call this
/// between ofBeginShape() and ofEndShape() to create a new contour for your
/// shape.
///
/// \param bClose If set to true then the previous contour will be
/// automatically closed. Default false
void OF_API_ENTRY ofNextContour(bool bClose = false);  // for multi contour shapes!


/// \}
/// \name Text Drawing
/// \{


/// \brief Set the bitmap drawing mode
///
/// Valid modes:
///
/// OF_BITMAPMODE_SCREEN: this is the default mode. It projects the 3d prosition onto
/// the screen so the letters always look the same size but can be positioned in any 3d coordinate.
///
/// OF_BITMAPMODE_VIEWPORT: does the same as screen but uses the current viewport instead
/// of the full window if it's different.
///
/// OF_BITMAPMODE_MODEL: uses real 3d coordinates so the text will look scaled if it's not in z=0
///
/// OF_BITMAPMODE_MODEL_BILLBOARD: uses real 3d coordinates but the text always faces the camera.
///
/// OF_BITMAPMODE_SIMPLE: only does 2d and the z coordinate is just disacarded, so if z is not 0
/// the position in which it'll be drawn will be wrong.
///
void OF_API_ENTRY ofSetDrawBitmapMode(ofDrawBitmapMode mode);

/// \brief Draws a bitmapped string, on screen, at point (x,y).
///
/// For example, you can write some text on screen like this:
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofDrawBitmapString("hi!!", 100,100);
/// }
/// ~~~~
///
/// Your strings can even be multiline:
/// ~~~~{.cpp}
/// ofDrawBitmapString("a test
/// of multiline
/// text", 100,100);
/// ~~~~
///
/// you can also using dynamically generated strings. For example, to print
/// the frame rate:
/// ~~~~{.cpp}
/// string fpsStr = "frame rate: "+ofToString(ofGetFrameRate(), 2);
/// ofDrawBitmapString(fpsStr, 100,100);
/// ~~~~
///
/// \note ofDrawBitmapString wraps a glut function that uses glDrawPixels. On
/// some graphics cards, you may discover that glDrawPixels is slow (or even,
/// very slow). If so, you might want to investigate using ofTrueTypeFont
/// with a small typeface, non-anti-aliased, as a suitable alternative.
///
/// \sa ofTrueTypeFont
template<typename T>
void ofDrawBitmapString(const T & textString, float x, float y);
template<typename T>
void ofDrawBitmapString(const T & textString, const glm::vec3 & p);
template<typename T>
void ofDrawBitmapString(const T & textString, const glm::vec2 & p);
template<typename T>
void ofDrawBitmapString(const T & textString, float x, float y, float z);
template<>
void OF_API_ENTRY ofDrawBitmapString(const std::string & textString, const glm::vec3 & p);
template<>
void OF_API_ENTRY ofDrawBitmapString(const std::string & textString, const glm::vec2 & p);
template<>
void OF_API_ENTRY ofDrawBitmapString(const std::string & textString, float x, float y, float z);
void OF_API_ENTRY ofDrawBitmapStringHighlight(std::string text, const glm::vec3& position, const ofColor& background = ofColor::black, const ofColor& foreground = ofColor::white);
void OF_API_ENTRY ofDrawBitmapStringHighlight(std::string text, const glm::vec2& position, const ofColor& background = ofColor::black, const ofColor& foreground = ofColor::white);
void OF_API_ENTRY ofDrawBitmapStringHighlight(std::string text, int x, int y, const ofColor& background = ofColor::black, const ofColor& foreground = ofColor::white);


/// \}
/// \name Rendering Settings
/// \{

/// \brief Resets openGL screen coordinates and values back to OF defaults.
void OF_API_ENTRY ofSetupGraphicDefaults();

void OF_API_ENTRY ofSetupScreen();

/// \brief Tells you if rectangle drawing mode is set to drawn from the center or drawn
/// from the top left corner, as set with the ofSetRectMode() function.
///
/// Default is `OF_RECTMODE_CORNER`
///
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     if(ofGetRectMode() == OF_RECTMODE_CORNER){
///         ofDrawRectangle(10,10,80,80);
///     }
///     else {
///         ofDrawRectangle(50,50,80,80);
///     }
/// }
/// ~~~~
/// \sa ofSetRectMode()
ofRectMode OF_API_ENTRY ofGetRectMode();

/// \brief Sets the resolution for the ofDrawCircle command. By default, the circle is 22
/// points, but if you need to draw larger circles, you can adjust the
/// resolution using this command. All circles are cached in openGL using a
/// display list for optimization purposes.
///
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofSetCircleResolution(10);
///     ofDrawCircle(150,150,100);          //draws a rough circle
///     ofSetCircleResolution(100);
///     ofDrawCircle(450,150,100);          //draws a fine circle
/// }
/// ~~~~
void OF_API_ENTRY ofSetCircleResolution(int res);      // if there 22 is a problem, you can change it here
void OF_API_ENTRY ofSetCurveResolution(int res);


/// \brief Sets the width of the ofDrawLine() called after.
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofSetLineWidth(1);          // set line width to 1
///     ofDrawLine(10,10,100,100);  // draw thin line
///     ofSetLineWidth(10);         // set line width to 10
///     ofDrawLine(10,100,100,10);  // draw fat line
/// }
/// ~~~~
void OF_API_ENTRY ofSetLineWidth(float lineWidth);

/// \brief Set depth testing on or off to either sort by z-depth (`true`)
/// or draw order (`false`).
void OF_API_ENTRY ofSetDepthTest(bool depthTest);


/// \brief Turns on depth testing so rendering happens according to z-depth rather
/// than draw order.
///
/// \sa ofDisableDepthTest()
void OF_API_ENTRY ofEnableDepthTest();

/// \brief Turn off depth testing so rendering happens in draw order rather than by
/// z-depth.
///
/// Turning off depth test is useful for combining 3d scenes with 2d
/// overlays such as a control panel.
///
/// ~~~~{.cpp}
/// void ofApp::draw(){
///
///     ofPushMatrix();
///
///         ofTranslate( ofGetWidth()/2, ofGetHeight()/2, 0 );
///
///         ofEnableDepthTest();
///         ofSetColor(255);
///         ofDrawSphere(0,0,100,60);
///         ofSetColor(255,0,255);
///         ofDrawSphere(50,0,50,100);
///         ofDisableDepthTest();
///
///         ofSetColor(0);
///         ofDrawRectangle(75,75,120,30);
///         ofSetColor(255);
///         ofDrawBitmapString("Some bubbles.",85,90);
///
///     ofPopMatrix();
/// }
/// ~~~~
///
/// \sa ofEnableDepthTest()
void OF_API_ENTRY ofDisableDepthTest();

/// \brief Sets and enables the blend mode for drawing. The options are:
///
///     OF_BLENDMODE_DISABLED
///     OF_BLENDMODE_ALPHA
///     OF_BLENDMODE_ADD
///     OF_BLENDMODE_SUBTRACT
///     OF_BLENDMODE_MULTIPLY
///     OF_BLENDMODE_SCREEN
///
/// There is a blendingExample in the openFrameworks examples > graphics
void OF_API_ENTRY ofEnableBlendMode(ofBlendMode blendMode);

/// \brief Disable the current blend mode.
void OF_API_ENTRY ofDisableBlendMode();

/// \brief Turn on point sprite.
///
/// Textures can be mapped onto points. By default, point size is 1pt. So
/// texture is not shown correctly. You can change point size by
/// `glPointSize(GLfloat size).
void OF_API_ENTRY ofEnablePointSprites();

/// \brief Turn off point sprites
void OF_API_ENTRY ofDisablePointSprites();

/// \brief Turns on alpha blending (which is on by default since OF version 0.8.0).
/// It simply wraps opengl commands that enable blending, and turn on a common
/// blend mode.
///
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofEnableAlphaBlending();    // turn on alpha blending
///     ofSetColor(255,0,0,127);    // red, 50% transparent
///     ofDrawRectangle(20,20,100,100);      // draws the rect with alpha
///     ofDisableAlphaBlending();   // turn off alpha
///     ofDrawRectangle(120,20,100,100);     // draws the rect without alpha
/// }
/// ~~~~
void OF_API_ENTRY ofEnableAlphaBlending();  // this just turns on and off opengl blending, the common mode

/// \brief Turn off alpha blending.
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofEnableAlphaBlending();    // turn on alpha blending
///     ofSetColor(255,0,0,127);    // red, 50% transparent
///     ofDrawRectangle(20,20,100,100);      // draws the rect with alpha
///     ofDisableAlphaBlending();   // turn off alpha
///     ofDrawRectangle(120,20,100,100); // draws the rect without alpha
/// }
/// ~~~~
///
/// \sa ofEnableAlphaBlending()
void OF_API_ENTRY ofDisableAlphaBlending();

void OF_API_ENTRY ofEnableSmoothing();

/// \brief Turn off smoothing. Currently, this only works for lines. You can draw a
/// filled object, and then draw the outline with smoothing enabled to get
/// smoothing effects on filled shapes.
void OF_API_ENTRY ofDisableSmoothing();

/// Enables anti-aliasing (smoothing) for lines.
void OF_API_ENTRY ofEnableAntiAliasing();

/// \brief Turns off anti-aliasing (smoothing).
void OF_API_ENTRY ofDisableAntiAliasing();

// drawing style - combines color, fill, blending and smoothing
ofStyle OF_API_ENTRY ofGetStyle();

/// \brief Set the current style of the ofGraphics.
/// \param style contains information of the graphics style such as
/// ofColor, ofFill, polyMode and others.
///
/// \sa See ofStyle for more details.
void OF_API_ENTRY ofSetStyle(ofStyle style);

/// \brief Saves the current style settings for the ofGraphics after its call.
/// Usage of ofPushStyle and ofPopStyle allow users to have more control of
/// certain graphics elements. All the style that applies to certain elements
/// is controled using ofStyle class. See ofStyle type.
///
/// In the following example the properties of being red and filled only applies to the ellipse:
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofPushStyle();  // push the current style for use later
///     ofFill();
///     ofSetColor(255,0,0);
///     ofDrawEllipse(30,10,40,40);
///     ofPopStyle();   // recall the pushed style
///
///     ofDrawCircle(10,10,5);
/// }
/// ~~~~
/// sa ofPopStyle()
void OF_API_ENTRY ofPushStyle();

/// \brief Restores the prior style settings. It needs to be called after ofPushStyle.
///
/// \sa ofPushStyle()
void OF_API_ENTRY ofPopStyle();

/// \brief Sets the drawing behavior for overlapping parts of the same polygon.
///
/// Possible modes are:
///
///     OF_POLY_WINDING_ODD
///     OF_POLY_WINDING_NONZERO
///     OF_POLY_WINDING_POSITIVE
///     OF_POLY_WINDING_NEGATIVE
///     OF_POLY_WINDING_ABS_GEQ_TWO
void OF_API_ENTRY ofSetPolyMode(ofPolyWindingMode mode);

/// \brief Sets the mode for drawing rectangles and other rectangular objects, if
/// they are corner aligned, or drawn so that the x,y position is the center
/// of the rectangle. possible options are `OF_RECTMODE_CENTER` and
/// `OF_RECTMODE_CORNER`. This affects not only how ofDrawRectangle() objects are drawn,
/// but also ofTexture (and therefore ofImage) objects.
///
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofSetRectMode(OF_RECTMODE_CORNER); //set rectangle mode to the corner
///     ofDrawRectangle(10,10,80,80);
///     ofSetRectMode(OF_RECTMODE_CENTER); //set rectangle mode to the center
///     ofDrawRectangle(50,50,80,80);
///     // both rectangles are drawn at the same place
/// }
/// ~~~~
void OF_API_ENTRY ofSetRectMode(ofRectMode mode);

/// \}
/// \name Transformation
/// \{

/// \brief Saves the current coordinate system allowing users to develop specific
/// movements in some graphic objects. ofPopMatrix needs to be called after.
///
/// In the following example we only rotate the square.
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofPushMatrix();         // push the current coordinate position
///     ofRotateX(90);          // change the coordinate system
///     ofDrawRectangle(10,10,40,40);  // draw a rect
///     ofPopMatrix()           // recall the pushed coordinate position
///     ofDrawCircle(10, 10, 5);    // draw a circle
/// }
/// ~~~~
void OF_API_ENTRY ofPushMatrix();

/// \brief Restores the prior coordinate system.
///
/// \sa ofPushMatrix()
void OF_API_ENTRY ofPopMatrix();

/// \brief Query the current (oF internal) Transformation Matrix state.
glm::mat4 OF_API_ENTRY ofGetCurrentMatrix(ofMatrixMode matrixMode);

/// \brief Query the current (oF internal) Orientation Matrix state.
/// \note  The matrix returned is the matrix openFrameworks uses internally
///        to calculate the (final, oriented) projection matrix as it is
///        passed on to the GPU.
///
///        Currently, only GL Programmable Renderer and GL Renderer
///        implement ofGetCurrentOrientationMatrix.
glm::mat4 OF_API_ENTRY ofGetCurrentOrientationMatrix();

/// \brief Query the current (oF internal) Normal Matrix state.
/// \note  The matrix returned is the transposed of the inverse of the
///        view matrix
///
///        Currently, only GL Programmable Renderer and GL Renderer
///        implement ofGetCurrentNormalMatrix.
glm::mat4 OF_API_ENTRY ofGetCurrentNormalMatrix();

/// \brief Translate by (x,y,z) vector of our coordinate system.
/// The call of ofTranslate() modifies graphics positions.
///
/// Use ofPushMatrix() and ofPopMatrix() to save and restore the untranslated
/// coordinate system.
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofTranslate(100, 100, 0);   // move the coordinate system to position x 100 and y 100 and make that zero.
///     ofDrawRectangle(0, 0, 10, 10);       // draw a rect at that position
/// }
/// ~~~~
void OF_API_ENTRY ofTranslate(float x, float y, float z = 0);

void OF_API_ENTRY ofTranslate(const glm::vec3 & p);
void OF_API_ENTRY ofTranslate(const glm::vec2 & p);

void OF_API_ENTRY ofScale(float xAmnt, float yAmnt, float zAmnt = 1);

/// \brief Scale along the X, Y and Z axis with the same amount.
void OF_API_ENTRY ofScale(float amount);

void OF_API_ENTRY ofScale(const glm::vec3 & p);

/// \brief Produces a rotation around the vector (vecX,vecY,vecZ).
///
/// All graphics drawn after ofRotate is called are rotated. Use ofPushMatrix()
/// and ofPopMatrix() to save and restore the unrotated coordinate system.
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofRotate(50, 1, 0.5, 0); //rotates the coordinate system 50 degrees along the x-axis and 25 degrees on the y-axis
///     ofDrawRectangle(20,20,100,100);
/// }
/// ~~~~
///
/// \param degrees Specifies the angle of rotation, in degrees.
/// \param vecX specifies the x coordinates of a vector
/// \param vecY specifies the y coordinates of a vector
/// \param vecZ specifies the z coordinates of a vector
OF_DEPRECATED_MSG("Use ofRotateDeg or ofRotateRad", void ofRotate(float degrees, float vecX, float vecY, float vecZ));

/// \brief Rotate around the z-axis
OF_DEPRECATED_MSG("Use ofRotateDeg or ofRotateRad", void ofRotate(float degrees));

/// \brief Produces a rotation around the X-axis of our coordinate
/// system represented by the vector (1,0,0).
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofRotateX(45); //rotates the coordinate system 45 degrees around the x-axis
///     ofDrawRectangle(20,20,100,100);
/// }
/// ~~~~
/// \param degrees Specifies the angle of rotation, in degrees.
OF_DEPRECATED_MSG("Use ofRotateXDeg or ofRotateXRad", void ofRotateX(float degrees));

/// \brief Produces a rotation around the Y-axis of our coordinate
/// system represented by the vector (0,1,0).
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofRotateY(45); //rotates the coordinate system 45 degrees around the y-axis
///     ofDrawRectangle(20,20,100,100);
/// }
/// ~~~~
/// \param degrees Specifies the angle of rotation, in degrees.
OF_DEPRECATED_MSG("Use ofRotateYDeg or ofRotateYRad", void ofRotateY(float degrees));

/// \brief Produces a rotation around the Z-axis of our coordinate
/// system represented by the vector (0,0,1).
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofRotateZ(45); //rotates the coordinate system 45 degrees around the z-axis
///     ofDrawRectangle(20,20,100,100);
/// }
/// ~~~~
/// \param degrees Specifies the angle of rotation, in degrees.
OF_DEPRECATED_MSG("Use ofRotateZDeg or ofRotateZRad", void ofRotateZ(float degrees));

/// \brief Produces a rotation around the vector (vecX,vecY,vecZ).
///
/// All graphics drawn after ofRotate is called are rotated. Use ofPushMatrix()
/// and ofPopMatrix() to save and restore the unrotated coordinate system.
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofRotate(50, 1, 0.5, 0); //rotates the coordinate system 50 degrees along the x-axis and 25 degrees on the y-axis
///     ofDrawRectangle(20,20,100,100);
/// }
/// ~~~~
///
/// \param degrees Specifies the angle of rotation, in degrees.
/// \param vecX specifies the x coordinates of a vector
/// \param vecY specifies the y coordinates of a vector
/// \param vecZ specifies the z coordinates of a vector
void OF_API_ENTRY ofRotateDeg(float degrees, float vecX, float vecY, float vecZ);

/// \brief Rotate around the z-axis
void OF_API_ENTRY ofRotateDeg(float degrees);

/// \brief Produces a rotation around the X-axis of our coordinate
/// system represented by the vector (1,0,0).
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofRotateX(45); //rotates the coordinate system 45 degrees around the x-axis
///     ofDrawRectangle(20,20,100,100);
/// }
/// ~~~~
/// \param degrees Specifies the angle of rotation, in degrees.
void OF_API_ENTRY ofRotateXDeg(float degrees);

/// \brief Produces a rotation around the Y-axis of our coordinate
/// system represented by the vector (0,1,0).
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofRotateY(45); //rotates the coordinate system 45 degrees around the y-axis
///     ofDrawRectangle(20,20,100,100);
/// }
/// ~~~~
/// \param degrees Specifies the angle of rotation, in degrees.
void OF_API_ENTRY ofRotateYDeg(float degrees);

/// \brief Produces a rotation around the Z-axis of our coordinate
/// system represented by the vector (0,0,1).
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofRotateZ(45); //rotates the coordinate system 45 degrees around the z-axis
///     ofDrawRectangle(20,20,100,100);
/// }
/// ~~~~
/// \param degrees Specifies the angle of rotation, in degrees.
void OF_API_ENTRY ofRotateZDeg(float degrees);

/// \brief Produces a rotation around the vector (vecX,vecY,vecZ).
///
/// All graphics drawn after ofRotate is called are rotated. Use ofPushMatrix()
/// and ofPopMatrix() to save and restore the unrotated coordinate system.
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofRotate(50, 1, 0.5, 0); //rotates the coordinate system 50 degrees along the x-axis and 25 degrees on the y-axis
///     ofDrawRectangle(20,20,100,100);
/// }
/// ~~~~
///
/// \param degrees Specifies the angle of rotation, in degrees.
/// \param vecX specifies the x coordinates of a vector
/// \param vecY specifies the y coordinates of a vector
/// \param vecZ specifies the z coordinates of a vector
void OF_API_ENTRY ofRotateRad(float degrees, float vecX, float vecY, float vecZ);

/// \brief Rotate around the z-axis
void OF_API_ENTRY ofRotateRad(float degrees);

/// \brief Produces a rotation around the X-axis of our coordinate
/// system represented by the vector (1,0,0).
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofRotateX(45); //rotates the coordinate system 45 degrees around the x-axis
///     ofDrawRectangle(20,20,100,100);
/// }
/// ~~~~
/// \param degrees Specifies the angle of rotation, in degrees.
void OF_API_ENTRY ofRotateXRad(float degrees);

/// \brief Produces a rotation around the Y-axis of our coordinate
/// system represented by the vector (0,1,0).
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofRotateY(45); //rotates the coordinate system 45 degrees around the y-axis
///     ofDrawRectangle(20,20,100,100);
/// }
/// ~~~~
/// \param degrees Specifies the angle of rotation, in degrees.
void OF_API_ENTRY ofRotateYRad(float degrees);

/// \brief Produces a rotation around the Z-axis of our coordinate
/// system represented by the vector (0,0,1).
/// ~~~~{.cpp}
/// void ofApp::draw(){
///     ofRotateZ(45); //rotates the coordinate system 45 degrees around the z-axis
///     ofDrawRectangle(20,20,100,100);
/// }
/// ~~~~
/// \param degrees Specifies the angle of rotation, in degrees.
void OF_API_ENTRY ofRotateZRad(float degrees);

/// \}
/// \name Matrix Transformation
/// \{

void OF_API_ENTRY ofLoadIdentityMatrix (void);
void OF_API_ENTRY ofLoadMatrix (const glm::mat4 & m);   // Andreas: I've included both a mat and a float* version here,
void OF_API_ENTRY ofLoadMatrix (const float *m);     // ideally we would always use mat4, but in a lot of temporary
void OF_API_ENTRY ofMultMatrix (const glm::mat4 & m);  // mat objects when interacting with non-OF code
void OF_API_ENTRY ofMultMatrix (const float *m);
void OF_API_ENTRY ofSetMatrixMode(ofMatrixMode matrixMode);
void OF_API_ENTRY ofLoadViewMatrix(const glm::mat4 & m);
void OF_API_ENTRY ofMultViewMatrix(const glm::mat4 & m);
glm::mat4 OF_API_ENTRY ofGetCurrentViewMatrix();


/// \}
/// \name Viewport Setup
/// \{

/// \brief Stores the current viewport and matrix settings
void OF_API_ENTRY ofPushView();

/// \brief Restores the viewport and matrix settings set by ofPushView()
void OF_API_ENTRY ofPopView();

/// \brief Get if view is flipped vertically
bool OF_API_ENTRY ofIsVFlipped();

/// \brief Setup the drawing viewport
/// \param viewport A rectangle describing the size and position of the viewport.
/// If the width or height are set to 0, it will assume the size to be the window
/// size (ofGetWidth(), ofGetHeight())
void OF_API_ENTRY ofViewport(ofRectangle viewport);

/// \brief Setup the drawing viewport
/// \param x The x position of the viewport
/// \param y The y position of the viewport
/// \param width The width of the viewport, defaults to ofGetWidth()
/// \param height The height of the viewport, defaults to ofGetHeight()
void OF_API_ENTRY ofViewport(float x = 0, float y = 0, float width = -1, float height = -1, bool vflip=ofIsVFlipped());

/// \brief Get the position and size of the current viewport
/// \returns A rectangle describing the viewport
ofRectangle OF_API_ENTRY ofGetCurrentViewport();

/// \brief Get the position and size of the native viewport
/// \returns A rectangle describing the viewport
ofRectangle OF_API_ENTRY ofGetNativeViewport();

/// \brief Get the width of the current viewport
/// \returns A width in pixels
int OF_API_ENTRY ofGetViewportWidth();

/// \brief Get the height of the current viewport
/// \returns A height in pixels
int OF_API_ENTRY ofGetViewportHeight();


// if nearDist or farDist are 0 assume defaults (calculated based on width / height)
void OF_API_ENTRY ofSetupScreenPerspective(float width = -1, float height = -1, float fov = 60, float nearDist = 0, float farDist = 0);
void OF_API_ENTRY ofSetupScreenOrtho(float width = -1, float height = -1, float nearDist = -1, float farDist = 1);

OF_DEPRECATED_MSG("ofSetupScreenPerspective() doesn't accept orientation and vflip parameters anymore, use ofSetOrientation() to specify them",
				  void ofSetupScreenPerspective(float width, float height, ofOrientation orientation, bool vFlip = ofIsVFlipped(), float fov = 60, float nearDist = 0, float farDist = 0)
				  );
OF_DEPRECATED_MSG("ofSetupScreenOrtho() doesn't accept orientation and vflip parameters anymore, use ofSetOrientation() to specify them",
				  void ofSetupScreenOrtho(float width, float height, ofOrientation orientation, bool vFlip = ofIsVFlipped(), float nearDist = -1, float farDist = 1)
				  );

int OF_API_ENTRY ofOrientationToDegrees(ofOrientation orientation);

void OF_API_ENTRY ofSetCoordHandedness(ofHandednessType handedness);
ofHandednessType OF_API_ENTRY ofGetCoordHandedness();

/// \}
/// \name Screen Saving
/// \{

/// \brief Begin rendering to a PDF file.
///
/// openFrameworks allows rendering of 2D graphics to pdf via the
/// ofCairoRenderer. ofBeginSaveScreenAsPDF() is called before drawing. When
/// done drawing call ofEndSaveScreenAsPDF() to output the file.
///
/// ~~~~{.cpp}
/// void ofApp::setup(){
///     ofBeginSaveScreenAsPDF("screenshot.pdf", false);
///     ofSetColor(54,54,54);
///     ofDrawEllipse(100,100,200,200);
///     ofEndSaveScreenAsPDF();
/// }
/// ~~~~
/// \sa End drawing with ofEndSaveScreenAsPDF()
void OF_API_ENTRY ofBeginSaveScreenAsPDF(std::string filename, bool bMultipage = false, bool b3D = false, ofRectangle outputsize = ofRectangle(0,0,0,0));

/// \brief Terminates draw to PDF through ofCairoRenderer and outputs the file.
/// \sa ofBeginSaveScreenAsPDF()
void OF_API_ENTRY ofEndSaveScreenAsPDF();

/// \brief Begin rendering to a SVG file.
/// \sa ofEndSaveScreenAsSVG(), ofBeginSaveScreenAsPDF()
void OF_API_ENTRY ofBeginSaveScreenAsSVG(std::string filename, bool bMultipage = false, bool b3D = false, ofRectangle outputsize = ofRectangle(0,0,0,0));

/// \brief Terminates draw to SVG and outputs the file.
/// \sa ofBeginSaveScreenAsSVG()
void OF_API_ENTRY ofEndSaveScreenAsSVG();

/// \}


//--------------------------------------------------
template<typename T>
void ofDrawBitmapString(const T & textString, const glm::vec3 & p){
	ofDrawBitmapString(ofToString(textString), p);
}

//--------------------------------------------------
template<typename T>
void ofDrawBitmapString(const T & textString, const glm::vec2 & p){
	ofDrawBitmapString(ofToString(textString), p);
}

//--------------------------------------------------
template<typename T>
void ofDrawBitmapString(const T & textString, float x, float y){
	ofDrawBitmapString(ofToString(textString), x, y, 0.f);
}

//--------------------------------------------------
template<typename T>
void ofDrawBitmapString(const T & textString, float x, float y, float z){
	ofDrawBitmapString(ofToString(textString), x, y, z);
}
