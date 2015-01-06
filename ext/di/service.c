
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

#include "di/service.h"
#include "di/serviceinterface.h"
#include "di/service/builder.h"
#include "di/exception.h"
#include "events/managerinterface.h"

#include <Zend/zend_closures.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/operators.h"

#include "interned-strings.h"
#include "internal/arginfo.h"

/**
 * Phalcon\DI\Service
 *
 * Represents individually a service in the services container
 *
 *<code>
 * $service = new Phalcon\DI\Service('request', 'Phalcon\Http\Request');
 * $request = $service->resolve();
 *<code>
 *
 */
zend_class_entry *phalcon_di_service_ce;

static zend_object_handlers phalcon_di_service_object_handlers;

typedef struct _phalcon_di_service_object {
	zend_object obj;
	const char *name;
	zval *definition;
	zval *shared_instance;
	size_t name_len;
	zend_bool shared;
	zend_bool resolved;
} phalcon_di_service_object;

PHP_METHOD(Phalcon_DI_Service, __construct);
PHP_METHOD(Phalcon_DI_Service, getName);
PHP_METHOD(Phalcon_DI_Service, setShared);
PHP_METHOD(Phalcon_DI_Service, isShared);
PHP_METHOD(Phalcon_DI_Service, setSharedInstance);
PHP_METHOD(Phalcon_DI_Service, setDefinition);
PHP_METHOD(Phalcon_DI_Service, getDefinition);
PHP_METHOD(Phalcon_DI_Service, resolve);
PHP_METHOD(Phalcon_DI_Service, setParameter);
PHP_METHOD(Phalcon_DI_Service, getParameter);
PHP_METHOD(Phalcon_DI_Service, isResolved);
PHP_METHOD(Phalcon_DI_Service, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_di_service_method_entry[] = {
	PHP_ME(Phalcon_DI_Service, __construct, arginfo_phalcon_di_service___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_DI_Service, getName, arginfo_phalcon_di_serviceinterface_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Service, setShared, arginfo_phalcon_di_serviceinterface_setshared, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Service, isShared, arginfo_phalcon_di_serviceinterface_isshared, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Service, setSharedInstance, arginfo_phalcon_di_service_setsharedinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Service, setDefinition, arginfo_phalcon_di_serviceinterface_setdefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Service, getDefinition, arginfo_phalcon_di_serviceinterface_getdefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Service, resolve, arginfo_phalcon_di_serviceinterface_resolve, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Service, setParameter, arginfo_phalcon_di_service_setparameter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Service, getParameter, arginfo_phalcon_di_service_getparameter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Service, isResolved, arginfo_phalcon_di_serviceinterface_isresolved, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Service, __set_state, arginfo___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

static inline phalcon_di_service_object* phalcon_di_service_get_object(zval *obj TSRMLS_DC)
{
	return (phalcon_di_service_object*)zend_objects_get_address(obj TSRMLS_CC);
}

static void phalcon_di_service_dtor(void *v TSRMLS_DC)
{
	phalcon_di_service_object *obj = v;

	if (obj->name && !IS_INTERNED(obj->name)) {
		efree((char*)obj->name);
	}

	if (obj->definition) {
		zval_ptr_dtor(&obj->definition);
	}

	if (obj->shared_instance) {
		zval_ptr_dtor(&obj->shared_instance);
	}

	zend_object_std_dtor(&obj->obj TSRMLS_CC);
	efree(obj);
}

static zend_object_value phalcon_di_service_ctor(zend_class_entry* ce TSRMLS_DC)
{
	phalcon_di_service_object *obj = ecalloc(1, sizeof(phalcon_di_service_object));
	zend_object_value retval;

	zend_object_std_init(&obj->obj, ce TSRMLS_CC);
	object_properties_init(&obj->obj, ce);

	retval.handle = zend_objects_store_put(
		obj,
		(zend_objects_store_dtor_t)zend_objects_destroy_object,
		phalcon_di_service_dtor,
		NULL TSRMLS_CC
	);

	retval.handlers = &phalcon_di_service_object_handlers;
	return retval;
}

static zend_object_value phalcon_di_service_clone_obj(zval *zobject TSRMLS_DC)
{
	zend_object_value new_obj_val;
	phalcon_di_service_object *old_object;
	phalcon_di_service_object *new_object;
	zend_object_handle handle = Z_OBJ_HANDLE_P(zobject);

	old_object  = phalcon_di_service_get_object(zobject TSRMLS_CC);
	new_obj_val = phalcon_di_service_ctor(Z_OBJCE_P(zobject) TSRMLS_CC);
	new_object  = zend_object_store_get_object_by_handle(new_obj_val.handle TSRMLS_CC);

	zend_objects_clone_members(&new_object->obj, new_obj_val, &old_object->obj, handle TSRMLS_CC);

	if (old_object->name) {
		new_object->name     = estrndup(old_object->name, old_object->name_len);
		new_object->name_len = old_object->name_len;
	}

	if (old_object->definition) {
		ZVAL_ZVAL(new_object->definition, old_object->definition, 1, 0);
	}

	if (old_object->shared_instance) {
		ZVAL_ZVAL(new_object->shared_instance, old_object->shared_instance, 1, 0);
	}

	new_object->resolved = old_object->resolved;
	new_object->shared   = old_object->shared;

	return new_obj_val;
}

static HashTable* phalcon_di_service_get_debug_info(zval *object, int *is_temp TSRMLS_DC)
{
	phalcon_di_service_object *obj = phalcon_di_service_get_object(object TSRMLS_CC);
	HashTable *props = Z_OBJPROP_P(object);
	HashTable *ht;
	zval *tmp;

	*is_temp = 1;

	ALLOC_HASHTABLE(ht);
	zend_hash_init(ht, zend_hash_num_elements(props) + 5, NULL, ZVAL_PTR_DTOR, 0);
	zend_hash_copy(ht, props, (copy_ctor_func_t)zval_add_ref, NULL, sizeof(zval*));

	MAKE_STD_ZVAL(tmp);
	if (obj->name) {
		ZVAL_STRINGL(tmp, obj->name, obj->name_len, !IS_INTERNED(obj->name));
	}
	else {
		ZVAL_EMPTY_STRING(tmp);
	}

	zend_hash_quick_update(ht, "_name", sizeof("_name"), zend_inline_hash_func(SS("_name")), (void*)&tmp, sizeof(zval*), NULL);

	if (obj->definition) {
		Z_ADDREF_P(obj->definition);
		tmp = obj->definition;
	}
	else {
		ALLOC_INIT_ZVAL(tmp);
	}

	zend_hash_quick_update(ht, "_definition", sizeof("_definition"), zend_inline_hash_func(SS("_definition")), (void*)&tmp, sizeof(zval*), NULL);

	if (obj->shared_instance) {
		Z_ADDREF_P(obj->shared_instance);
		tmp = obj->shared_instance;
	}
	else {
		ALLOC_INIT_ZVAL(tmp);
	}

	zend_hash_quick_update(ht, "_sharedInstance", sizeof("_sharedInstance"), zend_inline_hash_func(SS("_sharedInstance")), (void*)&tmp, sizeof(zval*), NULL);

	MAKE_STD_ZVAL(tmp);
	ZVAL_BOOL(tmp, obj->resolved);
	zend_hash_quick_update(ht, "_resolved", sizeof("_resolved"), zend_inline_hash_func(SS("_resolved")), (void*)&tmp, sizeof(zval*), NULL);

	MAKE_STD_ZVAL(tmp);
	ZVAL_BOOL(tmp, obj->shared);
	zend_hash_quick_update(ht, "_shared", sizeof("_shared"), zend_inline_hash_func(SS("_shared")), (void*)&tmp, sizeof(zval*), NULL);

	return ht;
}

/**
 * Phalcon\DI\Service initializer
 */
PHALCON_INIT_CLASS(Phalcon_DI_Service){

	PHALCON_REGISTER_CLASS(Phalcon\\DI, Service, di_service, phalcon_di_service_method_entry, 0);

	phalcon_di_service_ce->create_object = phalcon_di_service_ctor;

	phalcon_di_service_object_handlers = *zend_get_std_object_handlers();
	phalcon_di_service_object_handlers.clone_obj      = phalcon_di_service_clone_obj;
	phalcon_di_service_object_handlers.get_debug_info = phalcon_di_service_get_debug_info;

	zend_class_implements(phalcon_di_service_ce TSRMLS_CC, 1, phalcon_di_serviceinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\DI\Service
 *
 * @param string $name
 * @param mixed $definition
 * @param boolean $shared
 */
PHP_METHOD(Phalcon_DI_Service, __construct){

	zval **name, **definition, **shared = NULL;
	phalcon_di_service_object *obj;
	char *sname;

	phalcon_fetch_params_ex(2, 1, &name, &definition, &shared);

	PHALCON_ENSURE_IS_STRING(name);
	Z_ADDREF_PP(definition);

	//sname = (char*)zend_new_interned_string(Z_STRVAL_PP(name), Z_STRLEN_PP(name), 0 TSRMLS_CC);
	//if (!IS_INTERNED(sname)) {
		sname = estrndup(Z_STRVAL_PP(name), Z_STRLEN_PP(name));
	//}

	obj                  = phalcon_di_service_get_object(getThis() TSRMLS_CC);
	obj->name            = sname;
	obj->name_len        = Z_STRLEN_PP(name);
	obj->definition      = *definition;
	obj->shared          = shared ? zend_is_true(*shared) : 0;
	obj->shared_instance = NULL;
	obj->resolved        = 0;
}

/**
 * Returns the service's name
 *
 * @param string
 */
PHP_METHOD(Phalcon_DI_Service, getName)
{
	phalcon_di_service_object *obj = phalcon_di_service_get_object(getThis() TSRMLS_CC);
	RETURN_STRINGL(obj->name, obj->name_len, !IS_INTERNED(obj->name));
}

/**
 * Sets if the service is shared or not
 *
 * @param boolean $shared
 */
PHP_METHOD(Phalcon_DI_Service, setShared)
{
	zval *shared;
	phalcon_di_service_object *obj = phalcon_di_service_get_object(getThis() TSRMLS_CC);

	phalcon_fetch_params(0, 1, 0, &shared);
	obj->shared = zend_is_true(shared);
}

/**
 * Check whether the service is shared or not
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_DI_Service, isShared)
{
	phalcon_di_service_object *obj = phalcon_di_service_get_object(getThis() TSRMLS_CC);
	RETURN_BOOL(obj->shared);
}

/**
 * Sets/Resets the shared instance related to the service
 *
 * @param mixed $sharedInstance
 */
PHP_METHOD(Phalcon_DI_Service, setSharedInstance)
{
	zval *shared_instance;
	phalcon_di_service_object *obj = phalcon_di_service_get_object(getThis() TSRMLS_CC);

	phalcon_fetch_params(0, 1, 0, &shared_instance);

	if (obj->shared_instance) {
		zval_ptr_dtor(&obj->shared_instance);
	}

	obj->shared_instance = shared_instance;
}

/**
 * Set the service definition
 *
 * @param mixed $definition
 */
PHP_METHOD(Phalcon_DI_Service, setDefinition)
{
	zval *definition;
	phalcon_di_service_object *obj = phalcon_di_service_get_object(getThis() TSRMLS_CC);

	phalcon_fetch_params(0, 1, 0, &definition);

	if (obj->definition) {
		zval_ptr_dtor(&obj->definition);
	}

	obj->definition = definition;
}

/**
 * Returns the service definition
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_DI_Service, getDefinition)
{
	phalcon_di_service_object *obj = phalcon_di_service_get_object(getThis() TSRMLS_CC);
	RETURN_ZVAL(obj->definition, 1, 0);
}

/**
 * Resolves the service
 *
 * @param array $parameters
 * @param Phalcon\DiInterface $dependencyInjector
 * @return object
 */
PHP_METHOD(Phalcon_DI_Service, resolve){

	zval *parameters = NULL, *dependency_injector = NULL;
	zval *instance = NULL, *definition, *builder;
	int found;
	phalcon_di_service_object *obj = phalcon_di_service_get_object(getThis() TSRMLS_CC);

	phalcon_fetch_params(0, 0, 2, &parameters, &dependency_injector);

	if (!parameters) {
		parameters = PHALCON_GLOBAL(z_null);
	}

	if (!dependency_injector) {
		dependency_injector = PHALCON_GLOBAL(z_null);
	}

	/* Check if the service is shared */
	if (obj->shared && obj->shared_instance) {
		RETURN_ZVAL(obj->shared_instance, 1, 0);
	}

	PHALCON_MM_GROW();

	definition = obj->definition;
	found      = 0;
	if (Z_TYPE_P(definition) == IS_STRING) {
		/* String definitions can be class names without implicit parameters */
		if (phalcon_class_exists(Z_STRVAL_P(definition), Z_STRLEN_P(definition), 1 TSRMLS_CC)) {
			found = 1;
			if (Z_TYPE_P(parameters) == IS_ARRAY) {
				PHALCON_INIT_VAR(instance);
				RETURN_MM_ON_FAILURE(phalcon_create_instance_params(instance, definition, parameters TSRMLS_CC));
			} else {
				PHALCON_INIT_VAR(instance);
				RETURN_MM_ON_FAILURE(phalcon_create_instance(instance, definition TSRMLS_CC));
			}
		}
	}
	else if (likely(Z_TYPE_P(definition) == IS_OBJECT)) {
		/* Object definitions can be a Closure or an already resolved instance */
		found = 1;
		if (instanceof_function_ex(Z_OBJCE_P(definition), zend_ce_closure, 0 TSRMLS_CC)) {
			PHALCON_INIT_VAR(instance);
			if (Z_TYPE_P(parameters) == IS_ARRAY) {
				PHALCON_CALL_USER_FUNC_ARRAY(instance, definition, parameters);
			}
			else {
				PHALCON_CALL_USER_FUNC(instance, definition);
			}
		}
		else {
			PHALCON_CPY_WRT(instance, definition);
		}
	}
	else if (Z_TYPE_P(definition) == IS_ARRAY) {
		/* Array definitions require a 'className' parameter */
		PHALCON_INIT_VAR(builder);
		object_init_ex(builder, phalcon_di_service_builder_ce);

		PHALCON_CALL_METHOD(&instance, builder, "build", dependency_injector, definition, parameters);
		found = 1;
	}

	if (EG(exception)) {
		return;
	}

	/* If the service can't be built, we must throw an exception */
	if (!found) {
		zend_throw_exception_ex(phalcon_di_exception_ce, 0 TSRMLS_CC, "Service '%s' cannot be resolved", obj->name);
		PHALCON_MM_RESTORE();
		return;
	}

	//if (Z_TYPE_P(instance) != IS_OBJECT) {
	//	php_error_docref0(NULL TSRMLS_CC, E_DEPRECATED, "Usage of Phalcon\\DI to store non-objects is deprecated, please use Phalcon\\Registry instead");
	//}

	/* Update the shared instance if the service is shared */
	if (obj->shared) {
		Z_ADDREF_P(instance);
		obj->shared_instance = instance;
	}

	obj->resolved = 1;

	RETURN_CTOR(instance);
}

/**
 * Changes a parameter in the definition without resolve the service
 *
 * @param long $position
 * @param array $parameter
 * @return Phalcon\DI\Service
 */
PHP_METHOD(Phalcon_DI_Service, setParameter){

	zval **position, **parameter, *definition, *arguments = NULL;
	phalcon_di_service_object *obj = phalcon_di_service_get_object(getThis() TSRMLS_CC);

	phalcon_fetch_params_ex(2, 0, &position, &parameter);
	PHALCON_ENSURE_IS_LONG(position);

	definition = obj->definition;
	if (unlikely(Z_TYPE_P(definition) != IS_ARRAY)) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_di_exception_ce, "Definition must be an array to update its parameters");
		return;
	}

	if (unlikely(Z_TYPE_PP(parameter) != IS_ARRAY)) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_di_exception_ce, "The parameter must be an array");
		return;
	}

	/* Update the parameter */
	if (phalcon_array_isset_string_fetch(&arguments, definition, SS("arguments"))) {
		phalcon_array_update_zval(&arguments, *position, *parameter, PH_COPY);
	} else {
		MAKE_STD_ZVAL(arguments);
		array_init_size(arguments, 1);
		phalcon_array_update_zval(&arguments, *position, *parameter, PH_COPY);
		phalcon_array_update_string(&definition, SL("arguments"), arguments, 0);
	}

	RETURN_THISW();
}

/**
 * Returns a parameter in a specific position
 *
 * @param int $position
 * @return array
 */
PHP_METHOD(Phalcon_DI_Service, getParameter){

	zval **position, *definition, *arguments, *parameter;
	phalcon_di_service_object *obj = phalcon_di_service_get_object(getThis() TSRMLS_CC);

	phalcon_fetch_params_ex(1, 0, &position);
	PHALCON_ENSURE_IS_LONG(position);

	definition = obj->definition;
	if (Z_TYPE_P(definition) != IS_ARRAY) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_di_exception_ce, "Definition must be an array to obtain its parameters");
		return;
	}

	/* Update the parameter */
	if (
			phalcon_array_isset_string_fetch(&arguments, definition, SS("arguments"))
		 && phalcon_array_isset_fetch(&parameter, arguments, *position)
	) {
		RETURN_ZVAL(parameter, 1, 0);
	}

	RETURN_NULL();
}

/**
 * Returns true if the service was resolved
 *
 * @return bool
 */
PHP_METHOD(Phalcon_DI_Service, isResolved)
{
	phalcon_di_service_object *obj = phalcon_di_service_get_object(getThis() TSRMLS_CC);
	RETURN_BOOL(obj->resolved);
}

/**
 * Restore the internal state of a service
 *
 * @param array $attributes
 * @return Phalcon\DI\Service
 */
PHP_METHOD(Phalcon_DI_Service, __set_state){

	zval *attributes, *name, *definition, *shared;

	phalcon_fetch_params(0, 1, 0, &attributes);

	if (
			!phalcon_array_isset_string_fetch(&name, attributes, SS("_name"))
		 || !phalcon_array_isset_string_fetch(&definition, attributes, SS("_definition"))
		 || !phalcon_array_isset_string_fetch(&shared, attributes, SS("_shared"))
	) {
		PHALCON_THROW_EXCEPTION_STR(spl_ce_BadMethodCallException, "Bad parameters passed to Phalcon\\DI\\Service::__set_state()");
		return;
	}

	PHALCON_MM_GROW();
	object_init_ex(return_value, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, return_value, "__construct", name, definition, shared);
	RETURN_MM();
}
