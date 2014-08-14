
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
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
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
	array_init_size(_0, 2);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "php", 1);
	zephir_array_fast_append(_0, _1);
	zephir_update_property_this(this_ptr, SL("_extensions"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the events manager
 *
 * @param Phalcon\Events\ManagerInterface eventsManager
 */
PHP_METHOD(Phalcon_Loader, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	if (!(zephir_instance_of_ev(eventsManager, phalcon_events_managerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'eventsManager' must be an instance of 'Phalcon\\Events\\ManagerInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_eventsManager"), eventsManager TSRMLS_CC);

}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Loader, getEventsManager) {


	RETURN_MEMBER(this_ptr, "_eventsManager");

}

/**
 * Sets an array of extensions that the loader must try in each attempt to locate the file
 *
 * @param array extensions
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, setExtensions) {

	zval *extensions_param = NULL;
	zval *extensions = NULL;

	zephir_fetch_params(0, 1, 0, &extensions_param);

	if (unlikely(Z_TYPE_P(extensions_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'extensions' must be an array") TSRMLS_CC);
		RETURN_NULL();
	}

		extensions = extensions_param;



	zephir_update_property_this(this_ptr, SL("_extensions"), extensions TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Return file extensions registered in the loader
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Loader, getExtensions) {


	RETURN_MEMBER(this_ptr, "_extensions");

}

/**
 * Register namespaces and their related directories
 *
 * @param array namespaces
 * @param boolean merge
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, registerNamespaces) {

	zend_bool merge;
	zval *namespaces, *merge_param = NULL, *currentNamespaces, *mergedNamespaces = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &namespaces, &merge_param);

	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (Z_TYPE_P(namespaces) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_exception_ce, "Parameter namespaces must be an array", "phalcon/loader.zep", 131);
		return;
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
 * Return current namespaces registered in the autoloader
 *
 * @param array
 */
PHP_METHOD(Phalcon_Loader, getNamespaces) {


	RETURN_MEMBER(this_ptr, "_namespaces");

}

/**
 * Register directories on which "not found" classes could be found
 *
 * @param array prefixes
 * @param boolean merge
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, registerPrefixes) {

	zend_bool merge;
	zval *prefixes, *merge_param = NULL, *currentPrefixes, *mergedPrefixes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &prefixes, &merge_param);

	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (Z_TYPE_P(prefixes) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_exception_ce, "Parameter prefixes must be an array", "phalcon/loader.zep", 171);
		return;
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
 * Return current prefixes registered in the autoloader
 *
 * @param array
 */
PHP_METHOD(Phalcon_Loader, getPrefixes) {


	RETURN_MEMBER(this_ptr, "_prefixes");

}

/**
 * Register directories on which "not found" classes could be found
 *
 * @param array directories
 * @param boolean merge
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, registerDirs) {

	zend_bool merge;
	zval *directories, *merge_param = NULL, *currentDirectories, *mergedDirectories = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &directories, &merge_param);

	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (Z_TYPE_P(directories) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_exception_ce, "Parameter directories must be an array", "phalcon/loader.zep", 210);
		return;
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
 * Return current directories registered in the autoloader
 *
 * @param array
 */
PHP_METHOD(Phalcon_Loader, getDirs) {


	RETURN_MEMBER(this_ptr, "_directories");

}

/**
 * Register classes and their locations
 *
 * @param array classes
 * @param boolean merge
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, registerClasses) {

	zval *classes, *merge = NULL, *mergedClasses = NULL, *currentClasses;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &classes, &merge);

	if (!merge) {
		merge = ZEPHIR_GLOBAL(global_false);
	}


	if (Z_TYPE_P(classes) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_exception_ce, "Parameter classes must be an array", "phalcon/loader.zep", 249);
		return;
	}
	if (zephir_is_true(merge)) {
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
 * Return the current class-map registered in the autoloader
 *
 * @param array
 */
PHP_METHOD(Phalcon_Loader, getClasses) {


	RETURN_MEMBER(this_ptr, "_classes");

}

/**
 * Register the autoload method
 *
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, register) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *_0, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_registered"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_INIT_VAR(_1);
		array_init_size(_1, 3);
		zephir_array_fast_append(_1, this_ptr);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "autoLoad", 1);
		zephir_array_fast_append(_1, _2);
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, _1);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_registered"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Unregister the autoload method
 *
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, unregister) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *_0, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_registered"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE_IDENTICAL(_0)) {
		ZEPHIR_INIT_VAR(_1);
		array_init_size(_1, 3);
		zephir_array_fast_append(_1, this_ptr);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "autoLoad", 1);
		zephir_array_fast_append(_1, _2);
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_unregister", NULL, _1);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_registered"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Makes the work of autoload registered classes
 *
 * @param string className
 * @return boolean
 */
PHP_METHOD(Phalcon_Loader, autoLoad) {

	zephir_nts_static zephir_fcall_cache_entry *_11 = NULL;
	HashTable *_2, *_7, *_13, *_19, *_22, *_25;
	HashPosition _1, _6, _12, _18, _21, _24;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *eventsManager, *classes, *extensions, *filePath = NULL, *ds, *fixedDirectory = NULL, *prefixes, *directories, *namespaceSeparator, *namespaces, *nsPrefix = NULL, *directory = NULL, *fileName = NULL, *extension = NULL, *prefix = NULL, *dsClassName, *nsClassName, *_0 = NULL, **_3, *_4 = NULL, _5 = zval_used_for_init, **_8, *_9 = NULL, *_10 = NULL, **_14, *_15 = NULL, _16 = zval_used_for_init, _17 = zval_used_for_init, **_20, **_23, **_26;
	zval *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	if (unlikely(Z_TYPE_P(className_param) != IS_STRING && Z_TYPE_P(className_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'className' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(className_param) == IS_STRING)) {
		className = className_param;
	} else {
		ZEPHIR_INIT_VAR(className);
		ZVAL_EMPTY_STRING(className);
	}


	ZEPHIR_OBS_VAR(eventsManager);
	zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "loader:beforeCheckClass", 0);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, _0, this_ptr, className);
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
				ZVAL_STRING(_0, "loader:pathFound", 0);
				ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, _0, this_ptr, filePath);
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
		zephir_is_iterable(namespaces, &_2, &_1, 0, 0, "phalcon/loader.zep", 404);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HMKEY(nsPrefix, _2, _1);
			ZEPHIR_GET_HVALUE(directory, _3);
			if (zephir_start_with(className, nsPrefix, NULL)) {
				ZEPHIR_INIT_NVAR(fileName);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_VV(_4, nsPrefix, namespaceSeparator);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_STRING(&_5, "", 0);
				zephir_fast_str_replace(fileName, _4, &_5, className);
				ZEPHIR_INIT_NVAR(_0);
				zephir_fast_str_replace(_0, namespaceSeparator, ds, fileName);
				ZEPHIR_CPY_WRT(fileName, _0);
				if (zephir_is_true(fileName)) {
					ZEPHIR_INIT_NVAR(_0);
					zephir_fast_trim(_0, directory, ds, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
					ZEPHIR_INIT_NVAR(fixedDirectory);
					ZEPHIR_CONCAT_VV(fixedDirectory, _0, ds);
					zephir_is_iterable(extensions, &_7, &_6, 0, 0, "phalcon/loader.zep", 401);
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
							ZVAL_STRING(_9, "loader:beforeCheckPath", 0);
							ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, _9, this_ptr);
							zephir_check_temp_parameter(_9);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_FUNCTION(&_10, "is_file", &_11, filePath);
						zephir_check_call_status();
						if (zephir_is_true(_10)) {
							if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
								zephir_update_property_this(this_ptr, SL("_foundPath"), filePath TSRMLS_CC);
								ZEPHIR_INIT_NVAR(_9);
								ZVAL_STRING(_9, "loader:pathFound", 0);
								ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, _9, this_ptr, filePath);
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
		zephir_is_iterable(prefixes, &_13, &_12, 0, 0, "phalcon/loader.zep", 459);
		for (
		  ; zephir_hash_get_current_data_ex(_13, (void**) &_14, &_12) == SUCCESS
		  ; zephir_hash_move_forward_ex(_13, &_12)
		) {
			ZEPHIR_GET_HMKEY(prefix, _13, _12);
			ZEPHIR_GET_HVALUE(directory, _14);
			if (zephir_start_with(className, prefix, NULL)) {
				ZEPHIR_INIT_NVAR(fileName);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_VV(_4, prefix, namespaceSeparator);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_STRING(&_5, "", 0);
				zephir_fast_str_replace(fileName, _4, &_5, className);
				ZEPHIR_INIT_NVAR(_0);
				ZEPHIR_INIT_LNVAR(_15);
				ZEPHIR_CONCAT_VS(_15, prefix, "_");
				ZEPHIR_SINIT_NVAR(_16);
				ZVAL_STRING(&_16, "", 0);
				zephir_fast_str_replace(_0, _15, &_16, fileName);
				ZEPHIR_CPY_WRT(fileName, _0);
				ZEPHIR_INIT_NVAR(_0);
				ZEPHIR_SINIT_NVAR(_17);
				ZVAL_STRING(&_17, "_", 0);
				zephir_fast_str_replace(_0, &_17, ds, fileName);
				ZEPHIR_CPY_WRT(fileName, _0);
				if (zephir_is_true(fileName)) {
					ZEPHIR_INIT_NVAR(_0);
					zephir_fast_trim(_0, directory, ds, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
					ZEPHIR_INIT_NVAR(fixedDirectory);
					ZEPHIR_CONCAT_VV(fixedDirectory, _0, ds);
					zephir_is_iterable(extensions, &_19, &_18, 0, 0, "phalcon/loader.zep", 456);
					for (
					  ; zephir_hash_get_current_data_ex(_19, (void**) &_20, &_18) == SUCCESS
					  ; zephir_hash_move_forward_ex(_19, &_18)
					) {
						ZEPHIR_GET_HVALUE(extension, _20);
						ZEPHIR_INIT_NVAR(filePath);
						ZEPHIR_CONCAT_VVSV(filePath, fixedDirectory, fileName, ".", extension);
						if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
							zephir_update_property_this(this_ptr, SL("_checkedPath"), filePath TSRMLS_CC);
							ZEPHIR_INIT_NVAR(_9);
							ZVAL_STRING(_9, "loader:beforeCheckPath", 0);
							ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, _9, this_ptr, filePath);
							zephir_check_temp_parameter(_9);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_FUNCTION(&_10, "is_file", &_11, filePath);
						zephir_check_call_status();
						if (zephir_is_true(_10)) {
							if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
								zephir_update_property_this(this_ptr, SL("_foundPath"), filePath TSRMLS_CC);
								ZEPHIR_INIT_NVAR(_9);
								ZVAL_STRING(_9, "loader:pathFound", 0);
								ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, _9, this_ptr, filePath);
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
	ZEPHIR_INIT_VAR(dsClassName);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_STRING(&_5, "_", 0);
	zephir_fast_str_replace(dsClassName, &_5, ds, className);
	ZEPHIR_INIT_VAR(nsClassName);
	ZEPHIR_SINIT_NVAR(_16);
	ZVAL_STRING(&_16, "\\", 0);
	zephir_fast_str_replace(nsClassName, &_16, ds, dsClassName);
	ZEPHIR_OBS_VAR(directories);
	zephir_read_property_this(&directories, this_ptr, SL("_directories"), PH_NOISY_CC);
	if (Z_TYPE_P(directories) == IS_ARRAY) {
		zephir_is_iterable(directories, &_22, &_21, 0, 0, "phalcon/loader.zep", 521);
		for (
		  ; zephir_hash_get_current_data_ex(_22, (void**) &_23, &_21) == SUCCESS
		  ; zephir_hash_move_forward_ex(_22, &_21)
		) {
			ZEPHIR_GET_HVALUE(directory, _23);
			ZEPHIR_INIT_NVAR(_0);
			zephir_fast_trim(_0, directory, ds, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
			ZEPHIR_INIT_NVAR(fixedDirectory);
			ZEPHIR_CONCAT_VV(fixedDirectory, _0, ds);
			zephir_is_iterable(extensions, &_25, &_24, 0, 0, "phalcon/loader.zep", 520);
			for (
			  ; zephir_hash_get_current_data_ex(_25, (void**) &_26, &_24) == SUCCESS
			  ; zephir_hash_move_forward_ex(_25, &_24)
			) {
				ZEPHIR_GET_HVALUE(extension, _26);
				ZEPHIR_INIT_NVAR(filePath);
				ZEPHIR_CONCAT_VVSV(filePath, fixedDirectory, nsClassName, ".", extension);
				if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
					zephir_update_property_this(this_ptr, SL("_checkedPath"), filePath TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_9);
					ZVAL_STRING(_9, "loader:beforeCheckPath", 0);
					ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, _9, this_ptr, filePath);
					zephir_check_temp_parameter(_9);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_FUNCTION(&_10, "is_file", &_11, filePath);
				zephir_check_call_status();
				if (zephir_is_true(_10)) {
					if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
						zephir_update_property_this(this_ptr, SL("_foundPath"), filePath TSRMLS_CC);
						ZEPHIR_INIT_NVAR(_9);
						ZVAL_STRING(_9, "loader:pathFound", 0);
						ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, _9, this_ptr, filePath);
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
		ZVAL_STRING(_0, "loader:afterCheckClass", 0);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, _0, this_ptr, className);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Get the path when a class was found
 *
 * @return string
 */
PHP_METHOD(Phalcon_Loader, getFoundPath) {


	RETURN_MEMBER(this_ptr, "_foundPath");

}

/**
 * Get the path the loader is checking for a path
 *
 * @return string
 */
PHP_METHOD(Phalcon_Loader, getCheckedPath) {


	RETURN_MEMBER(this_ptr, "_checkedPath");

}

