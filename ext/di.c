
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
  |          Nikolaos Dimopoulos <nikos@niden.net>                         |
  +------------------------------------------------------------------------+
*/

#include "di.h"
#include "diinterface.h"
#include "di/exception.h"
#include "di/injectionawareinterface.h"
#include "di/service.h"
#include "di/serviceinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/string.h"
#include "kernel/hash.h"

#include "internal/arginfo.h"

/**
 * Phalcon\DI
 *
 * Phalcon\DI is a component that implements Dependency Injection/Service Location
 * of services and it's itself a container for them.
 *
 * Since Phalcon is highly decoupled, Phalcon\DI is essential to integrate the different
 * components of the framework. The developer can also use this component to inject dependencies
 * and manage global instances of the different classes used in the application.
 *
 * Basically, this component implements the `Inversion of Control` pattern. Applying this,
 * the objects do not receive their dependencies using setters or constructors, but requesting
 * a service dependency injector. This reduces the overall complexity, since there is only one
 * way to get the required dependencies within a component.
 *
 * Additionally, this pattern increases testability in the code, thus making it less prone to errors.
 *
 *<code>
 * $di = new Phalcon\DI();
 *
 * //Using a string definition
 * $di->set('request', 'Phalcon\Http\Request', true);
 *
 * //Using an anonymous function
 * $di->set('request', function(){
 *	  return new Phalcon\Http\Request();
 * }, true);
 *
 * $request = $di->getRequest();
 *
 *</code>
 */
zend_class_entry *phalcon_di_ce;

static zend_object_handlers phalcon_di_object_handlers;

typedef struct _phalcon_di_object {
	zend_object obj;
	HashTable* services;
	HashTable* shared;
	int fresh;
} phalcon_di_object;

static inline phalcon_di_object* phalcon_di_get_object(zval *obj TSRMLS_DC)
{
	return (phalcon_di_object*)zend_objects_get_address(obj TSRMLS_CC);
}

static PHP_FUNCTION(phalcon_di_method_handler)
{
	Z_OBJ_HANDLER_P(getThis(), call_method)(((zend_internal_function*)EG(current_execute_data)->function_state.function)->function_name, INTERNAL_FUNCTION_PARAM_PASSTHRU);
	efree(((zend_internal_function*)EG(current_execute_data)->function_state.function));
}

static union _zend_function* phalcon_di_get_method(zval **object_ptr, char *method, int method_len ZLK_DC TSRMLS_DC)
{
	char *lc_method_name   = emalloc(method_len + 1);
	phalcon_di_object *obj = phalcon_di_get_object(*object_ptr TSRMLS_CC);
	zend_function fbc;

	zend_str_tolower_copy(lc_method_name, method, method_len);

	if (
		   zend_hash_find(&obj->obj.ce->function_table, lc_method_name, method_len+1, (void **)&fbc) == FAILURE
		&& method_len > 3
		&& (!memcmp(lc_method_name, "get", 3) || !memcmp(lc_method_name, "set", 3))
	) {
		zend_internal_function *f = emalloc(sizeof(zend_internal_function));

		f->type          = ZEND_INTERNAL_FUNCTION;
		f->handler       = ZEND_FN(phalcon_di_method_handler);
		f->arg_info      = NULL;
		f->num_args      = 0;
		f->scope         = obj->obj.ce;
		f->fn_flags      = ZEND_ACC_CALL_VIA_HANDLER;
		f->function_name = method;
#if PHP_VERSION_ID < 50400
		f->module        = obj->obj.ce->module;
		f->pass_rest_by_reference = 0;
		f->return_reference = ZEND_RETURN_VALUE;
#else
		f->module        = (ZEND_INTERNAL_CLASS == obj->obj.ce->type) ? obj->obj.ce->info.internal.module : 0;
#endif

		efree(lc_method_name);
		return (union _zend_function*)f;
	}

	efree(lc_method_name);
	return std_object_handlers.get_method(object_ptr, method, method_len ZLK_CC TSRMLS_CC);
}

