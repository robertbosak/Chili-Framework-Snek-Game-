#include "graphics.h"
#include <iostream>
#include <string.h>
#include "window.h"

Graphics::Graphics()
:shader(Shader("shaders/screen.vert", "shaders/screen.frag"))
{
    //.....pixel data array.................
    data = new Pixel[(MainWindow::ScreenWidth * 2) * (MainWindow::ScreenHeight * 2)];

    //......rendering quad...............
    float vertices[] =
    {
        -1.0f,  1.0f,  0.0f, 1.0f,
        -1.0f, -1.0f,  0.0f, 0.0f,
         1.0f, -1.0f,  1.0f, 0.0f,

        -1.0f,  1.0f,  0.0f, 1.0f,
         1.0f, -1.0f,  1.0f, 0.0f,
         1.0f,  1.0f,  1.0f, 1.0f
    };

    unsigned int vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));

    shader.useProgram();
    shader.setInt("screenTexture", 0);
    
    //..........rendering texture...................
    glGenTextures(1, &textureBuffer);
    glBindTexture(GL_TEXTURE_2D, textureBuffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, MainWindow::ScreenWidth * 2, MainWindow::ScreenHeight * 2, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

Graphics::~Graphics()
{
    delete [] data;
    glDeleteTextures(1, &textureBuffer);
    glDeleteVertexArrays(1, &vao);
}

void Graphics::beginFrame()
{
    memset(data, 0, sizeof(Pixel) * MainWindow::ScreenWidth * MainWindow::ScreenHeight);
}

void Graphics::endFrame()
{
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, MainWindow::ScreenWidth, MainWindow::ScreenHeight,
                0, GL_RGB, GL_UNSIGNED_BYTE, data);

        glClear(GL_COLOR_BUFFER_BIT);

        shader.useProgram();
        glBindVertexArray(vao);
        glBindTexture(GL_TEXTURE_2D, textureBuffer);
        glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Graphics::PutPixel(int x, int y, int r, int g, int b)
{
    data[MainWindow::ScreenWidth * y + x].r = r;
    data[MainWindow::ScreenWidth * y + x].g = g;
    data[MainWindow::ScreenWidth * y + x].b = b;
}

void Graphics::drawRect(int x, int y, int x1, int y1, Color c)
{
    if(x > x1)
        std::swap(x, x1);
    if(y > y1)
        std::swap(y, y1);
    
    for(int j = y; j < y1; ++j)
    {
        for(int i = x; i < x1; ++i)
        {
            PutPixel(i, j, c.GetR(), c.GetG(), c.GetB());
        }
    }
}
