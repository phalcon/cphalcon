
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
	zval *namespaces_param = NULL, *merge_param = NULL, *currentNamespaces, *mergedNamespaces = NULL;
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
 */
PHP_METHOD(Phalcon_Loader, registerPrefixes) {

	zend_bool merge;
	zval *prefixes_param = NULL, *merge_param = NULL, *currentPrefixes, *mergedPrefixes = NULL;
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
 */
PHP_METHOD(Phalcon_Loader, getPrefixes) {


	RETURN_MEMBER(this_ptr, "_prefixes");

}

/**
 * Register directories in which "not found" classes could be found
 */
PHP_METHOD(Phalcon_Loader, registerDirs) {

	zend_bool merge;
	zval *directories_param = NULL, *merge_param = NULL, *currentDirectories, *mergedDirectories = NULL;
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
	zval *classes_param = NULL, *merge_param = NULL, *mergedClasses = NULL, *currentClasses;
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *_0, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_registered"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_INIT_VAR(_1);
		zephir_create_array(_1, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_1, this_ptr);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "autoLoad", 1);
		zephir_array_fast_append(_1, _2);
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 277, _1);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_registered"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Unregister the autoload method
 */
PHP_METHOD(Phalcon_Loader, unregister) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *_0, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_registered"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE_IDENTICAL(_0)) {
		ZEPHIR_INIT_VAR(_1);
		zephir_create_array(_1, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_1, this_ptr);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "autoLoad", 1);
		zephir_array_fast_append(_1, _2);
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_unregister", NULL, 278, _1);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_registered"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Autoloads the registered classes
 */
