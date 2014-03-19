
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

#include "session/bag.h"
#include "session/baginterface.h"
#include "session/exception.h"
#include "session/adapterinterface.h"
#include "di/injectionawareinterface.h"
#include "di.h"
#include "diinterface.h"
#include "internal/arginfo.h"

#include <ext/spl/spl_array.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"

#include "interned-strings.h"

/**
 * Phalcon\Session\Bag
 *
 * This component helps to separate session data into "namespaces". Working by this way
 * you can easily create groups of session variables into the application
 *
 *<code>
 *	$user = new \Phalcon\Session\Bag('user');
 *	$user->name = "Kimbra Johnson";
 *	$user->age = 22;
 *</code>
 */
zend_class_entry *phalcon_session_bag_ce;

PHP_METHOD(Phalcon_Session_Bag, __construct);
PHP_METHOD(Phalcon_Session_Bag, setDI);
PHP_METHOD(Phalcon_Session_Bag, getDI);
PHP_METHOD(Phalcon_Session_Bag, initialize);
PHP_METHOD(Phalcon_Session_Bag, destroy);
PHP_METHOD(Phalcon_Session_Bag, set);
PHP_METHOD(Phalcon_Session_Bag, get);
PHP_METHOD(Phalcon_Session_Bag, has);
PHP_METHOD(Phalcon_Session_Bag, __get);
PHP_METHOD(Phalcon_Session_Bag, remove);
PHP_METHOD(Phalcon_Session_Bag, getIterator);
PHP_METHOD(Phalcon_Session_Bag, count);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_session_bag_method_entry[] = {
	PHP_ME(Phalcon_Session_Bag, __construct, arginfo_phalcon_session_bag___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Session_Bag, setDI, arginfo_phalcon_di_injectionawareinterface_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, getDI, arginfo_phalcon_di_injectionawareinterface_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, initialize, arginfo_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, destroy, arginfo_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, set, arginfo_phalcon_session_baginterface_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, get, arginfo_phalcon_session_baginterface_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, has, arginfo_phalcon_session_baginterface_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, remove, arginfo_phalcon_session_baginterface_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, getIterator, arginfo_iteratoraggregate_getiterator, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, __get, arginfo___getref, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Session_Bag, __set, set, arginfo___set, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Session_Bag, __isset, has, arginfo___isset, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Session_Bag, __unset, remove, arginfo___unset, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Session_Bag, offsetGet, __get, arginfo_arrayaccess_offsetgetref, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Session_Bag, offsetSet, set, arginfo_arrayaccess_offsetset, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Session_Bag, offsetExists, has, arginfo_arrayaccess_offsetexists, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Session_Bag, offsetUnset, remove, arginfo_arrayaccess_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, count, arginfo_countable_count, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

static int phalcon_session_bag_maybe_initialize(zval *this_ptr TSRMLS_DC)
{
	zval *initialized;

	initialized = phalcon_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY TSRMLS_CC);
	if (PHALCON_IS_FALSE(initialized)) {
		return phalcon_call_method(NULL, this_ptr, "initialize", 0, NULL TSRMLS_CC);
	}

	return SUCCESS;
}

static zend_object_iterator* phalcon_session_bag_get_iterator(zend_class_entry *ce, zval *object, int by_ref TSRMLS_DC)
{
	zval *iterator;
	zval *data;
	zval *params[1];
	zend_object_iterator *ret;

	if (FAILURE == phalcon_session_bag_maybe_initialize(object TSRMLS_CC)) {
		return NULL;
	}

	data = phalcon_fetch_nproperty_this(object, SL("_data"), PH_NOISY TSRMLS_CC);

	MAKE_STD_ZVAL(iterator);
	object_init_ex(iterator, spl_ce_ArrayIterator);
	params[0] = data;
	if (FAILURE == phalcon_call_method(NULL, iterator, "__construct", 1, params TSRMLS_CC)) {
		ret = NULL;
	}
	else if (Z_TYPE_P(iterator) == IS_OBJECT) {
		ret = spl_ce_ArrayIterator->get_iterator(spl_ce_ArrayIterator, iterator, by_ref TSRMLS_CC);
	}
	else {
		ret = NULL;
	}

	zval_ptr_dtor(&iterator);
	return ret;
}

/**
 * Phalcon\Session\Bag initializer
 */
PHALCON_INIT_CLASS(Phalcon_Session_Bag){

	PHALCON_REGISTER_CLASS(Phalcon\\Session, Bag, session_bag, phalcon_session_bag_method_entry, 0);

	zend_declare_property_null(phalcon_session_bag_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_session_bag_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_session_bag_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_session_bag_ce, SL("_initialized"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_session_bag_ce, SL("_session"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_session_bag_ce->get_iterator = phalcon_session_bag_get_iterator;

	zend_class_implements(
		phalcon_session_bag_ce TSRMLS_CC, 5,
		phalcon_di_injectionawareinterface_ce,
		phalcon_session_baginterface_ce,
		zend_ce_aggregate,
		zend_ce_arrayaccess,
		spl_ce_Countable
	);

	return SUCCESS;
}

/**
 * Phalcon\Session\Bag constructor
 *
 * @param string $name
 */
PHP_METHOD(Phalcon_Session_Bag, __construct){

	zval **name;

	phalcon_fetch_params_ex(1, 0, &name);
	PHALCON_ENSURE_IS_STRING(name);
	phalcon_update_property_this(this_ptr, SL("_name"), *name TSRMLS_CC);
}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Session_Bag, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_session_exception_ce, 0);
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Session_Bag, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Initializes the session bag. This method must not be called directly, the class calls it when its internal data is accesed
 */
PHP_METHOD(Phalcon_Session_Bag, initialize){

	zval *session = NULL, *dependency_injector = NULL, *service;
	zval *name, **data, *tmp = NULL;

	PHALCON_MM_GROW();

	session = phalcon_fetch_nproperty_this(this_ptr, SL("_session"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(session) != IS_OBJECT) {
		dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {

			dependency_injector = NULL;
			PHALCON_CALL_CE_STATIC(&dependency_injector, phalcon_di_ce, "getdefault");

			if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_session_exception_ce, "A dependency injection object is required to access the 'session' service");
				return;
			}
		}

		PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_session_exception_ce, 1);

		PHALCON_INIT_VAR(service);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_session);

		session = NULL;
		PHALCON_CALL_METHOD(&session, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(session, phalcon_session_adapterinterface_ce);
		phalcon_update_property_this(this_ptr, SL("_session"), session TSRMLS_CC);
	}

	name = phalcon_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY TSRMLS_CC);

	/*if (!nusphere_dbg_present) {
#if PHP_VERSION_ID < 50500
		data = Z_OBJ_HANDLER_P(session, get_property_ptr_ptr)(session, name ZLK_NULL_CC TSRMLS_CC);
#else
		data = Z_OBJ_HANDLER_P(session, get_property_ptr_ptr)(session, name, BP_VAR_W ZLK_NULL_CC TSRMLS_CC);
#endif
	}
	else {*/
		PHALCON_CALL_METHOD(&tmp, session, "__get", name);
		data = &tmp;
	//}

	if (Z_TYPE_PP(data) != IS_ARRAY) {
		zval *empty_array;
		PHALCON_ALLOC_GHOST_ZVAL(empty_array);
		array_init(empty_array);
		phalcon_update_property_this(this_ptr, SL("_data"), empty_array TSRMLS_CC);
	}
	else {
		phalcon_update_property_this(this_ptr, SL("_data"), *data TSRMLS_CC);
	}

	phalcon_update_property_bool(this_ptr, SL("_initialized"), 1 TSRMLS_CC);
	PHALCON_MM_RESTORE();
}

