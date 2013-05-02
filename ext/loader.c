
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/require.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/file.h"

/**
 * Phalcon\Loader
 *
 * This component helps to load your project classes automatically based on some conventions
 *
 *<code>
 * //Creates the autoloader
 * $loader = new Phalcon\Loader();
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


/**
 * Phalcon\Loader initializer
 */
PHALCON_INIT_CLASS(Phalcon_Loader){

	PHALCON_REGISTER_CLASS(Phalcon, Loader, loader, phalcon_loader_method_entry, 0);

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
PHP_METHOD(Phalcon_Loader, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	
	PHALCON_INIT_VAR(a0);
	array_init_size(a0, 1);
	add_next_index_stringl(a0, SL("php"), 1);
	zend_update_property(phalcon_loader_ce, this_ptr, SL("_extensions"), a0 TSRMLS_CC);
	

	PHALCON_MM_RESTORE();
}

/**
 * Sets the events manager
 *
 * @param Phalcon\Events\ManagerInterface $eventsManager
 */
PHP_METHOD(Phalcon_Loader, setEventsManager){

	zval *events_manager;

	phalcon_fetch_params(0, 1, 0, &events_manager);
	
	phalcon_update_property_zval(this_ptr, SL("_eventsManager"), events_manager TSRMLS_CC);
	
}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Loader, getEventsManager){


	RETURN_MEMBER(this_ptr, "_eventsManager");
}

/**
 * Sets an array of extensions that the Loader must check together with the path
 *
 * @param array $extensions
 * @param boolean $merge
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, setExtensions){

	zval *extensions;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &extensions);
	
	if (Z_TYPE_P(extensions) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_loader_exception_ce, "Parameter $extensions must be an Array");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_extensions"), extensions TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Return file extensions registered in the loader
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Loader, getExtensions){


	RETURN_MEMBER(this_ptr, "_extensions");
}

/**
 * Register namespaces and their related directories
 *
 * @param array $namespaces
 * @param boolean $merge
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, registerNamespaces){

	zval *namespaces, *merge = NULL, *current_namespaces;
	zval *merged_namespaces;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &namespaces, &merge);
	
	if (!merge) {
		PHALCON_INIT_VAR(merge);
		ZVAL_BOOL(merge, 0);
	}
	
	if (Z_TYPE_P(namespaces) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_loader_exception_ce, "Parameter $namespaces must be an Array");
		return;
	}
	if (zend_is_true(merge)) {
		PHALCON_OBS_VAR(current_namespaces);
		phalcon_read_property_this(&current_namespaces, this_ptr, SL("_namespaces"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(merged_namespaces);
		phalcon_fast_array_merge(merged_namespaces, &current_namespaces, &namespaces TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_namespaces"), merged_namespaces TSRMLS_CC);
	} else {
		phalcon_update_property_zval(this_ptr, SL("_namespaces"), namespaces TSRMLS_CC);
	}
	
	
	RETURN_THIS();
}

/**
 * Return current namespaces registered in the autoloader
 *
 * @param array
 */
PHP_METHOD(Phalcon_Loader, getNamespaces){


	RETURN_MEMBER(this_ptr, "_namespaces");
}

/**
 * Register directories on which "not found" classes could be found
 *
 * @param array $prefixes
 * @param boolean $merge
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, registerPrefixes){

	zval *prefixes, *merge = NULL, *current_prefixes, *merged_prefixes;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &prefixes, &merge);
	
	if (!merge) {
		PHALCON_INIT_VAR(merge);
		ZVAL_BOOL(merge, 0);
	}
	
	if (Z_TYPE_P(prefixes) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_loader_exception_ce, "Parameter $prefixes must be an Array");
		return;
	}
	if (zend_is_true(merge)) {
		PHALCON_OBS_VAR(current_prefixes);
		phalcon_read_property_this(&current_prefixes, this_ptr, SL("_prefixes"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(merged_prefixes);
		phalcon_fast_array_merge(merged_prefixes, &current_prefixes, &prefixes TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_prefixes"), merged_prefixes TSRMLS_CC);
	} else {
		phalcon_update_property_zval(this_ptr, SL("_prefixes"), prefixes TSRMLS_CC);
	}
	
	
	RETURN_THIS();
}

/**
 * Return current prefixes registered in the autoloader
 *
 * @param array
 */
