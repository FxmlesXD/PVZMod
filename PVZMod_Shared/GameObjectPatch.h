#pragma once
#ifndef _PVZMOD_GAME_OBEJCT_PATCH_H_
#define _PVZMOD_GAME_OBEJCT_PATCH_H_

namespace PVZMod
{
	class InitPatch;

	/// ��Ϸ������ز���
	namespace GameObjectPatch
	{
		/// �������������޸� Board �� ToolTipWidget ����ʾ���ꡣ
		///
		/// �޸��󣬶��� Board ������ı��Լ��丸�ؼ�������ı䣬ToolTipWidget ������ȷ�Ĺ��������ʾ��
		/// 
		/// ʵ�� Board ��ħ����Ա mvOffset* ����Զ����ô˺�����
		/// 
		/// @param patch ��������
		void FixBoardToolTipPos(InitPatch& patch);

		/// �������������޸� Board �й����ʽ���ж����ꡣ
		///
		/// �޸��󣬶��� Board ������ı��Լ��丸�ؼ�������ı䣬�����ʽ������ȷ�Ĺ�������ж���
		/// 
		/// ʵ�� Board ��ħ����Ա mvOffset* ����Զ����ô˺�����
		/// 
		/// @param patch ��������
		void FixBoardCursorPos(InitPatch& patch);

		/// �������������޸� Board �ж���������ж����ꡣ
		///
		/// �޸��󣬶��� Board ������ı��Լ��丸�ؼ�������ı䣬�������������ȷ�Ĺ��������ʾ��
		/// 
		/// ʵ�� Board ��ħ����Ա mvOffset* ����Զ����ô˺�����
		/// 
		/// @param patch ��������
		void FixBoardHighlightPos(InitPatch& patch);

		/// �������������� Board �е����� GameButton ��ֵ mParent��
		///
		/// @param patch ��������
		void FixBoardGameButtonParent(InitPatch& patch);

		/// �������������޸� Board �� CursorObject ����ʾ���ꡣ
		///
		/// �޸��󣬶��� Board ������ı��Լ��丸�ؼ�������ı䣬CursorObject ������ȷ�Ĺ��������ʾ��
		/// 
		/// ʵ�� Board ��ħ����Ա mvOffset* ����Զ����ô˺�����
		/// 
		/// @param patch ��������
		void FixCursorObjectPos(InitPatch& patch);
		
		/// �������������޸� Board �� CursorPreview ����ʾ���ꡣ
		///
		/// �޸��󣬶��� Board ������ı��Լ��丸�ؼ�������ı䣬CursorPreview ������ȷ�Ĺ��������ʾ��
		/// 
		/// ʵ�� Board ��ħ����Ա mvOffset* ����Զ����ô˺�����
		/// 
		/// @param patch ��������
		void FixCursorPreviewPos(InitPatch& patch);
	}
}

#endif // !_PVZMOD_GAME_OBEJCT_PATCH_H_
