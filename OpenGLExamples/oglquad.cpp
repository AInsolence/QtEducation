#include "oglquad.h"

OGLQuad::OGLQuad(QWidget *parent)
    : QGLWidget(parent)
{
    glShadeModel(GL_SMOOTH);// on antialiasing mode
}

OGLQuad::~OGLQuad()
{

}

void OGLQuad::initializeGL()
{
    qglClearColor(Qt::black);
}

void OGLQuad::resizeGL(int width, int height)
{
    glMatrixMode(GL_PROJECTION);// set this matrix as 'camera' projection
    glLoadIdentity();// set this matrix as identity matrix
    glViewport(0, 0, static_cast<GLint>(width), static_cast<GLint>(height));// set a viewport size same as
                                                                            // our wgt size
    glOrtho(0, windowSize, windowSize, 0, -1, 1);
}

void OGLQuad::paintGL()
{
    // clear a color and a depth buffers before painting
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // begin painting
    glBegin(GL_QUADS);
        glColor3f(1, 1, 1);
        glVertex2f(0, 0);

        glColor3f(1, 0, 0);
        glVertex2f(0, windowSize);

        glColor3f(0, 1, 0);
        glVertex2f(windowSize, windowSize);

        glColor3f(0, 0, 1);
        glVertex2f(windowSize, 0);
    // finish painting
    glEnd();
}
