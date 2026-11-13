
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/require.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * The Phalcon Autoloader provides an easy way to automatically load classes
 * (namespaced or not) as well as files. It also features extension loading,
 * allowing the user to autoload files with different extensions than .php.
 *
 * @phpstan-import-type autoload_namespaces from AutoloadTypes
 * @phpstan-import-type autoload_strings from AutoloadTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Autoload_Loader)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Autoload, Loader, phalcon, autoload_loader, phalcon_autoload_loader_method_entry, 0);

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_autoload_loader_ce, SL("checkedPath"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING|MAY_BE_NULL, NULL, 0);
	}

	/**
	 * @var autoload_strings
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_autoload_loader_ce, SL("classes"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @var array<int, string>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_autoload_loader_ce, SL("debug"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @var autoload_strings
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_autoload_loader_ce, SL("directories"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @var autoload_strings
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_autoload_loader_ce, SL("extensions"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Always holds a callable. The setter accepts a callable or a callable
	 * string and rejects anything else.
	 *
	 * @var callable
	 */
	zend_declare_property_string(phalcon_autoload_loader_ce, SL("fileCheckingCallback"), "is_file", ZEND_ACC_PROTECTED);
	/**
	 * @var autoload_strings
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_autoload_loader_ce, SL("files"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_autoload_loader_ce, SL("foundPath"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING|MAY_BE_NULL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_autoload_loader_ce, SL("isDebug"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_autoload_loader_ce, SL("isRegistered"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * @var autoload_namespaces
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_autoload_loader_ce, SL("namespaces"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 0);
		zephir_declare_typed_property(phalcon_autoload_loader_ce, SL("nestingLevel"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_autoload_loader_ce, SL("eventsManager"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Events\\ManagerInterface"));
	}

	return SUCCESS;
}

/**
 * Loader constructor.
 */
PHP_METHOD(Phalcon_Autoload_Loader, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *isDebug_param = NULL, __$true, __$false, _0, _1;
	zend_bool isDebug;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("isDebug", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(isDebug)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &isDebug_param);
	if (!isDebug_param) {
		isDebug = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "php");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "php");
	zephir_update_property_array(this_ptr, SL("extensions"), &_0, &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (isDebug) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 490, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 490, &__$false);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Adds a class to the internal collection for the mapping
 */
PHP_METHOD(Phalcon_Autoload_Loader, addClass)
{
	zval name_zv, file_zv;
	zend_string *name = NULL, *file = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&file_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_STR(file)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	ZVAL_STR(&file_zv, file);
	zephir_update_property_array(this_ptr, SL("classes"), &name_zv, &file_zv);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_THISW();
}

/**
 * Adds a directory for the loaded files
 */
PHP_METHOD(Phalcon_Autoload_Loader, addDirectory)
{
	zval directory_zv;
	zend_string *directory = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directory_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(directory)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&directory_zv, directory);
	zephir_update_property_array(this_ptr, SL("directories"), &directory_zv, &directory_zv);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_THISW();
}

/**
 * Adds an extension for the loaded files
 */
PHP_METHOD(Phalcon_Autoload_Loader, addExtension)
{
	zval extension_zv;
	zend_string *extension = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extension_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(extension)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&extension_zv, extension);
	zephir_update_property_array(this_ptr, SL("extensions"), &extension_zv, &extension_zv);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_THISW();
}

/**
 * Adds a file to be added to the loader
 */
PHP_METHOD(Phalcon_Autoload_Loader, addFile)
{
	zval file_zv;
	zend_string *file = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(file)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&file_zv, file);
	zephir_update_property_array(this_ptr, SL("files"), &file_zv, &file_zv);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_THISW();
}

/**
 * @param autoload_strings|string $directories
 */
