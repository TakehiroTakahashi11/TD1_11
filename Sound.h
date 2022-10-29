#pragma once

class Sound
{
public:
	/// @brief デフォルトコンストラクタ
	Sound();
	
	/// @brief コンストラクタ
	/// @param loop ループするか
	Sound(bool loop);

	/// @brief コンストラクタ
	/// @param volume 音量
	Sound(float volume);

	/// @brief コンストラクタ
	/// @param loop ループするか
	/// @param volume 音量
	Sound(bool loop, float volume);

	/// @brief セッター
	/// @param volume 音量
	void SetVolume(float _volume){ volume = _volume; };
	
	/// @brief 音量をvelocity分変える
	/// @param velocity 変化量
	void MoveVolume(float velocity){ volume += velocity; }

	/// @brief 音を再生する
	void Play();

	/// @brief 音を再生する
	void PlayOnce();

	/// @brief 音を停止する
	void Stop();

	/// @brief 一時停止
	void Pause();

	/// @brief 一時停止解除
	void Resume();

private:
	// サウンドハンドル
	int soundhandle;	
	// サウンドハンドル
	int handle;
	// 音量
	float volume;
	// ループさせるか
	bool loop;
};