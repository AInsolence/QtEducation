#include "oglpyramide.h"
#include "QMouseEvent"

OGLPyramide::OGLPyramide(QWidget* parent)
    : QGLWidget (parent), xRotateAngle(0), yRotateAngle(0)
{

}

OGLPyramide::~OGLPyramide()
{

}

void OGLPyramide::initializeGL()
{
    qglClearColor(Qt::black);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    displayListNumber = createPyramide(1.2f);
}

void OGLPyramide::resizeGL(int width, int height)
{
    glViewport(0, 0, static_cast<GLuint>(width), static_cast<GLuint>(height));
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);// multiply current matrix by perspective matrix
}

void OGLPyramide::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.0);
    glRotatef(xRotateAngle, 1.0, 0.0, 0.0);
    glRotatef(yRotateAngle, 0.0, 1.0, 0.0);

    glCallList(displayListNumber);
}

void OGLPyramide::mousePressEvent(QMouseEvent *me)
{
    mouseCursorPosition = me->pos();
}

void OGLPyramide::mouseMoveEvent(QMouseEvent *me)
{
    xRotateAngle += 180 * static_cast<GLfloat>(me->y() - mouseCursorPosition.y());
    yRotateAngle += 180 * static_cast<GLfloat>(me->x() - mouseCursorPosition.x());
    updateGL();
    mouseCursorPosition = me->pos();
}

GLuint OGLPyramide::createPyramide(GLfloat pyramideSize)
{
    GLuint glListNumber = glGenLists(1);
    glNewList(glListNumber, GL_COMPILE);

        glBegin(GL_TRIANGLE_FAN);
            qglColor(Qt::green);
            glVertex3f(0.0, pyramideSize, 0.0);
            glVertex3f(-pyramideSize, -pyramideSize, pyramideSize);
            glVertex3f(pyramideSize, -pyramideSize, pyramideSize);
            qglColor(Qt::yellow);
            glVertex3f(pyramideSize, -pyramideSize, -pyramideSize);
            qglColor(Qt::white);
            glVertex3f(-pyramideSize, -pyramideSize, pyramideSize);
        glEnd();

        glBegin(GL_QUADS);
            qglColor(Qt::red);
            glVertex3f(-pyramideSize, -pyramideSize, pyramideSize);
            glVertex3f(pyramideSize, -pyramideSize, pyramideSize);
            glVertex3f(pyramideSize, -pyramideSize, -pyramideSize);
            glVertex3f(-pyramideSize, -pyramideSize, -pyramideSize);
        glEnd();

    glEndList();

    return glListNumber;
}
