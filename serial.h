//�V���A���ʐM�\����class serial
//serial.cpp,h
//modified 060530
//windows/linux�N���X�v���b�g�t�H�[��
//---------------------------------------------------------------------------
#ifndef serialH
#define serialH
#ifdef WIN32
  #include <windows.h>
#endif
//---------------------------------------------------------------------------

class serial
{
#ifdef WIN32
    HANDLE hcom;
    DWORD mask;
    COMMTIMEOUTS ctmo;
    OVERLAPPED o;
    COMMPROP cmp;
#endif
public:
    char flag_opened;//com�|�[�g���J����Ă��邩�ǂ���
    char comport[16];//com�|�[�g��
    int baudrate;//�{�[���[�g�������ɏo��

    bool init(char *comport_in,int baudrate);
    bool close(void);
    void purge(void);//WinAPI��PurgeComm�����s����
    int receive(char *buf_ptr,int size);//�󂯎��o�b�t�@�̏ꏊ�ƃT�C�Y
    int send(char *buf_ptr,int size);//����o�b�t�@�̏ꏊ�ƃT�C�Y
    bool receive2(char *buf_ptr,int size);//ACK���󂯎��֐�

};
//---------------------------------------------------------------------------
#endif
