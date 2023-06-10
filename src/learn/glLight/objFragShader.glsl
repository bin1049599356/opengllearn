#version 330 core
out vec4 FragColor;
in vec3 Normal;
in vec3 FragPos;
in vec3 LightPos;
uniform vec4 UniFragColor;

uniform vec3 objectColor;
uniform vec3 lightColor;

struct Light {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shiniess;
};

uniform Light light;
uniform Material material;

//uniform vec3 viewPos;

void main()
{
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(LightPos - FragPos);

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = (diff * material.diffuse) * light.diffuse;

    vec3 viewDir = vec3(0.0f, 0.0f, 1.0f);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shiniess);
    vec3 specular = (material.specular * spec) * light.specular;

    vec3 ambient = light.ambient * material.ambient;

    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
};