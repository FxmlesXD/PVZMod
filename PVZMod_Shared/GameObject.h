#pragma once
#ifndef _PVZMOD_GAME_OBJECT_H_
#define _PVZMOD_GAME_OBJECT_H_

namespace PVZMod
{
	enum RenderLayer
	{
		RENDER_LAYER_ROW_OFFSET = 10000,
		RENDER_LAYER_UI_BOTTOM = 100000,
		RENDER_LAYER_GROUND = 200000,
		RENDER_LAYER_LAWN = 300000,
		RENDER_LAYER_GRAVE_STONE = 301000,
		RENDER_LAYER_PLANT = 302000,
		RENDER_LAYER_ZOMBIE = 303000,
		RENDER_LAYER_BOSS = 304000,
		RENDER_LAYER_PROJECTILE = 305000,
		RENDER_LAYER_LAWN_MOWER = 306000,
		RENDER_LAYER_PARTICLE = 307000,
		RENDER_LAYER_TOP = 400000,
		RENDER_LAYER_FOG = 500000,
		RENDER_LAYER_COIN_BANK = 600000,
		RENDER_LAYER_UI_TOP = 700000,
		RENDER_LAYER_ABOVE_UI = 800000,
		RENDER_LAYER_SCREEN_FADE = 900000
	};

	enum GameObjectType
	{
		OBJECT_TYPE_NONE,
		OBJECT_TYPE_PLANT,
		OBJECT_TYPE_PROJECTILE,
		OBJECT_TYPE_COIN,
		OBJECT_TYPE_SEEDPACKET,
		OBJECT_TYPE_SHOVEL,
		OBJECT_TYPE_WATERING_CAN,
		OBJECT_TYPE_FERTILIZER,
		OBJECT_TYPE_BUG_SPRAY,
		OBJECT_TYPE_PHONOGRAPH,
		OBJECT_TYPE_CHOCOLATE,
		OBJECT_TYPE_GLOVE,
		OBJECT_TYPE_MONEY_SIGN,
		OBJECT_TYPE_WHEELBARROW,
		OBJECT_TYPE_TREE_FOOD,
		OBJECT_TYPE_NEXT_GARDEN,
		OBJECT_TYPE_MENU_BUTTON,
		OBJECT_TYPE_STORE_BUTTON,
		OBJECT_TYPE_SLOT_MACHINE_HANDLE,
		OBJECT_TYPE_SCARY_POT,
		OBJECT_TYPE_STINKY,
		OBJECT_TYPE_TREE_OF_WISDOM,
	};

	class LawnApp;
	class Board;

	/// 【游戏类】游戏对象。（原 ::GameObject）
	class GameObject
	{
	public:
		LawnApp*	mApp;			///< App 对象指针。
		Board*		mBoard;			///< Board 指针。
		int			mX;				///< X 坐标。
		int			mY;				///< Y 坐标。
		int			mWidth;			///< 宽度。
		int			mHeight;		///< 高度。
		bool		mVisible;		///< 是否可见。
		int			mRow;			///< 所在行。
		int			mRenderOrder;	///< 渲染图层。
	};
}

#endif // !_PVZMOD_GAME_OBJECT_H_
