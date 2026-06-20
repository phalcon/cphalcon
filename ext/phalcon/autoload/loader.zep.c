
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
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * The Phalcon Autoloader provides an easy way to automatically load classes
 * (namespaced or not) as well as files. It also features extension loading,
 * allowing the user to autoload files with different extensions than .php.
 */
ZEPHIR_INIT_CLASS(Phalcon_Autoload_Loader)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Autoload, Loader, phalcon, autoload_loader, phalcon_events_abstracteventsaware_ce, phalcon_autoload_loader_method_entry, 0);

	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_autoload_loader_ce, SL("checkedPath"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_autoload_loader_ce, SL("classes"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_autoload_loader_ce, SL("debug"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_autoload_loader_ce, SL("directories"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_autoload_loader_ce, SL("extensions"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|callable
	 */
	zend_declare_property_string(phalcon_autoload_loader_ce, SL("fileCheckingCallback"), "is_file", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_autoload_loader_ce, SL("files"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_autoload_loader_ce, SL("foundPath"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_autoload_loader_ce, SL("isDebug"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_autoload_loader_ce, SL("isRegistered"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_autoload_loader_ce, SL("namespaces"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_autoload_loader_ce, SL("nestingLevel"), 0, ZEND_ACC_PROTECTED);
	phalcon_autoload_loader_ce->create_object = zephir_init_properties_Phalcon_Autoload_Loader;

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
	if (isDebug) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isDebug"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isDebug"), &__$false);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Adds a class to the internal collection for the mapping
 *
 * @param string $name
 * @param string $file
 *
 * @return static
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
	RETURN_THISW();
}

/**
 * Adds a directory for the loaded files
 *
 * @param string $directory
 *
 * @return static
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
	RETURN_THISW();
}

/**
 * Adds an extension for the loaded files
 *
 * @param string $extension
 *
 * @return static
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
	RETURN_THISW();
}

/**
 * Adds a file to be added to the loader
 *
 * @param string $file
 *
 * @return static
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
	RETURN_THISW();
}

/**
 * @param string $name
 * @param mixed  $directories
 * @param bool   $prepend
 *
 * @return static
 * @throws Exception
 */
PHP_METHOD(Phalcon_Autoload_Loader, addNamespace)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool prepend;
	zval name_zv, *directories = NULL, directories_sub, *prepend_param = NULL, dirSeparator, nsName, nsSeparator, source, target, _0, _1, _2, _3, _5, _6, _7, _4$$3;
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_4$$3);
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
	ZEPHIR_CPY_WRT(&nsName, &_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "checkdirectories", NULL, 336, directories, &dirSeparator, &name_zv);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(directories, &_2);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("namespaces"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_value(&_3, &nsName))) {
		ZEPHIR_INIT_VAR(&_4$$3);
		array_init(&_4$$3);
		zephir_update_property_array(this_ptr, SL("namespaces"), &nsName, &_4$$3);
	}
	if (prepend) {
		ZEPHIR_CPY_WRT(&source, directories);
	} else {
		zephir_read_property(&_5, this_ptr, ZEND_STRL("namespaces"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&source);
		zephir_array_fetch(&source, &_5, &nsName, PH_NOISY, "phalcon/Autoload/Loader.zep", 176);
	}
	if (prepend) {
		zephir_read_property(&_6, this_ptr, ZEND_STRL("namespaces"), PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&target);
		zephir_array_fetch(&target, &_6, &nsName, PH_NOISY, "phalcon/Autoload/Loader.zep", 177);
	} else {
		ZEPHIR_CPY_WRT(&target, directories);
	}
	ZEPHIR_INIT_VAR(&_7);
	zephir_fast_array_merge(&_7, &source, &target);
	ZEPHIR_CALL_FUNCTION(&_2, "array_unique", NULL, 337, &_7);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("namespaces"), &nsName, &_2);
	RETURN_THIS();
}

/**
 * Autoloads the registered classes
 *
 * @param string $className
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Autoload_Loader, autoload)
{
	zval _4, _7$$4, _9$$5, _13$$6;
	zend_bool result = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, _0, _2, _3, _5, _6, _15, _1$$3, _8$$4, _10$$5, _11$$5, _12$$5, _14$$6;
	zend_string *className = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_13$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("nestingLevel"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG_IDENTICAL(&_0, 0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("debug"), &_1$$3);
	}
	result = 1;
	zephir_read_property(&_2, this_ptr, ZEND_STRL("nestingLevel"), PH_NOISY_CC | PH_READONLY);
	ZVAL_UNDEF(&_3);
	ZVAL_LONG(&_3, (zephir_get_numberval(&_2) + 1));
	zephir_update_property_zval(this_ptr, ZEND_STRL("nestingLevel"), &_3);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SV(&_4, "Loading: ", &className_zv);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", NULL, 338, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "loader:beforeCheckClass");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_5, &className_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "autoloadcheckclasses", NULL, 339, &className_zv);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_6)) {
		ZEPHIR_INIT_VAR(&_7$$4);
		ZEPHIR_CONCAT_SV(&_7$$4, "Class: 404: ", &className_zv);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", NULL, 338, &_7$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "autoloadchecknamespaces", NULL, 340, &className_zv);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_8$$4)) {
			ZEPHIR_INIT_VAR(&_9$$5);
			ZEPHIR_CONCAT_SV(&_9$$5, "Namespace: 404: ", &className_zv);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", NULL, 338, &_9$$5);
			zephir_check_call_status();
			zephir_read_property(&_11$$5, this_ptr, ZEND_STRL("directories"), PH_NOISY_CC | PH_READONLY);
			ZVAL_BOOL(&_12$$5, 1);
			ZEPHIR_CALL_METHOD(&_10$$5, this_ptr, "autoloadcheckdirectories", NULL, 341, &_11$$5, &className_zv, &_12$$5);
			zephir_check_call_status();
			if (!ZEPHIR_IS_TRUE_IDENTICAL(&_10$$5)) {
				ZEPHIR_INIT_VAR(&_13$$6);
				ZEPHIR_CONCAT_SV(&_13$$6, "Directories: 404: ", &className_zv);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", NULL, 338, &_13$$6);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_14$$6);
				ZVAL_STRING(&_14$$6, "loader:afterCheckClass");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_14$$6, &className_zv);
				zephir_check_call_status();
				result = 0;
			}
		}
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("nestingLevel"), PH_NOISY_CC | PH_READONLY);
	ZVAL_UNDEF(&_15);
	ZVAL_LONG(&_15, (zephir_get_numberval(&_3) - 1));
	zephir_update_property_zval(this_ptr, ZEND_STRL("nestingLevel"), &_15);
	RETURN_MM_BOOL(result);
}

/**
 * Get the path the loader is checking for a path
 *
 * @return string|null
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
 *
 * @return string|null
 */
PHP_METHOD(Phalcon_Autoload_Loader, getFoundPath)
{

	RETURN_MEMBER(getThis(), "foundPath");
}

/**
 * Returns the namespaces currently registered in the autoloader
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Autoload_Loader, getNamespaces)
{

	RETURN_MEMBER_TYPED(getThis(), "namespaces", IS_ARRAY);
}

/**
 * Checks if a file exists and then adds the file by doing virtual require
 */
PHP_METHOD(Phalcon_Autoload_Loader, loadFiles)
{
	zend_bool _6;
	zval file, files, _0, *_1, _5, _2$$3, _7$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_7$$4);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("files"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&files, &_0);
	zephir_is_iterable(&files, 0, "phalcon/Autoload/Loader.zep", 336);
	if (Z_TYPE_P(&files) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&files), _1)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _1);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "loader:beforeCheckPath");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", &_3, 0, &_2$$3, &file);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "requirefile", &_4, 0, &file);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &files, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &files, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &files, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&file, &files, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_7$$4);
				ZVAL_STRING(&_7$$4, "loader:beforeCheckPath");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", &_3, 0, &_7$$4, &file);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "requirefile", &_4, 0, &file);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&file);
	ZEPHIR_MM_RESTORE();
}

