#version 460 core

in vec2 UV;

out vec4 FragColor;

// 0 :: Albdeo
layout (binding = 0) uniform sampler2D u_Texture;

void main() {

//    FragColor = vec4(texture(u_Texture, UV), 1.0f);

    FragColor = vec4(1.0f , 0.0f , 0.0f , 0.0f);

}