PHP_METHOD(Phalcon_Autoload_Loader, addNamespace)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool prepend, _4;
	zval name_zv, *directories = NULL, directories_sub, *prepend_param = NULL, dirSeparator, nsName, nsSeparator, source, target, _0, _1, _2, _3, _6, _7, _8, _5$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&directories_sub);
	ZVAL_UNDEF(&dirSeparator);
	ZVAL_UNDEF(&nsName);
	ZVAL_UNDEF(&nsSeparator);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_5$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("namespaces", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(directories)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(prepend)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	directories = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		prepend_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_SEPARATE_PARAM(directories);
	if (!prepend_param) {
		prepend = 0;
	} else {
		}
	ZEPHIR_CPY_WRT(&nsName, &name_zv);
	ZEPHIR_INIT_VAR(&nsSeparator);
	ZVAL_STRING(&nsSeparator, "\\");
	ZEPHIR_INIT_VAR(&dirSeparator);
	ZVAL_STRING(&dirSeparator, "/");
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_trim(&_0, &nsName, &nsSeparator, ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &_0, &nsSeparator);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&nsName, &_1);
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "checkDirectories", &_zephir_call_cache[0], directories, &dirSeparator, &name_zv);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(directories, &_2);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 491, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_4 = zephir_array_isset_value(&_3, &nsName);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_4)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		array_init(&_5$$3);
		zephir_update_property_array(this_ptr, SL("namespaces"), &nsName, &_5$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (prepend) {
		ZEPHIR_CPY_WRT(&source, directories);
	} else {
		zephir_read_property_cached(&_6, this_ptr, _zephir_prop_0, 491, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(&source);
		zephir_array_fetch(&source, &_6, &nsName, PH_NOISY, "phalcon/Autoload/Loader.zep", 139);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (prepend) {
		zephir_read_property_cached(&_7, this_ptr, _zephir_prop_0, 491, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&target);
		zephir_array_fetch(&target, &_7, &nsName, PH_NOISY, "phalcon/Autoload/Loader.zep", 140);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CPY_WRT(&target, directories);
	}
	ZEPHIR_INIT_VAR(&_8);
	zephir_fast_array_merge(&_8, &source, &target);
	ZEPHIR_CALL_FUNCTION(&_2, "array_unique", NULL, 108, &_8);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("namespaces"), &nsName, &_2);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Autoloads the registered classes
 * @throws EventsException
 */
PHP_METHOD(Phalcon_Autoload_Loader, autoload)
{
	zval _5, _8$$4, _10$$5, _14$$6;
	zend_bool result = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, _0, _2, _3, _4, _6, _7, _16, _1$$3, _9$$4, _11$$5, _12$$5, _13$$5, _15$$6;
	zend_string *className = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_14$$6);
	ZEND_TLS zephir_method_cache _zephir_call_cache[9];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("nestingLevel", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("debug", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("directories", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 492, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_LONG_IDENTICAL(&_0, 0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 493, &_1$$3);
	}
	result = 1;
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 492, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_INIT_VAR(&_4);
	zephir_add_function(&_4, &_2, &_3);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 492, &_4);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SV(&_5, "Loading: ", &className_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addDebug", &_zephir_call_cache[0], &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "loader:beforeCheckClass");
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireManagerEvent", &_zephir_call_cache[1], &_6, &className_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_7, this_ptr, "autoloadCheckClasses", &_zephir_call_cache[2], &className_zv);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_7)) {
		ZEPHIR_INIT_VAR(&_8$$4);
		ZEPHIR_CONCAT_SV(&_8$$4, "Class: 404: ", &className_zv);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addDebug", &_zephir_call_cache[3], &_8$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_9$$4, this_ptr, "autoloadCheckNamespaces", &_zephir_call_cache[4], &className_zv);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_9$$4)) {
			ZEPHIR_INIT_VAR(&_10$$5);
			ZEPHIR_CONCAT_SV(&_10$$5, "Namespace: 404: ", &className_zv);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addDebug", &_zephir_call_cache[5], &_10$$5);
			zephir_check_call_status();
			zephir_read_property_cached(&_12$$5, this_ptr, _zephir_prop_2, 494, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZVAL_BOOL(&_13$$5, 1);
			ZEPHIR_CALL_METHOD_CACHED(&_11$$5, this_ptr, "autoloadCheckDirectories", &_zephir_call_cache[6], &_12$$5, &className_zv, &_13$$5);
			zephir_check_call_status();
			if (!ZEPHIR_IS_TRUE_IDENTICAL(&_11$$5)) {
				ZEPHIR_INIT_VAR(&_14$$6);
				ZEPHIR_CONCAT_SV(&_14$$6, "Directories: 404: ", &className_zv);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addDebug", &_zephir_call_cache[7], &_14$$6);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_15$$6);
				ZVAL_STRING(&_15$$6, "loader:afterCheckClass");
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireManagerEvent", &_zephir_call_cache[8], &_15$$6, &className_zv);
				zephir_check_call_status();
				result = 0;
			}
		}
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 492, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_INIT_VAR(&_16);
	zephir_sub_function(&_16, &_2, &_3);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 492, &_16);
	RETURN_MM_BOOL(result);
}

/**
 * Get the path the loader is checking for a path
 */
PHP_METHOD(Phalcon_Autoload_Loader, getCheckedPath)
{

	RETURN_MEMBER(getThis(), "checkedPath");
}

/**
 * Returns the class-map currently registered in the autoloader
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Autoload_Loader, getClasses)
{

	RETURN_MEMBER_TYPED(getThis(), "classes", IS_ARRAY);
}

/**
 * Returns debug information collected
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Autoload_Loader, getDebug)
{

	RETURN_MEMBER_TYPED(getThis(), "debug", IS_ARRAY);
}

/**
 * Returns the directories currently registered in the autoloader
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Autoload_Loader, getDirectories)
{

	RETURN_MEMBER_TYPED(getThis(), "directories", IS_ARRAY);
}

/**
 * Returns the file extensions registered in the loader
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Autoload_Loader, getExtensions)
{

	RETURN_MEMBER_TYPED(getThis(), "extensions", IS_ARRAY);
}

/**
 * Returns the files currently registered in the autoloader
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Autoload_Loader, getFiles)
{

	RETURN_MEMBER_TYPED(getThis(), "files", IS_ARRAY);
}

/**
 * Get the path when a class was found
 */
PHP_METHOD(Phalcon_Autoload_Loader, getFoundPath)
{

	RETURN_MEMBER(getThis(), "foundPath");
}

/**
 * Returns the namespaces currently registered in the autoloader
 *
 * @return autoload_namespaces
 */
PHP_METHOD(Phalcon_Autoload_Loader, getNamespaces)
{

	RETURN_MEMBER_TYPED(getThis(), "namespaces", IS_ARRAY);
}

/**
 * Returns isRegistered
 */
PHP_METHOD(Phalcon_Autoload_Loader, isRegistered)
{

	RETURN_MEMBER(getThis(), "isRegistered");
}

/**
 * Checks if a file exists and then adds the file by doing virtual require
 */
PHP_METHOD(Phalcon_Autoload_Loader, loadFiles)
{
	zend_bool _6;
	zval file, files, _0, *_1, _2, *_3, _5, _4$$3, _7$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("files", 5, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 495, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&files, &_0);
	if (Z_TYPE_P(&files) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &files);
		_1 = &_2;
	} else {
		_1 = &files;
	}
	zephir_is_iterable(_1, 0, "phalcon/Autoload/Loader.zep", 300);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _3);
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "loader:beforeCheckPath");
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireManagerEvent", &_zephir_call_cache[0], &_4$$3, &file);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "requireFile", &_zephir_call_cache[1], &file);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[2]);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[3]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_5, _1, "valid", &_zephir_call_cache[4]);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&file, _1, "current", &_zephir_call_cache[5]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_7$$4);
				ZVAL_STRING(&_7$$4, "loader:beforeCheckPath");
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireManagerEvent", &_zephir_call_cache[6], &_7$$4, &file);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "requireFile", &_zephir_call_cache[7], &file);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&file);
	ZEPHIR_MM_RESTORE();
}

