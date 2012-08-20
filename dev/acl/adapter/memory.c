
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
#include "kernel/exception.h"
#include "kernel/concat.h"

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

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
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
	zval *object = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
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
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, role_name);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_roles"), PH_NOISY_CC);
	phalcon_array_append(&t1, object, 0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_roles"), t1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	phalcon_array_update_zval_bool(&t2, role_name, 1, 0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_rolesNames"), t2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, SL("_access"), PH_NOISY_CC);
	if (Z_TYPE_P(t4) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_array_fetch(&t5, t4, role_name, PH_SILENT_CC);
	}
	if (Z_REFCOUNT_P(t5) > 1) {
		phalcon_array_update_zval(&t4, role_name, &t5, PH_COPY | PH_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t5) != IS_ARRAY) {
		convert_to_array(t5);
		phalcon_array_update_zval(&t4, role_name, &t5, PH_COPY TSRMLS_CC);
	}
	if (Z_TYPE_P(t5) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t6);
		phalcon_array_fetch_string(&t6, t5, SL("*"), PH_SILENT_CC);
	}
	if (Z_REFCOUNT_P(t6) > 1) {
		phalcon_array_update_string(&t5, SL("*"), &t6, PH_COPY | PH_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t6) != IS_ARRAY) {
		convert_to_array(t6);
		phalcon_array_update_string(&t5, SL("*"), &t6, PH_COPY TSRMLS_CC);
	}
	phalcon_array_update_string(&t6, SL("*"), &t3, PH_COPY TSRMLS_CC);
	if (zend_is_true(access_inherits)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD_PARAMS_2(r0, this_ptr, "addinherit", role_name, access_inherits, PH_NO_CHECK);
		RETURN_CTOR(r0);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Do a role inherit from another existing role
 *
 * @param string $roleName
 * @param string $roleToInherit
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit){

	zval *role_name = NULL, *role_to_inherit = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &role_name, &role_to_inherit) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, role_name);
	if (!eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t1, role_to_inherit);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_SVS(r0, "Role '", role_to_inherit, "' does not exist in the role list");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r0, PH_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, role_to_inherit, role_name TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t2, role_name);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
		phalcon_array_update_zval(&t3, role_name, &a0, PH_COPY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_roleInherits"), t3 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
	phalcon_array_update_multi_append_2(&t4, role_name, role_to_inherit, 0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_roleInherits"), t4 TSRMLS_CC);
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

	zval *role_name = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &role_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, role_name);
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

	zval *resource_name = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &resource_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, resource_name);
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
	zval *object = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL;
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
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, resource_name);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_resources"), PH_NOISY_CC);
		phalcon_array_append(&t1, object, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_resources"), t1 TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(a0);
		array_init(a0);
		
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, SL("_accessList"), PH_NOISY_CC);
		phalcon_array_update_zval(&t2, resource_name, &a0, PH_COPY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_accessList"), t2 TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
		phalcon_array_update_zval_bool(&t3, resource_name, 1, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_resourcesNames"), t3 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, this_ptr, "addresourceaccess", resource_name, access_list, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Adds access to resources
 *
 * @param string $resourceName
 * @param mixed $accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResourceAccess){

	zval *resource_name = NULL, *access_list = NULL, *access_name = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
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
			PHALCON_INIT_VAR(t1);
			phalcon_read_property(&t1, this_ptr, SL("_accessList"), PH_NOISY_CC);
			PHALCON_INIT_VAR(r1);
			phalcon_array_fetch(&r1, t1, resource_name, PH_NOISY_CC);
			eval_int = phalcon_array_isset(r1, access_name);
			if (!eval_int) {
				PHALCON_INIT_VAR(t2);
				phalcon_read_property(&t2, this_ptr, SL("_accessList"), PH_NOISY_CC);
				PHALCON_INIT_VAR(t3);
				ZVAL_LONG(t3, 1);
				phalcon_array_update_multi_2(&t2, resource_name, access_name, &t3, 0 TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, SL("_accessList"), t2 TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_c945_0;
		fee_c945_0:
		if(0){}
		
	} else {
		PHALCON_ALLOC_ZVAL_MM(t4);
		phalcon_read_property(&t4, this_ptr, SL("_accessList"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch(&r2, t4, resource_name, PH_NOISY_CC);
		eval_int = phalcon_array_isset(r2, access_list);
		if (!eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t5);
			phalcon_read_property(&t5, this_ptr, SL("_accessList"), PH_NOISY_CC);
			PHALCON_INIT_VAR(t6);
			ZVAL_LONG(t6, 1);
			phalcon_array_update_multi_2(&t5, resource_name, access_list, &t6, 0 TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, SL("_accessList"), t5 TSRMLS_CC);
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
	zval *access_name = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL, *t15 = NULL, *t16 = NULL, *t17 = NULL, *t18 = NULL, *t19 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &role_name, &resource_name, &access, &action) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, role_name);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_SVS(r0, "Role \"", role_name, "\" does not exist in ACL");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r0, PH_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t1, resource_name);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_acl_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "Resource \"", resource_name, "\" does not exist in ACL");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", r1, PH_CHECK);
		phalcon_throw_exception(i1 TSRMLS_CC);
		return;
	}
	
	if (Z_TYPE_P(access) == IS_ARRAY) { 
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
			PHALCON_INIT_VAR(t2);
			phalcon_read_property(&t2, this_ptr, SL("_accessList"), PH_NOISY_CC);
			PHALCON_INIT_VAR(r2);
			phalcon_array_fetch(&r2, t2, resource_name, PH_NOISY_CC);
			eval_int = phalcon_array_isset(r2, access_name);
			if (!eval_int) {
				PHALCON_INIT_VAR(i2);
				object_init_ex(i2, phalcon_acl_exception_ce);
				PHALCON_INIT_VAR(r3);
				PHALCON_CONCAT_SVSVS(r3, "Acccess '", access_name, "' does not exist in resource '", resource_name, "' in ACL");
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i2, "__construct", r3, PH_CHECK);
				phalcon_throw_exception(i2 TSRMLS_CC);
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
			PHALCON_INIT_VAR(t3);
			phalcon_read_property(&t3, this_ptr, SL("_access"), PH_NOISY_CC);
			if (Z_TYPE_P(t3) == IS_ARRAY) {
				PHALCON_INIT_VAR(t4);
				phalcon_array_fetch(&t4, t3, role_name, PH_SILENT_CC);
			}
			if (Z_REFCOUNT_P(t4) > 1) {
				phalcon_array_update_zval(&t3, role_name, &t4, PH_COPY | PH_CTOR TSRMLS_CC);
			}
			if (Z_TYPE_P(t4) != IS_ARRAY) {
				convert_to_array(t4);
				phalcon_array_update_zval(&t3, role_name, &t4, PH_COPY TSRMLS_CC);
			}
			if (Z_TYPE_P(t4) == IS_ARRAY) {
				PHALCON_INIT_VAR(t5);
				phalcon_array_fetch(&t5, t4, resource_name, PH_SILENT_CC);
			}
			if (Z_REFCOUNT_P(t5) > 1) {
				phalcon_array_update_zval(&t4, resource_name, &t5, PH_COPY | PH_CTOR TSRMLS_CC);
			}
			if (Z_TYPE_P(t5) != IS_ARRAY) {
				convert_to_array(t5);
				phalcon_array_update_zval(&t4, resource_name, &t5, PH_COPY TSRMLS_CC);
			}
			phalcon_array_update_zval(&t5, access_name, &action, PH_COPY TSRMLS_CC);
			
			PHALCON_INIT_VAR(t6);
			phalcon_read_property(&t6, this_ptr, SL("_access"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(r4);
			phalcon_array_fetch(&r4, t6, role_name, PH_NOISY_CC);
			
			PHALCON_INIT_VAR(r5);
			phalcon_array_fetch(&r5, r4, resource_name, PH_NOISY_CC);
			eval_int = phalcon_array_isset_string(r5, SL("*")+1);
			if (!eval_int) {
				PHALCON_INIT_VAR(t7);
				phalcon_read_property(&t7, this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
				PHALCON_INIT_VAR(t8);
				phalcon_read_property(&t8, this_ptr, SL("_access"), PH_NOISY_CC);
				if (Z_TYPE_P(t8) == IS_ARRAY) {
					PHALCON_INIT_VAR(t9);
					phalcon_array_fetch(&t9, t8, role_name, PH_SILENT_CC);
				}
				if (Z_REFCOUNT_P(t9) > 1) {
					phalcon_array_update_zval(&t8, role_name, &t9, PH_COPY | PH_CTOR TSRMLS_CC);
				}
				if (Z_TYPE_P(t9) != IS_ARRAY) {
					convert_to_array(t9);
					phalcon_array_update_zval(&t8, role_name, &t9, PH_COPY TSRMLS_CC);
				}
				if (Z_TYPE_P(t9) == IS_ARRAY) {
					PHALCON_INIT_VAR(t10);
					phalcon_array_fetch(&t10, t9, resource_name, PH_SILENT_CC);
				}
				if (Z_REFCOUNT_P(t10) > 1) {
					phalcon_array_update_zval(&t9, resource_name, &t10, PH_COPY | PH_CTOR TSRMLS_CC);
				}
				if (Z_TYPE_P(t10) != IS_ARRAY) {
					convert_to_array(t10);
					phalcon_array_update_zval(&t9, resource_name, &t10, PH_COPY TSRMLS_CC);
				}
				phalcon_array_update_string(&t10, SL("*"), &t7, PH_COPY TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_c945_3;
		fee_c945_3:
		if(0){}
		
	} else {
		PHALCON_ALLOC_ZVAL_MM(t11);
		phalcon_read_property(&t11, this_ptr, SL("_accessList"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r6);
		phalcon_array_fetch(&r6, t11, resource_name, PH_NOISY_CC);
		eval_int = phalcon_array_isset(r6, access);
		if (!eval_int) {
			PHALCON_ALLOC_ZVAL_MM(i3);
			object_init_ex(i3, phalcon_acl_exception_ce);
			PHALCON_ALLOC_ZVAL_MM(r7);
			PHALCON_CONCAT_SVSVS(r7, "Acccess '", access, "' does not exist in resource '", resource_name, "' in ACL");
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i3, "__construct", r7, PH_CHECK);
			phalcon_throw_exception(i3 TSRMLS_CC);
			return;
		}
		
		PHALCON_ALLOC_ZVAL_MM(t12);
		phalcon_read_property(&t12, this_ptr, SL("_access"), PH_NOISY_CC);
		if (Z_TYPE_P(t12) == IS_ARRAY) {
			PHALCON_ALLOC_ZVAL_MM(t13);
			phalcon_array_fetch(&t13, t12, role_name, PH_SILENT_CC);
		}
		if (Z_REFCOUNT_P(t13) > 1) {
			phalcon_array_update_zval(&t12, role_name, &t13, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(t13) != IS_ARRAY) {
			convert_to_array(t13);
			phalcon_array_update_zval(&t12, role_name, &t13, PH_COPY TSRMLS_CC);
		}
		if (Z_TYPE_P(t13) == IS_ARRAY) {
			PHALCON_ALLOC_ZVAL_MM(t14);
			phalcon_array_fetch(&t14, t13, resource_name, PH_SILENT_CC);
		}
		if (Z_REFCOUNT_P(t14) > 1) {
			phalcon_array_update_zval(&t13, resource_name, &t14, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(t14) != IS_ARRAY) {
			convert_to_array(t14);
			phalcon_array_update_zval(&t13, resource_name, &t14, PH_COPY TSRMLS_CC);
		}
		phalcon_array_update_zval(&t14, access, &action, PH_COPY TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(t15);
		phalcon_read_property(&t15, this_ptr, SL("_access"), PH_NOISY_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r8);
		phalcon_array_fetch(&r8, t15, role_name, PH_NOISY_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r9);
		phalcon_array_fetch(&r9, r8, resource_name, PH_NOISY_CC);
		eval_int = phalcon_array_isset_string(r9, SL("*")+1);
		if (!eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t16);
			phalcon_read_property(&t16, this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
			PHALCON_ALLOC_ZVAL_MM(t17);
			phalcon_read_property(&t17, this_ptr, SL("_access"), PH_NOISY_CC);
			if (Z_TYPE_P(t17) == IS_ARRAY) {
				PHALCON_ALLOC_ZVAL_MM(t18);
				phalcon_array_fetch(&t18, t17, role_name, PH_SILENT_CC);
			}
			if (Z_REFCOUNT_P(t18) > 1) {
				phalcon_array_update_zval(&t17, role_name, &t18, PH_COPY | PH_CTOR TSRMLS_CC);
			}
			if (Z_TYPE_P(t18) != IS_ARRAY) {
				convert_to_array(t18);
				phalcon_array_update_zval(&t17, role_name, &t18, PH_COPY TSRMLS_CC);
			}
			if (Z_TYPE_P(t18) == IS_ARRAY) {
				PHALCON_ALLOC_ZVAL_MM(t19);
				phalcon_array_fetch(&t19, t18, resource_name, PH_SILENT_CC);
			}
			if (Z_REFCOUNT_P(t19) > 1) {
				phalcon_array_update_zval(&t18, resource_name, &t19, PH_COPY | PH_CTOR TSRMLS_CC);
			}
			if (Z_TYPE_P(t19) != IS_ARRAY) {
				convert_to_array(t19);
				phalcon_array_update_zval(&t18, resource_name, &t19, PH_COPY TSRMLS_CC);
			}
			phalcon_array_update_string(&t19, SL("*"), &t16, PH_COPY TSRMLS_CC);
		}
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

	zval *role_name = NULL, *resource_name = NULL, *access = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &role_name, &resource_name, &access) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(c0);
	ZVAL_LONG(c0, 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_4(r0, this_ptr, "_allowordeny", role_name, resource_name, access, c0, PH_NO_CHECK);
	RETURN_CTOR(r0);
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

	zval *role_name = NULL, *resource_name = NULL, *access = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &role_name, &resource_name, &access) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(c0);
	ZVAL_LONG(c0, 0);
	PHALCON_CALL_METHOD_PARAMS_4_NORETURN(this_ptr, "_allowordeny", role_name, resource_name, access, c0, PH_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether a role is allowed to access an action from a resource
 *
 * @param  string $role
 * @param  string $resource
 * @param  mixed $accessList
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed){

	zval *role = NULL, *resource = NULL, *access = NULL, *access_roles = NULL, *resource_access = NULL;
	zval *resource_name = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
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

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, resource);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
		
		RETURN_CCTOR(t1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t2, role);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
		
		RETURN_CCTOR(t3);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, SL("_access"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(access_roles);
	phalcon_array_fetch(&access_roles, t4, role, PH_NOISY_CC);
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
		PHALCON_INIT_VAR(r0);
		is_equal_function(r0, resource_name, resource TSRMLS_CC);
		if (zend_is_true(r0)) {
			eval_int = phalcon_array_isset(resource_access, access);
			if (eval_int) {
				PHALCON_INIT_VAR(r1);
				phalcon_array_fetch(&r1, resource_access, access, PH_NOISY_CC);
				
				RETURN_CCTOR(r1);
			}
			
			PHALCON_INIT_VAR(r2);
			phalcon_array_fetch_string(&r2, resource_access, SL("*"), PH_NOISY_CC);
			
			RETURN_CCTOR(r2);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_c945_4;
	fee_c945_4:
	
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
				PHALCON_INIT_VAR(r3);
				phalcon_array_fetch(&r3, resource_access, access, PH_NOISY_CC);
				
				RETURN_CCTOR(r3);
			}
			
			PHALCON_INIT_VAR(r4);
			phalcon_array_fetch_string(&r4, resource_access, SL("*"), PH_NOISY_CC);
			
			RETURN_CCTOR(r4);
		}
		zend_hash_move_forward_ex(ah1, &hp1);
		goto fes_c945_5;
	fee_c945_5:
	
	PHALCON_MM_RESTORE();
	RETURN_LONG(0);
}

/**
 * Rebuild the list of access from the inherit lists
 *
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, _rebuildAccessList){

	zval *number_roles = NULL, *middle = NULL, *i = NULL, *one = NULL, *role_name = NULL;
	zval *role_inherit = NULL, *access = NULL, *resource_name = NULL;
	zval *value = NULL, *name = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	HashTable *ah0, *ah1, *ah2, *ah3;
	HashPosition hp0, hp1, hp2, hp3;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_roles"), PH_NOISY_CC);
	PHALCON_INIT_VAR(number_roles);
	phalcon_fast_count(number_roles, t0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, number_roles, number_roles TSRMLS_CC);
	
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 2);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	div_function(r1, r0, t1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(middle);
	PHALCON_CALL_FUNC_PARAMS_1(middle, "ceil", r1);
	
	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	fs_c945_6:
		
		PHALCON_INIT_VAR(r2);
		is_smaller_or_equal_function(r2, i, middle TSRMLS_CC);
		if (!zend_is_true(r2)) {
			goto fe_c945_6;
		}
		PHALCON_INIT_VAR(t2);
		phalcon_read_property(&t2, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
		if (!phalcon_valid_foreach(t2 TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(t2);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_c945_7:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_c945_7;
			}
			
			PHALCON_INIT_VAR(role_name);
			PHALCON_GET_FOREACH_KEY(role_name, ah0, hp0);
			PHALCON_INIT_VAR(one);
			ZVAL_ZVAL(one, *hd, 1, 0);
			PHALCON_INIT_VAR(t3);
			phalcon_read_property(&t3, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
			eval_int = phalcon_array_isset(t3, role_name);
			if (eval_int) {
				PHALCON_INIT_VAR(t4);
				phalcon_read_property(&t4, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
				PHALCON_INIT_VAR(r3);
				phalcon_array_fetch(&r3, t4, role_name, PH_NOISY_CC);
				if (!phalcon_valid_foreach(r3 TSRMLS_CC)) {
					return;
				}
				
				ah1 = Z_ARRVAL_P(r3);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				fes_c945_8:
					if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
						goto fee_c945_8;
					}
					
					PHALCON_INIT_VAR(role_inherit);
					ZVAL_ZVAL(role_inherit, *hd, 1, 0);
					PHALCON_INIT_VAR(t5);
					phalcon_read_property(&t5, this_ptr, SL("_access"), PH_NOISY_CC);
					eval_int = phalcon_array_isset(t5, role_inherit);
					if (eval_int) {
						PHALCON_INIT_VAR(t6);
						phalcon_read_property(&t6, this_ptr, SL("_access"), PH_NOISY_CC);
						PHALCON_INIT_VAR(r4);
						phalcon_array_fetch(&r4, t6, role_inherit, PH_NOISY_CC);
						if (!phalcon_valid_foreach(r4 TSRMLS_CC)) {
							return;
						}
						
						ah2 = Z_ARRVAL_P(r4);
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
								PHALCON_INIT_VAR(t7);
								phalcon_read_property(&t7, this_ptr, SL("_access"), PH_NOISY_CC);
								if (Z_TYPE_P(t7) == IS_ARRAY) {
									PHALCON_INIT_VAR(t8);
									phalcon_array_fetch(&t8, t7, role_name, PH_SILENT_CC);
								}
								if (Z_REFCOUNT_P(t8) > 1) {
									phalcon_array_update_zval(&t7, role_name, &t8, PH_COPY | PH_CTOR TSRMLS_CC);
								}
								if (Z_TYPE_P(t8) != IS_ARRAY) {
									convert_to_array(t8);
									phalcon_array_update_zval(&t7, role_name, &t8, PH_COPY TSRMLS_CC);
								}
								if (Z_TYPE_P(t8) == IS_ARRAY) {
									PHALCON_INIT_VAR(t9);
									phalcon_array_fetch(&t9, t8, resource_name, PH_SILENT_CC);
								}
								if (Z_REFCOUNT_P(t9) > 1) {
									phalcon_array_update_zval(&t8, resource_name, &t9, PH_COPY | PH_CTOR TSRMLS_CC);
								}
								if (Z_TYPE_P(t9) != IS_ARRAY) {
									convert_to_array(t9);
									phalcon_array_update_zval(&t8, resource_name, &t9, PH_COPY TSRMLS_CC);
								}
								phalcon_array_update_zval(&t9, name, &value, PH_COPY TSRMLS_CC);
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

