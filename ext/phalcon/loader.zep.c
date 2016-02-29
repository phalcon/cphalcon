
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
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

	zend_declare_property_bool(phalcon_loader_ce, SL("_registered"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_loader_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Loader constructor
 */
PHP_METHOD(Phalcon_Loader, __construct) {

	zval *_1;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "php", 1);
	zephir_array_fast_append(_0, _1);
	zephir_update_property_this(this_ptr, SL("_extensions"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

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

	HashTable *_1$$4;
	HashPosition _0$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge;
	zval *namespaces_param = NULL, *merge_param = NULL, *currentNamespaces = NULL, *preparedNamespaces = NULL, *name = NULL, *paths = NULL, **_2$$4, *_3$$6 = NULL, *_4$$5 = NULL, *_5$$5;
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
		ZEPHIR_OBS_VAR(currentNamespaces);
		zephir_read_property_this(&currentNamespaces, this_ptr, SL("_namespaces"), PH_NOISY_CC);
		if (Z_TYPE_P(currentNamespaces) == IS_ARRAY) {
			zephir_is_iterable(preparedNamespaces, &_1$$4, &_0$$4, 0, 0, "phalcon/loader.zep", 128);
			for (
			  ; zephir_hash_get_current_data_ex(_1$$4, (void**) &_2$$4, &_0$$4) == SUCCESS
			  ; zephir_hash_move_forward_ex(_1$$4, &_0$$4)
			) {
				ZEPHIR_GET_HMKEY(name, _1$$4, _0$$4);
				ZEPHIR_GET_HVALUE(paths, _2$$4);
				if (!(zephir_array_isset(currentNamespaces, name))) {
					ZEPHIR_INIT_NVAR(_3$$6);
					array_init(_3$$6);
					zephir_array_update_zval(&currentNamespaces, name, &_3$$6, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_INIT_NVAR(_4$$5);
				zephir_array_fetch(&_5$$5, currentNamespaces, name, PH_NOISY | PH_READONLY, "phalcon/loader.zep", 125 TSRMLS_CC);
				zephir_fast_array_merge(_4$$5, &(_5$$5), &(paths) TSRMLS_CC);
				zephir_array_update_zval(&currentNamespaces, name, &_4$$5, PH_COPY | PH_SEPARATE);
			}
			zephir_update_property_this(this_ptr, SL("_namespaces"), currentNamespaces TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("_namespaces"), preparedNamespaces TSRMLS_CC);
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
	zephir_is_iterable(namespace, &_1, &_0, 0, 0, "phalcon/loader.zep", 154);
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

	zend_bool merge;
	zval *directories_param = NULL, *merge_param = NULL, *currentDirectories = NULL, *mergedDirectories = NULL;
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
		ZEPHIR_OBS_VAR(currentDirectories);
		zephir_read_property_this(&currentDirectories, this_ptr, SL("_directories"), PH_NOISY_CC);
		if (Z_TYPE_P(currentDirectories) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedDirectories);
			zephir_fast_array_merge(mergedDirectories, &(currentDirectories), &(directories) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedDirectories, directories);
		}
		zephir_update_property_this(this_ptr, SL("_directories"), mergedDirectories TSRMLS_CC);
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
 * Register classes and their locations
 */
PHP_METHOD(Phalcon_Loader, registerClasses) {

	zend_bool merge;
	zval *classes_param = NULL, *merge_param = NULL, *mergedClasses = NULL, *currentClasses = NULL;
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
		ZEPHIR_OBS_VAR(currentClasses);
		zephir_read_property_this(&currentClasses, this_ptr, SL("_classes"), PH_NOISY_CC);
		if (Z_TYPE_P(currentClasses) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedClasses);
			zephir_fast_array_merge(mergedClasses, &(currentClasses), &(classes) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedClasses, classes);
		}
		zephir_update_property_this(this_ptr, SL("_classes"), mergedClasses TSRMLS_CC);
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
	zval *_0, *_2$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_registered"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_create_array(_1$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_1$$3, this_ptr);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "autoLoad", 1);
		zephir_array_fast_append(_1$$3, _2$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 284, _1$$3);
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
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_unregister", NULL, 285, _1$$3);
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
 * Autoloads the registered classes
 */
PHP_METHOD(Phalcon_Loader, autoLoad) {

	HashTable *_3$$7, *_9$$10, *_13$$11, *_23$$16, *_27$$17;
	HashPosition _2$$7, _8$$10, _12$$11, _22$$16, _26$$17;
	zephir_fcall_cache_entry *_16 = NULL, *_18 = NULL, *_20 = NULL, *_30 = NULL, *_33 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *eventsManager = NULL, *classes = NULL, *extensions = NULL, *filePath = NULL, *ds = NULL, *fixedDirectory = NULL, *directories = NULL, *ns = NULL, *namespaces = NULL, *nsPrefix = NULL, *directory = NULL, *fileName = NULL, *extension = NULL, *nsClassName = NULL, _21, *_0$$3, *_1$$6, **_4$$7, *_5$$9 = NULL, _6$$9 = zval_used_for_init, *_7$$9 = NULL, **_10$$10, *_11$$11 = NULL, **_14$$11, *_15$$13 = NULL, *_17$$12 = NULL, *_19$$15 = NULL, **_24$$16, *_25$$17 = NULL, **_28$$17, *_29$$19 = NULL, *_31$$18 = NULL, *_32$$21 = NULL, *_34$$22;
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
		zephir_is_iterable(namespaces, &_3$$7, &_2$$7, 0, 0, "phalcon/loader.zep", 345);
		for (
		  ; zephir_hash_get_current_data_ex(_3$$7, (void**) &_4$$7, &_2$$7) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3$$7, &_2$$7)
		) {
			ZEPHIR_GET_HMKEY(nsPrefix, _3$$7, _2$$7);
			ZEPHIR_GET_HVALUE(directories, _4$$7);
			if (zephir_start_with(className, nsPrefix, NULL)) {
				ZEPHIR_INIT_LNVAR(_5$$9);
				ZEPHIR_CONCAT_VV(_5$$9, nsPrefix, ns);
				ZEPHIR_SINIT_NVAR(_6$$9);
				ZVAL_LONG(&_6$$9, zephir_fast_strlen_ev(_5$$9));
				ZEPHIR_INIT_NVAR(fileName);
				zephir_substr(fileName, className, zephir_get_intval(&_6$$9), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_INIT_NVAR(_7$$9);
				zephir_fast_str_replace(&_7$$9, ns, ds, fileName TSRMLS_CC);
				ZEPHIR_CPY_WRT(fileName, _7$$9);
				if (zephir_is_true(fileName)) {
					zephir_is_iterable(directories, &_9$$10, &_8$$10, 0, 0, "phalcon/loader.zep", 342);
					for (
					  ; zephir_hash_get_current_data_ex(_9$$10, (void**) &_10$$10, &_8$$10) == SUCCESS
					  ; zephir_hash_move_forward_ex(_9$$10, &_8$$10)
					) {
						ZEPHIR_GET_HVALUE(directory, _10$$10);
						ZEPHIR_INIT_NVAR(_11$$11);
						zephir_fast_trim(_11$$11, directory, ds, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
						ZEPHIR_INIT_NVAR(fixedDirectory);
						ZEPHIR_CONCAT_VV(fixedDirectory, _11$$11, ds);
						zephir_is_iterable(extensions, &_13$$11, &_12$$11, 0, 0, "phalcon/loader.zep", 341);
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
							ZEPHIR_CALL_FUNCTION(&_17$$12, "is_file", &_18, 286, filePath);
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
		}
	}
	ZEPHIR_SINIT_VAR(_21);
	ZVAL_STRING(&_21, "\\", 0);
	ZEPHIR_INIT_VAR(nsClassName);
	zephir_fast_str_replace(&nsClassName, &_21, ds, className TSRMLS_CC);
	ZEPHIR_OBS_NVAR(directories);
	zephir_read_property_this(&directories, this_ptr, SL("_directories"), PH_NOISY_CC);
	if (Z_TYPE_P(directories) == IS_ARRAY) {
		zephir_is_iterable(directories, &_23$$16, &_22$$16, 0, 0, "phalcon/loader.zep", 402);
		for (
		  ; zephir_hash_get_current_data_ex(_23$$16, (void**) &_24$$16, &_22$$16) == SUCCESS
		  ; zephir_hash_move_forward_ex(_23$$16, &_22$$16)
		) {
			ZEPHIR_GET_HVALUE(directory, _24$$16);
			ZEPHIR_INIT_NVAR(_25$$17);
			zephir_fast_trim(_25$$17, directory, ds, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
			ZEPHIR_INIT_NVAR(fixedDirectory);
			ZEPHIR_CONCAT_VV(fixedDirectory, _25$$17, ds);
			zephir_is_iterable(extensions, &_27$$17, &_26$$17, 0, 0, "phalcon/loader.zep", 401);
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
				ZEPHIR_CALL_FUNCTION(&_31$$18, "is_file", &_18, 286, filePath);
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

