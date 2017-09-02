
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/require.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Phalcon\Loader
 *
 * This component helps to load your project classes automatically based on some conventions
 *
 *<code>
 * use Phalcon\Loader;
 *
 * // Creates the autoloader
 * $loader = new Loader();
 *
 * // Register some namespaces
 * $loader->registerNamespaces(
 *     [
 *         "Example\\Base"    => "vendor/example/base/",
 *         "Example\\Adapter" => "vendor/example/adapter/",
 *         "Example"          => "vendor/example/",
 *     ]
 * );
 *
 * // Register autoloader
 * $loader->register();
 *
 * // Requiring this class will automatically include file vendor/example/adapter/Some.php
 * $adapter = new \Example\Adapter\Some();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Loader) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Loader, phalcon, loader, phalcon_loader_method_entry, 0);

	zend_declare_property_null(phalcon_loader_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_loader_ce, SL("_foundPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_loader_ce, SL("_checkedPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_loader_ce, SL("_classes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_loader_ce, SL("_extensions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_loader_ce, SL("_namespaces"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_loader_ce, SL("_directories"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_loader_ce, SL("_files"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_loader_ce, SL("_registered"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_loader_ce->create_object = zephir_init_properties_Phalcon_Loader;

	zend_class_implements(phalcon_loader_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Loader, setEventsManager) {

	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_zval(this_ptr, SL("_eventsManager"), eventsManager);

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Loader, getEventsManager) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_eventsManager");

}

/**
 * Sets an array of file extensions that the loader must try in each attempt to locate the file
 */
PHP_METHOD(Phalcon_Loader, setExtensions) {

	zval *extensions_param = NULL;
	zval extensions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extensions);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &extensions_param);

	ZEPHIR_OBS_COPY_OR_DUP(&extensions, extensions_param);


	zephir_update_property_zval(this_ptr, SL("_extensions"), &extensions);
	RETURN_THIS();

}

/**
 * Returns the file extensions registered in the loader
 */
PHP_METHOD(Phalcon_Loader, getExtensions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_extensions");

}

/**
 * Register namespaces and their related directories
 */
PHP_METHOD(Phalcon_Loader, registerNamespaces) {

	zend_string *_2$$3;
	zend_ulong _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge;
	zval *namespaces_param = NULL, *merge_param = NULL, preparedNamespaces, name, paths, *_0$$3, _3$$4, _5$$4, _6$$4, _7$$4, _4$$5;
	zval namespaces;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&preparedNamespaces);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &namespaces_param, &merge_param);

	ZEPHIR_OBS_COPY_OR_DUP(&namespaces, namespaces_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	ZEPHIR_CALL_METHOD(&preparedNamespaces, this_ptr, "preparenamespace", NULL, 0, &namespaces);
	zephir_check_call_status();
	if (merge) {
		zephir_is_iterable(&preparedNamespaces, 0, "phalcon/loader.zep", 123);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&preparedNamespaces), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&name, _2$$3);
			} else {
				ZVAL_LONG(&name, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&paths);
			ZVAL_COPY(&paths, _0$$3);
			zephir_read_property(&_3$$4, this_ptr, SL("_namespaces"), PH_NOISY_CC | PH_READONLY);
			if (!(zephir_array_isset(&_3$$4, &name))) {
				ZEPHIR_INIT_NVAR(&_4$$5);
				array_init(&_4$$5);
				zephir_update_property_array(this_ptr, SL("_namespaces"), &name, &_4$$5 TSRMLS_CC);
			}
			ZEPHIR_INIT_NVAR(&_5$$4);
			zephir_read_property(&_6$$4, this_ptr, SL("_namespaces"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_7$$4, &_6$$4, &name, PH_NOISY | PH_READONLY, "phalcon/loader.zep", 121 TSRMLS_CC);
			zephir_fast_array_merge(&_5$$4, &_7$$4, &paths TSRMLS_CC);
			zephir_update_property_array(this_ptr, SL("_namespaces"), &name, &_5$$4 TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&paths);
		ZEPHIR_INIT_NVAR(&name);
	} else {
		zephir_update_property_zval(this_ptr, SL("_namespaces"), &preparedNamespaces);
	}
	RETURN_THIS();

}

PHP_METHOD(Phalcon_Loader, prepareNamespace) {

	zend_string *_2;
	zend_ulong _1;
	zval *namespace_param = NULL, localPaths, name, paths, prepared, *_0;
	zval namespace;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespace);
	ZVAL_UNDEF(&localPaths);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&prepared);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespace_param);

	ZEPHIR_OBS_COPY_OR_DUP(&namespace, namespace_param);


	ZEPHIR_INIT_VAR(&prepared);
	array_init(&prepared);
	zephir_is_iterable(&namespace, 0, "phalcon/loader.zep", 145);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&namespace), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&name, _2);
		} else {
			ZVAL_LONG(&name, _1);
		}
		ZEPHIR_INIT_NVAR(&paths);
		ZVAL_COPY(&paths, _0);
		if (Z_TYPE_P(&paths) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&localPaths);
			zephir_create_array(&localPaths, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&localPaths, &paths);
		} else {
			ZEPHIR_CPY_WRT(&localPaths, &paths);
		}
		zephir_array_update_zval(&prepared, &name, &localPaths, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&paths);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&prepared);

}