/**
 * Register the autoload method
 *
 * @throws EventsException
 */
PHP_METHOD(Phalcon_Autoload_Loader, register)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prepend_param = NULL, __$true, __$false, _0, _1$$3;
	zend_bool prepend;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("isRegistered", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(prepend)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &prepend_param);
	if (!prepend_param) {
		prepend = 0;
	} else {
		}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 496, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "loadFiles", &_zephir_call_cache[0]);
		zephir_check_call_status();
		if (prepend) {
			ZVAL_BOOL(&_1$$3, 1);
		} else {
			ZVAL_BOOL(&_1$$3, 0);
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "registerAutoload", &_zephir_call_cache[1], &_1$$3);
		zephir_check_call_status();
		if (1) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 496, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 496, &__$false);
		}
	}
	RETURN_THIS();
}

/**
 * Register classes and their locations
 *
 * @param autoload_strings $classes
 */
PHP_METHOD(Phalcon_Autoload_Loader, setClasses)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge, _5;
	zval *classes_param = NULL, *merge_param = NULL, className, name, *_1, _4, _0$$3;
	zval classes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classes);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("classes", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(classes, classes_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &classes_param, &merge_param);
	zephir_get_arrval(&classes, classes_param);
	if (!merge_param) {
		merge = 0;
	} else {
		}
	if (!merge) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 497, &_0$$3);
	}
	zephir_is_iterable(&classes, 0, "phalcon/Autoload/Loader.zep", 336);
	if (Z_TYPE_P(&classes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&classes), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&name, _3);
			} else {
				ZVAL_LONG(&name, _2);
			}
			ZEPHIR_INIT_NVAR(&className);
			ZVAL_COPY(&className, _1);
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addClass", &_zephir_call_cache[0], &name, &className);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &classes, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &classes, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_4, &classes, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&name, &classes, "key", &_zephir_call_cache[4]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&className, &classes, "current", &_zephir_call_cache[5]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addClass", &_zephir_call_cache[6], &name, &className);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&className);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_THIS();
}

/**
 * Register directories in which "not found" classes could be found
 *
 * @param autoload_strings $directories
 */
PHP_METHOD(Phalcon_Autoload_Loader, setDirectories)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge;
	zval *directories_param = NULL, *merge_param = NULL, _0, _1, _2;
	zval directories;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directories);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(directories, directories_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &directories_param, &merge_param);
	zephir_get_arrval(&directories, directories_param);
	if (!merge_param) {
		merge = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "directories");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "addDirectory");
	if (merge) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "addToCollection", &_zephir_call_cache[0], &directories, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets an array of file extensions that the loader must try in each attempt
 * to locate the file
 *
 * @param autoload_strings $extensions
 */
PHP_METHOD(Phalcon_Autoload_Loader, setExtensions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge, _5;
	zval *extensions_param = NULL, *merge_param = NULL, extension, *_3, _4, _0$$3, _1$$3, _2$$3;
	zval extensions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("extensions", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(extensions, extensions_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &extensions_param, &merge_param);
	zephir_get_arrval(&extensions, extensions_param);
	if (!merge_param) {
		merge = 0;
	} else {
		}
	if (!merge) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 498, &_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "php");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "php");
		zephir_update_property_array(this_ptr, SL("extensions"), &_1$$3, &_2$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_is_iterable(&extensions, 0, "phalcon/Autoload/Loader.zep", 373);
	if (Z_TYPE_P(&extensions) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extensions), _3)
		{
			ZEPHIR_INIT_NVAR(&extension);
			ZVAL_COPY(&extension, _3);
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addExtension", &_zephir_call_cache[0], &extension);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &extensions, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &extensions, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_4, &extensions, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&extension, &extensions, "current", &_zephir_call_cache[4]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addExtension", &_zephir_call_cache[5], &extension);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&extension);
	RETURN_THIS();
}

