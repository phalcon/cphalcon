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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#include "registry.h"
#include "internal/arginfo.h"

#include <Zend/zend_interfaces.h>
#include <ext/spl/spl_array.h>
#include <ext/standard/php_var.h>
#include <ext/standard/php_smart_str.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Registry
 *
 * A registry is a container for storing objects and values in the application space.
 * By storing the value in a registry, the same object is always available throughout
 * your application.
 *
 * <code>
 * 	$registry = new \Phalcon\Registry();
 *
 * 	// Set value
 * 	$registry->something = 'something';
 * 	// or
 * 	$registry['something'] = 'something';
 *
 * 	// Get value
 * 	$value = $registry->something;
 * 	// or
 * 	$value = $registry['something'];
 *
 * 	// Check if the key exists
 * 	$exists = isset($registry->something);
 * 	// or
 * 	$exists = isset($registry['something']);
 *
 * 	// Unset
 * 	unset($registry->something);
 * 	// or
 * 	unset($registry['something']);
 * </code>
 *
 * In addition to ArrayAccess, Phalcon\Registry also implements Countable
 * (count($registry) will return the number of elements in the registry),
 * Serializable and IteratorAggregate (you can iterate over the registry
 * using a foreach loop) interfaces. For PHP 5.4 and higher, JsonSerializable
 * interface is implemented.
 *
 * Phalcon\Registry is very fast (it is typically faster than any userspace
 * implementation of the registry); however, this comes at a price:
 * Phalcon\Registry is a final class and cannot be inherited from.
 *
 * Though Phalcon\Registry exposes methods like __get(), offsetGet(), count() etc,
 * it is not recommended to invoke them manually (these method exists mainly to
 * match the interfaces the registry implements): $registry->__get('property')
 * is several times slower than $registry->property.
 *
 * Internally all the magic methods (and interfaces except JsonSerializable)
 * are implemented using object handlers or similar techniques: this allows
 * to bypass relatively slow method calls.
 */
zend_class_entry *phalcon_registry_ce;

static zend_object_handlers phalcon_registry_object_handlers;

typedef struct _phalcon_registry_object {
	zend_object obj;
	zval *properties;
} phalcon_registry_object;

PHALCON_ATTR_NONNULL static inline phalcon_registry_object* phalcon_registry_get_object(zval *obj TSRMLS_DC)
{
	return (phalcon_registry_object*)zend_objects_get_address(obj TSRMLS_CC);
}

static void phalcon_registry_dtor(void *v TSRMLS_DC)
{
	phalcon_registry_object *obj = v;

	zval_ptr_dtor(&obj->properties);
	zend_object_std_dtor(&obj->obj TSRMLS_CC);
	efree(obj);
}

static zend_object_value phalcon_registry_ctor(zend_class_entry* ce TSRMLS_DC)
{
	phalcon_registry_object *obj = ecalloc(1, sizeof(phalcon_registry_object));
	zend_object_value retval;

	zend_object_std_init(&obj->obj, ce TSRMLS_CC);
	object_properties_init(&obj->obj, ce);

	MAKE_STD_ZVAL(obj->properties);
	array_init(obj->properties);

	retval.handle = zend_objects_store_put(
		obj,
		(zend_objects_store_dtor_t)zend_objects_destroy_object,
		phalcon_registry_dtor,
		NULL TSRMLS_CC
	);

	retval.handlers = &phalcon_registry_object_handlers;
	return retval;
}

#if PHP_VERSION_ID < 50500

static zval** phalcon_registry_get_property_ptr_ptr(zval *object, zval *member ZLK_DC TSRMLS_DC)
{
	phalcon_registry_object *obj = phalcon_registry_get_object(object TSRMLS_CC);
	return phalcon_hash_get(Z_ARRVAL_P(obj->properties), member, BP_VAR_W);
}

#else

static zval** phalcon_registry_get_property_ptr_ptr(zval *object, zval *member, int type ZLK_DC TSRMLS_DC)
{
	phalcon_registry_object *obj = phalcon_registry_get_object(object TSRMLS_CC);

	return phalcon_hash_get(Z_ARRVAL_P(obj->properties), member, type);
}

