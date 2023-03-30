#pragma once

#error ���ļ������ڲο�����Ҫ����

#include "LawnApp.h"
#include "MagicLawnApp.h"

namespace PVZMod
{
	/// MagicLawnApp ħ����Ա�ο���
	///
	/// �������ڲο� MagicLawnApp ħ����Ա�Ķ��巽ʽ���÷�����Ҫֱ��ʹ�ñ��ࡣ
	class MagicLawnApp_Reference :public LawnApp
	{
	public:
		/// ���캯����
		/// 
		/// @param base		ԭʼ������
		void MF_Constructor(MagicLawnApp::Constructor_t& base);

		/// ����������
		///
		/// @param base		ԭʼ������
		void MF_Destructor(MagicLawnApp::Destructor_t& base);

		/// ��ʼ��������
		/// 
		/// �ڴ˺����н��л����ĳ�ʼ����
		/// 
		/// ע�⣺��Ҫ����һ��ʱ��ļ��ز��������� MF_LoadingThreadProc �н��С�
		/// 
		/// @param base ԭʼ������
		void MF_Init(MagicLawnApp::Init_t& base);

		/// �����̺߳�����
		/// 
		/// �ڴ˺����н��к�ʱ�ļ��ز������������ͼ������ʱ TitleScreen ����ʾ��������
		/// 
		/// @param base ԭʼ������
		void MF_LoadingThreadProc(MagicLawnApp::LoadingThreadProc_t& base);

		/// ������Ϻ�����
		/// 
		/// ��� TitleScreen �п�ʼ��Ϸ��ťʱ��ִ�б�������
		/// 
		/// @param base ԭʼ������
		void MF_LoadingCompleted(MagicLawnApp::LoadingCompleted_t& base);

		/// �ڹر���Ϸʱ�ͷ���Դ��
		/// 
		/// @param base ԭʼ������
		void MF_Shutdown(MagicLawnApp::Shutdown_t& base);

		/// ����Ϸ���ڵ���Ϣ���д���
		/// 
		/// ����������Ϊ��̬����Ϊ��̬ʱ this ָ�����Ϊ nullptr��
		/// 
		/// @param hwnd		���ھ����
		/// @param uMsg		��Ϣ���͡�
		/// @param wParam	��Ϣ�ĵ�һ��������
		/// @param lParam	��Ϣ�ĵڶ���������
		/// @param base		ԭʼ������
		/// @return			��Ϣ��������
		/// 
		/// @see			<https://learn.microsoft.com/en-us/windows/win32/api/winuser/nc-winuser-wndproc>
		LRESULT MF_WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam, MagicLawnApp::WindowProc_t& base);


		/// ȫ�ֶԻ���������
		static const int MC_NUM_DIALOGS;

		/// ����ȫ�ֶԻ���İ�ť�����
		/// 
		/// @param theId	�Ի��� id��
		/// @param isYes	Ϊ true ������ȷ�������ǡ���ť��Ϊ false ������ȡ�����򡰷񡱰�ť��
		/// @param base		ԭʼ������
		void MF_DialogButtonDepress(int theId, bool isYes, MagicLawnApp::DialogButtonDepress_t& base);

		/// �Ƿ�ʹ�ö�ռȫ����
		/// 
		/// Ϊ true ʱʹ�ö�ռȫ����Ϊ false ʱʹ���ޱ߿򴰿�ȫ������Ĭ��Ϊ true��
		static bool mvExclusiveFullscreen;

		/// �Զ��޸����������
		///
		/// Ϊ true ʱ���ؽ����ڽ��Զ��޸������������Ĭ��Ϊ false��
		static bool mvAutoFixAspectRatio;

		/// �����Ƿ�������š�
		///
		/// Ϊ true ʱ���ڿ������ţ��ı��ֵ��Ҫ�ؽ����ں���Ч����Ĭ��Ϊ false��
		static bool mvWindowCanResize;
	};
}
