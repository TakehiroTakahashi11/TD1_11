#include "Sound.h"
#include <Novice.h>

/// @brief デフォルトコンストラクタ
Sound::Sound()
: soundhandle(-1),handle(-1),loop(false),volume(0.1f)
{
}

/// @brief コンストラクタ
Sound::Sound(bool loop)
: soundhandle(-1),handle(-1),loop(loop),volume(0.1f)
{
}

/// @brief コンストラクタ
Sound::Sound(float volume)
: soundhandle(-1),handle(-1),loop(false),volume(volume)
{
}

/// @brief コンストラクタ
Sound::Sound(bool loop,float volume)
: soundhandle(-1),handle(-1),loop(loop),volume(volume)
{
}

/// @brief 音を再生する
void Sound::Play(){
    if(!Novice::IsPlayingAudio(soundhandle) || soundhandle == -1){
        soundhandle = Novice::PlayAudio(handle,loop,volume);
    }
}

/// @brief 音を一回だけ再生する
void Sound::PlayOnce() {
    Novice::PlayAudio(handle, false, volume);
}


/// @brief 音を停止する
void Sound::Stop(){
    if(Novice::IsPlayingAudio(soundhandle)){
        Novice::StopAudio(soundhandle);
    }
}

/// @brief 一時停止
void Sound::Pause(){
    if(Novice::IsPlayingAudio(soundhandle)){
        Novice::PauseAudio(soundhandle);
    }
}

/// @brief 一時停止解除
void Sound::Resume(){
    if(!Novice::IsPlayingAudio(soundhandle)){
        Novice::ResumeAudio(soundhandle);
    }
}