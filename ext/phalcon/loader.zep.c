
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
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

	zend_declare_property_string(phalcon_loader_ce, SL("fileCheckingCallback"), "is_file", ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_loader_ce->create_object = zephir_init_properties_Phalcon_Loader;

	zend_class_implements(phalcon_loader_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

/**
 * Sets the file check callback.
 *
 * <code>
 * // Default behavior.
 * $loader->setFileCheckingCallback("is_file");
 *
 * // Faster than `is_file()`, but implies some issues if
 * // the file is removed from the filesystem.
 * $loader->setFileCheckingCallback("stream_resolve_include_path");
 *
 * // Do not check file existence.
 * $loader->setFileCheckingCallback(null);
 * </code>
 */
PHP_METHOD(Phalcon_Loader, setFileCheckingCallback) {

	zval *callback = NULL, *_0$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &callback);

	if (!callback) {
		callback = ZEPHIR_GLOBAL(global_null);
	}


	if (EXPECTED(zephir_is_callable(callback TSRMLS_CC))) {
		zephir_update_property_this(getThis(), SL("fileCheckingCallback"), callback TSRMLS_CC);
	} else if (Z_TYPE_P(callback) == IS_NULL) {
		ZEPHIR_INIT_VAR(_0$$4);
		ZEPHIR_INIT_NVAR(_0$$4);
		zephir_create_closure_ex(_0$$4, NULL, phalcon_0__closure_ce, SS("__invoke") TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("fileCheckingCallback"), _0$$4 TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_loader_exception_ce, "The 'callback' parameter must be either a callable or NULL.", "phalcon/loader.zep", 100);
		return;
	}
	RETURN_THIS();

}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Loader, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_this(getThis(), SL("_eventsManager"), eventsManager TSRMLS_CC);

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Loader, getEventsManager) {

	

	RETURN_MEMBER(getThis(), "_eventsManager");

}

/**
 * Sets an array of file extensions that the loader must try in each attempt to locate the file
 */
