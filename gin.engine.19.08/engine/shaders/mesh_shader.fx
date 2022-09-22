Texture2D txDiffuse : register(t0);
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


struct VS_INPUT
{
	float3 position : POSITION;
	float3 norm : NORMAL;
	float2 tex : TEXCOORD;
};

struct PS_INPUT
{
	float4 position : SV_POSITION;
	float3 norm : NORMAL;
	float2 tex : TEXCOORD;
};


PS_INPUT vertexShader(VS_INPUT input)
{
	PS_INPUT output;
	output.position = mul(float4(input.position, 1.0f), worldMatrix);
	output.position = mul(output.position, viewMatrix);
	output.position = mul(output.position, projMatrix);
	output.norm = mul(float4(input.norm, 1.0f), transpose(worldMatrix));
	output.tex = input.tex;
	return output;
}

float4 pixelShader(PS_INPUT input) : SV_TARGET
{
	float4 textureColor = txDiffuse.Sample(samLinear, input.tex);
	float intensity = saturate(dot(input.norm, -direction));
	float4 color = intensity * textureColor;
	color.a = 1;
	return color;

}