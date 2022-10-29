#pragma once

class Texture
{
public:
    /// @brief コンストラクタ
    /// @param width テクスチャ幅
    /// @param height テクスチャ高さ
    Texture(int width,int height);

    /// @brief ゲッター
    /// @return テクスチャハンドル
    int GetHandle() const { return handle; }

    /// @brief セッター
    /// @param _handle テクスチャハンドル 
    void SetHandle(const int set_handle) { handle = set_handle; }

    // テクスチャ幅
    const int width;
    // テクスチャ高さ
    const int height;

private:
    // テクスチャハンドル
    int handle;
};