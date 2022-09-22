#include "pch.h"
#include "AgentHelper.h"
#include <directxmath.h>
#include <math.h>

namespace Engine
{
	using namespace DirectX;

    /*
    getEuler(matrix44 trm)
    {
        vector3 euler;
        // Assuming the angles are in radians.
        if (trm.m[1][0] > 0.998f)
        {
            // singularity at north pole
            euler.y = n_atan2(trm.m[0][2], trm.m[2][2]);
            euler.z = PI / 2.f;
            euler.x = 0.f;
            return rad2deg(euler);
        }
        if (trm.m[1][0] < -0.998f)
        {
            // singularity at south pole
            euler.y = n_atan2(trm.m[0][2], trm.m[2][2]);
            euler.z = -PI / 2;
            euler.x = 0;

            return rad2deg(euler);
        }

        euler.y = n_atan2(-trm.m[2][0], trm.m[0][0]);
        euler.x = n_atan2(-trm.m[1][2], trm.m[1][1]);
        euler.z = n_asin(trm.m[1][0]);

        return rad2deg(euler);
    }
    */

	Vector3 AgentHelper::rotationFromDirection(Vector3 direction, Vector3 position, Vector3 up)
	{

        float oZ_angle;

        if (direction.x > 0)
        {
            oZ_angle = asin(direction.x);
        }

        if (direction.x <= 0)
        {
            oZ_angle = XM_2PI - asin(-direction.x);
        }

        return Vector3(0, 0, oZ_angle);



        /*
        XMMATRIX m = XMMatrixLookToLH(
            XMVectorSet(position.x, position.y, position.z, 1),
            XMVectorSet(direction.x, direction.y, direction.z, 1),
            XMVectorSet(up.x, up.y, up.z, 1)
        );

        XMVECTOR scale, rotation, pos;
        XMMatrixDecompose(&scale, &rotation, &pos, m);

        XMMATRIX rotM = XMMatrixRotationQuaternion(rotation);

        //rotM = XMMatrixTranspose(rotM);

        XMFLOAT4X4 trm;
        XMStoreFloat4x4(&trm, rotM);

        Vector3 euler;

        /*
        
        float sy = sqrt(trm._11 * trm._11 + trm._21 * trm._21);
        bool singular = sy < 0.00001f;
        float x, y, z;

        if (singular)
        {
        
            euler.x = atan2(trm._32, trm._33);
            euler.y = atan2(-trm._31, sy);
            euler.z = atan2(trm._21, trm._11);
        }
        else
        {
            euler.x = atan2(-trm._23, trm._22);
            euler.y = atan2(-trm._31, sy);
            euler.z = 0;
        }

        
        */

        
        /*
        
        if (trm._11 == 1.0f)
        {
            return Vector3(-atan2f(trm._13, trm._34), 0,0);
        }
        else if (trm._11 == -1.0f)
        {
            return Vector3(-atan2f(trm._13, trm._34), 0, 0);
        }
        else
        {
            return Vector3(-atan2(-trm._31, trm._11), -asin(trm._21), -atan2(-trm._23, trm._22));
        }
        */

        /*

        // Assuming the angles are in radians.
        if (trm.m[1][0] > 0.998f)
        {
            // singularity at north pole
            euler.y = atan2f(trm.m[0][2], trm.m[2][2]);
            euler.z = XM_PI / 2.f;
            euler.x = 0.f;

            

            return euler;
        }
        if (trm.m[1][0] < -0.998f)
        {
            // singularity at south pole
            euler.y = atan2f(trm.m[0][2], trm.m[2][2]);
            euler.z = -XM_PI / 2;
            euler.x = 0;

            
            return euler;
        }

        euler.y = atan2f(-trm.m[2][0], trm.m[0][0]);
        euler.x = atan2f(-trm.m[1][2], trm.m[1][1]);
        euler.z = asinf(trm.m[1][0]);

        return euler;
        

        /*


    void GetRotation(float& Yaw, float& Pitch, float& Roll)
    {

    }
        union {
            struct
            {
                float        _11, _12, _13, _14;
                float        _21, _22, _23, _24;
                float        _31, _32, _33, _34;
                float        _41, _42, _43, _44;
            };
            float m[4][4];
            float m2[16];
        };


        if (_11 == 1.0f)
        {
            Yaw = atan2f(_13, _34);
            Pitch = 0;
            Roll = 0;

        }
        else if (_11 == -1.0f)
        {
            Yaw = atan2f(_13, _34);
            Pitch = 0;
            Roll = 0;
        }
        else
        {

            Yaw = atan2(-_31, _11);
            Pitch = asin(_21);
            Roll = atan2(-_23, _22);
        }

        */
	}
	
}