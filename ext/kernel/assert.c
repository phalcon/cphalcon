
/*
	+------------------------------------------------------------------------+
	| Zephir Language                                                        |
	+------------------------------------------------------------------------+
	| Copyright (c) 2011-2013 Zephir Team (http://www.zephir-lang.com)       |
	+------------------------------------------------------------------------+
	| This source file is subject to the New BSD License that is bundled     |
	| with this package in the file docs/LICENSE.txt.                        |
	|                                                                        |
	| If you did not receive a copy of the license and are unable to         |
	| obtain it through the world-wide-web, please send an email             |
	| to license@zephir-lang.com so we can send you a copy immediately.      |
	+------------------------------------------------------------------------+
	| Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
	|          Eduar Carvajal <eduar@zephir-lang.com>                        |
	+------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "kernel/debug.h"

#ifndef ZEPHIR_RELEASE

int zephir_assert_class(zval *object, char *class_name TSRMLS_DC) {
	if (object) {
		if (Z_TYPE_P(object) != IS_OBJECT) {
			zephir_error_space();
			fprintf(zephir_log, "AssertClass: [Failed] Value is not an object\n");
			return FAILURE;
		} else {
			if (strcmp(Z_OBJCE_P(object)->name, class_name)) {
				zephir_error_space();
				fprintf(zephir_log, "AssertClass: [Failed] Object is not class %s, is %s\n", class_name, Z_OBJCE_P(object)->name);
				return FAILURE;
			}
		}
	}
	return SUCCESS;
}

#endif