/**
 * Register the autoload method
 */
PHP_METHOD(Phalcon_Autoload_Loader, register)
{
	zval _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prepend_param = NULL, __$true, __$false, _0, _2$$3, _3$$3;
	zend_bool prepend;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_1$$3);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("isRegistered"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadfiles", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0);
		zephir_array_fast_append(&_1$$3, this_ptr);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "autoload");
		zephir_array_fast_append(&_1$$3, &_2$$3);
		ZVAL_BOOL(&_3$$3, (prepend ? 1 : 0));
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 342, &_1$$3, &__$true, &_3$$3);
		zephir_check_call_status();
		if (1) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("isRegistered"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("isRegistered"), &__$false);
		}
	}
	RETURN_THIS();
}

/**
 * Register classes and their locations
 *
 * @param array $classes
 * @param bool  $merge
 *
 * @return static
 */
PHP_METHOD(Phalcon_Autoload_Loader, setClasses)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge, _6;
	zval *classes_param = NULL, *merge_param = NULL, className, name, *_1, _5, _0$$3;
	zval classes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classes);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
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
		zephir_update_property_zval(this_ptr, ZEND_STRL("classes"), &_0$$3);
	}
	zephir_is_iterable(&classes, 0, "phalcon/Autoload/Loader.zep", 378);
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
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addclass", &_4, 0, &name, &className);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &classes, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &classes, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &classes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &classes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&className, &classes, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addclass", &_4, 0, &name, &className);
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
 * @param array $directories
 * @param bool  $merge
 *
 * @return static
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addtocollection", NULL, 343, &directories, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets an array of file extensions that the loader must try in each attempt
 * to locate the file
 *
 * @param array $extensions
 * @param bool  $merge
 *
 * @return static
 */
