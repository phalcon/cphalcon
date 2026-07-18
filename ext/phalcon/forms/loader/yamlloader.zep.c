
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Supplies form element definitions from a YAML string or file.
 *
 * Requires the PHP `yaml` extension (pecl/yaml).
 *
 * When $source is an existing, readable file path the file is parsed
 * directly; otherwise the value is treated as a raw YAML string.
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Loader_YamlLoader)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Forms\\Loader, YamlLoader, phalcon, forms_loader_yamlloader, phalcon_forms_loader_yamlloader_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_forms_loader_yamlloader_ce, SL("source"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_forms_loader_yamlloader_ce, 1, phalcon_contracts_forms_schema_ce);
	return SUCCESS;
}

/**
 * @param string $source YAML string or path to a YAML file
 */
PHP_METHOD(Phalcon_Forms_Loader_YamlLoader, __construct)
{
	zval source_zv;
	zend_string *source = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("source", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(source)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&source_zv, source);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 783, &source_zv);
}

/**
 * @phpstan-return array<int, array<string, mixed>>
 * @throws Exception
 */
PHP_METHOD(Phalcon_Forms_Loader_YamlLoader, load)
{
	zend_bool _5;
	zval definitions, loader, source, _0, _1, _3, _4, _6, _2$$3, _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&definitions);
	ZVAL_UNDEF(&loader);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_7$$6);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("source", 6, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "yaml");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "phpextensionloaded", NULL, 0, &_1);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_forms_exceptions_yamlextensionrequired_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Forms/Loader/YamlLoader.zep", 53);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 783, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&source, &_3);
	ZEPHIR_CALL_FUNCTION(&_4, "is_file", NULL, 429, &source);
	zephir_check_call_status();
	_5 = zephir_is_true(&_4);
	if (_5) {
		ZEPHIR_CALL_FUNCTION(&_6, "is_readable", NULL, 0, &source);
		zephir_check_call_status();
		_5 = zephir_is_true(&_6);
	}
	if (_5) {
		ZEPHIR_CALL_FUNCTION(&definitions, "yaml_parse_file", NULL, 432, &source);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&definitions, "yaml_parse", NULL, 0, &source);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&definitions) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_7$$6);
		object_init_ex(&_7$$6, phalcon_forms_exceptions_yamlschemanotarray_ce);
		ZEPHIR_CALL_METHOD(NULL, &_7$$6, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$6, "phalcon/Forms/Loader/YamlLoader.zep", 65);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&loader);
	object_init_ex(&loader, phalcon_forms_loader_arrayloader_ce);
	ZEPHIR_CALL_METHOD(NULL, &loader, "__construct", NULL, 0, &definitions);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&loader, "load", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Find out whether an extension is loaded
 *
 * @param string $name
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.extension-loaded.php
 */
PHP_METHOD(Phalcon_Forms_Loader_YamlLoader, phpExtensionLoaded)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_RETURN_CALL_FUNCTION("extension_loaded", NULL, 431, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return true if the given function has been defined
 *
 * @param string $functionName
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.function-exists.php
 */
PHP_METHOD(Phalcon_Forms_Loader_YamlLoader, phpFunctionExists)
{
	zval functionName_zv;
	zend_string *functionName = NULL;

	ZVAL_UNDEF(&functionName_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(functionName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&functionName_zv, functionName);
	RETURN_BOOL((zephir_function_exists(&functionName_zv) == SUCCESS));
}