/**
 * Sets the file check callback.
 *
 * ```php
 * // Default behavior.
 * $loader->setFileCheckingCallback("is_file");
 *
 * // Faster than `is_file()`, but implies some issues if
 * // the file is removed from the filesystem.
 * $loader->setFileCheckingCallback("stream_resolve_include_path");
 *
 * // Do not check file existence.
 * $loader->setFileCheckingCallback(null);
 * ```
 *
 * @param callable|string|null $method
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Autoload_Loader, setFileCheckingCallback)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL, method_sub, __$null, _0$$4, _1$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("fileCheckingCallback", 20, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(method)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &method);
	if (!method) {
		method = &method_sub;
		method = &__$null;
	}
	if (1 == zephir_is_callable(method)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 499, method);
	} else if (Z_TYPE_P(method) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$4);
		ZEPHIR_INIT_NVAR(&_0$$4);
		zephir_create_closure_ex(&_0$$4, NULL, phalcon_7__closure_ce, SL("__invoke"));
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 499, &_0$$4);
	} else {
		ZEPHIR_INIT_VAR(&_1$$5);
		object_init_ex(&_1$$5, phalcon_autoload_exceptions_loadermethodnotcallable_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$5, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$5, "phalcon/Autoload/Loader.zep", 404);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Registers files that are "non-classes" hence need a "require". This is
 * very useful for including files that only have functions
 *
 * @param autoload_strings $files
 */
PHP_METHOD(Phalcon_Autoload_Loader, setFiles)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge;
	zval *files_param = NULL, *merge_param = NULL, _0, _1, _2;
	zval files;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(files, files_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &files_param, &merge_param);
	zephir_get_arrval(&files, files_param);
	if (!merge_param) {
		merge = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "files");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "addFile");
	if (merge) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "addToCollection", &_zephir_call_cache[0], &files, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Register namespaces and their related directories
 *
 * @param autoload_namespaces $namespaces
 */
PHP_METHOD(Phalcon_Autoload_Loader, setNamespaces)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge, _5;
	zval *namespaces_param = NULL, *merge_param = NULL, directories, name, *_1, _4, _0$$3;
	zval namespaces;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&directories);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("namespaces", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(namespaces, namespaces_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &namespaces_param, &merge_param);
	zephir_get_arrval(&namespaces, namespaces_param);
	if (!merge_param) {
		merge = 0;
	} else {
		}
	if (!merge) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 491, &_0$$3);
	}
	zephir_is_iterable(&namespaces, 0, "phalcon/Autoload/Loader.zep", 443);
	if (Z_TYPE_P(&namespaces) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&namespaces), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&name, _3);
			} else {
				ZVAL_LONG(&name, _2);
			}
			ZEPHIR_INIT_NVAR(&directories);
			ZVAL_COPY(&directories, _1);
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addNamespace", &_zephir_call_cache[0], &name, &directories);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &namespaces, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &namespaces, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_4, &namespaces, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&name, &namespaces, "key", &_zephir_call_cache[4]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&directories, &namespaces, "current", &_zephir_call_cache[5]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addNamespace", &_zephir_call_cache[6], &name, &directories);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&directories);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_THIS();
}

/**
 * Unregister the autoload method
 */
PHP_METHOD(Phalcon_Autoload_Loader, unregister)
{
	zval _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, _0, _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("isRegistered", 12, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 496, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0);
		zephir_array_fast_append(&_1$$3, this_ptr);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "autoload");
		zephir_array_fast_append(&_1$$3, &_2$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_unregister", NULL, 109, &_1$$3);
		zephir_check_call_status();
		if (0) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 496, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 496, &__$false);
		}
	}
	RETURN_THIS();
}

/**
 * If the file exists, require it and return true; false otherwise
 *
 * @throws EventsException
 */
PHP_METHOD(Phalcon_Autoload_Loader, requireFile)
{
	zval _4, _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval file_zv, _0, _1, _2$$3;
	zend_string *file = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("fileCheckingCallback", 20, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("foundPath", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(file)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&file_zv);
	ZVAL_STR_COPY(&file_zv, file);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 499, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_1, "call_user_func", NULL, 34, &_0, &file_zv);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 500, &file_zv);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "loader:pathFound");
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireManagerEvent", &_zephir_call_cache[0], &_2$$3, &file_zv);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, "Require: ", &file_zv);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addDebug", &_zephir_call_cache[1], &_3$$3);
		zephir_check_call_status();
		if (zephir_require_once_zval(&file_zv) == FAILURE) {
			RETURN_MM_NULL();
		}
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SV(&_4, "Require: 404: ", &file_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addDebug", &_zephir_call_cache[2], &_4);
	zephir_check_call_status();
	RETURN_MM_BOOL(0);
}

/**
 * Adds a debugging message in the collection
 */
PHP_METHOD(Phalcon_Autoload_Loader, addDebug)
{
	zval message_zv, _0;
	zend_string *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("isDebug", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&message_zv, message);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 490, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		zephir_update_property_array_append(this_ptr, SL("debug"), &message_zv);
		if (UNEXPECTED(EG(exception))) {
			return;
		}
	}
}

/**
 * Traverses a collection and adds elements to it using the relevant
 * class method
 *
 * @param autoload_strings $collection
 */
