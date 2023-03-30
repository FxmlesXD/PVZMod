#pragma once
#ifndef _PVZMOD_MAGIC_BOARD_H_
#define _PVZMOD_MAGIC_BOARD_H_

#ifndef _PVZMOD_BOARD_H_
#error ������ #include <MagicBoard.h> ֮ǰ #include <Board.h> ��
#endif // !_PVZMOD_BOARD_H_

#include "Magic.h"
#include "SexyCommon.h"
#include <optional>

namespace PVZMod
{
	class InitPatch;
	class Board;
	class LawnApp;
	class ZombiePicker;
	enum GameMode;

	/// Board ħ����Ա��չ��
	///
	/// @see MagicBoard_Reference
	namespace MagicBoard
	{
		/// ע���������
		template <typename BaseClass>
		class RegisterManager
		{
		public:
			/// ������������ע��ؿ���
			///
			/// @tparam theLevelId	�ؿ���š�
			/// @tparam LevelClass	�ؿ��࣬�̳��� BaseClass���������幹�캯���������������麯�����Ǿ�̬��Ա������
			/// @param patch		��������
			template <GameMode theLevelId, typename LevelClass>
			static RegisterManager RegisterLevel(InitPatch& patch);
		};

		/// ������������Ϊ Board ��չħ����Ա��
		///
		/// @tparam T		һ���̳��� Board ���࣬�������幹�캯���������������麯����
		/// @param patch	��������
		template<typename T>
		RegisterManager<T> Extend(InitPatch& patch);

		void Binding_ExtendBase(InitPatch& patch, size_t theBoardSize, bool autoSaveExtendedData);

		using Constructor_t = Magic::BaseFunction<void(Board* _this, LawnApp* theApp)>;
		void Binding_MF_Constructor(InitPatch& patch, const std::function<void(Board* _this, LawnApp* theApp, Constructor_t& base)>& func);
		
		using Destructor_t = Magic::BaseFunction<void(Board* _this)>;
		void Binding_MF_Destructor(InitPatch& patch, const std::function<void(Board* _this, Destructor_t& base)>& func);

		using InitLevel_t = Magic::BaseFunction<void(Board* _this)>;
		void Binding_MF_InitLevel(InitPatch& patch, const std::function<void(Board* _this, InitLevel_t& base)>& func);

		using DisposeBoard_t = Magic::BaseFunction<void(Board* _this)>;
		void Binding_MF_DisposeBoard(InitPatch& patch, const std::function<void(Board* _this, DisposeBoard_t& base)>& func);

		using ZombiePicker_CalculateNumWaves_t = Magic::BaseFunction<void(Board* _this)>;
		void Binding_MF_ZombiePicker_CalculateNumWaves(InitPatch& patch, const std::function<void(Board* _this, ZombiePicker_CalculateNumWaves_t& base)>& func);

		using ZombiePicker_SpecialLevelPut_t = Magic::BaseFunction<bool(Board* _this, ZombiePicker& theZombiePicker, int theWave)>;
		void Binding_MF_ZombiePicker_SpecialLevelPut(InitPatch& patch, const std::function<bool(Board* _this, ZombiePicker& theZombiePicker, int theWave, ZombiePicker_SpecialLevelPut_t& base)>& func);

		using ZombiePicker_CalculateBasicPoints_t = Magic::BaseFunction<void(Board* _this, ZombiePicker& theZombiePicker, int theWave)>;
		void Binding_MF_ZombiePicker_CalculateBasicPoints(InitPatch& patch, const std::function<void(Board* _this, ZombiePicker& theZombiePicker, int theWave, ZombiePicker_CalculateBasicPoints_t& base)>& func);

		using ZombiePicker_PutBeforeMultiple_t = Magic::BaseFunction<void(Board* _this, ZombiePicker& theZombiePicker, int theWave)>;
		void Binding_MF_ZombiePicker_PutBeforeMultiple(InitPatch& patch, const std::function<void(Board* _this, ZombiePicker& theZombiePicker, int theWave, ZombiePicker_PutBeforeMultiple_t& base)>& func);

		using ZombiePicker_CalculateMultiplePoints_t = Magic::BaseFunction<void(Board* _this, ZombiePicker& theZombiePicker, int theWave)>;
		void Binding_MF_ZombiePicker_CalculateMultiplePoints(InitPatch& patch, const std::function<void(Board* _this, ZombiePicker& theZombiePicker, int theWave, ZombiePicker_CalculateMultiplePoints_t& base)>& func);

		using ZombiePicker_PutPreset_t = Magic::BaseFunction<void(Board* _this, ZombiePicker& theZombiePicker, int theWave)>;
		void Binding_MF_ZombiePicker_PutPreset(InitPatch& patch, const std::function<void(Board* _this, ZombiePicker& theZombiePicker, int theWave, ZombiePicker_PutPreset_t& base)>& func);

		using ZombiePicker_PutRandom_t = Magic::BaseFunction<void(Board* _this, ZombiePicker& theZombiePicker, int theWave)>;
		void Binding_MF_ZombiePicker_PutRandom(InitPatch& patch, const std::function<void(Board* _this, ZombiePicker& theZombiePicker, int theWave, ZombiePicker_PutRandom_t& base)>& func);

		extern int* mvOffsetXPtr, * mvOffsetYPtr;
		void Binding_mvOffset(InitPatch& patch, int* theOffsetXPtr, int* theOffsetYPtr);
	}
}

#include "MagicBoard.inl"

#endif // !_PVZMOD_MAGIC_BOARD_H_
