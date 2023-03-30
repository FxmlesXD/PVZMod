#pragma once
#ifndef _PVZMOD_WIDGET_PATCH_H
#define _PVZMOD_WIDGET_PATCH_H

namespace PVZMod
{
	class InitPatch;

	/// �ؼ���ز�����
	namespace WidgetPatch
	{
		// �޸� GameButton �ĵ�����꣬�ݹ�ȡ mParent ���꣬�� mParent Ϊ Board������� MagicBoard::mvOffsetXPtr��MagicBoard::mvOffsetYPtr��

		/// �������������޸� GameButton ����ж�����
		///
		/// ԭ���У�GameButton ֻ����� mParent �����꣬������ݹ�ȡ mParent �ĸ��ؼ������꣬���µ���ж�����ȷ���˲������޸�������⡣
		/// 
		/// ʵ�� Board ��ħ����Ա mvOffset* ����Զ����ô˺�����
		/// 
		/// @param patch ��������
		void FixGameButtonClickPos(InitPatch& patch);
	}
}

#endif // !_PVZMOD_WIDGET_PATCH_H
