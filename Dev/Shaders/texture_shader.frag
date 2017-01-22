#version 330

uniform sampler2D tex;
in vec2 texCoord;

struct Light {
    vec3 position;
    vec3 direction;
    float cutOff;
    
    float constant;
    float linear;
    float quadratic;
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;       
}; 



out vec4 FragColour;

void main() {
   FragColour = texture(tex,texCoord);
}
