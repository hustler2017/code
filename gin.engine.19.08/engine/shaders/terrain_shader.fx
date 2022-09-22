Texture2D txDiffuse[5] : register(t0);
SamplerState samLinear : register(s0);

cbuffer Camera : register(b0)
{
	matrix viewMatrix;
	matrix projMatrix;
};


cbuffer ConstLight : register(b1)
{
	float3 light_color;
	float light_intensity;
	float3 direction;
	float d;
};


cbuffer ObjectData: register(b3)
{
	matrix worldMatrix;
}


struct VS_INPUT {
	float3 pos : POSITION;
	float3 norm : NORMAL;
	float2 tex1 : TEXCOORD1;
	float2 tex2 : TEXCOORD2;
	float2 tex3 : TEXCOORD3;
	float2 tex4 : TEXCOORD4;
	float4 mask : TEXCOORD5;
};

struct PS_INPUT {
	float4 pos : SV_POSITION;
	float4 norm : NORMAL;
	float2 tex1 : TEXCOORD1;
	float2 tex2 : TEXCOORD2;
	float2 tex3 : TEXCOORD3;
	float2 tex4 : TEXCOORD4;
	float4 mask : TEXCOORD5;
};

PS_INPUT vertexShader(VS_INPUT input)
{
	PS_INPUT output;
	output.pos = mul(float4(input.pos, 1.0f), worldMatrix);
	output.pos = mul(output.pos, viewMatrix);
	output.pos = mul(output.pos, projMatrix);
	output.norm = float4(input.norm, 1.0f);
	output.norm = mul(output.norm, transpose(worldMatrix));
	output.tex1 = input.tex1;
	output.tex2 = input.tex2;
	output.tex3 = input.tex3;
	output.tex4 = input.tex4;
	output.mask = input.mask;
	return output;
}



float4 pixelShader(PS_INPUT input) : SV_Target
{
	float4 textureColor1 = txDiffuse[0].Sample(samLinear, input.tex1);
	float4 textureColor2 = txDiffuse[1].Sample(samLinear, input.tex2);
	float4 textureColor3 = txDiffuse[2].Sample(samLinear, input.tex3);
	float4 textureColor4 = txDiffuse[3].Sample(samLinear, input.tex4);
	float4 alphaTex = txDiffuse[4].Sample(samLinear, input.mask);

	textureColor1.a = 1.0f;
	textureColor2.a = alphaTex[0];
	
	float4 color1 = textureColor1;
	color1 = (textureColor2 * textureColor2.a) + color1 * (1.0 - textureColor2.a);

	
	textureColor3.a = 1.0f;
	textureColor4.a = alphaTex[2];

	
	float4 color2 = textureColor3;
	color2 = (textureColor4 * textureColor4.a) + color2 * (1.0 - textureColor4.a);
	color2.a = alphaTex[1];

	float4 color;
	
	color = color1;
	color = (color2 * color2.a) + color * (1.0 - color2.a);

	//color = saturate(dot(input.norm, -direction)) * color;
	color.a = 1.0f;

	return color;
}

/*
float4 pixelShader(PS_INPUT input) : SV_Target
{
	float4 textureColor1 = txDiffuse[0].Sample(samLinear, input.tex1);
	float4 textureColor2 = txDiffuse[1].Sample(samLinear, input.tex2);
	float4 textureColor3 = txDiffuse[2].Sample(samLinear, input.tex3);
	float4 textureColor4 = txDiffuse[3].Sample(samLinear, input.tex4);
	float4 alphaTex = txDiffuse[4].Sample(samLinear, input.mask);

	textureColor1.a = 1.0f;
	textureColor2.a = alphaTex[0];
	textureColor3.a = alphaTex[1];
	textureColor4.a = alphaTex[2];

	float4 color = textureColor1;

	color = (textureColor2 * textureColor2.a) + color * (1.0 - textureColor2.a);
	color = (textureColor3 * textureColor3.a) + color * (1.0 - textureColor3.a);
	color = (textureColor4 * textureColor4.a) + color * (1.0 - textureColor4.a);

	//color = saturate(dot(input.norm, -direction)) * color;
	color.a = 1.0f;

	return color;
}*/