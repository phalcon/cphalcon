
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Translate\Adapter\Csv
 *
 * Allows to define translation lists using CSV file
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_Csv) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Translate\\Adapter, Csv, phalcon, translate_adapter_csv, phalcon_translate_adapter_ce, phalcon_translate_adapter_csv_method_entry, 0);

	zend_declare_property_null(phalcon_translate_adapter_csv_ce, SL("_translate"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_translate_adapter_csv_ce->create_object = zephir_init_properties_Phalcon_Translate_Adapter_Csv;

	zend_class_implements(phalcon_translate_adapter_csv_ce TSRMLS_CC, 1, phalcon_translate_adapterinterface_ce);
	zend_class_implements(phalcon_translate_adapter_csv_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * Phalcon\Translate\Adapter\Csv constructor
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, __construct) {

	zend_bool _12;
	zephir_fcall_cache_entry *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, *data = NULL, *file = NULL, *_0, *_2, _3 = zval_used_for_init, *_4 = NULL, *_5, *_6, *_7, *_8, *_10, _11 = zval_used_for_init, *_13, *_14 = NULL;
	zval *options = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	options = options_param;



	if (!(zephir_array_isset_string(options, SS("content")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_translate_exception_ce, "Parameter 'content' is required", "phalcon/translate/adapter/csv.zep", 43);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("delimiter"), SL(";"), 1);
	add_assoc_long_ex(_1, SS("length"), 0);
	add_assoc_stringl_ex(_1, SS("enclosure"), SL("\""), 1);
	zephir_fast_array_merge(_0, &(_1), &(options) TSRMLS_CC);
	ZEPHIR_CPY_WRT(options, _0);
	zephir_array_fetch_string(&_2, options, SL("content"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 52 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "rb", 0);
	ZEPHIR_CALL_FUNCTION(&file, "fopen", NULL, 291, _2, &_3);
	zephir_check_call_status();
	if (Z_TYPE_P(file) != IS_RESOURCE) {
		ZEPHIR_INIT_VAR(_4);
		object_init_ex(_4, phalcon_translate_exception_ce);
		zephir_array_fetch_string(&_5, options, SL("content"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 55 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_6);
		ZEPHIR_CONCAT_SVS(_6, "Error opening translation file '", _5, "'");
		ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, 9, _6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4, "phalcon/translate/adapter/csv.zep", 55 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	while (1) {
		zephir_array_fetch_string(&_5, options, SL("length"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 60 TSRMLS_CC);
		zephir_array_fetch_string(&_7, options, SL("delimiter"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 60 TSRMLS_CC);
		zephir_array_fetch_string(&_8, options, SL("enclosure"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 60 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&data, "fgetcsv", &_9, 422, file, _5, _7, _8);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(data)) {
			break;
		}
		zephir_array_fetch_long(&_10, data, 0, PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 65 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, 0);
		ZEPHIR_SINIT_NVAR(_11);
		ZVAL_LONG(&_11, 1);
		ZEPHIR_INIT_NVAR(_4);
		zephir_substr(_4, _10, 0 , 1 , 0);
		_12 = ZEPHIR_IS_STRING_IDENTICAL(_4, "#");
		if (!(_12)) {
			_12 = !(zephir_array_isset_long(data, 1));
		}
		if (_12) {
			continue;
		}
		zephir_array_fetch_long(&_13, data, 1, PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 69 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_14);
		zephir_array_fetch_long(&_14, data, 0, PH_NOISY, "phalcon/translate/adapter/csv.zep", 69 TSRMLS_CC);
		zephir_update_property_array(this_ptr, SL("_translate"), _14, _13 TSRMLS_CC);
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

static zend_object_value zephir_init_properties_Phalcon_Translate_Adapter_Csv(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_translate"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_translate"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