PHP_METHOD(Phalcon_Autoload_Loader, setExtensions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge, _6;
	zval *extensions_param = NULL, *merge_param = NULL, extension, *_3, _5, _0$$3, _1$$3, _2$$3;
	zval extensions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
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
		zephir_update_property_zval(this_ptr, ZEND_STRL("extensions"), &_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "php");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "php");
		zephir_update_property_array(this_ptr, SL("extensions"), &_1$$3, &_2$$3);
	}
	zephir_is_iterable(&extensions, 0, "phalcon/Autoload/Loader.zep", 421);
	if (Z_TYPE_P(&extensions) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extensions), _3)
		{
			ZEPHIR_INIT_NVAR(&extension);
			ZVAL_COPY(&extension, _3);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addextension", &_4, 0, &extension);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &extensions, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &extensions, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &extensions, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&extension, &extensions, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addextension", &_4, 0, &extension);
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
 * @param string|callable|null $method
 *
 * @return static
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
		zephir_update_property_zval(this_ptr, ZEND_STRL("fileCheckingCallback"), method);
	} else if (Z_TYPE_P(method) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$4);
		ZEPHIR_INIT_NVAR(&_0$$4);
		zephir_create_closure_ex(&_0$$4, NULL, phalcon_6__closure_ce, SL("__invoke"));
		zephir_update_property_zval(this_ptr, ZEND_STRL("fileCheckingCallback"), &_0$$4);
	} else {
		ZEPHIR_INIT_VAR(&_1$$5);
		object_init_ex(&_1$$5, phalcon_autoload_exceptions_loadermethodnotcallable_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 344);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$5, "phalcon/Autoload/Loader.zep", 453);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Registers files that are "non-classes" hence need a "require". This is
 * very useful for including files that only have functions
 *
 * @param array $files
 * @param bool  $merge
 *
 * @return static
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addtocollection", NULL, 343, &files, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Register namespaces and their related directories
 *
 * @param array $namespaces
 * @param bool  $merge
 *
 * @return static
 */
