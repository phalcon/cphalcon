
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
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
	phalcon_autoload_loader_ce->create_object = zephir_init_properties_Phalcon_Autoload_Loader;

	return SUCCESS;
}

/**
 * Loader constructor.
 */
PHP_METHOD(Phalcon_Autoload_Loader, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *isDebug_param = NULL, __$true, __$false, _0, _1, _2;
	zend_bool isDebug;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(isDebug)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &isDebug_param);
	if (!isDebug_param) {
		isDebug = 0;
	} else {
		isDebug = zephir_get_boolval(isDebug_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "sha256");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "php");
	ZEPHIR_CALL_FUNCTION(&_2, "hash", NULL, 68, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "php");
	zephir_update_property_array(this_ptr, SL("extensions"), &_2, &_0);
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
 * @return Loader
 */
PHP_METHOD(Phalcon_Autoload_Loader, addClass)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *file_param = NULL;
	zval name, file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&file);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_STR(file)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &file_param);
	zephir_get_strval(&name, name_param);
	zephir_get_strval(&file, file_param);


	zephir_update_property_array(this_ptr, SL("classes"), &name, &file);
	RETURN_THIS();
}

/**
 * Adds a directory for the loaded files
 *
 * @param string $directory
 *
 * @return Loader
 */
PHP_METHOD(Phalcon_Autoload_Loader, addDirectory)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *directory_param = NULL, _0, _1;
	zval directory;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(directory)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &directory_param);
	zephir_get_strval(&directory, directory_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "sha256");
	ZEPHIR_CALL_FUNCTION(&_1, "hash", NULL, 68, &_0, &directory);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("directories"), &_1, &directory);
	RETURN_THIS();
}

/**
 * Adds an extension for the loaded files
 *
 * @param string $extension
 *
 * @return Loader
 */
PHP_METHOD(Phalcon_Autoload_Loader, addExtension)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *extension_param = NULL, _0, _1;
	zval extension;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(extension)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &extension_param);
	zephir_get_strval(&extension, extension_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "sha256");
	ZEPHIR_CALL_FUNCTION(&_1, "hash", NULL, 68, &_0, &extension);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("extensions"), &_1, &extension);
	RETURN_THIS();
}

/**
 * Adds a file to be added to the loader
 *
 * @param string $file
 *
 * @return Loader
 */
PHP_METHOD(Phalcon_Autoload_Loader, addFile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, _0, _1;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(file)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);
	zephir_get_strval(&file, file_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "sha256");
	ZEPHIR_CALL_FUNCTION(&_1, "hash", NULL, 68, &_0, &file);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("files"), &_1, &file);
	RETURN_THIS();
}

/**
 * @param string $name
 * @param mixed  $directories
 * @param bool   $prepend
 *
 * @return Loader
 * @throws Exception
 */
