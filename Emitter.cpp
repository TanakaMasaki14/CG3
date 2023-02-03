#include "Emitter.h"

void Emitter::Init(ParticleManager* particleMan)
{
	this->particleMan = particleMan;
}

void Emitter::SpawnParticle(int life, XMFLOAT3 pos, XMFLOAT3 vel, XMFLOAT3 accel, float start_scale, float end_scale, XMFLOAT4 color)
{
	particleMan->particles.emplace_front();

	ParticleManager::Particle& p = particleMan->particles.front();

	p.pos = pos;
	p.vel = vel;
	p.accel = accel;
	p.num_frame = life;
	p.s_scale = start_scale;
	p.e_scale = end_scale;
	p.color = color;
}