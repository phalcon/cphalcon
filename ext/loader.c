
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
#include "kernel/concat.h"

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

	
	PHALCON_ALLOC_ZVAL_MM(a0);
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

	zval *events_manager = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &events_manager) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_eventsManager"), events_manager TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\Manager
 */
PHP_METHOD(Phalcon_Loader, getEventsManager){

	zval *events_manager = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	
	RETURN_CCTOR(events_manager);
}

/**
 * Sets an array of extensions that the Loader must check together with the path
 *
 * @param array $extensions
 */
PHP_METHOD(Phalcon_Loader, setExtensions){

	zval *extensions = NULL;

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
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Register namespaces and their related directories
 *
 * @param array $namespaces
 */
PHP_METHOD(Phalcon_Loader, registerNamespaces){

	zval *namespaces = NULL;

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
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Register directories on which "not found" classes could be found
 *
 * @param array $directories
 */
PHP_METHOD(Phalcon_Loader, registerPrefixes){

	zval *prefixes = NULL;

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
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Register directories on which "not found" classes could be found
 *
 * @param array $directories
 */
PHP_METHOD(Phalcon_Loader, registerDirs){

	zval *directories = NULL;

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
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Register classes and their locations
 *
 * @param array $directories
 */
PHP_METHOD(Phalcon_Loader, registerClasses){

	zval *classes = NULL;

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
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Register the autoload method
 */
PHP_METHOD(Phalcon_Loader, register){

	zval *registered = NULL, *autoloader = NULL;

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
	
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Unregister the autoload method
 */
PHP_METHOD(Phalcon_Loader, unregister){

	zval *registered = NULL, *autoloader = NULL;

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
	
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Makes the work of autoload registered classes
 *
 * @param string $className
 * @return boolean
 */
PHP_METHOD(Phalcon_Loader, autoLoad){

	zval *class_name = NULL, *events_manager = NULL, *event_name = NULL;
	zval *classes = NULL, *file_path = NULL, *extensions = NULL, *ds = NULL, *namespace_separator = NULL;
	zval *empty_str = NULL, *zero = NULL, *namespaces = NULL, *directory = NULL;
	zval *preffix = NULL, *preffix_len = NULL, *possible_preffix = NULL;
	zval *prefix_namespace = NULL, *file_name = NULL, *extension = NULL;
	zval *complete_path = NULL, *path = NULL, *prefixes = NULL, *ds_class_name = NULL;
	zval *directories = NULL;
	zval *r0 = NULL, *r1 = NULL;
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
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
	}
	
	PHALCON_INIT_VAR(classes);
	phalcon_read_property(&classes, this_ptr, SL("_classes"), PH_NOISY_CC);
	if (Z_TYPE_P(classes) == IS_ARRAY) { 
		eval_int = phalcon_array_isset(classes, class_name);
		if (eval_int) {
			PHALCON_INIT_VAR(file_path);
			phalcon_array_fetch(&file_path, classes, class_name, PH_NOISY_CC);
			if (Z_TYPE_P(events_manager) == IS_OBJECT) {
				phalcon_update_property_zval(this_ptr, SL("_foundPath"), file_path TSRMLS_CC);
				
				PHALCON_INIT_VAR(event_name);
				ZVAL_STRING(event_name, "loader:pathFound", 1);
				PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
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
	
	PHALCON_INIT_VAR(namespaces);
	phalcon_read_property(&namespaces, this_ptr, SL("_namespaces"), PH_NOISY_CC);
	if (Z_TYPE_P(namespaces) == IS_ARRAY) { 
		
		if (!phalcon_valid_foreach(namespaces TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(namespaces);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		
		ph_cycle_start_0:
		
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto ph_cycle_end_0;
			}
			
			PHALCON_INIT_VAR(preffix);
			PHALCON_GET_FOREACH_KEY(preffix, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(directory);
			
			PHALCON_INIT_VAR(preffix_len);
			PHALCON_CALL_FUNC_PARAMS_1(preffix_len, "strlen", preffix);
			
			PHALCON_INIT_VAR(possible_preffix);
			PHALCON_CALL_FUNC_PARAMS_3(possible_preffix, "substr", class_name, zero, preffix_len);
			
			PHALCON_INIT_VAR(r0);
			is_equal_function(r0, possible_preffix, preffix TSRMLS_CC);
			if (zend_is_true(r0)) {
				PHALCON_INIT_VAR(prefix_namespace);
				PHALCON_CONCAT_VV(prefix_namespace, preffix, namespace_separator);
				
				PHALCON_INIT_VAR(file_name);
				phalcon_fast_str_replace(file_name, prefix_namespace, empty_str, class_name TSRMLS_CC);
				if (zend_is_true(file_name)) {
					
					if (!phalcon_valid_foreach(extensions TSRMLS_CC)) {
						return;
					}
					
					ah1 = Z_ARRVAL_P(extensions);
					zend_hash_internal_pointer_reset_ex(ah1, &hp1);
					
					ph_cycle_start_1:
					
						if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
							goto ph_cycle_end_1;
						}
						
						PHALCON_GET_FOREACH_VALUE(extension);
						
						PHALCON_INIT_VAR(complete_path);
						PHALCON_CONCAT_VVSV(complete_path, directory, file_name, ".", extension);
						
						PHALCON_INIT_VAR(path);
						phalcon_fast_str_replace(path, namespace_separator, ds, complete_path TSRMLS_CC);
						if (Z_TYPE_P(events_manager) == IS_OBJECT) {
							phalcon_update_property_zval(this_ptr, SL("_checkedPath"), path TSRMLS_CC);
							
							PHALCON_INIT_VAR(event_name);
							ZVAL_STRING(event_name, "loader:beforeCheckPath", 1);
							PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
						}
						
						if (phalcon_file_exists(path TSRMLS_CC) == SUCCESS) {
							if (Z_TYPE_P(events_manager) == IS_OBJECT) {
								phalcon_update_property_zval(this_ptr, SL("_foundPath"), file_path TSRMLS_CC);
								
								PHALCON_INIT_VAR(event_name);
								ZVAL_STRING(event_name, "loader:pathFound", 1);
								PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
							}
							if (phalcon_require(path TSRMLS_CC) == FAILURE) {
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
	
	PHALCON_INIT_VAR(prefixes);
	phalcon_read_property(&prefixes, this_ptr, SL("_prefixes"), PH_NOISY_CC);
	if (Z_TYPE_P(prefixes) == IS_ARRAY) { 
		
		if (!phalcon_valid_foreach(prefixes TSRMLS_CC)) {
			return;
		}
		
		ah2 = Z_ARRVAL_P(prefixes);
		zend_hash_internal_pointer_reset_ex(ah2, &hp2);
		
		ph_cycle_start_2:
		
			if(zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS){
				goto ph_cycle_end_2;
			}
			
			PHALCON_INIT_VAR(preffix);
			PHALCON_GET_FOREACH_KEY(preffix, ah2, hp2);
			PHALCON_GET_FOREACH_VALUE(directory);
			
			PHALCON_INIT_VAR(preffix_len);
			PHALCON_CALL_FUNC_PARAMS_1(preffix_len, "strlen", preffix);
			
			PHALCON_INIT_VAR(possible_preffix);
			PHALCON_CALL_FUNC_PARAMS_3(possible_preffix, "substr", class_name, zero, preffix_len);
			
			PHALCON_INIT_VAR(r1);
			is_equal_function(r1, possible_preffix, preffix TSRMLS_CC);
			if (zend_is_true(r1)) {
				PHALCON_INIT_VAR(file_name);
				phalcon_fast_str_replace(file_name, preffix, empty_str, class_name TSRMLS_CC);
				if (zend_is_true(file_name)) {
					
					if (!phalcon_valid_foreach(extensions TSRMLS_CC)) {
						return;
					}
					
					ah3 = Z_ARRVAL_P(extensions);
					zend_hash_internal_pointer_reset_ex(ah3, &hp3);
					
					ph_cycle_start_3:
					
						if(zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) != SUCCESS){
							goto ph_cycle_end_3;
						}
						
						PHALCON_GET_FOREACH_VALUE(extension);
						
						PHALCON_INIT_VAR(complete_path);
						PHALCON_CONCAT_VVSV(complete_path, directory, file_name, ".", extension);
						
						PHALCON_INIT_VAR(path);
						phalcon_fast_str_replace(path, namespace_separator, ds, complete_path TSRMLS_CC);
						if (Z_TYPE_P(events_manager) == IS_OBJECT) {
							phalcon_update_property_zval(this_ptr, SL("_checkedPath"), path TSRMLS_CC);
							
							PHALCON_INIT_VAR(event_name);
							ZVAL_STRING(event_name, "loader:beforeCheckPath", 1);
							PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
						}
						
						if (phalcon_file_exists(path TSRMLS_CC) == SUCCESS) {
							if (Z_TYPE_P(events_manager) == IS_OBJECT) {
								phalcon_update_property_zval(this_ptr, SL("_foundPath"), file_path TSRMLS_CC);
								
								PHALCON_INIT_VAR(event_name);
								ZVAL_STRING(event_name, "loader:pathFound", 1);
								PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
							}
							if (phalcon_require(path TSRMLS_CC) == FAILURE) {
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
	phalcon_fast_str_replace(ds_class_name, namespace_separator, ds, class_name TSRMLS_CC);
	
	PHALCON_INIT_VAR(directories);
	phalcon_read_property(&directories, this_ptr, SL("_directories"), PH_NOISY_CC);
	if (Z_TYPE_P(directories) == IS_ARRAY) { 
		
		if (!phalcon_valid_foreach(directories TSRMLS_CC)) {
			return;
		}
		
		ah4 = Z_ARRVAL_P(directories);
		zend_hash_internal_pointer_reset_ex(ah4, &hp4);
		
		ph_cycle_start_4:
		
			if(zend_hash_get_current_data_ex(ah4, (void**) &hd, &hp4) != SUCCESS){
				goto ph_cycle_end_4;
			}
			
			PHALCON_GET_FOREACH_VALUE(directory);
			
			
			if (!phalcon_valid_foreach(extensions TSRMLS_CC)) {
				return;
			}
			
			ah5 = Z_ARRVAL_P(extensions);
			zend_hash_internal_pointer_reset_ex(ah5, &hp5);
			
			ph_cycle_start_5:
			
				if(zend_hash_get_current_data_ex(ah5, (void**) &hd, &hp5) != SUCCESS){
					goto ph_cycle_end_5;
				}
				
				PHALCON_GET_FOREACH_VALUE(extension);
				
				PHALCON_INIT_VAR(path);
				PHALCON_CONCAT_VVSV(path, directory, ds_class_name, ".", extension);
				if (Z_TYPE_P(events_manager) == IS_OBJECT) {
					phalcon_update_property_zval(this_ptr, SL("_checkedPath"), path TSRMLS_CC);
					
					PHALCON_INIT_VAR(event_name);
					ZVAL_STRING(event_name, "loader:beforeCheckPath", 1);
					PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
				}
				
				if (phalcon_file_exists(path TSRMLS_CC) == SUCCESS) {
					if (phalcon_require(path TSRMLS_CC) == FAILURE) {
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
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "loader:afterCheckClass", 1);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
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

	zval *found_path = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(found_path);
	phalcon_read_property(&found_path, this_ptr, SL("_foundPath"), PH_NOISY_CC);
	
	RETURN_CCTOR(found_path);
}

/**
 * Get the path the loader is checking
 *
 * @return string
 */
PHP_METHOD(Phalcon_Loader, getCheckedPath){

	zval *checked_path = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(checked_path);
	phalcon_read_property(&checked_path, this_ptr, SL("_checkedPath"), PH_NOISY_CC);
	
	RETURN_CCTOR(checked_path);
}

