%.c : %.y

remake:
	$(MAKE) clean
	$(MAKE) all

clean: clean-coverage

clean-coverage:
	-rm -rf .coverage coverage

unit-tests: install
	-@if test ! -z "$(PHP_EXECUTABLE)" && test -x "$(PHP_EXECUTABLE)"; then \
		(cd "$(top_srcdir)/../"; $(PHP_EXECUTABLE) $(phpenv which php) ./unit-tests/ci/phpunit.php -c unit-tests/phpunit.xml) \
	else \
		echo "ERROR: Cannot run tests without CLI sapi."; \
	fi

coverage: unit-tests clean-coverage
	$(LCOV) --quiet --directory . --capture --base-directory=. --output-file .coverage
	$(GENHTML) --quiet --legend --output-directory coverage/ --title "Phalcon code coverage" .coverage

SOURCE_DEPS = $(patsubst %.lo,%.d,$(shared_objects_phalcon))

clean: clean-deps

clean-deps:
	-rm -f $(SOURCE_DEPS)

%.d : %.c
	$(CC) -MM -MP -MF"$@" -MT"$(@:%.d=%.lo)" -MT"$@" $(COMMON_FLAGS) "$<"

ifneq ($(MAKECMDGOALS),clean)
-include $(SOURCE_DEPS)
endif