/**
 * Destroys the session bag
 *
 *<code>
 * $user->destroy();
 *</code>
 */
PHP_METHOD(Phalcon_Session_Bag, destroy){

	zval *name, *session;

	RETURN_ON_FAILURE(phalcon_session_bag_maybe_initialize(this_ptr TSRMLS_CC));

	name    = phalcon_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY TSRMLS_CC);
	session = phalcon_fetch_nproperty_this(this_ptr, SL("_session"), PH_NOISY TSRMLS_CC);

	/*if (!nusphere_dbg_present) {
		Z_OBJ_HANDLER_P(session, unset_property)(session, name ZLK_NULL_CC TSRMLS_CC);
	}
	else {*/
		PHALCON_CALL_METHODW(NULL, session, "__unset", name);
	//}
}

/**
 * Sets a value in the session bag
 *
 *<code>
 * $user->set('name', 'Kimbra');
 *</code>
 *
 * @param string $property
 * @param string $value
 */
PHP_METHOD(Phalcon_Session_Bag, set){

	zval *property, *value, *session, *name, *data;

	phalcon_fetch_params(0, 2, 0, &property, &value);

	RETURN_ON_FAILURE(phalcon_session_bag_maybe_initialize(this_ptr TSRMLS_CC));

	phalcon_update_property_array(this_ptr, SL("_data"), property, value TSRMLS_CC);

	name    = phalcon_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY TSRMLS_CC);
	data    = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY TSRMLS_CC);
	session = phalcon_fetch_nproperty_this(this_ptr, SL("_session"), PH_NOISY TSRMLS_CC);

	/*if (!nusphere_dbg_present) {
		Z_OBJ_HANDLER_P(session, write_property)(session, name, data ZLK_NULL_CC TSRMLS_CC);
	}
	else {*/
		PHALCON_CALL_METHODW(NULL, session, "__set", name, data);
	//}
}

