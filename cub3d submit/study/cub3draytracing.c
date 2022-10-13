1. 視点の位置を決める．
プレイヤーの座標などの表し方
 プレイヤーの現在地は2次元ベクトル pos→ で表されます.
  またプレイヤーの現在向いている方向は2次元方向ベクトル dir→
   で表され, これは大きさ1の単位ベクトルです.
 
double posX = 22, posY = 12;  //x and y start position
double dirX = -1, dirY = 0; //initial direction vector
double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

  dir - pos =   
void playerposition 
{
  pos = 
} 


// DDA.の説明
ここからがポイントで, ここにスクリーンを表すカメラ平面ベクトル
 plane→ を追加します. −plane→ が画面左側, +plane→ が画面右側
 を表します. またこの plane→ の長さ(大きさ)によってプレイヤーの
 視野角が変わります.
Wは画像の幅，Hは画像の高さである．

int plane ()
{
while(0< y < H-1)
{
  while(0 < x < W-1)
  {
    3. 視点位置から点(x,y)に向かう半直線と物体との交差判定を行う．
    if
    4.
    if (半直線が物体と交差する場合)
    {
      if ( 物体の交点と公言の間に他の物体がない )
        4a. シェーディングの処理を行う(図1-3a)．
      else
        4b. 影として扱う(図1-3b)．
    }
    else
    {
      4c. 次の点を処理する(背景色として扱う，図1-3c)．
    }
 
  }
}