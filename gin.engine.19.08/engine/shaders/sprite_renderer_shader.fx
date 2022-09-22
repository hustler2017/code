Texture2D txDiffuse[10] : register(t0);
SamplerState samLinear : register(s0);

cbuffer Camera : register(b0)
{
	matrix viewMatrix;
	matrix projMatrix;
};

struct VS_INPUT {
	float3 point_pos : POSITION;
	float3 center_pos : POSITION1;
	uint tex_id : TEXID;
	float2 tex : TEXCOORD;
};

struct PS_INPUT {
	float4 pos : SV_POSITION;
	uint tex_id : TEXID;
	float2 tex : TEXCOORD;
};

PS_INPUT vertexShader(VS_INPUT input)
{
	PS_INPUT output;
	output.pos = mul(float4(input.center_pos, 1.0f), viewMatrix);
	output.pos += float4(input.point_pos, 0.0f);
	output.pos = mul(output.pos, projMatrix);
	output.tex = input.tex;
	output.tex_id = input.tex_id;
	return output;
}

float4 pixelShader(PS_INPUT input) : SV_Target
{
	float4 color = txDiffuse[0].Sample(samLinear, input.tex);
	if (color.a < 0.1f) discard;
	
	return color;
}