PHP_METHOD(Phalcon_Loader, setExtensions) {

	zval *extensions_param = NULL;
	zval *extensions = NULL;

	zephir_fetch_params(0, 1, 0, &extensions_param);

	extensions = extensions_param;


	zephir_update_property_this(getThis(), SL("_extensions"), extensions TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the file extensions registered in the loader
 */
PHP_METHOD(Phalcon_Loader, getExtensions) {

	

	RETURN_MEMBER(getThis(), "_extensions");

}

/**
 * Register namespaces and their related directories
 */
PHP_METHOD(Phalcon_Loader, registerNamespaces) {

	HashTable *_1$$3;
	HashPosition _0$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge;
	zval *namespaces_param = NULL, *merge_param = NULL, *preparedNamespaces = NULL, *name = NULL, *paths = NULL, **_2$$3, *_3$$4, *_5$$4 = NULL, *_6$$4, *_7$$4, *_4$$5 = NULL;
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
	if (merge) {
		zephir_is_iterable(preparedNamespaces, &_1$$3, &_0$$3, 0, 0, "phalcon/loader.zep", 156);
		for (
		  ; zend_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HMKEY(name, _1$$3, _0$$3);
			ZEPHIR_GET_HVALUE(paths, _2$$3);
			_3$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_namespaces"), PH_NOISY_CC);
			if (!(zephir_array_isset(_3$$4, name))) {
				ZEPHIR_INIT_NVAR(_4$$5);
				array_init(_4$$5);
				zephir_update_property_array(this_ptr, SL("_namespaces"), name, _4$$5 TSRMLS_CC);
			}
			ZEPHIR_INIT_NVAR(_5$$4);
			_6$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_namespaces"), PH_NOISY_CC);
			zephir_array_fetch(&_7$$4, _6$$4, name, PH_NOISY | PH_READONLY, "phalcon/loader.zep", 154 TSRMLS_CC);
			zephir_fast_array_merge(_5$$4, &(_7$$4), &(paths) TSRMLS_CC);
			zephir_update_property_array(this_ptr, SL("_namespaces"), name, _5$$4 TSRMLS_CC);
		}
	} else {
		zephir_update_property_this(getThis(), SL("_namespaces"), preparedNamespaces TSRMLS_CC);
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
	zephir_is_iterable(namespace, &_1, &_0, 0, 0, "phalcon/loader.zep", 178);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
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

	

	RETURN_MEMBER(getThis(), "_namespaces");

}

/**
 * Register directories in which "not found" classes could be found
 */
PHP_METHOD(Phalcon_Loader, registerDirs) {

	zend_bool merge;
	zval *directories_param = NULL, *merge_param = NULL, *_0$$3, *_1$$3;
	zval *directories = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &directories_param, &merge_param);

	directories = directories_param;
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_INIT_VAR(_0$$3);
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_directories"), PH_NOISY_CC);
		zephir_fast_array_merge(_0$$3, &(_1$$3), &(directories) TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_directories"), _0$$3 TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_directories"), directories TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Returns the directories currently registered in the autoloader
 */
PHP_METHOD(Phalcon_Loader, getDirs) {

	

	RETURN_MEMBER(getThis(), "_directories");

}

/**
 * Registers files that are "non-classes" hence need a "require". This is very useful for including files that only
 * have functions
 */
PHP_METHOD(Phalcon_Loader, registerFiles) {

	zend_bool merge;
	zval *files_param = NULL, *merge_param = NULL, *_0$$3, *_1$$3;
	zval *files = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &files_param, &merge_param);

	files = files_param;
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_INIT_VAR(_0$$3);
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_files"), PH_NOISY_CC);
		zephir_fast_array_merge(_0$$3, &(_1$$3), &(files) TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_files"), _0$$3 TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_files"), files TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Returns the files currently registered in the autoloader
 */
PHP_METHOD(Phalcon_Loader, getFiles) {

	

	RETURN_MEMBER(getThis(), "_files");

}

/**
 * Register classes and their locations
 */
PHP_METHOD(Phalcon_Loader, registerClasses) {

	zend_bool merge;
	zval *classes_param = NULL, *merge_param = NULL, *_0$$3, *_1$$3;
	zval *classes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &classes_param, &merge_param);

	classes = classes_param;
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_INIT_VAR(_0$$3);
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_classes"), PH_NOISY_CC);
		zephir_fast_array_merge(_0$$3, &(_1$$3), &(classes) TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_classes"), _0$$3 TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_classes"), classes TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Returns the class-map currently registered in the autoloader
 */
PHP_METHOD(Phalcon_Loader, getClasses) {

	

	RETURN_MEMBER(getThis(), "_classes");

}

/**
 * Register the autoload method
 */
PHP_METHOD(Phalcon_Loader, register) {

	zval *_1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prepend_param = NULL, *_0, *_2$$3, _3$$3;
	zend_bool prepend;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prepend_param);

	if (!prepend_param) {
		prepend = 0;
	} else {
		prepend = zephir_get_boolval(prepend_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_registered"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadfiles", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_create_array(_1$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_1$$3, this_ptr);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "autoLoad", 1);
		zephir_array_fast_append(_1$$3, _2$$3);
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_BOOL(&_3$$3, (prepend ? 1 : 0));
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 309, _1$$3, ZEPHIR_GLOBAL(global_true), &_3$$3);
		zephir_check_call_status();
		if (1) {
			zephir_update_property_this(getThis(), SL("_registered"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_registered"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
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
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_registered"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE_IDENTICAL(_0)) {
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_create_array(_1$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_1$$3, this_ptr);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "autoLoad", 1);
		zephir_array_fast_append(_1$$3, _2$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_unregister", NULL, 310, _1$$3);
		zephir_check_call_status();
		if (0) {
			zephir_update_property_this(getThis(), SL("_registered"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_registered"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

/**
 * Checks if a file exists and then adds the file by doing virtual require
 */
PHP_METHOD(Phalcon_Loader, loadFiles) {

	HashTable *_2;
	HashPosition _1;
	zval *filePath = NULL, *fileCheckingCallback = NULL, *_0, **_3, *_4$$3 = NULL, *_7$$3 = NULL, *_5$$4, *_6$$4 = NULL, *_9$$5 = NULL, *_10$$6, *_11$$6 = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("fileCheckingCallback"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(fileCheckingCallback, _0);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_files"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/loader.zep", 323);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(filePath, _3);
		ZEPHIR_OBS_NVAR(_4$$3);
		zephir_read_property_this(&_4$$3, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
		if (Z_TYPE_P(_4$$3) == IS_OBJECT) {
			zephir_update_property_this(getThis(), SL("_checkedPath"), filePath TSRMLS_CC);
			_5$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_6$$4);
			ZVAL_STRING(_6$$4, "loader:beforeCheckPath", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _5$$4, "fire", NULL, 0, _6$$4, this_ptr, filePath);
			zephir_check_temp_parameter(_6$$4);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_FUNCTION(&_7$$3, "call_user_func", &_8, 311, fileCheckingCallback, filePath);
		zephir_check_call_status();
		if (zephir_is_true(_7$$3)) {
			ZEPHIR_OBS_NVAR(_9$$5);
			zephir_read_property_this(&_9$$5, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
			if (Z_TYPE_P(_9$$5) == IS_OBJECT) {
				zephir_update_property_this(getThis(), SL("_foundPath"), filePath TSRMLS_CC);
				_10$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_11$$6);
				ZVAL_STRING(_11$$6, "loader:pathFound", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _10$$6, "fire", NULL, 0, _11$$6, this_ptr, filePath);
				zephir_check_temp_parameter(_11$$6);
				zephir_check_call_status();
			}
			if (zephir_require_zval(filePath TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Autoloads the registered classes
 */
PHP_METHOD(Phalcon_Loader, autoLoad) {

	HashTable *_4, *_23, *_10$$6, *_14$$9, *_27$$14;
	HashPosition _3, _22, _9$$6, _13$$9, _26$$14;
	zephir_fcall_cache_entry *_17 = NULL, *_19 = NULL, *_21 = NULL, *_30 = NULL, *_33 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *eventsManager = NULL, *classes = NULL, *extensions = NULL, *filePath = NULL, *ds = NULL, *fixedDirectory = NULL, *directories = NULL, *ns = NULL, *namespaces = NULL, *nsPrefix = NULL, *directory = NULL, *fileName = NULL, *extension = NULL, *nsClassName = NULL, *fileCheckingCallback = NULL, *_2, **_5, **_24, *_0$$3, *_1$$5, *_6$$6 = NULL, _7$$6 = zval_used_for_init, *_8$$6 = NULL, **_11$$6, *_12$$9 = NULL, **_15$$9, *_16$$11 = NULL, *_18$$10 = NULL, *_20$$13 = NULL, *_25$$14 = NULL, **_28$$14, *_29$$16 = NULL, *_31$$15 = NULL, *_32$$18 = NULL, *_34$$19;
	zval *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	if (UNEXPECTED(Z_TYPE_P(className_param) != IS_STRING && Z_TYPE_P(className_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'className' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(className_param) == IS_STRING)) {
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
	ZEPHIR_OBS_VAR(filePath);
	if (zephir_array_isset_fetch(&filePath, classes, className, 0 TSRMLS_CC)) {
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			zephir_update_property_this(getThis(), SL("_foundPath"), filePath TSRMLS_CC);
			ZEPHIR_INIT_VAR(_1$$5);
			ZVAL_STRING(_1$$5, "loader:pathFound", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _1$$5, this_ptr, filePath);
			zephir_check_temp_parameter(_1$$5);
			zephir_check_call_status();
		}
		if (zephir_require_zval(filePath TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_OBS_VAR(extensions);
	zephir_read_property_this(&extensions, this_ptr, SL("_extensions"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(ds);
	ZVAL_STRING(ds, "/", 1);
	ZEPHIR_INIT_VAR(ns);
	ZVAL_STRING(ns, "\\", 1);
	ZEPHIR_OBS_VAR(namespaces);
	zephir_read_property_this(&namespaces, this_ptr, SL("_namespaces"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("fileCheckingCallback"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(fileCheckingCallback, _2);
	zephir_is_iterable(namespaces, &_4, &_3, 0, 0, "phalcon/loader.zep", 429);
	for (
	  ; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zend_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(nsPrefix, _4, _3);
		ZEPHIR_GET_HVALUE(directories, _5);
		if (!(zephir_start_with(className, nsPrefix, NULL))) {
			continue;
		}
		ZEPHIR_INIT_LNVAR(_6$$6);
		ZEPHIR_CONCAT_VV(_6$$6, nsPrefix, ns);
		ZEPHIR_SINIT_NVAR(_7$$6);
		ZVAL_LONG(&_7$$6, zephir_fast_strlen_ev(_6$$6));
		ZEPHIR_INIT_NVAR(fileName);
		zephir_substr(fileName, className, zephir_get_intval(&_7$$6), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		if (!(zephir_is_true(fileName))) {
			continue;
		}
		ZEPHIR_INIT_NVAR(_8$$6);
		zephir_fast_str_replace(&_8$$6, ns, ds, fileName TSRMLS_CC);
		ZEPHIR_CPY_WRT(fileName, _8$$6);
		zephir_is_iterable(directories, &_10$$6, &_9$$6, 0, 0, "phalcon/loader.zep", 424);
		for (
		  ; zend_hash_get_current_data_ex(_10$$6, (void**) &_11$$6, &_9$$6) == SUCCESS
		  ; zend_hash_move_forward_ex(_10$$6, &_9$$6)
		) {
			ZEPHIR_GET_HVALUE(directory, _11$$6);
			ZEPHIR_INIT_NVAR(_12$$9);
			zephir_fast_trim(_12$$9, directory, ds, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
			ZEPHIR_INIT_NVAR(fixedDirectory);
			ZEPHIR_CONCAT_VV(fixedDirectory, _12$$9, ds);
			zephir_is_iterable(extensions, &_14$$9, &_13$$9, 0, 0, "phalcon/loader.zep", 423);
			for (
			  ; zend_hash_get_current_data_ex(_14$$9, (void**) &_15$$9, &_13$$9) == SUCCESS
			  ; zend_hash_move_forward_ex(_14$$9, &_13$$9)
			) {
				ZEPHIR_GET_HVALUE(extension, _15$$9);
				ZEPHIR_INIT_NVAR(filePath);
				ZEPHIR_CONCAT_VVSV(filePath, fixedDirectory, fileName, ".", extension);
				if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
					zephir_update_property_this(getThis(), SL("_checkedPath"), filePath TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_16$$11);
					ZVAL_STRING(_16$$11, "loader:beforeCheckPath", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_17, 0, _16$$11, this_ptr);
					zephir_check_temp_parameter(_16$$11);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_FUNCTION(&_18$$10, "call_user_func", &_19, 311, fileCheckingCallback, filePath);
				zephir_check_call_status();
				if (zephir_is_true(_18$$10)) {
					if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
						zephir_update_property_this(getThis(), SL("_foundPath"), filePath TSRMLS_CC);
						ZEPHIR_INIT_NVAR(_20$$13);
						ZVAL_STRING(_20$$13, "loader:pathFound", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_21, 0, _20$$13, this_ptr, filePath);
						zephir_check_temp_parameter(_20$$13);
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
	ZEPHIR_INIT_VAR(nsClassName);
	zephir_fast_str_replace(&nsClassName, ns, ds, className TSRMLS_CC);
	ZEPHIR_OBS_NVAR(directories);
	zephir_read_property_this(&directories, this_ptr, SL("_directories"), PH_NOISY_CC);
	zephir_is_iterable(directories, &_23, &_22, 0, 0, "phalcon/loader.zep", 484);
	for (
	  ; zend_hash_get_current_data_ex(_23, (void**) &_24, &_22) == SUCCESS
	  ; zend_hash_move_forward_ex(_23, &_22)
	) {
		ZEPHIR_GET_HVALUE(directory, _24);
		ZEPHIR_INIT_NVAR(_25$$14);
		zephir_fast_trim(_25$$14, directory, ds, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		ZEPHIR_INIT_NVAR(fixedDirectory);
		ZEPHIR_CONCAT_VV(fixedDirectory, _25$$14, ds);
		zephir_is_iterable(extensions, &_27$$14, &_26$$14, 0, 0, "phalcon/loader.zep", 479);
		for (
		  ; zend_hash_get_current_data_ex(_27$$14, (void**) &_28$$14, &_26$$14) == SUCCESS
		  ; zend_hash_move_forward_ex(_27$$14, &_26$$14)
		) {
			ZEPHIR_GET_HVALUE(extension, _28$$14);
			ZEPHIR_INIT_NVAR(filePath);
			ZEPHIR_CONCAT_VVSV(filePath, fixedDirectory, nsClassName, ".", extension);
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				zephir_update_property_this(getThis(), SL("_checkedPath"), filePath TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_29$$16);
				ZVAL_STRING(_29$$16, "loader:beforeCheckPath", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_30, 0, _29$$16, this_ptr, filePath);
				zephir_check_temp_parameter(_29$$16);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_FUNCTION(&_31$$15, "call_user_func", &_19, 311, fileCheckingCallback, filePath);
			zephir_check_call_status();
			if (zephir_is_true(_31$$15)) {
				if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
					zephir_update_property_this(getThis(), SL("_foundPath"), filePath TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_32$$18);
					ZVAL_STRING(_32$$18, "loader:pathFound", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_33, 0, _32$$18, this_ptr, filePath);
					zephir_check_temp_parameter(_32$$18);
					zephir_check_call_status();
				}
				if (zephir_require_zval(filePath TSRMLS_CC) == FAILURE) {
					RETURN_MM_NULL();
				}
				RETURN_MM_BOOL(1);
			}
		}
	}
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_34$$19);
		ZVAL_STRING(_34$$19, "loader:afterCheckClass", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _34$$19, this_ptr, className);
		zephir_check_temp_parameter(_34$$19);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Get the path when a class was found
 */
PHP_METHOD(Phalcon_Loader, getFoundPath) {

	

	RETURN_MEMBER(getThis(), "_foundPath");

}

/**
 * Get the path the loader is checking for a path
 */
PHP_METHOD(Phalcon_Loader, getCheckedPath) {

	

	RETURN_MEMBER(getThis(), "_checkedPath");

}

zend_object_value zephir_init_properties_Phalcon_Loader(zend_class_entry *class_type TSRMLS_DC) {

		zval *_7$$6;
	zval *_0, *_2, *_4, *_6, *_9, *_1$$3, *_3$$4, *_5$$5, *_8$$6, *_10$$7;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_files"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("_files"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_directories"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(getThis(), SL("_directories"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_namespaces"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			array_init(_5$$5);
			zephir_update_property_this(getThis(), SL("_namespaces"), _5$$5 TSRMLS_CC);
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_extensions"), PH_NOISY_CC);
		if (Z_TYPE_P(_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(_7$$6);
			zephir_create_array(_7$$6, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_8$$6);
			ZVAL_STRING(_8$$6, "php", 1);
			zephir_array_fast_append(_7$$6, _8$$6);
			zephir_update_property_this(getThis(), SL("_extensions"), _7$$6 TSRMLS_CC);
		}
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_classes"), PH_NOISY_CC);
		if (Z_TYPE_P(_9) == IS_NULL) {
			ZEPHIR_INIT_VAR(_10$$7);
			array_init(_10$$7);
			zephir_update_property_this(getThis(), SL("_classes"), _10$$7 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

