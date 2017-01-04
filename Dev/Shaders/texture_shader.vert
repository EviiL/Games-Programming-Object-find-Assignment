#version 330

layout (location=0) in vec3 VertexPosition;
layout (location=1) in vec2 fragTexCoord;

out vec2 texCoord;

uniform mat4 mModel;
uniform mat4 mProjection;
uniform mat4 mView;

void main()
{
	texCoord = fragTexCoord;

    gl_Position = mProjection * mView * mModel  *  vec4(VertexPosition,1.0);
}
