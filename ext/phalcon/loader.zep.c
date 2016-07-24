
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

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_this(this_ptr, SL("_eventsManager"), eventsManager TSRMLS_CC);

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Loader, getEventsManager) {

	

	RETURN_MEMBER(this_ptr, "_eventsManager");

}

/**
 * Sets an array of file extensions that the loader must try in each attempt to locate the file
 */
PHP_METHOD(Phalcon_Loader, setExtensions) {

	zval *extensions_param = NULL;
	zval *extensions = NULL;

	zephir_fetch_params(0, 1, 0, &extensions_param);

	extensions = extensions_param;


	zephir_update_property_this(this_ptr, SL("_extensions"), extensions TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the file extensions registered in the loader
 */
PHP_METHOD(Phalcon_Loader, getExtensions) {

	

	RETURN_MEMBER(this_ptr, "_extensions");

}

/**
 * Register namespaces and their related directories
 */
PHP_METHOD(Phalcon_Loader, registerNamespaces) {

	HashTable *_3$$3;
	HashPosition _2$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge, _0;
	zval *namespaces_param = NULL, *merge_param = NULL, *preparedNamespaces = NULL, *name = NULL, *paths = NULL, *_1, **_4$$3, *_5$$4, *_7$$4 = NULL, *_8$$4, *_9$$4, *_6$$5 = NULL;
	zval *namespaces = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &namespaces_param, &merge_param);

	namespaces = namespaces_param;
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	ZEPHIR_CALL_METHOD(&preparedNamespaces, this_ptr, "preparenamespace", NULL, 0, namespaces);
	zephir_check_call_status();
	_0 = merge;
	if (_0) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_this(&_1, this_ptr, SL("_namespaces"), PH_NOISY_CC);
		_0 = Z_TYPE_P(_1) == IS_ARRAY;
	}
	if (_0) {
		zephir_is_iterable(preparedNamespaces, &_3$$3, &_2$$3, 0, 0, "phalcon/loader.zep", 119);
		for (
		  ; zephir_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HMKEY(name, _3$$3, _2$$3);
			ZEPHIR_GET_HVALUE(paths, _4$$3);
			_5$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_namespaces"), PH_NOISY_CC);
			if (!(zephir_array_isset(_5$$4, name))) {
				ZEPHIR_INIT_NVAR(_6$$5);
				array_init(_6$$5);
				zephir_update_property_array(this_ptr, SL("_namespaces"), name, _6$$5 TSRMLS_CC);
			}
			ZEPHIR_INIT_NVAR(_7$$4);
			_8$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_namespaces"), PH_NOISY_CC);
			zephir_array_fetch(&_9$$4, _8$$4, name, PH_NOISY | PH_READONLY, "phalcon/loader.zep", 117 TSRMLS_CC);
			zephir_fast_array_merge(_7$$4, &(_9$$4), &(paths) TSRMLS_CC);
			zephir_update_property_array(this_ptr, SL("_namespaces"), name, _7$$4 TSRMLS_CC);
		}
	} else {
		zephir_update_property_this(this_ptr, SL("_namespaces"), preparedNamespaces TSRMLS_CC);
	}
	RETURN_THIS();

}

PHP_METHOD(Phalcon_Loader, prepareNamespace) {

	HashTable *_1;
	HashPosition _0;
	zval *namespace_param = NULL, *localPaths = NULL, *name = NULL, *paths = NULL, *prepared = NULL, **_2;
	zval *namespace = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespace_param);

	namespace = namespace_param;


	ZEPHIR_INIT_VAR(prepared);
	array_init(prepared);
	zephir_is_iterable(namespace, &_1, &_0, 0, 0, "phalcon/loader.zep", 141);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(name, _1, _0);
		ZEPHIR_GET_HVALUE(paths, _2);
		if (Z_TYPE_P(paths) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(localPaths);
			zephir_create_array(localPaths, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(localPaths, paths);
		} else {
			ZEPHIR_CPY_WRT(localPaths, paths);
		}
		zephir_array_update_zval(&prepared, name, &localPaths, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(prepared);

}

/**
 * Returns the namespaces currently registered in the autoloader
 */
PHP_METHOD(Phalcon_Loader, getNamespaces) {

	

	RETURN_MEMBER(this_ptr, "_namespaces");

}

/**
 * Register directories in which "not found" classes could be found
 */
PHP_METHOD(Phalcon_Loader, registerDirs) {

	zend_bool merge, _0;
	zval *directories_param = NULL, *merge_param = NULL, *_1, *_2$$3, *_3$$3;
	zval *directories = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &directories_param, &merge_param);

	directories = directories_param;
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	_0 = merge;
	if (_0) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_this(&_1, this_ptr, SL("_directories"), PH_NOISY_CC);
		_0 = Z_TYPE_P(_1) == IS_ARRAY;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_2$$3);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_directories"), PH_NOISY_CC);
		zephir_fast_array_merge(_2$$3, &(_3$$3), &(directories) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_directories"), _2$$3 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_directories"), directories TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Returns the directories currently registered in the autoloader
 */
