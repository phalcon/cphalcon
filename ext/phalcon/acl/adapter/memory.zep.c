
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Acl\Adapter\Memory
 *
 * Manages ACL lists in memory
 *
 *<code>
 * $acl = new \Phalcon\Acl\Adapter\Memory();
 *
 * $acl->setDefaultAction(
 *     \Phalcon\Acl::DENY
 * );
 *
 * // Register operations
 * $operations = [
 *     "users"  => new \Phalcon\Acl\Operation("Users"),
 *     "guests" => new \Phalcon\Acl\Operation("Guests"),
 * ];
 * foreach ($operations as $operation) {
 *     $acl->addOperation($operation);
 * }
 *
 * // Private area subjects
 * $privateSubjects = [
 *     "companies" => ["index", "search", "new", "edit", "save", "create", "delete"],
 *     "products"  => ["index", "search", "new", "edit", "save", "create", "delete"],
 *     "invoices"  => ["index", "profile"],
 * ];
 *
 * foreach ($privateSubjects as $subjectName => $actions) {
 *     $acl->addSubject(
 *         new \Phalcon\Acl\Subject($subjectName),
 *         $actions
 *     );
 * }
 *
 * // Public area subjects
 * $publicSubjects = [
 *     "index"   => ["index"],
 *     "about"   => ["index"],
 *     "session" => ["index", "register", "start", "end"],
 *     "contact" => ["index", "send"],
 * ];
 *
 * foreach ($publicSubjects as $subjectName => $actions) {
 *     $acl->addSubject(
 *         new \Phalcon\Acl\Subject($subjectName),
 *         $actions
 *     );
 * }
 *
 * // Grant access to public areas to both users and guests
 * foreach ($operations as $operation){
 *     foreach ($publicSubjects as $subject => $actions) {
 *         $acl->allow($operation->getName(), $subject, "*");
 *     }
 * }
 *
 * // Grant access to private area to operation Users
 * foreach ($privateSubjects as $subject => $actions) {
 *     foreach ($actions as $action) {
 *         $acl->allow("Users", $subject, $action);
 *     }
 * }
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter_Memory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Acl\\Adapter, Memory, phalcon, acl_adapter_memory, phalcon_acl_adapter_ce, phalcon_acl_adapter_memory_method_entry, 0);

	/**
	 * Access
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("access"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Access List
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("accessList"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Returns latest function used to acquire access
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("activeFunction"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Returns number of additional arguments(excluding role and resource) for active function
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_acl_adapter_memory_ce, SL("activeFunctionCustomArgumentsCount"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Returns latest key used to acquire access
	 *
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("activeKey"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Function List
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("func"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Default action for no arguments is allow
	 *
	 * @var mixed
	 */
	zend_declare_property_long(phalcon_acl_adapter_memory_ce, SL("noArgumentsDefaultAction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Operations
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("operations"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Operation Inherits
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("operationInherits"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Operations Names
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("operationsNames"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Subjects
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("subjects"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Subject Names
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("subjectsNames"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Returns latest function used to acquire access
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveFunction) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "activeFunction");

}

/**
 * Returns number of additional arguments(excluding role and resource) for active function
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveFunctionCustomArgumentsCount) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "activeFunctionCustomArgumentsCount");

}

/**
 * Returns latest key used to acquire access
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveKey) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "activeKey");

}

/**
 * Phalcon\Acl\Adapter\Memory constructor
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, __construct) {

	zval _0, _1;
	zval __$true;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("*"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("subjectsNames"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("*!*"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("accessList"), &_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * Do a operation inherit from another existing operation
 *
 * Example:
 * <code>
 *
 * $acl->addOperation("administrator", "consultant");
 * $acl->addOperation("administrator", ["consultant", "consultant2"]);
 * </code>
 *
 * @param  array|string         accessInherits
 * @param  OperationInterface|string|array operation
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit) {

	zend_bool _5$$7;
	zephir_fcall_cache_entry *_14 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *operationName_param = NULL, *operationToInherits, operationToInherits_sub, __$true, operationInheritName, operationsNames, operationToInherit, checkOperationToInherit, checkOperationToInherits, usedOperationToInherits, operationToInheritList, usedOperationToInherit, _0, *_4, _1$$3, _3$$4, _6$$7, _7$$7, _10$$7, _8$$11, _9$$11, _11$$13, _12$$13, *_13$$13, _16$$17, _17$$17, _18$$15, _19$$18, _20$$18, *_21$$18;
	zval operationName, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&operationName);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&operationToInherits_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&operationInheritName);
	ZVAL_UNDEF(&operationsNames);
	ZVAL_UNDEF(&operationToInherit);
	ZVAL_UNDEF(&checkOperationToInherit);
	ZVAL_UNDEF(&checkOperationToInherits);
	ZVAL_UNDEF(&usedOperationToInherits);
	ZVAL_UNDEF(&operationToInheritList);
	ZVAL_UNDEF(&usedOperationToInherit);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_16$$17);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_19$$18);
	ZVAL_UNDEF(&_20$$18);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &operationName_param, &operationToInherits);

	zephir_get_strval(&operationName, operationName_param);


	zephir_read_property(&_0, this_ptr, SL("operationsNames"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&operationsNames, &_0);
	if (!(zephir_array_isset(&operationsNames, &operationName))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Operation '", &operationName, "' does not exist in the operation list");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 4, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/acl/adapter/memory.zep", 206 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("operationInherits"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &operationName))) {
		ZEPHIR_INIT_VAR(&_3$$4);
		array_init(&_3$$4);
		zephir_update_property_array(this_ptr, SL("operationInherits"), &operationName, &_3$$4 TSRMLS_CC);
	}
	if (Z_TYPE_P(operationToInherits) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&operationToInheritList);
		zephir_create_array(&operationToInheritList, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&operationToInheritList, operationToInherits);
	} else {
		ZEPHIR_CPY_WRT(&operationToInheritList, operationToInherits);
	}
	zephir_is_iterable(&operationToInheritList, 0, "phalcon/acl/adapter/memory.zep", 277);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&operationToInheritList), _4)
	{
		ZEPHIR_INIT_NVAR(&operationToInherit);
		ZVAL_COPY(&operationToInherit, _4);
		_5$$7 = Z_TYPE_P(&operationToInherit) == IS_OBJECT;
		if (_5$$7) {
			_5$$7 = zephir_instance_of_ev(&operationToInherit, phalcon_acl_operationinterface_ce TSRMLS_CC);
		}
		if (_5$$7) {
			ZEPHIR_CALL_METHOD(&operationInheritName, &operationToInherit, "getname", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&operationInheritName, &operationToInherit);
		}
		zephir_read_property(&_6$$7, this_ptr, SL("operationInherits"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_7$$7, &_6$$7, &operationName, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 232 TSRMLS_CC);
		if (zephir_fast_in_array(&operationInheritName, &_7$$7 TSRMLS_CC)) {
			continue;
		}
		if (!(zephir_array_isset(&operationsNames, &operationInheritName))) {
			ZEPHIR_INIT_NVAR(&_8$$11);
			object_init_ex(&_8$$11, phalcon_acl_exception_ce);
			ZEPHIR_INIT_LNVAR(_9$$11);
			ZEPHIR_CONCAT_SVS(&_9$$11, "Operation '", &operationInheritName, "' (to inherit) does not exist in the operation list");
			ZEPHIR_CALL_METHOD(NULL, &_8$$11, "__construct", NULL, 4, &_9$$11);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_8$$11, "phalcon/acl/adapter/memory.zep", 239 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_EQUAL(&operationName, &operationInheritName)) {
			RETURN_MM_BOOL(0);
		}
		zephir_read_property(&_10$$7, this_ptr, SL("operationInherits"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_10$$7, &operationInheritName)) {
			ZEPHIR_INIT_NVAR(&checkOperationToInherits);
			array_init(&checkOperationToInherits);
			zephir_read_property(&_11$$13, this_ptr, SL("operationInherits"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_12$$13, &_11$$13, &operationInheritName, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 250 TSRMLS_CC);
			zephir_is_iterable(&_12$$13, 0, "phalcon/acl/adapter/memory.zep", 253);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_12$$13), _13$$13)
			{
				ZEPHIR_INIT_NVAR(&usedOperationToInherit);
				ZVAL_COPY(&usedOperationToInherit, _13$$13);
				ZEPHIR_MAKE_REF(&checkOperationToInherits);
				ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_14, 69, &checkOperationToInherits, &usedOperationToInherit);
				ZEPHIR_UNREF(&checkOperationToInherits);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&usedOperationToInherit);
			ZEPHIR_INIT_NVAR(&usedOperationToInherits);
			array_init(&usedOperationToInherits);
			while (1) {
				if (!(!(ZEPHIR_IS_EMPTY(&checkOperationToInherits)))) {
					break;
				}
				ZEPHIR_MAKE_REF(&checkOperationToInherits);
				ZEPHIR_CALL_FUNCTION(&checkOperationToInherit, "array_shift", &_15, 11, &checkOperationToInherits);
				ZEPHIR_UNREF(&checkOperationToInherits);
				zephir_check_call_status();
				if (zephir_array_isset(&usedOperationToInherits, &checkOperationToInherit)) {
					continue;
				}
				zephir_array_update_zval(&usedOperationToInherits, &checkOperationToInherit, &__$true, PH_COPY | PH_SEPARATE);
				if (ZEPHIR_IS_EQUAL(&operationName, &checkOperationToInherit)) {
					ZEPHIR_INIT_NVAR(&_16$$17);
					object_init_ex(&_16$$17, phalcon_acl_exception_ce);
					ZEPHIR_INIT_LNVAR(_17$$17);
					ZEPHIR_CONCAT_SVS(&_17$$17, "Operation '", &operationInheritName, "' (to inherit) is infinite loop ");
					ZEPHIR_CALL_METHOD(NULL, &_16$$17, "__construct", NULL, 4, &_17$$17);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_16$$17, "phalcon/acl/adapter/memory.zep", 262 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_property(&_18$$15, this_ptr, SL("operationInherits"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_18$$15, &checkOperationToInherit)) {
					zephir_read_property(&_19$$18, this_ptr, SL("operationInherits"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_20$$18, &_19$$18, &checkOperationToInherit, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 268 TSRMLS_CC);
					zephir_is_iterable(&_20$$18, 0, "phalcon/acl/adapter/memory.zep", 271);
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_20$$18), _21$$18)
					{
						ZEPHIR_INIT_NVAR(&usedOperationToInherit);
						ZVAL_COPY(&usedOperationToInherit, _21$$18);
						ZEPHIR_MAKE_REF(&checkOperationToInherits);
						ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_14, 69, &checkOperationToInherits, &usedOperationToInherit);
						ZEPHIR_UNREF(&checkOperationToInherits);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
					ZEPHIR_INIT_NVAR(&usedOperationToInherit);
				}
			}
		}
		zephir_update_property_array_multi(this_ptr, SL("operationInherits"), &operationInheritName TSRMLS_CC, SL("za"), 2, &operationName);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&operationToInherit);
	RETURN_MM_BOOL(1);

}

/**
 * Adds a operation to the ACL list. Second parameter allows inheriting access data from other existing operation
 *
 * Example:
 * <code>
 * $acl->addOperation(
 *     new Phalcon\Acl\Operation("administrator"),
 *     "consultant"
 * );
 *
 * $acl->addOperation("administrator", "consultant");
 * $acl->addOperation("administrator", ["consultant", "consultant2"]);
 * </code>
 *
 * @param  array|string         accessInherits
 * @param  OperationInterface|string|array operation
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addOperation) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *operation, operation_sub, *accessInherits = NULL, accessInherits_sub, __$true, __$null, operationName, operationObject, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&operation_sub);
	ZVAL_UNDEF(&accessInherits_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&operationName);
	ZVAL_UNDEF(&operationObject);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &operation, &accessInherits);

	if (!accessInherits) {
		accessInherits = &accessInherits_sub;
		accessInherits = &__$null;
	}


	_0 = Z_TYPE_P(operation) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(operation, phalcon_acl_operationinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&operationName, operation, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&operationObject, operation);
	} else if (Z_TYPE_P(operation) == IS_STRING) {
		ZEPHIR_CPY_WRT(&operationName, operation);
		ZEPHIR_INIT_NVAR(&operationObject);
		object_init_ex(&operationObject, phalcon_acl_operation_ce);
		ZEPHIR_CALL_METHOD(NULL, &operationObject, "__construct", NULL, 70, operation);
		zephir_check_call_status();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Operation must be either an string or implement OperationInterface", "phalcon/acl/adapter/memory.zep", 308);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("operationsNames"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &operationName)) {
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_array_append(this_ptr, SL("operations"), &operationObject TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("operationsNames"), &operationName, &__$true TSRMLS_CC);
	if (Z_TYPE_P(accessInherits) != IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addinherit", NULL, 0, &operationName, accessInherits);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Adds a subject to the ACL list
 *
 * Access names can be a particular action, by example
 * search, update, delete, etc or a list of them
 *
 * Example:
 * <code>
 * // Add a subject to the the list allowing access to an action
 * $acl->addSubject(
 *     new Phalcon\Acl\Subject("customers"),
 *     "search"
 * );
 *
 * $acl->addSubject("customers", "search");
 *
 * // Add a subject  with an access list
 * $acl->addSubject(
 *     new Phalcon\Acl\Subject("customers"),
 *     [
 *         "create",
 *         "search",
 *     ]
 * );
 *
 * $acl->addSubject(
 *     "customers",
 *     [
 *         "create",
 *         "search",
 *     ]
 * );
 * </code>
 *
 * @param   Phalcon\Acl\Subject|string subjectValue
 * @param   array|string accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addSubject) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *subjectValue, subjectValue_sub, *accessList, accessList_sub, __$true, subjectName, subjectObject, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&subjectValue_sub);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&subjectName);
	ZVAL_UNDEF(&subjectObject);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &subjectValue, &accessList);



	_0 = Z_TYPE_P(subjectValue) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(subjectValue, phalcon_acl_subjectinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&subjectName, subjectValue, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&subjectObject, subjectValue);
	} else {
		ZEPHIR_CPY_WRT(&subjectName, subjectValue);
		ZEPHIR_INIT_NVAR(&subjectObject);
		object_init_ex(&subjectObject, phalcon_acl_subject_ce);
		ZEPHIR_CALL_METHOD(NULL, &subjectObject, "__construct", NULL, 71, &subjectName);
		zephir_check_call_status();
	}
	zephir_read_property(&_1, this_ptr, SL("subjectsNames"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_1, &subjectName))) {
		zephir_update_property_array_append(this_ptr, SL("subjects"), &subjectObject TSRMLS_CC);
		zephir_update_property_array(this_ptr, SL("subjectsNames"), &subjectName, &__$true TSRMLS_CC);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addsubjectaccess", NULL, 0, &subjectName, accessList);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds access to subjects
 *
 * @param array|string accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addSubjectAccess) {

	zend_bool exists = 0, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *subjectName_param = NULL, *accessList, accessList_sub, accessName, accessKey, _0, _1$$3, *_4$$5, _5$$6, _6$$7, _7$$8, _8$$9;
	zval subjectName, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&subjectName);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &subjectName_param, &accessList);

	zephir_get_strval(&subjectName, subjectName_param);


	zephir_read_property(&_0, this_ptr, SL("subjectsNames"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &subjectName))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Subject '", &subjectName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 4, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/acl/adapter/memory.zep", 392 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = Z_TYPE_P(accessList) != IS_ARRAY;
	if (_3) {
		_3 = Z_TYPE_P(accessList) != IS_STRING;
	}
	if (_3) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Invalid value for accessList", "phalcon/acl/adapter/memory.zep", 396);
		return;
	}
	exists = 1;
	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		zephir_is_iterable(accessList, 0, "phalcon/acl/adapter/memory.zep", 407);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(accessList), _4$$5)
		{
			ZEPHIR_INIT_NVAR(&accessName);
			ZVAL_COPY(&accessName, _4$$5);
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSV(&accessKey, &subjectName, "!", &accessName);
			zephir_read_property(&_5$$6, this_ptr, SL("accessList"), PH_NOISY_CC | PH_READONLY);
			if (!(zephir_array_isset(&_5$$6, &accessKey))) {
				ZEPHIR_INIT_NVAR(&_6$$7);
				ZVAL_BOOL(&_6$$7, exists);
				zephir_update_property_array(this_ptr, SL("accessList"), &accessKey, &_6$$7 TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		ZEPHIR_INIT_NVAR(&accessKey);
		ZEPHIR_CONCAT_VSV(&accessKey, &subjectName, "!", accessList);
		zephir_read_property(&_7$$8, this_ptr, SL("accessList"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset(&_7$$8, &accessKey))) {
			ZEPHIR_INIT_VAR(&_8$$9);
			ZVAL_BOOL(&_8$$9, exists);
			zephir_update_property_array(this_ptr, SL("accessList"), &accessKey, &_8$$9 TSRMLS_CC);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Allow access to a operation on a subject
 *
 * You can use '*' as wildcard
 *
 * Example:
 * <code>
 * //Allow access to guests to search on customers
 * $acl->allow("guests", "customers", "search");
 *
 * //Allow access to guests to search or create on customers
 * $acl->allow("guests", "customers", ["search", "create"]);
 *
 * //Allow access to any operation to browse on products
 * $acl->allow("*", "products", "browse");
 *
 * //Allow access to any operation to browse on any subject
 * $acl->allow("*", "*", "browse");
 * </code>
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow) {

	zend_string *_5$$4;
	zend_ulong _4$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *operationName_param = NULL, *subjectName_param = NULL, *access, access_sub, *func = NULL, func_sub, __$null, innerOperationName, _0$$3, _1$$4, _2$$4, *_3$$4, _6$$5;
	zval operationName, subjectName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&operationName);
	ZVAL_UNDEF(&subjectName);
	ZVAL_UNDEF(&access_sub);
	ZVAL_UNDEF(&func_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&innerOperationName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &operationName_param, &subjectName_param, &access, &func);

	zephir_get_strval(&operationName, operationName_param);
	zephir_get_strval(&subjectName, subjectName_param);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}


	if (!ZEPHIR_IS_STRING(&operationName, "*")) {
		ZVAL_LONG(&_0$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", NULL, 72, &operationName, &subjectName, access, &_0$$3, func);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_1$$4, this_ptr, SL("operationsNames"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_is_iterable(&_1$$4, 0, "phalcon/acl/adapter/memory.zep", 447);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1$$4), _4$$4, _5$$4, _3$$4)
		{
			ZEPHIR_INIT_NVAR(&innerOperationName);
			if (_5$$4 != NULL) { 
				ZVAL_STR_COPY(&innerOperationName, _5$$4);
			} else {
				ZVAL_LONG(&innerOperationName, _4$$4);
			}
			ZEPHIR_INIT_NVAR(&_2$$4);
			ZVAL_COPY(&_2$$4, _3$$4);
			ZVAL_LONG(&_6$$5, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", NULL, 72, &innerOperationName, &subjectName, access, &_6$$5, func);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_2$$4);
		ZEPHIR_INIT_NVAR(&innerOperationName);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Deny access to a operation on a subject
 *
 * You can use '*' as wildcard
 *
 * Example:
 * <code>
 * //Deny access to guests to search on customers
 * $acl->deny("guests", "customers", "search");
 *
 * //Deny access to guests to search or create on customers
 * $acl->deny("guests", "customers", ["search", "create"]);
 *
 * //Deny access to any operation to browse on products
 * $acl->deny("*", "products", "browse");
 *
 * //Deny access to any operation to browse on any subject
 * $acl->deny("*", "*", "browse");
 * </code>
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, deny) {

	zend_string *_5$$4;
	zend_ulong _4$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *operationName_param = NULL, *subjectName_param = NULL, *access, access_sub, *func = NULL, func_sub, __$null, innerOperationName, _0$$3, _1$$4, _2$$4, *_3$$4, _6$$5;
	zval operationName, subjectName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&operationName);
	ZVAL_UNDEF(&subjectName);
	ZVAL_UNDEF(&access_sub);
	ZVAL_UNDEF(&func_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&innerOperationName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &operationName_param, &subjectName_param, &access, &func);

	zephir_get_strval(&operationName, operationName_param);
	zephir_get_strval(&subjectName, subjectName_param);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}


	if (!ZEPHIR_IS_STRING(&operationName, "*")) {
		ZVAL_LONG(&_0$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", NULL, 72, &operationName, &subjectName, access, &_0$$3, func);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_1$$4, this_ptr, SL("operationsNames"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_is_iterable(&_1$$4, 0, "phalcon/acl/adapter/memory.zep", 480);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1$$4), _4$$4, _5$$4, _3$$4)
		{
			ZEPHIR_INIT_NVAR(&innerOperationName);
			if (_5$$4 != NULL) { 
				ZVAL_STR_COPY(&innerOperationName, _5$$4);
			} else {
				ZVAL_LONG(&innerOperationName, _4$$4);
			}
			ZEPHIR_INIT_NVAR(&_2$$4);
			ZVAL_COPY(&_2$$4, _3$$4);
			ZVAL_LONG(&_6$$5, 0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", NULL, 72, &innerOperationName, &subjectName, access, &_6$$5, func);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_2$$4);
		ZEPHIR_INIT_NVAR(&innerOperationName);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes an access from a subject
 *
 * @param array|string accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, dropSubjectAccess) {

	zval *subjectName_param = NULL, *accessList, accessList_sub, accessName, accessKey, *_0$$3, _1$$4, _2$$5, _3$$7, _4$$8;
	zval subjectName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&subjectName);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &subjectName_param, &accessList);

	zephir_get_strval(&subjectName, subjectName_param);


	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		zephir_is_iterable(accessList, 0, "phalcon/acl/adapter/memory.zep", 499);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(accessList), _0$$3)
		{
			ZEPHIR_INIT_NVAR(&accessName);
			ZVAL_COPY(&accessName, _0$$3);
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSV(&accessKey, &subjectName, "!", &accessName);
			zephir_read_property(&_1$$4, this_ptr, SL("accessList"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_1$$4, &accessKey)) {
				zephir_read_property(&_2$$5, this_ptr, SL("accessList"), PH_NOISY_CC | PH_READONLY);
				zephir_array_unset(&_2$$5, &accessKey, PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		if (Z_TYPE_P(accessList) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSV(&accessKey, &subjectName, "!", &accessName);
			zephir_read_property(&_3$$7, this_ptr, SL("accessList"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_3$$7, &accessKey)) {
				zephir_read_property(&_4$$8, this_ptr, SL("accessList"), PH_NOISY_CC | PH_READONLY);
				zephir_array_unset(&_4$$8, &accessKey, PH_SEPARATE);
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the default ACL access level for no arguments provided in
 * isAllowed action if there exists func for accessKey
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getNoArgumentsDefaultAction) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "noArgumentsDefaultAction");

}

/**
 * Return an array with every operation registered in the list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getOperations) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "operations");

}

/**
 * Return an array with every subject registered in the list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getSubjects) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "subjects");

}

/**
 * Check whether a operation is allowed to access an action from a subject
 *
 * <code>
 * //Does andres have access to the customers subject to create?
 * $acl->isAllowed("andres", "Products", "create");
 *
 * //Do guests have access to any subject to edit?
 * $acl->isAllowed("guests", "*", "edit");
 * </code>
 *
 * @param  OperationInterface|OperationAware|string operationName
 * @param  SubjectInterface|SubjectAware|string subjectName
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed) {

	zend_bool hasOperation, hasSubject, _6, _10$$18, _13$$20, _15$$20, _16$$20, _18$$20, _19$$20, _21$$20, _34$$27, _36$$26, _38$$28;
	zephir_fcall_cache_entry *_29 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval access;
	zval *operationName = NULL, operationName_sub, *subjectName = NULL, subjectName_sub, *access_param = NULL, *parameters_param = NULL, __$null, eventsManager, accessList, accessKey, haveAccess, operationsNames, funcAccess, subjectObject, operationObject, funcList, reflectionFunction, reflectionParameters, parameterNumber, parametersForFunction, numberOfRequiredParameters, userParametersSizeShouldBe, reflectionClass, parameterToCheck, reflectionParameter, _2, _0$$5, _1$$9, _3$$11, _4$$11, _5$$13, _7$$15, _8$$16, _9$$16, _11$$18, *_12$$17, _40$$17, _41$$17, _14$$20, _17$$20, _20$$20, _22$$20, _23$$20, _24$$23, _25$$23, _26$$23, _27$$23, _28$$23, _30$$24, _31$$25, _32$$25, _33$$27, _35$$27, _37$$26, _39$$28;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&operationName_sub);
	ZVAL_UNDEF(&subjectName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&accessList);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&haveAccess);
	ZVAL_UNDEF(&operationsNames);
	ZVAL_UNDEF(&funcAccess);
	ZVAL_UNDEF(&subjectObject);
	ZVAL_UNDEF(&operationObject);
	ZVAL_UNDEF(&funcList);
	ZVAL_UNDEF(&reflectionFunction);
	ZVAL_UNDEF(&reflectionParameters);
	ZVAL_UNDEF(&parameterNumber);
	ZVAL_UNDEF(&parametersForFunction);
	ZVAL_UNDEF(&numberOfRequiredParameters);
	ZVAL_UNDEF(&userParametersSizeShouldBe);
	ZVAL_UNDEF(&reflectionClass);
	ZVAL_UNDEF(&parameterToCheck);
	ZVAL_UNDEF(&reflectionParameter);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$9);
	ZVAL_UNDEF(&_3$$11);
	ZVAL_UNDEF(&_4$$11);
	ZVAL_UNDEF(&_5$$13);
	ZVAL_UNDEF(&_7$$15);
	ZVAL_UNDEF(&_8$$16);
	ZVAL_UNDEF(&_9$$16);
	ZVAL_UNDEF(&_11$$18);
	ZVAL_UNDEF(&_40$$17);
	ZVAL_UNDEF(&_41$$17);
	ZVAL_UNDEF(&_14$$20);
	ZVAL_UNDEF(&_17$$20);
	ZVAL_UNDEF(&_20$$20);
	ZVAL_UNDEF(&_22$$20);
	ZVAL_UNDEF(&_23$$20);
	ZVAL_UNDEF(&_24$$23);
	ZVAL_UNDEF(&_25$$23);
	ZVAL_UNDEF(&_26$$23);
	ZVAL_UNDEF(&_27$$23);
	ZVAL_UNDEF(&_28$$23);
	ZVAL_UNDEF(&_30$$24);
	ZVAL_UNDEF(&_31$$25);
	ZVAL_UNDEF(&_32$$25);
	ZVAL_UNDEF(&_33$$27);
	ZVAL_UNDEF(&_35$$27);
	ZVAL_UNDEF(&_37$$26);
	ZVAL_UNDEF(&_39$$28);
	ZVAL_UNDEF(&access);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &operationName, &subjectName, &access_param, &parameters_param);

	ZEPHIR_SEPARATE_PARAM(operationName);
	ZEPHIR_SEPARATE_PARAM(subjectName);
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
	ZEPHIR_INIT_VAR(&subjectObject);
	ZVAL_NULL(&subjectObject);
	ZEPHIR_INIT_VAR(&operationObject);
	ZVAL_NULL(&operationObject);
	hasOperation = 0;
	hasSubject = 0;
	if (Z_TYPE_P(operationName) == IS_OBJECT) {
		if (zephir_instance_of_ev(operationName, phalcon_acl_operationaware_ce TSRMLS_CC)) {
			ZEPHIR_CPY_WRT(&operationObject, operationName);
			ZEPHIR_CALL_METHOD(operationName, &operationObject, "getoperationname", NULL, 0);
			zephir_check_call_status();
		} else if (zephir_instance_of_ev(operationName, phalcon_acl_operationinterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_0$$5, operationName, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(operationName, &_0$$5);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Object passed as operationName must implement Phalcon\\Acl\\OperationAware or Phalcon\\Acl\\OperationInterface", "phalcon/acl/adapter/memory.zep", 564);
			return;
		}
	}
	if (Z_TYPE_P(subjectName) == IS_OBJECT) {
		if (zephir_instance_of_ev(subjectName, phalcon_acl_subjectaware_ce TSRMLS_CC)) {
			ZEPHIR_CPY_WRT(&subjectObject, subjectName);
			ZEPHIR_CALL_METHOD(subjectName, &subjectObject, "getsubjectname", NULL, 0);
			zephir_check_call_status();
		} else if (zephir_instance_of_ev(subjectName, phalcon_acl_subjectinterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_1$$9, subjectName, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(subjectName, &_1$$9);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Object passed as subjectName must implement Phalcon\\Acl\\SubjectAware or Phalcon\\Acl\\SubjectInterface", "phalcon/acl/adapter/memory.zep", 575);
			return;
		}
	}
	zephir_update_property_zval(this_ptr, SL("activeOperation"), operationName);
	zephir_update_property_zval(this_ptr, SL("activeSubject"), subjectName);
	zephir_update_property_zval(this_ptr, SL("activeAccess"), &access);
	zephir_update_property_zval(this_ptr, SL("activeKey"), &__$null);
	zephir_update_property_zval(this_ptr, SL("activeFunction"), &__$null);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, 0);
	zephir_update_property_zval(this_ptr, SL("activeFunctionCustomArgumentsCount"), &_2);
	ZEPHIR_OBS_VAR(&accessList);
	zephir_read_property(&accessList, this_ptr, SL("access"), PH_NOISY_CC);
	zephir_read_property(&_2, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_2);
	ZEPHIR_OBS_VAR(&funcList);
	zephir_read_property(&funcList, this_ptr, SL("func"), PH_NOISY_CC);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_4$$11);
		ZVAL_STRING(&_4$$11, "acl:beforeCheckAccess");
		ZEPHIR_CALL_METHOD(&_3$$11, &eventsManager, "fire", NULL, 0, &_4$$11, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_3$$11)) {
			RETURN_MM_BOOL(0);
		}
	}
	zephir_read_property(&_2, this_ptr, SL("operationsNames"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&operationsNames, &_2);
	if (!(zephir_array_isset(&operationsNames, operationName))) {
		zephir_read_property(&_5$$13, this_ptr, SL("defaultAccess"), PH_NOISY_CC | PH_READONLY);
		RETURN_MM_BOOL((ZEPHIR_IS_LONG(&_5$$13, 1)));
	}
	ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "canaccess", NULL, 73, operationName, subjectName, &access);
	zephir_check_call_status();
	_6 = !ZEPHIR_IS_FALSE(&accessKey);
	if (_6) {
		_6 = zephir_array_isset(&accessList, &accessKey);
	}
	if (_6) {
		ZEPHIR_OBS_NVAR(&haveAccess);
		zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 610 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&funcAccess);
		zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0 TSRMLS_CC);
	}
	zephir_update_property_zval(this_ptr, SL("accessGranted"), &haveAccess);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_7$$15);
		ZVAL_STRING(&_7$$15, "acl:afterCheckAccess");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_7$$15, this_ptr);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("activeKey"), &accessKey);
	zephir_update_property_zval(this_ptr, SL("activeFunction"), &funcAccess);
	if (Z_TYPE_P(&haveAccess) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_8$$16);
		ZEPHIR_CONCAT_VSVSV(&_8$$16, operationName, "!", subjectName, "!", &access);
		zephir_update_property_zval(this_ptr, SL("activeKey"), &_8$$16);
		zephir_read_property(&_9$$16, this_ptr, SL("defaultAccess"), PH_NOISY_CC | PH_READONLY);
		RETURN_MM_BOOL(ZEPHIR_IS_LONG(&_9$$16, 1));
	}
	if (zephir_is_callable(&funcAccess TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&reflectionFunction);
		object_init_ex(&reflectionFunction, zephir_get_internal_ce(SL("reflectionfunction")));
		ZEPHIR_CALL_METHOD(NULL, &reflectionFunction, "__construct", NULL, 74, &funcAccess);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&reflectionParameters, &reflectionFunction, "getparameters", NULL, 75);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&parameterNumber);
		ZVAL_LONG(&parameterNumber, zephir_fast_count_int(&reflectionParameters TSRMLS_CC));
		if (ZEPHIR_IS_LONG_IDENTICAL(&parameterNumber, 0)) {
			_10$$18 = ZEPHIR_IS_LONG(&haveAccess, 1);
			if (_10$$18) {
				ZEPHIR_INIT_VAR(&_11$$18);
				ZEPHIR_CALL_USER_FUNC(&_11$$18, &funcAccess);
				zephir_check_call_status();
				_10$$18 = zephir_is_true(&_11$$18);
			}
			RETURN_MM_BOOL(_10$$18);
		}
		ZEPHIR_INIT_VAR(&parametersForFunction);
		array_init(&parametersForFunction);
		ZEPHIR_CALL_METHOD(&numberOfRequiredParameters, &reflectionFunction, "getnumberofrequiredparameters", NULL, 76);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&userParametersSizeShouldBe, &parameterNumber);
		zephir_is_iterable(&reflectionParameters, 0, "phalcon/acl/adapter/memory.zep", 688);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&reflectionParameters), _12$$17)
		{
			ZEPHIR_INIT_NVAR(&reflectionParameter);
			ZVAL_COPY(&reflectionParameter, _12$$17);
			ZEPHIR_CALL_METHOD(&reflectionClass, &reflectionParameter, "getclass", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&parameterToCheck, &reflectionParameter, "getname", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&reflectionClass) != IS_NULL) {
				_13$$20 = Z_TYPE_P(&operationObject) != IS_NULL;
				if (_13$$20) {
					ZEPHIR_CALL_METHOD(&_14$$20, &reflectionClass, "isinstance", NULL, 0, &operationObject);
					zephir_check_call_status();
					_13$$20 = zephir_is_true(&_14$$20);
				}
				_15$$20 = _13$$20;
				if (_15$$20) {
					_15$$20 = !hasOperation;
				}
				if (_15$$20) {
					hasOperation = 1;
					zephir_array_append(&parametersForFunction, &operationObject, PH_SEPARATE, "phalcon/acl/adapter/memory.zep", 659);
					ZEPHIR_SEPARATE(&userParametersSizeShouldBe);
					zephir_decrement(&userParametersSizeShouldBe);
					continue;
				}
				_16$$20 = Z_TYPE_P(&subjectObject) != IS_NULL;
				if (_16$$20) {
					ZEPHIR_CALL_METHOD(&_17$$20, &reflectionClass, "isinstance", NULL, 0, &subjectObject);
					zephir_check_call_status();
					_16$$20 = zephir_is_true(&_17$$20);
				}
				_18$$20 = _16$$20;
				if (_18$$20) {
					_18$$20 = !hasSubject;
				}
				if (_18$$20) {
					hasSubject = 1;
					zephir_array_append(&parametersForFunction, &subjectObject, PH_SEPARATE, "phalcon/acl/adapter/memory.zep", 668);
					ZEPHIR_SEPARATE(&userParametersSizeShouldBe);
					zephir_decrement(&userParametersSizeShouldBe);
					continue;
				}
				_19$$20 = zephir_array_isset(&parameters, &parameterToCheck);
				if (_19$$20) {
					ZEPHIR_OBS_NVAR(&_20$$20);
					zephir_array_fetch(&_20$$20, &parameters, &parameterToCheck, PH_NOISY, "phalcon/acl/adapter/memory.zep", 675 TSRMLS_CC);
					_19$$20 = Z_TYPE_P(&_20$$20) == IS_OBJECT;
				}
				_21$$20 = _19$$20;
				if (_21$$20) {
					zephir_array_fetch(&_23$$20, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 675 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_22$$20, &reflectionClass, "isinstance", NULL, 0, &_23$$20);
					zephir_check_call_status();
					_21$$20 = !zephir_is_true(&_22$$20);
				}
				if (_21$$20) {
					ZEPHIR_INIT_NVAR(&_24$$23);
					object_init_ex(&_24$$23, phalcon_acl_exception_ce);
					ZEPHIR_INIT_NVAR(&_25$$23);
					zephir_array_fetch(&_26$$23, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 677 TSRMLS_CC);
					zephir_get_class(&_25$$23, &_26$$23, 0 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_27$$23, &reflectionClass, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_28$$23);
					ZEPHIR_CONCAT_SVSVSVSVSVS(&_28$$23, "Your passed parameter doesn't have the same class as the parameter in defined function when check ", operationName, " can ", &access, " ", subjectName, ". Class passed: ", &_25$$23, " , Class in defined function: ", &_27$$23, ".");
					ZEPHIR_CALL_METHOD(NULL, &_24$$23, "__construct", &_29, 4, &_28$$23);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_24$$23, "phalcon/acl/adapter/memory.zep", 678 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			if (zephir_array_isset(&parameters, &parameterToCheck)) {
				zephir_array_fetch(&_30$$24, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 684 TSRMLS_CC);
				zephir_array_append(&parametersForFunction, &_30$$24, PH_SEPARATE, "phalcon/acl/adapter/memory.zep", 684);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&reflectionParameter);
		zephir_update_property_zval(this_ptr, SL("activeFunctionCustomArgumentsCount"), &userParametersSizeShouldBe);
		if (ZEPHIR_LT_LONG(&userParametersSizeShouldBe, zephir_fast_count_int(&parameters TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(&_31$$25);
			ZEPHIR_CONCAT_SVSVSVS(&_31$$25, "Number of parameters in array is higher than the number of parameters in defined function when check ", operationName, " can ", &access, " ", subjectName, ". Remember that more parameters than defined in function will be ignored.");
			ZVAL_LONG(&_32$$25, 512);
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 1, &_31$$25, &_32$$25);
			zephir_check_call_status();
		}
		if (zephir_fast_count_int(&parametersForFunction TSRMLS_CC) == 0) {
			if (ZEPHIR_GT_LONG(&numberOfRequiredParameters, 0)) {
				ZEPHIR_INIT_VAR(&_33$$27);
				ZEPHIR_CONCAT_SVSVSVS(&_33$$27, "You didn't provide any parameters when '", operationName, "' can '", &access, "' '", subjectName, "'. We will use default action when no arguments.");
				ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 1, &_33$$27);
				zephir_check_call_status();
				_34$$27 = ZEPHIR_IS_LONG(&haveAccess, 1);
				if (_34$$27) {
					zephir_read_property(&_35$$27, this_ptr, SL("noArgumentsDefaultAction"), PH_NOISY_CC | PH_READONLY);
					_34$$27 = ZEPHIR_IS_LONG(&_35$$27, 1);
				}
				RETURN_MM_BOOL(_34$$27);
			}
			_36$$26 = ZEPHIR_IS_LONG(&haveAccess, 1);
			if (_36$$26) {
				ZEPHIR_INIT_VAR(&_37$$26);
				ZEPHIR_CALL_USER_FUNC(&_37$$26, &funcAccess);
				zephir_check_call_status();
				_36$$26 = zephir_is_true(&_37$$26);
			}
			RETURN_MM_BOOL(_36$$26);
		}
		if (ZEPHIR_LE_LONG(&numberOfRequiredParameters, zephir_fast_count_int(&parametersForFunction TSRMLS_CC))) {
			_38$$28 = ZEPHIR_IS_LONG(&haveAccess, 1);
			if (_38$$28) {
				ZEPHIR_INIT_VAR(&_39$$28);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&_39$$28, &funcAccess, &parametersForFunction);
				zephir_check_call_status();
				_38$$28 = zephir_is_true(&_39$$28);
			}
			RETURN_MM_BOOL(_38$$28);
		}
		ZEPHIR_INIT_VAR(&_40$$17);
		object_init_ex(&_40$$17, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_41$$17);
		ZEPHIR_CONCAT_SVSVSV(&_41$$17, "You didn't provide all necessary parameters for defined function when check ", operationName, " can ", &access, " ", subjectName);
		ZEPHIR_CALL_METHOD(NULL, &_40$$17, "__construct", &_29, 4, &_41$$17);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_40$$17, "phalcon/acl/adapter/memory.zep", 722 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(&haveAccess, 1));

}

/**
 * Check whether operation exist in the operations list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isOperation) {

	zval *operationName_param = NULL, _0;
	zval operationName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&operationName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &operationName_param);

	zephir_get_strval(&operationName, operationName_param);


	zephir_read_property(&_0, this_ptr, SL("operationsNames"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &operationName));

}

/**
 * Check whether subject exist in the subjects list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isSubject) {

	zval *subjectName_param = NULL, _0;
	zval subjectName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&subjectName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &subjectName_param);

	zephir_get_strval(&subjectName, subjectName_param);


	zephir_read_property(&_0, this_ptr, SL("subjectsNames"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &subjectName));

}

/**
 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
 * for no arguments provided in isAllowed action if there exists func for
 * accessKey
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, setNoArgumentsDefaultAction) {

	zval *defaultAccess_param = NULL, _0;
	zend_long defaultAccess;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &defaultAccess_param);

	defaultAccess = zephir_get_intval(defaultAccess_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, defaultAccess);
	zephir_update_property_zval(this_ptr, SL("noArgumentsDefaultAction"), &_0);

}

/**
 * Checks if a operation has access to a subject
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allowOrDeny) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *operationName_param = NULL, *subjectName_param = NULL, *access, access_sub, *action, action_sub, *func = NULL, func_sub, __$null, accessList, accessName, accessKey, _0, _3, _6, _1$$3, _4$$4, *_7$$5, *_10$$5, _8$$7, _9$$7, _11$$12, _12$$12;
	zval operationName, subjectName, _2$$3, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&operationName);
	ZVAL_UNDEF(&subjectName);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&access_sub);
	ZVAL_UNDEF(&action_sub);
	ZVAL_UNDEF(&func_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&accessList);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &operationName_param, &subjectName_param, &access, &action, &func);

	zephir_get_strval(&operationName, operationName_param);
	zephir_get_strval(&subjectName, subjectName_param);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("operationsNames"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &operationName))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Operation '", &operationName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 4, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/acl/adapter/memory.zep", 762 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("subjectsNames"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_3, &subjectName))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SVS(&_5$$4, "Subject '", &subjectName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 4, &_5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/acl/adapter/memory.zep", 766 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_6, this_ptr, SL("accessList"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&accessList, &_6);
	if (Z_TYPE_P(access) == IS_ARRAY) {
		zephir_is_iterable(access, 0, "phalcon/acl/adapter/memory.zep", 780);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(access), _7$$5)
		{
			ZEPHIR_INIT_NVAR(&accessName);
			ZVAL_COPY(&accessName, _7$$5);
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSV(&accessKey, &subjectName, "!", &accessName);
			if (!(zephir_array_isset(&accessList, &accessKey))) {
				ZEPHIR_INIT_NVAR(&_8$$7);
				object_init_ex(&_8$$7, phalcon_acl_exception_ce);
				ZEPHIR_INIT_LNVAR(_9$$7);
				ZEPHIR_CONCAT_SVSVS(&_9$$7, "Access '", &accessName, "' does not exist in subject '", &subjectName, "'");
				ZEPHIR_CALL_METHOD(NULL, &_8$$7, "__construct", NULL, 4, &_9$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_8$$7, "phalcon/acl/adapter/memory.zep", 776 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&accessName);
		zephir_is_iterable(access, 0, "phalcon/acl/adapter/memory.zep", 789);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(access), _10$$5)
		{
			ZEPHIR_INIT_NVAR(&accessName);
			ZVAL_COPY(&accessName, _10$$5);
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSVSV(&accessKey, &operationName, "!", &subjectName, "!", &accessName);
			zephir_update_property_array(this_ptr, SL("access"), &accessKey, action TSRMLS_CC);
			if (Z_TYPE_P(func) != IS_NULL) {
				zephir_update_property_array(this_ptr, SL("func"), &accessKey, func TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		if (!ZEPHIR_IS_STRING(access, "*")) {
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSV(&accessKey, &subjectName, "!", access);
			if (!(zephir_array_isset(&accessList, &accessKey))) {
				ZEPHIR_INIT_VAR(&_11$$12);
				object_init_ex(&_11$$12, phalcon_acl_exception_ce);
				ZEPHIR_INIT_VAR(&_12$$12);
				ZEPHIR_CONCAT_SVSVS(&_12$$12, "Access '", access, "' does not exist in subject '", &subjectName, "'");
				ZEPHIR_CALL_METHOD(NULL, &_11$$12, "__construct", NULL, 4, &_12$$12);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_11$$12, "phalcon/acl/adapter/memory.zep", 794 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_INIT_NVAR(&accessKey);
		ZEPHIR_CONCAT_VSVSV(&accessKey, &operationName, "!", &subjectName, "!", access);
		zephir_update_property_array(this_ptr, SL("access"), &accessKey, action TSRMLS_CC);
		if (Z_TYPE_P(func) != IS_NULL) {
			zephir_update_property_array(this_ptr, SL("func"), &accessKey, func TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether a operation is allowed to access an action from a subject
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, canAccess) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	zval *operationName_param = NULL, *subjectName_param = NULL, *access_param = NULL, __$true, accessList, accessKey, checkOperationToInherit, checkOperationToInherits, usedOperationToInherits, usedOperationToInherit, _1, _2$$6, _3$$6, *_4$$6, _7$$8, _8$$13, _9$$13, *_10$$13;
	zval operationName, subjectName, access, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&operationName);
	ZVAL_UNDEF(&subjectName);
	ZVAL_UNDEF(&access);
	ZVAL_UNDEF(&_0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&accessList);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&checkOperationToInherit);
	ZVAL_UNDEF(&checkOperationToInherits);
	ZVAL_UNDEF(&usedOperationToInherits);
	ZVAL_UNDEF(&usedOperationToInherit);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$13);
	ZVAL_UNDEF(&_9$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &operationName_param, &subjectName_param, &access_param);

	zephir_get_strval(&operationName, operationName_param);
	zephir_get_strval(&subjectName, subjectName_param);
	zephir_get_strval(&access, access_param);


	ZEPHIR_OBS_VAR(&accessList);
	zephir_read_property(&accessList, this_ptr, SL("access"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VSVSV(&_0, &operationName, "!", &subjectName, "!", &access);
	ZEPHIR_CPY_WRT(&accessKey, &_0);
	if (zephir_array_isset(&accessList, &accessKey)) {
		RETURN_CCTOR(&accessKey);
	}
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_VSVS(&_0, &operationName, "!", &subjectName, "!*");
	ZEPHIR_CPY_WRT(&accessKey, &_0);
	if (zephir_array_isset(&accessList, &accessKey)) {
		RETURN_CCTOR(&accessKey);
	}
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_VS(&_0, &operationName, "!*!*");
	ZEPHIR_CPY_WRT(&accessKey, &_0);
	if (zephir_array_isset(&accessList, &accessKey)) {
		RETURN_CCTOR(&accessKey);
	}
	zephir_read_property(&_1, this_ptr, SL("operationInherits"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &operationName)) {
		ZEPHIR_INIT_VAR(&checkOperationToInherits);
		array_init(&checkOperationToInherits);
		zephir_read_property(&_2$$6, this_ptr, SL("operationInherits"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$6, &_2$$6, &operationName, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 848 TSRMLS_CC);
		zephir_is_iterable(&_3$$6, 0, "phalcon/acl/adapter/memory.zep", 851);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3$$6), _4$$6)
		{
			ZEPHIR_INIT_NVAR(&usedOperationToInherit);
			ZVAL_COPY(&usedOperationToInherit, _4$$6);
			ZEPHIR_MAKE_REF(&checkOperationToInherits);
			ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_5, 69, &checkOperationToInherits, &usedOperationToInherit);
			ZEPHIR_UNREF(&checkOperationToInherits);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&usedOperationToInherit);
		ZEPHIR_INIT_VAR(&usedOperationToInherits);
		array_init(&usedOperationToInherits);
		while (1) {
			if (!(!(ZEPHIR_IS_EMPTY(&checkOperationToInherits)))) {
				break;
			}
			ZEPHIR_MAKE_REF(&checkOperationToInherits);
			ZEPHIR_CALL_FUNCTION(&checkOperationToInherit, "array_shift", &_6, 11, &checkOperationToInherits);
			ZEPHIR_UNREF(&checkOperationToInherits);
			zephir_check_call_status();
			if (zephir_array_isset(&usedOperationToInherits, &checkOperationToInherit)) {
				continue;
			}
			zephir_array_update_zval(&usedOperationToInherits, &checkOperationToInherit, &__$true, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSVSV(&accessKey, &checkOperationToInherit, "!", &subjectName, "!", &access);
			if (zephir_array_isset(&accessList, &accessKey)) {
				RETURN_CCTOR(&accessKey);
			}
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSVS(&accessKey, &checkOperationToInherit, "!", &subjectName, "!*");
			if (zephir_array_isset(&accessList, &accessKey)) {
				RETURN_CCTOR(&accessKey);
			}
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VS(&accessKey, &checkOperationToInherit, "!*!*");
			if (zephir_array_isset(&accessList, &accessKey)) {
				RETURN_CCTOR(&accessKey);
			}
			zephir_read_property(&_7$$8, this_ptr, SL("operationInherits"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_7$$8, &checkOperationToInherit)) {
				zephir_read_property(&_8$$13, this_ptr, SL("operationInherits"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_9$$13, &_8$$13, &checkOperationToInherit, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 885 TSRMLS_CC);
				zephir_is_iterable(&_9$$13, 0, "phalcon/acl/adapter/memory.zep", 888);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_9$$13), _10$$13)
				{
					ZEPHIR_INIT_NVAR(&usedOperationToInherit);
					ZVAL_COPY(&usedOperationToInherit, _10$$13);
					ZEPHIR_MAKE_REF(&checkOperationToInherits);
					ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_5, 69, &checkOperationToInherits, &usedOperationToInherit);
					ZEPHIR_UNREF(&checkOperationToInherits);
					zephir_check_call_status();
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&usedOperationToInherit);
			}
		}
	}
	RETURN_MM_BOOL(0);

}

