//091127�@�V���A���ʐM�e�X�g doi
//Visual Studio�ŃR���p�C������Ƃ��́C�v���W�F�N�g���v���p�e�B���S�ʁ������Z�b�g
//�̍��ڂ��C�u�}���`�o�C�g�����Z�b�g���g�p����v
//�Ɛݒ肷��D

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include "serial.h"


int main(void)
{
	serial s1;//�V���A���ʐM�N���X
	char s_buf[32];//���M�o�b�t�@
	char r_buf[32];//��M�o�b�t�@

	printf("Serial Commnucation Test for Win32\n");

	//������----------------------------------------
	bool res=s1.init("COM1",9600);//������
	if(res!=true)
	  {
	    printf("Port Open Error\n");
	    return 1;
	  }

	//���M����----------------------------------------
	printf("���M�e�X�g\n");
	sprintf(s_buf, "This is test.\n");//���M�o�b�t�@�Ƀf�[�^�Z�b�g
	s1.send(s_buf,32);//���M

	//��M����----------------------------------------
	printf("��M�e�X�g\n");
	s1.receive(r_buf,32);//32�o�C�g��M
	printf("[%s]",r_buf);//��M���ʕ\��

	//�I������----------------------------------------
	printf("�I������\n");
	s1.close();//�|�[�g�N���[�Y
	
	getchar();//�L�[���͑҂�





	return 0;
}

