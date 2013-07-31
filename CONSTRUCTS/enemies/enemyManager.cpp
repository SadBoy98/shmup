#include "enemyManager.h"

#include "../bullets/bulletManager.h"

#include "basicEnemy.h"

EnemyManager enemyManager;

EnemyManager::EnemyManager()
{
    enemies.reserve(300);
}

EnemyManager::~EnemyManager()
{
    enemies.clear();
}

void EnemyManager::Move()
{
    for(unsigned int i=0; i<enemies.size(); ++i)
    {
        enemies[i]->Move();
    }
}

void EnemyManager::Logic()
{
    for(unsigned int i=0; i<enemies.size(); ++i)
    {
        enemies[i]->ReduceHealth(bulletManager.IsEnemyHit(enemies[i]->GetLoc()));
        if(enemies[i]->IsDying()) {enemies.erase(enemies.begin()+i); i=i-1;}
        if(enemies.empty()) continue;
        enemies[i]->Logic();
    }
}

void EnemyManager::Draw()
{
    for(unsigned int i=0; i<enemies.size(); ++i) {enemies[i]->Draw();}
}

void EnemyManager::AddEnemy(int type, double x, double y, double vx, double vy)
{
    enemies.push_back(std::unique_ptr<BasicEnemy>(new BasicEnemy(type, x, y, vx, vy)));
}

void EnemyManager::KillAllEnemies()
{
    enemies.clear();
}