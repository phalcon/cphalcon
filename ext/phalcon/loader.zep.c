
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
#include "kernel/hash.h"
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
 * //Creates the autoloader
 * $loader = new Loader();
 *
 * //Register some namespaces
 * $loader->registerNamespaces(array(
 *   'Example\Base' => 'vendor/example/base/',
 *   'Example\Adapter' => 'vendor/example/adapter/',
 *   'Example' => 'vendor/example/'
 * ));
 *
 * //register autoloader
 * $loader->register();
 *
 * //Requiring this class will automatically include file vendor/example/adapter/Some.php
 * $adapter = Example\Adapter\Some();
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
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&eventsManager_sub);

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_zval(this_ptr, SL("_eventsManager"), eventsManager);

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Loader, getEventsManager) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_eventsManager");

}

/**
 * Sets an array of file extensions that the loader must try in each attempt to locate the file
 */
PHP_METHOD(Phalcon_Loader, setExtensions) {

	zval *extensions_param = NULL;
	zval extensions;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&extensions);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &extensions_param);

	ZEPHIR_OBS_VAR_ONCE(&extensions);
	ZVAL_COPY(&extensions, extensions_param);


	zephir_update_property_zval(this_ptr, SL("_extensions"), &extensions);
	RETURN_THIS();

}

/**
 * Returns the file extensions registered in the loader
 */
PHP_METHOD(Phalcon_Loader, getExtensions) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_extensions");

}

/**
 * Register namespaces and their related directories
 */
PHP_METHOD(Phalcon_Loader, registerNamespaces) {

	zend_string *_4$$3;
	zend_ulong _3$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge, _0;
	zval *namespaces_param = NULL, *merge_param = NULL, preparedNamespaces, name, paths, _1, *_2$$3, _5$$4, _7$$4, _8$$4, _9$$4, _6$$5;
	zval namespaces;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&preparedNamespaces);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &namespaces_param, &merge_param);

	ZEPHIR_OBS_VAR_ONCE(&namespaces);
	ZVAL_COPY(&namespaces, namespaces_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	ZEPHIR_CALL_METHOD(&preparedNamespaces, this_ptr, "preparenamespace", NULL, 0, &namespaces);
	zephir_check_call_status();
	_0 = merge;
	if (_0) {
		ZEPHIR_OBS_VAR(&_1);
		zephir_read_property(&_1, this_ptr, SL("_namespaces"), PH_NOISY_CC);
		_0 = Z_TYPE_P(&_1) == IS_ARRAY;
	}
	if (_0) {
		zephir_is_iterable(&preparedNamespaces, 0, "phalcon/loader.zep", 119);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&preparedNamespaces), _3$$3, _4$$3, _2$$3)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_4$$3 != NULL) { 
				ZVAL_STR_COPY(&name, _4$$3);
			} else {
				ZVAL_LONG(&name, _3$$3);
			}
			ZEPHIR_INIT_NVAR(&paths);
			ZVAL_COPY(&paths, _2$$3);
			zephir_read_property(&_5$$4, this_ptr, SL("_namespaces"), PH_NOISY_CC | PH_READONLY);
			if (!(zephir_array_isset(&_5$$4, &name))) {
				ZEPHIR_INIT_NVAR(&_6$$5);
				array_init(&_6$$5);
				zephir_update_property_array(this_ptr, SL("_namespaces"), &name, &_6$$5 TSRMLS_CC);
			}
			ZEPHIR_INIT_NVAR(&_7$$4);
			zephir_read_property(&_8$$4, this_ptr, SL("_namespaces"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_9$$4, &_8$$4, &name, PH_NOISY | PH_READONLY, "phalcon/loader.zep", 117 TSRMLS_CC);
			zephir_fast_array_merge(&_7$$4, &_9$$4, &paths TSRMLS_CC);
			zephir_update_property_array(this_ptr, SL("_namespaces"), &name, &_7$$4 TSRMLS_CC);
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
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&namespace);
	ZVAL_UNDEF(&localPaths);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&prepared);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespace_param);

	ZEPHIR_OBS_VAR_ONCE(&namespace);
	ZVAL_COPY(&namespace, namespace_param);


	ZEPHIR_INIT_VAR(&prepared);
	array_init(&prepared);
	zephir_is_iterable(&namespace, 0, "phalcon/loader.zep", 141);
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
	RETURN_CCTOR(prepared);

}

/**
 * Returns the namespaces currently registered in the autoloader
 */
PHP_METHOD(Phalcon_Loader, getNamespaces) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_namespaces");

}

/**
 * Register directories in which "not found" classes could be found
 */
