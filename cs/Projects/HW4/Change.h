class Change {
private:
  int mPennies;
  int mNickels;
  int mDimes;
  int mQuarters;

public:
  Change();
  Change(int, int, int, int);
  void setPennies(int);
  void setNickels(int);
  void setDimes(int);
  void setQuarters(int);
  int getPennies();
  int getNickels();
  int getDimes();
  int getQuarters();
};