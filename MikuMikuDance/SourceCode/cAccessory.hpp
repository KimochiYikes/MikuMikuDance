#ifndef CACCESSORY_HPP
#define CACCESSORY_HPP

struct cAccessory {
	_BYTE gap0[544];
	bool IsDisplayOn;
	cVector3 Position;
	cVector3 Radians;
	float Scale;
	int FollowModel;
	int FollowBone;
	_BYTE gap248[612];
	bool IsShadowOn;
	float Transparency;
	unsigned int NumberOfMaterials;
};


#endif // !CACCESSORY_HPP
