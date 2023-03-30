#pragma once
#ifndef _PVZMOD_RESOURCE_PATCH_H_
#define _PVZMOD_RESOURCE_PATCH_H_

#include "PVZSTL.h"
#include <Windows.h>

namespace PVZMod
{
	class InitPatch;
	class ResourceManager;

	namespace ImageLib
	{
		class Image;
	}

	namespace ResourcePatch
	{
		/*class ImageLoader
		{
		public:
			void PatchImageLoader(InitPatch& patch);

			virtual ImageLib::Image* GetImage(const std::string& thePath, const std::string& theName, const std::string& theExt, bool lookForAlphaImage);

			ImageLib::Image* LoadAlphaImage(const std::string& thePath, const std::string& theName, ImageLib::Image* theImage);

			template<typename T>
			bool TryImageExt(const std::string& thePath, const std::string& theName, const std::string& theExt, const std::string& theTargetExt, T func);
		private:
			static ImageLoader* gImageLoader;
			using GetImage_t = ImageLib::Image* (*)(const String& theFileName, bool lookForAlphaImage);
			static GetImage_t gRawGetImage;
		};*/


		// ���µ� xml ��Դ�ļ���������б���Ҫ������ ResourceGen ���ɵĴ����е� ExtractResourcesByName ������
		void AddResFile(InitPatch& patch, const String& theFileName, bool(*theExtractFunction)(ResourceManager*, const char*));

		/*
		 *	Magic Member List:
		 *		void MF_LoadPak();
		 */

		template <typename T>
		void ReplacePakInterface(InitPatch& patch);
	}
}

#include "ResourcePatch.inl"

#endif // !_PVZMOD_RESOURCE_PATCH_H_
