//현재 시스템시간상 봄,여름,가을,겨울중 어느것인지 윤년 고려안됨(22년기준...)
int season()
{
  int iReturn = FALSE;
  
	QDate NowDate = QDate::currentDate();	
	QString Year = NowDate.toString("yyyy");
	  
	QDate Spring(Year.toInt(), 2, 4);	// 입춘 2월 4일 
	QDate Summer(Year.toInt(), 5, 5);	// 입하 5월 5일
	QDate Fall(Year.toInt(), 8, 7);		// 입추 8월 7일
	QDate Winter(Year.toInt(), 11, 7);// 입동 11월 7일

	int iResult = Spring.daysTo(NowDate) + Summer.daysTo(NowDate) + Fall.daysTo(NowDate) + Winter.daysTo(NowDate);
	
  //2가 아닌경우...
  if(Year.at(0) == '2')
  {
    if(iResult >= -553 && iResult < -189)		//봄
      printf("spring\n");
    else if(iResult >= -189 && iResult < 187)	//여름
      printf("summer\n");
    else if(iResult >= 187 && iResult < 555)	//가을
      printf("fall\n");
    else if(iResult >= 555 && iResult < -553)	//겨울
      printf("winter\n");
    
    iReturn = TRUE;
  }
  
	return iReturn;
}
