
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * @property array $translate
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_Csv)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Translate\\Adapter, Csv, phalcon, translate_adapter_csv, phalcon_translate_adapter_abstractadapter_ce, phalcon_translate_adapter_csv_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_translate_adapter_csv_ce, SL("translate"), ZEND_ACC_PROTECTED);
	phalcon_translate_adapter_csv_ce->create_object = zephir_init_properties_Phalcon_Translate_Adapter_Csv;

	zend_class_implements(phalcon_translate_adapter_csv_ce, 1, zend_ce_arrayaccess);
	return SUCCESS;
}

/**
 * Csv constructor.
 *
 * @param InterpolatorFactory $interpolator
 * @param array               $options = [
 *                                       'content'   => '',
 *                                       'delimiter' => ';',
 *                                       'enclosure' => '"'
 *                                       ]
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *interpolator, interpolator_sub, *options_param = NULL, delimiter, enclosure, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&interpolator_sub);
	ZVAL_UNDEF(&delimiter);
	ZVAL_UNDEF(&enclosure);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(interpolator, phalcon_translate_interpolatorfactory_ce)
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &interpolator, &options_param);
	zephir_get_arrval(&options, options_param);
	ZEPHIR_CALL_PARENT(NULL, phalcon_translate_adapter_csv_ce, getThis(), "__construct", NULL, 0, interpolator, &options);
	zephir_check_call_status();
	if (UNEXPECTED(!(zephir_array_isset_string(&options, SL("content"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_translate_exception_ce, "Parameter 'content' is required", "phalcon/Translate/Adapter/Csv.zep", 48);
		return;
	}
	if (zephir_array_isset_string(&options, SL("delimiter"))) {
		zephir_memory_observe(&delimiter);
		zephir_array_fetch_string(&delimiter, &options, SL("delimiter"), PH_NOISY, "phalcon/Translate/Adapter/Csv.zep", 52);
	} else {
		ZEPHIR_INIT_NVAR(&delimiter);
		ZVAL_STRING(&delimiter, ";");
	}
	if (zephir_array_isset_string(&options, SL("enclosure"))) {
		zephir_memory_observe(&enclosure);
		zephir_array_fetch_string(&enclosure, &options, SL("enclosure"), PH_NOISY, "phalcon/Translate/Adapter/Csv.zep", 58);
	} else {
		ZEPHIR_INIT_NVAR(&enclosure);
		ZVAL_STRING(&enclosure, "\"");
	}
	zephir_array_fetch_string(&_0, &options, SL("content"), PH_NOISY | PH_READONLY, "phalcon/Translate/Adapter/Csv.zep", 63);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 0, &_0, &_1, &delimiter, &enclosure);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Check whether is defined a translation key in the internal array
 *
 * @param string $index
 *
 * @return bool
 * @deprecated
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, exists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &index_param);
	if (UNEXPECTED(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(&index, index_param);
	} else {
		ZEPHIR_INIT_VAR(&index);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, &index);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Check whether is defined a translation key in the internal array
 *
 * @param string $index
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, has)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *index_param = NULL, _0;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &index_param);
	if (UNEXPECTED(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(&index, index_param);
	} else {
		ZEPHIR_INIT_VAR(&index);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("translate"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &index));
}

/**
 * Returns the translation related to the given key
 *
 * @param string $translateKey
 * @param array  $placeholders
 *
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, query)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval *translateKey_param = NULL, *placeholders_param = NULL, translation, _0;
	zval translateKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translateKey);
	ZVAL_UNDEF(&translation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&placeholders);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(translateKey)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(placeholders)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &translateKey_param, &placeholders_param);
	if (UNEXPECTED(Z_TYPE_P(translateKey_param) != IS_STRING && Z_TYPE_P(translateKey_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translateKey' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(translateKey_param) == IS_STRING)) {
		zephir_get_strval(&translateKey, translateKey_param);
	} else {
		ZEPHIR_INIT_VAR(&translateKey);
	}
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}
	zephir_memory_observe(&translation);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("translate"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&translation, &_0, &translateKey, 0))) {
		ZEPHIR_CPY_WRT(&translation, &translateKey);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "replaceplaceholders", NULL, 0, &translation, &placeholders);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Load translations from file
 *
 * @param string $file
 * @param int    $length
 * @param string $delimiter
 * @param string $enclosure
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, load)
{
	zend_bool _8$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *length_param = NULL, *delimiter_param = NULL, *enclosure_param = NULL, data, fileHandler, _0, _1$$3, _3$$4, _5$$4, _6$$4, _7$$4, _9$$4, _10$$4;
	zval file, delimiter, enclosure, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&delimiter);
	ZVAL_UNDEF(&enclosure);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&fileHandler);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_STR(file)
		Z_PARAM_LONG(length)
		Z_PARAM_STR(delimiter)
		Z_PARAM_STR(enclosure)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &file_param, &length_param, &delimiter_param, &enclosure_param);
	zephir_get_strval(&file, file_param);
	zephir_get_strval(&delimiter, delimiter_param);
	zephir_get_strval(&enclosure, enclosure_param);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "rb");
	ZEPHIR_CALL_METHOD(&fileHandler, this_ptr, "phpfopen", NULL, 0, &file, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&fileHandler) != IS_RESOURCE)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_translate_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Error opening translation file '", &file, "'");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 33, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Translate/Adapter/Csv.zep", 129);
		ZEPHIR_MM_RESTORE();
		return;
	}
	while (1) {
		ZVAL_LONG(&_3$$4, length);
		ZEPHIR_CALL_FUNCTION(&data, "fgetcsv", &_4, 0, &fileHandler, &_3$$4, &delimiter, &enclosure);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&data)) {
			break;
		}
		zephir_array_fetch_long(&_5$$4, &data, 0, PH_NOISY | PH_READONLY, "phalcon/Translate/Adapter/Csv.zep", 139);
		ZVAL_LONG(&_3$$4, 0);
		ZVAL_LONG(&_6$$4, 1);
		ZEPHIR_INIT_NVAR(&_7$$4);
		zephir_substr(&_7$$4, &_5$$4, 0 , 1 , 0);
		_8$$4 = ZEPHIR_IS_STRING_IDENTICAL(&_7$$4, "#");
		if (!(_8$$4)) {
			_8$$4 = !(zephir_array_isset_long(&data, 1));
		}
		if (_8$$4) {
			continue;
		}
		zephir_array_fetch_long(&_9$$4, &data, 1, PH_NOISY | PH_READONLY, "phalcon/Translate/Adapter/Csv.zep", 143);
		ZEPHIR_OBS_NVAR(&_10$$4);
		zephir_array_fetch_long(&_10$$4, &data, 0, PH_NOISY, "phalcon/Translate/Adapter/Csv.zep", 143);
		zephir_update_property_array(this_ptr, SL("translate"), &_10$$4, &_9$$4);
	}
	zephir_fclose(&fileHandler);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the internal array
 *
 * @return array
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, toArray)
{

	RETURN_MEMBER(getThis(), "translate");
}

/**
 * @todo to be removed when we get traits
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpFopen)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filename_param = NULL, *mode_param = NULL;
	zval filename, mode;

	ZVAL_UNDEF(&filename);
	ZVAL_UNDEF(&mode);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(filename)
		Z_PARAM_STR(mode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &filename_param, &mode_param);
	zephir_get_strval(&filename, filename_param);
	zephir_get_strval(&mode, mode_param);
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 140, &filename, &mode);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Translate_Adapter_Csv(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("translate"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("translate"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