#endif

static zval* phalcon_registry_read_property(zval *object, zval *member, int type ZLK_DC TSRMLS_DC)
{
	zval **result;
	phalcon_registry_object *obj = phalcon_registry_get_object(object TSRMLS_CC);

	result = phalcon_hash_get(Z_ARRVAL_P(obj->properties), member, type);
	return result ? *result : NULL;
}

static void phalcon_registry_write_property(zval *object, zval *member, zval *value ZLK_DC TSRMLS_DC)
{
	phalcon_registry_object *obj = phalcon_registry_get_object(object TSRMLS_CC);

	Z_ADDREF_P(value);
	phalcon_hash_update_or_insert(Z_ARRVAL_P(obj->properties), member, value);
}

static void phalcon_registry_unset_property(zval *object, zval *member ZLK_DC TSRMLS_DC)
{
	phalcon_registry_object *obj = phalcon_registry_get_object(object TSRMLS_CC);
	phalcon_hash_unset(Z_ARRVAL_P(obj->properties), member);
}

static int phalcon_registry_has_property(zval *object, zval *member, int has_set_exists ZLK_DC TSRMLS_DC)
{
	phalcon_registry_object *obj = phalcon_registry_get_object(object TSRMLS_CC);
	zval **tmp = phalcon_hash_get(Z_ARRVAL_P(obj->properties), member, BP_VAR_NA);

	if (!tmp) {
		return 0;
	}

	if (0 == has_set_exists) {
		return Z_TYPE_PP(tmp) != IS_NULL;
	}

	if (1 == has_set_exists) {
		return zend_is_true(*tmp);
	}

	return 1;
}

static zval* phalcon_registry_read_dimension(zval *object, zval *offset, int type TSRMLS_DC)
{
	zval **ret;
	phalcon_registry_object *obj;

	if (UNEXPECTED(!offset)) {
		return EG(uninitialized_zval_ptr);
	}

	obj = phalcon_registry_get_object(object TSRMLS_CC);
	ret = phalcon_hash_get(Z_ARRVAL_P(obj->properties), offset, type);

	/* For write context we need to return a reference */
	if ((type == BP_VAR_W || type == BP_VAR_RW || type == BP_VAR_UNSET) && !Z_ISREF_PP(ret)) {
		if (Z_REFCOUNT_PP(ret) > 1) {
			zval *newval;

			MAKE_STD_ZVAL(newval);
			*newval = **ret;
			zval_copy_ctor(newval);
			Z_SET_REFCOUNT_P(newval, 1);

			Z_DELREF_PP(ret);
			*ret = newval;
		}

		Z_SET_ISREF_PP(ret);
	}

	return *ret;
}

static void phalcon_registry_write_dimension(zval *object, zval *offset, zval *value TSRMLS_DC)
{
	phalcon_registry_write_property(object, offset, value ZLK_NULL_CC TSRMLS_CC);
}

static int phalcon_registry_has_dimension(zval *object, zval *offset, int check_empty TSRMLS_DC)
{
	return phalcon_registry_has_property(object, offset, check_empty ZLK_NULL_CC TSRMLS_CC);
}

static void phalcon_registry_unset_dimension(zval *object, zval *offset TSRMLS_DC)
{
	phalcon_registry_unset_property(object, offset ZLK_NULL_CC TSRMLS_CC);
}

static int phalcon_registry_count_elements(zval *object, long int *count TSRMLS_DC)
{
	phalcon_registry_object *obj = phalcon_registry_get_object(object TSRMLS_CC);
	*count = zend_hash_num_elements(Z_ARRVAL_P(obj->properties));
	return SUCCESS;
}

static HashTable* phalcon_registry_get_properties(zval *object TSRMLS_DC)
{
	phalcon_registry_object *obj = phalcon_registry_get_object(object TSRMLS_CC);
	return Z_ARRVAL_P(obj->properties);
}

