
//struct Light
//{
//	float4 color;
//	float4 position;
//	float range;
//};

cbuffer SceneConstantBuffer : register(b0) {
	matrix ViewMatrix;
	matrix ProjectionMatrix;
	//int numLights;
	//Light lights[10];
};

cbuffer ObjectConstantBuffer : register(b1) {
	float4x4 WorldMatrix;
};



struct VS_INPUT
{
	float4 position : POSITION;
	//float4 color : COLOR;
	//float3 norm : NORMAL;
};

struct PS_INPUT
{
	float4 position : SV_POSITION;
	//float4 color : COLOR;
	//float3 norm : TEXCOORD0;
};


//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
PS_INPUT VS_Main(VS_INPUT Input)
{
	PS_INPUT Output = (PS_INPUT)0;

	Output.position = mul(Input.position, WorldMatrix);
	Output.position = mul(Out.position, ViewMatrix);
	Output.position = mul(Out.position, ProjectionMatrix);
	//Output.norm = mul(Input.norm, WorldMatrix);
	//Output.color = Input.color;

	return Out;
}


//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------
float4 PS_Main(PS_INPUT input) : SV_Target
{
	//float4 finalColor = 0;

	//for (int i = 0; i < numLights; i++)
	//{
		//finalColor += 0.1f;
	//}

	return input.color;
}

//--------------------------------------------------------------------------------------
// PSSolid - render a solid color
//--------------------------------------------------------------------------------------
float4 PSSolid(PS_INPUT input) : SV_Target
{
	return input.color;
}