PHP_METHOD(Phalcon_Loader, autoLoad) {

	zephir_fcall_cache_entry *_10 = NULL, *_12 = NULL, *_13 = NULL, *_23 = NULL, *_24 = NULL, *_31 = NULL, *_32 = NULL;
	HashTable *_2, *_7, *_15, *_21, *_26, *_29;
	HashPosition _1, _6, _14, _20, _25, _28;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *eventsManager, *classes, *extensions, *filePath = NULL, *ds, *fixedDirectory = NULL, *prefixes, *directories, *namespaceSeparator, *namespaces, *nsPrefix = NULL, *directory = NULL, *fileName = NULL, *extension = NULL, *prefix = NULL, *dsClassName, *nsClassName, *_0 = NULL, **_3, *_4 = NULL, _5 = zval_used_for_init, **_8, *_9 = NULL, *_11 = NULL, **_16, *_17 = NULL, _18 = zval_used_for_init, _19 = zval_used_for_init, **_22, **_27, **_30;
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
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "loader:beforeCheckClass", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _0, this_ptr, className);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(classes);
	zephir_read_property_this(&classes, this_ptr, SL("_classes"), PH_NOISY_CC);
	if (Z_TYPE_P(classes) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(filePath);
		if (zephir_array_isset_fetch(&filePath, classes, className, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				zephir_update_property_this(this_ptr, SL("_foundPath"), filePath TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_0);
				ZVAL_STRING(_0, "loader:pathFound", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _0, this_ptr, filePath);
				zephir_check_temp_parameter(_0);
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
		zephir_is_iterable(namespaces, &_2, &_1, 0, 0, "phalcon/loader.zep", 347);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HMKEY(nsPrefix, _2, _1);
			ZEPHIR_GET_HVALUE(directory, _3);
			if (zephir_start_with(className, nsPrefix, NULL)) {
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_VV(_4, nsPrefix, namespaceSeparator);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_LONG(&_5, zephir_fast_strlen_ev(_4));
				ZEPHIR_INIT_NVAR(fileName);
				zephir_substr(fileName, className, zephir_get_intval(&_5), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_INIT_NVAR(_0);
				zephir_fast_str_replace(&_0, namespaceSeparator, ds, fileName TSRMLS_CC);
				ZEPHIR_CPY_WRT(fileName, _0);
				if (zephir_is_true(fileName)) {
					ZEPHIR_INIT_NVAR(_0);
					zephir_fast_trim(_0, directory, ds, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
					ZEPHIR_INIT_NVAR(fixedDirectory);
					ZEPHIR_CONCAT_VV(fixedDirectory, _0, ds);
					zephir_is_iterable(extensions, &_7, &_6, 0, 0, "phalcon/loader.zep", 344);
					for (
					  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
					  ; zephir_hash_move_forward_ex(_7, &_6)
					) {
						ZEPHIR_GET_HVALUE(extension, _8);
						ZEPHIR_INIT_NVAR(filePath);
						ZEPHIR_CONCAT_VVSV(filePath, fixedDirectory, fileName, ".", extension);
						if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
							zephir_update_property_this(this_ptr, SL("_checkedPath"), filePath TSRMLS_CC);
							ZEPHIR_INIT_NVAR(_9);
							ZVAL_STRING(_9, "loader:beforeCheckPath", ZEPHIR_TEMP_PARAM_COPY);
							ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_10, 0, _9, this_ptr);
							zephir_check_temp_parameter(_9);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_FUNCTION(&_11, "is_file", &_12, 279, filePath);
						zephir_check_call_status();
						if (zephir_is_true(_11)) {
							if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
								zephir_update_property_this(this_ptr, SL("_foundPath"), filePath TSRMLS_CC);
								ZEPHIR_INIT_NVAR(_9);
								ZVAL_STRING(_9, "loader:pathFound", ZEPHIR_TEMP_PARAM_COPY);
								ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_13, 0, _9, this_ptr, filePath);
								zephir_check_temp_parameter(_9);
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
		zephir_is_iterable(prefixes, &_15, &_14, 0, 0, "phalcon/loader.zep", 402);
		for (
		  ; zephir_hash_get_current_data_ex(_15, (void**) &_16, &_14) == SUCCESS
		  ; zephir_hash_move_forward_ex(_15, &_14)
		) {
			ZEPHIR_GET_HMKEY(prefix, _15, _14);
			ZEPHIR_GET_HVALUE(directory, _16);
			if (zephir_start_with(className, prefix, NULL)) {
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_VV(_4, prefix, namespaceSeparator);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_STRING(&_5, "", 0);
				ZEPHIR_INIT_NVAR(fileName);
				zephir_fast_str_replace(&fileName, _4, &_5, className TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_0);
				ZEPHIR_INIT_LNVAR(_17);
				ZEPHIR_CONCAT_VS(_17, prefix, "_");
				ZEPHIR_SINIT_NVAR(_18);
				ZVAL_STRING(&_18, "", 0);
				zephir_fast_str_replace(&_0, _17, &_18, fileName TSRMLS_CC);
				ZEPHIR_CPY_WRT(fileName, _0);
				ZEPHIR_INIT_NVAR(_0);
				ZEPHIR_SINIT_NVAR(_19);
				ZVAL_STRING(&_19, "_", 0);
				zephir_fast_str_replace(&_0, &_19, ds, fileName TSRMLS_CC);
				ZEPHIR_CPY_WRT(fileName, _0);
				if (zephir_is_true(fileName)) {
					ZEPHIR_INIT_NVAR(_0);
					zephir_fast_trim(_0, directory, ds, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
					ZEPHIR_INIT_NVAR(fixedDirectory);
					ZEPHIR_CONCAT_VV(fixedDirectory, _0, ds);
					zephir_is_iterable(extensions, &_21, &_20, 0, 0, "phalcon/loader.zep", 399);
					for (
					  ; zephir_hash_get_current_data_ex(_21, (void**) &_22, &_20) == SUCCESS
					  ; zephir_hash_move_forward_ex(_21, &_20)
					) {
						ZEPHIR_GET_HVALUE(extension, _22);
						ZEPHIR_INIT_NVAR(filePath);
						ZEPHIR_CONCAT_VVSV(filePath, fixedDirectory, fileName, ".", extension);
						if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
							zephir_update_property_this(this_ptr, SL("_checkedPath"), filePath TSRMLS_CC);
							ZEPHIR_INIT_NVAR(_9);
							ZVAL_STRING(_9, "loader:beforeCheckPath", ZEPHIR_TEMP_PARAM_COPY);
							ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_23, 0, _9, this_ptr, filePath);
							zephir_check_temp_parameter(_9);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_FUNCTION(&_11, "is_file", &_12, 279, filePath);
						zephir_check_call_status();
						if (zephir_is_true(_11)) {
							if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
								zephir_update_property_this(this_ptr, SL("_foundPath"), filePath TSRMLS_CC);
								ZEPHIR_INIT_NVAR(_9);
								ZVAL_STRING(_9, "loader:pathFound", ZEPHIR_TEMP_PARAM_COPY);
								ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_24, 0, _9, this_ptr, filePath);
								zephir_check_temp_parameter(_9);
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
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_STRING(&_5, "_", 0);
	ZEPHIR_INIT_VAR(dsClassName);
	zephir_fast_str_replace(&dsClassName, &_5, ds, className TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_18);
	ZVAL_STRING(&_18, "\\", 0);
	ZEPHIR_INIT_VAR(nsClassName);
	zephir_fast_str_replace(&nsClassName, &_18, ds, dsClassName TSRMLS_CC);
	ZEPHIR_OBS_VAR(directories);
	zephir_read_property_this(&directories, this_ptr, SL("_directories"), PH_NOISY_CC);
	if (Z_TYPE_P(directories) == IS_ARRAY) {
		zephir_is_iterable(directories, &_26, &_25, 0, 0, "phalcon/loader.zep", 464);
		for (
		  ; zephir_hash_get_current_data_ex(_26, (void**) &_27, &_25) == SUCCESS
		  ; zephir_hash_move_forward_ex(_26, &_25)
		) {
			ZEPHIR_GET_HVALUE(directory, _27);
			ZEPHIR_INIT_NVAR(_0);
			zephir_fast_trim(_0, directory, ds, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
			ZEPHIR_INIT_NVAR(fixedDirectory);
			ZEPHIR_CONCAT_VV(fixedDirectory, _0, ds);
			zephir_is_iterable(extensions, &_29, &_28, 0, 0, "phalcon/loader.zep", 463);
			for (
			  ; zephir_hash_get_current_data_ex(_29, (void**) &_30, &_28) == SUCCESS
			  ; zephir_hash_move_forward_ex(_29, &_28)
			) {
				ZEPHIR_GET_HVALUE(extension, _30);
				ZEPHIR_INIT_NVAR(filePath);
				ZEPHIR_CONCAT_VVSV(filePath, fixedDirectory, nsClassName, ".", extension);
				if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
					zephir_update_property_this(this_ptr, SL("_checkedPath"), filePath TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_9);
					ZVAL_STRING(_9, "loader:beforeCheckPath", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_31, 0, _9, this_ptr, filePath);
					zephir_check_temp_parameter(_9);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_FUNCTION(&_11, "is_file", &_12, 279, filePath);
				zephir_check_call_status();
				if (zephir_is_true(_11)) {
					if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
						zephir_update_property_this(this_ptr, SL("_foundPath"), filePath TSRMLS_CC);
						ZEPHIR_INIT_NVAR(_9);
						ZVAL_STRING(_9, "loader:pathFound", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_32, 0, _9, this_ptr, filePath);
						zephir_check_temp_parameter(_9);
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
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "loader:afterCheckClass", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _0, this_ptr, className);
		zephir_check_temp_parameter(_0);
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

