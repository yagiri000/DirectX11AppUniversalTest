﻿#pragma once

namespace DirectX11AppUniversalTest
{
	// MVP マトリックスを頂点シェーダーに送信するために使用する定数バッファー。
	struct ModelViewProjectionConstantBuffer
	{
		DirectX::XMFLOAT4X4 model;
		DirectX::XMFLOAT4X4 view;
		DirectX::XMFLOAT4X4 projection;
	};

	// MVP 定数バッファー。
	struct LightColConstantBuffer
	{
		DirectX::XMFLOAT3 lightCol;
	};

	// 頂点シェーダーへの頂点ごとのデータの送信に使用します。
	struct VertexPositionColor
	{
		DirectX::XMFLOAT3 pos;
		DirectX::XMFLOAT3 color;
	};
}