static int phalcon_di_call_method_internal(zval *return_value, zval **return_value_ptr, zval *this_ptr, const char *method, zval *param TSRMLS_DC)
{
	int method_len       = strlen(method);
	char *lc_method_name = emalloc(method_len + 1);
	int retval           = FAILURE;

	zend_str_tolower_copy(lc_method_name, method, method_len);

	if (method_len > 3 && (!memcmp(lc_method_name, "get", 3) || !memcmp(lc_method_name, "set", 3))) {
		phalcon_di_object *obj = phalcon_di_get_object(getThis() TSRMLS_CC);
		char *service          = estrndup(method+3, method_len-3);

		service[0] = tolower(service[0]);

		if (SUCCESS == zend_symtable_exists(obj->services, method, method_len + 1)) {
			zval *svc;
			zval *params[2];

			PHALCON_ALLOC_GHOST_ZVAL(svc);
			ZVAL_STRINGL(svc, service, method_len - 3, 0);

			params[0] = svc;
			params[1] = param;

			if (lc_method_name[0] == 'g') {
				retval = phalcon_return_call_method(return_value, return_value_ptr, this_ptr, "get", 2, params TSRMLS_CC);
			}
			else {
				retval = phalcon_return_call_method(return_value, return_value_ptr, this_ptr, "set", 2, params TSRMLS_CC);
			}

			if (EG(exception)) {
				retval = SUCCESS;
			}
		}
	}

	if (FAILURE == retval) {
		zend_throw_exception_ex(phalcon_di_exception_ce, 0 TSRMLS_CC, "Call to undefined method or service '%s'", method);
	}

	efree(lc_method_name);
	return retval;
}

static int phalcon_di_call_method(const char *method, INTERNAL_FUNCTION_PARAMETERS)
{
	zval **param;

	if (!ZEND_NUM_ARGS()) {
		param = &PHALCON_GLOBAL(z_null);
	}
	else {
		phalcon_fetch_parameters_ex(0 TSRMLS_CC, 1, 0, &param);
	}

	return phalcon_di_call_method_internal(return_value, return_value_ptr, getThis(), method, *param TSRMLS_CC);
}

static zval* phalcon_di_read_dimension_internal(zval *this_ptr, phalcon_di_object *obj, zval *offset, zval *parameters TSRMLS_DC)
{
	zval *tmp = NULL;
	zval **retval = &tmp, **service;
	zend_class_entry *ce;

	assert(Z_TYPE_P(offset) == IS_STRING);

	if (UNEXPECTED(!offset)) {
		return EG(uninitialized_zval_ptr);
	}

	if (SUCCESS == zend_symtable_find(obj->shared, Z_STRVAL_P(offset), Z_STRLEN_P(offset)+1, (void**)&retval)) {
		obj->fresh = 0;
		return *retval;
	}

	/* Resolve the instance normally */
	if (SUCCESS == zend_symtable_find(obj->services, Z_STRVAL_P(offset), Z_STRLEN_P(offset)+1, (void**)&service)) {
		zval *params[] = { parameters, this_ptr };

		/* The service is registered in the DI */
		if (FAILURE == phalcon_call_method(retval, *service, "resolve", 2, params TSRMLS_CC)) {
			return NULL;
		}

		/* *retval has refcount = 1 here, it will be used in zend_symtable_update() */
		ce = (Z_TYPE_PP(retval) == IS_OBJECT) ? Z_OBJCE_PP(retval) : NULL;
	}
	else {
		/* The DI also acts as builder for any class even if it isn't defined in the DI */
		if (phalcon_class_exists_ex(&ce, offset, 1 TSRMLS_CC)) {
			MAKE_STD_ZVAL(*retval);
			if (FAILURE == phalcon_create_instance_params_ce(*retval, ce, parameters TSRMLS_CC)) {
				return NULL;
			}

			/* *retval has refcount = 1 here, it will be used in zend_symtable_update() */
		}
		else {
			zend_throw_exception_ex(phalcon_di_exception_ce, 0 TSRMLS_CC, "Service '%s' was not found in the dependency injection container", Z_STRVAL_P(offset));
			return NULL;
		}
	}

	/* Pass the DI itself if the instance implements Phalcon\DI\InjectionAwareInterface */
	if (ce && instanceof_function_ex(ce, phalcon_di_injectionawareinterface_ce, 1 TSRMLS_CC)) {
		zval *params[] = { this_ptr };
		if (FAILURE == phalcon_call_method(NULL, *retval, "setdi", 1, params TSRMLS_CC)) {
			zval_ptr_dtor(retval);
			return NULL;
		}
	}

	/**
	 * Save the instance in the first level shared
	 */
	assert(Z_REFCOUNT_PP(retval) == 1);
	zend_symtable_update(obj->shared, Z_STRVAL_P(offset), Z_STRLEN_P(offset)+1, (void*)retval, sizeof(zval*), NULL);
	obj->fresh = 1;

	return *retval;
}

