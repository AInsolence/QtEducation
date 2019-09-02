#ifndef OGLQUAD_H
#define OGLQUAD_H

#include <QGLWidget>

class OGLQuad : public QGLWidget
{
    Q_OBJECT

public:
    OGLQuad(QWidget *parent = nullptr);
    ~OGLQuad();
protected:
    virtual void initializeGL() override;
    virtual void resizeGL(int width, int height) override;
    virtual void paintGL() override;
private:
    int windowSize = 300;
};

#endif // OGLQUAD_H