PHP_METHOD(Phalcon_Autoload_Loader, setNamespaces)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge, _6;
	zval *namespaces_param = NULL, *merge_param = NULL, directories, name, *_1, _5, _0$$3;
	zval namespaces;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&directories);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
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
		zephir_update_property_zval(this_ptr, ZEND_STRL("namespaces"), &_0$$3);
	}
	zephir_is_iterable(&namespaces, 0, "phalcon/Autoload/Loader.zep", 498);
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
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addnamespace", &_4, 0, &name, &directories);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &namespaces, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &namespaces, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &namespaces, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &namespaces, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&directories, &namespaces, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addnamespace", &_4, 0, &name, &directories);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&directories);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_THIS();
}

/**
 * returns isRegistered
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Autoload_Loader, isRegistered)
{

	RETURN_MEMBER(getThis(), "isRegistered");
}

/**
 * Unregister the autoload method
 *
 * @return static
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("isRegistered"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0);
		zephir_array_fast_append(&_1$$3, this_ptr);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "autoload");
		zephir_array_fast_append(&_1$$3, &_2$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_unregister", NULL, 345, &_1$$3);
		zephir_check_call_status();
		if (0) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("isRegistered"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("isRegistered"), &__$false);
		}
	}
	RETURN_THIS();
}

/**
 * If the file exists, require it and return true; false otherwise
 *
 * @param string $file The file to require
 *
 * @return bool
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(file)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&file_zv);
	ZVAL_STR_COPY(&file_zv, file);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("fileCheckingCallback"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "call_user_func", NULL, 346, &_0, &file_zv);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("foundPath"), &file_zv);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "loader:pathFound");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_2$$3, &file_zv);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, "Require: ", &file_zv);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", NULL, 338, &_3$$3);
		zephir_check_call_status();
		if (zephir_require_once_zval(&file_zv) == FAILURE) {
			RETURN_MM_NULL();
		}
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SV(&_4, "Require: 404: ", &file_zv);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", NULL, 338, &_4);
	zephir_check_call_status();
	RETURN_MM_BOOL(0);
}

/**
 * Adds a debugging message in the collection
 *
 * @param string $message
 */
PHP_METHOD(Phalcon_Autoload_Loader, addDebug)
{
	zval message_zv, _0;
	zend_string *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&message_zv, message);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("isDebug"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		zephir_update_property_array_append(this_ptr, SL("debug"), &message_zv);
	}
}

