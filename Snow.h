#pragma once
#include"ParticleManager.h"

class Snow
{
private:
	// DirectX::???ȗ?
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

	ParticleManager* particleM;

	XMFLOAT3 generateLength;
	int coolTime;


private:
	void GenerateSnow(XMFLOAT3 pos, XMFLOAT3 generateLength, int coolTime, int lifeTime);

public:

	/*const float accel = 1.0f;
	XMFLOAT3 velocity;*/

	Snow();


	void Generate(XMFLOAT3 pos, XMFLOAT3 generateLength, int coolTime);

	void Update();
	void Draw();
};

