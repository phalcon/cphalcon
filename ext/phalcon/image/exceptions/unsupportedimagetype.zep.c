
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Image_Exceptions_UnsupportedImageType)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Image\\Exceptions, UnsupportedImageType, phalcon, image_exceptions_unsupportedimagetype, phalcon_image_exception_ce, phalcon_image_exceptions_unsupportedimagetype_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Image_Exceptions_UnsupportedImageType, __construct)
{
	zval _0$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval format_zv, message;
	zend_string *format = NULL;

	ZVAL_UNDEF(&format_zv);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0$$4);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(format)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!format) {
		format = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&format_zv);
		ZVAL_STR(&format_zv, format);
	} else {
		zephir_memory_observe(&format_zv);
	ZVAL_STR_COPY(&format_zv, format);
	}
	ZEPHIR_INIT_VAR(&message);
	if (ZEPHIR_IS_EMPTY(&format_zv)) {
		ZVAL_STRING(&message, "Installed GD does not support such images");
	} else {
		ZEPHIR_INIT_VAR(&_0$$4);
		ZEPHIR_CONCAT_SVS(&_0$$4, "Installed GD does not support ", &format_zv, " images");
		ZEPHIR_CPY_WRT(&message, &_0$$4);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_image_exceptions_unsupportedimagetype_ce, getThis(), "__construct", NULL, 0, &message);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

