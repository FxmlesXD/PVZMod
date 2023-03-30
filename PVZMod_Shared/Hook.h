#pragma once
#ifndef _PVZMOD_HOOK_H_
#define _PVZMOD_HOOK_H_

#include <Windows.h>

namespace PVZMod
{
	/// �ṩ�����ĺ����滻�Ͳ�����������
	class Hook
	{
	private:
		HANDLE mHeap;
	public:
		Hook();
		~Hook();
		
		/// �滻������
		///
		/// @param pFunction	Ҫ�滻�ĺ�����ָ�롣
		/// @param pDetour		�滻�ɴ�ָ��ָ��ĺ�����
		/// @return				���ڵ���ԭʼ������ָ�롣
		void* HookFunction(void* pFunction, void* pDetour);

		/// �Ĵ����ṹ��
		struct Regs
		{
			DWORD efl;
			DWORD edi;
			DWORD esi;
			DWORD ebp;
			DWORD esp;
			DWORD ebx;
			DWORD edx;
			DWORD ecx;
			DWORD eax;
		};

		/// �������ĺ������͡�
		using InsertCodeFunc = void(__stdcall*)(Regs*);

		/// ������롣
		///
		/// ����ָ��λ�ò��� jmp ָ����ת��������Ĵ��룬������ jmp ���ǵ���ָ���һ����ִ�������Ĵ���󷵻ص����ݵ�ָ���������ԭ���ĵ�ַ��
		/// 
		/// @param address				����ĵ�ַ��
		/// @param code					����Ĵ��롣
		/// @param trampolineOffset		���ص����ݵ�ָ�ʱƫ�Ƶ��ֽڡ�
		void InsertCode(void* address, InsertCodeFunc code, int trampolineOffset = 0);

		/// ������룬ִ�к���ת��ָ����ַ��
		/// 
		/// ����ָ��λ�ò��� jmp ָ����ת��������Ĵ��룬ִ�������Ĵ������ת��ָ��λ�á�
		/// 
		/// @param address				����ĵ�ַ��
		/// @param jmpAddress			���صĵ�ַ��
		/// @param code					����Ĵ��롣
		void InsertCodeAndJump(void* address, void* jmpAddress, InsertCodeFunc code);

		/// ִ�л�� cmp ָ��Ĳ�����
		/// 
		/// @param num1	��һ��������
		/// @param num2	�ڶ���������
		/// @return		ִ�к� efl �Ĵ�����ֵ��
		static DWORD cmp(DWORD num1, DWORD num2);

		/// ִ�л�� test ָ��Ĳ�����
		/// 
		/// @param num1	��һ��������
		/// @param num2	�ڶ���������
		/// @return		ִ�к� efl �Ĵ�����ֵ��
		static DWORD test(DWORD num1, DWORD num2);
	};
}

#endif // !_PVZMOD_HOOK_H_
