#!/bin/bash

export PATH=$PATH:/opt/Qt5.5.0/5.5/gcc_64/bin/

build_release_version() {
	cd sources/FootballEditor16
	qmake --version
	qmake
	if [ -e "Makefile" ]; then
		make --version
		make
		cd ../..
	else
		echo "Makefile does not exist"
		echo "Build release version failure!"
		exit 1
	fi	
}

build_debug_version() {
	cd sources/FootballEditor16
	cloc --version
	cloc --by-file --xml --out=./cloc_result *
	qmake --version
	qmake "QMAKE_CXXFLAGS+=-fprofile-arcs -ftest-coverage -fPIC -O0 -g --coverage" "LIBS+=-lgcov"
	if [ -e "Makefile" ]; then
		make --version
		make
		Test/tst_testcore -xml -o test_results || true
		cppcheck --version
		cppcheck --enable=all -v  --xml  * 2> cppcheck_result
		#gcovr --version
		#gcovr -r . --xml --exclude='tst*' -o gcovr_result
		
		valgrind --version
		valgrind --leak-check=full --xml=yes --xml-file=/opt/tomcat/.jenkins/jobs/FootballEditor16/workspace/tst_testcore.%p.result /opt/tomcat/.jenkins/jobs/FootballEditor16/workspace/sources/FootballEditor16/Test/tst_testcore || true

		if [ -e "doxygen.ini" ]; then
			doxygen --version
			doxygen doxygen.ini
		else
			echo "Doxygen failed"
			echo "doxygen.ini does not exist"
		fi

		cd ../..
	else
		echo "Makefile does not exist"
		echo "Build debug version failure!"
		exit 1
	fi
}

make_report() {
	cd sources/FootballEditor16/doxygen/latex
	if [ -e "Makefile" ]; then
		make --version
		make
#		cd ../../../../report
#		pdflatex FootballEditor16.tex
#		pdflatex FootballEditor16.tex
#		pdflatex FootballEditor16.tex
#		cd ..
		cd ../../../..
	else
		echo "Makefile does not exist"
		echo "Report failure!"
		cd ../..
		exit 1
	fi
}

zip_files() {
	if [ -z ${JOB_NAME} ] || [ -z ${BUILD_NUMBER}]; then
		echo "Vars JOB_NAME/BUILD_NUMBER are unset"
		echo "Zip failure!"
		exit 1
	fi

	TITLE="${JOB_NAME}_v${BUILD_NUMBER}"
	mkdir "$TITLE"

	if [ -e "sources/FootballEditor16/ConsoleApp/ConsoleApp" ]; then
		cp sources/FootballEditor16/ConsoleApp/ConsoleApp $TITLE/FootballEditor16_Console_v${BUILD_NUMBER}
		if [ -e "report/FootballEditor16.pdf" ]; then
			cp report/FootballEditor16.pdf $TITLE/FootballEditor16_v${BUILD_NUMBER}.pdf
		fi
		if [ -e "report/uefa16" ]; then
			cp report/uefa16 $TITLE/uefa16
		fi
		if [ -e "report/fifa32" ]; then
			cp report/fifa32 $TITLE/fifa32
		fi
		if [ -e "sources/FootballEditor16/doxygen/latex/refman.pdf" ]; then
			cp sources/FootballEditor16/doxygen/latex/refman.pdf $TITLE/FootballEditor16_Doxygen_v${BUILD_NUMBER}.pdf
		fi
	else
		echo "ConsoleApp does not exist"
		echo "Zip failure!"
		exit 1
	fi

	if [ -e "sources/FootballEditor16/GUIApp/GUIApp" ]; then
		cp sources/FootballEditor16/GUIApp/GUIApp $TITLE/FootballEditor16_GUI_v${BUILD_NUMBER}
	else
		echo "GUIApp does not exist"
		echo "Zip failure!"
		exit 1
	fi
	zip --version
	zip $TITLE.zip $TITLE/*
}

clean() {
	git clean -f -e *.zip
}
