#include "BuffManager.h"


BuffManager::BuffManager()
{

}

void BuffManager::addBuff(Buff* buff, GameObject *owner)
{
	buffsArray.push_back(buff);
	buff->onBuffStart(owner);
}

void BuffManager::update(float deltaTime, GameObject *owner)
{
	for (int i = 0; i != buffsArray.size(); i++)
	{
		buffsArray[i]->update(deltaTime);
		if (buffsArray[i]->isOverTime())
		{
			buffsArray[i]->onBuffEnd(owner);
			buffsArray.erase(buffsArray.begin() + i);
			std::cout << "erasing" << std::endl;
			break;
		}
	}
}


BuffManager::~BuffManager()
{
}
