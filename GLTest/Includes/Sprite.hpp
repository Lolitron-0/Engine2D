#pragma once
#include <GLFW/glfw3.h>
#include "Vector2.hpp"
#include "Utils.hpp"
#include <iostream>
#include <vector>
#include <Gameobject.hpp>
#include <Vector2.hpp>

class Sprite
{
public:

    Sprite(GameObject *thisObject, string path, vector<Vector2> vertices)
    {
        mSpriteClient = thisObject;
        mPathToTexture = path;
        mVertices = vertices;
    }

    void setVertices(vector<Vector2> vertices)
    {
        mVertices = vertices;
    }

private:

    vector<Vector2> mVertices;
    string mPathToTexture;
    // TODO: rename
	std::shared_ptr<GameObject> mSpriteClient;
};
