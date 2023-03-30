#pragma once

#error ���ļ������ڲο�����Ҫ����

#include "MagicPlant.h"

namespace PVZMod
{
	/// MagicPlant ħ����Ա�ο���
	namespace MagicPlant_Reference
	{
		class MagicPlant_Main :public Plant
		{
		public:
			/// ֲ���ʼ�� - ��ʼ����Ա������
			///
			/// @param theGridX			������
			/// @param theGridY			������
			/// @param theSeedType		ֲ�����͡�
			/// @param theImitaterType	ģ�������͡�
			/// @param base				ԭʼ������
			/// @return					ֲ�ﶨ����Ϣ��
			PlantDefinition& MF_PlantInitialize_InitMemberVariable(int theGridX, int theGridY, SeedType theSeedType, SeedType theImitaterType, MagicPlant::PlantInitialize_InitMemberVariable_t& base);

			/// ֲ���ʼ�� - ��ʼ��������
			///
			/// @param thePlantDef	ֲ�ﶨ����Ϣ��
			/// @param base			ԭʼ������
			/// @return				���嶯��ָ�롣
			Reanimation* MF_PlantInitialize_InitReanimation(PlantDefinition& thePlantDef, MagicPlant::PlantInitialize_InitReanimation& base);

			/// ֲ���ʼ�� - ��Բ�ֲͬ�����ͳ�ʼ��֮ǰ��
			///
			/// @param thePlantDef		ֲ�ﶨ����Ϣ��
			/// @param theBodyReanim	ֲ�����嶯����
			/// @param base				ԭʼ������
			void MF_PlantInitialize_BeforeInitType(PlantDefinition& thePlantDef, Reanimation* theBodyReanim, MagicPlant::PlantInitialize_BeforeInitType& base);

			/// ֲ���ʼ�� - ��Բ�ֲͬ�����ͳ�ʼ����
			///
			/// @param thePlantDef		ֲ�ﶨ����Ϣ��
			/// @param theBodyReanim	ֲ�����嶯����
			/// @param base				ԭʼ������
			void MF_PlantInitialize_InitType(PlantDefinition& thePlantDef, Reanimation* theBodyReanim, MagicPlant::PlantInitialize_InitType& base);

			/// ֲ���ʼ�� - ��Բ�ֲͬ�����ͳ�ʼ��֮��
			///
			/// @param thePlantDef		ֲ�ﶨ����Ϣ��
			/// @param theBodyReanim	ֲ�����嶯����
			/// @param base				ԭʼ������
			void MF_PlantInitialize_AfterInitType(PlantDefinition& thePlantDef, Reanimation* theBodyReanim, MagicPlant::PlantInitialize_AfterInitType& base);

			/// ֲ�� DataArray ��С��
			static const size_t MC_DATA_ARRAY_SIZE;
		};

		class MagicPlant_Plant :public MagicPlant_Main
		{
		public:
			/// ֲ���ʼ�� - ��ʼ����Ա������
			///
			/// @param theGridX			������
			/// @param theGridY			������
			/// @param theSeedType		ֲ�����͡�
			/// @param theImitaterType	ģ�������͡�
			/// @param base				ԭʼ������
			/// @return					ֲ�ﶨ����Ϣ��
			PlantDefinition& MF_PlantInitialize_InitMemberVariable(int theGridX, int theGridY, SeedType theSeedType, SeedType theImitaterType, MagicPlant::PlantInitialize_InitMemberVariable_t& base);

			/// ֲ���ʼ�� - ��ʼ��������
			///
			/// @param thePlantDef	ֲ�ﶨ����Ϣ��
			/// @param base			ԭʼ������
			/// @return				���嶯��ָ�롣
			Reanimation* MF_PlantInitialize_InitReanimation(PlantDefinition& thePlantDef, MagicPlant::PlantInitialize_InitReanimation& base);

			/// ֲ���ʼ�� - ��Բ�ֲͬ�����ͳ�ʼ��֮ǰ��
			///
			/// @param thePlantDef		ֲ�ﶨ����Ϣ��
			/// @param theBodyReanim	ֲ�����嶯����
			/// @param base				ԭʼ������
			void MF_PlantInitialize_BeforeInitType(PlantDefinition& thePlantDef, Reanimation* theBodyReanim, MagicPlant::PlantInitialize_BeforeInitType& base);

			/// ֲ���ʼ�� - ��Բ�ֲͬ�����ͳ�ʼ����
			///
			/// @param thePlantDef		ֲ�ﶨ����Ϣ��
			/// @param theBodyReanim	ֲ�����嶯����
			/// @param base				ԭʼ������
			void MF_PlantInitialize_InitType(PlantDefinition& thePlantDef, Reanimation* theBodyReanim, MagicPlant::PlantInitialize_InitType& base);

			/// ֲ���ʼ�� - ��Բ�ֲͬ�����ͳ�ʼ��֮��
			///
			/// @param thePlantDef		ֲ�ﶨ����Ϣ��
			/// @param theBodyReanim	ֲ�����嶯����
			/// @param base				ԭʼ������
			void MF_PlantInitialize_AfterInitType(PlantDefinition& thePlantDef, Reanimation* theBodyReanim, MagicPlant::PlantInitialize_AfterInitType& base);
		};
	}
}