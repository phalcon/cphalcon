
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
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
 *   'Example\\Base' => 'vendor/example/base/',
 *   'Example\\Adapter' => 'vendor/example/adapter/',
 *   'Example' => 'vendor/example/'
 * ));
 *
 * //register autoloader
 * $loader->register();
 *
 * //Requiring class will automatically include file vendor/example/adapter/Some.php
 * $adapter = Example\Adapter\Some();
 *</code>
 */


PHP_METHOD(Phalcon_Loader, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, SL("php"), 1);
	zend_update_property(phalcon_loader_ce, this_ptr, SL("_extensions"), a0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets the events manager
 *
 * @param Phalcon\Events\Manager $eventsManager
 */
PHP_METHOD(Phalcon_Loader, setEventsManager){

	zval *events_manager;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &events_manager) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_eventsManager"), events_manager TSRMLS_CC);
	
}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\Manager
 */
PHP_METHOD(Phalcon_Loader, getEventsManager){


	RETURN_MEMBER(this_ptr, "_eventsManager");
}

/**
 * Sets an array of extensions that the Loader must check together with the path
 *
 * @param array $extensions
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, setExtensions){

	zval *extensions;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &extensions) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(extensions) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_loader_exception_ce, "Parameter $extensions must be an Array");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_extensions"), extensions TSRMLS_CC);
	
	RETURN_CTOR(this_ptr);
}

/**
 * Register namespaces and their related directories
 *
 * @param array $namespaces
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, registerNamespaces){

	zval *namespaces;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &namespaces) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(namespaces) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_loader_exception_ce, "Parameter $namespaces must be an Array");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_namespaces"), namespaces TSRMLS_CC);
	
	RETURN_CTOR(this_ptr);
}

/**
 * Register directories on which "not found" classes could be found
 *
 * @param array $directories
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, registerPrefixes){

	zval *prefixes;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &prefixes) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(prefixes) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_loader_exception_ce, "Parameter $prefixes must be an Array");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_prefixes"), prefixes TSRMLS_CC);
	
	RETURN_CTOR(this_ptr);
}

/**
 * Register directories on which "not found" classes could be found
 *
 * @param array $directories
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, registerDirs){

	zval *directories;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &directories) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(directories) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_loader_exception_ce, "Parameter $directories must be an Array");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_directories"), directories TSRMLS_CC);
	
	RETURN_CTOR(this_ptr);
}

/**
 * Register classes and their locations
 *
 * @param array $directories
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, registerClasses){

	zval *classes;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &classes) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(classes) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_loader_exception_ce, "Parameter $classes must be an Array");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_classes"), classes TSRMLS_CC);
	
	RETURN_CTOR(this_ptr);
}

/**
 * Register the autoload method
 *
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, register){

	zval *registered, *autoloader;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(registered);
	phalcon_read_property(&registered, this_ptr, SL("_registered"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(registered)) {
		PHALCON_INIT_VAR(autoloader);
		array_init(autoloader);
		phalcon_array_append(&autoloader, this_ptr, PH_SEPARATE TSRMLS_CC);
		add_next_index_stringl(autoloader, SL("autoLoad"), 1);
		PHALCON_CALL_FUNC_PARAMS_1_NORETURN("spl_autoload_register", autoloader);
	}
	
	
	RETURN_CTOR(this_ptr);
}

/**
 * Unregister the autoload method
 *
 * @return Phalcon\Loader
 */
