#pragma once
#ifndef _PVZMOD_MAGIC_ZOMBIE_H_
#define _PVZMOD_MAGIC_ZOMBIE_H_

#include "Magic.h"

namespace PVZMod
{
	class InitPatch;
	class Zombie;

	/// Zombie ħ����Ա��չ��
	///
	/// @see MagicZombie_Reference
	namespace MagicZombie
	{
		/// ������������Ϊ Zombie ��չħ����Ա��
		///
		/// @tparam T		һ���̳��� Zombie ���࣬�������幹�캯���������������麯����
		/// @param patch	��������
		template <typename T>
		void Extend(InitPatch& patch);

		void Binding_ExtendBase(InitPatch& patch, size_t theZombieSize, size_t theDataArraySize);
	}
}

#include "MagicZombie.inl"

#endif // !_PVZMOD_MAGIC_ZOMBIE_H_