PHP_METHOD(Phalcon_Autoload_Loader, addToCollection)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge, _3;
	zend_string *collectionName = NULL, *method = NULL;
	zval *collection_param = NULL, collectionName_zv, method_zv, *merge_param = NULL, element, *_1, _2, _0$$3;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&collectionName_zv);
	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	ZEND_PARSE_PARAMETERS_START(3, 4)
		ZEPHIR_Z_PARAM_ARRAY(collection, collection_param)
		Z_PARAM_STR(collectionName)
		Z_PARAM_STR(method)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	collection_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 3) {
		merge_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_get_arrval(&collection, collection_param);
	zephir_memory_observe(&collectionName_zv);
	ZVAL_STR_COPY(&collectionName_zv, collectionName);
	zephir_memory_observe(&method_zv);
	ZVAL_STR_COPY(&method_zv, method);
	if (!merge_param) {
		merge = 0;
	} else {
		}
	if (!merge) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		zephir_update_property_zval_zval(this_ptr, &collectionName_zv, &_0$$3);
	}
	zephir_is_iterable(&collection, 0, "phalcon/Autoload/Loader.zep", 529);
	if (Z_TYPE_P(&collection) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&collection), _1)
		{
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _1);
			ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &method_zv, NULL, 0, &element);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &collection, "rewind", &_zephir_call_cache[0]);
		zephir_check_call_status();
		_3 = 1;
		while (1) {
			if (_3) {
				_3 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &collection, "next", &_zephir_call_cache[1]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_2, &collection, "valid", &_zephir_call_cache[2]);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&element, &collection, "current", &_zephir_call_cache[3]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &method_zv, NULL, 0, &element);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&element);
	RETURN_THIS();
}

/**
 * Checks the registered classes to find the class. Includes the file if
 * found and returns true; false otherwise
 *
 * @throws EventsException
 */
PHP_METHOD(Phalcon_Autoload_Loader, autoloadCheckClasses)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, filePath, _0, _2$$3, _3$$3, _4$$3, _5$$4;
	zend_string *className = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("classes", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 497, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_value(&_0, &className_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (1 == _1) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 497, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&filePath);
		zephir_array_fetch(&filePath, &_2$$3, &className_zv, PH_NOISY, "phalcon/Autoload/Loader.zep", 543);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "loader:beforeCheckPath");
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireManagerEvent", &_zephir_call_cache[0], &_3$$3, &filePath);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_4$$3, this_ptr, "requireFile", &_zephir_call_cache[1], &filePath);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_4$$3)) {
			ZEPHIR_INIT_VAR(&_5$$4);
			ZEPHIR_CONCAT_SV(&_5$$4, "Class: load: ", &filePath);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addDebug", &_zephir_call_cache[2], &_5$$4);
			zephir_check_call_status();
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);
}

/**
 * Checks the registered directories to find the class. Includes the file if
 * found and returns true; false otherwise
 *
 * @param autoload_strings $directories
 *
 * @throws EventsException
 */
