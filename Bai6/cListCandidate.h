#ifndef LISTCANDIDATE_H
#define LISTCANDIDATE_H
#include "cCandidate.h"

class cListCandidate {
private:
    int n;
    cCandidate* ds;
public:
    cListCandidate();
    ~cListCandidate();
    
    void NhapDS();
    void XuatTren15();
    void ThiSinhDiemCaoNhat();
    void SapXepGiam();
};
#endif