PHP_METHOD(Phalcon_Loader, getPrefixes){


	RETURN_MEMBER(this_ptr, "_prefixes");
}

/**
 * Register directories on which "not found" classes could be found
 *
 * @param array $directories
 * @param boolean $merge
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, registerDirs){

	zval *directories, *merge = NULL, *current_directories;
	zval *merged_directories;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &directories, &merge);
	
	if (!merge) {
		PHALCON_INIT_VAR(merge);
		ZVAL_BOOL(merge, 0);
	}
	
	if (Z_TYPE_P(directories) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_loader_exception_ce, "Parameter $directories must be an Array");
		return;
	}
	if (zend_is_true(merge)) {
		PHALCON_OBS_VAR(current_directories);
		phalcon_read_property_this(&current_directories, this_ptr, SL("_directories"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(merged_directories);
		phalcon_fast_array_merge(merged_directories, &current_directories, &directories TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_directories"), merged_directories TSRMLS_CC);
	} else {
		phalcon_update_property_zval(this_ptr, SL("_directories"), directories TSRMLS_CC);
	}
	
	
	RETURN_THIS();
}

/**
 * Return current directories registered in the autoloader
 *
 * @param array
 */
PHP_METHOD(Phalcon_Loader, getDirs){


	RETURN_MEMBER(this_ptr, "_directories");
}

/**
 * Register classes and their locations
 *
 * @param array $classes
 * @param boolean $merge
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, registerClasses){

	zval *classes, *merge = NULL, *current_classes, *merged_classes;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &classes, &merge);
	
	if (!merge) {
		PHALCON_INIT_VAR(merge);
		ZVAL_BOOL(merge, 0);
	}
	
	if (Z_TYPE_P(classes) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_loader_exception_ce, "Parameter $classes must be an Array");
		return;
	}
	if (zend_is_true(merge)) {
		PHALCON_OBS_VAR(current_classes);
		phalcon_read_property_this(&current_classes, this_ptr, SL("_classes"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(merged_classes);
		phalcon_fast_array_merge(merged_classes, &current_classes, &classes TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_classes"), merged_classes TSRMLS_CC);
	} else {
		phalcon_update_property_zval(this_ptr, SL("_classes"), classes TSRMLS_CC);
	}
	
	
	RETURN_THIS();
}

/**
 * Return the current class-map registered in the autoloader
 *
 * @param array
 */
PHP_METHOD(Phalcon_Loader, getClasses){


	RETURN_MEMBER(this_ptr, "_classes");
}

/**
 * Register the autoload method
 *
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, register){

	zval *registered, *autoloader;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(registered);
	phalcon_read_property_this(&registered, this_ptr, SL("_registered"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(registered)) {
		PHALCON_INIT_VAR(autoloader);
		array_init_size(autoloader, 2);
		phalcon_array_append(&autoloader, this_ptr, PH_SEPARATE TSRMLS_CC);
		add_next_index_stringl(autoloader, SL("autoLoad"), 1);
		PHALCON_CALL_FUNC_PARAMS_1_NORETURN("spl_autoload_register", autoloader);
	}
	
	
	RETURN_THIS();
}

/**
 * Unregister the autoload method
 *
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, unregister){

	zval *registered, *autoloader;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(registered);
	phalcon_read_property_this(&registered, this_ptr, SL("_registered"), PH_NOISY_CC);
	if (PHALCON_IS_TRUE(registered)) {
		PHALCON_INIT_VAR(autoloader);
		array_init_size(autoloader, 2);
		phalcon_array_append(&autoloader, this_ptr, PH_SEPARATE TSRMLS_CC);
		add_next_index_stringl(autoloader, SL("autoLoad"), 1);
		PHALCON_CALL_FUNC_PARAMS_1_NORETURN("spl_autoload_unregister", autoloader);
	}
	
	
	RETURN_THIS();
}

/**
 * Makes the work of autoload registered classes
 *
 * @param string $className
 * @return boolean
 */