/**
 * Magic setter to assign values to the session bag.
 * Alias for Phalcon\Session\Bag::set()
 *
 *<code>
 * $user->name = "Kimbra";
 *</code>
 *
 * @param string $property
 * @param string $value
 */
PHALCON_DOC_METHOD(Phalcon_Session_Bag, __set);

/**
 * Obtains a value from the session bag optionally setting a default value
 *
 *<code>
 * echo $user->get('name', 'Kimbra');
 *</code>
 *
 * @param string $property
 * @param string $defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Session_Bag, get){

	zval *property, *default_value = NULL;
	zval *data, *value;

	phalcon_fetch_params(0, 1, 1, &property, &default_value);

	if (!default_value) {
		default_value = PHALCON_GLOBAL(z_null);
	}

	/* Check first if the bag is initialized */
	RETURN_ON_FAILURE(phalcon_session_bag_maybe_initialize(this_ptr TSRMLS_CC));

	/* Retrieve the data */
	data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_fetch(&value, data, property)) {
		RETURN_ZVAL(value, 1, 0);
	}

	RETURN_ZVAL(default_value, 1, 0);
}

/**
 * Magic getter to obtain values from the session bag.
 *
 *<code>
 * echo $user->name;
 *</code>
 *
 * @param string $property
 * @return string
 */
