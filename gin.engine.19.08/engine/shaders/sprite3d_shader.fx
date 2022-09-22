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
	float2 tex : TEXCOORD;
	uint tex_id : TEXID;
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
	float4 color;

if (input.tex_id == 0) { color = txDiffuse[0].Sample(samLinear, input.tex); }
if (input.tex_id == 1) { color = txDiffuse[1].Sample(samLinear, input.tex); }
if (input.tex_id == 2) { color = txDiffuse[2].Sample(samLinear, input.tex); }
if (input.tex_id == 3) { color = txDiffuse[3].Sample(samLinear, input.tex); }
if (input.tex_id == 4) { color = txDiffuse[4].Sample(samLinear, input.tex); }
if (input.tex_id == 5) { color = txDiffuse[5].Sample(samLinear, input.tex); }
if (input.tex_id == 6) { color = txDiffuse[6].Sample(samLinear, input.tex); }
if (input.tex_id == 7) { color = txDiffuse[7].Sample(samLinear, input.tex); }
if (input.tex_id == 8) { color = txDiffuse[8].Sample(samLinear, input.tex); }
if (input.tex_id == 9) { color = txDiffuse[9].Sample(samLinear, input.tex); }
	

if (color.a < 0.2f) discard;

	return color;
}