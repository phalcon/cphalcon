
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/file.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/string.h"

/**
 * Phalcon\Translate\Adapter\NativeArray
 *
 * Allows to define translation lists using PHP arrays
 *
 */


/**
 * Phalcon\Translate\Adapter\NativeArray initializer
 */
PHALCON_INIT_CLASS(Phalcon_Translate_Adapter_NativeArray){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Translate\\Adapter, NativeArray, translate_adapter_nativearray, "phalcon\\translate\\adapter", phalcon_translate_adapter_nativearray_method_entry, 0);

	zend_declare_property_null(phalcon_translate_adapter_nativearray_ce, SL("_translate"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_translate_adapter_nativearray_ce TSRMLS_CC, 1, phalcon_translate_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Translate\Adapter\NativeArray constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, __construct){

	zval *options, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &options);
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_translate_exception_ce, "Invalid options");
		return;
	}
	if (!phalcon_array_isset_string(options, SS("content"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_translate_exception_ce, "Translation content was not provided");
		return;
	}
	
	PHALCON_OBS_VAR(data);
	phalcon_array_fetch_string(&data, options, SL("content"), PH_NOISY_CC);
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_translate_exception_ce, "Translation data must be an array");
		return;
	}
	
	phalcon_update_property_this(this_ptr, SL("_translate"), data TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the translation related to the given key
 *
 * @param string $index
 * @param array $placeholders
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, query){

	zval *index, *placeholders = NULL, *translate, *translation = NULL;
	zval *value = NULL, *key = NULL, *key_placeholder = NULL, *replaced = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &index, &placeholders);
	
	if (!placeholders) {
		PHALCON_INIT_VAR(placeholders);
	}
	
	PHALCON_OBS_VAR(translate);
	phalcon_read_property_this(&translate, this_ptr, SL("_translate"), PH_NOISY_CC);
	if (phalcon_array_isset(translate, index)) {
	
		PHALCON_OBS_VAR(translation);
		phalcon_array_fetch(&translation, translate, index, PH_NOISY_CC);
		if (Z_TYPE_P(placeholders) == IS_ARRAY) { 
			if (phalcon_fast_count_ev(placeholders TSRMLS_CC)) {
	
				if (!phalcon_is_iterable(placeholders, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
					return;
				}
	
				while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
					PHALCON_GET_HKEY(key, ah0, hp0);
					PHALCON_GET_HVALUE(value);
	
					PHALCON_INIT_NVAR(key_placeholder);
					PHALCON_CONCAT_SVS(key_placeholder, "%", key, "%");
	
					PHALCON_INIT_NVAR(replaced);
					phalcon_fast_str_replace(replaced, key_placeholder, value, translation TSRMLS_CC);
					PHALCON_CPY_WRT(translation, replaced);
	
					zend_hash_move_forward_ex(ah0, &hp0);
				}
	
			}
		}
	
		RETURN_CCTOR(translation);
	}
	
	RETURN_CCTOR(index);
}

/**
 * Check whether is defined a translation key in the internal array
 *
 * @param 	string $index
 * @return bool
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, exists){

	zval *index, *translate, *exists = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &index);
	
	PHALCON_OBS_VAR(translate);
	phalcon_read_property_this(&translate, this_ptr, SL("_translate"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, phalcon_array_isset(translate, index));
	PHALCON_CPY_WRT(exists, r0);
	RETURN_NCTOR(exists);
}

