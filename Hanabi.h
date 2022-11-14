#pragma once
#include"ParticleManager.h"

static const float pi = 3.1415f;

class Hanabi
{
private:
	// DirectX::Çè»ó™
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

	ParticleManager* particleM;

	const int numTmp = 50;
	const float angleTmp = 2.0f * pi / numTmp;
	const float distanceTmp = 0.5f;
	int lifeTime;

public:

	/*const float accel = 1.0f;
	XMFLOAT3 velocity;*/

	Hanabi();

	void GenerateHanabi(XMFLOAT3 pos, float scale, int lifeTime);

	void Generate(XMFLOAT3 pos, float scale, int lifeTime);

	void Update();

	void Draw();
};

