
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/hash.h"


/**
 * Phalcon\Acl\Adapter\Memory
 *
 * Manages ACL lists in memory
 *
 *<code>
 *
 *	$acl = new \Phalcon\Acl\Adapter\Memory();
 *
 *	$acl->setDefaultAction(Phalcon\Acl::DENY);
 *
 *	//Register roles
 *	$roles = array(
 *		'users' => new \Phalcon\Acl\Role('Users'),
 *		'guests' => new \Phalcon\Acl\Role('Guests')
 *	);
 *	foreach ($roles as $role) {
 *		$acl->addRole($role);
 *	}
 *
 *	//Private area resources
 *	$privateResources = array(
 *		'companies' => array('index', 'search', 'new', 'edit', 'save', 'create', 'delete'),
 *		'products' => array('index', 'search', 'new', 'edit', 'save', 'create', 'delete'),
 *		'invoices' => array('index', 'profile')
 *	);
 *	foreach ($privateResources as $resource => $actions) {
 *		$acl->addResource(new Phalcon\Acl\Resource($resource), $actions);
 *	}
 *
 *	//Public area resources
 *	$publicResources = array(
 *		'index' => array('index'),
 *		'about' => array('index'),
 *		'session' => array('index', 'register', 'start', 'end'),
 *		'contact' => array('index', 'send')
 *	);
 *	foreach ($publicResources as $resource => $actions) {
 *		$acl->addResource(new Phalcon\Acl\Resource($resource), $actions);
 *	}
 *
 *	//Grant access to public areas to both users and guests
 *	foreach ($roles as $role){
 *		foreach ($publicResources as $resource => $actions) {
 *			$acl->allow($role->getName(), $resource, '*');
 *		}
 *	}
 *
 *	//Grant access to private area to role Users
 *	foreach ($privateResources as $resource => $actions) {
 * 		foreach ($actions as $action) {
 *			$acl->allow('Users', $resource, $action);
 *		}
 *	}
 *
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter_Memory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Acl\\Adapter, Memory, phalcon, acl_adapter_memory, phalcon_acl_adapter_ce, phalcon_acl_adapter_memory_method_entry, 0);

	/**
	 * Roles Names
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_rolesNames"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Roles
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_roles"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Resource Names
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_resourcesNames"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Resources
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_resources"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Access
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_access"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Role Inherits
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_roleInherits"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Access List
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_accessList"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Function List
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_func"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Default action for no arguments is allow
	 *
	 * @var mixed
	 */
	zend_declare_property_long(phalcon_acl_adapter_memory_ce, SL("_noArgumentsDefaultAction"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Acl\Adapter\Memory constructor
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, __construct) {

	zval _0, _1;
	zval __$true;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("*"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("_resourcesNames"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("*!*"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("_accessList"), &_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a role to the ACL list. Second parameter allows inheriting access data from other existing role
 *
 * Example:
 * <code>
 * 	$acl->addRole(new Phalcon\Acl\Role('administrator'), 'consultant');
 * 	$acl->addRole('administrator', 'consultant');
 * </code>
 *
 * @param  array|string         accessInherits
 * @param  RoleInterface|string role
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addRole) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *role, role_sub, *accessInherits = NULL, accessInherits_sub, __$true, __$null, roleName, roleObject, _1, _2, _3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&role_sub);
	ZVAL_UNDEF(&accessInherits_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&roleObject);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &role, &accessInherits);

	if (!accessInherits) {
		accessInherits = &accessInherits_sub;
		accessInherits = &__$null;
	}


	_0 = Z_TYPE_P(role) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(role, phalcon_acl_roleinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&roleName, role, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&roleObject, role);
	} else if (Z_TYPE_P(role) == IS_STRING) {
		ZEPHIR_CPY_WRT(&roleName, role);
		ZEPHIR_INIT_NVAR(&roleObject);
		object_init_ex(&roleObject, phalcon_acl_role_ce);
		ZEPHIR_CALL_METHOD(NULL, &roleObject, "__construct", NULL, 82, role);
		zephir_check_call_status();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Role must be either an string or implement RoleInterface", "phalcon/acl/adapter/memory.zep", 187);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("_rolesNames"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &roleName)) {
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_array_append(this_ptr, SL("_roles"), &roleObject TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_rolesNames"), &roleName, &__$true TSRMLS_CC);
	zephir_read_property(&_2, this_ptr, SL("_defaultAccess"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VS(&_3, &roleName, "!*!*");
	zephir_update_property_array(this_ptr, SL("_access"), &_3, &_2 TSRMLS_CC);
	if (Z_TYPE_P(accessInherits) != IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addinherit", NULL, 0, &roleName, accessInherits);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Do a role inherit from another existing role
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit) {

	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *roleToInherit, roleToInherit_sub, __$true, roleInheritName, rolesNames, deepInheritName, _2, _9, _0$$3, _3$$6, _4$$6, *_5$$6, _7$$8, _8$$8;
	zval roleName, _1$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&roleToInherit_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&roleInheritName);
	ZVAL_UNDEF(&rolesNames);
	ZVAL_UNDEF(&deepInheritName);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &roleName_param, &roleToInherit);

	zephir_get_strval(&roleName, roleName_param);


	ZEPHIR_OBS_VAR(&rolesNames);
	zephir_read_property(&rolesNames, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(&rolesNames, &roleName))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SVS(&_1$$3, "Role '", &roleName, "' does not exist in the role list");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 9, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/acl/adapter/memory.zep", 214 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(roleToInherit) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&roleInheritName, roleToInherit, "getname", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&roleInheritName, roleToInherit);
	}
	zephir_read_property(&_2, this_ptr, SL("_roleInherits"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_2, &roleInheritName)) {
		zephir_read_property(&_3$$6, this_ptr, SL("_roleInherits"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_4$$6, &_3$$6, &roleInheritName, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 227 TSRMLS_CC);
		zephir_is_iterable(&_4$$6, 0, "phalcon/acl/adapter/memory.zep", 230);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4$$6), _5$$6)
		{
			ZEPHIR_INIT_NVAR(&deepInheritName);
			ZVAL_COPY(&deepInheritName, _5$$6);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addinherit", &_6, 83, &roleName, &deepInheritName);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&deepInheritName);
	}
	if (!(zephir_array_isset(&rolesNames, &roleInheritName))) {
		ZEPHIR_INIT_VAR(&_7$$8);
		object_init_ex(&_7$$8, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_8$$8);
		ZEPHIR_CONCAT_SVS(&_8$$8, "Role '", &roleInheritName, "' (to inherit) does not exist in the role list");
		ZEPHIR_CALL_METHOD(NULL, &_7$$8, "__construct", NULL, 9, &_8$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$8, "phalcon/acl/adapter/memory.zep", 236 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_EQUAL(&roleName, &roleInheritName)) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_9, this_ptr, SL("_roleInherits"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_9, &roleName))) {
		zephir_update_property_array(this_ptr, SL("_roleInherits"), &roleName, &__$true TSRMLS_CC);
	}
	zephir_update_property_array_multi(this_ptr, SL("_roleInherits"), &roleInheritName TSRMLS_CC, SL("za"), 2, &roleName);
	RETURN_MM_BOOL(1);

}

/**
 * Check whether role exist in the roles list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isRole) {

	zval *roleName_param = NULL, _0;
	zval roleName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &roleName_param);

	zephir_get_strval(&roleName, roleName_param);


	zephir_read_property(&_0, this_ptr, SL("_rolesNames"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &roleName));

}

/**
 * Check whether resource exist in the resources list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isResource) {

	zval *resourceName_param = NULL, _0;
	zval resourceName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &resourceName_param);

	zephir_get_strval(&resourceName, resourceName_param);


	zephir_read_property(&_0, this_ptr, SL("_resourcesNames"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &resourceName));

}

/**
 * Adds a resource to the ACL list
 *
 * Access names can be a particular action, by example
 * search, update, delete, etc or a list of them
 *
 * Example:
 * <code>
 * //Add a resource to the the list allowing access to an action
 * $acl->addResource(new Phalcon\Acl\Resource('customers'), 'search');
 * $acl->addResource('customers', 'search');
 *
 * //Add a resource  with an access list
 * $acl->addResource(new Phalcon\Acl\Resource('customers'), array('create', 'search'));
 * $acl->addResource('customers', array('create', 'search'));
 * </code>
 *
 * @param   Phalcon\Acl\Resource|string resourceValue
 * @param   array|string accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResource) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *resourceValue, resourceValue_sub, *accessList, accessList_sub, __$true, resourceName, resourceObject, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&resourceValue_sub);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&resourceObject);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resourceValue, &accessList);



	if (Z_TYPE_P(resourceValue) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&resourceName, resourceValue, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&resourceObject, resourceValue);
	} else {
		ZEPHIR_CPY_WRT(&resourceName, resourceValue);
		ZEPHIR_INIT_NVAR(&resourceObject);
		object_init_ex(&resourceObject, phalcon_acl_resource_ce);
		ZEPHIR_CALL_METHOD(NULL, &resourceObject, "__construct", NULL, 84, &resourceName);
		zephir_check_call_status();
	}
	zephir_read_property(&_0, this_ptr, SL("_resourcesNames"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &resourceName))) {
		zephir_update_property_array_append(this_ptr, SL("_resources"), &resourceObject TSRMLS_CC);
		zephir_update_property_array(this_ptr, SL("_resourcesNames"), &resourceName, &__$true TSRMLS_CC);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addresourceaccess", NULL, 0, &resourceName, accessList);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds access to resources
 *
 * @param array|string accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResourceAccess) {

	zend_bool exists = 0, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *resourceName_param = NULL, *accessList, accessList_sub, accessName, accessKey, _0, _1$$3, *_4$$5, _5$$7, _6$$9;
	zval resourceName, _2$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resourceName_param, &accessList);

	zephir_get_strval(&resourceName, resourceName_param);


	zephir_read_property(&_0, this_ptr, SL("_resourcesNames"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &resourceName))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Resource '", &resourceName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 9, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/acl/adapter/memory.zep", 318 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = Z_TYPE_P(accessList) != IS_ARRAY;
	if (_3) {
		_3 = Z_TYPE_P(accessList) != IS_STRING;
	}
	if (_3) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Invalid value for accessList", "phalcon/acl/adapter/memory.zep", 322);
		return;
	}
	exists = 1;
	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		zephir_is_iterable(accessList, 0, "phalcon/acl/adapter/memory.zep", 333);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(accessList), _4$$5)
		{
			ZEPHIR_INIT_NVAR(&accessName);
			ZVAL_COPY(&accessName, _4$$5);
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSV(&accessKey, &resourceName, "!", &accessName);
			if (!(zephir_array_isset(accessList, &accessKey))) {
				ZEPHIR_INIT_NVAR(&_5$$7);
				ZVAL_BOOL(&_5$$7, exists);
				zephir_update_property_array(this_ptr, SL("_accessList"), &accessKey, &_5$$7 TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		ZEPHIR_INIT_NVAR(&accessKey);
		ZEPHIR_CONCAT_VSV(&accessKey, &resourceName, "!", accessList);
		if (!(zephir_array_isset(accessList, &accessKey))) {
			ZEPHIR_INIT_VAR(&_6$$9);
			ZVAL_BOOL(&_6$$9, exists);
			zephir_update_property_array(this_ptr, SL("_accessList"), &accessKey, &_6$$9 TSRMLS_CC);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Removes an access from a resource
 *
 * @param array|string accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, dropResourceAccess) {

	zval *resourceName_param = NULL, *accessList, accessList_sub, accessName, accessKey, *_0$$3, _1$$5, _2$$8;
	zval resourceName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resourceName_param, &accessList);

	zephir_get_strval(&resourceName, resourceName_param);


	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		zephir_is_iterable(accessList, 0, "phalcon/acl/adapter/memory.zep", 359);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(accessList), _0$$3)
		{
			ZEPHIR_INIT_NVAR(&accessName);
			ZVAL_COPY(&accessName, _0$$3);
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSV(&accessKey, &resourceName, "!", &accessName);
			if (zephir_array_isset(accessList, &accessKey)) {
				zephir_read_property(&_1$$5, this_ptr, SL("_accessList"), PH_NOISY_CC | PH_READONLY);
				zephir_array_unset(&_1$$5, &accessKey, PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		if (Z_TYPE_P(accessList) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSV(&accessKey, &resourceName, "!", &accessName);
			if (zephir_array_isset(accessList, &accessKey)) {
				zephir_read_property(&_2$$8, this_ptr, SL("_accessList"), PH_NOISY_CC | PH_READONLY);
				zephir_array_unset(&_2$$8, &accessKey, PH_SEPARATE);
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if a role has access to a resource
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, _allowOrDeny) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *resourceName_param = NULL, *access, access_sub, *action, action_sub, *func = NULL, func_sub, __$null, defaultAccess, accessList, accessName, accessKey, accessKeyAll, internalAccess, _0, _3, _1$$3, _4$$4, *_6$$5, *_9$$5, _7$$7, _8$$7, _11$$14, _12$$14, _14$$17;
	zval roleName, resourceName, _2$$3, _5$$4, _10$$10, _13$$16;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_13$$16);
	ZVAL_UNDEF(&access_sub);
	ZVAL_UNDEF(&action_sub);
	ZVAL_UNDEF(&func_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&defaultAccess);
	ZVAL_UNDEF(&accessList);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&accessKeyAll);
	ZVAL_UNDEF(&internalAccess);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_14$$17);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &roleName_param, &resourceName_param, &access, &action, &func);

	zephir_get_strval(&roleName, roleName_param);
	zephir_get_strval(&resourceName, resourceName_param);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_rolesNames"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &roleName))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Role '", &roleName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 9, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/acl/adapter/memory.zep", 377 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("_resourcesNames"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_3, &resourceName))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SVS(&_5$$4, "Resource '", &resourceName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 9, &_5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/acl/adapter/memory.zep", 381 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&defaultAccess);
	zephir_read_property(&defaultAccess, this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&accessList);
	zephir_read_property(&accessList, this_ptr, SL("_accessList"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&internalAccess);
	zephir_read_property(&internalAccess, this_ptr, SL("_access"), PH_NOISY_CC);
	if (Z_TYPE_P(access) == IS_ARRAY) {
		zephir_is_iterable(access, 0, "phalcon/acl/adapter/memory.zep", 397);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(access), _6$$5)
		{
			ZEPHIR_INIT_NVAR(&accessName);
			ZVAL_COPY(&accessName, _6$$5);
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSV(&accessKey, &resourceName, "!", &accessName);
			if (!(zephir_array_isset(&accessList, &accessKey))) {
				ZEPHIR_INIT_NVAR(&_7$$7);
				object_init_ex(&_7$$7, phalcon_acl_exception_ce);
				ZEPHIR_INIT_LNVAR(_8$$7);
				ZEPHIR_CONCAT_SVSVS(&_8$$7, "Access '", &accessName, "' does not exist in resource '", &resourceName, "'");
				ZEPHIR_CALL_METHOD(NULL, &_7$$7, "__construct", NULL, 9, &_8$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_7$$7, "phalcon/acl/adapter/memory.zep", 393 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&accessName);
		zephir_is_iterable(access, 0, "phalcon/acl/adapter/memory.zep", 413);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(access), _9$$5)
		{
			ZEPHIR_INIT_NVAR(&accessName);
			ZVAL_COPY(&accessName, _9$$5);
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSVSV(&accessKey, &roleName, "!", &resourceName, "!", &accessName);
			zephir_update_property_array(this_ptr, SL("_access"), &accessKey, action TSRMLS_CC);
			if (Z_TYPE_P(func) != IS_NULL) {
				zephir_update_property_array(this_ptr, SL("_func"), &accessKey, func TSRMLS_CC);
			}
			if (!ZEPHIR_IS_STRING(&accessName, "*")) {
				ZEPHIR_INIT_LNVAR(_10$$10);
				ZEPHIR_CONCAT_VSVS(&_10$$10, &roleName, "!", &resourceName, "!*");
				ZEPHIR_CPY_WRT(&accessKeyAll, &_10$$10);
				if (!(zephir_array_isset(&internalAccess, &accessKeyAll))) {
					zephir_update_property_array(this_ptr, SL("_access"), &accessKeyAll, &defaultAccess TSRMLS_CC);
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		if (!ZEPHIR_IS_STRING(access, "*")) {
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSV(&accessKey, &resourceName, "!", access);
			if (!(zephir_array_isset(&accessList, &accessKey))) {
				ZEPHIR_INIT_VAR(&_11$$14);
				object_init_ex(&_11$$14, phalcon_acl_exception_ce);
				ZEPHIR_INIT_VAR(&_12$$14);
				ZEPHIR_CONCAT_SVSVS(&_12$$14, "Access '", access, "' does not exist in resource '", &resourceName, "'");
				ZEPHIR_CALL_METHOD(NULL, &_11$$14, "__construct", NULL, 9, &_12$$14);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_11$$14, "phalcon/acl/adapter/memory.zep", 418 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_INIT_NVAR(&accessKey);
		ZEPHIR_CONCAT_VSVSV(&accessKey, &roleName, "!", &resourceName, "!", access);
		zephir_update_property_array(this_ptr, SL("_access"), &accessKey, action TSRMLS_CC);
		if (Z_TYPE_P(func) != IS_NULL) {
			zephir_update_property_array(this_ptr, SL("_func"), &accessKey, func TSRMLS_CC);
		}
		if (!ZEPHIR_IS_STRING(access, "*")) {
			ZEPHIR_INIT_VAR(&_13$$16);
			ZEPHIR_CONCAT_VSVS(&_13$$16, &roleName, "!", &resourceName, "!*");
			ZEPHIR_CPY_WRT(&accessKey, &_13$$16);
			if (!(zephir_array_isset(&internalAccess, &accessKey))) {
				zephir_read_property(&_14$$17, this_ptr, SL("_defaultAccess"), PH_NOISY_CC | PH_READONLY);
				zephir_update_property_array(this_ptr, SL("_access"), &accessKey, &_14$$17 TSRMLS_CC);
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Allow access to a role on a resource
 *
 * You can use '*' as wildcard
 *
 * Example:
 * <code>
 * //Allow access to guests to search on customers
 * $acl->allow('guests', 'customers', 'search');
 *
 * //Allow access to guests to search or create on customers
 * $acl->allow('guests', 'customers', array('search', 'create'));
 *
 * //Allow access to any role to browse on products
 * $acl->allow('*', 'products', 'browse');
 *
 * //Allow access to any role to browse on any resource
 * $acl->allow('*', '*', 'browse');
 * </code>
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow) {

	zend_string *_6$$4;
	zend_ulong _5$$4;
	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *resourceName_param = NULL, *access, access_sub, *func = NULL, func_sub, __$null, innerRoleName, _0$$3, _2$$4, _3$$4, *_4$$4, _7$$5;
	zval roleName, resourceName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&access_sub);
	ZVAL_UNDEF(&func_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&innerRoleName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_7$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &roleName_param, &resourceName_param, &access, &func);

	zephir_get_strval(&roleName, roleName_param);
	zephir_get_strval(&resourceName, resourceName_param);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}


	if (!ZEPHIR_IS_STRING(&roleName, "*")) {
		ZVAL_LONG(&_0$$3, 1);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_allowordeny", &_1, 0, &roleName, &resourceName, access, &_0$$3, func);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		zephir_read_property(&_2$$4, this_ptr, SL("_rolesNames"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$4);
		zephir_is_iterable(&_2$$4, 0, "phalcon/acl/adapter/memory.zep", 477);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_2$$4), _5$$4, _6$$4, _4$$4)
		{
			ZEPHIR_INIT_NVAR(&innerRoleName);
			if (_6$$4 != NULL) { 
				ZVAL_STR_COPY(&innerRoleName, _6$$4);
			} else {
				ZVAL_LONG(&innerRoleName, _5$$4);
			}
			ZEPHIR_INIT_NVAR(&_3$$4);
			ZVAL_COPY(&_3$$4, _4$$4);
			ZVAL_LONG(&_7$$5, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_allowordeny", &_1, 0, &innerRoleName, &resourceName, access, &_7$$5, func);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZEPHIR_INIT_NVAR(&innerRoleName);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Deny access to a role on a resource
 *
 * You can use '*' as wildcard
 *
 * Example:
 * <code>
 * //Deny access to guests to search on customers
 * $acl->deny('guests', 'customers', 'search');
 *
 * //Deny access to guests to search or create on customers
 * $acl->deny('guests', 'customers', array('search', 'create'));
 *
 * //Deny access to any role to browse on products
 * $acl->deny('*', 'products', 'browse');
 *
 * //Deny access to any role to browse on any resource
 * $acl->deny('*', '*', 'browse');
 * </code>
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, deny) {

	zend_string *_5$$4;
	zend_ulong _4$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *resourceName_param = NULL, *access, access_sub, *func = NULL, func_sub, __$null, innerRoleName, _0$$3, _1$$4, _2$$4, *_3$$4, _6$$5;
	zval roleName, resourceName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&access_sub);
	ZVAL_UNDEF(&func_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&innerRoleName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &roleName_param, &resourceName_param, &access, &func);

	zephir_get_strval(&roleName, roleName_param);
	zephir_get_strval(&resourceName, resourceName_param);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}


	if (!ZEPHIR_IS_STRING(&roleName, "*")) {
		ZVAL_LONG(&_0$$3, 0);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_allowordeny", NULL, 0, &roleName, &resourceName, access, &_0$$3, func);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		zephir_read_property(&_1$$4, this_ptr, SL("_rolesNames"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_is_iterable(&_1$$4, 0, "phalcon/acl/adapter/memory.zep", 510);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1$$4), _4$$4, _5$$4, _3$$4)
		{
			ZEPHIR_INIT_NVAR(&innerRoleName);
			if (_5$$4 != NULL) { 
				ZVAL_STR_COPY(&innerRoleName, _5$$4);
			} else {
				ZVAL_LONG(&innerRoleName, _4$$4);
			}
			ZEPHIR_INIT_NVAR(&_2$$4);
			ZVAL_COPY(&_2$$4, _3$$4);
			ZVAL_LONG(&_6$$5, 0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_allowordeny", NULL, 0, &innerRoleName, &resourceName, access, &_6$$5, func);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_2$$4);
		ZEPHIR_INIT_NVAR(&innerRoleName);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether a role is allowed to access an action from a resource
 *
 * <code>
 * //Does andres have access to the customers resource to create?
 * $acl->isAllowed('andres', 'Products', 'create');
 *
 * //Do guests have access to any resource to edit?
 * $acl->isAllowed('guests', '*', 'edit');
 * </code>
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed) {

	zend_bool _8$$31, _13$$34, _16$$34, _19$$34, _20$$34, _22$$34, _33$$33, _39$$41, _41$$40, _43$$42;
	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL, *_15 = NULL, *_18 = NULL, *_25 = NULL, *_30 = NULL, *_32 = NULL, *_37 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval access;
	zval *roleName = NULL, roleName_sub, *resourceName = NULL, resourceName_sub, *access_param = NULL, *parameters_param = NULL, eventsManager, accessList, accessKey, haveAccess, roleInherits, inheritedRole, rolesNames, inheritedRoles, funcAccess, resourceObject, roleObject, funcList, _0, _1$$7, _2$$7, _3$$9, *_4$$13, *_5$$19, *_6$$25, _7$$28, reflectionFunction$$30, reflectionParameters$$30, parameterNumber$$30, parametersForFunction$$30, numberOfRequiredParameters$$30, userParametersSizeShouldBe$$30, reflectionClass$$30, parameterToCheck$$30, reflectionParameter$$30, _9$$31, *_10$$32, _14$$34, _17$$34, _21$$34, _23$$34, _24$$34, _26$$37, _27$$37, _28$$37, _29$$37, _31$$37, _34$$38, _35$$39, _36$$39, _38$$41, _40$$41, _42$$40, _44$$42, _45$$43, _46$$43;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&roleName_sub);
	ZVAL_UNDEF(&resourceName_sub);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&accessList);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&haveAccess);
	ZVAL_UNDEF(&roleInherits);
	ZVAL_UNDEF(&inheritedRole);
	ZVAL_UNDEF(&rolesNames);
	ZVAL_UNDEF(&inheritedRoles);
	ZVAL_UNDEF(&funcAccess);
	ZVAL_UNDEF(&resourceObject);
	ZVAL_UNDEF(&roleObject);
	ZVAL_UNDEF(&funcList);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$7);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_7$$28);
	ZVAL_UNDEF(&reflectionFunction$$30);
	ZVAL_UNDEF(&reflectionParameters$$30);
	ZVAL_UNDEF(&parameterNumber$$30);
	ZVAL_UNDEF(&parametersForFunction$$30);
	ZVAL_UNDEF(&numberOfRequiredParameters$$30);
	ZVAL_UNDEF(&userParametersSizeShouldBe$$30);
	ZVAL_UNDEF(&reflectionClass$$30);
	ZVAL_UNDEF(&parameterToCheck$$30);
	ZVAL_UNDEF(&reflectionParameter$$30);
	ZVAL_UNDEF(&_9$$31);
	ZVAL_UNDEF(&_14$$34);
	ZVAL_UNDEF(&_17$$34);
	ZVAL_UNDEF(&_21$$34);
	ZVAL_UNDEF(&_23$$34);
	ZVAL_UNDEF(&_24$$34);
	ZVAL_UNDEF(&_26$$37);
	ZVAL_UNDEF(&_27$$37);
	ZVAL_UNDEF(&_28$$37);
	ZVAL_UNDEF(&_29$$37);
	ZVAL_UNDEF(&_31$$37);
	ZVAL_UNDEF(&_34$$38);
	ZVAL_UNDEF(&_35$$39);
	ZVAL_UNDEF(&_36$$39);
	ZVAL_UNDEF(&_38$$41);
	ZVAL_UNDEF(&_40$$41);
	ZVAL_UNDEF(&_42$$40);
	ZVAL_UNDEF(&_44$$42);
	ZVAL_UNDEF(&_45$$43);
	ZVAL_UNDEF(&_46$$43);
	ZVAL_UNDEF(&access);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &roleName, &resourceName, &access_param, &parameters_param);

	ZEPHIR_SEPARATE_PARAM(roleName);
	ZEPHIR_SEPARATE_PARAM(resourceName);
	zephir_get_strval(&access, access_param);
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&haveAccess);
	ZVAL_NULL(&haveAccess);
	ZEPHIR_INIT_VAR(&funcAccess);
	ZVAL_NULL(&funcAccess);
	ZEPHIR_INIT_VAR(&resourceObject);
	ZVAL_NULL(&resourceObject);
	ZEPHIR_INIT_VAR(&roleObject);
	ZVAL_NULL(&roleObject);
	if (Z_TYPE_P(roleName) == IS_OBJECT) {
		if (!(zephir_instance_of_ev(roleName, phalcon_acl_roleaware_ce TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Object passed as roleName must implement RoleAware", "phalcon/acl/adapter/memory.zep", 534);
			return;
		}
		ZEPHIR_CPY_WRT(&roleObject, roleName);
		ZEPHIR_CALL_METHOD(roleName, &roleObject, "getrolename", NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(resourceName) == IS_OBJECT) {
		if (!(zephir_instance_of_ev(resourceName, phalcon_acl_resourceaware_ce TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Object passed as resourceName must implement ResourceAware", "phalcon/acl/adapter/memory.zep", 542);
			return;
		}
		ZEPHIR_CPY_WRT(&resourceObject, resourceName);
		ZEPHIR_CALL_METHOD(resourceName, &resourceObject, "getresourcename", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("_activeRole"), roleName);
	zephir_update_property_zval(this_ptr, SL("_activeResource"), resourceName);
	zephir_update_property_zval(this_ptr, SL("_activeAccess"), &access);
	ZEPHIR_OBS_VAR(&accessList);
	zephir_read_property(&accessList, this_ptr, SL("_access"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, SL("_eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	ZEPHIR_OBS_VAR(&funcList);
	zephir_read_property(&funcList, this_ptr, SL("_func"), PH_NOISY_CC);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$7);
		ZVAL_STRING(&_2$$7, "acl:beforeCheckAccess");
		ZEPHIR_CALL_METHOD(&_1$$7, &eventsManager, "fire", NULL, 0, &_2$$7, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_1$$7)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_OBS_VAR(&rolesNames);
	zephir_read_property(&rolesNames, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(&rolesNames, roleName))) {
		zephir_read_property(&_3$$9, this_ptr, SL("_defaultAccess"), PH_NOISY_CC | PH_READONLY);
		RETURN_MM_BOOL((ZEPHIR_IS_LONG(&_3$$9, 1)));
	}
	ZEPHIR_INIT_VAR(&accessKey);
	ZEPHIR_CONCAT_VSVSV(&accessKey, roleName, "!", resourceName, "!", &access);
	if (zephir_array_isset(&accessList, &accessKey)) {
		ZEPHIR_OBS_NVAR(&haveAccess);
		zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 575 TSRMLS_CC);
	}
	ZEPHIR_OBS_NVAR(&funcAccess);
	zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0 TSRMLS_CC);
	if (Z_TYPE_P(&haveAccess) == IS_NULL) {
		ZEPHIR_OBS_VAR(&roleInherits);
		zephir_read_property(&roleInherits, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(&inheritedRoles);
		if (zephir_array_isset_fetch(&inheritedRoles, &roleInherits, roleName, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(&inheritedRoles) == IS_ARRAY) {
				zephir_is_iterable(&inheritedRoles, 0, "phalcon/acl/adapter/memory.zep", 599);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&inheritedRoles), _4$$13)
				{
					ZEPHIR_INIT_NVAR(&inheritedRole);
					ZVAL_COPY(&inheritedRole, _4$$13);
					ZEPHIR_INIT_NVAR(&accessKey);
					ZEPHIR_CONCAT_VSVSV(&accessKey, &inheritedRole, "!", resourceName, "!", &access);
					if (zephir_array_isset(&accessList, &accessKey)) {
						ZEPHIR_OBS_NVAR(&haveAccess);
						zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 595 TSRMLS_CC);
					}
					ZEPHIR_OBS_NVAR(&funcAccess);
					zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0 TSRMLS_CC);
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&inheritedRole);
			}
		}
	}
	if (Z_TYPE_P(&haveAccess) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&accessKey);
		ZEPHIR_CONCAT_VSVS(&accessKey, roleName, "!", resourceName, "!*");
		if (zephir_array_isset(&accessList, &accessKey)) {
			ZEPHIR_OBS_NVAR(&haveAccess);
			zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 614 TSRMLS_CC);
		} else {
			if (Z_TYPE_P(&inheritedRoles) == IS_ARRAY) {
				zephir_is_iterable(&inheritedRoles, 0, "phalcon/acl/adapter/memory.zep", 629);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&inheritedRoles), _5$$19)
				{
					ZEPHIR_INIT_NVAR(&inheritedRole);
					ZVAL_COPY(&inheritedRole, _5$$19);
					ZEPHIR_INIT_NVAR(&accessKey);
					ZEPHIR_CONCAT_VSVS(&accessKey, &inheritedRole, "!", resourceName, "!*");
					ZEPHIR_OBS_NVAR(&funcAccess);
					zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0 TSRMLS_CC);
					if (zephir_array_isset(&accessList, &accessKey)) {
						ZEPHIR_OBS_NVAR(&haveAccess);
						zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 625 TSRMLS_CC);
						break;
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&inheritedRole);
			}
		}
	}
	if (Z_TYPE_P(&haveAccess) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&accessKey);
		ZEPHIR_CONCAT_VS(&accessKey, roleName, "!*!*");
		if (zephir_array_isset(&accessList, &accessKey)) {
			ZEPHIR_OBS_NVAR(&haveAccess);
			zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 644 TSRMLS_CC);
		} else {
			if (Z_TYPE_P(&inheritedRoles) == IS_ARRAY) {
				zephir_is_iterable(&inheritedRoles, 0, "phalcon/acl/adapter/memory.zep", 659);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&inheritedRoles), _6$$25)
				{
					ZEPHIR_INIT_NVAR(&inheritedRole);
					ZVAL_COPY(&inheritedRole, _6$$25);
					ZEPHIR_INIT_NVAR(&accessKey);
					ZEPHIR_CONCAT_VS(&accessKey, &inheritedRole, "!*!*");
					ZEPHIR_OBS_NVAR(&funcAccess);
					zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0 TSRMLS_CC);
					if (zephir_array_isset(&accessList, &accessKey)) {
						ZEPHIR_OBS_NVAR(&haveAccess);
						zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 655 TSRMLS_CC);
						break;
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&inheritedRole);
			}
		}
	}
	zephir_update_property_zval(this_ptr, SL("_accessGranted"), &haveAccess);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_7$$28);
		ZVAL_STRING(&_7$$28, "acl:afterCheckAccess");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_7$$28, this_ptr);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&haveAccess) == IS_NULL) {
		RETURN_MM_BOOL(0);
	}
	if (Z_TYPE_P(&funcAccess) != IS_NULL) {
		ZEPHIR_INIT_VAR(&reflectionFunction$$30);
		object_init_ex(&reflectionFunction$$30, zephir_get_internal_ce(SL("reflectionfunction")));
		ZEPHIR_CALL_METHOD(NULL, &reflectionFunction$$30, "__construct", NULL, 85, &funcAccess);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&reflectionParameters$$30, &reflectionFunction$$30, "getparameters", NULL, 86);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&parameterNumber$$30);
		ZVAL_LONG(&parameterNumber$$30, zephir_fast_count_int(&reflectionParameters$$30 TSRMLS_CC));
		do {
			if (ZEPHIR_IS_LONG(&parameterNumber$$30, 0)) {
				_8$$31 = (ZEPHIR_IS_LONG(&haveAccess, 1));
				if (_8$$31) {
					ZEPHIR_INIT_VAR(&_9$$31);
					ZEPHIR_CALL_USER_FUNC(&_9$$31, &funcAccess);
					zephir_check_call_status();
					_8$$31 = zephir_is_true(&_9$$31);
				}
				RETURN_MM_BOOL(_8$$31);
			}
			ZEPHIR_INIT_VAR(&parametersForFunction$$30);
			array_init(&parametersForFunction$$30);
			ZEPHIR_CALL_METHOD(&numberOfRequiredParameters$$30, &reflectionFunction$$30, "getnumberofrequiredparameters", NULL, 87);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&userParametersSizeShouldBe$$30, &parameterNumber$$30);
			zephir_is_iterable(&reflectionParameters$$30, 0, "phalcon/acl/adapter/memory.zep", 718);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&reflectionParameters$$30), _10$$32)
			{
				ZEPHIR_INIT_NVAR(&reflectionParameter$$30);
				ZVAL_COPY(&reflectionParameter$$30, _10$$32);
				ZEPHIR_CALL_METHOD(&reflectionClass$$30, &reflectionParameter$$30, "getclass", &_11, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&parameterToCheck$$30, &reflectionParameter$$30, "getname", &_12, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&reflectionClass$$30) != IS_NULL) {
					_13$$34 = Z_TYPE_P(&roleObject) != IS_NULL;
					if (_13$$34) {
						ZEPHIR_CALL_METHOD(&_14$$34, &reflectionClass$$30, "isinstance", &_15, 0, &roleObject);
						zephir_check_call_status();
						_13$$34 = zephir_is_true(&_14$$34);
					}
					_16$$34 = Z_TYPE_P(&resourceObject) != IS_NULL;
					if (_16$$34) {
						ZEPHIR_CALL_METHOD(&_17$$34, &reflectionClass$$30, "isinstance", &_18, 0, &resourceObject);
						zephir_check_call_status();
						_16$$34 = zephir_is_true(&_17$$34);
					}
					_19$$34 = !ZEPHIR_IS_STRING(&parameters, "");
					if (_19$$34) {
						_19$$34 = zephir_array_isset(&parameters, &parameterToCheck$$30);
					}
					_20$$34 = _19$$34;
					if (_20$$34) {
						ZEPHIR_OBS_NVAR(&_21$$34);
						zephir_array_fetch(&_21$$34, &parameters, &parameterToCheck$$30, PH_NOISY, "phalcon/acl/adapter/memory.zep", 709 TSRMLS_CC);
						_20$$34 = Z_TYPE_P(&_21$$34) == IS_OBJECT;
					}
					_22$$34 = _20$$34;
					if (_22$$34) {
						zephir_array_fetch(&_24$$34, &parameters, &parameterToCheck$$30, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 709 TSRMLS_CC);
						ZEPHIR_CALL_METHOD(&_23$$34, &reflectionClass$$30, "isinstance", &_25, 0, &_24$$34);
						zephir_check_call_status();
						_22$$34 = !zephir_is_true(&_23$$34);
					}
					if (_13$$34) {
						zephir_array_append(&parametersForFunction$$30, &roleObject, PH_SEPARATE, "phalcon/acl/adapter/memory.zep", 698);
						ZEPHIR_SEPARATE(&userParametersSizeShouldBe$$30);
						zephir_decrement(&userParametersSizeShouldBe$$30);
						continue;
					} else if (_16$$34) {
						zephir_array_append(&parametersForFunction$$30, &resourceObject, PH_SEPARATE, "phalcon/acl/adapter/memory.zep", 704);
						ZEPHIR_SEPARATE(&userParametersSizeShouldBe$$30);
						zephir_decrement(&userParametersSizeShouldBe$$30);
						continue;
					} else if (_22$$34) {
						ZEPHIR_INIT_NVAR(&_26$$37);
						object_init_ex(&_26$$37, phalcon_acl_exception_ce);
						ZEPHIR_INIT_NVAR(&_27$$37);
						zephir_array_fetch(&_28$$37, &parameters, &parameterToCheck$$30, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 710 TSRMLS_CC);
						zephir_get_class(&_27$$37, &_28$$37, 0 TSRMLS_CC);
						ZEPHIR_CALL_METHOD(&_29$$37, &reflectionClass$$30, "getname", &_30, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_LNVAR(_31$$37);
						ZEPHIR_CONCAT_SVSVSVSVSVS(&_31$$37, "Your passed parameter dont have same class as parameter in defined function when check ", roleName, " can ", &access, " ", resourceName, ". Class passed: ", &_27$$37, " , Class in defined function: ", &_29$$37, ".");
						ZEPHIR_CALL_METHOD(NULL, &_26$$37, "__construct", &_32, 9, &_31$$37);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_26$$37, "phalcon/acl/adapter/memory.zep", 710 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				_33$$33 = !ZEPHIR_IS_STRING(&parameters, "");
				if (_33$$33) {
					_33$$33 = zephir_array_isset(&parameters, &parameterToCheck$$30);
				}
				if (_33$$33) {
					zephir_array_fetch(&_34$$38, &parameters, &parameterToCheck$$30, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 715 TSRMLS_CC);
					zephir_array_append(&parametersForFunction$$30, &_34$$38, PH_SEPARATE, "phalcon/acl/adapter/memory.zep", 715);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&reflectionParameter$$30);
			if (ZEPHIR_LT_LONG(&userParametersSizeShouldBe$$30, zephir_fast_count_int(&parameters TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(&_35$$39);
				ZEPHIR_CONCAT_SVSVSVS(&_35$$39, "Number of parameters in array is higher than number of parameters in defined function when check ", roleName, " can ", &access, " ", resourceName, ". Remember that more parameters than defined in function will be ignored.");
				ZVAL_LONG(&_36$$39, 512);
				ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", &_37, 2, &_35$$39, &_36$$39);
				zephir_check_call_status();
			}
			if (zephir_fast_count_int(&parametersForFunction$$30 TSRMLS_CC) == 0) {
				if (ZEPHIR_GT_LONG(&numberOfRequiredParameters$$30, 0)) {
					ZEPHIR_INIT_VAR(&_38$$41);
					ZEPHIR_CONCAT_SVSVSVS(&_38$$41, "You didnt provide any parameters when check ", roleName, " can ", &access, " ", resourceName, ". We will use default action when no arguments.");
					ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", &_37, 2, &_38$$41);
					zephir_check_call_status();
					_39$$41 = (ZEPHIR_IS_LONG(&haveAccess, 1));
					if (_39$$41) {
						zephir_read_property(&_40$$41, this_ptr, SL("_noArgumentsDefaultAction"), PH_NOISY_CC | PH_READONLY);
						_39$$41 = (ZEPHIR_IS_LONG(&_40$$41, 1));
					}
					RETURN_MM_BOOL(_39$$41);
				}
				_41$$40 = (ZEPHIR_IS_LONG(&haveAccess, 1));
				if (_41$$40) {
					ZEPHIR_INIT_VAR(&_42$$40);
					ZEPHIR_CALL_USER_FUNC(&_42$$40, &funcAccess);
					zephir_check_call_status();
					_41$$40 = zephir_is_true(&_42$$40);
				}
				RETURN_MM_BOOL(_41$$40);
			} else if (ZEPHIR_LE_LONG(&numberOfRequiredParameters$$30, zephir_fast_count_int(&parametersForFunction$$30 TSRMLS_CC))) {
				_43$$42 = (ZEPHIR_IS_LONG(&haveAccess, 1));
				if (_43$$42) {
					ZEPHIR_INIT_VAR(&_44$$42);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&_44$$42, &funcAccess, &parametersForFunction$$30);
					zephir_check_call_status();
					_43$$42 = zephir_is_true(&_44$$42);
				}
				RETURN_MM_BOOL(_43$$42);
			} else {
				ZEPHIR_INIT_VAR(&_45$$43);
				object_init_ex(&_45$$43, phalcon_acl_exception_ce);
				ZEPHIR_INIT_VAR(&_46$$43);
				ZEPHIR_CONCAT_SVSVSV(&_46$$43, "You didnt provide all necessary parameters for defined function when check ", roleName, " can ", &access, " ", resourceName);
				ZEPHIR_CALL_METHOD(NULL, &_45$$43, "__construct", &_32, 9, &_46$$43);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_45$$43, "phalcon/acl/adapter/memory.zep", 736 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} while(0);

	}
	RETURN_MM_BOOL((ZEPHIR_IS_LONG(&haveAccess, 1)));

}

/**
 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY) for no arguments provided in isAllowed action if there exists func for accessKey
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, setNoArgumentsDefaultAction) {

	zval *defaultAccess_param = NULL, _0;
	int defaultAccess;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &defaultAccess_param);

	defaultAccess = zephir_get_intval(defaultAccess_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, defaultAccess);
	zephir_update_property_zval(this_ptr, SL("_noArgumentsDefaultAction"), &_0);

}

/**
 * Returns the default ACL access level for no arguments provided in isAllowed action if there exists func for accessKey
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getNoArgumentsDefaultAction) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_noArgumentsDefaultAction");

}

/**
 * Return an array with every role registered in the list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getRoles) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_roles");

}

/**
 * Return an array with every resource registered in the list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getResources) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_resources");

}