static zval* phalcon_di_read_dimension(zval *object, zval *offset, int type TSRMLS_DC)
{
	phalcon_di_object *obj = phalcon_di_get_object(object TSRMLS_CC);
	zval tmp, *ret;

	if (!is_phalcon_class(obj->obj.ce)) {
		return zend_get_std_object_handlers()->read_dimension(object, offset, type TSRMLS_CC);
	}

	if (UNEXPECTED(Z_TYPE_P(offset) != IS_STRING)) {
		ZVAL_ZVAL(&tmp, offset, 1, 0);
		convert_to_string(&tmp);
		offset = &tmp;
	}

	ret = phalcon_di_read_dimension_internal(object, obj, offset, PHALCON_GLOBAL(z_null) TSRMLS_CC);

	if (UNEXPECTED(offset == &tmp)) {
		zval_dtor(&tmp);
	}

	return ret;
}

static int phalcon_di_has_dimension_internal(phalcon_di_object *obj, zval *offset, int check_empty)
{
	zval **tmp = phalcon_hash_get(obj->services, offset, BP_VAR_NA);

	if (!tmp) {
		return 0;
	}

	if (0 == check_empty) {
		return Z_TYPE_PP(tmp) != IS_NULL;
	}

	if (1 == check_empty) {
		return zend_is_true(*tmp);
	}

	return 1;
}

static int phalcon_di_has_dimension(zval *object, zval *offset, int check_empty TSRMLS_DC)
{
	phalcon_di_object *obj = phalcon_di_get_object(object TSRMLS_CC);

	if (!is_phalcon_class(obj->obj.ce)) {
		return zend_get_std_object_handlers()->has_dimension(object, offset, check_empty TSRMLS_CC);
	}

	return phalcon_di_has_dimension_internal(obj, offset, check_empty);
}

static zval* phalcon_di_write_dimension_internal(phalcon_di_object *obj, zval *offset, zval *value TSRMLS_DC)
{
	zval *retval;
	zval *params[] = { offset, value, PHALCON_GLOBAL(z_true) };

	assert(Z_TYPE_P(offset) == IS_STRING);

	MAKE_STD_ZVAL(retval);
	object_init_ex(retval, phalcon_di_service_ce);
	if (FAILURE == phalcon_call_method(NULL, retval, "__construct", 3, params TSRMLS_CC)) {
		return NULL;
	}

	zend_hash_update(obj->services, Z_STRVAL_P(offset), Z_STRLEN_P(offset)+1, &retval, sizeof(zval*), NULL);
	return retval;
}

static void phalcon_di_write_dimension(zval *object, zval *offset, zval *value TSRMLS_DC)
{
	phalcon_di_object *obj = phalcon_di_get_object(object TSRMLS_CC);
	zval tmp;

	if (!is_phalcon_class(obj->obj.ce)) {
		zend_get_std_object_handlers()->write_dimension(object, offset, value TSRMLS_CC);
		return;
	}

	if (UNEXPECTED(Z_TYPE_P(offset) != IS_STRING)) {
		ZVAL_ZVAL(&tmp, offset, 1, 0);
		convert_to_string(&tmp);
		offset = &tmp;
	}

	phalcon_di_write_dimension_internal(obj, offset, value TSRMLS_CC);

	if (UNEXPECTED(offset == &tmp)) {
		zval_dtor(&tmp);
	}
}

static inline void phalcon_di_unset_dimension_internal(phalcon_di_object *obj, zval *offset)
{
	assert(Z_TYPE_P(offset) == IS_STRING);
	zend_symtable_del(obj->services, Z_STRVAL_P(offset), Z_STRLEN_P(offset)+1);
}

static void phalcon_di_unset_dimension(zval *object, zval *offset TSRMLS_DC)
{
	phalcon_di_object *obj = phalcon_di_get_object(object TSRMLS_CC);
	zval tmp;

	if (!is_phalcon_class(obj->obj.ce)) {
		zend_get_std_object_handlers()->unset_dimension(object, offset TSRMLS_CC);
		return;
	}

	if (UNEXPECTED(Z_TYPE_P(offset) != IS_STRING)) {
		ZVAL_ZVAL(&tmp, offset, 1, 0);
		convert_to_string(&tmp);
		offset = &tmp;
	}

	phalcon_di_unset_dimension_internal(obj, offset);

	if (UNEXPECTED(offset == &tmp)) {
		zval_dtor(&tmp);
	}
}