/**
 * Traverses a collection and adds elements to it using the relevant
 * class method
 *
 * @param array  $collection
 * @param string $collectionName
 * @param string $method
 * @param bool   $merge
 *
 * @return static
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
	zephir_is_iterable(&collection, 0, "phalcon/Autoload/Loader.zep", 605);
	if (Z_TYPE_P(&collection) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&collection), _1)
		{
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _1);
			ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &method_zv, NULL, 0, &element);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &collection, "rewind", NULL, 0);
		zephir_check_call_status();
		_3 = 1;
		while (1) {
			if (_3) {
				_3 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &collection, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_2, &collection, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&element, &collection, "current", NULL, 0);
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
 * @param string $className
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Autoload_Loader, autoloadCheckClasses)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, filePath, _0, _1$$3, _2$$3, _3$$3, _4$$4;
	zend_string *className = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("classes"), PH_NOISY_CC | PH_READONLY);
	if (1 == zephir_array_isset_value(&_0, &className_zv)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("classes"), PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&filePath);
		zephir_array_fetch(&filePath, &_1$$3, &className_zv, PH_NOISY, "phalcon/Autoload/Loader.zep", 621);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "loader:beforeCheckPath");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_2$$3, &filePath);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "requirefile", NULL, 0, &filePath);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_3$$3)) {
			ZEPHIR_INIT_VAR(&_4$$4);
			ZEPHIR_CONCAT_SV(&_4$$4, "Class: load: ", &filePath);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", NULL, 338, &_4$$4);
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
 * @param array  $directories
 * @param string $className
 * @param bool   $isDirectory
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Autoload_Loader, autoloadCheckDirectories)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool isDirectory, _16, _11$$3, _23$$10;
	zend_string *className = NULL;
	zval *directories_param = NULL, className_zv, *isDirectory_param = NULL, dirSeparator, directory, extension, extensions, filePath, fixedDirectory, localClassName, nsSeparator, _0, *_1, _15, _2$$3, *_3$$3, _10$$3, _4$$4, _6$$4, _8$$6, _12$$7, _13$$7, _14$$9, _17$$10, *_18$$10, _22$$10, _19$$11, _20$$11, _21$$13, _24$$14, _25$$14, _26$$16;
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
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_24$$14);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_26$$16);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("extensions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&extensions, &_0);
	zephir_is_iterable(&directories, 0, "phalcon/Autoload/Loader.zep", 682);
	if (Z_TYPE_P(&directories) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&directories), _1)
		{
			ZEPHIR_INIT_NVAR(&directory);
			ZVAL_COPY(&directory, _1);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_fast_trim(&_2$$3, &directory, &dirSeparator, ZEPHIR_TRIM_RIGHT);
			ZEPHIR_INIT_NVAR(&fixedDirectory);
			ZEPHIR_CONCAT_VV(&fixedDirectory, &_2$$3, &dirSeparator);
			zephir_is_iterable(&extensions, 0, "phalcon/Autoload/Loader.zep", 680);
			if (Z_TYPE_P(&extensions) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extensions), _3$$3)
				{
					ZEPHIR_INIT_NVAR(&extension);
					ZVAL_COPY(&extension, _3$$3);
					ZEPHIR_INIT_NVAR(&filePath);
					ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &localClassName, ".", &extension);
					zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
					ZEPHIR_INIT_NVAR(&_4$$4);
					ZVAL_STRING(&_4$$4, "loader:beforeCheckPath");
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", &_5, 0, &_4$$4, &filePath);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "requirefile", &_7, 0, &filePath);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_6$$4)) {
						if (isDirectory) {
							ZEPHIR_INIT_NVAR(&_8$$6);
							ZEPHIR_CONCAT_SV(&_8$$6, "Directories: ", &filePath);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", &_9, 338, &_8$$6);
							zephir_check_call_status();
						}
						RETURN_MM_BOOL(1);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &extensions, "rewind", NULL, 0);
				zephir_check_call_status();
				_11$$3 = 1;
				while (1) {
					if (_11$$3) {
						_11$$3 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &extensions, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_10$$3, &extensions, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_10$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&extension, &extensions, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&filePath);
						ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &localClassName, ".", &extension);
						zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
						ZEPHIR_INIT_NVAR(&_12$$7);
						ZVAL_STRING(&_12$$7, "loader:beforeCheckPath");
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", &_5, 0, &_12$$7, &filePath);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_13$$7, this_ptr, "requirefile", &_7, 0, &filePath);
						zephir_check_call_status();
						if (ZEPHIR_IS_TRUE_IDENTICAL(&_13$$7)) {
							if (isDirectory) {
								ZEPHIR_INIT_NVAR(&_14$$9);
								ZEPHIR_CONCAT_SV(&_14$$9, "Directories: ", &filePath);
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", &_9, 338, &_14$$9);
								zephir_check_call_status();
							}
							RETURN_MM_BOOL(1);
						}
				}
			}
			ZEPHIR_INIT_NVAR(&extension);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &directories, "rewind", NULL, 0);
		zephir_check_call_status();
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &directories, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_15, &directories, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&directory, &directories, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_17$$10);
				zephir_fast_trim(&_17$$10, &directory, &dirSeparator, ZEPHIR_TRIM_RIGHT);
				ZEPHIR_INIT_NVAR(&fixedDirectory);
				ZEPHIR_CONCAT_VV(&fixedDirectory, &_17$$10, &dirSeparator);
				zephir_is_iterable(&extensions, 0, "phalcon/Autoload/Loader.zep", 680);
				if (Z_TYPE_P(&extensions) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extensions), _18$$10)
					{
						ZEPHIR_INIT_NVAR(&extension);
						ZVAL_COPY(&extension, _18$$10);
						ZEPHIR_INIT_NVAR(&filePath);
						ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &localClassName, ".", &extension);
						zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
						ZEPHIR_INIT_NVAR(&_19$$11);
						ZVAL_STRING(&_19$$11, "loader:beforeCheckPath");
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", &_5, 0, &_19$$11, &filePath);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_20$$11, this_ptr, "requirefile", &_7, 0, &filePath);
						zephir_check_call_status();
						if (ZEPHIR_IS_TRUE_IDENTICAL(&_20$$11)) {
							if (isDirectory) {
								ZEPHIR_INIT_NVAR(&_21$$13);
								ZEPHIR_CONCAT_SV(&_21$$13, "Directories: ", &filePath);
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", &_9, 338, &_21$$13);
								zephir_check_call_status();
							}
							RETURN_MM_BOOL(1);
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &extensions, "rewind", NULL, 0);
					zephir_check_call_status();
					_23$$10 = 1;
					while (1) {
						if (_23$$10) {
							_23$$10 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &extensions, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_22$$10, &extensions, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_22$$10)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&extension, &extensions, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&filePath);
							ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &localClassName, ".", &extension);
							zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
							ZEPHIR_INIT_NVAR(&_24$$14);
							ZVAL_STRING(&_24$$14, "loader:beforeCheckPath");
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", &_5, 0, &_24$$14, &filePath);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_25$$14, this_ptr, "requirefile", &_7, 0, &filePath);
							zephir_check_call_status();
							if (ZEPHIR_IS_TRUE_IDENTICAL(&_25$$14)) {
								if (isDirectory) {
									ZEPHIR_INIT_NVAR(&_26$$16);
									ZEPHIR_CONCAT_SV(&_26$$16, "Directories: ", &filePath);
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", &_9, 338, &_26$$16);
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
 * @param string $className
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Autoload_Loader, autoloadCheckNamespaces)
{
	zend_bool _11;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, directories, fileName, namespaces, prefix, _0, *_1, _10, _4$$3, _5$$3, _7$$5, _8$$5, _12$$6, _13$$6, _14$$8, _15$$8;
	zend_string *className = NULL, *_3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&directories);
	ZVAL_UNDEF(&fileName);
	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("namespaces"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&namespaces, &_0);
	zephir_is_iterable(&namespaces, 0, "phalcon/Autoload/Loader.zep", 712);
	if (Z_TYPE_P(&namespaces) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&namespaces), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&prefix);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&prefix, _3);
			} else {
				ZVAL_LONG(&prefix, _2);
			}
			ZEPHIR_INIT_NVAR(&directories);
			ZVAL_COPY(&directories, _1);
			if (1 != zephir_start_with(&className_zv, &prefix, NULL)) {
				continue;
			}
			ZVAL_LONG(&_4$$3, zephir_fast_strlen_ev(&prefix));
			ZEPHIR_INIT_NVAR(&fileName);
			zephir_substr(&fileName, &className_zv, zephir_get_intval(&_4$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "autoloadcheckdirectories", &_6, 341, &directories, &fileName);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_5$$3)) {
				zephir_read_property(&_7$$5, this_ptr, ZEND_STRL("checkedPath"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_8$$5);
				ZEPHIR_CONCAT_SVSV(&_8$$5, "Namespace: ", &prefix, " - ", &_7$$5);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", &_9, 338, &_8$$5);
				zephir_check_call_status();
				RETURN_MM_BOOL(1);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &namespaces, "rewind", NULL, 0);
		zephir_check_call_status();
		_11 = 1;
		while (1) {
			if (_11) {
				_11 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &namespaces, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_10, &namespaces, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&prefix, &namespaces, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&directories, &namespaces, "current", NULL, 0);
			zephir_check_call_status();
				if (1 != zephir_start_with(&className_zv, &prefix, NULL)) {
					continue;
				}
				ZVAL_LONG(&_12$$6, zephir_fast_strlen_ev(&prefix));
				ZEPHIR_INIT_NVAR(&fileName);
				zephir_substr(&fileName, &className_zv, zephir_get_intval(&_12$$6), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_CALL_METHOD(&_13$$6, this_ptr, "autoloadcheckdirectories", &_6, 341, &directories, &fileName);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_13$$6)) {
					zephir_read_property(&_14$$8, this_ptr, ZEND_STRL("checkedPath"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_15$$8);
					ZEPHIR_CONCAT_SVSV(&_15$$8, "Namespace: ", &prefix, " - ", &_14$$8);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", &_9, 338, &_15$$8);
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
 * @param mixed  $directories
 * @param string $dirSeparator
 * @param string $name
 *
 * @return array<string, string>
 * @throws Exception
 */
