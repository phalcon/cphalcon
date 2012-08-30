
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

#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/operators.h"

/**
 * Phalcon\Acl\Adapter\Memory
 *
 * Manages ACL lists in memory
 */

PHP_METHOD(Phalcon_Acl_Adapter_Memory, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL, *a6 = NULL;
	zval *a7 = NULL;

	PHALCON_MM_GROW();

	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_acl_adapter_memory_ce, this_ptr, SL("_rolesNames"), a0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a1);
	array_init(a1);
	zend_update_property(phalcon_acl_adapter_memory_ce, this_ptr, SL("_roles"), a1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a2);
	array_init(a2);
	zend_update_property(phalcon_acl_adapter_memory_ce, this_ptr, SL("_resources"), a2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a3);
	array_init(a3);
	zend_update_property(phalcon_acl_adapter_memory_ce, this_ptr, SL("_access"), a3 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a4);
	array_init(a4);
	zend_update_property(phalcon_acl_adapter_memory_ce, this_ptr, SL("_roleInherits"), a4 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a5);
	array_init(a5);
	add_assoc_bool_ex(a5, SL("*")+1, 1);
	zend_update_property(phalcon_acl_adapter_memory_ce, this_ptr, SL("_resourcesNames"), a5 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a6);
	array_init(a6);
	
	PHALCON_ALLOC_ZVAL_MM(a7);
	array_init(a7);
	add_assoc_bool_ex(a7, SL("*")+1, 1);
	phalcon_array_update_string(&a6, SL("*"), &a7, PH_COPY | PH_SEPARATE TSRMLS_CC);
	zend_update_property(phalcon_acl_adapter_memory_ce, this_ptr, SL("_accessList"), a6 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
 *
 * @param int $defaultAccess
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, setDefaultAction){

	zval *default_access = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &default_access) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultAccess"), default_access TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the default ACL access level
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getDefaultAction){

	zval *default_access = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(default_access);
	phalcon_read_property(&default_access, this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
	
	RETURN_CCTOR(default_access);
}

/**
 * Adds a role to the ACL list. Second parameter lets to inherit access data from other existing role
 *
 * Example:
 * 
 * @param  string $roleObject
 * @param  array $accessInherits
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addRole){

	zval *role_object = NULL, *access_inherits = NULL, *role_name = NULL;
	zval *object = NULL, *roles_names = NULL, *default_access = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &role_object, &access_inherits) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!access_inherits) {
		PHALCON_ALLOC_ZVAL_MM(access_inherits);
		ZVAL_NULL(access_inherits);
	}
	
	if (Z_TYPE_P(role_object) == IS_OBJECT) {
		PHALCON_INIT_VAR(role_name);
		PHALCON_CALL_METHOD(role_name, role_object, "getname", PH_NO_CHECK);
		PHALCON_CPY_WRT(object, role_object);
	} else {
		PHALCON_CPY_WRT(role_name, role_object);
		
		PHALCON_INIT_VAR(object);
		object_init_ex(object, phalcon_acl_role_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(object, "__construct", role_name, PH_CHECK);
	}
	
	PHALCON_INIT_VAR(roles_names);
	phalcon_read_property(&roles_names, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(roles_names, role_name);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_roles"), PH_NOISY_CC);
	phalcon_array_append(&t0, object, 0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_roles"), t0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	phalcon_array_update_zval_bool(&t1, role_name, 1, 0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_rolesNames"), t1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(default_access);
	phalcon_read_property(&default_access, this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_access"), PH_NOISY_CC);
	if (Z_TYPE_P(t2) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_array_fetch(&t3, t2, role_name, PH_SILENT_CC);
	}
	if (Z_REFCOUNT_P(t3) > 1) {
		phalcon_array_update_zval(&t2, role_name, &t3, PH_COPY | PH_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t3) != IS_ARRAY) {
		convert_to_array(t3);
		phalcon_array_update_zval(&t2, role_name, &t3, PH_COPY TSRMLS_CC);
	}
	if (Z_TYPE_P(t3) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t4);
		phalcon_array_fetch_string(&t4, t3, SL("*"), PH_SILENT_CC);
	}
	if (Z_REFCOUNT_P(t4) > 1) {
		phalcon_array_update_string(&t3, SL("*"), &t4, PH_COPY | PH_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t4) != IS_ARRAY) {
		convert_to_array(t4);
		phalcon_array_update_string(&t3, SL("*"), &t4, PH_COPY TSRMLS_CC);
	}
	phalcon_array_update_string(&t4, SL("*"), &default_access, PH_COPY TSRMLS_CC);
	if (zend_is_true(access_inherits)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD_PARAMS_2(r0, this_ptr, "addinherit", role_name, access_inherits, PH_NO_CHECK);
		RETURN_CTOR(r0);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Do a role inherit from another existing role
 *
 * @param string $roleName
 * @param string $roleToInherit
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit){

	zval *role_name = NULL, *role_to_inherit = NULL, *roles_names = NULL;
	zval *exception_message = NULL, *exception = NULL, *is_the_same = NULL;
	zval *roles_inherits = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &role_name, &role_to_inherit) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(roles_names);
	phalcon_read_property(&roles_names, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(roles_names, role_name);
	if (!eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	eval_int = phalcon_array_isset(roles_names, role_to_inherit);
	if (!eval_int) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Role '", role_to_inherit, "' does not exist in the role list");
		
		PHALCON_INIT_VAR(exception);
		object_init_ex(exception, phalcon_acl_exception_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_message, PH_CHECK);
		phalcon_throw_exception(exception TSRMLS_CC);
		return;
	}
	
	PHALCON_INIT_VAR(is_the_same);
	is_equal_function(is_the_same, role_to_inherit, role_name TSRMLS_CC);
	if (zend_is_true(is_the_same)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_INIT_VAR(roles_inherits);
	phalcon_read_property(&roles_inherits, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(roles_inherits, role_name);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
		phalcon_array_update_zval(&t0, role_name, &a0, PH_COPY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_roleInherits"), t0 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
	phalcon_array_update_multi_append_2(&t1, role_name, role_to_inherit, 0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_roleInherits"), t1 TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_rebuildaccesslist", PH_NO_CHECK);
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Check whether role exist in the roles list
 *
 * @param  string $roleName
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isRole){

	zval *role_name = NULL, *roles_names = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &role_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(roles_names);
	phalcon_read_property(&roles_names, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(roles_names, role_name);
	
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	
	RETURN_NCTOR(r0);
}

/**
 * Check whether resource exist in the resources list
 *
 * @param  string $resourceName
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isResource){

	zval *resource_name = NULL, *resources_names = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &resource_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(resources_names);
	phalcon_read_property(&resources_names, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(resources_names, resource_name);
	
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	
	RETURN_NCTOR(r0);
}

/**
 * Adds a resource to the ACL list
 *
 * Access names can be a particular action, by example
 * search, update, delete, etc or a list of them
 *
 * Example:
 * 
 * @param   Phalcon\Acl\Resource $resource
 * @return  boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResource){

	zval *resource = NULL, *access_list = NULL, *resource_name = NULL;
	zval *object = NULL, *resources_names = NULL, *status = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &resource, &access_list) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!access_list) {
		PHALCON_INIT_VAR(access_list);
		array_init(access_list);
	}
	
	if (Z_TYPE_P(resource) == IS_OBJECT) {
		PHALCON_INIT_VAR(resource_name);
		PHALCON_CALL_METHOD(resource_name, resource, "getname", PH_NO_CHECK);
		PHALCON_CPY_WRT(object, resource);
	} else {
		PHALCON_CPY_WRT(resource_name, resource);
		
		PHALCON_INIT_VAR(object);
		object_init_ex(object, phalcon_acl_resource_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(object, "__construct", resource_name, PH_CHECK);
	}
	
	PHALCON_INIT_VAR(resources_names);
	phalcon_read_property(&resources_names, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(resources_names, resource_name);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, SL("_resources"), PH_NOISY_CC);
		phalcon_array_append(&t0, object, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_resources"), t0 TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(a0);
		array_init(a0);
		
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_accessList"), PH_NOISY_CC);
		phalcon_array_update_zval(&t1, resource_name, &a0, PH_COPY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_accessList"), t1 TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
		phalcon_array_update_zval_bool(&t2, resource_name, 1, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_resourcesNames"), t2 TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_METHOD_PARAMS_2(status, this_ptr, "addresourceaccess", resource_name, access_list, PH_NO_CHECK);
	
	RETURN_CCTOR(status);
}

/**
 * Adds access to resources
 *
 * @param string $resourceName
 * @param mixed $accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResourceAccess){

	zval *resource_name = NULL, *access_list = NULL, *access_name = NULL;
	zval *internal_access_list = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &resource_name, &access_list) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, resource_name);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_SVS(r0, "Resource '", resource_name, "' does not exist in ACL");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r0, PH_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	if (Z_TYPE_P(access_list) == IS_ARRAY) { 
		if (!phalcon_valid_foreach(access_list TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(access_list);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_c945_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_c945_0;
			}
			
			PHALCON_INIT_VAR(access_name);
			ZVAL_ZVAL(access_name, *hd, 1, 0);
			PHALCON_INIT_VAR(internal_access_list);
			phalcon_read_property(&internal_access_list, this_ptr, SL("_accessList"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(r1);
			phalcon_array_fetch(&r1, internal_access_list, resource_name, PH_NOISY_CC);
			eval_int = phalcon_array_isset(r1, access_name);
			if (!eval_int) {
				PHALCON_INIT_VAR(t1);
				phalcon_read_property(&t1, this_ptr, SL("_accessList"), PH_NOISY_CC);
				PHALCON_INIT_VAR(t2);
				ZVAL_LONG(t2, 1);
				phalcon_array_update_multi_2(&t1, resource_name, access_name, &t2, 0 TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, SL("_accessList"), t1 TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_c945_0;
		fee_c945_0:
		if(0){}
		
	} else {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, SL("_accessList"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch(&r2, t3, resource_name, PH_NOISY_CC);
		eval_int = phalcon_array_isset(r2, access_list);
		if (!eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t4);
			phalcon_read_property(&t4, this_ptr, SL("_accessList"), PH_NOISY_CC);
			PHALCON_INIT_VAR(t5);
			ZVAL_LONG(t5, 1);
			phalcon_array_update_multi_2(&t4, resource_name, access_list, &t5, 0 TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, SL("_accessList"), t4 TSRMLS_CC);
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Removes an access from a resource
 *
 * @param string $resourceName
 * @param mixed $accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, dropResourceAccess){

	zval *resource_name = NULL, *access_list = NULL, *access_name = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &resource_name, &access_list) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(access_list) == IS_ARRAY) { 
		if (!phalcon_valid_foreach(access_list TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(access_list);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_c945_1:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_c945_1;
			}
			
			PHALCON_INIT_VAR(access_name);
			ZVAL_ZVAL(access_name, *hd, 1, 0);
			PHALCON_INIT_VAR(t0);
			phalcon_read_property(&t0, this_ptr, SL("_accessList"), PH_NOISY_CC);
			PHALCON_INIT_VAR(r0);
			phalcon_array_fetch(&r0, t0, resource_name, PH_NOISY_CC);
			PHALCON_SEPARATE_NMO(r0);
			phalcon_array_unset(r0, access_name);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_c945_1;
		fee_c945_1:
		if(0){}
		
	} else {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_accessList"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch(&r1, t1, resource_name, PH_NOISY_CC);
		PHALCON_SEPARATE_NMO(r1);
		phalcon_array_unset(r1, access_list);
	}
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_rebuildaccesslist", PH_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Acl_Adapter_Memory, _allowOrDeny){

	zval *role_name = NULL, *resource_name = NULL, *access = NULL, *action = NULL;
	zval *roles_names = NULL, *exception_message = NULL, *exception = NULL;
	zval *resources_names = NULL, *default_access = NULL, *access_list = NULL;
	zval *access_name = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL, *t15 = NULL, *t16 = NULL, *t17 = NULL, *t18 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &role_name, &resource_name, &access, &action) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(roles_names);
	phalcon_read_property(&roles_names, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(roles_names, role_name);
	if (!eval_int) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Role \"", role_name, "\" does not exist in ACL");
		
		PHALCON_INIT_VAR(exception);
		object_init_ex(exception, phalcon_acl_exception_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_message, PH_CHECK);
		phalcon_throw_exception(exception TSRMLS_CC);
		return;
	}
	
	PHALCON_INIT_VAR(resources_names);
	phalcon_read_property(&resources_names, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(resources_names, resource_name);
	if (!eval_int) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Resource \"", resource_name, "\" does not exist in ACL");
		
		PHALCON_INIT_VAR(exception);
		object_init_ex(exception, phalcon_acl_exception_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_message, PH_CHECK);
		phalcon_throw_exception(exception TSRMLS_CC);
		return;
	}
	
	PHALCON_INIT_VAR(default_access);
	phalcon_read_property(&default_access, this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
	if (Z_TYPE_P(access) == IS_ARRAY) { 
		PHALCON_INIT_VAR(access_list);
		phalcon_read_property(&access_list, this_ptr, SL("_accessList"), PH_NOISY_CC);
		if (!phalcon_valid_foreach(access TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(access);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_c945_2:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_c945_2;
			}
			
			PHALCON_INIT_VAR(access_name);
			ZVAL_ZVAL(access_name, *hd, 1, 0);
			PHALCON_INIT_VAR(r0);
			phalcon_array_fetch(&r0, access_list, resource_name, PH_NOISY_CC);
			eval_int = phalcon_array_isset(r0, access_name);
			if (!eval_int) {
				PHALCON_INIT_VAR(exception_message);
				PHALCON_CONCAT_SVSVS(exception_message, "Acccess '", access_name, "' does not exist in resource '", resource_name, "' in ACL");
				
				PHALCON_INIT_VAR(exception);
				object_init_ex(exception, phalcon_acl_exception_ce);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_message, PH_CHECK);
				phalcon_throw_exception(exception TSRMLS_CC);
				return;
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_c945_2;
		fee_c945_2:
		
		if (!phalcon_valid_foreach(access TSRMLS_CC)) {
			return;
		}
		
		ah1 = Z_ARRVAL_P(access);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
		fes_c945_3:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_c945_3;
			}
			
			PHALCON_INIT_VAR(access_name);
			ZVAL_ZVAL(access_name, *hd, 1, 0);
			PHALCON_INIT_VAR(t0);
			phalcon_read_property(&t0, this_ptr, SL("_access"), PH_NOISY_CC);
			PHALCON_INIT_VAR(r1);
			phalcon_array_fetch(&r1, t0, role_name, PH_NOISY_CC);
			eval_int = phalcon_array_isset(r1, resource_name);
			if (!eval_int) {
				PHALCON_INIT_VAR(a0);
				array_init(a0);
				PHALCON_INIT_VAR(t1);
				phalcon_read_property(&t1, this_ptr, SL("_access"), PH_NOISY_CC);
				phalcon_array_update_multi_2(&t1, role_name, resource_name, &a0, 0 TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, SL("_access"), t1 TSRMLS_CC);
			}
			
			PHALCON_INIT_VAR(t2);
			phalcon_read_property(&t2, this_ptr, SL("_access"), PH_NOISY_CC);
			if (Z_TYPE_P(t2) == IS_ARRAY) {
				PHALCON_INIT_VAR(t3);
				phalcon_array_fetch(&t3, t2, role_name, PH_SILENT_CC);
			}
			if (Z_REFCOUNT_P(t3) > 1) {
				phalcon_array_update_zval(&t2, role_name, &t3, PH_COPY | PH_CTOR TSRMLS_CC);
			}
			if (Z_TYPE_P(t3) != IS_ARRAY) {
				convert_to_array(t3);
				phalcon_array_update_zval(&t2, role_name, &t3, PH_COPY TSRMLS_CC);
			}
			if (Z_TYPE_P(t3) == IS_ARRAY) {
				PHALCON_INIT_VAR(t4);
				phalcon_array_fetch(&t4, t3, resource_name, PH_SILENT_CC);
			}
			if (Z_REFCOUNT_P(t4) > 1) {
				phalcon_array_update_zval(&t3, resource_name, &t4, PH_COPY | PH_CTOR TSRMLS_CC);
			}
			if (Z_TYPE_P(t4) != IS_ARRAY) {
				convert_to_array(t4);
				phalcon_array_update_zval(&t3, resource_name, &t4, PH_COPY TSRMLS_CC);
			}
			phalcon_array_update_zval(&t4, access_name, &action, PH_COPY TSRMLS_CC);
			
			PHALCON_INIT_VAR(t5);
			phalcon_read_property(&t5, this_ptr, SL("_access"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(r2);
			phalcon_array_fetch(&r2, t5, role_name, PH_NOISY_CC);
			
			PHALCON_INIT_VAR(r3);
			phalcon_array_fetch(&r3, r2, resource_name, PH_NOISY_CC);
			eval_int = phalcon_array_isset_string(r3, SL("*")+1);
			if (!eval_int) {
				PHALCON_INIT_VAR(t6);
				phalcon_read_property(&t6, this_ptr, SL("_access"), PH_NOISY_CC);
				if (Z_TYPE_P(t6) == IS_ARRAY) {
					PHALCON_INIT_VAR(t7);
					phalcon_array_fetch(&t7, t6, role_name, PH_SILENT_CC);
				}
				if (Z_REFCOUNT_P(t7) > 1) {
					phalcon_array_update_zval(&t6, role_name, &t7, PH_COPY | PH_CTOR TSRMLS_CC);
				}
				if (Z_TYPE_P(t7) != IS_ARRAY) {
					convert_to_array(t7);
					phalcon_array_update_zval(&t6, role_name, &t7, PH_COPY TSRMLS_CC);
				}
				if (Z_TYPE_P(t7) == IS_ARRAY) {
					PHALCON_INIT_VAR(t8);
					phalcon_array_fetch(&t8, t7, resource_name, PH_SILENT_CC);
				}
				if (Z_REFCOUNT_P(t8) > 1) {
					phalcon_array_update_zval(&t7, resource_name, &t8, PH_COPY | PH_CTOR TSRMLS_CC);
				}
				if (Z_TYPE_P(t8) != IS_ARRAY) {
					convert_to_array(t8);
					phalcon_array_update_zval(&t7, resource_name, &t8, PH_COPY TSRMLS_CC);
				}
				phalcon_array_update_string(&t8, SL("*"), &default_access, PH_COPY TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_c945_3;
		fee_c945_3:
		if(0){}
		
	} else {
		if (!PHALCON_COMPARE_STRING(access, "*")) {
			PHALCON_ALLOC_ZVAL_MM(t9);
			phalcon_read_property(&t9, this_ptr, SL("_accessList"), PH_NOISY_CC);
			PHALCON_ALLOC_ZVAL_MM(r4);
			phalcon_array_fetch(&r4, t9, resource_name, PH_NOISY_CC);
			eval_int = phalcon_array_isset(r4, access);
			if (!eval_int) {
				PHALCON_INIT_VAR(exception_message);
				PHALCON_CONCAT_SVSVS(exception_message, "Acccess '", access, "' does not exist in resource '", resource_name, "' in ACL");
				
				PHALCON_INIT_VAR(exception);
				object_init_ex(exception, phalcon_acl_exception_ce);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_message, PH_CHECK);
				phalcon_throw_exception(exception TSRMLS_CC);
				return;
			}
		}
		
		PHALCON_ALLOC_ZVAL_MM(t10);
		phalcon_read_property(&t10, this_ptr, SL("_access"), PH_NOISY_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r5);
		phalcon_array_fetch(&r5, t10, role_name, PH_NOISY_CC);
		eval_int = phalcon_array_isset(r5, resource_name);
		if (!eval_int) {
			PHALCON_ALLOC_ZVAL_MM(a1);
			array_init(a1);
			PHALCON_ALLOC_ZVAL_MM(t11);
			phalcon_read_property(&t11, this_ptr, SL("_access"), PH_NOISY_CC);
			phalcon_array_update_multi_2(&t11, role_name, resource_name, &a1, 0 TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, SL("_access"), t11 TSRMLS_CC);
		}
		
		PHALCON_ALLOC_ZVAL_MM(t12);
		phalcon_read_property(&t12, this_ptr, SL("_access"), PH_NOISY_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r6);
		phalcon_array_fetch(&r6, t12, role_name, PH_NOISY_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r7);
		phalcon_array_fetch(&r7, r6, resource_name, PH_NOISY_CC);
		eval_int = phalcon_array_isset_string(r7, SL("*")+1);
		if (!eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t13);
			phalcon_read_property(&t13, this_ptr, SL("_access"), PH_NOISY_CC);
			if (Z_TYPE_P(t13) == IS_ARRAY) {
				PHALCON_ALLOC_ZVAL_MM(t14);
				phalcon_array_fetch(&t14, t13, role_name, PH_SILENT_CC);
			}
			if (Z_REFCOUNT_P(t14) > 1) {
				phalcon_array_update_zval(&t13, role_name, &t14, PH_COPY | PH_CTOR TSRMLS_CC);
			}
			if (Z_TYPE_P(t14) != IS_ARRAY) {
				convert_to_array(t14);
				phalcon_array_update_zval(&t13, role_name, &t14, PH_COPY TSRMLS_CC);
			}
			if (Z_TYPE_P(t14) == IS_ARRAY) {
				PHALCON_ALLOC_ZVAL_MM(t15);
				phalcon_array_fetch(&t15, t14, resource_name, PH_SILENT_CC);
			}
			if (Z_REFCOUNT_P(t15) > 1) {
				phalcon_array_update_zval(&t14, resource_name, &t15, PH_COPY | PH_CTOR TSRMLS_CC);
			}
			if (Z_TYPE_P(t15) != IS_ARRAY) {
				convert_to_array(t15);
				phalcon_array_update_zval(&t14, resource_name, &t15, PH_COPY TSRMLS_CC);
			}
			phalcon_array_update_string(&t15, SL("*"), &default_access, PH_COPY TSRMLS_CC);
		}
		
		PHALCON_ALLOC_ZVAL_MM(t16);
		phalcon_read_property(&t16, this_ptr, SL("_access"), PH_NOISY_CC);
		if (Z_TYPE_P(t16) == IS_ARRAY) {
			PHALCON_ALLOC_ZVAL_MM(t17);
			phalcon_array_fetch(&t17, t16, role_name, PH_SILENT_CC);
		}
		if (Z_REFCOUNT_P(t17) > 1) {
			phalcon_array_update_zval(&t16, role_name, &t17, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(t17) != IS_ARRAY) {
			convert_to_array(t17);
			phalcon_array_update_zval(&t16, role_name, &t17, PH_COPY TSRMLS_CC);
		}
		if (Z_TYPE_P(t17) == IS_ARRAY) {
			PHALCON_ALLOC_ZVAL_MM(t18);
			phalcon_array_fetch(&t18, t17, resource_name, PH_SILENT_CC);
		}
		if (Z_REFCOUNT_P(t18) > 1) {
			phalcon_array_update_zval(&t17, resource_name, &t18, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(t18) != IS_ARRAY) {
			convert_to_array(t18);
			phalcon_array_update_zval(&t17, resource_name, &t18, PH_COPY TSRMLS_CC);
		}
		phalcon_array_update_zval(&t18, access, &action, PH_COPY TSRMLS_CC);
	}
	
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_rebuildaccesslist", PH_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * Allow access to a role on a resource
 *
 * You can use '*' as wildcard
 *
 * Ej:
 * 
 * @param string $roleName
 * @param string $resourceName
 * @param mixed $access
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow){

	zval *role_name = NULL, *resource_name = NULL, *access = NULL, *status = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &role_name, &resource_name, &access) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(c0);
	ZVAL_LONG(c0, 1);
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_METHOD_PARAMS_4(status, this_ptr, "_allowordeny", role_name, resource_name, access, c0, PH_NO_CHECK);
	
	RETURN_CCTOR(status);
}

/**
 * Deny access to a role on a resource
 *
 * You can use '*' as wildcard
 *
 * Ej:
 * 
 * @param string $roleName
 * @param string $resourceName
 * @param mixed $access
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, deny){

	zval *role_name = NULL, *resource_name = NULL, *access = NULL, *status = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &role_name, &resource_name, &access) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(c0);
	ZVAL_LONG(c0, 0);
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_METHOD_PARAMS_4(status, this_ptr, "_allowordeny", role_name, resource_name, access, c0, PH_NO_CHECK);
	
	RETURN_CCTOR(status);
}

/**
 * Check whether a role is allowed to access an action from a resource
 *
 * @param  string $role
 * @param  string $resource
 * @param  string $accessList
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed){

	zval *role = NULL, *resource = NULL, *access = NULL, *default_access = NULL;
	zval *events_manager = NULL, *event_name = NULL, *status = NULL, *resources_names = NULL;
	zval *roles_names = NULL, *have_access = NULL, *access_roles = NULL;
	zval *resource_access = NULL, *resource_name = NULL, *same_resource = NULL;
	zval *t0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &role, &resource, &access) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_activeRole"), role TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_activeResource"), resource TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_activeAccess"), access TSRMLS_CC);
	
	PHALCON_INIT_VAR(default_access);
	phalcon_read_property(&default_access, this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "acl:beforeCheckAccess", 1);
		
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
		if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
			
			RETURN_CCTOR(default_access);
		}
	}
	
	PHALCON_INIT_VAR(resources_names);
	phalcon_read_property(&resources_names, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(resources_names, resource);
	if (!eval_int) {
		
		RETURN_CCTOR(default_access);
	}
	
	PHALCON_INIT_VAR(roles_names);
	phalcon_read_property(&roles_names, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(roles_names, role);
	if (!eval_int) {
		
		RETURN_CCTOR(default_access);
	}
	
	PHALCON_INIT_VAR(have_access);
	ZVAL_NULL(have_access);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_access"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(access_roles);
	phalcon_array_fetch(&access_roles, t0, role, PH_NOISY_CC);
	if (!phalcon_valid_foreach(access_roles TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(access_roles);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_c945_4:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_c945_4;
		}
		
		PHALCON_INIT_VAR(resource_name);
		PHALCON_GET_FOREACH_KEY(resource_name, ah0, hp0);
		PHALCON_INIT_VAR(resource_access);
		ZVAL_ZVAL(resource_access, *hd, 1, 0);
		PHALCON_INIT_VAR(same_resource);
		is_equal_function(same_resource, resource_name, resource TSRMLS_CC);
		if (Z_TYPE_P(same_resource) == IS_BOOL && Z_BVAL_P(same_resource)) {
			eval_int = phalcon_array_isset(resource_access, access);
			if (eval_int) {
				PHALCON_INIT_VAR(have_access);
				phalcon_array_fetch(&have_access, resource_access, access, PH_NOISY_CC);
				goto fee_c945_4;
			}
			
			PHALCON_INIT_VAR(have_access);
			phalcon_array_fetch_string(&have_access, resource_access, SL("*"), PH_NOISY_CC);
			goto fee_c945_4;
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_c945_4;
	fee_c945_4:
	
	if (Z_TYPE_P(have_access) == IS_NULL) {
		if (!phalcon_valid_foreach(access_roles TSRMLS_CC)) {
			return;
		}
		
		ah1 = Z_ARRVAL_P(access_roles);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
		fes_c945_5:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_c945_5;
			}
			
			PHALCON_INIT_VAR(resource_name);
			PHALCON_GET_FOREACH_KEY(resource_name, ah1, hp1);
			PHALCON_INIT_VAR(resource_access);
			ZVAL_ZVAL(resource_access, *hd, 1, 0);
			eval_int = phalcon_array_isset_string(resource_access, SL("*")+1);
			if (eval_int) {
				eval_int = phalcon_array_isset(resource_access, access);
				if (eval_int) {
					PHALCON_INIT_VAR(have_access);
					phalcon_array_fetch(&have_access, resource_access, access, PH_NOISY_CC);
					goto fee_c945_5;
				}
				
				PHALCON_INIT_VAR(have_access);
				phalcon_array_fetch_string(&have_access, resource_access, SL("*"), PH_NOISY_CC);
				goto fee_c945_5;
			}
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_c945_5;
		fee_c945_5:
		if(0){}
		
	}
	
	phalcon_update_property_zval(this_ptr, SL("_accessGranted"), have_access TSRMLS_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "acl:afterCheckAccess", 1);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
	}
	
	if (Z_TYPE_P(have_access) == IS_NULL) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(0);
	}
	
	
	RETURN_CCTOR(have_access);
}

PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveRole){

	zval *role = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(role);
	phalcon_read_property(&role, this_ptr, SL("_activeRole"), PH_NOISY_CC);
	
	RETURN_CCTOR(role);
}

PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveResource){

	zval *resource = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(resource);
	phalcon_read_property(&resource, this_ptr, SL("_activeResource"), PH_NOISY_CC);
	
	RETURN_CCTOR(resource);
}

PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveAccess){

	zval *access = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(access);
	phalcon_read_property(&access, this_ptr, SL("_activeAccess"), PH_NOISY_CC);
	
	RETURN_CCTOR(access);
}

/**
 * Rebuild the list of access from the inherit lists
 *
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, _rebuildAccessList){

	zval *roles = NULL, *number_roles = NULL, *pow_roles = NULL, *middle_roles = NULL;
	zval *middle = NULL, *roles_names = NULL, *roles_inherits = NULL;
	zval *i = NULL, *internal_access = NULL, *one = NULL, *role_name = NULL, *role_inherit = NULL;
	zval *inherit_internal = NULL, *access = NULL, *resource_name = NULL;
	zval *value = NULL, *name = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0, *ah1, *ah2, *ah3;
	HashPosition hp0, hp1, hp2, hp3;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(roles);
	phalcon_read_property(&roles, this_ptr, SL("_roles"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(number_roles);
	phalcon_fast_count(number_roles, roles TSRMLS_CC);
	
	PHALCON_INIT_VAR(pow_roles);
	mul_function(pow_roles, number_roles, number_roles TSRMLS_CC);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 2);
	
	PHALCON_INIT_VAR(middle_roles);
	div_function(middle_roles, pow_roles, t0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(middle);
	PHALCON_CALL_FUNC_PARAMS_1(middle, "ceil", middle_roles);
	
	PHALCON_INIT_VAR(roles_names);
	phalcon_read_property(&roles_names, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(roles_inherits);
	phalcon_read_property(&roles_inherits, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	fs_c945_6:
		
		PHALCON_INIT_VAR(r0);
		is_smaller_or_equal_function(r0, i, middle TSRMLS_CC);
		if (!zend_is_true(r0)) {
			goto fe_c945_6;
		}
		PHALCON_INIT_VAR(internal_access);
		phalcon_read_property(&internal_access, this_ptr, SL("_access"), PH_NOISY_CC);
		if (!phalcon_valid_foreach(roles_names TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(roles_names);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_c945_7:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_c945_7;
			}
			
			PHALCON_INIT_VAR(role_name);
			PHALCON_GET_FOREACH_KEY(role_name, ah0, hp0);
			PHALCON_INIT_VAR(one);
			ZVAL_ZVAL(one, *hd, 1, 0);
			eval_int = phalcon_array_isset(roles_inherits, role_name);
			if (eval_int) {
				PHALCON_INIT_VAR(r1);
				phalcon_array_fetch(&r1, roles_inherits, role_name, PH_NOISY_CC);
				if (!phalcon_valid_foreach(r1 TSRMLS_CC)) {
					return;
				}
				
				ah1 = Z_ARRVAL_P(r1);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				fes_c945_8:
					if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
						goto fee_c945_8;
					}
					
					PHALCON_INIT_VAR(role_inherit);
					ZVAL_ZVAL(role_inherit, *hd, 1, 0);
					eval_int = phalcon_array_isset(internal_access, role_inherit);
					if (eval_int) {
						PHALCON_INIT_VAR(inherit_internal);
						phalcon_array_fetch(&inherit_internal, internal_access, role_inherit, PH_NOISY_CC);
						if (!phalcon_valid_foreach(inherit_internal TSRMLS_CC)) {
							return;
						}
						
						ah2 = Z_ARRVAL_P(inherit_internal);
						zend_hash_internal_pointer_reset_ex(ah2, &hp2);
						fes_c945_9:
							if(zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS){
								goto fee_c945_9;
							}
							
							PHALCON_INIT_VAR(resource_name);
							PHALCON_GET_FOREACH_KEY(resource_name, ah2, hp2);
							PHALCON_INIT_VAR(access);
							ZVAL_ZVAL(access, *hd, 1, 0);
							if (!phalcon_valid_foreach(access TSRMLS_CC)) {
								return;
							}
							
							ah3 = Z_ARRVAL_P(access);
							zend_hash_internal_pointer_reset_ex(ah3, &hp3);
							fes_c945_10:
								if(zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) != SUCCESS){
									goto fee_c945_10;
								}
								
								PHALCON_INIT_VAR(name);
								PHALCON_GET_FOREACH_KEY(name, ah3, hp3);
								PHALCON_INIT_VAR(value);
								ZVAL_ZVAL(value, *hd, 1, 0);
								PHALCON_INIT_VAR(t1);
								phalcon_read_property(&t1, this_ptr, SL("_access"), PH_NOISY_CC);
								if (Z_TYPE_P(t1) == IS_ARRAY) {
									PHALCON_INIT_VAR(t2);
									phalcon_array_fetch(&t2, t1, role_name, PH_SILENT_CC);
								}
								if (Z_REFCOUNT_P(t2) > 1) {
									phalcon_array_update_zval(&t1, role_name, &t2, PH_COPY | PH_CTOR TSRMLS_CC);
								}
								if (Z_TYPE_P(t2) != IS_ARRAY) {
									convert_to_array(t2);
									phalcon_array_update_zval(&t1, role_name, &t2, PH_COPY TSRMLS_CC);
								}
								if (Z_TYPE_P(t2) == IS_ARRAY) {
									PHALCON_INIT_VAR(t3);
									phalcon_array_fetch(&t3, t2, resource_name, PH_SILENT_CC);
								}
								if (Z_REFCOUNT_P(t3) > 1) {
									phalcon_array_update_zval(&t2, resource_name, &t3, PH_COPY | PH_CTOR TSRMLS_CC);
								}
								if (Z_TYPE_P(t3) != IS_ARRAY) {
									convert_to_array(t3);
									phalcon_array_update_zval(&t2, resource_name, &t3, PH_COPY TSRMLS_CC);
								}
								phalcon_array_update_zval(&t3, name, &value, PH_COPY TSRMLS_CC);
								zend_hash_move_forward_ex(ah3, &hp3);
								goto fes_c945_10;
							fee_c945_10:
							if(0){}
							
							zend_hash_move_forward_ex(ah2, &hp2);
							goto fes_c945_9;
						fee_c945_9:
						if(0){}
						
					}
					zend_hash_move_forward_ex(ah1, &hp1);
					goto fes_c945_8;
				fee_c945_8:
				if(0){}
				
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_c945_7;
		fee_c945_7:
		if(0){}
		
		PHALCON_SEPARATE(i);
		increment_function(i);
		goto fs_c945_6;
	fe_c945_6:
	if(0){}
	
	PHALCON_MM_RESTORE();
}

