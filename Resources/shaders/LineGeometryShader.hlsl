
#include "LineShaderHeader.hlsli"

//四角形の頂点数
static const uint vnum = 2;

//センターからのオフセット
static const float4 offset_array[vnum] =
{
	float4(-0.5f,-1.5f,0,0),//左下
	float4(-0.0f,+1.5f,0,0),//左上

};

//uv用
static const float2 uv_array[vnum] =
{
	float2(0,1),//左下
	float2(0,0),//左上
};

//(32bit(float)を最大1024個)
[maxvertexcount(vnum)]
void main(
	point VSOutput input[1] : SV_POSITION, //入力プリミティブの種類
	inout LineStream< GSOutput > output//出力ストリーム型
)
{
	GSOutput element;
	//四点分
	for (int i = 0; i < vnum; i++)
	{
		//中心からのオフセットをスケーリング
		float4 offset = offset_array[i] * input[0].scale;
		//中心からのオフセットをビルボード回転（モデル座標）
		offset = mul(matBillboard, offset);
		//オフセット分ずらす（ワールド座標）
		element.svpos = input[0].pos + offset;

		//ワールド座標ベースで、ずらす
		//element.svpos = input[0].pos + offset_array[i];
		//ビュー射影変換
		element.svpos = mul(mat, element.svpos);
		element.uv = uv_array[i];
		element.color = input[0].color;
		output.Append(element);
	}
}