PHP_METHOD(Phalcon_Autoload_Loader, autoloadCheckDirectories)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool isDirectory, _15, _10$$3, _24$$10;
	zend_string *className = NULL;
	zval *directories_param = NULL, className_zv, *isDirectory_param = NULL, dirSeparator, directory, extension, extensions, filePath, fixedDirectory, localClassName, nsSeparator, _0, *_1, _14, _2$$3, *_3$$3, _4$$3, *_5$$3, _9$$3, _6$$4, _7$$4, _8$$6, _11$$7, _12$$7, _13$$9, _16$$10, *_17$$10, _18$$10, *_19$$10, _23$$10, _20$$11, _21$$11, _22$$13, _25$$14, _26$$14, _27$$16;
	zval directories;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directories);
	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&dirSeparator);
	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&fixedDirectory);
	ZVAL_UNDEF(&localClassName);
	ZVAL_UNDEF(&nsSeparator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_27$$16);
	ZEND_TLS zephir_method_cache _zephir_call_cache[24];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("extensions", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("checkedPath", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 3)
		ZEPHIR_Z_PARAM_ARRAY(directories, directories_param)
		Z_PARAM_STR(className)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(isDirectory)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	directories_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		isDirectory_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_get_arrval(&directories, directories_param);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	if (!isDirectory_param) {
		isDirectory = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&dirSeparator);
	ZVAL_STRING(&dirSeparator, "/");
	ZEPHIR_INIT_VAR(&nsSeparator);
	ZVAL_STRING(&nsSeparator, "\\");
	ZEPHIR_INIT_VAR(&localClassName);
	zephir_fast_str_replace(&localClassName, &nsSeparator, &dirSeparator, &className_zv);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 498, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&extensions, &_0);
	zephir_is_iterable(&directories, 0, "phalcon/Autoload/Loader.zep", 602);
	if (Z_TYPE_P(&directories) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&directories), _1)
		{
			ZEPHIR_INIT_NVAR(&directory);
			ZVAL_COPY(&directory, _1);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_fast_trim(&_2$$3, &directory, &dirSeparator, ZEPHIR_TRIM_RIGHT);
			ZEPHIR_INIT_NVAR(&fixedDirectory);
			ZEPHIR_CONCAT_VV(&fixedDirectory, &_2$$3, &dirSeparator);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&extensions) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_4$$3);
				zephir_string_to_char_array(&_4$$3, &extensions);
				_3$$3 = &_4$$3;
			} else {
				_3$$3 = &extensions;
			}
			zephir_is_iterable(_3$$3, 0, "phalcon/Autoload/Loader.zep", 600);
			if (Z_TYPE_P(_3$$3) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3$$3), _5$$3)
				{
					ZEPHIR_INIT_NVAR(&extension);
					ZVAL_COPY(&extension, _5$$3);
					ZEPHIR_INIT_NVAR(&filePath);
					ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &localClassName, ".", &extension);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 501, &filePath);
					ZEPHIR_INIT_NVAR(&_6$$4);
					ZVAL_STRING(&_6$$4, "loader:beforeCheckPath");
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireManagerEvent", &_zephir_call_cache[0], &_6$$4, &filePath);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_7$$4, this_ptr, "requireFile", &_zephir_call_cache[1], &filePath);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_7$$4)) {
						if (isDirectory) {
							ZEPHIR_INIT_NVAR(&_8$$6);
							ZEPHIR_CONCAT_SV(&_8$$6, "Directories: ", &filePath);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addDebug", &_zephir_call_cache[2], &_8$$6);
							zephir_check_call_status();
						}
						RETURN_MM_BOOL(1);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _3$$3, "rewind", &_zephir_call_cache[3]);
				zephir_check_call_status();
				_10$$3 = 1;
				while (1) {
					if (_10$$3) {
						_10$$3 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _3$$3, "next", &_zephir_call_cache[4]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_9$$3, _3$$3, "valid", &_zephir_call_cache[5]);
					zephir_check_call_status();
					if (!zend_is_true(&_9$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&extension, _3$$3, "current", &_zephir_call_cache[6]);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&filePath);
						ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &localClassName, ".", &extension);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 501, &filePath);
						ZEPHIR_INIT_NVAR(&_11$$7);
						ZVAL_STRING(&_11$$7, "loader:beforeCheckPath");
						ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireManagerEvent", &_zephir_call_cache[7], &_11$$7, &filePath);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&_12$$7, this_ptr, "requireFile", &_zephir_call_cache[8], &filePath);
						zephir_check_call_status();
						if (ZEPHIR_IS_TRUE_IDENTICAL(&_12$$7)) {
							if (isDirectory) {
								ZEPHIR_INIT_NVAR(&_13$$9);
								ZEPHIR_CONCAT_SV(&_13$$9, "Directories: ", &filePath);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addDebug", &_zephir_call_cache[9], &_13$$9);
								zephir_check_call_status();
							}
							RETURN_MM_BOOL(1);
						}
				}
			}
			ZEPHIR_INIT_NVAR(&extension);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &directories, "rewind", &_zephir_call_cache[10]);
		zephir_check_call_status();
		_15 = 1;
		while (1) {
			if (_15) {
				_15 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &directories, "next", &_zephir_call_cache[11]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_14, &directories, "valid", &_zephir_call_cache[12]);
			zephir_check_call_status();
			if (!zend_is_true(&_14)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&directory, &directories, "current", &_zephir_call_cache[13]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_16$$10);
				zephir_fast_trim(&_16$$10, &directory, &dirSeparator, ZEPHIR_TRIM_RIGHT);
				ZEPHIR_INIT_NVAR(&fixedDirectory);
				ZEPHIR_CONCAT_VV(&fixedDirectory, &_16$$10, &dirSeparator);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&extensions) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_18$$10);
					zephir_string_to_char_array(&_18$$10, &extensions);
					_17$$10 = &_18$$10;
				} else {
					_17$$10 = &extensions;
				}
				zephir_is_iterable(_17$$10, 0, "phalcon/Autoload/Loader.zep", 600);
				if (Z_TYPE_P(_17$$10) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_17$$10), _19$$10)
					{
						ZEPHIR_INIT_NVAR(&extension);
						ZVAL_COPY(&extension, _19$$10);
						ZEPHIR_INIT_NVAR(&filePath);
						ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &localClassName, ".", &extension);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 501, &filePath);
						ZEPHIR_INIT_NVAR(&_20$$11);
						ZVAL_STRING(&_20$$11, "loader:beforeCheckPath");
						ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireManagerEvent", &_zephir_call_cache[14], &_20$$11, &filePath);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&_21$$11, this_ptr, "requireFile", &_zephir_call_cache[15], &filePath);
						zephir_check_call_status();
						if (ZEPHIR_IS_TRUE_IDENTICAL(&_21$$11)) {
							if (isDirectory) {
								ZEPHIR_INIT_NVAR(&_22$$13);
								ZEPHIR_CONCAT_SV(&_22$$13, "Directories: ", &filePath);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addDebug", &_zephir_call_cache[16], &_22$$13);
								zephir_check_call_status();
							}
							RETURN_MM_BOOL(1);
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _17$$10, "rewind", &_zephir_call_cache[17]);
					zephir_check_call_status();
					_24$$10 = 1;
					while (1) {
						if (_24$$10) {
							_24$$10 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _17$$10, "next", &_zephir_call_cache[18]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_23$$10, _17$$10, "valid", &_zephir_call_cache[19]);
						zephir_check_call_status();
						if (!zend_is_true(&_23$$10)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&extension, _17$$10, "current", &_zephir_call_cache[20]);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&filePath);
							ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &localClassName, ".", &extension);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 501, &filePath);
							ZEPHIR_INIT_NVAR(&_25$$14);
							ZVAL_STRING(&_25$$14, "loader:beforeCheckPath");
							ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireManagerEvent", &_zephir_call_cache[21], &_25$$14, &filePath);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&_26$$14, this_ptr, "requireFile", &_zephir_call_cache[22], &filePath);
							zephir_check_call_status();
							if (ZEPHIR_IS_TRUE_IDENTICAL(&_26$$14)) {
								if (isDirectory) {
									ZEPHIR_INIT_NVAR(&_27$$16);
									ZEPHIR_CONCAT_SV(&_27$$16, "Directories: ", &filePath);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addDebug", &_zephir_call_cache[23], &_27$$16);
									zephir_check_call_status();
								}
								RETURN_MM_BOOL(1);
							}
					}
				}
				ZEPHIR_INIT_NVAR(&extension);
		}
	}
	ZEPHIR_INIT_NVAR(&directory);
	RETURN_MM_BOOL(0);
}

