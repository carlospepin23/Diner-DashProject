#pragma once

#include "Entity.h"
#include "Client.h"
#include "Inspector.h"

class EntityManager {

private:
int clientsMad=0;

public:
	Client* firstClient;
	void tick();
	void render();
	void addEntity(Entity *e);
	void addClient(Client *c);
	void removeLeavingClients();
	std::vector<Entity*> entities;
	int getClientsMad();
};