PHP_METHOD(Phalcon_Loader, getDirs) {

	

	RETURN_MEMBER(this_ptr, "_directories");

}

/**
 * Registers files that are "non-classes" hence need a "require". This is very useful for including files that only
 * have functions
 */
PHP_METHOD(Phalcon_Loader, registerFiles) {

	zend_bool merge, _0;
	zval *files_param = NULL, *merge_param = NULL, *_1, *_2$$3, *_3$$3;
	zval *files = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &files_param, &merge_param);

	files = files_param;
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	_0 = merge;
	if (_0) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_this(&_1, this_ptr, SL("_files"), PH_NOISY_CC);
		_0 = Z_TYPE_P(_1) == IS_ARRAY;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_2$$3);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_files"), PH_NOISY_CC);
		zephir_fast_array_merge(_2$$3, &(_3$$3), &(files) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_files"), _2$$3 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_files"), files TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Returns the files currently registered in the autoloader
 */
PHP_METHOD(Phalcon_Loader, getFiles) {

	

	RETURN_MEMBER(this_ptr, "_files");

}

/**
 * Register classes and their locations
 */
PHP_METHOD(Phalcon_Loader, registerClasses) {

	zend_bool merge, _0;
	zval *classes_param = NULL, *merge_param = NULL, *_1, *_2$$3, *_3$$3;
	zval *classes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &classes_param, &merge_param);

	classes = classes_param;
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	_0 = merge;
	if (_0) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_this(&_1, this_ptr, SL("_classes"), PH_NOISY_CC);
		_0 = Z_TYPE_P(_1) == IS_ARRAY;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_2$$3);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_classes"), PH_NOISY_CC);
		zephir_fast_array_merge(_2$$3, &(_3$$3), &(classes) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_classes"), _2$$3 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_classes"), classes TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Returns the class-map currently registered in the autoloader
 */
PHP_METHOD(Phalcon_Loader, getClasses) {

	

	RETURN_MEMBER(this_ptr, "_classes");

}

/**
 * Register the autoload method
 */
