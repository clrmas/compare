		---------------------------------------
		※　imageファイルを比較ツールを説明　※
		---------------------------------------
★　実行フォルダはC:\en_work\face_recognize-3\x64\Debug

★　実行方法
	�“羈嗟僂�imageファイルをC:\en_work\face_recognize-3\x64\Debugフォルダにコーピします。
	��compare.batを実行します。compare.batの内容を以下に説明します：
		del *sobel.bmp
		del imagelist.txt
		dir *.bmp /b > imagelist.txt	--->この行の*.bmpの拡張子を実際のimageファイルに合わせて、変更します
		del image_compare_log.txt
		cmd
	��imagelist.txtファイルの格式例で説明します。
		例：
		1242.bmp　<---第一行は比較の標準画像となる、他の画像はこの標準画像と比べて、何％を似ている。
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
	��Project1.exe画像比較ツールを実行する、そうすれば、同じフォルダにsobel画像と比較結果を生成します。
★比較結果はOK,SUSPICIOUS,NG三種類がある。
　【OK】は二つ画像は同じものです。
　【SUSPICIOUS】は同じの可能性があるが、不同な画像可能性もあり。
　【NG】は二つ画像は違いものです。

　比較出力結果image_compare_logを例で説明します：

例：
comparison standard base: 1242.bmp

 1243.bmp:  CV_COMP_EMD ：96.6% ----OK

                                   CV_COMP_CHISQR : 0.1267
                                   CV_COMP_BHATTACHARYYA : 0.1206
                                   CV_COMP_CORREL : 0.8463
                                   CV_COMP_INTERSECT : 0.8715

 1246.bmp:  CV_COMP_EMD ：90.5% ----OK

                                   CV_COMP_CHISQR : 0.1973
                                   CV_COMP_BHATTACHARYYA : 0.1384
                                   CV_COMP_CORREL : 0.7931
                                   CV_COMP_INTERSECT : 0.8557

 1247.bmp:  CV_COMP_EMD ：92.6% ----OK

                                   CV_COMP_CHISQR : 0.1256
                                   CV_COMP_BHATTACHARYYA : 0.1183
                                   CV_COMP_CORREL : 0.8573
                                   CV_COMP_INTERSECT : 0.8725

 1310.bmp:  CV_COMP_EMD ：95.5% ----OK

                                   CV_COMP_CHISQR : 0.0982
                                   CV_COMP_BHATTACHARYYA : 0.1096
                                   CV_COMP_CORREL : 0.8671
                                   CV_COMP_INTERSECT : 0.8776

 1313.bmp:  CV_COMP_EMD ：97.3% ----OK

                                   CV_COMP_CHISQR : 0.1121
                                   CV_COMP_BHATTACHARYYA : 0.1210
                                   CV_COMP_CORREL : 0.8578
                                   CV_COMP_INTERSECT : 0.8731

 1314.bmp:  CV_COMP_EMD ：96.6% ----OK

                                   CV_COMP_CHISQR : 0.1136
                                   CV_COMP_BHATTACHARYYA : 0.1217
                                   CV_COMP_CORREL : 0.8549
                                   CV_COMP_INTERSECT : 0.8670

 22.bmp:  CV_COMP_EMD ：59.7% ==============NG

                                   CV_COMP_CHISQR : 1.5341
                                   CV_COMP_BHATTACHARYYA : 0.4048
                                   CV_COMP_CORREL : 0.5131
                                   CV_COMP_INTERSECT : 0.5519
