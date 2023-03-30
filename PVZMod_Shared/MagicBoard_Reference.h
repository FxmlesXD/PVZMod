#pragma once

#error ���ļ������ڲο�����Ҫ����

#include "Board.h"
#include "MagicBoard.h"

namespace PVZMod
{
	/// MagicBoard ħ����Ա�ο���
	///
	/// @code{.cpp}
	/// #include <MagicBoard.h>
	/// 
	/// using namespace PVZMod;
	/// 
	/// void PVZMod::Main(InitPatch& patch)
	/// {
	///		MagicBoard::Extend<MagicBoard_Main>(patch)											// �滻���ࡣ
	///			.RegisterLevel<(GameMode)100, MagicBoard_Level>(patch)							// ע�ᵥ���ࡣ
	///			.RegisterLevel<(GameMode)100, MagicBoard_Level2>(patch)							// һ���ؿ�����ע�����࣬�����յ�����á�
	///			.RegisterLevel<(GameMode)101, MagicBoard_Level>(patch)							// ����ؿ�����ʹ��һ���ࡣ
	///			.RegisterLevel<GAMEMODE_SURVIVAL_NORMAL_STAGE_1, MagicBoard_Level>(patch);		// ����Ϊԭ��ؿ�ע���ࡣ
	/// }
	/// @endcode
	namespace MagicBoard_Reference
	{
		/// MagicBoard ���ࡣ
		class MagicBoard_Main :public Board
		{
		public:
			/// ���캯����
			/// 
			/// @param theApp	��Ϸ�������
			/// @param base		ԭʼ������
			void MF_Constructor(LawnApp* theApp, MagicBoard::Constructor_t& base);

			/// ����������
			///
			/// @param base		ԭʼ������
			void MF_Destructor(MagicBoard::Destructor_t& base);

			/// �ؿ���Ϣ��ʼ����
			///
			/// @param base		ԭʼ������
			void MF_InitLevel(MagicBoard::InitLevel_t& base);

			/// �ͷ������Դ��
			///
			/// @param base		ԭʼ������
			void MF_DisposeBoard(MagicBoard::DisposeBoard_t& base);

			/// ���ּ��� - ���㲨����
			///
			/// ����������� mNumWaves �С�
			/// 
			/// @param base		ԭʼ������
			void MF_ZombiePicker_CalculateNumWaves(MagicBoard::ZombiePicker_CalculateNumWaves_t& base);

			/// ���ּ��� - �������ؿ���������Ľ�ʬ���ò�����
			///
			/// @param theZombiePicker	���ּ�����Ϣ��
			/// @param theWave			��ǰ������
			/// @param base				ԭʼ������
			/// @return					���Ϊ true����ִ����ͨ�ؿ��ĳ�����ּ��������
			bool MF_ZombiePicker_SpecialLevelPut(ZombiePicker& theZombiePicker, int theWave, MagicBoard::ZombiePicker_SpecialLevelPut_t& base);

			/// ���ּ��� - ���㱾���������ֵ�����
			/// 
			/// ����������� mZombiePoints.mZombiePoints �С�
			/// 
			/// @param theZombiePicker	���ּ�����Ϣ��
			/// @param theWave			��ǰ������
			/// @param base				ԭʼ������
			void MF_ZombiePicker_CalculateBasicPoints(ZombiePicker& theZombiePicker, int theWave, MagicBoard::ZombiePicker_CalculateBasicPoints_t& base);

			/// ���ּ��� - �ڳ��ֵ����ӱ�֮ǰ���н�ʬ���ò�����
			///
			/// ��ԭ���У��������ڷ������Ĳ������⽩ʬ��
			/// 
			/// @param theZombiePicker	���ּ�����Ϣ��
			/// @param theWave			��ǰ������
			/// @param base				ԭʼ������
			void MF_ZombiePicker_PutBeforeMultiple(ZombiePicker& theZombiePicker, int theWave, MagicBoard::ZombiePicker_PutBeforeMultiple_t& base);

			/// ���ּ��� - ���ݹؿ���ͬ��������ֵ���������
			///
			/// ���������ֵ����˱����Ľ������� mZombiePoints.mZombiePoints �С�
			/// 
			/// @param theZombiePicker	���ּ�����Ϣ��
			/// @param theWave			��ǰ������
			/// @param base				ԭʼ������
			void MF_ZombiePicker_CalculateMultiplePoints(ZombiePicker& theZombiePicker, int theWave, MagicBoard::ZombiePicker_CalculateMultiplePoints_t& base);

			/// ���ּ��� - ���ùؿ�Ԥ�轩ʬ��
			/// 
			/// @param theZombiePicker	���ּ�����Ϣ��
			/// @param theWave			��ǰ������
			/// @param base				ԭʼ������
			void MF_ZombiePicker_PutPreset(ZombiePicker& theZombiePicker, int theWave, MagicBoard::ZombiePicker_PutPreset_t& base);

