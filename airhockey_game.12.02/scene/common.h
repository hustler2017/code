#pragma once


#define HR(x)													\
{																\
	HRESULT res = (x);											\
	if (FAILED(res))											\
	{															\
		DXTrace(__FILE__, DWORD(__LINE__), res, L#x, true);		\
		throw 0;												\
	}															\
}

#define SafeRelease(x)  \
{						\
	if (x) {			\
		(x)->Release();	\
		(x) = nullptr;	\
	}					\
}


inline wstring SToW(string s)
{
	wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
	return converter.from_bytes(s.c_str());
}


inline string WToS(wstring w)
{
	wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
	return converter.to_bytes(w.c_str());
}

namespace Scene3D {

	typedef unsigned int TEXTURERESOURCE, VERTICIESRESOURCE, SHADERRESOURCE;

	typedef struct Position3
	{
		float x;
		float y;
		float z;
	} Position, Rotation;

	class Light
	{
		Position position;
	};
}