﻿#pragma once

#include "..\Common\DeviceResources.h"
#include "ShaderStructures.h"
#include "..\Common\StepTimer.h"

namespace DirectX11AppUniversalTest
{

class WavePoint {
public:
	// 自分の原点に対するバネ定数
	static const float K_BASE;
	// 自分の隣接する点に対するバネ定数
	static const float K_NEAR;
	// 減衰定数
	static const float DEC_RATE;

	float h;
	float v;
	WavePoint(float h_, float v_) : h(h_), v(v_) {}
	WavePoint(){}
};

// このサンプル レンダリングでは、基本的なレンダリング パイプラインをインスタンス化します。
class Sample3DSceneRenderer
{
public:
	static const int xNum = 100;
	static const int yNum = 100;
	WavePoint wavePoints[yNum][xNum];
	Sample3DSceneRenderer(const std::shared_ptr<DX::DeviceResources>& deviceResources);
	void CreateDeviceDependentResources();
	void CreateWindowSizeDependentResources();
	void ReleaseDeviceDependentResources();
	void Update(DX::StepTimer const& timer);
	void Render();
	void StartTracking();
	void TrackingUpdate(float positionX);
	void StopTracking();
	bool IsTracking() { return m_tracking; }


private:
	void Rotate(float radians);

private:
	// デバイス リソースへのキャッシュされたポインター。
	std::shared_ptr<DX::DeviceResources> m_deviceResources;

	// キューブ ジオメトリの Direct3D リソース。
	Microsoft::WRL::ComPtr<ID3D11InputLayout>	m_inputLayout;
	Microsoft::WRL::ComPtr<ID3D11Buffer>		m_vertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11Buffer>		m_indexBuffer;
	Microsoft::WRL::ComPtr<ID3D11VertexShader>	m_vertexShader;
	Microsoft::WRL::ComPtr<ID3D11PixelShader>	m_pixelShader;
	Microsoft::WRL::ComPtr<ID3D11Buffer>		m_constantBuffer;
	Microsoft::WRL::ComPtr<ID3D11Buffer>		m_constantBufferLightCol;

	// キューブ ジオメトリのシステム リソース。
	ModelViewProjectionConstantBuffer	m_constantBufferData;
	LightColConstantBuffer m_cBLightBufferData;

	uint32	m_indexCount;

	// レンダリング ループで使用する変数。
	bool	m_loadingComplete;
	float	m_degreesPerSecond;
	bool	m_tracking;
};
}

