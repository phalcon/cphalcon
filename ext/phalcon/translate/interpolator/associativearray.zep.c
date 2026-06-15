
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class AssociativeArray
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Interpolator_AssociativeArray)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Translate\\Interpolator, AssociativeArray, phalcon, translate_interpolator_associativearray, phalcon_translate_interpolator_associativearray_method_entry, 0);

	/**
	 * @var Interpolate | null
	 */
	zend_declare_property_null(phalcon_translate_interpolator_associativearray_ce, SL("interpolate"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_translate_interpolator_associativearray_ce, 1, phalcon_translate_interpolator_interpolatorinterface_ce);
	return SUCCESS;
}

/**
 * Replaces placeholders by the values passed
 *
 * @phpstan-param array<string, string> $placeholders
 *
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Interpolator_AssociativeArray, replacePlaceholders)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval translation_zv, *placeholders_param = NULL, _0, _2, _1$$3;
	zend_string *translation = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translation_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
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
	zephir_memory_observe(&translation_zv);
	ZVAL_STR_COPY(&translation_zv, translation);
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("interpolate"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_support_helper_str_interpolate_ce);
		if (zephir_has_constructor(&_1$$3)) {
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		zephir_update_property_zval(this_ptr, ZEND_STRL("interpolate"), &_1$$3);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("interpolate"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_2, "__invoke", NULL, 0, &translation_zv, &placeholders);
	zephir_check_call_status();
	RETURN_MM();
}

