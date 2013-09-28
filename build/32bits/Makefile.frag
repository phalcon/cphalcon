%.c : %.y

clean-coverage:
	-rm -rf .coverage coverage

coverage: test clean-coverage
	echo "Generating $@"
	$(LCOV) --directory . --capture --base-directory=. --output-file .coverage
	$(GENHTML) --legend --output-directory coverage/ --title "Phalcon code coverage" .coverage