			/// ���ּ��� - ���������ʬ��
			/// 
			/// @param theZombiePicker	���ּ�����Ϣ��
			/// @param theWave			��ǰ������
			/// @param base				ԭʼ������
			void MF_ZombiePicker_PutRandom(ZombiePicker& theZombiePicker, int theWave, MagicBoard::ZombiePicker_PutRandom_t& base);

			/// Board ƫ�� X ���ꡣ
			static int mvOffsetX;

			/// Board ƫ�� Y ���ꡣ
			static int mvOffsetY;

			/// Ϊ true ���Զ��洢��չ�����ݡ���Ĭ��Ϊ false��
			static const bool MC_AUTO_SAVE_EXTENDED_DATA;
		};

		/// MagicBoard �����ؿ��ࡣ
		///
		/// ע�⣺�����಻����ӳ�Ա������������������ӡ�
		class MagicBoard_Level :public MagicBoard_Main
		{
		public:
			/// ���캯����
			/// 
			/// @param theApp	��Ϸ�������
			/// @param base		ԭʼ������
			void MF_Constructor(LawnApp* theApp, MagicBoard::Constructor_t& base);

			/// ����������
			///
			/// @param base		ԭʼ������
			void MF_Destructor(MagicBoard::Destructor_t& base);

			/// �ؿ���Ϣ��ʼ����
			///
			/// @param base		ԭʼ������
			void MF_InitLevel(MagicBoard::InitLevel_t& base);

			/// �ͷ������Դ��
			///
			/// @param base		ԭʼ������
			void MF_DisposeBoard(MagicBoard::DisposeBoard_t& base);

			/// ���ּ��� - ���㲨����
			///
			/// ����������� mNumWaves �С�
			/// 
			/// @param base		ԭʼ������
			void MF_ZombiePicker_CalculateNumWaves(MagicBoard::ZombiePicker_CalculateNumWaves_t& base);

			/// ���ּ��� - �������ؿ���������Ľ�ʬ���ò�����
			///
			/// @param theZombiePicker	���ּ�����Ϣ��
			/// @param theWave			��ǰ������
			/// @param base				ԭʼ������
			/// @return					���Ϊ true����ִ����ͨ�ؿ��ĳ�����ּ��������
			bool MF_ZombiePicker_SpecialLevelPut(ZombiePicker& theZombiePicker, int theWave, MagicBoard::ZombiePicker_SpecialLevelPut_t& base);

			/// ���ּ��� - ���㱾���������ֵ�����
			/// 
			/// ����������� mZombiePoints.mZombiePoints �С�
			/// 
			/// @param theZombiePicker	���ּ�����Ϣ��
			/// @param theWave			��ǰ������
			/// @param base				ԭʼ������
			void MF_ZombiePicker_CalculateBasicPoints(ZombiePicker& theZombiePicker, int theWave, MagicBoard::ZombiePicker_CalculateBasicPoints_t& base);

			/// ���ּ��� - �ڳ��ֵ����ӱ�֮ǰ���н�ʬ���ò�����
			///
			/// ��ԭ���У��������ڷ������Ĳ������⽩ʬ��
			/// 
			/// @param theZombiePicker	���ּ�����Ϣ��
			/// @param theWave			��ǰ������
			/// @param base				ԭʼ������
			void MF_ZombiePicker_PutBeforeMultiple(ZombiePicker& theZombiePicker, int theWave, MagicBoard::ZombiePicker_PutBeforeMultiple_t& base);

			/// ���ּ��� - ���ݹؿ���ͬ��������ֵ���������
			///
			/// ���������ֵ����˱����Ľ������� mZombiePoints.mZombiePoints �С�
			/// 
			/// @param theZombiePicker	���ּ�����Ϣ��
			/// @param theWave			��ǰ������
			/// @param base				ԭʼ������
			void MF_ZombiePicker_CalculateMultiplePoints(ZombiePicker& theZombiePicker, int theWave, MagicBoard::ZombiePicker_CalculateMultiplePoints_t& base);

			/// ���ּ��� - ���ùؿ�Ԥ�轩ʬ��
			/// 
			/// @param theZombiePicker	���ּ�����Ϣ��
			/// @param theWave			��ǰ������
			/// @param base				ԭʼ������
			void MF_ZombiePicker_PutPreset(ZombiePicker& theZombiePicker, int theWave, MagicBoard::ZombiePicker_PutPreset_t& base);

			/// ���ּ��� - ���������ʬ��
			/// 
			/// @param theZombiePicker	���ּ�����Ϣ��
			/// @param theWave			��ǰ������
			/// @param base				ԭʼ������
			void MF_ZombiePicker_PutRandom(ZombiePicker& theZombiePicker, int theWave, MagicBoard::ZombiePicker_PutRandom_t& base);
		};

	}
}