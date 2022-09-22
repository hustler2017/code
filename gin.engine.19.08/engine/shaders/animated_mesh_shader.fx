#define MAX_MATRICES 30

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

cbuffer AnimationMatrices : register(b2)
{
	matrix matrices[MAX_MATRICES];
}

cbuffer ObjectData: register(b3)
{
	matrix worldMatrix;
}



struct VS_INPUT {
	float3 position : POSITION;
	float3 normal : NORMAL;
	float2 tex : TEXCOORD;
	uint4 bone : BONEID;
	float4 weight : BONEWEIGHT;
};

struct PS_INPUT {
	float4 position : SV_POSITION;
	float4 normal : NORMAL;
	float2 tex : TEXTCOORD;

};


PS_INPUT vertexShader(VS_INPUT input)
{
	PS_INPUT output;

	matrix result_transform =
		matrices[input.bone[0]] * input.weight[0] +
		matrices[input.bone[1]] * input.weight[1] +
		matrices[input.bone[2]] * input.weight[2] +
		matrices[input.bone[3]] * input.weight[3];

	output.position = float4(input.position, 1.0f);
	output.normal = float4(input.normal, 1.0f);
	output.position = mul(output.position, result_transform);
	output.position = mul(output.position, worldMatrix);
	output.position = mul(output.position, viewMatrix);
	output.position = mul(output.position, projMatrix);
	output.normal = mul(output.normal, transpose(result_transform));
	output.normal = mul(output.normal, transpose(worldMatrix));
	output.tex = input.tex;

	return output;
}


/*
PS_INPUT vertexShader(VS_INPUT input)
{
	PS_INPUT output;
	output.position = float4(input.position, 1.0f);
	float4 result_position = mul(output.position, matrices[input.bone[0]]) * input.weight[0];
	result_position += mul(output.position, matrices[input.bone[1]]) * input.weight[1];
	result_position += mul(output.position, matrices[input.bone[2]]) * input.weight[2];
	result_position += mul(output.position, matrices[input.bone[3]]) * input.weight[3];
	output.position = result_position;
	output.position = mul(output.position, viewMatrix);
	output.position = mul(output.position, projMatrix);

	

	//output.normal = mul(float4(output.normal, 1.0f), transponse(weight_world));
	output.tex = input.tex;
	
	return output;
}
*/

float4 pixelShader(PS_INPUT input) : SV_Target
{
	float4 textureColor = txDiffuse.Sample(samLinear, input.tex);
	float intensity = saturate(dot(input.normal, -direction));
	float4 color = intensity * textureColor;
	color.a = 1;
	return color;
}