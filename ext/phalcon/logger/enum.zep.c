
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Log Level Enum constants
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Enum)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger, Enum, phalcon, logger_enum, NULL, 0);

	zephir_declare_class_constant_long(phalcon_logger_enum_ce, SL("ALERT"), 2);

	zephir_declare_class_constant_long(phalcon_logger_enum_ce, SL("CRITICAL"), 1);

	zephir_declare_class_constant_long(phalcon_logger_enum_ce, SL("CUSTOM"), 8);

	zephir_declare_class_constant_long(phalcon_logger_enum_ce, SL("DEBUG"), 7);

	zephir_declare_class_constant_long(phalcon_logger_enum_ce, SL("EMERGENCY"), 0);

	zephir_declare_class_constant_long(phalcon_logger_enum_ce, SL("ERROR"), 3);

	zephir_declare_class_constant_long(phalcon_logger_enum_ce, SL("INFO"), 6);

	zephir_declare_class_constant_long(phalcon_logger_enum_ce, SL("NOTICE"), 5);

	zephir_declare_class_constant_long(phalcon_logger_enum_ce, SL("WARNING"), 4);

	return SUCCESS;
}

