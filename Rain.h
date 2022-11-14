#pragma once
#include"ParticleManager.h"

class Rain
{
private:
	// DirectX::Çè»ó™
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

	ParticleManager* particleM;

	XMFLOAT3 generateLength;
	int coolTime;


private:
	void GenerateRain(XMFLOAT3 pos, XMFLOAT3 generateLength, int coolTime, int lifeTime);

public:

	/*const float accel = 1.0f;
	XMFLOAT3 velocity;*/

	Rain();


	void Generate(XMFLOAT3 pos, XMFLOAT3 generateLength, int coolTime);

	void Update();
	void Draw();
};