PHP_METHOD(Phalcon_Loader, autoLoad){

	zval *class_name, *events_manager, *event_name = NULL;
	zval *classes, *file_path = NULL, *extensions, *ds, *namespace_separator;
	zval *empty_str, *zero, *namespaces, *directory = NULL;
	zval *prefix = NULL, *prefix_namespace = NULL, *file_name = NULL;
	zval *fixed_directory = NULL, *extension = NULL, *complete_path = NULL;
	zval *pseudo_separator, *prefixes, *no_prefix_class = NULL;
	zval *ds_class_name, *ns_class_name, *directories;
	HashTable *ah0, *ah1, *ah2, *ah3, *ah4, *ah5;
	HashPosition hp0, hp1, hp2, hp3, hp4, hp5;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &class_name);
	
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "loader:beforeCheckClass", 1);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, class_name);
	}
	
	/** 
	 * First we check for static paths for classes
	 */
	PHALCON_OBS_VAR(classes);
	phalcon_read_property_this(&classes, this_ptr, SL("_classes"), PH_NOISY_CC);
	if (Z_TYPE_P(classes) == IS_ARRAY) { 
		if (phalcon_array_isset(classes, class_name)) {
	
			PHALCON_OBS_VAR(file_path);
			phalcon_array_fetch(&file_path, classes, class_name, PH_NOISY_CC);
			if (Z_TYPE_P(events_manager) == IS_OBJECT) {
				phalcon_update_property_zval(this_ptr, SL("_foundPath"), file_path TSRMLS_CC);
	
				PHALCON_INIT_NVAR(event_name);
				ZVAL_STRING(event_name, "loader:pathFound", 1);
				PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, file_path);
			}
	
			if (phalcon_require(file_path TSRMLS_CC) == FAILURE) {
				return;
			}
			RETURN_MM_TRUE;
		}
	}
	
	PHALCON_OBS_VAR(extensions);
	phalcon_read_property_this(&extensions, this_ptr, SL("_extensions"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(ds);
	ZVAL_STRING(ds, DEFAULT_SLASH, 1);
	
	PHALCON_INIT_VAR(namespace_separator);
	ZVAL_STRING(namespace_separator, "\\", 1);
	
	PHALCON_INIT_VAR(empty_str);
	ZVAL_STRING(empty_str, "", 1);
	
	PHALCON_INIT_VAR(zero);
	ZVAL_LONG(zero, 0);
	
	/** 
	 * Checking in namespaces
	 */
	PHALCON_OBS_VAR(namespaces);
	phalcon_read_property_this(&namespaces, this_ptr, SL("_namespaces"), PH_NOISY_CC);
	if (Z_TYPE_P(namespaces) == IS_ARRAY) { 
	
		if (!phalcon_is_iterable(namespaces, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_KEY(prefix, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(directory);
	
			/** 
			 * The class name must start with the current namespace
			 */
			if (phalcon_start_with(class_name, prefix, NULL)) {
	
				/** 
				 * Append the namespace separator to the prefix
				 */
				PHALCON_INIT_NVAR(prefix_namespace);
				PHALCON_CONCAT_VV(prefix_namespace, prefix, namespace_separator);
	
				PHALCON_INIT_NVAR(file_name);
				phalcon_fast_str_replace(file_name, prefix_namespace, empty_str, class_name TSRMLS_CC);
				if (zend_is_true(file_name)) {
	
					/** 
					 * Add a trailing directory separator if the user forgot to do that
					 */
					PHALCON_INIT_NVAR(fixed_directory);
					phalcon_fix_path(&fixed_directory, directory, ds TSRMLS_CC);
	
					if (!phalcon_is_iterable(extensions, &ah1, &hp1, 0, 0 TSRMLS_CC)) {
						return;
					}
	
					while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
						PHALCON_GET_FOREACH_VALUE(extension);
	
						PHALCON_INIT_NVAR(complete_path);
						PHALCON_CONCAT_VVSV(complete_path, fixed_directory, file_name, ".", extension);
	
						PHALCON_INIT_NVAR(file_path);
						phalcon_fast_str_replace(file_path, namespace_separator, ds, complete_path TSRMLS_CC);
	
						/** 
						 * Check if a events manager is available
						 */
						if (Z_TYPE_P(events_manager) == IS_OBJECT) {
							phalcon_update_property_zval(this_ptr, SL("_checkedPath"), file_path TSRMLS_CC);
	
							PHALCON_INIT_NVAR(event_name);
							ZVAL_STRING(event_name, "loader:beforeCheckPath", 1);
							PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr);
						}
	
						/** 
						 * This is probably a good path, let's check if the file exist
						 */
						if (phalcon_file_exists(file_path TSRMLS_CC) == SUCCESS) {
							if (Z_TYPE_P(events_manager) == IS_OBJECT) {
								phalcon_update_property_zval(this_ptr, SL("_foundPath"), file_path TSRMLS_CC);
	
								PHALCON_INIT_NVAR(event_name);
								ZVAL_STRING(event_name, "loader:pathFound", 1);
								PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, file_path);
							}
	
							/** 
							 * Simulate a require
							 */
							if (phalcon_require(file_path TSRMLS_CC) == FAILURE) {
								return;
							}
	
							/** 
							 * Return true mean success
							 */
							RETURN_MM_TRUE;
						}
	
						zend_hash_move_forward_ex(ah1, &hp1);
					}
	
				}
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	PHALCON_INIT_VAR(pseudo_separator);
	ZVAL_STRING(pseudo_separator, "_", 1);
	
	/** 
	 * Checking in prefixes
	 */
	PHALCON_OBS_VAR(prefixes);
	phalcon_read_property_this(&prefixes, this_ptr, SL("_prefixes"), PH_NOISY_CC);
	if (Z_TYPE_P(prefixes) == IS_ARRAY) { 
	
		if (!phalcon_is_iterable(prefixes, &ah2, &hp2, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
			PHALCON_GET_FOREACH_KEY(prefix, ah2, hp2);
			PHALCON_GET_FOREACH_VALUE(directory);
	
			/** 
			 * The class name starts with the prefix?
			 */
			if (phalcon_start_with(class_name, prefix, NULL)) {
	
				/** 
				 * Remove the prefix from the class
				 */
				PHALCON_INIT_NVAR(no_prefix_class);
				phalcon_fast_str_replace(no_prefix_class, prefix, empty_str, class_name TSRMLS_CC);
	
				/** 
				 * Change the pseudo-separator '_' by the directory separator
				 */
				PHALCON_INIT_NVAR(file_name);
				phalcon_fast_str_replace(file_name, pseudo_separator, ds, no_prefix_class TSRMLS_CC);
				if (zend_is_true(file_name)) {
	
					/** 
					 * Add a trailing directory separator if the user forgot to do that
					 */
					PHALCON_INIT_NVAR(fixed_directory);
					phalcon_fix_path(&fixed_directory, directory, ds TSRMLS_CC);
	
					if (!phalcon_is_iterable(extensions, &ah3, &hp3, 0, 0 TSRMLS_CC)) {
						return;
					}
	
					while (zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) == SUCCESS) {
	
						PHALCON_GET_FOREACH_VALUE(extension);
	
						PHALCON_INIT_NVAR(complete_path);
						PHALCON_CONCAT_VVSV(complete_path, fixed_directory, file_name, ".", extension);
	
						PHALCON_INIT_NVAR(file_path);
						phalcon_fast_str_replace(file_path, namespace_separator, ds, complete_path TSRMLS_CC);
						if (Z_TYPE_P(events_manager) == IS_OBJECT) {
							phalcon_update_property_zval(this_ptr, SL("_checkedPath"), file_path TSRMLS_CC);
	
							PHALCON_INIT_NVAR(event_name);
							ZVAL_STRING(event_name, "loader:beforeCheckPath", 1);
							PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, file_path);
						}
	
						if (phalcon_file_exists(file_path TSRMLS_CC) == SUCCESS) {
	
							/** 
							 * Call 'pathFound' event
							 */
							if (Z_TYPE_P(events_manager) == IS_OBJECT) {
								phalcon_update_property_zval(this_ptr, SL("_foundPath"), file_path TSRMLS_CC);
	
								PHALCON_INIT_NVAR(event_name);
								ZVAL_STRING(event_name, "loader:pathFound", 1);
								PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, file_path);
							}
							if (phalcon_require(file_path TSRMLS_CC) == FAILURE) {
								return;
							}
							RETURN_MM_TRUE;
						}
	
						zend_hash_move_forward_ex(ah3, &hp3);
					}
	
				}
			}
	
			zend_hash_move_forward_ex(ah2, &hp2);
		}
	
	}
	
	/** 
	 * Change the pseudo-separator by the directory separator in the class name
	 */
	PHALCON_INIT_VAR(ds_class_name);
	phalcon_fast_str_replace(ds_class_name, pseudo_separator, ds, class_name TSRMLS_CC);
	
	/** 
	 * And change the namespace separator by directory separator too
	 */
	PHALCON_INIT_VAR(ns_class_name);
	phalcon_fast_str_replace(ns_class_name, namespace_separator, ds, ds_class_name TSRMLS_CC);
	
	/** 
	 * Checking in directories
	 */
	PHALCON_OBS_VAR(directories);
	phalcon_read_property_this(&directories, this_ptr, SL("_directories"), PH_NOISY_CC);
	if (Z_TYPE_P(directories) == IS_ARRAY) { 
	
		if (!phalcon_is_iterable(directories, &ah4, &hp4, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah4, (void**) &hd, &hp4) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(directory);
	
			/** 
			 * Add a trailing directory separator if the user forgot to do that
			 */
			PHALCON_INIT_NVAR(fixed_directory);
			phalcon_fix_path(&fixed_directory, directory, ds TSRMLS_CC);
	
			if (!phalcon_is_iterable(extensions, &ah5, &hp5, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah5, (void**) &hd, &hp5) == SUCCESS) {
	
				PHALCON_GET_FOREACH_VALUE(extension);
	
				/** 
				 * Create a possible path for the file
				 */
				PHALCON_INIT_NVAR(file_path);
				PHALCON_CONCAT_VVSV(file_path, fixed_directory, ns_class_name, ".", extension);
				if (Z_TYPE_P(events_manager) == IS_OBJECT) {
					phalcon_update_property_zval(this_ptr, SL("_checkedPath"), file_path TSRMLS_CC);
	
					PHALCON_INIT_NVAR(event_name);
					ZVAL_STRING(event_name, "loader:beforeCheckPath", 1);
					PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, file_path);
				}
	
				/** 
				 * Check in every directory if the class exists here
				 */
				if (phalcon_file_exists(file_path TSRMLS_CC) == SUCCESS) {
	
					/** 
					 * Call 'pathFound' event
					 */
					if (Z_TYPE_P(events_manager) == IS_OBJECT) {
						phalcon_update_property_zval(this_ptr, SL("_foundPath"), file_path TSRMLS_CC);
	
						PHALCON_INIT_NVAR(event_name);
						ZVAL_STRING(event_name, "loader:pathFound", 1);
						PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, file_path);
					}
	
					/** 
					 * Simulate a require
					 */
					if (phalcon_require(file_path TSRMLS_CC) == FAILURE) {
						return;
					}
	
					/** 
					 * Return true meaning success
					 */
					RETURN_MM_TRUE;
				}
	
				zend_hash_move_forward_ex(ah5, &hp5);
			}
	
	
			zend_hash_move_forward_ex(ah4, &hp4);
		}
	
	}
	
	/** 
	 * Call 'afterCheckClass' event
	 */
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "loader:afterCheckClass", 1);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, class_name);
	}
	
	/** 
	 * Cannot find the class return false
	 */
	RETURN_MM_FALSE;
}

/**
 * Get the path when a class was found
 *
 * @return string
 */
PHP_METHOD(Phalcon_Loader, getFoundPath){


	RETURN_MEMBER(this_ptr, "_foundPath");
}

/**
 * Get the path the loader is checking for a path
 *
 * @return string
 */
PHP_METHOD(Phalcon_Loader, getCheckedPath){


	RETURN_MEMBER(this_ptr, "_checkedPath");
}