static zend_object_iterator* phalcon_registry_get_iterator(zend_class_entry *ce, zval *object, int by_ref TSRMLS_DC)
{
	zval *iterator;
	phalcon_registry_object *obj = phalcon_registry_get_object(object TSRMLS_CC);
	zend_object_iterator *ret;

	MAKE_STD_ZVAL(iterator);
	object_init_ex(iterator, spl_ce_ArrayIterator);
	if (FAILURE == phalcon_call_method_params(NULL, NULL, iterator, SL("__construct"), zend_inline_hash_func(SS("__construct")) TSRMLS_CC, 1, obj->properties)) {
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

static int phalcon_registry_serialize(zval *object, unsigned char **buffer, zend_uint *buf_len, zend_serialize_data *data TSRMLS_DC)
{
	phalcon_registry_object *obj = phalcon_registry_get_object(object TSRMLS_CC);
	smart_str buf = { NULL, 0, 0 };
	php_serialize_data_t var_hash;

	PHP_VAR_SERIALIZE_INIT(var_hash);
	php_var_serialize(&buf, &obj->properties, &var_hash TSRMLS_CC);
	PHP_VAR_SERIALIZE_DESTROY(var_hash);

	if (buf.c) {
		*buffer  = (unsigned char*)buf.c;
		*buf_len = buf.len;
		return SUCCESS;
	}

	return FAILURE;
}

static int phalcon_registry_unserialize(zval **object, zend_class_entry *ce, const unsigned char *buf, zend_uint buf_len, zend_unserialize_data *data TSRMLS_DC)
{
	phalcon_registry_object *obj;
	php_unserialize_data_t var_hash;
	zval zv = zval_used_for_init, *pzv = &zv;
	const unsigned char *max;
	int retval;

	object_init_ex(*object, ce);
	obj = phalcon_registry_get_object(*object TSRMLS_CC);

	max = buf + buf_len;

	PHP_VAR_UNSERIALIZE_INIT(var_hash);
	retval = (php_var_unserialize(&pzv, &buf, max, &var_hash TSRMLS_CC) && Z_TYPE(zv) == IS_ARRAY) ? SUCCESS : FAILURE;
	if (SUCCESS == retval) {
		if (zend_hash_num_elements(Z_ARRVAL(zv)) != 0) {
			zend_hash_copy(Z_ARRVAL_P(obj->properties), Z_ARRVAL(zv), (copy_ctor_func_t)zval_add_ref, NULL, sizeof(zval*));
		}
	}
	else {
		zend_throw_exception_ex(spl_ce_BadMethodCallException, 0 TSRMLS_CC, "Bad parameters passed to Phalcon\\Registry::unserialize()");
	}

	zval_dtor(pzv);
	PHP_VAR_UNSERIALIZE_DESTROY(var_hash);

	return retval;
}

static PHP_METHOD(Phalcon_Registry, __get)
{
	zval **property, **result;
	phalcon_registry_object *obj;

	assert(return_value_ptr != NULL);

	phalcon_fetch_params_ex(1, 0, &property);

	obj    = phalcon_registry_get_object(getThis() TSRMLS_CC);
	result = phalcon_hash_get(Z_ARRVAL_P(obj->properties), *property, BP_VAR_W);

	zval_ptr_dtor(return_value_ptr);
	*return_value_ptr = *result;
	Z_ADDREF_PP(return_value_ptr);
	Z_SET_ISREF_PP(return_value_ptr);
}

static PHP_METHOD(Phalcon_Registry, __set)
{
	zval **property, **value;

	phalcon_fetch_params_ex(2, 0, &property, &value);
	phalcon_registry_write_property(getThis(), *property, *value ZLK_NULL_CC TSRMLS_CC);
}

static PHP_METHOD(Phalcon_Registry, __isset)
{
	zval **property;

	phalcon_fetch_params_ex(1, 0, &property);
	phalcon_registry_has_property(getThis(), *property, 0 ZLK_NULL_CC TSRMLS_CC);
}

static PHP_METHOD(Phalcon_Registry, __unset)
{
	zval **property;

	phalcon_fetch_params_ex(1, 0, &property);
	phalcon_registry_unset_property(getThis(), *property ZLK_NULL_CC TSRMLS_CC);
}

static PHP_METHOD(Phalcon_Registry, count)
{
	long int result;

	phalcon_registry_count_elements(getThis(), &result TSRMLS_CC);
	RETURN_LONG(result);
}

static PHP_METHOD(Phalcon_Registry, offsetGet)
{
	if (return_value_ptr) {
		ZEND_MN(Phalcon_Registry___get)(INTERNAL_FUNCTION_PARAM_PASSTHRU);
	}
	else {
		zval **offset, **result;
		phalcon_registry_object *obj;

		phalcon_fetch_params_ex(1, 0, &offset);

		obj    = phalcon_registry_get_object(getThis() TSRMLS_CC);
		result = phalcon_hash_get(Z_ARRVAL_P(obj->properties), *offset, BP_VAR_R);

		RETURN_ZVAL(*result, 1, 0);
	}
}

static PHP_METHOD(Phalcon_Registry, offsetSet)
{
	zval **offset, **value;

	phalcon_fetch_params_ex(2, 0, &offset, &value);
	phalcon_registry_write_dimension(getThis(), *offset, *value TSRMLS_CC);
}

static PHP_METHOD(Phalcon_Registry, offsetUnset)
{
	zval **offset;

	phalcon_fetch_params_ex(1, 0, &offset);
	phalcon_registry_unset_dimension(getThis(), *offset TSRMLS_CC);
}

static PHP_METHOD(Phalcon_Registry, offsetExists)
{
	zval **offset;

	phalcon_fetch_params_ex(1, 0, &offset);
	phalcon_registry_has_dimension(getThis(), *offset, 0 TSRMLS_CC);
}

static PHP_METHOD(Phalcon_Registry, getIterator)
{
	phalcon_registry_object *obj = phalcon_registry_get_object(getThis() TSRMLS_CC);

	object_init_ex(return_value, spl_ce_ArrayIterator);
	RETURN_ON_FAILURE(phalcon_call_method_params(NULL, NULL, return_value, SL("__construct"), zend_inline_hash_func(SS("__construct")) TSRMLS_CC, 1, obj->properties));
}

static PHP_METHOD(Phalcon_Registry, jsonSerialize)
{
	phalcon_registry_object *obj = phalcon_registry_get_object(getThis() TSRMLS_CC);
	RETURN_ZVAL(obj->properties, 1, 0);
}

static PHP_METHOD(Phalcon_Registry, serialize)
{
	phalcon_registry_object *obj = phalcon_registry_get_object(getThis() TSRMLS_CC);
	smart_str buf = { NULL, 0, 0 };
	php_serialize_data_t var_hash;

	PHP_VAR_SERIALIZE_INIT(var_hash);
	php_var_serialize(&buf, &obj->properties, &var_hash TSRMLS_CC);
	PHP_VAR_SERIALIZE_DESTROY(var_hash);

	if (buf.c) {
		RETURN_STRINGL(buf.c, buf.len, 0);
	}
}

static PHP_METHOD(Phalcon_Registry, unserialize)
{
	zval **str;
	phalcon_registry_object *obj;
	php_unserialize_data_t var_hash;
	zval zv = zval_used_for_init, *pzv = &zv;
	const unsigned char *buf, *max;

	phalcon_fetch_params_ex(1, 0, &str);
	PHALCON_ENSURE_IS_STRING(str);

	obj = phalcon_registry_get_object(getThis() TSRMLS_CC);

	if (zend_hash_num_elements(Z_ARRVAL_P(obj->properties))) {
		zend_throw_exception_ex(spl_ce_BadMethodCallException, 0 TSRMLS_CC, "Cannot call unserialize() on an already constructed object");
		return;
	}

	buf = (unsigned char*)(Z_STRVAL_PP(str));
	max = buf + Z_STRLEN_PP(str);

	PHP_VAR_UNSERIALIZE_INIT(var_hash);
	if (php_var_unserialize(&pzv, &buf, max, &var_hash TSRMLS_CC) && Z_TYPE(zv) == IS_ARRAY) {
		if (zend_hash_num_elements(Z_ARRVAL(zv)) != 0) {
			zend_hash_copy(Z_ARRVAL_P(obj->properties), Z_ARRVAL(zv), (copy_ctor_func_t) zval_add_ref, NULL, sizeof(zval*));
		}
	}
	else {
		zend_throw_exception_ex(spl_ce_BadMethodCallException, 0 TSRMLS_CC, "Bad parameters passed to Phalcon\\Registry::unserialize()");
	}

	zval_dtor(pzv);
	PHP_VAR_UNSERIALIZE_DESTROY(var_hash);
}

static PHP_METHOD(Phalcon_Registry, __wakeup)
{
}

static const zend_function_entry phalcon_registry_method_entry[] = {
	PHP_ME(Phalcon_Registry, __get, arginfo___getref, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Registry, __set, arginfo___set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Registry, __isset, arginfo___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Registry, __unset, arginfo___unset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Registry, count, arginfo_countable_count, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Registry, offsetGet, arginfo_arrayaccess_offsetgetref, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Registry, offsetSet, arginfo_arrayaccess_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Registry, offsetUnset, arginfo_arrayaccess_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Registry, offsetExists, arginfo_arrayaccess_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Registry, getIterator, arginfo_iteratoraggregate_getiterator, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Registry, jsonSerialize, arginfo_jsonserializable_jsonserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Registry, serialize, arginfo_serializable_serialize, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Registry, unserialize, arginfo_serializable_unserialize, ZEND_ACC_PUBLIC | ZEND_ACC_DTOR)
	PHP_ME(Phalcon_Registry, __wakeup, arginfo_empty, ZEND_ACC_PRIVATE)
	PHP_FE_END
};

PHALCON_INIT_CLASS(Phalcon_Registry)
{
	zend_class_entry **jsonserializable_ce = NULL;

	PHALCON_REGISTER_CLASS(Phalcon, Registry, registry, phalcon_registry_method_entry, ZEND_ACC_FINAL_CLASS);

	phalcon_registry_ce->create_object = phalcon_registry_ctor;
	phalcon_registry_ce->serialize     = phalcon_registry_serialize;
	phalcon_registry_ce->unserialize   = phalcon_registry_unserialize;

	phalcon_registry_object_handlers = *zend_get_std_object_handlers();
	phalcon_registry_object_handlers.get_property_ptr_ptr = phalcon_registry_get_property_ptr_ptr;
	phalcon_registry_object_handlers.read_property        = phalcon_registry_read_property;
	phalcon_registry_object_handlers.write_property       = phalcon_registry_write_property;
	phalcon_registry_object_handlers.unset_property       = phalcon_registry_unset_property;
	phalcon_registry_object_handlers.has_property         = phalcon_registry_has_property;
	phalcon_registry_object_handlers.read_dimension       = phalcon_registry_read_dimension;
	phalcon_registry_object_handlers.has_dimension        = phalcon_registry_has_dimension;
	phalcon_registry_object_handlers.write_dimension      = phalcon_registry_write_dimension;
	phalcon_registry_object_handlers.unset_dimension      = phalcon_registry_unset_dimension;
	phalcon_registry_object_handlers.get_properties       = phalcon_registry_get_properties;
	phalcon_registry_object_handlers.count_elements       = phalcon_registry_count_elements;

	phalcon_registry_ce->get_iterator = phalcon_registry_get_iterator;

	zend_hash_find(CG(class_table), ZEND_STRS("jsonserializable"), (void**)&jsonserializable_ce);

	zend_class_implements(
		phalcon_registry_ce TSRMLS_CC,
		(jsonserializable_ce ? 5 : 4),
		zend_ce_arrayaccess,
		zend_ce_aggregate,
		zend_ce_serializable,
		spl_ce_Countable,
		(jsonserializable_ce ? *jsonserializable_ce : NULL) /* must be the last one */
	);

	return SUCCESS;
}
