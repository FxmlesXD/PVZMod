#pragma once

#error ���ļ������ڲο�����Ҫ����

#include "MagicMusic.h"
#include "Music.h"

namespace PVZMod
{
	/// MagicMusic ħ����Ա�ο���
	///
	/// �������ڲο� MagicMusic ħ����Ա�Ķ��巽ʽ���÷�����Ҫֱ��ʹ�ñ��ࡣ
	class MagicMusic_Reference :public Music
	{
	public:
		/// ���캯����
		MagicMusic_Reference();

		/// ����������
		~MagicMusic_Reference();

		/// �������֡�
		///
		/// @param theMusicTune		���ֱ�š�
		/// @param theOffset		���ֽ��ȣ�Ϊ -1 ���ͷ���š�
		/// @param theDrumsOffset	��������ȡ�
		/// @param base				ԭʼ������
		void MF_PlayMusic(MusicTune theMusicTune, int theOffset, int theDrumsOffset, MagicMusic::PlayMusic_t& base);
	};
}