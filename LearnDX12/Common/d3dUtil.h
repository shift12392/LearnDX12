#pragma once




#include <d3d12.h>



class DxException
{

};


#ifndef ThrowIfFailed
#define ThrowIfFailed(x)   \
HRESULT __hr = (x);        \
if(FAILED(__hr)) {throw __FILEW__; }

#endif // !ThrowIfFailed


#ifndef ReleaseCom
#define ReleaseCom(x) { if( x != nullptr) { x->Release();  x = nullptr;} }
#endif // !ReleaseCom




