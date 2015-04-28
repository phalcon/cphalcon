
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


/**
 * Phalcon\Annotations\Adapter\Memory
 *
 * Stores the parsed annotations in memory. This adapter is the suitable development/testing
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_Memory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Annotations\\Adapter, Memory, phalcon, annotations_adapter_memory, phalcon_annotations_adapter_ce, phalcon_annotations_adapter_memory_method_entry, 0);

	/**
	 * Data
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_annotations_adapter_memory_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_annotations_adapter_memory_ce TSRMLS_CC, 1, phalcon_annotations_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Reads parsed annotations from memory
 *
 * @param string key
 * @return Phalcon\Annotations\Reflection
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Memory, read) {

	zval *key_param = NULL, *data, *_0, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, key);
	if (zephir_array_isset_fetch(&data, _0, _1, 1 TSRMLS_CC)) {
		RETURN_CTOR(data);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Writes parsed annotations to memory
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Memory, write) {

	zval *key_param = NULL, *data, *lowercasedKey;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &data);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_INIT_VAR(lowercasedKey);
	zephir_fast_strtolower(lowercasedKey, key);
	zephir_update_property_array(this_ptr, SL("_data"), lowercasedKey, data TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

