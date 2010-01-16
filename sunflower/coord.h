#ifndef __coord_h
#define __coord_h

#include <string>
#include <iostream>

/*
 * ���W���������߂�class.
 * vector�Ƃ������Ƃ��낾���A�R���e�i�N���X�ɓ��������邽�߁Acoord�Ƃ���
 */
class coord {
  protected:
    /* �ȉ��̕ϐ��錾�͎����Ɋւ��Ă��邽�߉B�������Ƃ���B
     * C++���ƃw�b�_�[�t�@�C���ɏ������N���X��`�����J�ƂȂ�̂Œʏ킾�ƉB���Ȃ�
     * ����E�Q�Ƃ͂ł��Ȃ��̂����ǁA�����̕ύX���ϐ��ɋy�񂾂Ƃ���
     * �w�b�_�[�t�@�C����ύX����̂́A�C����������
     */
    int dim;
    double v[3];

  public:
    coord(int dim); // �w�肵�������ō��W�𐶐�
    coord(double x, double y);  // 2�����ō��W�𐶐�
    coord(const coord& cod);  // �w�肵�����W���R�s�[���Đ���
    ~coord();  // �f�X�g���N�^

    coord& operator=(const coord& cod); // coord = coord�B�߂�l���Q�ƁI
    coord operator+(const coord& cod); // coord + coord
    coord operator-(const coord& cod); // coord - coord
    coord operator-(); // - coord
    coord operator*(double a); // coord * double
    coord operator*(const coord& cod); // �O��

    double length();
    double dot(const coord& cod); // ����

    std::string toString();
};

// 2�����Z�q�ō����� coord �ȊO�̏ꍇ�́A�ʏ�̊֐��Ƃ��ĉ��Z�q���I�[�o�[���[�h����
// double * coord �����߂���
coord operator*(const double a, const coord& b);

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& o, coord cod);

#endif
