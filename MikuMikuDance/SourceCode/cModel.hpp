#include "cKeyframe.hpp"
#include "cKeyframe.hpp"

#ifndef CMODEL_HPP
#define CMODEL_HPP

struct cModel_Vertex
{
	cVector3 Position;
	cVector3 Normal;
	cVector2 UV;
	unsigned __int16 BoneIndices[2];
	unsigned __int8 BoneWeight;
	bool HasEdge;
	char unk[2];
};

struct cModel_Material
{
	cVector3 Diffuse;
	float Opaque;
	cVector3 DiffuseCopy;
	float OpaqueCopy;
	cVector3 Specular;
	_BYTE gap2C[4];
	cVector3 Ambient;
	_BYTE gap3C[4];
	float Reflection;
	wchar_t TextureDiffuse[280];
	wchar_t TextureSphere[280];
	unsigned int NumberOfIndices;
	signed __int8 ToonNumber;
	bool HasEdge;
	_BYTE gap4AA[1097];
	char temp_end;
};

struct cModel
{
	_BYTE gap0[8];
	unsigned int NumberOfVertices;
	_BYTE gapC[28];
	unsigned int NumberOfIndices;
	_BYTE gap2C[4];
	unsigned int* Indices;
	unsigned int NumberOfMaterials;
	_BYTE gap3C[4];
	cModel_Material* Materials;
	_BYTE gap48[8824];
	char ModelName_Japanese[20];
	_BYTE gap22D4[80];
	char ModelDescription_Japanese[256];
	_BYTE gap2424[828];
	cModel_Vertex* Vertices;
	_BYTE gap2768[40];
	cKeyframe_Bone* KeyframeList_Bone;
	_BYTE gap2798[2424];
	DWORD field_3110;
	_BYTE gap31148[582];
	unsigned int NumberOfMorphs;
	unsigned int NumberOfBones;
	_BYTE gap3114[5];
	char IsDisplayOn;
	_BYTE gap311A[1094];
	bool IsEnglishModeOn;
	_BYTE gap35610[95586];
	char temp;
	
	float CalculateBoneInterpolationFactor(
		BoneInterpolationType type, int index, float linear
	);
};

#endif // !CMODEL_HPP
