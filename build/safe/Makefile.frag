%.c : %.y

clean-coverage:
	-rm -rf .coverage coverage

unit-tests: all
	-@if test ! -z "$(PHP_EXECUTABLE)" && test -x "$(PHP_EXECUTABLE)"; then \
		NO_INTERACTION=1 TEST_PHP_USER="$(srcdir)/tests/" $(MAKE) test && \
		$(MAKE) install && \
		(cd "$(top_srcdir)/../../"; $(PHP_EXECUTABLE) unit-tests/manual-unit.php) \
	else \
		echo "ERROR: Cannot run tests without CLI sapi."; \
	fi

coverage: unit-tests clean-coverage
	$(LCOV) --directory . --capture --base-directory=. --output-file .coverage
	$(GENHTML) --legend --output-directory coverage/ --title "Phalcon code coverage" .coverage
