
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"

ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_Csv) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Translate\\Adapter, Csv, phalcon, translate_adapter_csv, phalcon_translate_adapter_ce, phalcon_translate_adapter_csv_method_entry, 0);

	zend_declare_property_null(phalcon_translate_adapter_csv_ce, SL("_translate"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_translate_adapter_csv_ce TSRMLS_CC, 1, phalcon_translate_adapterinterface_ce);
	zend_class_implements(phalcon_translate_adapter_csv_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * Phalcon\Translate\Adapter\Csv constructor
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, __construct) {

	zend_bool _13;
	zephir_fcall_cache_entry *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, *_0, *data = NULL, *file = NULL, *_1, *_3, _4 = zval_used_for_init, *_5 = NULL, *_6, *_7, *_8, *_9, *_11, _12 = zval_used_for_init, *_14, *_15 = NULL;
	zval *options = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	options = options_param;



	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_translate"), _0 TSRMLS_CC);
	if (!(zephir_array_isset_string(options, SS("content")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_translate_exception_ce, "Parameter 'content' is required", "phalcon/translate/adapter/csv.zep", 43);
		return;
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_2, SS("delimiter"), SL(";"), 1);
	add_assoc_long_ex(_2, SS("length"), 0);
	add_assoc_stringl_ex(_2, SS("enclosure"), SL("\""), 1);
	zephir_fast_array_merge(_1, &(_2), &(options) TSRMLS_CC);
	ZEPHIR_CPY_WRT(options, _1);
	zephir_array_fetch_string(&_3, options, SL("content"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 52 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "rb", 0);
	ZEPHIR_CALL_FUNCTION(&file, "fopen", NULL, 276, _3, &_4);
	zephir_check_call_status();
	if (Z_TYPE_P(file) != IS_RESOURCE) {
		ZEPHIR_INIT_VAR(_5);
		object_init_ex(_5, phalcon_translate_exception_ce);
		zephir_array_fetch_string(&_6, options, SL("content"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 55 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_SVS(_7, "Error opening translation file '", _6, "'");
		ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, 2, _7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5, "phalcon/translate/adapter/csv.zep", 55 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	while (1) {
		zephir_array_fetch_string(&_6, options, SL("length"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 60 TSRMLS_CC);
		zephir_array_fetch_string(&_8, options, SL("delimiter"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 60 TSRMLS_CC);
		zephir_array_fetch_string(&_9, options, SL("enclosure"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 60 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&data, "fgetcsv", &_10, 417, file, _6, _8, _9);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(data)) {
			break;
		}
		zephir_array_fetch_long(&_11, data, 0, PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 65 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 0);
		ZEPHIR_SINIT_NVAR(_12);
		ZVAL_LONG(&_12, 1);
		ZEPHIR_INIT_NVAR(_5);
		zephir_substr(_5, _11, 0 , 1 , 0);
		_13 = ZEPHIR_IS_STRING_IDENTICAL(_5, "#");
		if (!(_13)) {
			_13 = !(zephir_array_isset_long(data, 1));
		}
		if (_13) {
			continue;
		}
		zephir_array_fetch_long(&_14, data, 1, PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 69 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_15);
		zephir_array_fetch_long(&_15, data, 0, PH_NOISY, "phalcon/translate/adapter/csv.zep", 69 TSRMLS_CC);
		zephir_update_property_array(this_ptr, SL("_translate"), _15, _14 TSRMLS_CC);
	}
	zephir_fclose(file TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the translation related to the given key
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, query) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *placeholders = NULL, *translation = NULL, *_0;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &index_param, &placeholders);

	if (unlikely(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(index, index_param);
	} else {
		ZEPHIR_INIT_VAR(index);
		ZVAL_EMPTY_STRING(index);
	}
	if (!placeholders) {
		placeholders = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(translation);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_translate"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&translation, _0, index, 0 TSRMLS_CC))) {
		ZEPHIR_CPY_WRT(translation, index);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "replaceplaceholders", NULL, 0, translation, placeholders);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether is defined a translation key in the internal array
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, exists) {

	zval *index_param = NULL, *_0;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	if (unlikely(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(index, index_param);
	} else {
		ZEPHIR_INIT_VAR(index);
		ZVAL_EMPTY_STRING(index);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_translate"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, index));

}

