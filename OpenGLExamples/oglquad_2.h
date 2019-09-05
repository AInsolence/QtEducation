#pragma once

#include <QGLWidget>

class OGLQuad_2 : public QGLWidget
{
    Q_OBJECT

public:
    OGLQuad_2(QWidget *parent = nullptr);
    ~OGLQuad_2();
protected:
    virtual void initializeGL() override;
    virtual void resizeGL(int width, int height) override;
    virtual void paintGL() override;
private:
    int windowSize = 400;
    void draw(int x, int y, GLenum type);
};
