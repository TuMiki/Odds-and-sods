#ifndef __gvector_h
#define __gvector_h

#include <string>
#include <iostream>

/*
 * ���W���������߂�class.
 * vector�Ƃ������Ƃ��낾���A�R���e�i�N���X�ɓ��������邽�߁Acoord�Ƃ���
 */
class gvector {
  protected:
    /* �ȉ��̕ϐ��錾�͎����Ɋւ��Ă��邽�߉B�������Ƃ���B
     * C++���ƃw�b�_�[�t�@�C���ɏ������N���X��`�����J�ƂȂ�̂Œʏ킾�ƉB���Ȃ�
     * ����E�Q�Ƃ͂ł��Ȃ��̂����ǁA�����̕ύX���ϐ��ɋy�񂾂Ƃ���
     * �w�b�_�[�t�@�C����ύX����̂́A�C����������
     */
    int dim;
    double v[3];

  public:
    gvector(int dim); // �w�肵�������ō��W�𐶐�
    gvector(double x, double y);  // 2�����ō��W�𐶐�
    gvector(double x, double y, double z);  // 3�����ō��W�𐶐�
    gvector(const gvector& cod);  // �w�肵�����W���R�s�[���Đ���
    ~gvector();  // �f�X�g���N�^

    gvector& operator=(const gvector& cod); // gvector = gvector�B�߂�l���Q�ƁI
    gvector operator+(const gvector& cod); // gvector + gvector
    gvector operator-(const gvector& cod); // gvector - gvector
    gvector operator-(); // - gvector
    gvector operator*(double a); // gvector * double
    gvector operator*(const gvector& cod); // �O��

    bool operator==(const gvector& cod); // ��r
    bool operator!=(const gvector& cod); // ��r

    double length();
    double dot(const gvector& cod); // ����

    std::string toString();
};

// 2�����Z�q�ō����� gvector �ȊO�̏ꍇ�́A�ʏ�̊֐��Ƃ��ĉ��Z�q���I�[�o�[���[�h����
// double * gvector �����߂���
gvector operator*(const double a, const gvector& b);

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& o, gvector cod);

// �������n�_�ƕ����x�N�g���ŕ\��
gvector intersect(const gvector posA, const gvector vecA, const gvector posB, const gvector vecB);

#endif