PHP_METHOD(Phalcon_Loader, unregister){

	zval *registered, *autoloader;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(registered);
	phalcon_read_property(&registered, this_ptr, SL("_registered"), PH_NOISY_CC);
	if (PHALCON_IS_TRUE(registered)) {
		PHALCON_INIT_VAR(autoloader);
		array_init(autoloader);
		phalcon_array_append(&autoloader, this_ptr, PH_SEPARATE TSRMLS_CC);
		add_next_index_stringl(autoloader, SL("autoLoad"), 1);
		PHALCON_CALL_FUNC_PARAMS_1_NORETURN("spl_autoload_unregister", autoloader);
	}
	
	
	RETURN_CTOR(this_ptr);
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
	zval *extension = NULL, *complete_path = NULL, *pseudo_separator;
	zval *prefixes, *no_prefix_class = NULL, *ds_class_name;
	zval *ns_class_name, *directories;
	HashTable *ah0, *ah1, *ah2, *ah3, *ah4, *ah5;
	HashPosition hp0, hp1, hp2, hp3, hp4, hp5;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &class_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "loader:beforeCheckClass", 1);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, class_name, PH_NO_CHECK);
	}
	
	/** 
	 * First we check for static paths for classes
	 */
	PHALCON_INIT_VAR(classes);
	phalcon_read_property(&classes, this_ptr, SL("_classes"), PH_NOISY_CC);
	if (Z_TYPE_P(classes) == IS_ARRAY) { 
		eval_int = phalcon_array_isset(classes, class_name);
		if (eval_int) {
			PHALCON_INIT_VAR(file_path);
			phalcon_array_fetch(&file_path, classes, class_name, PH_NOISY_CC);
			if (Z_TYPE_P(events_manager) == IS_OBJECT) {
				phalcon_update_property_zval(this_ptr, SL("_foundPath"), file_path TSRMLS_CC);
				
				PHALCON_INIT_NVAR(event_name);
				ZVAL_STRING(event_name, "loader:pathFound", 1);
				PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, file_path, PH_NO_CHECK);
			}
			
			if (phalcon_require(file_path TSRMLS_CC) == FAILURE) {
				return;
			}
			PHALCON_MM_RESTORE();
			RETURN_TRUE;
		}
	}
	
	PHALCON_INIT_VAR(extensions);
	phalcon_read_property(&extensions, this_ptr, SL("_extensions"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(ds);
	zend_get_constant(SL("DIRECTORY_SEPARATOR"), ds TSRMLS_CC);
	
	PHALCON_INIT_VAR(namespace_separator);
	ZVAL_STRING(namespace_separator, "\\", 1);
	
	PHALCON_INIT_VAR(empty_str);
	ZVAL_STRING(empty_str, "", 1);
	
	PHALCON_INIT_VAR(zero);
	ZVAL_LONG(zero, 0);
	/** 
	 * Checking in namespaces
	 */
	PHALCON_INIT_VAR(namespaces);
	phalcon_read_property(&namespaces, this_ptr, SL("_namespaces"), PH_NOISY_CC);
	if (Z_TYPE_P(namespaces) == IS_ARRAY) { 
		
		if (!phalcon_valid_foreach(namespaces TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(namespaces);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		
		ph_cycle_start_0:
		
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_0;
			}
			
			PHALCON_GET_FOREACH_KEY(prefix, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(directory);
			
			if (phalcon_start_with(class_name, prefix)) {
				PHALCON_INIT_NVAR(prefix_namespace);
				PHALCON_CONCAT_VV(prefix_namespace, prefix, namespace_separator);
				
				PHALCON_INIT_NVAR(file_name);
				phalcon_fast_str_replace(file_name, prefix_namespace, empty_str, class_name TSRMLS_CC);
				if (zend_is_true(file_name)) {
					
					if (!phalcon_valid_foreach(extensions TSRMLS_CC)) {
						return;
					}
					
					ah1 = Z_ARRVAL_P(extensions);
					zend_hash_internal_pointer_reset_ex(ah1, &hp1);
					
					ph_cycle_start_1:
					
						if (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS) {
							goto ph_cycle_end_1;
						}
						
						PHALCON_GET_FOREACH_VALUE(extension);
						
						PHALCON_INIT_NVAR(complete_path);
						PHALCON_CONCAT_VVSV(complete_path, directory, file_name, ".", extension);
						
						PHALCON_INIT_NVAR(file_path);
						phalcon_fast_str_replace(file_path, namespace_separator, ds, complete_path TSRMLS_CC);
						if (Z_TYPE_P(events_manager) == IS_OBJECT) {
							phalcon_update_property_zval(this_ptr, SL("_checkedPath"), file_path TSRMLS_CC);
							
							PHALCON_INIT_NVAR(event_name);
							ZVAL_STRING(event_name, "loader:beforeCheckPath", 1);
							PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
						}
						
						if (phalcon_file_exists(file_path TSRMLS_CC) == SUCCESS) {
							if (Z_TYPE_P(events_manager) == IS_OBJECT) {
								phalcon_update_property_zval(this_ptr, SL("_foundPath"), file_path TSRMLS_CC);
								
								PHALCON_INIT_NVAR(event_name);
								ZVAL_STRING(event_name, "loader:pathFound", 1);
								PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, file_path, PH_NO_CHECK);
							}
							if (phalcon_require(file_path TSRMLS_CC) == FAILURE) {
								return;
							}
							PHALCON_MM_RESTORE();
							RETURN_TRUE;
						}
						
						zend_hash_move_forward_ex(ah1, &hp1);
						goto ph_cycle_start_1;
						
					ph_cycle_end_1:
					if(0){}
					
				}
			}
			
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
			
		ph_cycle_end_0:
		if(0){}
		
	}
	
	PHALCON_INIT_VAR(pseudo_separator);
	ZVAL_STRING(pseudo_separator, "_", 1);
	/** 
	 * Checking in prefixes
	 */
	PHALCON_INIT_VAR(prefixes);
	phalcon_read_property(&prefixes, this_ptr, SL("_prefixes"), PH_NOISY_CC);
	if (Z_TYPE_P(prefixes) == IS_ARRAY) { 
		
		if (!phalcon_valid_foreach(prefixes TSRMLS_CC)) {
			return;
		}
		
		ah2 = Z_ARRVAL_P(prefixes);
		zend_hash_internal_pointer_reset_ex(ah2, &hp2);
		
		ph_cycle_start_2:
		
			if (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS) {
				goto ph_cycle_end_2;
			}
			
			PHALCON_GET_FOREACH_KEY(prefix, ah2, hp2);
			PHALCON_GET_FOREACH_VALUE(directory);
			
			if (phalcon_start_with(class_name, prefix)) {
				PHALCON_INIT_NVAR(no_prefix_class);
				phalcon_fast_str_replace(no_prefix_class, prefix, empty_str, class_name TSRMLS_CC);
				
				PHALCON_INIT_NVAR(file_name);
				phalcon_fast_str_replace(file_name, pseudo_separator, ds, no_prefix_class TSRMLS_CC);
				if (zend_is_true(file_name)) {
					
					if (!phalcon_valid_foreach(extensions TSRMLS_CC)) {
						return;
					}
					
					ah3 = Z_ARRVAL_P(extensions);
					zend_hash_internal_pointer_reset_ex(ah3, &hp3);
					
					ph_cycle_start_3:
					
						if (zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) != SUCCESS) {
							goto ph_cycle_end_3;
						}
						
						PHALCON_GET_FOREACH_VALUE(extension);
						
						PHALCON_INIT_NVAR(complete_path);
						PHALCON_CONCAT_VVSV(complete_path, directory, file_name, ".", extension);
						
						PHALCON_INIT_NVAR(file_path);
						phalcon_fast_str_replace(file_path, namespace_separator, ds, complete_path TSRMLS_CC);
						if (Z_TYPE_P(events_manager) == IS_OBJECT) {
							phalcon_update_property_zval(this_ptr, SL("_checkedPath"), file_path TSRMLS_CC);
							
							PHALCON_INIT_NVAR(event_name);
							ZVAL_STRING(event_name, "loader:beforeCheckPath", 1);
							PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, file_path, PH_NO_CHECK);
						}
						
						if (phalcon_file_exists(file_path TSRMLS_CC) == SUCCESS) {
							if (Z_TYPE_P(events_manager) == IS_OBJECT) {
								phalcon_update_property_zval(this_ptr, SL("_foundPath"), file_path TSRMLS_CC);
								
								PHALCON_INIT_NVAR(event_name);
								ZVAL_STRING(event_name, "loader:pathFound", 1);
								PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, file_path, PH_NO_CHECK);
							}
							if (phalcon_require(file_path TSRMLS_CC) == FAILURE) {
								return;
							}
							PHALCON_MM_RESTORE();
							RETURN_TRUE;
						}
						
						zend_hash_move_forward_ex(ah3, &hp3);
						goto ph_cycle_start_3;
						
					ph_cycle_end_3:
					if(0){}
					
				}
			}
			
			zend_hash_move_forward_ex(ah2, &hp2);
			goto ph_cycle_start_2;
			
		ph_cycle_end_2:
		if(0){}
		
	}
	
	PHALCON_INIT_VAR(ds_class_name);
	phalcon_fast_str_replace(ds_class_name, pseudo_separator, ds, class_name TSRMLS_CC);
	
	PHALCON_INIT_VAR(ns_class_name);
	phalcon_fast_str_replace(ns_class_name, namespace_separator, ds, ds_class_name TSRMLS_CC);
	/** 
	 * Checking in directories
	 */
	PHALCON_INIT_VAR(directories);
	phalcon_read_property(&directories, this_ptr, SL("_directories"), PH_NOISY_CC);
	if (Z_TYPE_P(directories) == IS_ARRAY) { 
		
		if (!phalcon_valid_foreach(directories TSRMLS_CC)) {
			return;
		}
		
		ah4 = Z_ARRVAL_P(directories);
		zend_hash_internal_pointer_reset_ex(ah4, &hp4);
		
		ph_cycle_start_4:
		
			if (zend_hash_get_current_data_ex(ah4, (void**) &hd, &hp4) != SUCCESS) {
				goto ph_cycle_end_4;
			}
			
			PHALCON_GET_FOREACH_VALUE(directory);
			
			
			if (!phalcon_valid_foreach(extensions TSRMLS_CC)) {
				return;
			}
			
			ah5 = Z_ARRVAL_P(extensions);
			zend_hash_internal_pointer_reset_ex(ah5, &hp5);
			
			ph_cycle_start_5:
			
				if (zend_hash_get_current_data_ex(ah5, (void**) &hd, &hp5) != SUCCESS) {
					goto ph_cycle_end_5;
				}
				
				PHALCON_GET_FOREACH_VALUE(extension);
				
				PHALCON_INIT_NVAR(file_path);
				PHALCON_CONCAT_VVSV(file_path, directory, ns_class_name, ".", extension);
				if (Z_TYPE_P(events_manager) == IS_OBJECT) {
					phalcon_update_property_zval(this_ptr, SL("_checkedPath"), file_path TSRMLS_CC);
					
					PHALCON_INIT_NVAR(event_name);
					ZVAL_STRING(event_name, "loader:beforeCheckPath", 1);
					PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, file_path, PH_NO_CHECK);
				}
				
				if (phalcon_file_exists(file_path TSRMLS_CC) == SUCCESS) {
					if (Z_TYPE_P(events_manager) == IS_OBJECT) {
						phalcon_update_property_zval(this_ptr, SL("_foundPath"), file_path TSRMLS_CC);
						
						PHALCON_INIT_NVAR(event_name);
						ZVAL_STRING(event_name, "loader:pathFound", 1);
						PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, file_path, PH_NO_CHECK);
					}
					if (phalcon_require(file_path TSRMLS_CC) == FAILURE) {
						return;
					}
					PHALCON_MM_RESTORE();
					RETURN_TRUE;
				}
				
				zend_hash_move_forward_ex(ah5, &hp5);
				goto ph_cycle_start_5;
				
			ph_cycle_end_5:
			
			
			zend_hash_move_forward_ex(ah4, &hp4);
			goto ph_cycle_start_4;
			
		ph_cycle_end_4:
		if(0){}
		
	}
	
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "loader:afterCheckClass", 1);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, class_name, PH_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
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

