#ifndef OGLPYRAMIDE_H
#define OGLPYRAMIDE_H

#include <QGLWidget>

class OGLPyramide : public QGLWidget
{
public:
    OGLPyramide(QWidget* parent = nullptr);
    ~OGLPyramide();
protected:
    virtual void initializeGL() override;
    virtual void resizeGL(int width, int height) override;
    virtual void paintGL() override;

    virtual void mousePressEvent(QMouseEvent* me) override;
    virtual void mouseMoveEvent(QMouseEvent* me) override;

    GLuint createPyramide(GLfloat pyramideSize = 1.0f);
private:
    GLuint displayListNumber;
    GLfloat xRotateAngle;
    GLfloat yRotateAngle;
    QPoint mouseCursorPosition;
};

#endif // OGLPYRAMIDE_H
