#pragma once



#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ�ļ����ų�����ʹ�õ�����
#include <Windows.h>


#if defined(DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#endif

#include <d3d12.h>
#include <wrl.h>
#include <dxgi1_4.h>


class D3DApp
{
protected:
	static D3DApp* mApp;


	HINSTANCE mhAppInst = nullptr; // application instance handle
	HWND      mhMainWnd = nullptr; // main window handle

	Microsoft::WRL::ComPtr<IDXGIFactory4> mDXGIFactory;


public:
	D3DApp(HINSTANCE hInstance);
	~D3DApp();


	virtual bool Initialize();
	virtual bool Exit();



protected:
	bool InitDirect3D();

};