static HashTable* phalcon_di_get_properties(zval* object TSRMLS_DC)
{
	HashTable* props = zend_std_get_properties(object TSRMLS_CC);

	if (!GC_G(gc_active) && !props->nApplyCount) {
		phalcon_di_object *obj = phalcon_di_get_object(object TSRMLS_CC);
		zval *zv;

		MAKE_STD_ZVAL(zv);
		array_init_size(zv, zend_hash_num_elements(obj->services));
		zend_hash_copy(Z_ARRVAL_P(zv), obj->services, (copy_ctor_func_t)zval_add_ref, NULL, sizeof(zval*));
		zend_hash_quick_update(props, "_services", sizeof("_services"), zend_inline_hash_func(SS("_sharedInstances")), (void*)&zv, sizeof(zval*), NULL);

		MAKE_STD_ZVAL(zv);
		array_init_size(zv, zend_hash_num_elements(obj->shared));
		zend_hash_copy(Z_ARRVAL_P(zv), obj->shared, (copy_ctor_func_t)zval_add_ref, NULL, sizeof(zval*));
		zend_hash_quick_update(props, "_sharedInstances", sizeof("_sharedInstances"), zend_inline_hash_func(SS("_sharedInstances")), (void*)&zv, sizeof(zval*), NULL);

		MAKE_STD_ZVAL(zv);
		ZVAL_BOOL(zv, obj->fresh);
		zend_hash_quick_update(props, "_freshInstance", sizeof("_freshInstance"), zend_inline_hash_func(SS("_freshInstance")), (void*)&zv, sizeof(zval*), NULL);
	}

	return props;
}

static void phalcon_di_dtor(void *v TSRMLS_DC)
{
	phalcon_di_object *obj = v;

	zend_hash_destroy(obj->services);
	zend_hash_destroy(obj->shared);
	FREE_HASHTABLE(obj->services);
	FREE_HASHTABLE(obj->shared);

	zend_object_std_dtor(&obj->obj TSRMLS_CC);
	efree(obj);
}

static zend_object_value phalcon_di_ctor(zend_class_entry* ce TSRMLS_DC)
{
	phalcon_di_object *obj = ecalloc(1, sizeof(phalcon_di_object));
	zend_object_value retval;

	zend_object_std_init(&obj->obj, ce TSRMLS_CC);
	object_properties_init(&obj->obj, ce);

	ALLOC_HASHTABLE(obj->services);
	ALLOC_HASHTABLE(obj->shared);
	zend_hash_init(obj->services, 32, NULL, ZVAL_PTR_DTOR, 0);
	zend_hash_init(obj->shared, 8, NULL, ZVAL_PTR_DTOR, 0);

	retval.handle = zend_objects_store_put(
		obj,
		(zend_objects_store_dtor_t)zend_objects_destroy_object,
		phalcon_di_dtor,
		NULL TSRMLS_CC
	);

	retval.handlers = &phalcon_di_object_handlers;
	return retval;
}

static zend_object_value phalcon_di_clone_obj(zval *zobject TSRMLS_DC)
{
	zend_object_value new_obj_val;
	phalcon_di_object *old_object;
	phalcon_di_object *new_object;
	zend_object_handle handle = Z_OBJ_HANDLE_P(zobject);

	old_object  = phalcon_di_get_object(zobject TSRMLS_CC);
	new_obj_val = phalcon_di_ctor(Z_OBJCE_P(zobject) TSRMLS_CC);
	new_object  = zend_object_store_get_object_by_handle(new_obj_val.handle TSRMLS_CC);

	zend_objects_clone_members(&new_object->obj, new_obj_val, &old_object->obj, handle TSRMLS_CC);

	zend_hash_copy(new_object->services, old_object->services, (copy_ctor_func_t)zval_add_ref, NULL, sizeof(zval*));
	zend_hash_copy(new_object->shared, old_object->shared, (copy_ctor_func_t)zval_add_ref, NULL, sizeof(zval*));
	new_object->fresh = old_object->fresh;

	return new_obj_val;
}

void phalcon_di_set_services(zval *this_ptr, zval *services TSRMLS_DC)
{
	phalcon_di_object *obj = phalcon_di_get_object(this_ptr TSRMLS_CC);
	zend_hash_copy(obj->services, Z_ARRVAL_P(services), (copy_ctor_func_t)zval_add_ref, NULL, sizeof(zval*));
}