PHP_METHOD(Phalcon_Autoload_Loader, addNamespace)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool prepend;
	zval *name_param = NULL, *directories = NULL, directories_sub, *prepend_param = NULL, dirSeparator, nsName, nsSeparator, source, target, _0, _1, _2, _3, _5, _6, _7, _4$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(directories)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(prepend)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &directories, &prepend_param);
	zephir_get_strval(&name, name_param);
	ZEPHIR_SEPARATE_PARAM(directories);
	if (!prepend_param) {
		prepend = 0;
	} else {
		prepend = zephir_get_boolval(prepend_param);
	}


	ZEPHIR_CPY_WRT(&nsName, &name);
	ZEPHIR_INIT_VAR(&nsSeparator);
	ZVAL_STRING(&nsSeparator, "\\");
	ZEPHIR_INIT_VAR(&dirSeparator);
	ZVAL_STRING(&dirSeparator, "/");
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_trim(&_0, &nsName, &nsSeparator, ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &_0, &nsSeparator);
	ZEPHIR_CPY_WRT(&nsName, &_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "checkdirectories", NULL, 172, directories, &dirSeparator);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(directories, &_2);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("namespaces"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_3, &nsName))) {
		ZEPHIR_INIT_VAR(&_4$$3);
		array_init(&_4$$3);
		zephir_update_property_array(this_ptr, SL("namespaces"), &nsName, &_4$$3);
	}
	if (prepend) {
		ZEPHIR_CPY_WRT(&source, directories);
	} else {
		zephir_read_property(&_5, this_ptr, ZEND_STRL("namespaces"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&source);
		zephir_array_fetch(&source, &_5, &nsName, PH_NOISY, "phalcon/Autoload/Loader.zep", 169);
	}
	if (prepend) {
		zephir_read_property(&_6, this_ptr, ZEND_STRL("namespaces"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&target);
		zephir_array_fetch(&target, &_6, &nsName, PH_NOISY, "phalcon/Autoload/Loader.zep", 170);
	} else {
		ZEPHIR_CPY_WRT(&target, directories);
	}
	ZEPHIR_INIT_VAR(&_7);
	zephir_fast_array_merge(&_7, &source, &target);
	ZEPHIR_CALL_FUNCTION(&_2, "array_unique", NULL, 173, &_7);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, _0, _2, _3, _5, _7, _8, _9;
	zval className, _1, _4, _6, _10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);
	zephir_get_strval(&className, className_param);


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("debug"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "Loading: ", &className);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", NULL, 174, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "loader:beforeCheckClass");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_2, &className);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "autoloadcheckclasses", NULL, 175, &className);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_3)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SV(&_4, "Class: 404: ", &className);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", NULL, 174, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "autoloadchecknamespaces", NULL, 176, &className);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_5)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SV(&_6, "Namespace: 404: ", &className);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", NULL, 174, &_6);
	zephir_check_call_status();
	zephir_read_property(&_8, this_ptr, ZEND_STRL("directories"), PH_NOISY_CC | PH_READONLY);
	ZVAL_BOOL(&_9, 1);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "autoloadcheckdirectories", NULL, 177, &_8, &className, &_9);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_7)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_CONCAT_SV(&_10, "Directories: 404: ", &className);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", NULL, 174, &_10);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "loader:afterCheckClass");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_2, &className);
	zephir_check_call_status();
	RETURN_MM_BOOL(0);
}

/**
 * Get the path the loader is checking for a path
 *
 * @return string|null
 */
PHP_METHOD(Phalcon_Autoload_Loader, getCheckedPath)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "checkedPath");
}

/**
 * Returns the class-map currently registered in the autoloader
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Autoload_Loader, getClasses)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "classes");
}

/**
 * Returns debug information collected
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Autoload_Loader, getDebug)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "debug");
}

/**
 * Returns the directories currently registered in the autoloader
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Autoload_Loader, getDirectories)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "directories");
}

/**
 * Returns the file extensions registered in the loader
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Autoload_Loader, getExtensions)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "extensions");
}

/**
 * Returns the files currently registered in the autoloader
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Autoload_Loader, getFiles)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "files");
}

/**
 * Get the path when a class was found
 *
 * @return string|null
 */
PHP_METHOD(Phalcon_Autoload_Loader, getFoundPath)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "foundPath");
}

/**
 * Returns the namespaces currently registered in the autoloader
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Autoload_Loader, getNamespaces)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "namespaces");
}

/**
 * Checks if a file exists and then adds the file by doing virtual require
 */
PHP_METHOD(Phalcon_Autoload_Loader, loadFiles)
{
	zval file, files, _0, *_1, _2, _3$$3, _5$$3, _7$$4, _8$$5, _9$$5, _10$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$6);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("files"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&files, &_0);
	zephir_is_iterable(&files, 0, "phalcon/Autoload/Loader.zep", 322);
	if (Z_TYPE_P(&files) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&files), _1)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _1);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "loader:beforeCheckPath");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", &_4, 0, &_3$$3, &file);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "requirefile", &_6, 0, &file);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_5$$3)) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("foundPath"), &file);
				ZEPHIR_INIT_NVAR(&_7$$4);
				ZVAL_STRING(&_7$$4, "loader:pathFound");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", &_4, 0, &_7$$4, &file);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &files, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &files, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&file, &files, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_8$$5);
				ZVAL_STRING(&_8$$5, "loader:beforeCheckPath");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", &_4, 0, &_8$$5, &file);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_9$$5, this_ptr, "requirefile", &_6, 0, &file);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_9$$5)) {
					zephir_update_property_zval(this_ptr, ZEND_STRL("foundPath"), &file);
					ZEPHIR_INIT_NVAR(&_10$$6);
					ZVAL_STRING(&_10$$6, "loader:pathFound");
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", &_4, 0, &_10$$6, &file);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &files, "next", NULL, 0);
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(prepend)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prepend_param);
	if (!prepend_param) {
		prepend = 0;
	} else {
		prepend = zephir_get_boolval(prepend_param);
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
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 178, &_1$$3, &__$true, &_3$$3);
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
 * @return Loader
 */