/**
 * Checks the registered namespaces to find the class. Includes the file if
 * found and returns true; false otherwise
 *
 * @throws EventsException
 */
PHP_METHOD(Phalcon_Autoload_Loader, autoloadCheckNamespaces)
{
	zend_bool _11;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, directories, fileName, namespaces, prefix, _0, *_1, _2, *_3, _10, _6$$3, _7$$3, _8$$5, _9$$5, _12$$6, _13$$6, _14$$8, _15$$8;
	zend_string *className = NULL, *_5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&directories);
	ZVAL_UNDEF(&fileName);
	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZEND_TLS zephir_method_cache _zephir_call_cache[9];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("namespaces", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("checkedPath", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 491, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&namespaces, &_0);
	if (Z_TYPE_P(&namespaces) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &namespaces);
		_1 = &_2;
	} else {
		_1 = &namespaces;
	}
	zephir_is_iterable(_1, 0, "phalcon/Autoload/Loader.zep", 630);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_1), _4, _5, _3)
		{
			ZEPHIR_INIT_NVAR(&prefix);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&prefix, _5);
			} else {
				ZVAL_LONG(&prefix, _4);
			}
			ZEPHIR_INIT_NVAR(&directories);
			ZVAL_COPY(&directories, _3);
			if (1 != zephir_start_with(&className_zv, &prefix, NULL)) {
				continue;
			}
			ZVAL_LONG(&_6$$3, zephir_fast_strlen_ev(&prefix));
			ZEPHIR_INIT_NVAR(&fileName);
			zephir_substr(&fileName, &className_zv, zephir_get_intval(&_6$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_CALL_METHOD_CACHED(&_7$$3, this_ptr, "autoloadCheckDirectories", &_zephir_call_cache[0], &directories, &fileName);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_7$$3)) {
				zephir_read_property_cached(&_8$$5, this_ptr, _zephir_prop_1, 501, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZEPHIR_CONCAT_SVSV(&_9$$5, "Namespace: ", &prefix, " - ", &_8$$5);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addDebug", &_zephir_call_cache[1], &_9$$5);
				zephir_check_call_status();
				RETURN_MM_BOOL(1);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[2]);
		zephir_check_call_status();
		_11 = 1;
		while (1) {
			if (_11) {
				_11 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[3]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_10, _1, "valid", &_zephir_call_cache[4]);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&prefix, _1, "key", &_zephir_call_cache[5]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&directories, _1, "current", &_zephir_call_cache[6]);
			zephir_check_call_status();
				if (1 != zephir_start_with(&className_zv, &prefix, NULL)) {
					continue;
				}
				ZVAL_LONG(&_12$$6, zephir_fast_strlen_ev(&prefix));
				ZEPHIR_INIT_NVAR(&fileName);
				zephir_substr(&fileName, &className_zv, zephir_get_intval(&_12$$6), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_CALL_METHOD_CACHED(&_13$$6, this_ptr, "autoloadCheckDirectories", &_zephir_call_cache[7], &directories, &fileName);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_13$$6)) {
					zephir_read_property_cached(&_14$$8, this_ptr, _zephir_prop_1, 501, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_15$$8);
					ZEPHIR_CONCAT_SVSV(&_15$$8, "Namespace: ", &prefix, " - ", &_14$$8);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addDebug", &_zephir_call_cache[8], &_15$$8);
					zephir_check_call_status();
					RETURN_MM_BOOL(1);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&directories);
	ZEPHIR_INIT_NVAR(&prefix);
	RETURN_MM_BOOL(0);
}

/**
 * Checks if the directories is an array or a string and throws an exception
 * if not. It converts the string to an array and then traverses the array
 * to normalize the directories with the proper directory separator at the
 * end
 *
 * @param mixed $directories
 *
 * @return autoload_strings
 */
