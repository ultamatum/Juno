//Texture Shader

#type vertex
#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Colour;
layout(location = 2) in vec2 a_TexCoord;
layout(location = 3) in float a_TexIndex;
layout(location = 4) in float a_TilingFactor;

uniform mat4 u_ViewProjection;

out vec4 v_Colour;
out vec2 v_TexCoord;
out float v_TexIndex;
out float v_TilingFactor;

void main()
{
	v_Colour = a_Colour;
	v_TexCoord = a_TexCoord;
	v_TexIndex = a_TexIndex;
	v_TilingFactor = a_TilingFactor;
	gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
}

#type fragment
#version 330 core

layout(location = 0) out vec4 colour;

in vec4 v_Colour;
in vec2 v_TexCoord;
in float v_TexIndex;
in float v_TilingFactor;

uniform sampler2D u_Textures[32];

void main()
{
	vec4 texColour = v_Colour;
	switch(int(v_TexIndex))
	{
		case 0: texColour *= texture(u_Textures[0], v_TexCoord * v_TilingFactor); break;
		case 1: texColour *= texture(u_Textures[1], v_TexCoord * v_TilingFactor); break;
		case 2: texColour *= texture(u_Textures[2], v_TexCoord * v_TilingFactor); break;
		case 3: texColour *= texture(u_Textures[3], v_TexCoord * v_TilingFactor); break;
		case 4: texColour *= texture(u_Textures[4], v_TexCoord * v_TilingFactor); break;
		case 5: texColour *= texture(u_Textures[5], v_TexCoord * v_TilingFactor); break;
		case 6: texColour *= texture(u_Textures[6], v_TexCoord * v_TilingFactor); break;
		case 7: texColour *= texture(u_Textures[7], v_TexCoord * v_TilingFactor); break;
		case 8: texColour *= texture(u_Textures[8], v_TexCoord * v_TilingFactor); break;
		case 9: texColour *= texture(u_Textures[9], v_TexCoord * v_TilingFactor); break;
		case 10: texColour *= texture(u_Textures[10], v_TexCoord * v_TilingFactor); break;
		case 11: texColour *= texture(u_Textures[11], v_TexCoord * v_TilingFactor); break;
		case 12: texColour *= texture(u_Textures[12], v_TexCoord * v_TilingFactor); break;
		case 13: texColour *= texture(u_Textures[13], v_TexCoord * v_TilingFactor); break;
		case 14: texColour *= texture(u_Textures[14], v_TexCoord * v_TilingFactor); break;
		case 15: texColour *= texture(u_Textures[15], v_TexCoord * v_TilingFactor); break;
		case 16: texColour *= texture(u_Textures[16], v_TexCoord * v_TilingFactor); break;
		case 17: texColour *= texture(u_Textures[17], v_TexCoord * v_TilingFactor); break;
		case 18: texColour *= texture(u_Textures[18], v_TexCoord * v_TilingFactor); break;
		case 19: texColour *= texture(u_Textures[19], v_TexCoord * v_TilingFactor); break;
		case 20: texColour *= texture(u_Textures[20], v_TexCoord * v_TilingFactor); break;
		case 21: texColour *= texture(u_Textures[21], v_TexCoord * v_TilingFactor); break;
		case 22: texColour *= texture(u_Textures[22], v_TexCoord * v_TilingFactor); break;
		case 23: texColour *= texture(u_Textures[23], v_TexCoord * v_TilingFactor); break;
		case 24: texColour *= texture(u_Textures[24], v_TexCoord * v_TilingFactor); break;
		case 25: texColour *= texture(u_Textures[25], v_TexCoord * v_TilingFactor); break;
		case 26: texColour *= texture(u_Textures[26], v_TexCoord * v_TilingFactor); break;
		case 27: texColour *= texture(u_Textures[27], v_TexCoord * v_TilingFactor); break;
		case 28: texColour *= texture(u_Textures[28], v_TexCoord * v_TilingFactor); break;
		case 29: texColour *= texture(u_Textures[29], v_TexCoord * v_TilingFactor); break;
		case 30: texColour *= texture(u_Textures[30], v_TexCoord * v_TilingFactor); break;
		case 31: texColour *= texture(u_Textures[31], v_TexCoord * v_TilingFactor); break;
	}
	colour = texColour;
}