PHP_METHOD(Phalcon_Autoload_Loader, setClasses)
{
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge;
	zval *classes_param = NULL, *merge_param = NULL, className, name, *_1, _2, _0$$3;
	zval classes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classes);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(classes)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &classes_param, &merge_param);
	zephir_get_arrval(&classes, classes_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (!merge) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("classes"), &_0$$3);
	}
	zephir_is_iterable(&classes, 0, "phalcon/Autoload/Loader.zep", 364);
	if (Z_TYPE_P(&classes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&classes), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&name, _4);
			} else {
				ZVAL_LONG(&name, _3);
			}
			ZEPHIR_INIT_NVAR(&className);
			ZVAL_COPY(&className, _1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addclass", &_5, 0, &name, &className);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &classes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &classes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &classes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&className, &classes, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addclass", &_5, 0, &name, &className);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &classes, "next", NULL, 0);
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
 * @return Loader
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(directories)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &directories_param, &merge_param);
	zephir_get_arrval(&directories, directories_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addtocollection", NULL, 179, &directories, &_0, &_1, &_2);
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
 * @return Loader
 */
PHP_METHOD(Phalcon_Autoload_Loader, setExtensions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge;
	zval *extensions_param = NULL, *merge_param = NULL, extension, *_4, _5, _0$$3, _1$$3, _2$$3, _3$$3;
	zval extensions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(extensions)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &extensions_param, &merge_param);
	zephir_get_arrval(&extensions, extensions_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (!merge) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("extensions"), &_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sha256");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "php");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "hash", NULL, 68, &_1$$3, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "php");
		zephir_update_property_array(this_ptr, SL("extensions"), &_3$$3, &_1$$3);
	}
	zephir_is_iterable(&extensions, 0, "phalcon/Autoload/Loader.zep", 407);
	if (Z_TYPE_P(&extensions) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extensions), _4)
		{
			ZEPHIR_INIT_NVAR(&extension);
			ZVAL_COPY(&extension, _4);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addextension", &_6, 0, &extension);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &extensions, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &extensions, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&extension, &extensions, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addextension", &_6, 0, &extension);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &extensions, "next", NULL, 0);
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
 * @return Loader
 * @throws Exception
 */
PHP_METHOD(Phalcon_Autoload_Loader, setFileCheckingCallback)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *method = NULL, method_sub, __$null, _0$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(method)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
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
		zephir_create_closure_ex(&_0$$4, NULL, phalcon_7__closure_ce, SL("__invoke"));
		zephir_update_property_zval(this_ptr, ZEND_STRL("fileCheckingCallback"), &_0$$4);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_autoload_exception_ce, "The 'method' parameter must be either a callable or NULL", "phalcon/Autoload/Loader.zep", 441);
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
 * @return Loader
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(files)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &files_param, &merge_param);
	zephir_get_arrval(&files, files_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addtocollection", NULL, 179, &files, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Register namespaces and their related directories
 *
 * @param array $namespaces
 * @param bool  $merge
 *
 * @return Loader
 */
PHP_METHOD(Phalcon_Autoload_Loader, setNamespaces)
{
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge;
	zval *namespaces_param = NULL, *merge_param = NULL, dirSeparator, directories, name, *_1, _2, _0$$3, _5$$4, _8$$5;
	zval namespaces;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&dirSeparator);
	ZVAL_UNDEF(&directories);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(namespaces)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &namespaces_param, &merge_param);
	zephir_get_arrval(&namespaces, namespaces_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	ZEPHIR_INIT_VAR(&dirSeparator);
	ZVAL_STRING(&dirSeparator, "/");
	if (!merge) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("namespaces"), &_0$$3);
	}
	zephir_is_iterable(&namespaces, 0, "phalcon/Autoload/Loader.zep", 489);
	if (Z_TYPE_P(&namespaces) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&namespaces), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&name, _4);
			} else {
				ZVAL_LONG(&name, _3);
			}
			ZEPHIR_INIT_NVAR(&directories);
			ZVAL_COPY(&directories, _1);
			ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "checkdirectories", &_6, 172, &directories, &dirSeparator);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&directories, &_5$$4);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addnamespace", &_7, 0, &name, &directories);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &namespaces, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &namespaces, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &namespaces, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&directories, &namespaces, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8$$5, this_ptr, "checkdirectories", &_6, 172, &directories, &dirSeparator);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&directories, &_8$$5);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addnamespace", &_7, 0, &name, &directories);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &namespaces, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&directories);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_THIS();
}

