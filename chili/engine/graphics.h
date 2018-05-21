#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "shader.h"
#include "color.h"

class Graphics
{
public:
    Graphics();
    ~Graphics();

    void beginFrame();
    void endFrame();
    void PutPixel(int x, int y, int r, int g, int b);
    void drawRect(int x, int y, int x1, int y1, Color c);
    void drawRectDim(int x, int y, int width, int height, Color c)
    {
        drawRect(x, y, x + width, y + height, c);
    }

protected:

private:
    Shader shader;
    GLuint vao, framebuffer, textureBuffer;
    //..............................................................

    struct Pixel
    {
      GLubyte r, g, b;
    };

    Pixel* data;
};

#endif // GRAPHICS_H
