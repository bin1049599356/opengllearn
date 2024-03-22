#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec3 Position;

uniform vec3 cameraPos;
uniform samplerCube skybox;


in vec2 TexCoords;
uniform sampler2D texture_diffuse1;
uniform sampler2D texture_normal1;
uniform sampler2D texture_height1;

void main()
{    
    vec3 I = normalize(Position - cameraPos);
    vec3 R = reflect(I, normalize(Normal));

    
    vec4 D = texture(texture_diffuse1, TexCoords);
    vec4 RColor = vec4(texture(skybox, R).rgb, 1.0);
    texture(texture_height1, TexCoords);
    
    FragColor = mix(texture(texture_diffuse1, TexCoords), texture(skybox, R), texture(texture_height1, TexCoords));
}