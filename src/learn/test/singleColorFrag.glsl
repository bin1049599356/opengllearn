#version 330 core
out vec4 FragColor;
// in vec4 InFragColor;
uniform vec4 UniFragColor;

uniform vec3 objectColor;
uniform vec3 lightColor;

void main()
{
    FragColor = vec4(1.0, 1.0, 0.0, 1.0);
};