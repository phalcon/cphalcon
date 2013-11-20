
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
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"


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
* Phalcon\Translate\Adapter\NativeArray
*
* Allows to define translation lists using PHP arrays
*
*/
ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_NativeArray) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Translate\\Adapter, NativeArray, phalcon, translate_adapter_nativearray, phalcon_translate_adapter_nativearray_method_entry, 0);

	zend_declare_property_null(phalcon_translate_adapter_nativearray_ce, SL("_translate"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Translate\Adapter\NativeArray constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, __construct) {

	zval *options, *data;

	zephir_fetch_params(0, 1, 0, &options);



	if ((Z_TYPE_P(options) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_translate_exception_ce, "Invalid options");
		return;
	}
	if (!(zephir_array_isset_string_fetch(&data, options, SS("content"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_translate_exception_ce, "Translation content was not provided");
		return;
	}
	if ((Z_TYPE_P(data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_translate_exception_ce, "Translation data must be an array");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_translate"), data TSRMLS_CC);

}

/**
 * Returns the translation related to the given key
 *
 * @param string  index
 * @param array   placeholders
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, query) {

	HashTable *_2;
	HashPosition _1;
	zval *index_param = NULL, *placeholders = NULL, *traslation = NULL, *key = NULL, *value = NULL, *_0, **_3, *_4 = NULL, *_5 = NULL;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &index_param, &placeholders);

		if (Z_TYPE_P(index_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		index = index_param;

	if (!placeholders || Z_TYPE_P(placeholders) == IS_NULL) {
		placeholders = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(traslation);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_translate"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&traslation, _0, index, 0 TSRMLS_CC)) {
		if ((Z_TYPE_P(placeholders) == IS_ARRAY)) {
			if (zephir_fast_count_int(placeholders TSRMLS_CC)) {
				zephir_is_iterable(placeholders, &_2, &_1, 0, 0);
				for (
					; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
					; zend_hash_move_forward_ex(_2, &_1)
				) {
					ZEPHIR_GET_HMKEY(key, _2, _1);
					ZEPHIR_GET_HVALUE(value, _3);
					ZEPHIR_INIT_LNVAR(_4);
					ZEPHIR_CONCAT_SVS(_4, "%", key, "%");
					ZEPHIR_INIT_NVAR(_5);
					zephir_call_func_p3(_5, "str_replace", _4, value, traslation);
					ZEPHIR_CPY_WRT(traslation, _5);
				}
			}
		}
		RETURN_CCTOR(traslation);
	}
	RETURN_CTOR(index);

}

/**
 * Check whether is defined a translation key in the internal array
 *
 * @param    string index
 * @return   bool
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, exists) {

	zval *index_param = NULL, *_0;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

		if (Z_TYPE_P(index_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		index = index_param;



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_translate"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, index));

}