PHP_METHOD(Phalcon_Loader, register) {

	zval *_1$$3;
	zval *eventsManager = NULL, *_0, *_2$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_registered"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_OBS_VAR(eventsManager);
		zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadfiles", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_create_array(_1$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_1$$3, this_ptr);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "autoLoad", 1);
		zephir_array_fast_append(_1$$3, _2$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 293, _1$$3);
		zephir_check_call_status();
		if (1) {
			zephir_update_property_this(this_ptr, SL("_registered"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("_registered"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

/**
 * Unregister the autoload method
 */
PHP_METHOD(Phalcon_Loader, unregister) {

	zval *_1$$3;
	zval *_0, *_2$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_registered"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE_IDENTICAL(_0)) {
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_create_array(_1$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_1$$3, this_ptr);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "autoLoad", 1);
		zephir_array_fast_append(_1$$3, _2$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_unregister", NULL, 294, _1$$3);
		zephir_check_call_status();
		if (0) {
			zephir_update_property_this(this_ptr, SL("_registered"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("_registered"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

/**
 * Checks if a file exists and then adds the file by doing virtual require
 */
PHP_METHOD(Phalcon_Loader, loadFiles) {

	HashTable *_3$$3;
	HashPosition _2$$3;
	zval *filePath = NULL, *_0, *_1$$3, **_4$$3, *_5$$4 = NULL, *_8$$4 = NULL, *_6$$5, *_7$$5 = NULL, *_10$$6 = NULL, *_11$$7, *_12$$7 = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_files"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_files"), PH_NOISY_CC);
		zephir_is_iterable(_1$$3, &_3$$3, &_2$$3, 0, 0, "phalcon/loader.zep", 290);
		for (
		  ; zephir_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HVALUE(filePath, _4$$3);
			ZEPHIR_OBS_NVAR(_5$$4);
			zephir_read_property_this(&_5$$4, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
			if (Z_TYPE_P(_5$$4) == IS_OBJECT) {
				zephir_update_property_this(this_ptr, SL("_checkedPath"), filePath TSRMLS_CC);
				_6$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_7$$5);
				ZVAL_STRING(_7$$5, "loader:beforeCheckPath", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _6$$5, "fire", NULL, 0, _7$$5, this_ptr, filePath);
				zephir_check_temp_parameter(_7$$5);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_FUNCTION(&_8$$4, "is_file", &_9, 295, filePath);
			zephir_check_call_status();
			if (zephir_is_true(_8$$4)) {
				ZEPHIR_OBS_NVAR(_10$$6);
				zephir_read_property_this(&_10$$6, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
				if (Z_TYPE_P(_10$$6) == IS_OBJECT) {
					zephir_update_property_this(this_ptr, SL("_foundPath"), filePath TSRMLS_CC);
					_11$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
					ZEPHIR_INIT_NVAR(_12$$7);
					ZVAL_STRING(_12$$7, "loader:pathFound", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(NULL, _11$$7, "fire", NULL, 0, _12$$7, this_ptr, filePath);
					zephir_check_temp_parameter(_12$$7);
					zephir_check_call_status();
				}
				if (zephir_require_zval(filePath TSRMLS_CC) == FAILURE) {
					RETURN_MM_NULL();
				}
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Autoloads the registered classes
 */
PHP_METHOD(Phalcon_Loader, autoLoad) {

	HashTable *_3$$7, *_9$$8, *_13$$11, *_23$$16, *_27$$17;
	HashPosition _2$$7, _8$$8, _12$$11, _22$$16, _26$$17;
	zephir_fcall_cache_entry *_16 = NULL, *_18 = NULL, *_20 = NULL, *_30 = NULL, *_33 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *eventsManager = NULL, *classes = NULL, *extensions = NULL, *filePath = NULL, *ds = NULL, *fixedDirectory = NULL, *directories = NULL, *ns = NULL, *namespaces = NULL, *nsPrefix = NULL, *directory = NULL, *fileName = NULL, *extension = NULL, *nsClassName = NULL, _21, *_0$$3, *_1$$6, **_4$$7, *_5$$8 = NULL, _6$$8 = zval_used_for_init, *_7$$8 = NULL, **_10$$8, *_11$$11 = NULL, **_14$$11, *_15$$13 = NULL, *_17$$12 = NULL, *_19$$15 = NULL, **_24$$16, *_25$$17 = NULL, **_28$$17, *_29$$19 = NULL, *_31$$18 = NULL, *_32$$21 = NULL, *_34$$22;
	zval *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	if (unlikely(Z_TYPE_P(className_param) != IS_STRING && Z_TYPE_P(className_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'className' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(className_param) == IS_STRING)) {
		zephir_get_strval(className, className_param);
	} else {
		ZEPHIR_INIT_VAR(className);
		ZVAL_EMPTY_STRING(className);
	}


	ZEPHIR_OBS_VAR(eventsManager);
	zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "loader:beforeCheckClass", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _0$$3, this_ptr, className);
		zephir_check_temp_parameter(_0$$3);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(classes);
	zephir_read_property_this(&classes, this_ptr, SL("_classes"), PH_NOISY_CC);
	if (Z_TYPE_P(classes) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(filePath);
		if (zephir_array_isset_fetch(&filePath, classes, className, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				zephir_update_property_this(this_ptr, SL("_foundPath"), filePath TSRMLS_CC);
				ZEPHIR_INIT_VAR(_1$$6);
				ZVAL_STRING(_1$$6, "loader:pathFound", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _1$$6, this_ptr, filePath);
				zephir_check_temp_parameter(_1$$6);
				zephir_check_call_status();
			}
			if (zephir_require_zval(filePath TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
			RETURN_MM_BOOL(1);
		}
	}
	ZEPHIR_OBS_VAR(extensions);
	zephir_read_property_this(&extensions, this_ptr, SL("_extensions"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(ds);
	ZVAL_STRING(ds, "/", 1);
	ZEPHIR_INIT_VAR(ns);
	ZVAL_STRING(ns, "\\", 1);
	ZEPHIR_OBS_VAR(namespaces);
	zephir_read_property_this(&namespaces, this_ptr, SL("_namespaces"), PH_NOISY_CC);
	if (Z_TYPE_P(namespaces) == IS_ARRAY) {
		zephir_is_iterable(namespaces, &_3$$7, &_2$$7, 0, 0, "phalcon/loader.zep", 393);
		for (
		  ; zephir_hash_get_current_data_ex(_3$$7, (void**) &_4$$7, &_2$$7) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3$$7, &_2$$7)
		) {
			ZEPHIR_GET_HMKEY(nsPrefix, _3$$7, _2$$7);
			ZEPHIR_GET_HVALUE(directories, _4$$7);
			if (!(zephir_start_with(className, nsPrefix, NULL))) {
				continue;
			}
			ZEPHIR_INIT_LNVAR(_5$$8);
			ZEPHIR_CONCAT_VV(_5$$8, nsPrefix, ns);
			ZEPHIR_SINIT_NVAR(_6$$8);
			ZVAL_LONG(&_6$$8, zephir_fast_strlen_ev(_5$$8));
			ZEPHIR_INIT_NVAR(fileName);
			zephir_substr(fileName, className, zephir_get_intval(&_6$$8), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_INIT_NVAR(_7$$8);
			zephir_fast_str_replace(&_7$$8, ns, ds, fileName TSRMLS_CC);
			ZEPHIR_CPY_WRT(fileName, _7$$8);
			if (!(zephir_is_true(fileName))) {
				continue;
			}
			zephir_is_iterable(directories, &_9$$8, &_8$$8, 0, 0, "phalcon/loader.zep", 392);
			for (
			  ; zephir_hash_get_current_data_ex(_9$$8, (void**) &_10$$8, &_8$$8) == SUCCESS
			  ; zephir_hash_move_forward_ex(_9$$8, &_8$$8)
			) {
				ZEPHIR_GET_HVALUE(directory, _10$$8);
				ZEPHIR_INIT_NVAR(_11$$11);
				zephir_fast_trim(_11$$11, directory, ds, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
				ZEPHIR_INIT_NVAR(fixedDirectory);
				ZEPHIR_CONCAT_VV(fixedDirectory, _11$$11, ds);
				zephir_is_iterable(extensions, &_13$$11, &_12$$11, 0, 0, "phalcon/loader.zep", 391);
				for (
				  ; zephir_hash_get_current_data_ex(_13$$11, (void**) &_14$$11, &_12$$11) == SUCCESS
				  ; zephir_hash_move_forward_ex(_13$$11, &_12$$11)
				) {
					ZEPHIR_GET_HVALUE(extension, _14$$11);
					ZEPHIR_INIT_NVAR(filePath);
					ZEPHIR_CONCAT_VVSV(filePath, fixedDirectory, fileName, ".", extension);
					if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
						zephir_update_property_this(this_ptr, SL("_checkedPath"), filePath TSRMLS_CC);
						ZEPHIR_INIT_NVAR(_15$$13);
						ZVAL_STRING(_15$$13, "loader:beforeCheckPath", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_16, 0, _15$$13, this_ptr);
						zephir_check_temp_parameter(_15$$13);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_FUNCTION(&_17$$12, "is_file", &_18, 295, filePath);
					zephir_check_call_status();
					if (zephir_is_true(_17$$12)) {
						if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
							zephir_update_property_this(this_ptr, SL("_foundPath"), filePath TSRMLS_CC);
							ZEPHIR_INIT_NVAR(_19$$15);
							ZVAL_STRING(_19$$15, "loader:pathFound", ZEPHIR_TEMP_PARAM_COPY);
							ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_20, 0, _19$$15, this_ptr, filePath);
							zephir_check_temp_parameter(_19$$15);
							zephir_check_call_status();
						}
						if (zephir_require_zval(filePath TSRMLS_CC) == FAILURE) {
							RETURN_MM_NULL();
						}
						RETURN_MM_BOOL(1);
					}
				}
			}
		}
	}
	ZEPHIR_SINIT_VAR(_21);
	ZVAL_STRING(&_21, "\\", 0);
	ZEPHIR_INIT_VAR(nsClassName);
	zephir_fast_str_replace(&nsClassName, &_21, ds, className TSRMLS_CC);
	ZEPHIR_OBS_NVAR(directories);
	zephir_read_property_this(&directories, this_ptr, SL("_directories"), PH_NOISY_CC);
	if (Z_TYPE_P(directories) == IS_ARRAY) {
		zephir_is_iterable(directories, &_23$$16, &_22$$16, 0, 0, "phalcon/loader.zep", 450);
		for (
		  ; zephir_hash_get_current_data_ex(_23$$16, (void**) &_24$$16, &_22$$16) == SUCCESS
		  ; zephir_hash_move_forward_ex(_23$$16, &_22$$16)
		) {
			ZEPHIR_GET_HVALUE(directory, _24$$16);
			ZEPHIR_INIT_NVAR(_25$$17);
			zephir_fast_trim(_25$$17, directory, ds, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
			ZEPHIR_INIT_NVAR(fixedDirectory);
			ZEPHIR_CONCAT_VV(fixedDirectory, _25$$17, ds);
			zephir_is_iterable(extensions, &_27$$17, &_26$$17, 0, 0, "phalcon/loader.zep", 449);
			for (
			  ; zephir_hash_get_current_data_ex(_27$$17, (void**) &_28$$17, &_26$$17) == SUCCESS
			  ; zephir_hash_move_forward_ex(_27$$17, &_26$$17)
			) {
				ZEPHIR_GET_HVALUE(extension, _28$$17);
				ZEPHIR_INIT_NVAR(filePath);
				ZEPHIR_CONCAT_VVSV(filePath, fixedDirectory, nsClassName, ".", extension);
				if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
					zephir_update_property_this(this_ptr, SL("_checkedPath"), filePath TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_29$$19);
					ZVAL_STRING(_29$$19, "loader:beforeCheckPath", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_30, 0, _29$$19, this_ptr, filePath);
					zephir_check_temp_parameter(_29$$19);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_FUNCTION(&_31$$18, "is_file", &_18, 295, filePath);
				zephir_check_call_status();
				if (zephir_is_true(_31$$18)) {
					if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
						zephir_update_property_this(this_ptr, SL("_foundPath"), filePath TSRMLS_CC);
						ZEPHIR_INIT_NVAR(_32$$21);
						ZVAL_STRING(_32$$21, "loader:pathFound", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_33, 0, _32$$21, this_ptr, filePath);
						zephir_check_temp_parameter(_32$$21);
						zephir_check_call_status();
					}
					if (zephir_require_zval(filePath TSRMLS_CC) == FAILURE) {
						RETURN_MM_NULL();
					}
					RETURN_MM_BOOL(1);
				}
			}
		}
	}
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_34$$22);
		ZVAL_STRING(_34$$22, "loader:afterCheckClass", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _34$$22, this_ptr, className);
		zephir_check_temp_parameter(_34$$22);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Get the path when a class was found
 */
PHP_METHOD(Phalcon_Loader, getFoundPath) {

	

	RETURN_MEMBER(this_ptr, "_foundPath");

}

/**
 * Get the path the loader is checking for a path
 */
PHP_METHOD(Phalcon_Loader, getCheckedPath) {

	

	RETURN_MEMBER(this_ptr, "_checkedPath");

}

zend_object_value zephir_init_properties_Phalcon_Loader(zend_class_entry *class_type TSRMLS_DC) {

		zval *_1$$3;
	zval *_0, *_2$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_extensions"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			zephir_create_array(_1$$3, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_2$$3);
			ZVAL_STRING(_2$$3, "php", 1);
			zephir_array_fast_append(_1$$3, _2$$3);
			zephir_update_property_this(this_ptr, SL("_extensions"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

