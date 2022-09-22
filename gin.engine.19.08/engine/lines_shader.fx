
cbuffer Camera : register(b0)
{
	matrix viewMatrix;
	matrix projMatrix;
};

struct VS_INPUT
{
	float3 position : POSITION;
	float4 color : COLOR;
};

struct PS_INPUT
{
	float4 position : SV_POSITION;
	float4 color : COLOR;
};


PS_INPUT vertexShader(VS_INPUT input)
{
	PS_INPUT output;
	output.position = mul(float4(input.position, 1.0f), viewMatrix);
	output.position = mul(output.position, projMatrix);
	output.color = input.color;
	return output;
}

float4 pixelShader(PS_INPUT input) : SV_TARGET
{
	return input.color;
}