		---------------------------------------
		����image�ե��������ӥġ������������
		---------------------------------------
�����¹ԥե������C:\en_work\face_recognize-3\x64\Debug

�����¹���ˡ
	������Ѥ�image�ե������C:\en_work\face_recognize-3\x64\Debug�ե�����˥����Ԥ��ޤ���
	��compare.bat��¹Ԥ��ޤ���compare.bat�����Ƥ�ʲ����������ޤ���
		del *sobel.bmp
		del imagelist.txt
		dir *.bmp /b > imagelist.txt	--->���ιԤ�*.bmp�γ�ĥ�Ҥ�ºݤ�image�ե�����˹�碌�ơ��ѹ����ޤ�
		del image_compare_log.txt
		cmd
	��imagelist.txt�ե�����γʼ�����������ޤ���
		�㡧
		1242.bmp��<---���Ԥ���Ӥ�ɸ������Ȥʤ롢¾�β����Ϥ���ɸ���������٤ơ��������Ƥ��롣
		1243.bmp
		1246.bmp
		1247.bmp
		1310.bmp
		1313.bmp
		1314.bmp
		22.bmp
		25.bmp
		422.bmp
		424.bmp
		425.bmp
		426.bmp
		427.bmp
		428.bmp
		429.bmp
		430.bmp
		437.bmp
		438.bmp
		439.bmp
		440.bmp
	��Project1.exe������ӥġ����¹Ԥ��롢��������С�Ʊ���ե������sobel��������ӷ�̤��������ޤ���
����ӷ�̤�OK,SUSPICIOUS,NG�����ब���롣
����OK�ۤ���Ĳ�����Ʊ����ΤǤ���
����SUSPICIOUS�ۤ�Ʊ���β�ǽ�������뤬����Ʊ�ʲ�����ǽ���⤢�ꡣ
����NG�ۤ���Ĳ����ϰ㤤��ΤǤ���

����ӽ��Ϸ��image_compare_log������������ޤ���

�㡧
comparison standard base: 1242.bmp

 1243.bmp:  CV_COMP_EMD ��96.6% ----OK

                                   CV_COMP_CHISQR : 0.1267
                                   CV_COMP_BHATTACHARYYA : 0.1206
                                   CV_COMP_CORREL : 0.8463
                                   CV_COMP_INTERSECT : 0.8715

 1246.bmp:  CV_COMP_EMD ��90.5% ----OK

                                   CV_COMP_CHISQR : 0.1973
                                   CV_COMP_BHATTACHARYYA : 0.1384
                                   CV_COMP_CORREL : 0.7931
                                   CV_COMP_INTERSECT : 0.8557

 1247.bmp:  CV_COMP_EMD ��92.6% ----OK

                                   CV_COMP_CHISQR : 0.1256
                                   CV_COMP_BHATTACHARYYA : 0.1183
                                   CV_COMP_CORREL : 0.8573
                                   CV_COMP_INTERSECT : 0.8725

 1310.bmp:  CV_COMP_EMD ��95.5% ----OK

                                   CV_COMP_CHISQR : 0.0982
                                   CV_COMP_BHATTACHARYYA : 0.1096
                                   CV_COMP_CORREL : 0.8671
                                   CV_COMP_INTERSECT : 0.8776

 1313.bmp:  CV_COMP_EMD ��97.3% ----OK

                                   CV_COMP_CHISQR : 0.1121
                                   CV_COMP_BHATTACHARYYA : 0.1210
                                   CV_COMP_CORREL : 0.8578
                                   CV_COMP_INTERSECT : 0.8731

 1314.bmp:  CV_COMP_EMD ��96.6% ----OK

                                   CV_COMP_CHISQR : 0.1136
                                   CV_COMP_BHATTACHARYYA : 0.1217
                                   CV_COMP_CORREL : 0.8549
                                   CV_COMP_INTERSECT : 0.8670

 22.bmp:  CV_COMP_EMD ��59.7% ==============NG

                                   CV_COMP_CHISQR : 1.5341
                                   CV_COMP_BHATTACHARYYA : 0.4048
                                   CV_COMP_CORREL : 0.5131
                                   CV_COMP_INTERSECT : 0.5519