/**
 * Unregister the autoload method
 *
 * @return Loader
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


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("isRegistered"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0);
		zephir_array_fast_append(&_1$$3, this_ptr);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "autoload");
		zephir_array_fast_append(&_1$$3, &_2$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_unregister", NULL, 180, &_1$$3);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, _0, _1, _2$$3;
	zval file, _4, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(file)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);
	zephir_get_strval(&file, file_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("fileCheckingCallback"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "call_user_func", NULL, 181, &_0, &file);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "loader:pathFound");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_2$$3, &file);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, "Require: ", &file);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", NULL, 174, &_3$$3);
		zephir_check_call_status();
		if (zephir_require_once_zval(&file) == FAILURE) {
			RETURN_MM_NULL();
		}
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SV(&_4, "Require: 404: ", &file);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", NULL, 174, &_4);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);
	zephir_get_strval(&message, message_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("isDebug"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		zephir_update_property_array_append(this_ptr, SL("debug"), &message);
	}
	ZEPHIR_MM_RESTORE();
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
 * @return Loader
 */
PHP_METHOD(Phalcon_Autoload_Loader, addToCollection)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge;
	zval collectionName, method;
	zval *collection_param = NULL, *collectionName_param = NULL, *method_param = NULL, *merge_param = NULL, element, *_1, _2, _0$$3;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&collectionName);
	ZVAL_UNDEF(&method);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_ARRAY(collection)
		Z_PARAM_STR(collectionName)
		Z_PARAM_STR(method)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &collection_param, &collectionName_param, &method_param, &merge_param);
	zephir_get_arrval(&collection, collection_param);
	zephir_get_strval(&collectionName, collectionName_param);
	zephir_get_strval(&method, method_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (!merge) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		zephir_update_property_zval_zval(this_ptr, &collectionName, &_0$$3);
	}
	zephir_is_iterable(&collection, 0, "phalcon/Autoload/Loader.zep", 584);
	if (Z_TYPE_P(&collection) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&collection), _1)
		{
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _1);
			ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &method, NULL, 0, &element);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &collection, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &collection, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&element, &collection, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &method, NULL, 0, &element);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &collection, "next", NULL, 0);
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
	zval *className_param = NULL, filePath, _0, _1$$3, _2$$3, _3$$3;
	zval className;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);
	zephir_get_strval(&className, className_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("classes"), PH_NOISY_CC | PH_READONLY);
	if (1 == zephir_array_isset(&_0, &className)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("classes"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&filePath);
		zephir_array_fetch(&filePath, &_1$$3, &className, PH_NOISY, "phalcon/Autoload/Loader.zep", 600);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "loader:pathFound");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_2$$3, &filePath);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "requirefile", NULL, 0, &filePath);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, "Class: load: ", &filePath);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", NULL, 174, &_3$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
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
	zephir_fcall_cache_entry *_8 = NULL, *_10 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool isDirectory;
	zval *directories_param = NULL, className, *className_param = NULL, *isDirectory_param = NULL, dirSeparator, directory, extension, extensions, filePath, fixedDirectory, nsSeparator, _0, _1, *_2, _3, _4$$3, *_5$$3, _6$$3, _7$$4, _9$$4, _11$$6, _13$$7, _14$$7, _15$$9, _16$$10, *_17$$10, _18$$10, _19$$11, _20$$11, _21$$13, _22$$14, _23$$14, _24$$16;
	zval directories;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directories);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&dirSeparator);
	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&fixedDirectory);
	ZVAL_UNDEF(&nsSeparator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_24$$16);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ARRAY(directories)
		Z_PARAM_STR(className)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(isDirectory)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &directories_param, &className_param, &isDirectory_param);
	zephir_get_arrval(&directories, directories_param);
	zephir_get_strval(&className, className_param);
	if (!isDirectory_param) {
		isDirectory = 0;
	} else {
		isDirectory = zephir_get_boolval(isDirectory_param);
	}


	ZEPHIR_INIT_VAR(&dirSeparator);
	ZVAL_STRING(&dirSeparator, "/");
	ZEPHIR_INIT_VAR(&nsSeparator);
	ZVAL_STRING(&nsSeparator, "\\");
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_str_replace(&_0, &nsSeparator, &dirSeparator, &className);
	ZEPHIR_CPY_WRT(&className, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("extensions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&extensions, &_1);
	zephir_is_iterable(&directories, 0, "phalcon/Autoload/Loader.zep", 659);
	if (Z_TYPE_P(&directories) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&directories), _2)
		{
			ZEPHIR_INIT_NVAR(&directory);
			ZVAL_COPY(&directory, _2);
			ZEPHIR_INIT_NVAR(&_4$$3);
			zephir_fast_trim(&_4$$3, &directory, &dirSeparator, ZEPHIR_TRIM_RIGHT);
			ZEPHIR_INIT_NVAR(&fixedDirectory);
			ZEPHIR_CONCAT_VV(&fixedDirectory, &_4$$3, &dirSeparator);
			zephir_is_iterable(&extensions, 0, "phalcon/Autoload/Loader.zep", 657);
			if (Z_TYPE_P(&extensions) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extensions), _5$$3)
				{
					ZEPHIR_INIT_NVAR(&extension);
					ZVAL_COPY(&extension, _5$$3);
					ZEPHIR_INIT_NVAR(&filePath);
					ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &className, ".", &extension);
					zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
					ZEPHIR_INIT_NVAR(&_7$$4);
					ZVAL_STRING(&_7$$4, "loader:beforeCheckPath");
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", &_8, 0, &_7$$4, &filePath);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_9$$4, this_ptr, "requirefile", &_10, 0, &filePath);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_9$$4)) {
						if (isDirectory) {
							ZEPHIR_INIT_NVAR(&_11$$6);
							ZEPHIR_CONCAT_SV(&_11$$6, "Directories: ", &filePath);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", &_12, 174, &_11$$6);
							zephir_check_call_status();
						}
						RETURN_MM_BOOL(1);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &extensions, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_6$$3, &extensions, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_6$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&extension, &extensions, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&filePath);
						ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &className, ".", &extension);
						zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
						ZEPHIR_INIT_NVAR(&_13$$7);
						ZVAL_STRING(&_13$$7, "loader:beforeCheckPath");
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", &_8, 0, &_13$$7, &filePath);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_14$$7, this_ptr, "requirefile", &_10, 0, &filePath);
						zephir_check_call_status();
						if (ZEPHIR_IS_TRUE_IDENTICAL(&_14$$7)) {
							if (isDirectory) {
								ZEPHIR_INIT_NVAR(&_15$$9);
								ZEPHIR_CONCAT_SV(&_15$$9, "Directories: ", &filePath);
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", &_12, 174, &_15$$9);
								zephir_check_call_status();
							}
							RETURN_MM_BOOL(1);
						}
					ZEPHIR_CALL_METHOD(NULL, &extensions, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&extension);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &directories, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &directories, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&directory, &directories, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_16$$10);
				zephir_fast_trim(&_16$$10, &directory, &dirSeparator, ZEPHIR_TRIM_RIGHT);
				ZEPHIR_INIT_NVAR(&fixedDirectory);
				ZEPHIR_CONCAT_VV(&fixedDirectory, &_16$$10, &dirSeparator);
				zephir_is_iterable(&extensions, 0, "phalcon/Autoload/Loader.zep", 657);
				if (Z_TYPE_P(&extensions) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extensions), _17$$10)
					{
						ZEPHIR_INIT_NVAR(&extension);
						ZVAL_COPY(&extension, _17$$10);
						ZEPHIR_INIT_NVAR(&filePath);
						ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &className, ".", &extension);
						zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
						ZEPHIR_INIT_NVAR(&_19$$11);
						ZVAL_STRING(&_19$$11, "loader:beforeCheckPath");
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", &_8, 0, &_19$$11, &filePath);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_20$$11, this_ptr, "requirefile", &_10, 0, &filePath);
						zephir_check_call_status();
						if (ZEPHIR_IS_TRUE_IDENTICAL(&_20$$11)) {
							if (isDirectory) {
								ZEPHIR_INIT_NVAR(&_21$$13);
								ZEPHIR_CONCAT_SV(&_21$$13, "Directories: ", &filePath);
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", &_12, 174, &_21$$13);
								zephir_check_call_status();
							}
							RETURN_MM_BOOL(1);
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &extensions, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_18$$10, &extensions, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_18$$10)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&extension, &extensions, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&filePath);
							ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &className, ".", &extension);
							zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
							ZEPHIR_INIT_NVAR(&_22$$14);
							ZVAL_STRING(&_22$$14, "loader:beforeCheckPath");
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", &_8, 0, &_22$$14, &filePath);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_23$$14, this_ptr, "requirefile", &_10, 0, &filePath);
							zephir_check_call_status();
							if (ZEPHIR_IS_TRUE_IDENTICAL(&_23$$14)) {
								if (isDirectory) {
									ZEPHIR_INIT_NVAR(&_24$$16);
									ZEPHIR_CONCAT_SV(&_24$$16, "Directories: ", &filePath);
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", &_12, 174, &_24$$16);
									zephir_check_call_status();
								}
								RETURN_MM_BOOL(1);
							}
						ZEPHIR_CALL_METHOD(NULL, &extensions, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&extension);
			ZEPHIR_CALL_METHOD(NULL, &directories, "next", NULL, 0);
			zephir_check_call_status();
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
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, directories, fileName, namespaces, nsSeparator, prefix, _0, *_1, _2, _5$$3, _6$$3, _7$$3, _8$$3, _10$$5, _11$$5, _13$$6, _14$$6, _15$$6, _16$$6, _17$$8, _18$$8;
	zval className;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&directories);
	ZVAL_UNDEF(&fileName);
	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&nsSeparator);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);
	zephir_get_strval(&className, className_param);


	ZEPHIR_INIT_VAR(&nsSeparator);
	ZVAL_STRING(&nsSeparator, "\\");
	zephir_read_property(&_0, this_ptr, ZEND_STRL("namespaces"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&namespaces, &_0);
	zephir_is_iterable(&namespaces, 0, "phalcon/Autoload/Loader.zep", 694);
	if (Z_TYPE_P(&namespaces) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&namespaces), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&prefix);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&prefix, _4);
			} else {
				ZVAL_LONG(&prefix, _3);
			}
			ZEPHIR_INIT_NVAR(&directories);
			ZVAL_COPY(&directories, _1);
			if (1 != zephir_start_with(&className, &prefix, NULL)) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_5$$3);
			zephir_fast_trim(&_5$$3, &prefix, &nsSeparator, ZEPHIR_TRIM_RIGHT);
			ZEPHIR_INIT_NVAR(&_6$$3);
			ZEPHIR_CONCAT_VV(&_6$$3, &_5$$3, &nsSeparator);
			ZEPHIR_CPY_WRT(&prefix, &_6$$3);
			ZVAL_LONG(&_7$$3, zephir_fast_strlen_ev(&prefix));
			ZEPHIR_INIT_NVAR(&fileName);
			zephir_substr(&fileName, &className, zephir_get_intval(&_7$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_CALL_METHOD(&_8$$3, this_ptr, "autoloadcheckdirectories", &_9, 177, &directories, &fileName);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_8$$3)) {
				zephir_read_property(&_10$$5, this_ptr, ZEND_STRL("checkedPath"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_11$$5);
				ZEPHIR_CONCAT_SVSV(&_11$$5, "Namespace: ", &prefix, " - ", &_10$$5);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", &_12, 174, &_11$$5);
				zephir_check_call_status();
				RETURN_MM_BOOL(1);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &namespaces, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &namespaces, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&prefix, &namespaces, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&directories, &namespaces, "current", NULL, 0);
			zephir_check_call_status();
				if (1 != zephir_start_with(&className, &prefix, NULL)) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_13$$6);
				zephir_fast_trim(&_13$$6, &prefix, &nsSeparator, ZEPHIR_TRIM_RIGHT);
				ZEPHIR_INIT_NVAR(&_14$$6);
				ZEPHIR_CONCAT_VV(&_14$$6, &_13$$6, &nsSeparator);
				ZEPHIR_CPY_WRT(&prefix, &_14$$6);
				ZVAL_LONG(&_15$$6, zephir_fast_strlen_ev(&prefix));
				ZEPHIR_INIT_NVAR(&fileName);
				zephir_substr(&fileName, &className, zephir_get_intval(&_15$$6), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_CALL_METHOD(&_16$$6, this_ptr, "autoloadcheckdirectories", &_9, 177, &directories, &fileName);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_16$$6)) {
					zephir_read_property(&_17$$8, this_ptr, ZEND_STRL("checkedPath"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_18$$8);
					ZEPHIR_CONCAT_SVSV(&_18$$8, "Namespace: ", &prefix, " - ", &_17$$8);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddebug", &_12, 174, &_18$$8);
					zephir_check_call_status();
					RETURN_MM_BOOL(1);
				}
			ZEPHIR_CALL_METHOD(NULL, &namespaces, "next", NULL, 0);
			zephir_check_call_status();
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
 *
 * @return array<string, string>
 * @throws Exception
 */
PHP_METHOD(Phalcon_Autoload_Loader, checkDirectories)
{
	zend_bool _0;
	zval results;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval dirSeparator;
	zval *directories = NULL, directories_sub, *dirSeparator_param = NULL, directory, *_2, _3, _1$$4, _4$$5, _5$$5, _6$$5, _7$$5, _9$$6, _10$$6, _11$$6, _12$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directories_sub);
	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&dirSeparator);
	ZVAL_UNDEF(&results);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(directories)
		Z_PARAM_STR(dirSeparator)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &directories, &dirSeparator_param);
	ZEPHIR_SEPARATE_PARAM(directories);
	zephir_get_strval(&dirSeparator, dirSeparator_param);


	_0 = !(Z_TYPE_P(directories) == IS_STRING);
	if (_0) {
		_0 = !(Z_TYPE_P(directories) == IS_ARRAY);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_autoload_exception_ce, "The directories parameter is not a string or array", "phalcon/Autoload/Loader.zep", 717);
		return;
	}
	if (Z_TYPE_P(directories) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_create_array(&_1$$4, 1, 0);
		zephir_array_fast_append(&_1$$4, directories);
		ZEPHIR_CPY_WRT(directories, &_1$$4);
	}
	ZEPHIR_INIT_VAR(&results);
	array_init(&results);
	zephir_is_iterable(directories, 0, "phalcon/Autoload/Loader.zep", 731);
	if (Z_TYPE_P(directories) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(directories), _2)
		{
			ZEPHIR_INIT_NVAR(&directory);
			ZVAL_COPY(&directory, _2);
			ZEPHIR_INIT_NVAR(&_4$$5);
			zephir_fast_trim(&_4$$5, &directory, &dirSeparator, ZEPHIR_TRIM_RIGHT);
			ZEPHIR_INIT_NVAR(&_5$$5);
			ZEPHIR_CONCAT_VV(&_5$$5, &_4$$5, &dirSeparator);
			ZEPHIR_CPY_WRT(&directory, &_5$$5);
			ZEPHIR_INIT_NVAR(&_6$$5);
			ZVAL_STRING(&_6$$5, "sha256");
			ZEPHIR_CALL_FUNCTION(&_7$$5, "hash", &_8, 68, &_6$$5, &directory);
			zephir_check_call_status();
			zephir_array_update_zval(&results, &_7$$5, &directory, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, directories, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, directories, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&directory, directories, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_9$$6);
				zephir_fast_trim(&_9$$6, &directory, &dirSeparator, ZEPHIR_TRIM_RIGHT);
				ZEPHIR_INIT_NVAR(&_10$$6);
				ZEPHIR_CONCAT_VV(&_10$$6, &_9$$6, &dirSeparator);
				ZEPHIR_CPY_WRT(&directory, &_10$$6);
				ZEPHIR_INIT_NVAR(&_11$$6);
				ZVAL_STRING(&_11$$6, "sha256");
				ZEPHIR_CALL_FUNCTION(&_12$$6, "hash", &_8, 68, &_11$$6, &directory);
				zephir_check_call_status();
				zephir_array_update_zval(&results, &_12$$6, &directory, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, directories, "next", NULL, 0);
			zephir_check_call_status();
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
	

		ZEPHIR_MM_GROW();
	
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

