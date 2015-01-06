
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "translate/adapter/nativearray.h"
#include "translate/adapter.h"
#include "translate/adapterinterface.h"
#include "translate/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/string.h"

/**
 * Phalcon\Translate\Adapter\NativeArray
 *
 * Allows to define translation lists using PHP arrays
 *
 */
zend_class_entry *phalcon_translate_adapter_nativearray_ce;

static zend_object_handlers phalcon_translate_adapter_nativearray_object_handlers;

static zval* phalcon_translate_adapter_nativearray_read_dimension(zval *object, zval *offset, int type TSRMLS_DC)
{
	zval *translate, *translation;

	if (!is_phalcon_class(Z_OBJCE_P(object))) {
		return zend_get_std_object_handlers()->read_dimension(object, offset, type TSRMLS_CC);
	}

	translate = phalcon_fetch_nproperty_this(object, SL("_translate"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_fetch(&translation, translate, offset)) {
		return translation;
	}

	return offset;
}

static int phalcon_translate_adapter_nativearray_has_dimension(zval *object, zval *offset, int check_empty TSRMLS_DC)
{
	zval *translate, *translation;

	if (!is_phalcon_class(Z_OBJCE_P(object))) {
		return zend_get_std_object_handlers()->has_dimension(object, offset, check_empty TSRMLS_CC);
	}

	translate = phalcon_fetch_nproperty_this(object, SL("_translate"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset_fetch(&translation, translate, offset)) {
		return 0;
	}

	return (1 == check_empty) ? zend_is_true(translation) : 1;
}

PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, __construct);
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, query);
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, exists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_nativearray___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_translate_adapter_nativearray_method_entry[] = {
	PHP_ME(Phalcon_Translate_Adapter_NativeArray, __construct, arginfo_phalcon_translate_adapter_nativearray___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Translate_Adapter_NativeArray, query, arginfo_phalcon_translate_adapterinterface_query, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_NativeArray, exists, arginfo_phalcon_translate_adapterinterface_exists, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Translate\Adapter\NativeArray initializer
 */
PHALCON_INIT_CLASS(Phalcon_Translate_Adapter_NativeArray){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Translate\\Adapter, NativeArray, translate_adapter_nativearray, phalcon_translate_adapter_ce, phalcon_translate_adapter_nativearray_method_entry, 0);

	zend_declare_property_null(phalcon_translate_adapter_nativearray_ce, SL("_translate"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_translate_adapter_nativearray_ce TSRMLS_CC, 1, phalcon_translate_adapterinterface_ce);

	phalcon_translate_adapter_nativearray_object_handlers                = phalcon_translate_adapter_object_handlers;
	phalcon_translate_adapter_nativearray_object_handlers.read_dimension = phalcon_translate_adapter_nativearray_read_dimension;
	phalcon_translate_adapter_nativearray_object_handlers.has_dimension  = phalcon_translate_adapter_nativearray_has_dimension;

	return SUCCESS;
}

/**
 * Phalcon\Translate\Adapter\NativeArray constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, __construct){

	zval *options, *data;

	phalcon_fetch_params(0, 1, 0, &options);
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STRW(phalcon_translate_exception_ce, "Invalid options");
		return;
	}

	if (!phalcon_array_isset_string_fetch(&data, options, SS("content"))) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_translate_exception_ce, "Translation content was not provided");
		return;
	}

	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STRW(phalcon_translate_exception_ce, "Translation data must be an array");
		return;
	}
	
	phalcon_update_property_this(this_ptr, SL("_translate"), data TSRMLS_CC);

	Z_OBJ_HT_P(getThis()) = &phalcon_translate_adapter_nativearray_object_handlers;
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
	zval *key_placeholder, *replaced;
	HashPosition hp0;
	zval **value;

	phalcon_fetch_params(0, 1, 1, &index, &placeholders);
	
	if (!placeholders) {
		placeholders = PHALCON_GLOBAL(z_null);
	}
	
	translate = phalcon_fetch_nproperty_this(this_ptr, SL("_translate"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset_fetch(&translation, translate, index)) {
		translation = index;
	}

	if (Z_TYPE_P(placeholders) == IS_ARRAY && zend_hash_num_elements(Z_ARRVAL_P(placeholders))) {
		ALLOC_INIT_ZVAL(key_placeholder);
		Z_ADDREF_P(translation);

		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(placeholders), &hp0);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(placeholders), (void**)&value, &hp0) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(placeholders), &hp0)
		) {
			zval key = phalcon_get_current_key_w(Z_ARRVAL_P(placeholders), &hp0);

			PHALCON_CONCAT_SVS(key_placeholder, "%", &key, "%");

			ALLOC_INIT_ZVAL(replaced);
			phalcon_fast_str_replace(replaced, key_placeholder, *value, translation);
			zval_dtor(key_placeholder);

			zval_ptr_dtor(&translation);
			translation = replaced;
		}

		ZVAL_NULL(key_placeholder);
		zval_ptr_dtor(&key_placeholder);
		RETURN_ZVAL(translation, 1, 1);
	}

	RETURN_ZVAL(translation, 1, 0);
}

/**
 * Check whether is defined a translation key in the internal array
 *
 * @param string $index
 * @return bool
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, exists){

	zval **index;

	phalcon_fetch_params_ex(1, 0, &index);
	RETURN_BOOL(phalcon_translate_adapter_nativearray_has_dimension(getThis(), *index, 0 TSRMLS_CC));
}
