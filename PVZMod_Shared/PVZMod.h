#pragma once
#ifndef _PVZMOD_PVZMOD_H_
#define _PVZMOD_PVZMOD_H_

#ifdef _WIN64
#error 暂不支持 64 位。
#endif

#include "Hook.h"
#include "PVZSTL.h"
#include <stack>
#include <functional>

BOOL WINAPI DllMain(HINSTANCE, DWORD, LPVOID);

/// 框架主命名空间。
/// 
/// 用于修改游戏的函数和类，以及游戏内原有的在 Sexy 命名空间或根命名空间内容，都放入 PVZMod 命名空间。
/// 
/// 使用本框架的改版，也可以将新增的内容放入 PVZMod 命名空间，或创建自己的命名空间，在此之中 `using namespace PVZMod`。
namespace PVZMod
{
	/// 提供对游戏的基本修改操作。
	///
	/// 在游戏运行前，需要对游戏代码进行修改。InitPatch 除了提供基本的修改接口，还可以标记一个函数为“补丁函数”。
	/// 
	/// 根据框架的设计理念，一切对代码的修改操作都应在游戏正式运行前完成，若一个函数的第一个参数为 InitPatch& patch，则代表这个函数为“补丁函数”，即对游戏代码进行修改的函数。
	/// 
	/// 即使一个函数对游戏代码的修改没有用到 InitPatch 提供的任何接口，也应该将第一个参数设置为 InitPatch& patch，用于说明这个函数会对游戏代码进行修改。
	class InitPatch
	{
	public:

		/// 提供基本的函数替换和插入代码操作。
		///
		/// @see Hook
		Hook& mHook;

		/// 用于标记补丁任务。
		/// 
		/// @param name			用于区分补丁任务的名称，通常为补丁函数的函数名。
		/// @param func			补丁任务函数，通常为 Lambda。
		/// @param once			为 true 则代表该名称的补丁任务只需要执行一次，第二次遇到相同名称的补丁任务时不再执行。
		/// @param throwOnTwice	为 true 则该名称补丁任务在第二次执行时抛出异常。
		void PatchTask(const std::string& name, const std::function<void()>& func, bool once = true, bool throwOnTwice = false);

	private:
		InitPatch();
		~InitPatch();
		
		static Hook* gHook;

		std::unordered_map<std::string, bool> mPatchMap;
		std::list<std::string> mPatchList;

		friend BOOL WINAPI ::DllMain(HINSTANCE, DWORD, LPVOID);
	};

	/// 【总入口点】补丁函数入口点。
	///
	/// 应在此函数中对游戏代码进行修改以及调用补丁函数。
	/// 
	/// 本函数中，可任意读写游戏的只读内存。
	void Main(InitPatch& patch);
}

extern "C" __declspec(dllexport) inline void exportfunc() {};

#endif // !_PVZMOD_PVZMOD_H_