/**
 * Returns the namespaces currently registered in the autoloader
 */
PHP_METHOD(Phalcon_Loader, getNamespaces) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_namespaces");

}

/**
 * Register directories in which "not found" classes could be found
 */
PHP_METHOD(Phalcon_Loader, registerDirs) {

	zend_bool merge;
	zval *directories_param = NULL, *merge_param = NULL, _0$$3, _1$$3;
	zval directories;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directories);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &directories_param, &merge_param);

	ZEPHIR_OBS_COPY_OR_DUP(&directories, directories_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property(&_1$$3, this_ptr, SL("_directories"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_0$$3, &_1$$3, &directories TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_directories"), &_0$$3);
	} else {
		zephir_update_property_zval(this_ptr, SL("_directories"), &directories);
	}
	RETURN_THIS();

}

/**
 * Returns the directories currently registered in the autoloader
 */
PHP_METHOD(Phalcon_Loader, getDirs) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_directories");

}

/**
 * Registers files that are "non-classes" hence need a "require". This is very useful for including files that only
 * have functions
 */
PHP_METHOD(Phalcon_Loader, registerFiles) {

	zend_bool merge;
	zval *files_param = NULL, *merge_param = NULL, _0$$3, _1$$3;
	zval files;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &files_param, &merge_param);

	ZEPHIR_OBS_COPY_OR_DUP(&files, files_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property(&_1$$3, this_ptr, SL("_files"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_0$$3, &_1$$3, &files TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_files"), &_0$$3);
	} else {
		zephir_update_property_zval(this_ptr, SL("_files"), &files);
	}
	RETURN_THIS();

}

/**
 * Returns the files currently registered in the autoloader
 */
PHP_METHOD(Phalcon_Loader, getFiles) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_files");

}

/**
 * Register classes and their locations
 */
PHP_METHOD(Phalcon_Loader, registerClasses) {

	zend_bool merge;
	zval *classes_param = NULL, *merge_param = NULL, _0$$3, _1$$3;
	zval classes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classes);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &classes_param, &merge_param);

	ZEPHIR_OBS_COPY_OR_DUP(&classes, classes_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property(&_1$$3, this_ptr, SL("_classes"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_0$$3, &_1$$3, &classes TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_classes"), &_0$$3);
	} else {
		zephir_update_property_zval(this_ptr, SL("_classes"), &classes);
	}
	RETURN_THIS();

}

/**
 * Returns the class-map currently registered in the autoloader
 */
PHP_METHOD(Phalcon_Loader, getClasses) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_classes");

}

/**
 * Register the autoload method
 */