PHP_METHOD(Phalcon_Autoload_Loader, checkDirectories)
{
	zend_bool _0, _9;
	zval results;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *dirSeparator = NULL, *name = NULL;
	zval *directories = NULL, directories_sub, dirSeparator_zv, name_zv, directory, *_3, _4, *_5, _8, _1$$3, _2$$4, _6$$5, _7$$5, _10$$6, _11$$6;

	ZVAL_UNDEF(&directories_sub);
	ZVAL_UNDEF(&dirSeparator_zv);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&results);
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(directories)
		Z_PARAM_STR(dirSeparator)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	directories = ZEND_CALL_ARG(execute_data, 1);
	ZEPHIR_SEPARATE_PARAM(directories);
	zephir_memory_observe(&dirSeparator_zv);
	ZVAL_STR_COPY(&dirSeparator_zv, dirSeparator);
	if (!name) {
		name = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&name_zv);
		ZVAL_STR(&name_zv, name);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	_0 = !((Z_TYPE_P(directories) == IS_STRING));
	if (_0) {
		_0 = !((Z_TYPE_P(directories) == IS_ARRAY));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_autoload_exceptions_loaderdirectoriesnotarray_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0], &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Autoload/Loader.zep", 652);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if ((Z_TYPE_P(directories) == IS_STRING)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_create_array(&_2$$4, 1, 0);
		zephir_array_fast_append(&_2$$4, directories);
		ZEPHIR_CPY_WRT(directories, &_2$$4);
	}
	ZEPHIR_INIT_VAR(&results);
	array_init(&results);
	if (Z_TYPE_P(directories) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, directories);
		_3 = &_4;
	} else {
		_3 = directories;
	}
	zephir_is_iterable(_3, 0, "phalcon/Autoload/Loader.zep", 666);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3), _5)
		{
			ZEPHIR_INIT_NVAR(&directory);
			ZVAL_COPY(&directory, _5);
			ZEPHIR_INIT_NVAR(&_6$$5);
			zephir_fast_trim(&_6$$5, &directory, &dirSeparator_zv, ZEPHIR_TRIM_RIGHT);
			ZEPHIR_INIT_NVAR(&_7$$5);
			ZEPHIR_CONCAT_VV(&_7$$5, &_6$$5, &dirSeparator_zv);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CPY_WRT(&directory, &_7$$5);
			zephir_array_update_zval(&results, &directory, &directory, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _3, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_9 = 1;
		while (1) {
			if (_9) {
				_9 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _3, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_8, _3, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&directory, _3, "current", &_zephir_call_cache[4]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_10$$6);
				zephir_fast_trim(&_10$$6, &directory, &dirSeparator_zv, ZEPHIR_TRIM_RIGHT);
				ZEPHIR_INIT_NVAR(&_11$$6);
				ZEPHIR_CONCAT_VV(&_11$$6, &_10$$6, &dirSeparator_zv);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CPY_WRT(&directory, &_11$$6);
				zephir_array_update_zval(&results, &directory, &directory, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&directory);
	RETURN_CTOR(&results);
}

PHP_METHOD(Phalcon_Autoload_Loader, registerAutoload)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prepend_param = NULL, __$true, _1, _2;
	zend_bool prepend;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(prepend)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &prepend_param);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "autoload");
	zephir_array_fast_append(&_0, &_1);
	ZVAL_BOOL(&_2, (prepend ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("spl_autoload_register", NULL, 110, &_0, &__$true, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Autoload_Loader, getEventsManager)
{

	RETURN_MEMBER(getThis(), "eventsManager");
}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Autoload_Loader, setEventsManager)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventsManager, eventsManager_sub, _0, _1, _3, _4$$3, _5$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("eventsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &eventsManager);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "container");
	ZEPHIR_CALL_FUNCTION(&_1, "property_exists", NULL, 7, this_ptr, &_0);
	zephir_check_call_status();
	_2 = ZEPHIR_IS_TRUE_IDENTICAL(&_1);
	if (_2) {
		zephir_memory_observe(&_3);
		zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 502, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_2 = Z_TYPE_P(&_3) != IS_NULL;
	}
	if (_2) {
		zephir_memory_observe(&_4$$3);
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_0, 502, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "eventsManager");
		ZVAL_BOOL(&_6$$3, 1);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$3, "set", &_zephir_call_cache[0], &_5$$3, eventsManager, &_6$$3);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 503, eventsManager);
	ZEPHIR_MM_RESTORE();
}

/**
 * Helper method to fire an event
 * 
 * @throws EventsException
 */
PHP_METHOD(Phalcon_Autoload_Loader, fireManagerEvent)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool cancellable, stopOnFalse, _1$$3;
	zval eventName_zv, *data = NULL, data_sub, *cancellable_param = NULL, *stopOnFalse_param = NULL, __$null, _0, _2$$3, _6$$3, _7$$3, _3$$4, _4$$4, _5$$4;
	zend_string *eventName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("eventsManager", 13, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(eventName)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_BOOL(cancellable)
		Z_PARAM_BOOL(stopOnFalse)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		data = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		cancellable_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		stopOnFalse_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&eventName_zv);
	ZVAL_STR_COPY(&eventName_zv, eventName);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!cancellable_param) {
		cancellable = 1;
	} else {
		}
	if (!stopOnFalse_param) {
		stopOnFalse = 0;
	} else {
		}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 503, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_0) != IS_NULL) {
		_1$$3 = stopOnFalse;
		if (_1$$3) {
			zephir_memory_observe(&_2$$3);
			zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 503, PH_NOISY_CC);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_1$$3 = zephir_instance_of_ev(&_2$$3, phalcon_events_manager_ce);
		}
		if (_1$$3) {
			zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_0, 503, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (cancellable) {
				ZVAL_BOOL(&_4$$4, 1);
			} else {
				ZVAL_BOOL(&_4$$4, 0);
			}
			ZVAL_BOOL(&_5$$4, 1);
			ZEPHIR_RETURN_CALL_METHOD_CACHED(&_3$$4, "fire", &_zephir_call_cache[0], &eventName_zv, this_ptr, data, &_4$$4, &_5$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
		zephir_read_property_cached(&_6$$3, this_ptr, _zephir_prop_0, 503, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (cancellable) {
			ZVAL_BOOL(&_7$$3, 1);
		} else {
			ZVAL_BOOL(&_7$$3, 0);
		}
		ZEPHIR_RETURN_CALL_METHOD_CACHED(&_6$$3, "fire", &_zephir_call_cache[1], &eventName_zv, this_ptr, data, &_7$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);
}

