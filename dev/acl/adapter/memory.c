
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
	zend_update_property(phalcon_acl_adapter_memory_class_entry, this_ptr, "_rolesNames", strlen("_rolesNames"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_acl_adapter_memory_class_entry, this_ptr, "_roles", strlen("_roles"), a1 TSRMLS_CC);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	zend_update_property(phalcon_acl_adapter_memory_class_entry, this_ptr, "_resources", strlen("_resources"), a2 TSRMLS_CC);
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	zend_update_property(phalcon_acl_adapter_memory_class_entry, this_ptr, "_access", strlen("_access"), a3 TSRMLS_CC);
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	zend_update_property(phalcon_acl_adapter_memory_class_entry, this_ptr, "_roleInherits", strlen("_roleInherits"), a4 TSRMLS_CC);
	PHALCON_INIT_VAR(a5);
	array_init(a5);
	add_assoc_bool_ex(a5, "*", strlen("*")+1, 1);
	zend_update_property(phalcon_acl_adapter_memory_class_entry, this_ptr, "_resourcesNames", strlen("_resourcesNames"), a5 TSRMLS_CC);
	PHALCON_INIT_VAR(a6);
	array_init(a6);
	PHALCON_INIT_VAR(a7);
	array_init(a7);
	add_assoc_bool_ex(a7, "*", strlen("*")+1, 1);
	Z_ADDREF_P(a7);
	PHALCON_SEPARATE_ARRAY(a6);
	add_assoc_zval(a6, "*", a7);
	zend_update_property(phalcon_acl_adapter_memory_class_entry, this_ptr, "_accessList", strlen("_accessList"), a6 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets the default access level (Phalcon_Acl::ALLOW or Phalcon_Acl::DENY)
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, setDefaultAction){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_defaultAccess", strlen("_defaultAccess"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the default ACL access level
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getDefaultAction){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_defaultAccess", sizeof("_defaultAccess")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	if (Z_TYPE_P(v0) == IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, v0, "getname", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v2, r0);
		PHALCON_CPY_WRT(v3, v0);
	} else {
		PHALCON_CPY_WRT(v2, v0);
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_role_class_entry);
		Z_ADDREF_P(v2);
		p1[0] = v2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		PHALCON_CPY_WRT(v3, i0);
	}
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v2);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_roles", sizeof("_roles")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v3);
	phalcon_array_append(t1, v3 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_roles", strlen("_roles"), t1 TSRMLS_CC);
	PHALCON_INIT_VAR(t2);
	ZVAL_BOOL(t2, 1);
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t2);
	phalcon_array_update(t3, v2, t2 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_rolesNames", strlen("_rolesNames"), t3 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, "_defaultAccess", sizeof("_defaultAccess")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t5);
	phalcon_read_property(&t5, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t5) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t6);
		phalcon_array_fetch(&t6, t5, v2, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t6) > 1) {
		zval *new_zv;
		Z_DELREF_P(t6);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t6);
		t6 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update(t5, v2, t6 TSRMLS_CC);
	}
	Z_ADDREF_P(t6);
	if (Z_TYPE_P(t6) != IS_ARRAY) {
		convert_to_array(t6);
		phalcon_array_update(t5, v2, t6 TSRMLS_CC);
	}
	if (Z_TYPE_P(t6) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t7);
		phalcon_array_fetch_string(&t7, t6, "*", strlen("*"), PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t7) > 1) {
		zval *new_zv;
		Z_DELREF_P(t7);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t7);
		t7 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update_string(t6, "*", strlen("*"), t7 TSRMLS_CC);
	}
	Z_ADDREF_P(t7);
	if (Z_TYPE_P(t7) != IS_ARRAY) {
		convert_to_array(t7);
		phalcon_array_update_string(t6, "*", strlen("*"), t7 TSRMLS_CC);
	}
	Z_ADDREF_P(t4);
	phalcon_array_update_string(t7, "*", strlen("*"), t4 TSRMLS_CC);
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		Z_ADDREF_P(v2);
		p2[0] = v2;
		Z_ADDREF_P(v1);
		p2[1] = v1;
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "addinherit", 2, p2, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p2[0]);
		Z_DELREF_P(p2[1]);
		PHALCON_RETURN_DZVAL(r1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Do a role inherit from another existing role
 *
 * @param string $roleName
 * @param string $roleToInherit
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	if (!zend_is_true(r0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	if (PHALCON_COMPARE_STRING(v1, "")) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_BOTH(r1,  "Role '", v1, "' does not exist in the role list");
		Z_ADDREF_P(r1);
		p0[0] = r1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		Z_DELREF_P(p0[0]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		if (Z_TYPE_P(v1) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v1);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_c945_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_c945_0;
			}
			PHALCON_INIT_VAR(v2);
			ZVAL_ZVAL(v2, *hd, 1, 0);
			PHALCON_INIT_VAR(r2);
			is_equal_function(r2, v2, v0 TSRMLS_CC);
			if (zend_is_true(r2)) {
				goto fes_c945_0;
			}
			PHALCON_INIT_VAR(t1);
			phalcon_read_property(&t1, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			eval_int = phalcon_array_isset(t1, v2);
			PHALCON_INIT_VAR(r3);
			ZVAL_BOOL(r3, eval_int);
			if (!zend_is_true(r3)) {
				PHALCON_INIT_VAR(i1);
				object_init_ex(i1, phalcon_acl_exception_class_entry);
				PHALCON_INIT_VAR(r4);
				PHALCON_CONCAT_BOTH(r4,  "Role '", v2, "' does not exist in the role list");
				Z_ADDREF_P(r4);
				p1[0] = r4;
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p1, PHALCON_CALL_CHECK);
				Z_DELREF_P(p1[0]);
				return phalcon_throw_exception(i1 TSRMLS_CC);
			}
			PHALCON_INIT_VAR(t2);
			phalcon_read_property(&t2, this_ptr, "_roleInherits", sizeof("_roleInherits")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (Z_TYPE_P(t2) == IS_ARRAY) {
				PHALCON_INIT_VAR(t3);
				phalcon_array_fetch(&t3, t2, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
			}
			if (Z_REFCOUNT_P(t3) > 1) {
				zval *new_zv;
				Z_DELREF_P(t3);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, t3);
				t3 = new_zv;
				zval_copy_ctor(new_zv);
				phalcon_array_update(t2, v0, t3 TSRMLS_CC);
			}
			Z_ADDREF_P(t3);
			if (Z_TYPE_P(t3) != IS_ARRAY) {
				convert_to_array(t3);
				phalcon_array_update(t2, v0, t3 TSRMLS_CC);
			}
			Z_ADDREF_P(v2);
			phalcon_array_append(t3, v2 TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_roleInherits", strlen("_roleInherits"), t2 TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_c945_0;
			fee_c945_0:
			if(0){ };
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(r5);
		is_equal_function(r5, v1, v0 TSRMLS_CC);
		if (zend_is_true(r5)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		PHALCON_ALLOC_ZVAL_MM(t4);
		phalcon_read_property(&t4, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(t4, v1);
		PHALCON_INIT_VAR(r6);
		ZVAL_BOOL(r6, eval_int);
		if (!zend_is_true(r6)) {
			PHALCON_ALLOC_ZVAL_MM(i2);
			object_init_ex(i2, phalcon_acl_exception_class_entry);
			PHALCON_ALLOC_ZVAL_MM(r7);
			PHALCON_CONCAT_BOTH(r7,  "Role '", v1, "' does not exist in the role list");
			Z_ADDREF_P(r7);
			p2[0] = r7;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p2, PHALCON_CALL_CHECK);
			Z_DELREF_P(p2[0]);
			return phalcon_throw_exception(i2 TSRMLS_CC);
		}
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_read_property(&t5, this_ptr, "_roleInherits", sizeof("_roleInherits")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(t5) == IS_ARRAY) {
			PHALCON_ALLOC_ZVAL_MM(t6);
			phalcon_array_fetch(&t6, t5, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t6) > 1) {
			zval *new_zv;
			Z_DELREF_P(t6);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, t6);
			t6 = new_zv;
			zval_copy_ctor(new_zv);
			phalcon_array_update(t5, v0, t6 TSRMLS_CC);
		}
		Z_ADDREF_P(t6);
		if (Z_TYPE_P(t6) != IS_ARRAY) {
			convert_to_array(t6);
			phalcon_array_update(t5, v0, t6 TSRMLS_CC);
		}
		Z_ADDREF_P(v1);
		phalcon_array_append(t6, v1 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_roleInherits", strlen("_roleInherits"), t5 TSRMLS_CC);
	}
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_rebuildaccesslist", PHALCON_CALL_DEFAULT);
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

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
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

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_resourcesNames", sizeof("_resourcesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
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

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v1, a0);
	}
	
	if (Z_TYPE_P(v0) == IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, v0, "getname", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v2, r0);
		PHALCON_CPY_WRT(v3, v0);
	} else {
		PHALCON_CPY_WRT(v2, v0);
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_resource_class_entry);
		Z_ADDREF_P(v2);
		p1[0] = v2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		PHALCON_CPY_WRT(v3, i0);
	}
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_resourcesNames", sizeof("_resourcesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v2);
	PHALCON_INIT_VAR(r1);
	ZVAL_BOOL(r1, eval_int);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_resources", sizeof("_resources")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(v3);
		phalcon_array_append(t1, v3 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_resources", strlen("_resources"), t1 TSRMLS_CC);
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(a1);
		phalcon_array_update(t2, v2, a1 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_accessList", strlen("_accessList"), t2 TSRMLS_CC);
		PHALCON_INIT_VAR(t3);
		ZVAL_BOOL(t3, 1);
		PHALCON_ALLOC_ZVAL_MM(t4);
		phalcon_read_property(&t4, this_ptr, "_resourcesNames", sizeof("_resourcesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t3);
		phalcon_array_update(t4, v2, t3 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_resourcesNames", strlen("_resourcesNames"), t4 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r2);
	Z_ADDREF_P(v2);
	p2[0] = v2;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "addresourceaccess", 2, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	PHALCON_RETURN_DZVAL(r2);
}

/**
 * Adds access to resources
 *
 * @param string $resourceName
 * @param mixed $accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResourceAccess){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_resourcesNames", sizeof("_resourcesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_BOTH(r1,  "Resource '", v0, "' does not exist in ACL");
		Z_ADDREF_P(r1);
		p0[0] = r1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		Z_DELREF_P(p0[0]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		if (Z_TYPE_P(v1) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v1);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_c945_1:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_c945_1;
			}
			PHALCON_INIT_VAR(v2);
			ZVAL_ZVAL(v2, *hd, 1, 0);
			PHALCON_INIT_VAR(t1);
			phalcon_read_property(&t1, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_INIT_VAR(r2);
			phalcon_array_fetch(&r2, t1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			eval_int = phalcon_array_isset(r2, v2);
			PHALCON_INIT_VAR(r3);
			ZVAL_BOOL(r3, eval_int);
			if (!zend_is_true(r3)) {
				PHALCON_INIT_VAR(t2);
				ZVAL_BOOL(t2, 1);
				PHALCON_INIT_VAR(t3);
				phalcon_read_property(&t3, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				if (Z_TYPE_P(t3) == IS_ARRAY) {
					PHALCON_INIT_VAR(t4);
					phalcon_array_fetch(&t4, t3, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t4) > 1) {
					zval *new_zv;
					Z_DELREF_P(t4);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, t4);
					t4 = new_zv;
					zval_copy_ctor(new_zv);
					phalcon_array_update(t3, v0, t4 TSRMLS_CC);
				}
				Z_ADDREF_P(t4);
				if (Z_TYPE_P(t4) != IS_ARRAY) {
					convert_to_array(t4);
					phalcon_array_update(t3, v0, t4 TSRMLS_CC);
				}
				Z_ADDREF_P(t2);
				phalcon_array_update(t4, v2, t2 TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, "_accessList", strlen("_accessList"), t3 TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_c945_1;
			fee_c945_1:
			if(0){ };
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_read_property(&t5, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch(&r4, t5, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(r4, v1);
		PHALCON_INIT_VAR(r5);
		ZVAL_BOOL(r5, eval_int);
		if (!zend_is_true(r5)) {
			PHALCON_INIT_VAR(t6);
			ZVAL_BOOL(t6, 1);
			PHALCON_ALLOC_ZVAL_MM(t7);
			phalcon_read_property(&t7, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (Z_TYPE_P(t7) == IS_ARRAY) {
				PHALCON_ALLOC_ZVAL_MM(t8);
				phalcon_array_fetch(&t8, t7, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
			}
			if (Z_REFCOUNT_P(t8) > 1) {
				zval *new_zv;
				Z_DELREF_P(t8);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, t8);
				t8 = new_zv;
				zval_copy_ctor(new_zv);
				phalcon_array_update(t7, v0, t8 TSRMLS_CC);
			}
			Z_ADDREF_P(t8);
			if (Z_TYPE_P(t8) != IS_ARRAY) {
				convert_to_array(t8);
				phalcon_array_update(t7, v0, t8 TSRMLS_CC);
			}
			Z_ADDREF_P(t6);
			phalcon_array_update(t8, v1, t6 TSRMLS_CC);
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

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		if (Z_TYPE_P(v1) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v1);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_c945_2:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_c945_2;
			}
			PHALCON_INIT_VAR(v2);
			ZVAL_ZVAL(v2, *hd, 1, 0);
			PHALCON_INIT_VAR(t0);
			phalcon_read_property(&t0, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_INIT_VAR(r0);
			phalcon_array_fetch(&r0, t0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_SEPARATE_NMO(r0);
			phalcon_array_unset(r0, v2);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_c945_2;
			fee_c945_2:
			if(0){ };
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch(&r1, t1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_SEPARATE_NMO(r1);
		phalcon_array_unset(r1, v1);
	}
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_rebuildaccesslist", PHALCON_CALL_DEFAULT);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Acl_Adapter_Memory, _allowOrDeny){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL, *t15 = NULL, *t16 = NULL, *t17 = NULL, *t18 = NULL, *t19 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_BOTH(r1,  "Role \"", v0, "\" does not exist in ACL");
		Z_ADDREF_P(r1);
		p0[0] = r1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		Z_DELREF_P(p0[0]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_resourcesNames", sizeof("_resourcesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t1, v1);
	PHALCON_INIT_VAR(r2);
	ZVAL_BOOL(r2, eval_int);
	if (!zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_acl_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "Resource \"", v1, "\" does not exist in ACL");
		Z_ADDREF_P(r3);
		p1[0] = r3;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	if (Z_TYPE_P(v2) == IS_ARRAY) { 
		if (Z_TYPE_P(v2) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v2);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_c945_3:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_c945_3;
			}
			PHALCON_INIT_VAR(v4);
			ZVAL_ZVAL(v4, *hd, 1, 0);
			PHALCON_INIT_VAR(t2);
			phalcon_read_property(&t2, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_INIT_VAR(r4);
			phalcon_array_fetch(&r4, t2, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
			eval_int = phalcon_array_isset(r4, v4);
			PHALCON_INIT_VAR(r5);
			ZVAL_BOOL(r5, eval_int);
			if (!zend_is_true(r5)) {
				PHALCON_INIT_VAR(i2);
				object_init_ex(i2, phalcon_acl_exception_class_entry);
				PHALCON_INIT_VAR(r7);
				PHALCON_CONCAT_LEFT(r7, "Acccess '", v4);
				PHALCON_INIT_VAR(r6);
				PHALCON_CONCAT_VBOTH(r6, r7, "' does not exist in resource '", v1);
				PHALCON_INIT_VAR(r8);
				PHALCON_CONCAT_RIGHT(r8, r6, "' in ACL");
				Z_ADDREF_P(r8);
				p2[0] = r8;
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p2, PHALCON_CALL_CHECK);
				Z_DELREF_P(p2[0]);
				return phalcon_throw_exception(i2 TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_c945_3;
			fee_c945_3:
			if(0){ };
		}
		if (Z_TYPE_P(v2) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah1 = Z_ARRVAL_P(v2);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_c945_4:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_c945_4;
			}
			PHALCON_INIT_VAR(v4);
			ZVAL_ZVAL(v4, *hd, 1, 0);
			PHALCON_INIT_VAR(t3);
			phalcon_read_property(&t3, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (Z_TYPE_P(t3) == IS_ARRAY) {
				PHALCON_INIT_VAR(t4);
				phalcon_array_fetch(&t4, t3, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
			}
			if (Z_REFCOUNT_P(t4) > 1) {
				zval *new_zv;
				Z_DELREF_P(t4);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, t4);
				t4 = new_zv;
				zval_copy_ctor(new_zv);
				phalcon_array_update(t3, v0, t4 TSRMLS_CC);
			}
			Z_ADDREF_P(t4);
			if (Z_TYPE_P(t4) != IS_ARRAY) {
				convert_to_array(t4);
				phalcon_array_update(t3, v0, t4 TSRMLS_CC);
			}
			if (Z_TYPE_P(t4) == IS_ARRAY) {
				PHALCON_INIT_VAR(t5);
				phalcon_array_fetch(&t5, t4, v1, PHALCON_SILENT_FETCH TSRMLS_CC);
			}
			if (Z_REFCOUNT_P(t5) > 1) {
				zval *new_zv;
				Z_DELREF_P(t5);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, t5);
				t5 = new_zv;
				zval_copy_ctor(new_zv);
				phalcon_array_update(t4, v1, t5 TSRMLS_CC);
			}
			Z_ADDREF_P(t5);
			if (Z_TYPE_P(t5) != IS_ARRAY) {
				convert_to_array(t5);
				phalcon_array_update(t4, v1, t5 TSRMLS_CC);
			}
			Z_ADDREF_P(v3);
			phalcon_array_update(t5, v4, v3 TSRMLS_CC);
			PHALCON_INIT_VAR(t6);
			phalcon_read_property(&t6, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_INIT_VAR(r9);
			phalcon_array_fetch(&r9, t6, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_INIT_VAR(r10);
			phalcon_array_fetch(&r10, r9, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
			eval_int = phalcon_array_isset_string(r10, "*", strlen("*")+1);
			PHALCON_INIT_VAR(r11);
			ZVAL_BOOL(r11, eval_int);
			if (!zend_is_true(r11)) {
				PHALCON_INIT_VAR(t7);
				phalcon_read_property(&t7, this_ptr, "_defaultAccess", sizeof("_defaultAccess")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_INIT_VAR(t8);
				phalcon_read_property(&t8, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				if (Z_TYPE_P(t8) == IS_ARRAY) {
					PHALCON_INIT_VAR(t9);
					phalcon_array_fetch(&t9, t8, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t9) > 1) {
					zval *new_zv;
					Z_DELREF_P(t9);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, t9);
					t9 = new_zv;
					zval_copy_ctor(new_zv);
					phalcon_array_update(t8, v0, t9 TSRMLS_CC);
				}
				Z_ADDREF_P(t9);
				if (Z_TYPE_P(t9) != IS_ARRAY) {
					convert_to_array(t9);
					phalcon_array_update(t8, v0, t9 TSRMLS_CC);
				}
				if (Z_TYPE_P(t9) == IS_ARRAY) {
					PHALCON_INIT_VAR(t10);
					phalcon_array_fetch(&t10, t9, v1, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t10) > 1) {
					zval *new_zv;
					Z_DELREF_P(t10);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, t10);
					t10 = new_zv;
					zval_copy_ctor(new_zv);
					phalcon_array_update(t9, v1, t10 TSRMLS_CC);
				}
				Z_ADDREF_P(t10);
				if (Z_TYPE_P(t10) != IS_ARRAY) {
					convert_to_array(t10);
					phalcon_array_update(t9, v1, t10 TSRMLS_CC);
				}
				Z_ADDREF_P(t7);
				phalcon_array_update_string(t10, "*", strlen("*"), t7 TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_c945_4;
			fee_c945_4:
			if(0){ };
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(t11);
		phalcon_read_property(&t11, this_ptr, "_accessList", sizeof("_accessList")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r12);
		phalcon_array_fetch(&r12, t11, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(r12, v2);
		PHALCON_INIT_VAR(r13);
		ZVAL_BOOL(r13, eval_int);
		if (!zend_is_true(r13)) {
			PHALCON_ALLOC_ZVAL_MM(i3);
			object_init_ex(i3, phalcon_acl_exception_class_entry);
			PHALCON_ALLOC_ZVAL_MM(r15);
			PHALCON_CONCAT_LEFT(r15, "Acccess '", v2);
			PHALCON_ALLOC_ZVAL_MM(r14);
			PHALCON_CONCAT_VBOTH(r14, r15, "' does not exist in resource '", v1);
			PHALCON_ALLOC_ZVAL_MM(r16);
			PHALCON_CONCAT_RIGHT(r16, r14, "' in ACL");
			Z_ADDREF_P(r16);
			p3[0] = r16;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i3, "__construct", 1, p3, PHALCON_CALL_CHECK);
			Z_DELREF_P(p3[0]);
			return phalcon_throw_exception(i3 TSRMLS_CC);
		}
		PHALCON_ALLOC_ZVAL_MM(t12);
		phalcon_read_property(&t12, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(t12) == IS_ARRAY) {
			PHALCON_ALLOC_ZVAL_MM(t13);
			phalcon_array_fetch(&t13, t12, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t13) > 1) {
			zval *new_zv;
			Z_DELREF_P(t13);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, t13);
			t13 = new_zv;
			zval_copy_ctor(new_zv);
			phalcon_array_update(t12, v0, t13 TSRMLS_CC);
		}
		Z_ADDREF_P(t13);
		if (Z_TYPE_P(t13) != IS_ARRAY) {
			convert_to_array(t13);
			phalcon_array_update(t12, v0, t13 TSRMLS_CC);
		}
		if (Z_TYPE_P(t13) == IS_ARRAY) {
			PHALCON_ALLOC_ZVAL_MM(t14);
			phalcon_array_fetch(&t14, t13, v1, PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t14) > 1) {
			zval *new_zv;
			Z_DELREF_P(t14);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, t14);
			t14 = new_zv;
			zval_copy_ctor(new_zv);
			phalcon_array_update(t13, v1, t14 TSRMLS_CC);
		}
		Z_ADDREF_P(t14);
		if (Z_TYPE_P(t14) != IS_ARRAY) {
			convert_to_array(t14);
			phalcon_array_update(t13, v1, t14 TSRMLS_CC);
		}
		Z_ADDREF_P(v3);
		phalcon_array_update(t14, v2, v3 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t15);
		phalcon_read_property(&t15, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r17);
		phalcon_array_fetch(&r17, t15, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r18);
		phalcon_array_fetch(&r18, r17, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset_string(r18, "*", strlen("*")+1);
		PHALCON_INIT_VAR(r19);
		ZVAL_BOOL(r19, eval_int);
		if (!zend_is_true(r19)) {
			PHALCON_ALLOC_ZVAL_MM(t16);
			phalcon_read_property(&t16, this_ptr, "_defaultAccess", sizeof("_defaultAccess")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(t17);
			phalcon_read_property(&t17, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (Z_TYPE_P(t17) == IS_ARRAY) {
				PHALCON_ALLOC_ZVAL_MM(t18);
				phalcon_array_fetch(&t18, t17, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
			}
			if (Z_REFCOUNT_P(t18) > 1) {
				zval *new_zv;
				Z_DELREF_P(t18);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, t18);
				t18 = new_zv;
				zval_copy_ctor(new_zv);
				phalcon_array_update(t17, v0, t18 TSRMLS_CC);
			}
			Z_ADDREF_P(t18);
			if (Z_TYPE_P(t18) != IS_ARRAY) {
				convert_to_array(t18);
				phalcon_array_update(t17, v0, t18 TSRMLS_CC);
			}
			if (Z_TYPE_P(t18) == IS_ARRAY) {
				PHALCON_ALLOC_ZVAL_MM(t19);
				phalcon_array_fetch(&t19, t18, v1, PHALCON_SILENT_FETCH TSRMLS_CC);
			}
			if (Z_REFCOUNT_P(t19) > 1) {
				zval *new_zv;
				Z_DELREF_P(t19);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, t19);
				t19 = new_zv;
				zval_copy_ctor(new_zv);
				phalcon_array_update(t18, v1, t19 TSRMLS_CC);
			}
			Z_ADDREF_P(t19);
			if (Z_TYPE_P(t19) != IS_ARRAY) {
				convert_to_array(t19);
				phalcon_array_update(t18, v1, t19 TSRMLS_CC);
			}
			Z_ADDREF_P(t16);
			phalcon_array_update_string(t19, "*", strlen("*"), t16 TSRMLS_CC);
		}
	}
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_rebuildaccesslist", PHALCON_CALL_DEFAULT);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
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

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_INIT_VAR(p0[3]);
	ZVAL_LONG(p0[3], 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "_allowordeny", 4, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
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

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_INIT_VAR(p0[3]);
	ZVAL_LONG(p0[3], 0);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_allowordeny", 4, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Check whether a role is allowed to access an action from a resource
 *
 * 
 *
 * @param string $role
 * @param string $resource
 * @param mixed $accessList
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v1);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_resourcesNames", sizeof("_resourcesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t0);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "in_array", v1, t0, 0x019);
	Z_DELREF_P(v1);
	Z_DELREF_P(t0);
	if (!zend_is_true(r0)) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, t1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r1);
	if (Z_TYPE_P(v3) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v3);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_c945_5:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_c945_5;
		} else {
			PHALCON_INIT_VAR(v5);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v5, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v5, num);
				}
			}
		}
		PHALCON_INIT_VAR(v4);
		ZVAL_ZVAL(v4, *hd, 1, 0);
		PHALCON_INIT_VAR(r2);
		is_equal_function(r2, v5, v1 TSRMLS_CC);
		if (zend_is_true(r2)) {
			eval_int = phalcon_array_isset(v4, v2);
			if (eval_int) {
				PHALCON_INIT_VAR(r3);
				phalcon_array_fetch(&r3, v4, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_RETURN_CHECK_CTOR(r3);
			}
			PHALCON_INIT_VAR(r4);
			phalcon_array_fetch_string(&r4, v4, "*", strlen("*"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_RETURN_CHECK_CTOR(r4);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_c945_5;
		fee_c945_5:
		if(0){ };
	}
	if (Z_TYPE_P(v3) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah1 = Z_ARRVAL_P(v3);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
		fes_c945_6:
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto fee_c945_6;
		} else {
			PHALCON_INIT_VAR(v5);
			htype = zend_hash_get_current_key_ex(ah1, &index, &index_len, &num, 0, &hp1);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v5, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v5, num);
				}
			}
		}
		PHALCON_INIT_VAR(v4);
		ZVAL_ZVAL(v4, *hd, 1, 0);
		eval_int = phalcon_array_isset_string(v4, "*", strlen("*")+1);
		if (eval_int) {
			eval_int = phalcon_array_isset(v4, v2);
			if (eval_int) {
				PHALCON_INIT_VAR(r5);
				phalcon_array_fetch(&r5, v4, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_RETURN_CHECK_CTOR(r5);
			}
			PHALCON_INIT_VAR(r6);
			phalcon_array_fetch_string(&r6, v4, "*", strlen("*"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_RETURN_CHECK_CTOR(r6);
		}
		zend_hash_move_forward_ex(ah1, &hp1);
		goto fes_c945_6;
		fee_c945_6:
		if(0){ };
	}
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Rebuild the list of access from the inherit lists
 *
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, _rebuildAccessList){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;
	HashTable *ah0, *ah1, *ah2, *ah3;
	HashPosition hp0, hp1, hp2, hp3;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_roles", sizeof("_roles")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "count", t0, 0x007);
	PHALCON_CPY_WRT(v0, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	mul_function(r2, v0, v0 TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 2);
	PHALCON_ALLOC_ZVAL_MM(r3);
	div_function(r3, r2, t1 TSRMLS_CC);
	Z_ADDREF_P(r3);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "ceil", r3, 0x01A);
	Z_DELREF_P(r3);
	PHALCON_CPY_WRT(v1, r1);
	PHALCON_INIT_VAR(v2);
	ZVAL_LONG(v2, 0);
	fs_c945_7:
	PHALCON_INIT_VAR(r4);
	is_smaller_or_equal_function(r4, v2, v1 TSRMLS_CC);
	if (!zend_is_true(r4)) {
		goto fe_c945_7;
	}
	PHALCON_INIT_VAR(t2);
	phalcon_read_property(&t2, this_ptr, "_rolesNames", sizeof("_rolesNames")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t2) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(t2);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_c945_8:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_c945_8;
		} else {
			PHALCON_INIT_VAR(v4);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v4, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v4, num);
				}
			}
		}
		PHALCON_INIT_VAR(v3);
		ZVAL_ZVAL(v3, *hd, 1, 0);
		PHALCON_INIT_VAR(t3);
		phalcon_read_property(&t3, this_ptr, "_roleInherits", sizeof("_roleInherits")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(t3, v4);
		if (eval_int) {
			PHALCON_INIT_VAR(t4);
			phalcon_read_property(&t4, this_ptr, "_roleInherits", sizeof("_roleInherits")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_INIT_VAR(r5);
			phalcon_array_fetch(&r5, t4, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (Z_TYPE_P(r5) != IS_ARRAY) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
			} else {
				ah1 = Z_ARRVAL_P(r5);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				fes_c945_9:
				if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
					goto fee_c945_9;
				}
				PHALCON_INIT_VAR(v5);
				ZVAL_ZVAL(v5, *hd, 1, 0);
				PHALCON_INIT_VAR(t5);
				phalcon_read_property(&t5, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				eval_int = phalcon_array_isset(t5, v5);
				if (eval_int) {
					PHALCON_INIT_VAR(t6);
					phalcon_read_property(&t6, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_INIT_VAR(r6);
					phalcon_array_fetch(&r6, t6, v5, PHALCON_NOISY_FETCH TSRMLS_CC);
					if (Z_TYPE_P(r6) != IS_ARRAY) {
						php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
					} else {
						ah2 = Z_ARRVAL_P(r6);
						zend_hash_internal_pointer_reset_ex(ah2, &hp2);
						fes_c945_10:
						if(zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS){
							goto fee_c945_10;
						} else {
							PHALCON_INIT_VAR(v7);
							htype = zend_hash_get_current_key_ex(ah2, &index, &index_len, &num, 0, &hp2);
							if (htype == HASH_KEY_IS_STRING) {
								ZVAL_STRINGL(v7, index, index_len-1, 1);
							} else {
								if (htype == HASH_KEY_IS_LONG) {
									ZVAL_LONG(v7, num);
								}
							}
						}
						PHALCON_INIT_VAR(v6);
						ZVAL_ZVAL(v6, *hd, 1, 0);
						if (Z_TYPE_P(v6) != IS_ARRAY) {
							php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
						} else {
							ah3 = Z_ARRVAL_P(v6);
							zend_hash_internal_pointer_reset_ex(ah3, &hp3);
							fes_c945_11:
							if(zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) != SUCCESS){
								goto fee_c945_11;
							} else {
								PHALCON_INIT_VAR(v9);
								htype = zend_hash_get_current_key_ex(ah3, &index, &index_len, &num, 0, &hp3);
								if (htype == HASH_KEY_IS_STRING) {
									ZVAL_STRINGL(v9, index, index_len-1, 1);
								} else {
									if (htype == HASH_KEY_IS_LONG) {
										ZVAL_LONG(v9, num);
									}
								}
							}
							PHALCON_INIT_VAR(v8);
							ZVAL_ZVAL(v8, *hd, 1, 0);
							PHALCON_INIT_VAR(t7);
							phalcon_read_property(&t7, this_ptr, "_access", sizeof("_access")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
							if (Z_TYPE_P(t7) == IS_ARRAY) {
								PHALCON_INIT_VAR(t8);
								phalcon_array_fetch(&t8, t7, v4, PHALCON_SILENT_FETCH TSRMLS_CC);
							}
							if (Z_REFCOUNT_P(t8) > 1) {
								zval *new_zv;
								Z_DELREF_P(t8);
								ALLOC_ZVAL(new_zv);
								INIT_PZVAL_COPY(new_zv, t8);
								t8 = new_zv;
								zval_copy_ctor(new_zv);
								phalcon_array_update(t7, v4, t8 TSRMLS_CC);
							}
							Z_ADDREF_P(t8);
							if (Z_TYPE_P(t8) != IS_ARRAY) {
								convert_to_array(t8);
								phalcon_array_update(t7, v4, t8 TSRMLS_CC);
							}
							if (Z_TYPE_P(t8) == IS_ARRAY) {
								PHALCON_INIT_VAR(t9);
								phalcon_array_fetch(&t9, t8, v7, PHALCON_SILENT_FETCH TSRMLS_CC);
							}
							if (Z_REFCOUNT_P(t9) > 1) {
								zval *new_zv;
								Z_DELREF_P(t9);
								ALLOC_ZVAL(new_zv);
								INIT_PZVAL_COPY(new_zv, t9);
								t9 = new_zv;
								zval_copy_ctor(new_zv);
								phalcon_array_update(t8, v7, t9 TSRMLS_CC);
							}
							Z_ADDREF_P(t9);
							if (Z_TYPE_P(t9) != IS_ARRAY) {
								convert_to_array(t9);
								phalcon_array_update(t8, v7, t9 TSRMLS_CC);
							}
							Z_ADDREF_P(v8);
							phalcon_array_update(t9, v9, v8 TSRMLS_CC);
							zend_hash_move_forward_ex(ah3, &hp3);
							goto fes_c945_11;
							fee_c945_11:
							if(0){ };
						}
						zend_hash_move_forward_ex(ah2, &hp2);
						goto fes_c945_10;
						fee_c945_10:
						if(0){ };
					}
				}
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_c945_9;
				fee_c945_9:
				if(0){ };
			}
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_c945_8;
		fee_c945_8:
		if(0){ };
	}
	increment_function(v2);
	goto fs_c945_7;
	fe_c945_7:
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