PHP_METHOD(Phalcon_Session_Bag, __get)
{
	zval *property, *data, *value;

	assert(return_value_ptr != NULL);

	phalcon_fetch_params(0, 1, 0, &property);

	/* Check first if the bag is initialized */
	RETURN_ON_FAILURE(phalcon_session_bag_maybe_initialize(this_ptr TSRMLS_CC));

	/* Retrieve the data */
	data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY TSRMLS_CC);
	zval_ptr_dtor(return_value_ptr);
	if (phalcon_array_isset_fetch(&value, data, property)) {
		*return_value_ptr = value;
	}
	else {
		zval *tmp, *name, *data, *session;

		ALLOC_INIT_ZVAL(tmp);
		Z_DELREF_P(tmp);
		phalcon_update_property_array(this_ptr, SL("_data"), property, tmp TSRMLS_CC);
		*return_value_ptr = tmp;

		name    = phalcon_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY TSRMLS_CC);
		data    = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY TSRMLS_CC);
		session = phalcon_fetch_nproperty_this(this_ptr, SL("_session"), PH_NOISY TSRMLS_CC);
		/*if (!nusphere_dbg_present) {
			Z_OBJ_HANDLER_P(session, write_property)(session, name, data ZLK_NULL_CC TSRMLS_CC);
		}
		else {*/
			PHALCON_CALL_METHODW(NULL, session, "__set", name, data);
		//}
	}

	Z_ADDREF_PP(return_value_ptr);
	Z_SET_ISREF_PP(return_value_ptr);
}


/**
 * Check whether a property is defined in the internal bag
 *
 *<code>
 * var_dump($user->has('name'));
 *</code>
 *
 * @param string $property
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Bag, has){

	zval *property, *data;

	phalcon_fetch_params(0, 1, 0, &property);

	RETURN_ON_FAILURE(phalcon_session_bag_maybe_initialize(this_ptr TSRMLS_CC));

	data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY TSRMLS_CC);
	RETURN_BOOL(phalcon_array_isset(data, property));
}

/**
 * Magic isset to check whether a property is defined in the bag.
 * Alias for Phalcon\Session\Bag::has()
 *
 *<code>
 * var_dump(isset($user['name']));
 *</code>
 *
 * @param string $property
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Session_Bag, __isset);

/**
 * Removes a property from the internal bag
 *
 *<code>
 * $user->remove('name');
 *</code>
 *
 * @param string $property
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Bag, remove){

	zval *property, *data = NULL, *name, *session;

	phalcon_fetch_params(0, 1, 0, &property);

	RETURN_ON_FAILURE(phalcon_session_bag_maybe_initialize(this_ptr TSRMLS_CC));

	data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset(data, property)) {
		phalcon_unset_property_array(this_ptr, SL("_data"), property TSRMLS_CC);

		data    = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY TSRMLS_CC);
		name    = phalcon_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY TSRMLS_CC);
		session = phalcon_fetch_nproperty_this(this_ptr, SL("_session"), PH_NOISY TSRMLS_CC);

		/*if (!nusphere_dbg_present) {
			Z_OBJ_HANDLER_P(session, write_property)(session, name, data ZLK_NULL_CC TSRMLS_CC);
		}
		else {*/
			PHALCON_CALL_METHODW(NULL, session, "__set", name, data);
		//}

		RETURN_TRUE;
	}

	RETURN_FALSE;
}

/**
 * Magic unset to remove items using the property syntax.
 * Alias for Phalcon\Session\Bag::remove()
 *
 *<code>
 * unset($user['name']);
 *</code>
 *
 * @param string $property
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Session_Bag, __unset);

PHP_METHOD(Phalcon_Session_Bag, getIterator)
{
	zval *data;

	RETURN_ON_FAILURE(phalcon_session_bag_maybe_initialize(this_ptr TSRMLS_CC));

	data = phalcon_fetch_nproperty_this(getThis(), SL("_data"), PH_NOISY TSRMLS_CC);
	object_init_ex(return_value, spl_ce_ArrayIterator);
	PHALCON_CALL_METHODW(NULL, return_value, "__construct", data);
}

PHP_METHOD(Phalcon_Session_Bag, count)
{
	zval *data;
	long int count;

	RETURN_ON_FAILURE(phalcon_session_bag_maybe_initialize(this_ptr TSRMLS_CC));

	data  = phalcon_fetch_nproperty_this(getThis(), SL("_data"), PH_NOISY TSRMLS_CC);
	count = (Z_TYPE_P(data) == IS_ARRAY) ? zend_hash_num_elements(Z_ARRVAL_P(data)) : 0;
	RETURN_LONG(count);
}
