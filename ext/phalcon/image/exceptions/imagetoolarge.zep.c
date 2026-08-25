
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
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Image_Exceptions_ImageTooLarge)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Image\\Exceptions, ImageTooLarge, phalcon, image_exceptions_imagetoolarge, phalcon_image_exception_ce, phalcon_image_exceptions_imagetoolarge_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Image_Exceptions_ImageTooLarge, __construct)
{
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *pixels_param = NULL, *maxPixels_param = NULL, _0, _1;
	zend_long pixels, maxPixels, ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(pixels)
		Z_PARAM_LONG(maxPixels)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &pixels_param, &maxPixels_param);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, pixels);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, maxPixels);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVSVS(&_2, "Image size ", &_0, " pixels exceeds the maximum allowed ", &_1, " pixels");
	ZEPHIR_CALL_PARENT(NULL, phalcon_image_exceptions_imagetoolarge_ce, getThis(), "__construct", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

