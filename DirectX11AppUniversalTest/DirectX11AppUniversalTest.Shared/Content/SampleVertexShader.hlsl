// �W�I���g�����쐬���邽�߂� 3 �̊�{�I�ȗ�D��̃}�g���b�N�X��ۑ�����萔�o�b�t�@�[�B
cbuffer ModelViewProjectionConstantBuffer : register(b0)
{
	matrix model;
	matrix view;
	matrix projection;
};

// ���_�V�F�[�_�[�ւ̓��͂Ƃ��Ďg�p���钸�_���Ƃ̃f�[�^�B
struct VertexShaderInput
{
	float3 pos : POSITION;
	float3 color : COLOR0;
};

// �s�N�Z�� �V�F�[�_�[��ʂ��ēn�����s�N�Z�����Ƃ̐F�f�[�^�B
struct PixelShaderInput
{
	float4 pos : SV_POSITION;
	float3 color : COLOR0;
};

// GPU �Œ��_�������s�����߂̊ȒP�ȃV�F�[�_�[�B
PixelShaderInput main(VertexShaderInput input)
{
	PixelShaderInput output;
	float4 pos = float4(input.pos, 1.0f);

	// ���_�̈ʒu���A�ˉe���ꂽ�̈�ɕϊ����܂��B
	pos = mul(pos, model);
	pos = mul(pos, view);
	pos = mul(pos, projection);
	output.pos = pos;

	// �ύX�����ɐF���p�X�X���[���܂��B
	output.color = input.color;

	return output;
}