PHP_METHOD(Phalcon_Loader, register) {

	zval _1$$3;
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prepend_param);

	if (!prepend_param) {
		prepend = 0;
	} else {
		prepend = zephir_get_boolval(prepend_param);
	}


	zephir_read_property(&_0, this_ptr, SL("_registered"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadfiles", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_1$$3, this_ptr);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "autoLoad");
		zephir_array_fast_append(&_1$$3, &_2$$3);
		ZVAL_BOOL(&_3$$3, (prepend ? 1 : 0));
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 271, &_1$$3, &__$true, &_3$$3);
		zephir_check_call_status();
		if (1) {
			zephir_update_property_zval(this_ptr, SL("_registered"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_registered"), &__$false);
		}
	}
	RETURN_THIS();

}

/**
 * Unregister the autoload method
 */
PHP_METHOD(Phalcon_Loader, unregister) {

	zval _1$$3;
	zval __$true, __$false, _0, _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_registered"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_1$$3, this_ptr);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "autoLoad");
		zephir_array_fast_append(&_1$$3, &_2$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_unregister", NULL, 272, &_1$$3);
		zephir_check_call_status();
		if (0) {
			zephir_update_property_zval(this_ptr, SL("_registered"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_registered"), &__$false);
		}
	}
	RETURN_THIS();

}

/**
 * Checks if a file exists and then adds the file by doing virtual require
 */
PHP_METHOD(Phalcon_Loader, loadFiles) {

	zval filePath, _0, *_1, _2$$3, _5$$3, _3$$4, _4$$4, _7$$5, _8$$6, _9$$6;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_files"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/loader.zep", 288);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&filePath);
		ZVAL_COPY(&filePath, _1);
		ZEPHIR_OBS_NVAR(&_2$$3);
		zephir_read_property(&_2$$3, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
		if (Z_TYPE_P(&_2$$3) == IS_OBJECT) {
			zephir_update_property_zval(this_ptr, SL("_checkedPath"), &filePath);
			zephir_read_property(&_3$$4, this_ptr, SL("_eventsManager"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "loader:beforeCheckPath");
			ZEPHIR_CALL_METHOD(NULL, &_3$$4, "fire", NULL, 0, &_4$$4, this_ptr, &filePath);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_FUNCTION(&_5$$3, "is_file", &_6, 273, &filePath);
		zephir_check_call_status();
		if (zephir_is_true(&_5$$3)) {
			ZEPHIR_OBS_NVAR(&_7$$5);
			zephir_read_property(&_7$$5, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
			if (Z_TYPE_P(&_7$$5) == IS_OBJECT) {
				zephir_update_property_zval(this_ptr, SL("_foundPath"), &filePath);
				zephir_read_property(&_8$$6, this_ptr, SL("_eventsManager"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_9$$6);
				ZVAL_STRING(&_9$$6, "loader:pathFound");
				ZEPHIR_CALL_METHOD(NULL, &_8$$6, "fire", NULL, 0, &_9$$6, this_ptr, &filePath);
				zephir_check_call_status();
			}
			if (zephir_require_zval(&filePath TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&filePath);
	ZEPHIR_MM_RESTORE();

}

/**
 * Autoloads the registered classes
 */
PHP_METHOD(Phalcon_Loader, autoLoad) {

	zend_string *_4;
	zend_ulong _3;
	zephir_fcall_cache_entry *_12 = NULL, *_14 = NULL, *_16 = NULL, *_22 = NULL, *_25 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, eventsManager, classes, extensions, filePath, ds, fixedDirectory, directories, ns, namespaces, nsPrefix, directory, fileName, extension, nsClassName, *_2, _17, *_18, _0$$3, _1$$5, _5$$6, _6$$6, _7$$6, *_8$$6, _9$$9, *_10$$9, _11$$11, _13$$10, _15$$13, _19$$14, *_20$$14, _21$$16, _23$$15, _24$$18, _26$$19;
	zval className;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&classes);
	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&ds);
	ZVAL_UNDEF(&fixedDirectory);
	ZVAL_UNDEF(&directories);
	ZVAL_UNDEF(&ns);
	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&nsPrefix);
	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&fileName);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&nsClassName);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_21$$16);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$18);
	ZVAL_UNDEF(&_26$$19);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	if (UNEXPECTED(Z_TYPE_P(className_param) != IS_STRING && Z_TYPE_P(className_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'className' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(className_param) == IS_STRING)) {
		zephir_get_strval(&className, className_param);
	} else {
		ZEPHIR_INIT_VAR(&className);
		ZVAL_EMPTY_STRING(&className);
	}


	ZEPHIR_OBS_VAR(&eventsManager);
	zephir_read_property(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "loader:beforeCheckClass");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_0$$3, this_ptr, &className);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&classes);
	zephir_read_property(&classes, this_ptr, SL("_classes"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&filePath);
	if (zephir_array_isset_fetch(&filePath, &classes, &className, 0 TSRMLS_CC)) {
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			zephir_update_property_zval(this_ptr, SL("_foundPath"), &filePath);
			ZEPHIR_INIT_VAR(&_1$$5);
			ZVAL_STRING(&_1$$5, "loader:pathFound");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_1$$5, this_ptr, &filePath);
			zephir_check_call_status();
		}
		if (zephir_require_zval(&filePath TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_OBS_VAR(&extensions);
	zephir_read_property(&extensions, this_ptr, SL("_extensions"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&ds);
	ZVAL_STRING(&ds, "/");
	ZEPHIR_INIT_VAR(&ns);
	ZVAL_STRING(&ns, "\\");
	ZEPHIR_OBS_VAR(&namespaces);
	zephir_read_property(&namespaces, this_ptr, SL("_namespaces"), PH_NOISY_CC);
	zephir_is_iterable(&namespaces, 0, "phalcon/loader.zep", 392);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&namespaces), _3, _4, _2)
	{
		ZEPHIR_INIT_NVAR(&nsPrefix);
		if (_4 != NULL) { 
			ZVAL_STR_COPY(&nsPrefix, _4);
		} else {
			ZVAL_LONG(&nsPrefix, _3);
		}
		ZEPHIR_INIT_NVAR(&directories);
		ZVAL_COPY(&directories, _2);
		if (!(zephir_start_with(&className, &nsPrefix, NULL))) {
			continue;
		}
		ZEPHIR_INIT_LNVAR(_5$$6);
		ZEPHIR_CONCAT_VV(&_5$$6, &nsPrefix, &ns);
		ZVAL_LONG(&_6$$6, zephir_fast_strlen_ev(&_5$$6));
		ZEPHIR_INIT_NVAR(&fileName);
		zephir_substr(&fileName, &className, zephir_get_intval(&_6$$6), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		if (!(zephir_is_true(&fileName))) {
			continue;
		}
		ZEPHIR_INIT_NVAR(&_7$$6);
		zephir_fast_str_replace(&_7$$6, &ns, &ds, &fileName TSRMLS_CC);
		ZEPHIR_CPY_WRT(&fileName, &_7$$6);
		zephir_is_iterable(&directories, 0, "phalcon/loader.zep", 387);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&directories), _8$$6)
		{
			ZEPHIR_INIT_NVAR(&directory);
			ZVAL_COPY(&directory, _8$$6);
			ZEPHIR_INIT_NVAR(&_9$$9);
			zephir_fast_trim(&_9$$9, &directory, &ds, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&fixedDirectory);
			ZEPHIR_CONCAT_VV(&fixedDirectory, &_9$$9, &ds);
			zephir_is_iterable(&extensions, 0, "phalcon/loader.zep", 386);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extensions), _10$$9)
			{
				ZEPHIR_INIT_NVAR(&extension);
				ZVAL_COPY(&extension, _10$$9);
				ZEPHIR_INIT_NVAR(&filePath);
				ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &fileName, ".", &extension);
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					zephir_update_property_zval(this_ptr, SL("_checkedPath"), &filePath);
					ZEPHIR_INIT_NVAR(&_11$$11);
					ZVAL_STRING(&_11$$11, "loader:beforeCheckPath");
					ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_12, 0, &_11$$11, this_ptr);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_FUNCTION(&_13$$10, "is_file", &_14, 273, &filePath);
				zephir_check_call_status();
				if (zephir_is_true(&_13$$10)) {
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						zephir_update_property_zval(this_ptr, SL("_foundPath"), &filePath);
						ZEPHIR_INIT_NVAR(&_15$$13);
						ZVAL_STRING(&_15$$13, "loader:pathFound");
						ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_16, 0, &_15$$13, this_ptr, &filePath);
						zephir_check_call_status();
					}
					if (zephir_require_zval(&filePath TSRMLS_CC) == FAILURE) {
						RETURN_MM_NULL();
					}
					RETURN_MM_BOOL(1);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&extension);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&directory);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&directories);
	ZEPHIR_INIT_NVAR(&nsPrefix);
	ZEPHIR_INIT_VAR(&_17);
	ZVAL_STRING(&_17, "\\");
	ZEPHIR_INIT_VAR(&nsClassName);
	zephir_fast_str_replace(&nsClassName, &_17, &ds, &className TSRMLS_CC);
	ZEPHIR_OBS_NVAR(&directories);
	zephir_read_property(&directories, this_ptr, SL("_directories"), PH_NOISY_CC);
	zephir_is_iterable(&directories, 0, "phalcon/loader.zep", 447);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&directories), _18)
	{
		ZEPHIR_INIT_NVAR(&directory);
		ZVAL_COPY(&directory, _18);
		ZEPHIR_INIT_NVAR(&_19$$14);
		zephir_fast_trim(&_19$$14, &directory, &ds, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&fixedDirectory);
		ZEPHIR_CONCAT_VV(&fixedDirectory, &_19$$14, &ds);
		zephir_is_iterable(&extensions, 0, "phalcon/loader.zep", 442);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extensions), _20$$14)
		{
			ZEPHIR_INIT_NVAR(&extension);
			ZVAL_COPY(&extension, _20$$14);
			ZEPHIR_INIT_NVAR(&filePath);
			ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &nsClassName, ".", &extension);
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				zephir_update_property_zval(this_ptr, SL("_checkedPath"), &filePath);
				ZEPHIR_INIT_NVAR(&_21$$16);
				ZVAL_STRING(&_21$$16, "loader:beforeCheckPath");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_22, 0, &_21$$16, this_ptr, &filePath);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_FUNCTION(&_23$$15, "is_file", &_14, 273, &filePath);
			zephir_check_call_status();
			if (zephir_is_true(&_23$$15)) {
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					zephir_update_property_zval(this_ptr, SL("_foundPath"), &filePath);
					ZEPHIR_INIT_NVAR(&_24$$18);
					ZVAL_STRING(&_24$$18, "loader:pathFound");
					ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_25, 0, &_24$$18, this_ptr, &filePath);
					zephir_check_call_status();
				}
				if (zephir_require_zval(&filePath TSRMLS_CC) == FAILURE) {
					RETURN_MM_NULL();
				}
				RETURN_MM_BOOL(1);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&extension);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&directory);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_26$$19);
		ZVAL_STRING(&_26$$19, "loader:afterCheckClass");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_26$$19, this_ptr, &className);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Get the path when a class was found
 */
PHP_METHOD(Phalcon_Loader, getFoundPath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_foundPath");

}

/**
 * Get the path the loader is checking for a path
 */
PHP_METHOD(Phalcon_Loader, getCheckedPath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_checkedPath");

}

zend_object *zephir_init_properties_Phalcon_Loader(zend_class_entry *class_type TSRMLS_DC) {

		zval _7$$6;
	zval _0, _2, _4, _6, _9, _1$$3, _3$$4, _5$$5, _8$$6, _10$$7;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_7$$6);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_files"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_files"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("_directories"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("_directories"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("_namespaces"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("_namespaces"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("_extensions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			zephir_create_array(&_7$$6, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_8$$6);
			ZVAL_STRING(&_8$$6, "php");
			zephir_array_fast_append(&_7$$6, &_8$$6);
			zephir_update_property_zval(this_ptr, SL("_extensions"), &_7$$6);
		}
		zephir_read_property(&_9, this_ptr, SL("_classes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_9) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_10$$7);
			array_init(&_10$$7);
			zephir_update_property_zval(this_ptr, SL("_classes"), &_10$$7);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

