#pragma once
#include "ParticleManager.h"
#include <DirectXMath.h>

using namespace DirectX;

class Emitter
{
public:
	void Init(ParticleManager* particleMan);
	void SpawnParticle(int life, XMFLOAT3 pos, XMFLOAT3 vel, XMFLOAT3 accel, float start_scale, float end_scale, XMFLOAT4 color);

private:
	ParticleManager* particleMan = nullptr;

};