
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

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Phalcon_Acl_Adapter_Memory
 *
 * Manages ACL lists in memory
 */

PHP_METHOD(Phalcon_Acl_Adapter_Memory, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL, *a6 = NULL;
	zval *a7 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_acl_adapter_memory_ce, this_ptr, "_rolesNames", strlen("_rolesNames"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_acl_adapter_memory_ce, this_ptr, "_roles", strlen("_roles"), a1 TSRMLS_CC);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	zend_update_property(phalcon_acl_adapter_memory_ce, this_ptr, "_resources", strlen("_resources"), a2 TSRMLS_CC);
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	zend_update_property(phalcon_acl_adapter_memory_ce, this_ptr, "_access", strlen("_access"), a3 TSRMLS_CC);
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	zend_update_property(phalcon_acl_adapter_memory_ce, this_ptr, "_roleInherits", strlen("_roleInherits"), a4 TSRMLS_CC);
	PHALCON_INIT_VAR(a5);
	array_init(a5);
	add_assoc_bool_ex(a5, "*", strlen("*")+1, 1);
	zend_update_property(phalcon_acl_adapter_memory_ce, this_ptr, "_resourcesNames", strlen("_resourcesNames"), a5 TSRMLS_CC);
	PHALCON_INIT_VAR(a6);
	array_init(a6);
	PHALCON_INIT_VAR(a7);
	array_init(a7);
	add_assoc_bool_ex(a7, "*", strlen("*")+1, 1);
	phalcon_array_update_string(&a6, "*", strlen("*"), a7, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	zend_update_property(phalcon_acl_adapter_memory_ce, this_ptr, "_accessList", strlen("_accessList"), a6 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets the default access level (Phalcon_Acl::ALLOW or Phalcon_Acl::DENY)
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, setDefaultAction){

	zval *default_access = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &default_access) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_defaultAccess", strlen("_defaultAccess"), default_access TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the default ACL access level
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getDefaultAction){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_defaultAccess", sizeof("_defaultAccess")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Adds a role to the ACL list. Second parameter lets to inherit access data from other existing role
 *
 * Example:
 * 
 * 
 *
 * @param  string $roleObject
 * @param  array $accessInherits
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addRole){

	zval *role_object = NULL, *access_inherits = NULL, *role_name = NULL;
	zval *object = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &role_object, &access_inherits) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!access_inherits) {
		PHALCON_INIT_VAR(access_inherits);
		ZVAL_NULL(access_inherits);
	}
	
	if (Z_TYPE_P(role_object) == IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, role_object, "getname", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(role_name, r0);
		PHALCON_CPY_WRT(object, role_object);
	} else {
		PHALCON_CPY_WRT(role_name, role_object);
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_role_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", role_name, PHALCON_CHECK);
		PHALCON_CPY_WRT(object, i0);
	}
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, role_name);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_roles", sizeof("_roles")-1, PHALCON_NOISY TSRMLS_CC);
	phalcon_array_append(&t1, object, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_roles", strlen("_roles"), t1 TSRMLS_CC);
	PHALCON_INIT_VAR(t2);
	ZVAL_BOOL(t2, 1);
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY TSRMLS_CC);
	phalcon_array_update(&t3, role_name, t2, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_rolesNames", strlen("_rolesNames"), t3 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, "_defaultAccess", sizeof("_defaultAccess")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t5);
	phalcon_read_property(&t5, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY TSRMLS_CC);
	if (Z_TYPE_P(t5) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t6);
		phalcon_array_fetch(&t6, t5, role_name, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t6) > 1) {
		phalcon_array_update(&t5, role_name, t6, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	Z_ADDREF_P(t6);
	if (Z_TYPE_P(t6) != IS_ARRAY) {
		convert_to_array(t6);
		phalcon_array_update(&t5, role_name, t6, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t6) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t7);
		phalcon_array_fetch_string(&t7, t6, "*", strlen("*"), PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t7) > 1) {
		phalcon_array_update_string(&t6, "*", strlen("*"), t7, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	Z_ADDREF_P(t7);
	if (Z_TYPE_P(t7) != IS_ARRAY) {
		convert_to_array(t7);
		phalcon_array_update_string(&t6, "*", strlen("*"), t7, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	phalcon_array_update_string(&t7, "*", strlen("*"), t4, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	if (zend_is_true(access_inherits)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD_PARAMS_2(r1, this_ptr, "addinherit", role_name, access_inherits, PHALCON_NO_CHECK);
		PHALCON_RETURN_DZVAL(r1);
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
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
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
	phalcon_read_property(&t0, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, role_name);
	if (!eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t1, role_to_inherit);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_BOTH(r0,  "Role '", role_to_inherit, "' does not exist in the role list");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r0, PHALCON_CHECK);
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
	phalcon_read_property(&t2, this_ptr, "_roleInherits", sizeof("_roleInherits")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t2, role_name);
	if (!eval_int) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_roleInherits", sizeof("_roleInherits")-1, PHALCON_NOISY TSRMLS_CC);
		phalcon_array_update(&t3, role_name, a0, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_roleInherits", strlen("_roleInherits"), t3 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, "_roleInherits", sizeof("_roleInherits")-1, PHALCON_NOISY TSRMLS_CC);
	if (Z_TYPE_P(t4) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_array_fetch(&t5, t4, role_name, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t5) > 1) {
		phalcon_array_update(&t4, role_name, t5, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	Z_ADDREF_P(t5);
	if (Z_TYPE_P(t5) != IS_ARRAY) {
		convert_to_array(t5);
		phalcon_array_update(&t4, role_name, t5, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	phalcon_array_append(&t5, role_to_inherit, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_roleInherits", strlen("_roleInherits"), t4 TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_rebuildaccesslist", PHALCON_NO_CHECK);
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
	phalcon_read_property(&t0, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, role_name);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	PHALCON_RETURN_NCTOR(r0);
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
	phalcon_read_property(&t0, this_ptr, "_resourcesNames", sizeof("_resourcesNames")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, resource_name);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	PHALCON_RETURN_NCTOR(r0);
}

/**
 * Adds a resource to the ACL list
 *
 * Access names can be a particular action, by example
 * search, update, delete, etc or a list of them
 *
 * Example:
 * 
 *
 * @param   Phalcon_Acl_Resource $resource
 * @return  boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResource){

	zval *resource = NULL, *access_list = NULL, *resource_name = NULL;
	zval *object = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &resource, &access_list) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!access_list) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(access_list, a0);
	}
	
	if (Z_TYPE_P(resource) == IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, resource, "getname", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(resource_name, r0);
		PHALCON_CPY_WRT(object, resource);
	} else {
		PHALCON_CPY_WRT(resource_name, resource);
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_resource_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", resource_name, PHALCON_CHECK);
		PHALCON_CPY_WRT(object, i0);
	}
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_resourcesNames", sizeof("_resourcesNames")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, resource_name);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_resources", sizeof("_resources")-1, PHALCON_NOISY TSRMLS_CC);
		phalcon_array_append(&t1, object, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_resources", strlen("_resources"), t1 TSRMLS_CC);
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY TSRMLS_CC);
		phalcon_array_update(&t2, resource_name, a1, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_accessList", strlen("_accessList"), t2 TSRMLS_CC);
		PHALCON_INIT_VAR(t3);
		ZVAL_BOOL(t3, 1);
		PHALCON_ALLOC_ZVAL_MM(t4);
		phalcon_read_property(&t4, this_ptr, "_resourcesNames", sizeof("_resourcesNames")-1, PHALCON_NOISY TSRMLS_CC);
		phalcon_array_update(&t4, resource_name, t3, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_resourcesNames", strlen("_resourcesNames"), t4 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_2(r1, this_ptr, "addresourceaccess", resource_name, access_list, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r1);
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
	zval *t7 = NULL, *t8 = NULL;
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
	phalcon_read_property(&t0, this_ptr, "_resourcesNames", sizeof("_resourcesNames")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, resource_name);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_BOTH(r0,  "Resource '", resource_name, "' does not exist in ACL");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	if (Z_TYPE_P(access_list) == IS_ARRAY) { 
		if (phalcon_valid_foreach(access_list TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(access_list);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_c945_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_c945_0;
			}
			PHALCON_INIT_VAR(access_name);
			ZVAL_ZVAL(access_name, *hd, 1, 0);
			PHALCON_INIT_VAR(t1);
			phalcon_read_property(&t1, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_INIT_VAR(r1);
			phalcon_array_fetch(&r1, t1, resource_name, PHALCON_NOISY TSRMLS_CC);
			eval_int = phalcon_array_isset(r1, access_name);
			if (!eval_int) {
				PHALCON_INIT_VAR(t2);
				ZVAL_BOOL(t2, 1);
				PHALCON_INIT_VAR(t3);
				phalcon_read_property(&t3, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY TSRMLS_CC);
				if (Z_TYPE_P(t3) == IS_ARRAY) {
					PHALCON_INIT_VAR(t4);
					phalcon_array_fetch(&t4, t3, resource_name, PHALCON_SILENT TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t4) > 1) {
					phalcon_array_update(&t3, resource_name, t4, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_CTOR TSRMLS_CC);
				}
				Z_ADDREF_P(t4);
				if (Z_TYPE_P(t4) != IS_ARRAY) {
					convert_to_array(t4);
					phalcon_array_update(&t3, resource_name, t4, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				}
				phalcon_array_update(&t4, access_name, t2, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, "_accessList", strlen("_accessList"), t3 TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_c945_0;
			fee_c945_0:
			if(0){ };
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_read_property(&t5, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch(&r2, t5, resource_name, PHALCON_NOISY TSRMLS_CC);
		eval_int = phalcon_array_isset(r2, access_list);
		if (!eval_int) {
			PHALCON_INIT_VAR(t6);
			ZVAL_BOOL(t6, 1);
			PHALCON_ALLOC_ZVAL_MM(t7);
			phalcon_read_property(&t7, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY TSRMLS_CC);
			if (Z_TYPE_P(t7) == IS_ARRAY) {
				PHALCON_ALLOC_ZVAL_MM(t8);
				phalcon_array_fetch(&t8, t7, resource_name, PHALCON_SILENT TSRMLS_CC);
			}
			if (Z_REFCOUNT_P(t8) > 1) {
				phalcon_array_update(&t7, resource_name, t8, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_CTOR TSRMLS_CC);
			}
			Z_ADDREF_P(t8);
			if (Z_TYPE_P(t8) != IS_ARRAY) {
				convert_to_array(t8);
				phalcon_array_update(&t7, resource_name, t8, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			}
			phalcon_array_update(&t8, access_list, t6, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_accessList", strlen("_accessList"), t7 TSRMLS_CC);
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
		if (phalcon_valid_foreach(access_list TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(access_list);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_c945_1:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_c945_1;
			}
			PHALCON_INIT_VAR(access_name);
			ZVAL_ZVAL(access_name, *hd, 1, 0);
			PHALCON_INIT_VAR(t0);
			phalcon_read_property(&t0, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_INIT_VAR(r0);
			phalcon_array_fetch(&r0, t0, resource_name, PHALCON_NOISY TSRMLS_CC);
			PHALCON_SEPARATE_NMO(r0);
			phalcon_array_unset(r0, access_name);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_c945_1;
			fee_c945_1:
			if(0){ };
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch(&r1, t1, resource_name, PHALCON_NOISY TSRMLS_CC);
		PHALCON_SEPARATE_NMO(r1);
		phalcon_array_unset(r1, access_list);
	}
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_rebuildaccesslist", PHALCON_NO_CHECK);
	
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
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
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
	phalcon_read_property(&t0, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, role_name);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_BOTH(r0,  "Role \"", role_name, "\" does not exist in ACL");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_resourcesNames", sizeof("_resourcesNames")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t1, resource_name);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_acl_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_BOTH(r1,  "Resource \"", resource_name, "\" does not exist in ACL");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", r1, PHALCON_CHECK);
		phalcon_throw_exception(i1 TSRMLS_CC);
		return;
	}
	if (Z_TYPE_P(access) == IS_ARRAY) { 
		if (phalcon_valid_foreach(access TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(access);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_c945_2:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_c945_2;
			}
			PHALCON_INIT_VAR(access_name);
			ZVAL_ZVAL(access_name, *hd, 1, 0);
			PHALCON_INIT_VAR(t2);
			phalcon_read_property(&t2, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_INIT_VAR(r2);
			phalcon_array_fetch(&r2, t2, resource_name, PHALCON_NOISY TSRMLS_CC);
			eval_int = phalcon_array_isset(r2, access_name);
			if (!eval_int) {
				PHALCON_INIT_VAR(i2);
				object_init_ex(i2, phalcon_acl_exception_ce);
				PHALCON_INIT_VAR(r4);
				PHALCON_CONCAT_LEFT(r4, "Acccess '", access_name);
				PHALCON_INIT_VAR(r3);
				PHALCON_CONCAT_VBOTH(r3, r4, "' does not exist in resource '", resource_name);
				PHALCON_INIT_VAR(r5);
				PHALCON_CONCAT_RIGHT(r5, r3, "' in ACL");
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i2, "__construct", r5, PHALCON_CHECK);
				phalcon_throw_exception(i2 TSRMLS_CC);
				return;
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_c945_2;
			fee_c945_2:
			if(0){ };
		}
		if (phalcon_valid_foreach(access TSRMLS_CC)) {
			ah1 = Z_ARRVAL_P(access);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_c945_3:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_c945_3;
			}
			PHALCON_INIT_VAR(access_name);
			ZVAL_ZVAL(access_name, *hd, 1, 0);
			PHALCON_INIT_VAR(t3);
			phalcon_read_property(&t3, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY TSRMLS_CC);
			if (Z_TYPE_P(t3) == IS_ARRAY) {
				PHALCON_INIT_VAR(t4);
				phalcon_array_fetch(&t4, t3, role_name, PHALCON_SILENT TSRMLS_CC);
			}
			if (Z_REFCOUNT_P(t4) > 1) {
				phalcon_array_update(&t3, role_name, t4, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_CTOR TSRMLS_CC);
			}
			Z_ADDREF_P(t4);
			if (Z_TYPE_P(t4) != IS_ARRAY) {
				convert_to_array(t4);
				phalcon_array_update(&t3, role_name, t4, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			}
			if (Z_TYPE_P(t4) == IS_ARRAY) {
				PHALCON_INIT_VAR(t5);
				phalcon_array_fetch(&t5, t4, resource_name, PHALCON_SILENT TSRMLS_CC);
			}
			if (Z_REFCOUNT_P(t5) > 1) {
				phalcon_array_update(&t4, resource_name, t5, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_CTOR TSRMLS_CC);
			}
			Z_ADDREF_P(t5);
			if (Z_TYPE_P(t5) != IS_ARRAY) {
				convert_to_array(t5);
				phalcon_array_update(&t4, resource_name, t5, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			}
			phalcon_array_update(&t5, access_name, action, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			PHALCON_INIT_VAR(t6);
			phalcon_read_property(&t6, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_INIT_VAR(r6);
			phalcon_array_fetch(&r6, t6, role_name, PHALCON_NOISY TSRMLS_CC);
			PHALCON_INIT_VAR(r7);
			phalcon_array_fetch(&r7, r6, resource_name, PHALCON_NOISY TSRMLS_CC);
			eval_int = phalcon_array_isset_string(r7, "*", strlen("*")+1);
			if (!eval_int) {
				PHALCON_INIT_VAR(t7);
				phalcon_read_property(&t7, this_ptr, "_defaultAccess", sizeof("_defaultAccess")-1, PHALCON_NOISY TSRMLS_CC);
				PHALCON_INIT_VAR(t8);
				phalcon_read_property(&t8, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY TSRMLS_CC);
				if (Z_TYPE_P(t8) == IS_ARRAY) {
					PHALCON_INIT_VAR(t9);
					phalcon_array_fetch(&t9, t8, role_name, PHALCON_SILENT TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t9) > 1) {
					phalcon_array_update(&t8, role_name, t9, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_CTOR TSRMLS_CC);
				}
				Z_ADDREF_P(t9);
				if (Z_TYPE_P(t9) != IS_ARRAY) {
					convert_to_array(t9);
					phalcon_array_update(&t8, role_name, t9, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				}
				if (Z_TYPE_P(t9) == IS_ARRAY) {
					PHALCON_INIT_VAR(t10);
					phalcon_array_fetch(&t10, t9, resource_name, PHALCON_SILENT TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t10) > 1) {
					phalcon_array_update(&t9, resource_name, t10, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_CTOR TSRMLS_CC);
				}
				Z_ADDREF_P(t10);
				if (Z_TYPE_P(t10) != IS_ARRAY) {
					convert_to_array(t10);
					phalcon_array_update(&t9, resource_name, t10, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				}
				phalcon_array_update_string(&t10, "*", strlen("*"), t7, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_c945_3;
			fee_c945_3:
			if(0){ };
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(t11);
		phalcon_read_property(&t11, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r8);
		phalcon_array_fetch(&r8, t11, resource_name, PHALCON_NOISY TSRMLS_CC);
		eval_int = phalcon_array_isset(r8, access);
		if (!eval_int) {
			PHALCON_ALLOC_ZVAL_MM(i3);
			object_init_ex(i3, phalcon_acl_exception_ce);
			PHALCON_ALLOC_ZVAL_MM(r10);
			PHALCON_CONCAT_LEFT(r10, "Acccess '", access);
			PHALCON_ALLOC_ZVAL_MM(r9);
			PHALCON_CONCAT_VBOTH(r9, r10, "' does not exist in resource '", resource_name);
			PHALCON_ALLOC_ZVAL_MM(r11);
			PHALCON_CONCAT_RIGHT(r11, r9, "' in ACL");
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i3, "__construct", r11, PHALCON_CHECK);
			phalcon_throw_exception(i3 TSRMLS_CC);
			return;
		}
		PHALCON_ALLOC_ZVAL_MM(t12);
		phalcon_read_property(&t12, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY TSRMLS_CC);
		if (Z_TYPE_P(t12) == IS_ARRAY) {
			PHALCON_ALLOC_ZVAL_MM(t13);
			phalcon_array_fetch(&t13, t12, role_name, PHALCON_SILENT TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t13) > 1) {
			phalcon_array_update(&t12, role_name, t13, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_CTOR TSRMLS_CC);
		}
		Z_ADDREF_P(t13);
		if (Z_TYPE_P(t13) != IS_ARRAY) {
			convert_to_array(t13);
			phalcon_array_update(&t12, role_name, t13, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(t13) == IS_ARRAY) {
			PHALCON_ALLOC_ZVAL_MM(t14);
			phalcon_array_fetch(&t14, t13, resource_name, PHALCON_SILENT TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t14) > 1) {
			phalcon_array_update(&t13, resource_name, t14, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_CTOR TSRMLS_CC);
		}
		Z_ADDREF_P(t14);
		if (Z_TYPE_P(t14) != IS_ARRAY) {
			convert_to_array(t14);
			phalcon_array_update(&t13, resource_name, t14, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		}
		phalcon_array_update(&t14, access, action, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t15);
		phalcon_read_property(&t15, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r12);
		phalcon_array_fetch(&r12, t15, role_name, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r13);
		phalcon_array_fetch(&r13, r12, resource_name, PHALCON_NOISY TSRMLS_CC);
		eval_int = phalcon_array_isset_string(r13, "*", strlen("*")+1);
		if (!eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t16);
			phalcon_read_property(&t16, this_ptr, "_defaultAccess", sizeof("_defaultAccess")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(t17);
			phalcon_read_property(&t17, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY TSRMLS_CC);
			if (Z_TYPE_P(t17) == IS_ARRAY) {
				PHALCON_ALLOC_ZVAL_MM(t18);
				phalcon_array_fetch(&t18, t17, role_name, PHALCON_SILENT TSRMLS_CC);
			}
			if (Z_REFCOUNT_P(t18) > 1) {
				phalcon_array_update(&t17, role_name, t18, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_CTOR TSRMLS_CC);
			}
			Z_ADDREF_P(t18);
			if (Z_TYPE_P(t18) != IS_ARRAY) {
				convert_to_array(t18);
				phalcon_array_update(&t17, role_name, t18, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			}
			if (Z_TYPE_P(t18) == IS_ARRAY) {
				PHALCON_ALLOC_ZVAL_MM(t19);
				phalcon_array_fetch(&t19, t18, resource_name, PHALCON_SILENT TSRMLS_CC);
			}
			if (Z_REFCOUNT_P(t19) > 1) {
				phalcon_array_update(&t18, resource_name, t19, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_CTOR TSRMLS_CC);
			}
			Z_ADDREF_P(t19);
			if (Z_TYPE_P(t19) != IS_ARRAY) {
				convert_to_array(t19);
				phalcon_array_update(&t18, resource_name, t19, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			}
			phalcon_array_update_string(&t19, "*", strlen("*"), t16, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		}
	}
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_rebuildaccesslist", PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * Allow access to a role on a resource
 *
 * You can use '*' as wildcard
 *
 * Ej:
 * 
 *
 * @param string $roleName
 * @param string $resourceName
 * @param mixed $access
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow){

	zval *role_name = NULL, *resource_name = NULL, *access = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &role_name, &resource_name, &access) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	p0[0] = role_name;
	p0[1] = resource_name;
	p0[2] = access;
	PHALCON_INIT_VAR(p0[3]);
	ZVAL_LONG(p0[3], 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "_allowordeny", 4, p0, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Deny access to a role on a resource
 *
 * You can use '*' as wildcard
 *
 * Ej:
 * 
 *
 * @param string $roleName
 * @param string $resourceName
 * @param mixed $access
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, deny){

	zval *role_name = NULL, *resource_name = NULL, *access = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &role_name, &resource_name, &access) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	p0[0] = role_name;
	p0[1] = resource_name;
	p0[2] = access;
	PHALCON_INIT_VAR(p0[3]);
	ZVAL_LONG(p0[3], 0);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_allowordeny", 4, p0, PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether a role is allowed to access an action from a resource
 *
 * 
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
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
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
	phalcon_read_property(&t0, this_ptr, "_resourcesNames", sizeof("_resourcesNames")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, resource);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_defaultAccess", sizeof("_defaultAccess")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t1);
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t2, role);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_defaultAccess", sizeof("_defaultAccess")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t3);
	}
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch(&r0, t4, role, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(access_roles, r0);
	if (phalcon_valid_foreach(access_roles TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(access_roles);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_c945_4:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_c945_4;
		} else {
			PHALCON_INIT_VAR(resource_name);
			hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
			if (hash_type == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(resource_name, hash_index, hash_index_len-1, 1);
			} else {
				if (hash_type == HASH_KEY_IS_LONG) {
					ZVAL_LONG(resource_name, hash_num);
				}
			}
		}
		PHALCON_INIT_VAR(resource_access);
		ZVAL_ZVAL(resource_access, *hd, 1, 0);
		PHALCON_INIT_VAR(r1);
		is_equal_function(r1, resource_name, resource TSRMLS_CC);
		if (zend_is_true(r1)) {
			eval_int = phalcon_array_isset(resource_access, access);
			if (eval_int) {
				PHALCON_INIT_VAR(r2);
				phalcon_array_fetch(&r2, resource_access, access, PHALCON_NOISY TSRMLS_CC);
				PHALCON_RETURN_CHECK_CTOR(r2);
			}
			PHALCON_INIT_VAR(r3);
			phalcon_array_fetch_string(&r3, resource_access, "*", strlen("*"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_RETURN_CHECK_CTOR(r3);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_c945_4;
		fee_c945_4:
		if(0){ };
	}
	if (phalcon_valid_foreach(access_roles TSRMLS_CC)) {
		ah1 = Z_ARRVAL_P(access_roles);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
		fes_c945_5:
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto fee_c945_5;
		} else {
			PHALCON_INIT_VAR(resource_name);
			hash_type = zend_hash_get_current_key_ex(ah1, &hash_index, &hash_index_len, &hash_num, 0, &hp1);
			if (hash_type == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(resource_name, hash_index, hash_index_len-1, 1);
			} else {
				if (hash_type == HASH_KEY_IS_LONG) {
					ZVAL_LONG(resource_name, hash_num);
				}
			}
		}
		PHALCON_INIT_VAR(resource_access);
		ZVAL_ZVAL(resource_access, *hd, 1, 0);
		eval_int = phalcon_array_isset_string(resource_access, "*", strlen("*")+1);
		if (eval_int) {
			eval_int = phalcon_array_isset(resource_access, access);
			if (eval_int) {
				PHALCON_INIT_VAR(r4);
				phalcon_array_fetch(&r4, resource_access, access, PHALCON_NOISY TSRMLS_CC);
				PHALCON_RETURN_CHECK_CTOR(r4);
			}
			PHALCON_INIT_VAR(r5);
			phalcon_array_fetch_string(&r5, resource_access, "*", strlen("*"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_RETURN_CHECK_CTOR(r5);
		}
		zend_hash_move_forward_ex(ah1, &hp1);
		goto fes_c945_5;
		fee_c945_5:
		if(0){ };
	}
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
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
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
	phalcon_read_property(&t0, this_ptr, "_roles", sizeof("_roles")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_fast_count(r0, t0 TSRMLS_CC);
	PHALCON_CPY_WRT(number_roles, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	mul_function(r2, number_roles, number_roles TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 2);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	div_function(r3, r2, t1 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "ceil", r3, 0x01C);
	PHALCON_CPY_WRT(middle, r1);
	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	fs_c945_6:
		PHALCON_INIT_VAR(r4);
		is_smaller_or_equal_function(r4, i, middle TSRMLS_CC);
		if (!zend_is_true(r4)) {
			goto fe_c945_6;
		}
		PHALCON_INIT_VAR(t2);
		phalcon_read_property(&t2, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY TSRMLS_CC);
		if (phalcon_valid_foreach(t2 TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(t2);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_c945_7:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_c945_7;
			} else {
				PHALCON_INIT_VAR(role_name);
				hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
				if (hash_type == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(role_name, hash_index, hash_index_len-1, 1);
				} else {
					if (hash_type == HASH_KEY_IS_LONG) {
						ZVAL_LONG(role_name, hash_num);
					}
				}
			}
			PHALCON_INIT_VAR(one);
			ZVAL_ZVAL(one, *hd, 1, 0);
			PHALCON_INIT_VAR(t3);
			phalcon_read_property(&t3, this_ptr, "_roleInherits", sizeof("_roleInherits")-1, PHALCON_NOISY TSRMLS_CC);
			eval_int = phalcon_array_isset(t3, role_name);
			if (eval_int) {
				PHALCON_INIT_VAR(t4);
				phalcon_read_property(&t4, this_ptr, "_roleInherits", sizeof("_roleInherits")-1, PHALCON_NOISY TSRMLS_CC);
				PHALCON_INIT_VAR(r5);
				phalcon_array_fetch(&r5, t4, role_name, PHALCON_NOISY TSRMLS_CC);
				if (phalcon_valid_foreach(r5 TSRMLS_CC)) {
					ah1 = Z_ARRVAL_P(r5);
					zend_hash_internal_pointer_reset_ex(ah1, &hp1);
					fes_c945_8:
					if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
						goto fee_c945_8;
					}
					PHALCON_INIT_VAR(role_inherit);
					ZVAL_ZVAL(role_inherit, *hd, 1, 0);
					PHALCON_INIT_VAR(t5);
					phalcon_read_property(&t5, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY TSRMLS_CC);
					eval_int = phalcon_array_isset(t5, role_inherit);
					if (eval_int) {
						PHALCON_INIT_VAR(t6);
						phalcon_read_property(&t6, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY TSRMLS_CC);
						PHALCON_INIT_VAR(r6);
						phalcon_array_fetch(&r6, t6, role_inherit, PHALCON_NOISY TSRMLS_CC);
						if (phalcon_valid_foreach(r6 TSRMLS_CC)) {
							ah2 = Z_ARRVAL_P(r6);
							zend_hash_internal_pointer_reset_ex(ah2, &hp2);
							fes_c945_9:
							if(zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS){
								goto fee_c945_9;
							} else {
								PHALCON_INIT_VAR(resource_name);
								hash_type = zend_hash_get_current_key_ex(ah2, &hash_index, &hash_index_len, &hash_num, 0, &hp2);
								if (hash_type == HASH_KEY_IS_STRING) {
									ZVAL_STRINGL(resource_name, hash_index, hash_index_len-1, 1);
								} else {
									if (hash_type == HASH_KEY_IS_LONG) {
										ZVAL_LONG(resource_name, hash_num);
									}
								}
							}
							PHALCON_INIT_VAR(access);
							ZVAL_ZVAL(access, *hd, 1, 0);
							if (phalcon_valid_foreach(access TSRMLS_CC)) {
								ah3 = Z_ARRVAL_P(access);
								zend_hash_internal_pointer_reset_ex(ah3, &hp3);
								fes_c945_10:
								if(zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) != SUCCESS){
									goto fee_c945_10;
								} else {
									PHALCON_INIT_VAR(name);
									hash_type = zend_hash_get_current_key_ex(ah3, &hash_index, &hash_index_len, &hash_num, 0, &hp3);
									if (hash_type == HASH_KEY_IS_STRING) {
										ZVAL_STRINGL(name, hash_index, hash_index_len-1, 1);
									} else {
										if (hash_type == HASH_KEY_IS_LONG) {
											ZVAL_LONG(name, hash_num);
										}
									}
								}
								PHALCON_INIT_VAR(value);
								ZVAL_ZVAL(value, *hd, 1, 0);
								PHALCON_INIT_VAR(t7);
								phalcon_read_property(&t7, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY TSRMLS_CC);
								if (Z_TYPE_P(t7) == IS_ARRAY) {
									PHALCON_INIT_VAR(t8);
									phalcon_array_fetch(&t8, t7, role_name, PHALCON_SILENT TSRMLS_CC);
								}
								if (Z_REFCOUNT_P(t8) > 1) {
									phalcon_array_update(&t7, role_name, t8, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_CTOR TSRMLS_CC);
								}
								Z_ADDREF_P(t8);
								if (Z_TYPE_P(t8) != IS_ARRAY) {
									convert_to_array(t8);
									phalcon_array_update(&t7, role_name, t8, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_NO_CTOR TSRMLS_CC);
								}
								if (Z_TYPE_P(t8) == IS_ARRAY) {
									PHALCON_INIT_VAR(t9);
									phalcon_array_fetch(&t9, t8, resource_name, PHALCON_SILENT TSRMLS_CC);
								}
								if (Z_REFCOUNT_P(t9) > 1) {
									phalcon_array_update(&t8, resource_name, t9, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_CTOR TSRMLS_CC);
								}
								Z_ADDREF_P(t9);
								if (Z_TYPE_P(t9) != IS_ARRAY) {
									convert_to_array(t9);
									phalcon_array_update(&t8, resource_name, t9, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_NO_CTOR TSRMLS_CC);
								}
								phalcon_array_update(&t9, name, value, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
								zend_hash_move_forward_ex(ah3, &hp3);
								goto fes_c945_10;
								fee_c945_10:
								if(0){ };
							}
							zend_hash_move_forward_ex(ah2, &hp2);
							goto fes_c945_9;
							fee_c945_9:
							if(0){ };
						}
					}
					zend_hash_move_forward_ex(ah1, &hp1);
					goto fes_c945_8;
					fee_c945_8:
					if(0){ };
				}
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_c945_7;
			fee_c945_7:
			if(0){ };
		}
		phalcon_increment_function(&i, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		goto fs_c945_6;
	fe_c945_6:
	
	PHALCON_MM_RESTORE();
}

