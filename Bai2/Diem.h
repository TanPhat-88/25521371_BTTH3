#ifndef DIEM_H
#define DIEM_H

struct Diem {
	double x, y;
	Diem();
	Diem(double a, double b);
	void NhapDiem();
	void XuatDiem();
	double KhoangCach(Diem);
};

#endif
