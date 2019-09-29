//#include "stdafx.h"
#include "D3DApp.h"
#include "../Common/d3dUtil.h"


#include <string>
#include <cassert>
#include <vector>

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


	ThrowIfFailed(CreateDXGIFactory1(IID_PPV_ARGS(&mDXGIFactory)));


	return false;
}

bool D3DApp::Exit()
{
	return false;
}

#if defined(DEBUG) || defined(_DEBUG)

void D3DApp::LogAdapters()
{
	UINT i = 0;
	IDXGIAdapter *adapter = nullptr;
	std::vector<IDXGIAdapter*> adapterList;
	while (mDXGIFactory->EnumAdapters(i, &adapter) != DXGI_ERROR_NOT_FOUND)
	{
		DXGI_ADAPTER_DESC desc;
		adapter->GetDesc(&desc);

		std::wstring text = L"***Adapter: ";
		text += desc.Description;
		text += L"\n";

		OutputDebugStringW(text.c_str());

		adapterList.push_back(adapter);
		++i;
	}

	for (size_t i = 0; i < adapterList.size(); i++)
	{
		LogAdapterOutputs(adapterList[i]);
		ReleaseCom(adapterList[i]);
	}
}

void D3DApp::LogAdapterOutputs(IDXGIAdapter * adapter)
{
	UINT i = 0;
	IDXGIOutput *output = nullptr;
	while (adapter->EnumOutputs(i,&output) != DXGI_ERROR_NOT_FOUND)
	{
		DXGI_OUTPUT_DESC desc;
		output->GetDesc(&desc);

		std::wstring text = L"***Output";
		text += desc.DeviceName;
		text += L"\n";

		OutputDebugStringW(text.c_str());

		LogOutputDisplayModes(output, mBackBufferFormat);

		ReleaseCom(output);
	}
}

void D3DApp::LogOutputDisplayModes(IDXGIOutput * output, DXGI_FORMAT format)
{
}

#endif

bool D3DApp::InitDirect3D()
{
	return false;
}
