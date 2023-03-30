#pragma once
#ifndef _PVZMOD_GAME_UI_PATCH_H_
#define _PVZMOD_GAME_UI_PATCH_H_

namespace PVZMod
{
	class InitPatch;

	/// ��Ϸ������ز�����
	namespace GameUIPatch
	{
		/// �������������滻���˵���
		/// 
		/// @tparam T		һ���̳��� GameSelector ���࣬���Զ��幹�캯��������������������д�麯����
		/// @param patch	��������
		template<typename T>
		void ReplaceGameSelector(InitPatch& patch);

		/// �������������滻������档
		/// 
		/// @tparam T		һ���̳��� TitleScreen ���࣬���Զ��幹�캯��������������������д�麯����
		/// @param patch	��������
		template<typename T>
		void ReplaceTitleScreen(InitPatch& patch);

		/// �������������滻ѡ�ؽ��档
		/// 
		/// @tparam T		һ���̳��� ChallengeScreen ���࣬���Զ��幹�캯��������������������д�麯����
		/// @param patch	��������
		template<typename T>
		void ReplaceChallengeScreen(InitPatch& patch);
	}
}

#include "GameUIPatch.inl"

#endif // !_PVZMOD_GAME_UI_PATCH_H_
