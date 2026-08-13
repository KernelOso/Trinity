#version 460 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormals;
layout (location = 2) in vec2 aUV;

out vec2 UV;

uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProjection;

void main() {

    gl_Position = projection * view * model * vec4(aPos, 1.0);

    UV = aUV;

}