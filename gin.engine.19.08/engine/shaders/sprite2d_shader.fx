Texture2D txDiffuse[10] : register(t0);
SamplerState samLinear : register(s0);


struct VS_INPUT {
	float3 point_pos : POSITION;
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
	output.pos.x = input.point_pos.x / 1920.0f - 0.5f;
	output.pos.y = (input.point_pos.y / 1080.0f - 0.5f) * -1.0f;
	output.pos.z = 0.5f;
	output.pos.w = 1.0f;
	output.tex_id = input.tex_id;
	output.tex = input.tex;
	return output;
}

float4 pixelShader(PS_INPUT input) : SV_Target
{
	float4 color = txDiffuse[0].Sample(samLinear, input.tex);
	if (color.a < 0.1f) discard;
	
	return color;
}