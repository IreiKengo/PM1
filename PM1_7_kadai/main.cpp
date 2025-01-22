#include <Novice.h>

const char kWindowTitle[] = "LC1D_06_イレイ_ケンゴ_タイトル";

struct Vector2
{
	float x;
	float y;
};

struct Player
{
	Vector2 center;
	float radius;
	float speed;
};




// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Player player[2] = {};
	player[0] = { 50.0f,100.0f,50.0f,5.0f };

	player[1] = { 50.0f,250.0f,50.0f,5.0f };

	float t[2] = {};

	t[0] = {0.0f};
	t[1] = {0.0f};
	int isMove = false;

	Vector2 start[2] = {};
	start[0] = { 50.0f,100.0f };
	start[1] = { 50.0f,250.0f };

	Vector2 end[2] = {};
	end[0] = { 1230.0f,100.0f };
	end[1] = { 1230.0f,250.0f };



	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		if (keys[DIK_SPACE])
		{
			isMove = true;
		}

		if (isMove)
		{
			//一定
			t[0] += 1.0f / 120.0f;
			if (1.0f <= t[0])
			{
				t[0] = 1.0f;
			}
			player[0].center.x = (1.0f - t[0]) * start[0].x + t[0] * end[0].x;
			player[0].center.y = (1.0f - t[0]) * start[0].y + t[0] * end[0].y;


			//穏やかにスタートし穏やかに停止

		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		//一定の速度
		Novice::DrawEllipse(static_cast<int>(player[0].center.x), static_cast<int>(player[0].center.y), static_cast<int>(player[0].radius), static_cast<int>(player[0].radius), 0.0f, RED, kFillModeSolid);

		//穏やかにスタートし穏やかに停止
		Novice::DrawEllipse(static_cast<int>(player[1].center.x), static_cast<int>(player[1].center.y), static_cast<int>(player[1].radius), static_cast<int>(player[1].radius), 0.0f, RED, kFillModeSolid);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