PHP_METHOD(Phalcon_Loader, registerDirs) {

	zend_bool merge, _0;
	zval *directories_param = NULL, *merge_param = NULL, _1, _2$$3, _3$$3;
	zval directories;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&directories);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &directories_param, &merge_param);

	ZEPHIR_OBS_VAR_ONCE(&directories);
	ZVAL_COPY(&directories, directories_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	_0 = merge;
	if (_0) {
		ZEPHIR_OBS_VAR(&_1);
		zephir_read_property(&_1, this_ptr, SL("_directories"), PH_NOISY_CC);
		_0 = Z_TYPE_P(&_1) == IS_ARRAY;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_read_property(&_3$$3, this_ptr, SL("_directories"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_2$$3, &_3$$3, &directories TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_directories"), &_2$$3);
	} else {
		zephir_update_property_zval(this_ptr, SL("_directories"), &directories);
	}
	RETURN_THIS();

}

/**
 * Returns the directories currently registered in the autoloader
 */
PHP_METHOD(Phalcon_Loader, getDirs) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_directories");

}

/**
 * Registers files that are "non-classes" hence need a "require". This is very useful for including files that only
 * have functions
 */
PHP_METHOD(Phalcon_Loader, registerFiles) {

	zend_bool merge, _0;
	zval *files_param = NULL, *merge_param = NULL, _1, _2$$3, _3$$3;
	zval files;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &files_param, &merge_param);

	ZEPHIR_OBS_VAR_ONCE(&files);
	ZVAL_COPY(&files, files_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	_0 = merge;
	if (_0) {
		ZEPHIR_OBS_VAR(&_1);
		zephir_read_property(&_1, this_ptr, SL("_files"), PH_NOISY_CC);
		_0 = Z_TYPE_P(&_1) == IS_ARRAY;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_read_property(&_3$$3, this_ptr, SL("_files"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_2$$3, &_3$$3, &files TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_files"), &_2$$3);
	} else {
		zephir_update_property_zval(this_ptr, SL("_files"), &files);
	}
	RETURN_THIS();

}

/**
 * Returns the files currently registered in the autoloader
 */
PHP_METHOD(Phalcon_Loader, getFiles) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_files");

}

/**
 * Register classes and their locations
 */
PHP_METHOD(Phalcon_Loader, registerClasses) {

	zend_bool merge, _0;
	zval *classes_param = NULL, *merge_param = NULL, _1, _2$$3, _3$$3;
	zval classes;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&classes);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &classes_param, &merge_param);

	ZEPHIR_OBS_VAR_ONCE(&classes);
	ZVAL_COPY(&classes, classes_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	_0 = merge;
	if (_0) {
		ZEPHIR_OBS_VAR(&_1);
		zephir_read_property(&_1, this_ptr, SL("_classes"), PH_NOISY_CC);
		_0 = Z_TYPE_P(&_1) == IS_ARRAY;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_read_property(&_3$$3, this_ptr, SL("_classes"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_2$$3, &_3$$3, &classes TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_classes"), &_2$$3);
	} else {
		zephir_update_property_zval(this_ptr, SL("_classes"), &classes);
	}
	RETURN_THIS();

}

/**
 * Returns the class-map currently registered in the autoloader
 */
PHP_METHOD(Phalcon_Loader, getClasses) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_classes");

}

/**
 * Register the autoload method
 */
PHP_METHOD(Phalcon_Loader, register) {

	zval _1$$3;
	zval __$true, __$false, eventsManager, _0, _2$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_registered"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		ZEPHIR_OBS_VAR(&eventsManager);
		zephir_read_property(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadfiles", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_1$$3, this_ptr);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "autoLoad");
		zephir_array_fast_append(&_1$$3, &_2$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 295, &_1$$3);
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
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

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
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_unregister", NULL, 296, &_1$$3);
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

	zval filePath, _0, _1$$3, *_2$$3, _3$$4, _6$$4, _4$$5, _5$$5, _8$$6, _9$$7, _10$$7;
	zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_files"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		zephir_read_property(&_1$$3, this_ptr, SL("_files"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_1$$3, 0, "phalcon/loader.zep", 290);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1$$3), _2$$3)
		{
			ZEPHIR_INIT_NVAR(&filePath);
			ZVAL_COPY(&filePath, _2$$3);
			ZEPHIR_OBS_NVAR(&_3$$4);
			zephir_read_property(&_3$$4, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
			if (Z_TYPE_P(&_3$$4) == IS_OBJECT) {
				zephir_update_property_zval(this_ptr, SL("_checkedPath"), &filePath);
				zephir_read_property(&_4$$5, this_ptr, SL("_eventsManager"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZVAL_STRING(&_5$$5, "loader:beforeCheckPath");
				ZEPHIR_CALL_METHOD(NULL, &_4$$5, "fire", NULL, 0, &_5$$5, this_ptr, &filePath);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_FUNCTION(&_6$$4, "is_file", &_7, 297, &filePath);
			zephir_check_call_status();
			if (zephir_is_true(&_6$$4)) {
				ZEPHIR_OBS_NVAR(&_8$$6);
				zephir_read_property(&_8$$6, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
				if (Z_TYPE_P(&_8$$6) == IS_OBJECT) {
					zephir_update_property_zval(this_ptr, SL("_foundPath"), &filePath);
					zephir_read_property(&_9$$7, this_ptr, SL("_eventsManager"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_10$$7);
					ZVAL_STRING(&_10$$7, "loader:pathFound");
					ZEPHIR_CALL_METHOD(NULL, &_9$$7, "fire", NULL, 0, &_10$$7, this_ptr, &filePath);
					zephir_check_call_status();
				}
				if (zephir_require_zval(&filePath TSRMLS_CC) == FAILURE) {
					RETURN_MM_NULL();
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&filePath);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Autoloads the registered classes
 */
PHP_METHOD(Phalcon_Loader, autoLoad) {

	zend_string *_4$$7;
	zend_ulong _3$$7;
	zephir_fcall_cache_entry *_12 = NULL, *_14 = NULL, *_16 = NULL, *_22 = NULL, *_25 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, eventsManager, classes, extensions, filePath, ds, fixedDirectory, directories, ns, namespaces, nsPrefix, directory, fileName, extension, nsClassName, _17, _0$$3, _1$$6, *_2$$7, _5$$8, _6$$8, _7$$8, *_8$$8, _9$$11, *_10$$11, _11$$13, _13$$12, _15$$15, *_18$$16, _19$$17, *_20$$17, _21$$19, _23$$18, _24$$21, _26$$22;
	zval className;
	ZEPHIR_INIT_THIS();

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
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_19$$17);
	ZVAL_UNDEF(&_21$$19);
	ZVAL_UNDEF(&_23$$18);
	ZVAL_UNDEF(&_24$$21);
	ZVAL_UNDEF(&_26$$22);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	if (unlikely(Z_TYPE_P(className_param) != IS_STRING && Z_TYPE_P(className_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'className' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(className_param) == IS_STRING)) {
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
	if (Z_TYPE_P(&classes) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&filePath);
		if (zephir_array_isset_fetch(&filePath, &classes, &className, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				zephir_update_property_zval(this_ptr, SL("_foundPath"), &filePath);
				ZEPHIR_INIT_VAR(&_1$$6);
				ZVAL_STRING(&_1$$6, "loader:pathFound");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_1$$6, this_ptr, &filePath);
				zephir_check_call_status();
			}
			if (zephir_require_zval(&filePath TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
			RETURN_MM_BOOL(1);
		}
	}
	ZEPHIR_OBS_VAR(&extensions);
	zephir_read_property(&extensions, this_ptr, SL("_extensions"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&ds);
	ZVAL_STRING(&ds, "/");
	ZEPHIR_INIT_VAR(&ns);
	ZVAL_STRING(&ns, "\\");
	ZEPHIR_OBS_VAR(&namespaces);
	zephir_read_property(&namespaces, this_ptr, SL("_namespaces"), PH_NOISY_CC);
	if (Z_TYPE_P(&namespaces) == IS_ARRAY) {
		zephir_is_iterable(&namespaces, 0, "phalcon/loader.zep", 393);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&namespaces), _3$$7, _4$$7, _2$$7)
		{
			ZEPHIR_INIT_NVAR(&nsPrefix);
			if (_4$$7 != NULL) { 
				ZVAL_STR_COPY(&nsPrefix, _4$$7);
			} else {
				ZVAL_LONG(&nsPrefix, _3$$7);
			}
			ZEPHIR_INIT_NVAR(&directories);
			ZVAL_COPY(&directories, _2$$7);
			if (!(zephir_start_with(&className, &nsPrefix, NULL))) {
				continue;
			}
			ZEPHIR_INIT_LNVAR(_5$$8);
			ZEPHIR_CONCAT_VV(&_5$$8, &nsPrefix, &ns);
			ZVAL_LONG(&_6$$8, zephir_fast_strlen_ev(&_5$$8));
			ZEPHIR_INIT_NVAR(&fileName);
			zephir_substr(&fileName, &className, zephir_get_intval(&_6$$8), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_INIT_NVAR(&_7$$8);
			zephir_fast_str_replace(&_7$$8, &ns, &ds, &fileName TSRMLS_CC);
			ZEPHIR_CPY_WRT(&fileName, &_7$$8);
			if (!(zephir_is_true(&fileName))) {
				continue;
			}
			zephir_is_iterable(&directories, 0, "phalcon/loader.zep", 392);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&directories), _8$$8)
			{
				ZEPHIR_INIT_NVAR(&directory);
				ZVAL_COPY(&directory, _8$$8);
				ZEPHIR_INIT_NVAR(&_9$$11);
				zephir_fast_trim(&_9$$11, &directory, &ds, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&fixedDirectory);
				ZEPHIR_CONCAT_VV(&fixedDirectory, &_9$$11, &ds);
				zephir_is_iterable(&extensions, 0, "phalcon/loader.zep", 391);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extensions), _10$$11)
				{
					ZEPHIR_INIT_NVAR(&extension);
					ZVAL_COPY(&extension, _10$$11);
					ZEPHIR_INIT_NVAR(&filePath);
					ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &fileName, ".", &extension);
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						zephir_update_property_zval(this_ptr, SL("_checkedPath"), &filePath);
						ZEPHIR_INIT_NVAR(&_11$$13);
						ZVAL_STRING(&_11$$13, "loader:beforeCheckPath");
						ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_12, 0, &_11$$13, this_ptr);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_FUNCTION(&_13$$12, "is_file", &_14, 297, &filePath);
					zephir_check_call_status();
					if (zephir_is_true(&_13$$12)) {
						if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
							zephir_update_property_zval(this_ptr, SL("_foundPath"), &filePath);
							ZEPHIR_INIT_NVAR(&_15$$15);
							ZVAL_STRING(&_15$$15, "loader:pathFound");
							ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_16, 0, &_15$$15, this_ptr, &filePath);
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
	}
	ZEPHIR_INIT_VAR(&_17);
	ZVAL_STRING(&_17, "\\");
	ZEPHIR_INIT_VAR(&nsClassName);
	zephir_fast_str_replace(&nsClassName, &_17, &ds, &className TSRMLS_CC);
	ZEPHIR_OBS_NVAR(&directories);
	zephir_read_property(&directories, this_ptr, SL("_directories"), PH_NOISY_CC);
	if (Z_TYPE_P(&directories) == IS_ARRAY) {
		zephir_is_iterable(&directories, 0, "phalcon/loader.zep", 450);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&directories), _18$$16)
		{
			ZEPHIR_INIT_NVAR(&directory);
			ZVAL_COPY(&directory, _18$$16);
			ZEPHIR_INIT_NVAR(&_19$$17);
			zephir_fast_trim(&_19$$17, &directory, &ds, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&fixedDirectory);
			ZEPHIR_CONCAT_VV(&fixedDirectory, &_19$$17, &ds);
			zephir_is_iterable(&extensions, 0, "phalcon/loader.zep", 449);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extensions), _20$$17)
			{
				ZEPHIR_INIT_NVAR(&extension);
				ZVAL_COPY(&extension, _20$$17);
				ZEPHIR_INIT_NVAR(&filePath);
				ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &nsClassName, ".", &extension);
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					zephir_update_property_zval(this_ptr, SL("_checkedPath"), &filePath);
					ZEPHIR_INIT_NVAR(&_21$$19);
					ZVAL_STRING(&_21$$19, "loader:beforeCheckPath");
					ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_22, 0, &_21$$19, this_ptr, &filePath);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_FUNCTION(&_23$$18, "is_file", &_14, 297, &filePath);
				zephir_check_call_status();
				if (zephir_is_true(&_23$$18)) {
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						zephir_update_property_zval(this_ptr, SL("_foundPath"), &filePath);
						ZEPHIR_INIT_NVAR(&_24$$21);
						ZVAL_STRING(&_24$$21, "loader:pathFound");
						ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_25, 0, &_24$$21, this_ptr, &filePath);
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
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_26$$22);
		ZVAL_STRING(&_26$$22, "loader:afterCheckClass");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_26$$22, this_ptr, &className);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Get the path when a class was found
 */
PHP_METHOD(Phalcon_Loader, getFoundPath) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_foundPath");

}

/**
 * Get the path the loader is checking for a path
 */
PHP_METHOD(Phalcon_Loader, getCheckedPath) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_checkedPath");

}

zend_object *zephir_init_properties_Phalcon_Loader(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0, _2$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_extensions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "php");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			zephir_update_property_zval(this_ptr, SL("_extensions"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

