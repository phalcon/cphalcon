
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
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
/**
 * Class AssociativeArray
 *
 * @package Phalcon\Translate\Interpolator
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Interpolator_AssociativeArray)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Translate\\Interpolator, AssociativeArray, phalcon, translate_interpolator_associativearray, phalcon_translate_interpolator_associativearray_method_entry, 0);

	zend_class_implements(phalcon_translate_interpolator_associativearray_ce, 1, phalcon_translate_interpolator_interpolatorinterface_ce);
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
PHP_METHOD(Phalcon_Translate_Interpolator_AssociativeArray, replacePlaceholders)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval *translation_param = NULL, *placeholders_param = NULL, interpolate;
	zval translation;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translation);
	ZVAL_UNDEF(&interpolate);
	ZVAL_UNDEF(&placeholders);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(translation)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(placeholders)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &translation_param, &placeholders_param);
	if (UNEXPECTED(Z_TYPE_P(translation_param) != IS_STRING && Z_TYPE_P(translation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translation' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(translation_param) == IS_STRING)) {
		zephir_get_strval(&translation, translation_param);
	} else {
		ZEPHIR_INIT_VAR(&translation);
	}
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}


	ZEPHIR_INIT_VAR(&interpolate);
	object_init_ex(&interpolate, phalcon_support_helper_str_interpolate_ce);
	if (zephir_has_constructor(&interpolate)) {
		ZEPHIR_CALL_METHOD(NULL, &interpolate, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_RETURN_CALL_METHOD(&interpolate, "__invoke", NULL, 429, &translation, &placeholders);
	zephir_check_call_status();
	RETURN_MM();
}

