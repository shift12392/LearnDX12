#pragma once



#if defined(DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
#include <Windows.h>

#include <d3d12.h>
#include <wrl.h>
#include <dxgi1_4.h>

#pragma comment(lib, "D3D12.lib")
#pragma comment(lib, "dxgi.lib")


class D3DApp
{
protected:
	static D3DApp* mApp;


	HINSTANCE mhAppInst = nullptr; // application instance handle
	HWND      mhMainWnd = nullptr; // main window handle

	Microsoft::WRL::ComPtr<IDXGIFactory4> mDXGIFactory;


	DXGI_FORMAT mBackBufferFormat = DXGI_FORMAT_R8G8B8A8_UNORM;

public:
	D3DApp(HINSTANCE hInstance);
	~D3DApp();


	virtual bool Initialize();
	virtual bool Exit();

#if defined(DEBUG) || defined(_DEBUG)

	void LogAdapters();
	void LogAdapterOutputs(IDXGIAdapter* adapter);
	void LogOutputDisplayModes(IDXGIOutput* output, DXGI_FORMAT format);

#endif



protected:
	bool InitDirect3D();

};

