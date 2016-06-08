

class CmmcMonoLedMartix
{
	public:
	    int colList[8] = {1, 2, 4, 8, 16, 32, 64, 128};
		unsigned long time_prev_control;
		int countArray = 0;
		int addI2c;
		
		CmmcMonoLedMartix();
		
		void begin(int addr);
		void showPic8bit(int dataPic[8]);
};