PHP_METHOD(Phalcon_Autoload_Loader, checkDirectories)
{
	zend_bool _0, _7;
	zval results;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *dirSeparator = NULL, *name = NULL;
	zval *directories = NULL, directories_sub, dirSeparator_zv, name_zv, directory, *_3, _6, _1$$3, _2$$4, _4$$5, _5$$5, _8$$6, _9$$6;

	ZVAL_UNDEF(&directories_sub);
	ZVAL_UNDEF(&dirSeparator_zv);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&results);
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
	_0 = !(Z_TYPE_P(directories) == IS_STRING);
	if (_0) {
		_0 = !(Z_TYPE_P(directories) == IS_ARRAY);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_autoload_exceptions_loaderdirectoriesnotarray_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 347, &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Autoload/Loader.zep", 737);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(directories) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_create_array(&_2$$4, 1, 0);
		zephir_array_fast_append(&_2$$4, directories);
		ZEPHIR_CPY_WRT(directories, &_2$$4);
	}
	ZEPHIR_INIT_VAR(&results);
	array_init(&results);
	zephir_is_iterable(directories, 0, "phalcon/Autoload/Loader.zep", 751);
	if (Z_TYPE_P(directories) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(directories), _3)
		{
			ZEPHIR_INIT_NVAR(&directory);
			ZVAL_COPY(&directory, _3);
			ZEPHIR_INIT_NVAR(&_4$$5);
			zephir_fast_trim(&_4$$5, &directory, &dirSeparator_zv, ZEPHIR_TRIM_RIGHT);
			ZEPHIR_INIT_NVAR(&_5$$5);
			ZEPHIR_CONCAT_VV(&_5$$5, &_4$$5, &dirSeparator_zv);
			ZEPHIR_CPY_WRT(&directory, &_5$$5);
			zephir_array_update_zval(&results, &directory, &directory, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, directories, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, directories, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, directories, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&directory, directories, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_8$$6);
				zephir_fast_trim(&_8$$6, &directory, &dirSeparator_zv, ZEPHIR_TRIM_RIGHT);
				ZEPHIR_INIT_NVAR(&_9$$6);
				ZEPHIR_CONCAT_VV(&_9$$6, &_8$$6, &dirSeparator_zv);
				ZEPHIR_CPY_WRT(&directory, &_9$$6);
				zephir_array_update_zval(&results, &directory, &directory, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&directory);
	RETURN_CTOR(&results);
}

zend_object *zephir_init_properties_Phalcon_Autoload_Loader(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _8, _10, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("namespaces"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("namespaces"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("files"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("files"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("extensions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("extensions"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("directories"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("directories"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("debug"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("debug"), &_9$$7);
		}
		zephir_read_property_ex(&_10, this_ptr, ZEND_STRL("classes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("classes"), &_11$$8);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

