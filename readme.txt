		---------------------------------------
		¢¨¡¡image¥Õ¥¡¥¤¥ë¤òÈæ³Ó¥Ä¡¼¥ë¤òÀâÌÀ¡¡¢¨
		---------------------------------------
¡ú¡¡¼Â¹Ô¥Õ¥©¥ë¥À¤ÏC:\en_work\face_recognize-3\x64\Debug

¡ú¡¡¼Â¹ÔÊýË¡
	­¡Èæ³ÓÍÑ¤Îimage¥Õ¥¡¥¤¥ë¤òC:\en_work\face_recognize-3\x64\Debug¥Õ¥©¥ë¥À¤Ë¥³¡¼¥Ô¤·¤Þ¤¹¡£
	­¢compare.bat¤ò¼Â¹Ô¤·¤Þ¤¹¡£compare.bat¤ÎÆâÍÆ¤ò°Ê²¼¤ËÀâÌÀ¤·¤Þ¤¹¡§
		del *sobel.bmp
		del imagelist.txt
		dir *.bmp /b > imagelist.txt	--->¤³¤Î¹Ô¤Î*.bmp¤Î³ÈÄ¥»Ò¤ò¼ÂºÝ¤Îimage¥Õ¥¡¥¤¥ë¤Ë¹ç¤ï¤»¤Æ¡¢ÊÑ¹¹¤·¤Þ¤¹
		del image_compare_log.txt
		cmd
	­£imagelist.txt¥Õ¥¡¥¤¥ë¤Î³Ê¼°Îã¤ÇÀâÌÀ¤·¤Þ¤¹¡£
		Îã¡§
		1242.bmp¡¡<---Âè°ì¹Ô¤ÏÈæ³Ó¤ÎÉ¸½à²èÁü¤È¤Ê¤ë¡¢Â¾¤Î²èÁü¤Ï¤³¤ÎÉ¸½à²èÁü¤ÈÈæ¤Ù¤Æ¡¢²¿¡ó¤ò»÷¤Æ¤¤¤ë¡£
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
	­¤Project1.exe²èÁüÈæ³Ó¥Ä¡¼¥ë¤ò¼Â¹Ô¤¹¤ë¡¢¤½¤¦¤¹¤ì¤Ð¡¢Æ±¤¸¥Õ¥©¥ë¥À¤Ësobel²èÁü¤ÈÈæ³Ó·ë²Ì¤òÀ¸À®¤·¤Þ¤¹¡£
¡úÈæ³Ó·ë²Ì¤ÏOK,SUSPICIOUS,NG»°¼ïÎà¤¬¤¢¤ë¡£
¡¡¡ÚOK¡Û¤ÏÆó¤Ä²èÁü¤ÏÆ±¤¸¤â¤Î¤Ç¤¹¡£
¡¡¡ÚSUSPICIOUS¡Û¤ÏÆ±¤¸¤Î²ÄÇ½À­¤¬¤¢¤ë¤¬¡¢ÉÔÆ±¤Ê²èÁü²ÄÇ½À­¤â¤¢¤ê¡£
¡¡¡ÚNG¡Û¤ÏÆó¤Ä²èÁü¤Ï°ã¤¤¤â¤Î¤Ç¤¹¡£

¡¡Èæ³Ó½ÐÎÏ·ë²Ìimage_compare_log¤òÎã¤ÇÀâÌÀ¤·¤Þ¤¹¡§

Îã¡§
comparison standard base: 1242.bmp

 1243.bmp:  CV_COMP_EMD ¡§96.6% ----OK

                                   CV_COMP_CHISQR : 0.1267
                                   CV_COMP_BHATTACHARYYA : 0.1206
                                   CV_COMP_CORREL : 0.8463
                                   CV_COMP_INTERSECT : 0.8715

 1246.bmp:  CV_COMP_EMD ¡§90.5% ----OK

                                   CV_COMP_CHISQR : 0.1973
                                   CV_COMP_BHATTACHARYYA : 0.1384
                                   CV_COMP_CORREL : 0.7931
                                   CV_COMP_INTERSECT : 0.8557

 1247.bmp:  CV_COMP_EMD ¡§92.6% ----OK

                                   CV_COMP_CHISQR : 0.1256
                                   CV_COMP_BHATTACHARYYA : 0.1183
                                   CV_COMP_CORREL : 0.8573
                                   CV_COMP_INTERSECT : 0.8725

 1310.bmp:  CV_COMP_EMD ¡§95.5% ----OK

                                   CV_COMP_CHISQR : 0.0982
                                   CV_COMP_BHATTACHARYYA : 0.1096
                                   CV_COMP_CORREL : 0.8671
                                   CV_COMP_INTERSECT : 0.8776

 1313.bmp:  CV_COMP_EMD ¡§97.3% ----OK

                                   CV_COMP_CHISQR : 0.1121
                                   CV_COMP_BHATTACHARYYA : 0.1210
                                   CV_COMP_CORREL : 0.8578
                                   CV_COMP_INTERSECT : 0.8731

 1314.bmp:  CV_COMP_EMD ¡§96.6% ----OK

                                   CV_COMP_CHISQR : 0.1136
                                   CV_COMP_BHATTACHARYYA : 0.1217
                                   CV_COMP_CORREL : 0.8549
                                   CV_COMP_INTERSECT : 0.8670

 22.bmp:  CV_COMP_EMD ¡§59.7% ==============NG

                                   CV_COMP_CHISQR : 1.5341
                                   CV_COMP_BHATTACHARYYA : 0.4048
                                   CV_COMP_CORREL : 0.5131
                                   CV_COMP_INTERSECT : 0.5519