PHP_METHOD(Phalcon_DI, __construct);
PHP_METHOD(Phalcon_DI, set);
PHP_METHOD(Phalcon_DI, setShared);
PHP_METHOD(Phalcon_DI, remove);
PHP_METHOD(Phalcon_DI, attempt);
PHP_METHOD(Phalcon_DI, getRaw);
PHP_METHOD(Phalcon_DI, setService);
PHP_METHOD(Phalcon_DI, getService);
PHP_METHOD(Phalcon_DI, get);
PHP_METHOD(Phalcon_DI, getShared);
PHP_METHOD(Phalcon_DI, has);
PHP_METHOD(Phalcon_DI, wasFreshInstance);
PHP_METHOD(Phalcon_DI, getServices);
PHP_METHOD(Phalcon_DI, __call);
PHP_METHOD(Phalcon_DI, setDefault);
PHP_METHOD(Phalcon_DI, getDefault);
PHP_METHOD(Phalcon_DI, reset);
PHP_METHOD(Phalcon_DI, __clone);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di___call, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_setshared, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_attempt, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_getraw, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_di_method_entry[] = {
	PHP_ME(Phalcon_DI, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	/* Phalcon\DiInterface*/
	PHP_ME(Phalcon_DI, set, arginfo_phalcon_diinterface_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI, remove, arginfo_phalcon_diinterface_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI, getRaw, arginfo_phalcon_di_getraw, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI, getService, arginfo_phalcon_diinterface_getservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI, setService, arginfo_phalcon_diinterface_setservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI, get, arginfo_phalcon_diinterface_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI, getShared, arginfo_phalcon_diinterface_getshared, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI, has, arginfo_phalcon_diinterface_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI, wasFreshInstance, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI, getServices, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI, setDefault, arginfo_phalcon_diinterface_setdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_DI, getDefault, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_DI, reset, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)

	/* Convenience methods */
	PHP_ME(Phalcon_DI, attempt, arginfo_phalcon_di_attempt, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI, setShared, arginfo_phalcon_di_setshared, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_DI, setRaw, setService, arginfo_phalcon_diinterface_setservice, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)

	/* Syntactic sugar */
	PHP_MALIAS(Phalcon_DI, offsetExists, has, arginfo_arrayaccess_offsetexists, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_DI, offsetSet, setShared, arginfo_arrayaccess_offsetset, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_DI, offsetGet, getShared, arginfo_arrayaccess_offsetget, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_DI, offsetUnset, remove, arginfo_arrayaccess_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI, __call, arginfo_phalcon_di___call, ZEND_ACC_PUBLIC)

	/* Misc */
	PHP_ME(Phalcon_DI, __clone, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\DI initializer
 */
PHALCON_INIT_CLASS(Phalcon_DI){

	PHALCON_REGISTER_CLASS(Phalcon, DI, di, phalcon_di_method_entry, 0);

	zend_declare_property_null(phalcon_di_ce, SL("_default"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_class_implements(phalcon_di_ce TSRMLS_CC, 1, phalcon_diinterface_ce);

	phalcon_di_ce->create_object = phalcon_di_ctor;
	phalcon_di_ce->serialize     = zend_class_serialize_deny;
	phalcon_di_ce->unserialize   = zend_class_unserialize_deny;

	phalcon_di_object_handlers = *zend_get_std_object_handlers();
	phalcon_di_object_handlers.read_dimension  = phalcon_di_read_dimension;
	phalcon_di_object_handlers.has_dimension   = phalcon_di_has_dimension;
	phalcon_di_object_handlers.write_dimension = phalcon_di_write_dimension;
	phalcon_di_object_handlers.unset_dimension = phalcon_di_unset_dimension;
	phalcon_di_object_handlers.get_method      = phalcon_di_get_method;
	phalcon_di_object_handlers.call_method     = (zend_object_call_method_t)phalcon_di_call_method;
	phalcon_di_object_handlers.clone_obj       = phalcon_di_clone_obj;

	if (!nusphere_dbg_present) {
		phalcon_di_object_handlers.get_properties = phalcon_di_get_properties;
	}

	return SUCCESS;
}

/**
 * Phalcon\DI constructor
 *
 */
PHP_METHOD(Phalcon_DI, __construct){

	zval *default_di;

	default_di = phalcon_fetch_static_property_ce(phalcon_di_ce, SL("_default") TSRMLS_CC);
	if (Z_TYPE_P(default_di) == IS_NULL) {
		phalcon_update_static_property_ce(phalcon_di_ce, SL("_default"), this_ptr TSRMLS_CC);
	}
}

/**
 * Registers a service in the services container
 *
 * @param string $name
 * @param mixed $definition
 * @param boolean $shared
 * @return Phalcon\DI\ServiceInterface
 */
PHP_METHOD(Phalcon_DI, set) {

	zval **name, **definition, **shared = NULL, *service;
	phalcon_di_object *obj;

	phalcon_fetch_params_ex(2, 1, &name, &definition, &shared);
	PHALCON_ENSURE_IS_STRING(name);
	
	if (!shared) {
		shared = &PHALCON_GLOBAL(z_false);
	}

	MAKE_STD_ZVAL(service);
	object_init_ex(service, phalcon_di_service_ce);
	/* Won't throw exceptions */
	PHALCON_CALL_METHODW(NULL, service, "__construct", *name, *definition, *shared);

	obj = phalcon_di_get_object(getThis() TSRMLS_CC);

	zend_hash_update(obj->services, Z_STRVAL_PP(name), Z_STRLEN_PP(name)+1, &service, sizeof(zval*), NULL);
	RETURN_ZVAL(service, 1, 0);
}

/**
 * Registers an "always shared" service in the services container
 *
 * @param string $name
 * @param mixed $definition
 * @return Phalcon\DI\ServiceInterface
 */
PHP_METHOD(Phalcon_DI, setShared){

	zval **name, **definition, *retval;
	phalcon_di_object *obj;

	phalcon_fetch_params_ex(2, 0, &name, &definition);
	PHALCON_ENSURE_IS_STRING(name);

	obj    = phalcon_di_get_object(getThis() TSRMLS_CC);
	retval = phalcon_di_write_dimension_internal(obj, *name, *definition TSRMLS_CC);
	RETURN_ZVAL(retval, 1, 0);
}

/**
 * Removes a service in the services container
 *
 * @param string $name
 */
PHP_METHOD(Phalcon_DI, remove){

	zval **name;
	phalcon_di_object *obj;

	phalcon_fetch_params_ex(1, 0, &name);
	PHALCON_ENSURE_IS_STRING(name);
	
	obj = phalcon_di_get_object(getThis() TSRMLS_CC);
	phalcon_di_unset_dimension_internal(obj, *name);
}

/**
 * Attempts to register a service in the services container
 * Only is successful if a service hasn't been registered previously
 * with the same name
 *
 * @param string $name
 * @param mixed $definition
 * @param boolean $shared
 * @return Phalcon\DI\ServiceInterface
 */
PHP_METHOD(Phalcon_DI, attempt){

	zval **name, **definition, **shared = NULL;
	phalcon_di_object *obj;

	phalcon_fetch_params_ex(2, 1, &name, &definition, &shared);
	PHALCON_ENSURE_IS_STRING(name);
	
	obj = phalcon_di_get_object(getThis() TSRMLS_CC);
	if (!zend_symtable_exists(obj->services, Z_STRVAL_PP(name), Z_STRLEN_PP(name)+1)) {
		PHALCON_MM_GROW();

		if (!shared) {
			shared = &PHALCON_GLOBAL(z_false);
		}

		object_init_ex(return_value, phalcon_di_service_ce);
		PHALCON_CALL_METHOD(NULL, return_value, "__construct", *name, *definition, *shared);
	
		Z_ADDREF_P(return_value);
		zend_hash_update(obj->services, Z_STRVAL_PP(name), Z_STRLEN_PP(name)+1, &return_value, sizeof(zval*), NULL);

		PHALCON_MM_RESTORE();
	}
}

/**
 * Sets a service using a raw Phalcon\DI\Service definition
 *
 * @param string|Phalcon\DI\ServiceInterface $raw_definition_or_name
 * @param Phalcon\DI\ServiceInterface $rawDefinition
 * @return Phalcon\DI\ServiceInterface
 */
PHP_METHOD(Phalcon_DI, setService)
{
	zval **name_or_def, **raw_definition = NULL;
	phalcon_di_object *obj;

	phalcon_fetch_params_ex(1, 1, &name_or_def, &raw_definition);

	obj = phalcon_di_get_object(getThis() TSRMLS_CC);

	if (raw_definition != NULL) {
		zval *name = NULL;
		raw_definition = name_or_def;
		PHALCON_VERIFY_INTERFACE_EX(*raw_definition, phalcon_di_serviceinterface_ce, phalcon_di_exception_ce, 0);

		PHALCON_CALL_METHODW(&name, *raw_definition, "getname");

		Z_ADDREF_PP(raw_definition);
		zend_hash_update(obj->services, Z_STRVAL_P(name), Z_STRLEN_P(name)+1, (void*)raw_definition, sizeof(zval*), NULL);
		zval_ptr_dtor(&name);
	}
	else {
		zval **name = name_or_def;
		PHALCON_ENSURE_IS_STRING(name);
		PHALCON_VERIFY_INTERFACE_EX(*raw_definition, phalcon_di_serviceinterface_ce, phalcon_di_exception_ce, 0);

		Z_ADDREF_PP(raw_definition);
		zend_hash_update(obj->services, Z_STRVAL_PP(name), Z_STRLEN_PP(name)+1, (void*)raw_definition, sizeof(zval*), NULL);
	}

	RETURN_ZVAL(*raw_definition, 1, 0);
}

/**
 * Returns a service definition without resolving
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Phalcon_DI, getRaw){

	zval **name, **service;
	phalcon_di_object *obj;

	phalcon_fetch_params_ex(1, 0, &name);
	PHALCON_ENSURE_IS_STRING(name);

	obj = phalcon_di_get_object(getThis() TSRMLS_CC);
	if (SUCCESS == zend_symtable_find(obj->services, Z_STRVAL_PP(name), Z_STRLEN_PP(name)+1, (void**)&service)) {
		PHALCON_RETURN_CALL_METHODW(*service, "getdefinition");
		return;
	}

	zend_throw_exception_ex(phalcon_di_exception_ce, 0 TSRMLS_CC, "Service '%s' was not found in the dependency injection container", Z_STRVAL_PP(name));
}

/**
 * Returns a Phalcon\DI\Service instance
 *
 * @param string $name
 * @return Phalcon\DI\ServiceInterface
 */
PHP_METHOD(Phalcon_DI, getService){

	zval **name, **service;
	phalcon_di_object *obj;

	phalcon_fetch_params_ex(1, 0, &name);
	PHALCON_ENSURE_IS_STRING(name);
	
	obj = phalcon_di_get_object(getThis() TSRMLS_CC);
	if (SUCCESS == zend_symtable_find(obj->services, Z_STRVAL_PP(name), Z_STRLEN_PP(name)+1, (void**)&service)) {
		RETURN_ZVAL(*service, 1, 0);
	}

	zend_throw_exception_ex(phalcon_di_exception_ce, 0 TSRMLS_CC, "Service '%s' was not found in the dependency injection container", Z_STRVAL_PP(name));
}

/**
 * Resolves the service based on its configuration
 *
 * @param string $name
 * @param array $parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_DI, get){

	zval **name, **parameters = NULL, **service;
	phalcon_di_object *obj;
	zend_class_entry *ce;

	phalcon_fetch_params_ex(1, 1, &name, &parameters);
	PHALCON_ENSURE_IS_STRING(name);
	
	if (!parameters) {
		parameters = &PHALCON_GLOBAL(z_null);
	}

	obj = phalcon_di_get_object(getThis() TSRMLS_CC);
	if (SUCCESS == zend_symtable_find(obj->services, Z_STRVAL_PP(name), Z_STRLEN_PP(name)+1, (void**)&service)) {
		/* The service is registered in the DI */
		PHALCON_RETURN_CALL_METHODW(*service, "resolve", *parameters, this_ptr);

		if (return_value_ptr) {
			return_value = *return_value_ptr;
		}

		ce = (Z_TYPE_P(return_value) == IS_OBJECT) ? Z_OBJCE_P(return_value) : NULL;
	}
	else {
		/* The DI also acts as builder for any class even if it isn't defined in the DI */
		if (phalcon_class_exists_ex(&ce, *name, 1 TSRMLS_CC)) {
			if (FAILURE == phalcon_create_instance_params_ce(return_value, ce, *parameters TSRMLS_CC)) {
				return;
			}
		}
		else {
			zend_throw_exception_ex(phalcon_di_exception_ce, 0 TSRMLS_CC, "Service '%s' was not found in the dependency injection container", Z_STRVAL_PP(name));
			return;
		}
	}

	/* Pass the DI itself if the instance implements Phalcon\DI\InjectionAwareInterface */
	if (ce && instanceof_function_ex(ce, phalcon_di_injectionawareinterface_ce, 1 TSRMLS_CC)) {
		PHALCON_CALL_METHODW(NULL, return_value, "setdi", this_ptr);
	}
}

/**
 * Resolves a service, the resolved service is stored in the DI, subsequent requests for this service will return the same instance
 *
 * @param string $name
 * @param array $parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_DI, getShared){

	zval **name, **parameters = NULL;
	zval *retval;
	phalcon_di_object *obj;

	phalcon_fetch_params_ex(1, 1, &name, &parameters);
	PHALCON_ENSURE_IS_STRING(name);
	if (!parameters) {
		parameters = &PHALCON_GLOBAL(z_null);
	}

	obj = phalcon_di_get_object(getThis() TSRMLS_CC);
	
	retval = phalcon_di_read_dimension_internal(getThis(), obj, *name, *parameters TSRMLS_CC);
	if (retval) {
		RETURN_ZVAL(retval, 1, 0);
	}

	RETURN_NULL();
}

/**
 * Check whether the DI contains a service by a name
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_DI, has){

	zval **name;
	phalcon_di_object *obj;

	phalcon_fetch_params_ex(1, 0, &name);
	PHALCON_ENSURE_IS_STRING(name);
	
	obj = phalcon_di_get_object(getThis() TSRMLS_CC);
	RETURN_BOOL(zend_symtable_exists(obj->services, Z_STRVAL_PP(name), Z_STRLEN_PP(name)+1));
}

/**
 * Check whether the last service obtained via getShared produced a fresh instance or an existing one
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_DI, wasFreshInstance){

	phalcon_di_object *obj = phalcon_di_get_object(getThis() TSRMLS_CC);

	RETURN_BOOL(obj->fresh);
}

/**
 * Return the services registered in the DI
 *
 * @return Phalcon\DI\Service[]
 */
PHP_METHOD(Phalcon_DI, getServices){

	phalcon_di_object *obj = phalcon_di_get_object(getThis() TSRMLS_CC);

	array_init_size(return_value, zend_hash_num_elements(obj->services));
	zend_hash_copy(Z_ARRVAL_P(return_value), obj->services, (copy_ctor_func_t)zval_add_ref, NULL, sizeof(zval*));
}

/**
 * Check if a service is registered using the array syntax.
 * Alias for Phalcon\Di::has()
 *
 * @param string $name
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_DI, offsetExists);

/**
 * Allows to register a shared service using the array syntax.
 * Alias for Phalcon\Di::setShared()
 *
 *<code>
 *	$di['request'] = new Phalcon\Http\Request();
 *</code>
 *
 * @param string $name
 * @param mixed $definition
 */
PHALCON_DOC_METHOD(Phalcon_DI, offsetSet);

/**
 * Allows to obtain a shared service using the array syntax.
 * Alias for Phalcon\Di::getShared()
 *
 *<code>
 *	var_dump($di['request']);
 *</code>
 *
 * @param string $name
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_DI, offsetGet);

/**
 * Removes a service from the services container using the array syntax.
 * Alias for Phalcon\Di::remove()
 *
 * @param string $name
 */
PHALCON_DOC_METHOD(Phalcon_DI, offsetUnset);

/**
 * Magic method to get or set services using setters/getters
 *
 * @param string $method
 * @param array $arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_DI, __call){

	zval **method, **arguments = NULL;

	phalcon_fetch_params_ex(1, 1, &method, &arguments);
	PHALCON_ENSURE_IS_STRING(method);

	if (!arguments) {
		arguments = &PHALCON_GLOBAL(z_null);
	}
	
	phalcon_di_call_method_internal(return_value, return_value_ptr, getThis(), Z_STRVAL_PP(method), *arguments TSRMLS_CC);
}

/**
 * Set a default dependency injection container to be obtained into static methods
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_DI, setDefault){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	
	phalcon_update_static_property_ce(phalcon_di_ce, SL("_default"), dependency_injector TSRMLS_CC);
	
}

/**
 * Return the lastest DI created
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_DI, getDefault){

	zval *default_di;

	default_di = phalcon_fetch_static_property_ce(phalcon_di_ce, SL("_default") TSRMLS_CC);
	RETURN_CTORW(default_di);
}

/**
 * Resets the internal default DI
 */
PHP_METHOD(Phalcon_DI, reset){

	zend_update_static_property_null(phalcon_di_ce, SL("_default") TSRMLS_CC);
}

PHP_METHOD(Phalcon_DI, __clone) {
}
