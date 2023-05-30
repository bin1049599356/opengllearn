#version 330 core
out vec4 FragColor;
// in vec4 InFragColor;
uniform vec4 UniFragColor;
in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    FragColor = mix(texture(texture1, TexCoord), texture(texture2, vec2(TexCoord.y, -TexCoord.x)), 0.2);// * vec4(InFragColor);
};