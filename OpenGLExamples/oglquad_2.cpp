#include "oglquad_2.h"
#include "QtDebug"

OGLQuad_2::OGLQuad_2(QWidget *parent)
    : QGLWidget(parent)
{
    glShadeModel(GL_SMOOTH);// on antialiasing mode
}

OGLQuad_2::~OGLQuad_2()
{

}

void OGLQuad_2::initializeGL()
{
    qglClearColor(Qt::white);
}

void OGLQuad_2::resizeGL(int width, int height)
{
    glMatrixMode(GL_PROJECTION);// set this matrix as 'camera' projection
    glLoadIdentity();// set this matrix as identity matrix
    glViewport(0, 0, static_cast<GLint>(width), static_cast<GLint>(height));// set a viewport size same as
                                                                            // our wgt size
    glOrtho(0, windowSize, windowSize, 0, -1, 1);
}

void OGLQuad_2::paintGL()
{
    // clear a color and a depth buffers before painting
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // use helper functions to draw
    draw(0, 0, GL_POINTS);
    draw(100, 0, GL_LINES);
    draw(200, 0, GL_LINE_STRIP);
    draw(300, 0, GL_LINE_LOOP);

    draw(0, 100, GL_TRIANGLE_STRIP);
    draw(100, 100, GL_POLYGON);
    draw(200, 100, GL_QUADS);
    draw(300, 100, GL_TRIANGLES);
}

void OGLQuad_2::draw(int xOffset, int yOffset, GLenum type)
{
    int numOfPoints = 8;
    glPointSize(2);
    // begin painting
    glBegin(type);
        glColor3f(0, 0, 0);
        for (int i = 0; i < numOfPoints; ++i) {
            float fAngle = 2 * 3.14 * i/numOfPoints;
            int x = static_cast<int>(50 + cos(fAngle) * 40 + xOffset);
            int y = static_cast<int>(50 + sin(fAngle) * 40 + yOffset);
            glVertex2f(x, y);
            qDebug() << "in for loop x = " << x << ", y = " << y;
        }
    // finish painting
        //glVertex2f(100, 100);
        glEnd();
}
