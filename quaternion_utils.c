#include "fdf.h"

t_quaternion	quaternion_add(t_quaternion quaternion1, t_quaternion quaternion2)
{
	t_quaternion	new;

	new.w = quaternion1.w + quaternion2.w;
	new.x = quaternion1.x + quaternion2.x;
	new.y = quaternion1.y + quaternion2.y;
	new.z = quaternion1.z + quaternion2.z;
	return (new);
}

double	quaternion_dotprod(t_quaternion quaternion1, t_quaternion quaternion2)
{
	return (quaternion1.w * quaternion2.w
			+ quaternion1.x * quaternion2.x
			+ quaternion1.y * quaternion2.y
			+ quaternion1.z * quaternion2.z);
}

double	quaternion_angle_between(t_quaternion quaternion1, t_quaternion quaternion2)
{
	return (2 * acos(fabs(quaternion_dotprod(quaternion1, quaternion2))));
}

t_quaternion	quaternion_new(int x, int y, int z, int w)
{
	return ((t_quaternion){x, y, z, w});
}