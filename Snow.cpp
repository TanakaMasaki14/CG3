#include "Snow.h"
#include<random>

Snow::Snow()
{
	particleM = ParticleManager::Create();
	particleM->Initialize();

	particleM->SetEye({ 0, 0, -30 });
	this->coolTime = 0;
	generateLength = { 0,0,0 };
}

void Snow::GenerateSnow(XMFLOAT3 pos, XMFLOAT3 generateLength, int coolTime, int lifeTime)
{
	//pos
	XMFLOAT3 poss{};
	poss.x = pos.x + (float)rand() / RAND_MAX * generateLength.x - generateLength.x / 2.0f;
	poss.y = pos.y + (float)rand() / RAND_MAX * generateLength.y - generateLength.y / 2.0f;
	poss.z = pos.z + (float)rand() / RAND_MAX * generateLength.z - generateLength.z / 2.0f;

	//velocity
	XMFLOAT3 vel{};
	vel.x = 0;
	vel.y = 0;
	vel.z = 0;

	//d—Í‚ÉŒ©—§‚Ä‚ÄY‚Ì‚Ý[-0.001f~0]‚Åƒ‰ƒ“ƒ_ƒ€‚É
	XMFLOAT3 acc{};
	acc.y = -0.005f;

	//F
	XMFLOAT4 color{};
	color.x = 1.0f;
	color.y = 1.0f;
	color.z = 1.0f;
	color.w = 1.0f;

	particleM->Add(lifeTime, poss, vel, acc, (float)rand() / RAND_MAX + 0.1f, 0
		, color, { 0.1f,0.1f,0.1f,0.1f });

	this->coolTime = coolTime;
}

void Snow::Update()
{
	particleM->Update();
}

void Snow::Generate(XMFLOAT3 pos, XMFLOAT3 generateLength, int coolTime)
{
	if (this->coolTime <= 0)
	{
		GenerateSnow(pos, generateLength, coolTime, (float)rand() / RAND_MAX * 300);
	}

	this->coolTime--;
}

void Snow::Draw()
{
	particleM->Draw();
}
