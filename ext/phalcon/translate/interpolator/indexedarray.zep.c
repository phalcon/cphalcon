
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class IndexedArray
 *
 * @package Phalcon\Translate\Interpolator
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Interpolator_IndexedArray)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Translate\\Interpolator, IndexedArray, phalcon, translate_interpolator_indexedarray, phalcon_translate_interpolator_indexedarray_method_entry, 0);

	zend_class_implements(phalcon_translate_interpolator_indexedarray_ce, 1, phalcon_translate_interpolator_interpolatorinterface_ce);
	return SUCCESS;
}

/**
 * Replaces placeholders by the values passed
 *
 * @param string $translation
 * @param array  $placeholders
 *
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Interpolator_IndexedArray, replacePlaceholders)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval translation_zv, *placeholders_param = NULL, _0$$3;
	zend_string *translation = NULL;

	ZVAL_UNDEF(&translation_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&placeholders);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(translation)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(placeholders, placeholders_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		placeholders_param = ZEND_CALL_ARG(execute_data, 2);
	}
	ZVAL_STR_COPY(&translation_zv, translation);
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}
	if (1 != ZEPHIR_IS_EMPTY(&placeholders)) {
		ZEPHIR_MAKE_REF(&placeholders);
		ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 293, &placeholders, &translation_zv);
		ZEPHIR_UNREF(&placeholders);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "sprintf");
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0$$3, &placeholders);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_STR(zend_string_copy(translation));
}

