#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>

class Shader
{
public:
    Shader(const std::string& vertexSource, const std::string& fragmentSource);
    ~Shader();

    void useProgram();
    
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    
    GLuint ID;
    
protected:
    
private:
    
};

#endif // SHADER_H
