#include "Hanabi.h"
#include <random>
#include<math.h>


Hanabi::Hanabi()
{
	particleM = ParticleManager::Create();
	particleM->Initialize();

	particleM->SetEye({ 0, 0, -30 });
	lifeTime = 0;
}

void Hanabi::GenerateHanabi(XMFLOAT3 pos, float scale, int lifeTime)
{
	float radius = 0;
	float angle = 0;
	this->lifeTime = lifeTime;

	for (int i = 0; i < numTmp * 10; i++)
	{
		if (i % numTmp == 0)
		{
			radius += distanceTmp * scale;
			angle = 0;
		}

		//pos
		XMFLOAT3 poss{};
		poss.x = pos.x + cosf(angle) * radius;
		poss.y = pos.y + sinf(angle) * radius;
		poss.z = pos.z;

		//velocity
		XMFLOAT3 vel{};
		vel.x = cosf(angle) * radius * 0.01f;
		vel.y = sinf(angle) * radius * 0.01f;
		vel.z = 0;

		//d—Í‚ÉŒ©—§‚Ä‚ÄY‚Ì‚Ý[-0.001f~0]‚Åƒ‰ƒ“ƒ_ƒ€‚É
		XMFLOAT3 acc{};
		acc.y = -0.0005f;

		//F
		XMFLOAT4 color{};
		const float md_color = 1.0f;
		color.x = ((float)rand() / RAND_MAX+0.1f) * md_color;
		color.y = ((float)rand() / RAND_MAX+0.1f) * md_color;
		color.z = ((float)rand() / RAND_MAX+0.1f) * md_color;
		color.w = ((float)rand() / RAND_MAX+0.1f) * md_color;

		particleM->Add(lifeTime, poss, vel, acc, 0.5f, 0
			, color, { color.x,color.y,color.z,0.1f });


		angle += angleTmp;
	}
}

void Hanabi::Generate(XMFLOAT3 pos, float scale, int lifeTime)
{
	if (this->lifeTime <= 0)
	{
		GenerateHanabi(pos, scale, lifeTime);
	}

	this->lifeTime--;
}

void Hanabi::Update()
{
	particleM->Update();
}

void Hanabi::Draw()
{
	particleM->Draw();
}
