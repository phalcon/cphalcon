
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/hash.h"
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

	zend_declare_property_null(phalcon_loader_ce, SL("_prefixes"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

	zend_bool merge;
	zval *namespaces_param = NULL, *merge_param = NULL, *currentNamespaces = NULL, *mergedNamespaces = NULL;
	zval *namespaces = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &namespaces_param, &merge_param);

	namespaces = namespaces_param;
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_OBS_VAR(currentNamespaces);
		zephir_read_property_this(&currentNamespaces, this_ptr, SL("_namespaces"), PH_NOISY_CC);
		if (Z_TYPE_P(currentNamespaces) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedNamespaces);
			zephir_fast_array_merge(mergedNamespaces, &(currentNamespaces), &(namespaces) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedNamespaces, namespaces);
		}
		zephir_update_property_this(this_ptr, SL("_namespaces"), mergedNamespaces TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_namespaces"), namespaces TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Returns the namespaces currently registered in the autoloader
 */
PHP_METHOD(Phalcon_Loader, getNamespaces) {

	

	RETURN_MEMBER(this_ptr, "_namespaces");

}

/**
 * Register directories in which "not found" classes could be found
 * @deprecated From Phalcon 2.1.0 version has been removed support for prefixes strategy
 */
PHP_METHOD(Phalcon_Loader, registerPrefixes) {

	zend_bool merge;
	zval *prefixes_param = NULL, *merge_param = NULL, *currentPrefixes = NULL, *mergedPrefixes = NULL;
	zval *prefixes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &prefixes_param, &merge_param);

	prefixes = prefixes_param;
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_OBS_VAR(currentPrefixes);
		zephir_read_property_this(&currentPrefixes, this_ptr, SL("_prefixes"), PH_NOISY_CC);
		if (Z_TYPE_P(currentPrefixes) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedPrefixes);
			zephir_fast_array_merge(mergedPrefixes, &(currentPrefixes), &(prefixes) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedPrefixes, prefixes);
		}
		zephir_update_property_this(this_ptr, SL("_prefixes"), mergedPrefixes TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_prefixes"), prefixes TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Returns the prefixes currently registered in the autoloader
 * @deprecated From Phalcon 2.1.0 version has been removed support for prefixes strategy
 */
PHP_METHOD(Phalcon_Loader, getPrefixes) {

	

	RETURN_MEMBER(this_ptr, "_prefixes");

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
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 282, _1$$3);
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
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_unregister", NULL, 283, _1$$3);
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

	HashTable *_3$$7, *_10$$10, *_19$$15, *_29$$18, *_39$$23, *_43$$24;
	HashPosition _2$$7, _9$$10, _18$$15, _28$$18, _38$$23, _42$$24;
	zephir_fcall_cache_entry *_13 = NULL, *_15 = NULL, *_17 = NULL, *_32 = NULL, *_35 = NULL, *_46 = NULL, *_49 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *eventsManager = NULL, *classes = NULL, *extensions = NULL, *filePath = NULL, *ds = NULL, *fixedDirectory = NULL, *prefixes = NULL, *directories = NULL, *namespaceSeparator = NULL, *namespaces = NULL, *nsPrefix = NULL, *directory = NULL, *fileName = NULL, *extension = NULL, *prefix = NULL, *dsClassName = NULL, *nsClassName = NULL, _36, _37, *_0$$3, *_1$$6, **_4$$7, *_5$$9 = NULL, _6$$9 = zval_used_for_init, *_7$$9 = NULL, *_8$$10 = NULL, **_11$$10, *_12$$12 = NULL, *_14$$11 = NULL, *_16$$14 = NULL, **_20$$15, *_21$$17 = NULL, _22$$17 = zval_used_for_init, *_23$$17 = NULL, *_24$$17 = NULL, _25$$17 = zval_used_for_init, _26$$17 = zval_used_for_init, *_27$$18 = NULL, **_30$$18, *_31$$20 = NULL, *_33$$19 = NULL, *_34$$22 = NULL, **_40$$23, *_41$$24 = NULL, **_44$$24, *_45$$26 = NULL, *_47$$25 = NULL, *_48$$28 = NULL, *_50$$29;
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
	ZEPHIR_INIT_VAR(namespaceSeparator);
	ZVAL_STRING(namespaceSeparator, "\\", 1);
	ZEPHIR_OBS_VAR(namespaces);
	zephir_read_property_this(&namespaces, this_ptr, SL("_namespaces"), PH_NOISY_CC);
	if (Z_TYPE_P(namespaces) == IS_ARRAY) {
		zephir_is_iterable(namespaces, &_3$$7, &_2$$7, 0, 0, "phalcon/loader.zep", 349);
		for (
		  ; zephir_hash_get_current_data_ex(_3$$7, (void**) &_4$$7, &_2$$7) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3$$7, &_2$$7)
		) {
			ZEPHIR_GET_HMKEY(nsPrefix, _3$$7, _2$$7);
			ZEPHIR_GET_HVALUE(directory, _4$$7);
			if (zephir_start_with(className, nsPrefix, NULL)) {
				ZEPHIR_INIT_LNVAR(_5$$9);
				ZEPHIR_CONCAT_VV(_5$$9, nsPrefix, namespaceSeparator);
				ZEPHIR_SINIT_NVAR(_6$$9);
				ZVAL_LONG(&_6$$9, zephir_fast_strlen_ev(_5$$9));
				ZEPHIR_INIT_NVAR(fileName);
				zephir_substr(fileName, className, zephir_get_intval(&_6$$9), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_INIT_NVAR(_7$$9);
				zephir_fast_str_replace(&_7$$9, namespaceSeparator, ds, fileName TSRMLS_CC);
				ZEPHIR_CPY_WRT(fileName, _7$$9);
				if (zephir_is_true(fileName)) {
					ZEPHIR_INIT_NVAR(_8$$10);
					zephir_fast_trim(_8$$10, directory, ds, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
					ZEPHIR_INIT_NVAR(fixedDirectory);
					ZEPHIR_CONCAT_VV(fixedDirectory, _8$$10, ds);
					zephir_is_iterable(extensions, &_10$$10, &_9$$10, 0, 0, "phalcon/loader.zep", 346);
					for (
					  ; zephir_hash_get_current_data_ex(_10$$10, (void**) &_11$$10, &_9$$10) == SUCCESS
					  ; zephir_hash_move_forward_ex(_10$$10, &_9$$10)
					) {
						ZEPHIR_GET_HVALUE(extension, _11$$10);
						ZEPHIR_INIT_NVAR(filePath);
						ZEPHIR_CONCAT_VVSV(filePath, fixedDirectory, fileName, ".", extension);
						if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
							zephir_update_property_this(this_ptr, SL("_checkedPath"), filePath TSRMLS_CC);
							ZEPHIR_INIT_NVAR(_12$$12);
							ZVAL_STRING(_12$$12, "loader:beforeCheckPath", ZEPHIR_TEMP_PARAM_COPY);
							ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_13, 0, _12$$12, this_ptr);
							zephir_check_temp_parameter(_12$$12);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_FUNCTION(&_14$$11, "is_file", &_15, 284, filePath);
						zephir_check_call_status();
						if (zephir_is_true(_14$$11)) {
							if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
								zephir_update_property_this(this_ptr, SL("_foundPath"), filePath TSRMLS_CC);
								ZEPHIR_INIT_NVAR(_16$$14);
								ZVAL_STRING(_16$$14, "loader:pathFound", ZEPHIR_TEMP_PARAM_COPY);
								ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_17, 0, _16$$14, this_ptr, filePath);
								zephir_check_temp_parameter(_16$$14);
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
	ZEPHIR_OBS_VAR(prefixes);
	zephir_read_property_this(&prefixes, this_ptr, SL("_prefixes"), PH_NOISY_CC);
	if (Z_TYPE_P(prefixes) == IS_ARRAY) {
		zephir_is_iterable(prefixes, &_19$$15, &_18$$15, 0, 0, "phalcon/loader.zep", 404);
		for (
		  ; zephir_hash_get_current_data_ex(_19$$15, (void**) &_20$$15, &_18$$15) == SUCCESS
		  ; zephir_hash_move_forward_ex(_19$$15, &_18$$15)
		) {
			ZEPHIR_GET_HMKEY(prefix, _19$$15, _18$$15);
			ZEPHIR_GET_HVALUE(directory, _20$$15);
			if (zephir_start_with(className, prefix, NULL)) {
				ZEPHIR_INIT_LNVAR(_21$$17);
				ZEPHIR_CONCAT_VV(_21$$17, prefix, namespaceSeparator);
				ZEPHIR_SINIT_NVAR(_22$$17);
				ZVAL_STRING(&_22$$17, "", 0);
				ZEPHIR_INIT_NVAR(fileName);
				zephir_fast_str_replace(&fileName, _21$$17, &_22$$17, className TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_23$$17);
				ZEPHIR_INIT_LNVAR(_24$$17);
				ZEPHIR_CONCAT_VS(_24$$17, prefix, "_");
				ZEPHIR_SINIT_NVAR(_25$$17);
				ZVAL_STRING(&_25$$17, "", 0);
				zephir_fast_str_replace(&_23$$17, _24$$17, &_25$$17, fileName TSRMLS_CC);
				ZEPHIR_CPY_WRT(fileName, _23$$17);
				ZEPHIR_INIT_NVAR(_23$$17);
				ZEPHIR_SINIT_NVAR(_26$$17);
				ZVAL_STRING(&_26$$17, "_", 0);
				zephir_fast_str_replace(&_23$$17, &_26$$17, ds, fileName TSRMLS_CC);
				ZEPHIR_CPY_WRT(fileName, _23$$17);
				if (zephir_is_true(fileName)) {
					ZEPHIR_INIT_NVAR(_27$$18);
					zephir_fast_trim(_27$$18, directory, ds, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
					ZEPHIR_INIT_NVAR(fixedDirectory);
					ZEPHIR_CONCAT_VV(fixedDirectory, _27$$18, ds);
					zephir_is_iterable(extensions, &_29$$18, &_28$$18, 0, 0, "phalcon/loader.zep", 401);
					for (
					  ; zephir_hash_get_current_data_ex(_29$$18, (void**) &_30$$18, &_28$$18) == SUCCESS
					  ; zephir_hash_move_forward_ex(_29$$18, &_28$$18)
					) {
						ZEPHIR_GET_HVALUE(extension, _30$$18);
						ZEPHIR_INIT_NVAR(filePath);
						ZEPHIR_CONCAT_VVSV(filePath, fixedDirectory, fileName, ".", extension);
						if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
							zephir_update_property_this(this_ptr, SL("_checkedPath"), filePath TSRMLS_CC);
							ZEPHIR_INIT_NVAR(_31$$20);
							ZVAL_STRING(_31$$20, "loader:beforeCheckPath", ZEPHIR_TEMP_PARAM_COPY);
							ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_32, 0, _31$$20, this_ptr, filePath);
							zephir_check_temp_parameter(_31$$20);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_FUNCTION(&_33$$19, "is_file", &_15, 284, filePath);
						zephir_check_call_status();
						if (zephir_is_true(_33$$19)) {
							if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
								zephir_update_property_this(this_ptr, SL("_foundPath"), filePath TSRMLS_CC);
								ZEPHIR_INIT_NVAR(_34$$22);
								ZVAL_STRING(_34$$22, "loader:pathFound", ZEPHIR_TEMP_PARAM_COPY);
								ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_35, 0, _34$$22, this_ptr, filePath);
								zephir_check_temp_parameter(_34$$22);
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
	ZEPHIR_SINIT_VAR(_36);
	ZVAL_STRING(&_36, "_", 0);
	ZEPHIR_INIT_VAR(dsClassName);
	zephir_fast_str_replace(&dsClassName, &_36, ds, className TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_37);
	ZVAL_STRING(&_37, "\\", 0);
	ZEPHIR_INIT_VAR(nsClassName);
	zephir_fast_str_replace(&nsClassName, &_37, ds, dsClassName TSRMLS_CC);
	ZEPHIR_OBS_VAR(directories);
	zephir_read_property_this(&directories, this_ptr, SL("_directories"), PH_NOISY_CC);
	if (Z_TYPE_P(directories) == IS_ARRAY) {
		zephir_is_iterable(directories, &_39$$23, &_38$$23, 0, 0, "phalcon/loader.zep", 466);
		for (
		  ; zephir_hash_get_current_data_ex(_39$$23, (void**) &_40$$23, &_38$$23) == SUCCESS
		  ; zephir_hash_move_forward_ex(_39$$23, &_38$$23)
		) {
			ZEPHIR_GET_HVALUE(directory, _40$$23);
			ZEPHIR_INIT_NVAR(_41$$24);
			zephir_fast_trim(_41$$24, directory, ds, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
			ZEPHIR_INIT_NVAR(fixedDirectory);
			ZEPHIR_CONCAT_VV(fixedDirectory, _41$$24, ds);
			zephir_is_iterable(extensions, &_43$$24, &_42$$24, 0, 0, "phalcon/loader.zep", 465);
			for (
			  ; zephir_hash_get_current_data_ex(_43$$24, (void**) &_44$$24, &_42$$24) == SUCCESS
			  ; zephir_hash_move_forward_ex(_43$$24, &_42$$24)
			) {
				ZEPHIR_GET_HVALUE(extension, _44$$24);
				ZEPHIR_INIT_NVAR(filePath);
				ZEPHIR_CONCAT_VVSV(filePath, fixedDirectory, nsClassName, ".", extension);
				if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
					zephir_update_property_this(this_ptr, SL("_checkedPath"), filePath TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_45$$26);
					ZVAL_STRING(_45$$26, "loader:beforeCheckPath", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_46, 0, _45$$26, this_ptr, filePath);
					zephir_check_temp_parameter(_45$$26);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_FUNCTION(&_47$$25, "is_file", &_15, 284, filePath);
				zephir_check_call_status();
				if (zephir_is_true(_47$$25)) {
					if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
						zephir_update_property_this(this_ptr, SL("_foundPath"), filePath TSRMLS_CC);
						ZEPHIR_INIT_NVAR(_48$$28);
						ZVAL_STRING(_48$$28, "loader:pathFound", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_49, 0, _48$$28, this_ptr, filePath);
						zephir_check_temp_parameter(_48$$28);
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
		ZEPHIR_INIT_VAR(_50$$29);
		ZVAL_STRING(_50$$29, "loader:afterCheckClass", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _50$$29, this_ptr, className);
		zephir_check_temp_parameter(_50$$29);
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

