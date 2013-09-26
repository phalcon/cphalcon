
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Logger\Formatter
 *
 * This is a base class for logger formatters
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger, Formatter, phalcon, logger_formatter, phalcon_logger_formatter_method_entry, 0);


	return SUCCESS;

}

/**
 * Returns the string meaning of a logger constant
 *
 * @param  integer type
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter, getTypeString) {

	zval *type_param = NULL;
	int type;

	zephir_fetch_params(0, 1, 0, &type_param);

		type = zephir_get_intval(type_param);


	do {
		if ((type == 7)) {
			RETURN_STRING("DEBUG", 1);
		}
		if ((type == 7)) {
			RETURN_STRING("ERROR", 1);
		}
		if ((type == 4)) {
			RETURN_STRING("WARNING", 1);
		}
		if ((type == 1)) {
			RETURN_STRING("CRITICAL", 1);
		}
		if ((type == 8)) {
			RETURN_STRING("CUSTOM", 1);
		}
		if ((type == 2)) {
			RETURN_STRING("ALERT", 1);
		}
		if ((type == 5)) {
			RETURN_STRING("NOTICE", 1);
		}
		if ((type == 6)) {
			RETURN_STRING("INFO", 1);
		}
		if ((type == 0)) {
			RETURN_STRING("EMERGENCE", 1);
		}
		if ((type == 9)) {
			RETURN_STRING("SPECIAL", 1);
		}
		RETURN_STRING("CUSTOM", 1);
	} while(0);


}

