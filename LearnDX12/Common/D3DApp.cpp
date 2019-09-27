#include "stdafx.h"
#include "D3DApp.h"
#include <cassert>

using namespace Microsoft::WRL;

D3DApp* D3DApp::mApp = nullptr;


D3DApp::D3DApp(HINSTANCE hInstance)
	:mhAppInst(hInstance)
{

	assert(mhAppInst != nullptr);

	mApp = this;
}

D3DApp::~D3DApp()
{
}

bool D3DApp::Initialize()
{
#if defined(DEBUG) || defined(_DEBUG) 
	// Enable the D3D12 debug layer.
	{
		ComPtr<ID3D12Debug> debugController;
		ThrowIfFailed(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController)));
		debugController->EnableDebugLayer();
	}
#endif


	return false;
}

bool D3DApp::Exit()
{
	return false;
}

bool D3DApp::InitDirect3D()
{
	return false;
}
