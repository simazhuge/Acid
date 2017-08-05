﻿#pragma once

#include <vector>
#include <GL/glew.h>

#include "../loaders/loaders.h"
#include "../maths/vector3.h"
#include "../maths/matrix4x4.h"
#include "../noise/noiseperlin.h"
#include "../physics/aabb.h"
#include "../models/model.h"
#include "biome.h"

namespace flounder
{
	class terrain
	{
	private:
		noiseperlin *m_noise;

		model *m_model;

		vector3 *m_position;
		vector3 *m_rotation;
		bool m_moved;

		matrix4x4 *m_modelMatrix;
		aabb *m_aabb;
	public:
		static const float SQUARE_SIZE;
		static const int VERTEX_COUNT;
		static const float SIDE_LENGTH;

		terrain(const vector3 &position, const vector3 &rotation, const int &seed);

		~terrain();

		void update();
	private:
		void generateMesh();

		void storeQuad1(std::vector<GLint> *indices, const int &topLeft, const int &topRight, const int &bottomLeft, const int &bottomRight, const bool &mixed);

		void storeQuad2(std::vector<GLint> *indices, const int &topLeft, const int &topRight, const int &bottomLeft, const int &bottomRight, const bool &mixed);

		vector3 calculateNormal(const float &x, const float &z);

		colour getBiomeColour(const float &x, const float &z);

		float getFactorIsland(const float &x, const float &z);

		float getFactorMoisture(const float & x, const float & y, const float & z);
	public:
		float getHeight(const float &x, const float &z);

		model *getModel() const { return m_model; }

		vector3 *getPosition() const { return m_position; }

		void setPosition(const vector3 &position);

		vector3 *getRotation() const { return m_rotation; }

		void setRotation(const vector3 &rotation);

		matrix4x4 *getModelMatrix() const { return m_modelMatrix; }

		aabb *getAabb() const { return m_aabb; }
	};
}