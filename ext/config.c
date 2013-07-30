
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"

/**
 * Phalcon\Config
 *
 * Phalcon\Config is designed to simplify the access to, and the use of, configuration data within applications.
 * It provides a nested object property based user interface for accessing this configuration data within
 * application code.
 *
 *<code>
 *	$config = new Phalcon\Config(array(
 *		"database" => array(
 *			"adapter" => "Mysql",
 *			"host" => "localhost",
 *			"username" => "scott",
 *			"password" => "cheetah",
 *			"dbname" => "test_db"
 *		),
 *		"phalcon" => array(
 *			"controllersDir" => "../app/controllers/",
 *			"modelsDir" => "../app/models/",
 *			"viewsDir" => "../app/views/"
 *		)
 * ));
 *</code>
 *
 */

static zend_object_handlers phalcon_config_object_handlers;

typedef struct _phalcon_config_object {
	zend_object obj;  /**< Zend object data */
	HashTable* props; /**< Properties */
} phalcon_config_object;

/**
 * @brief Fetches @c phalcon_config_object
 * @see phalcon_config_object
 * @param zobj @c \Phalcon\Config instance
 * @return phalcon_config_object associated with @a zobj
 * @pre <tt>Z_TYPE_P(zobj) == IS_OBJECT && instanceof_function(Z_OBJCE_P(zobj), phalcon_config_ce TSRMLS_CC)</tt>
 */
static inline phalcon_config_object* fetchPhalconConfigObject(zval* zobj TSRMLS_DC)
{
#ifndef PHALCON_RELEASE
	assert(Z_TYPE_P(zobj) == IS_OBJECT && instanceof_function(Z_OBJCE_P(zobj), phalcon_config_ce TSRMLS_CC));
#endif

	return (phalcon_config_object*)zend_objects_get_address(zobj TSRMLS_CC);
}

/**
 * @brief Counts the number of elements in the configuration; this is the part of Countable interface
 */
static int phalcon_config_count_elements(zval *object, long int *count TSRMLS_DC)
{
	phalcon_config_object* obj = fetchPhalconConfigObject(object TSRMLS_CC);
	*count = zend_hash_num_elements(obj->props);
	return SUCCESS;
}

/**
 * @brief Common part of @c __get() and @c offsetGet()
 */
static zval* phalcon_config_read_internal(phalcon_config_object *object, zval *key, int type TSRMLS_DC)
{
	zval **retval;
	if (UNEXPECTED(!key)) {
		return EG(uninitialized_zval_ptr);
	}

	retval = phalcon_hash_get(object->props, key, type);
	return retval ? *retval : NULL;
}

/**
 * @brief @c read_property handler, used instead of @c __get() magic method
 */
static zval* phalcon_config_read_property(zval *object, zval *offset, int type ZLK_DC TSRMLS_DC)
{
	phalcon_config_object *obj = fetchPhalconConfigObject(object TSRMLS_CC);

	if (obj->obj.ce->type != ZEND_INTERNAL_CLASS) {
		return zend_get_std_object_handlers()->read_property(object, offset, type ZLK_CC TSRMLS_CC);
	}

	return phalcon_config_read_internal(obj, offset, type TSRMLS_CC);
}

/**
 * @brief @c read_dimension handler, used instead of @c offsetGet() method
 */
static zval* phalcon_config_read_dimension(zval *object, zval *offset, int type TSRMLS_DC)
{
	phalcon_config_object *obj = fetchPhalconConfigObject(object TSRMLS_CC);

	if (obj->obj.ce->type != ZEND_INTERNAL_CLASS) {
		return zend_get_std_object_handlers()->read_dimension(object, offset, type TSRMLS_CC);
	}

	return phalcon_config_read_internal(obj, offset, type TSRMLS_CC);
}

/**
 * @brief Common part of @c __set() and @c offsetSet()
 */
static void phalcon_config_write_internal(phalcon_config_object *object, zval *offset, zval *value TSRMLS_DC)
{
	if (Z_TYPE_P(value) == IS_ARRAY) {
		zval *instance;
		ALLOC_INIT_ZVAL(instance);
		object_init_ex(instance, phalcon_config_ce);
		phalcon_config_construct_internal(instance, value TSRMLS_CC);
		phalcon_hash_update_or_insert(object->props, offset, instance);
	}
	else {
		Z_ADDREF_P(value);
		phalcon_hash_update_or_insert(object->props, offset, value);
	}
}

/**
 * @brief @c write_property handler, used instead of @c __set() magic method
 */
static void phalcon_config_write_property(zval *object, zval *offset, zval *value ZLK_DC TSRMLS_DC)
{
	phalcon_config_object *obj = fetchPhalconConfigObject(object TSRMLS_CC);

	if (obj->obj.ce->type != ZEND_INTERNAL_CLASS) {
		zend_get_std_object_handlers()->write_property(object, offset, value ZLK_CC TSRMLS_CC);
	}

	phalcon_config_write_internal(obj, offset, value TSRMLS_CC);
}

/**
 * @brief @c write_dimension handler, used instead of @c offsetSet() method
 */
static void phalcon_config_write_dimension(zval *object, zval *offset, zval *value TSRMLS_DC)
{
	phalcon_config_object *obj = fetchPhalconConfigObject(object TSRMLS_CC);

	if (obj->obj.ce->type != ZEND_INTERNAL_CLASS) {
		zend_get_std_object_handlers()->write_dimension(object, offset, value TSRMLS_CC);
	}

	phalcon_config_write_internal(obj, offset, value TSRMLS_CC);
}

/**
 * @brief Common part of @c __isset() and @c offsetExists()
 */
static int phalcon_config_has_internal(phalcon_config_object *object, zval *key, int check_empty TSRMLS_DC)
{
	zval **tmp = phalcon_hash_get(object->props, key, BP_VAR_NA);

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

static int phalcon_config_has_property(zval *object, zval *offset, int has_set_exists ZLK_DC TSRMLS_DC)
{
	phalcon_config_object *obj = fetchPhalconConfigObject(object TSRMLS_CC);

	if (obj->obj.ce->type != ZEND_INTERNAL_CLASS) {
		return zend_get_std_object_handlers()->has_property(object, offset, has_set_exists ZLK_CC TSRMLS_CC);
	}

	return phalcon_config_has_internal(obj, offset, 2 TSRMLS_CC);
}

static int phalcon_config_has_dimension(zval *object, zval *offset, int check_empty TSRMLS_DC)
{
	phalcon_config_object *obj = fetchPhalconConfigObject(object TSRMLS_CC);

	if (obj->obj.ce->type != ZEND_INTERNAL_CLASS) {
		return zend_get_std_object_handlers()->has_dimension(object, offset, check_empty TSRMLS_CC);
	}

	return phalcon_config_has_internal(obj, offset, check_empty TSRMLS_CC);
}

/**
 * @brief Common part of @c __unset() and @c offsetUnset()
 */
static void phalcon_config_unset_internal(phalcon_config_object *obj, zval *key TSRMLS_DC)
{
	phalcon_hash_unset(obj->props, key);
}

static void phalcon_config_unset_property(zval *object, zval *member ZLK_DC TSRMLS_DC)
{
	phalcon_config_object *obj = fetchPhalconConfigObject(object TSRMLS_CC);

	if (obj->obj.ce->type != ZEND_INTERNAL_CLASS) {
		zend_get_std_object_handlers()->unset_property(object, member ZLK_CC TSRMLS_CC);
	}

	phalcon_config_unset_internal(obj, member TSRMLS_CC);
}

static void phalcon_config_unset_dimension(zval *object, zval *offset TSRMLS_DC)
{
	phalcon_config_object *obj = fetchPhalconConfigObject(object TSRMLS_CC);

	if (obj->obj.ce->type != ZEND_INTERNAL_CLASS) {
		zend_get_std_object_handlers()->unset_dimension(object, offset TSRMLS_CC);
	}

	phalcon_config_unset_internal(obj, offset TSRMLS_CC);
}

/**
 * @brief Returns the list of all internal properties. Used by @c print_r() and other functions
 */
static HashTable* phalcon_config_get_properties(zval* object TSRMLS_DC)
{
	HashTable* props = zend_std_get_properties(object TSRMLS_CC);

	if (!GC_G(gc_active)) {
		phalcon_config_object* obj = fetchPhalconConfigObject(object TSRMLS_CC);
		zval *tmp;

		zend_hash_copy(props, obj->props, (copy_ctor_func_t)zval_add_ref, (void*)&tmp, sizeof(zval*));
	}

	return props;
}

/**
 * @brief Fast object compare function
 */
static int phalcon_config_compare_objects(zval *object1, zval *object2 TSRMLS_DC)
{
	phalcon_config_object *zobj1, *zobj2;
	zval result;

	zobj1 = fetchPhalconConfigObject(object1 TSRMLS_CC);
	zobj2 = fetchPhalconConfigObject(object2 TSRMLS_CC);

	if (zobj1->obj.ce != zobj2->obj.ce) {
		return 1;
	}

	if (zobj1->props == zobj2->props) {
		return 0;
	}

	zend_compare_symbol_tables(&result, zobj1->props, zobj2->props TSRMLS_CC);
	assert(Z_TYPE_P(&result) == IS_LONG);
	return Z_LVAL_P(&result);
}

/**
 * @brief Frees all memory associated with @c phalcon_config_object
 */
static void phalcon_config_object_dtor(void* v TSRMLS_DC)
{
	phalcon_config_object* obj = v;

	if (obj->props) {
		zend_hash_destroy(obj->props);
		FREE_HASHTABLE(obj->props);
	}

	zend_object_std_dtor(&(obj->obj) TSRMLS_CC);
	efree(obj);
}

/**
 * @brief Constructs @c phalcon_config_object
 */
static zend_object_value phalcon_config_object_ctor(zend_class_entry* ce TSRMLS_DC)
{
	phalcon_config_object* obj = ecalloc(1, sizeof(phalcon_config_object));
	zend_object_value retval;

	zend_object_std_init(&(obj->obj), ce TSRMLS_CC);
	retval.handle = zend_objects_store_put(
		obj,
		(zend_objects_store_dtor_t)zend_objects_destroy_object,
		phalcon_config_object_dtor,
		NULL TSRMLS_CC
	);

	retval.handlers = &phalcon_config_object_handlers;

	return retval;
}

/**
 * Phalcon\Config initializer
 */
PHALCON_INIT_CLASS(Phalcon_Config){

	PHALCON_REGISTER_CLASS(Phalcon, Config, config, phalcon_config_method_entry, 0);

	phalcon_config_ce->create_object = phalcon_config_object_ctor;

	phalcon_config_object_handlers = *zend_get_std_object_handlers();
	phalcon_config_object_handlers.count_elements  = phalcon_config_count_elements;
	phalcon_config_object_handlers.read_property   = phalcon_config_read_property;
	phalcon_config_object_handlers.write_property  = phalcon_config_write_property;
	phalcon_config_object_handlers.unset_property  = phalcon_config_unset_property;
	phalcon_config_object_handlers.has_property    = phalcon_config_has_property;
	phalcon_config_object_handlers.read_dimension  = phalcon_config_read_dimension;
	phalcon_config_object_handlers.write_dimension = phalcon_config_write_dimension;
	phalcon_config_object_handlers.unset_dimension = phalcon_config_unset_dimension;
	phalcon_config_object_handlers.has_dimension   = phalcon_config_has_dimension;
	phalcon_config_object_handlers.get_properties  = phalcon_config_get_properties;
	phalcon_config_object_handlers.compare_objects = phalcon_config_compare_objects;

	zend_class_implements(phalcon_config_ce TSRMLS_CC, 2, zend_ce_arrayaccess, spl_ce_Countable);

	return SUCCESS;
}

/**
 * Internal implementation of __construct(). Used to avoid calls to userspace when
 * recursively walking the configuration array. Does not use MM.
 */
void phalcon_config_construct_internal(zval* this_ptr, zval *array_config TSRMLS_DC)
{
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	phalcon_config_object* obj;

	if (!array_config || Z_TYPE_P(array_config) == IS_NULL) {
		obj = fetchPhalconConfigObject(getThis() TSRMLS_CC);
		ALLOC_HASHTABLE(obj->props);
		zend_hash_init(obj->props, 0, NULL, ZVAL_PTR_DTOR, 0);
		return;
	}

	phalcon_is_iterable(array_config, &ah0, &hp0, 0, 0);

	obj = fetchPhalconConfigObject(getThis() TSRMLS_CC);
	ALLOC_HASHTABLE(obj->props);
	zend_hash_init(obj->props, zend_hash_num_elements(Z_ARRVAL_P(array_config)), NULL, ZVAL_PTR_DTOR, 0);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

		zval key = phalcon_get_current_key_w(ah0, &hp0);
		phalcon_config_write_internal(obj, &key, *hd TSRMLS_CC);

		zend_hash_move_forward_ex(ah0, &hp0);
	}
}

/**
 * Internal implementation of non-recursive @c toArray(). Used as an alternative
 * to @c get_object_properties().
 */
static void phalcon_config_toarray_internal(zval *return_value, zval *this_ptr TSRMLS_DC)
{
	phalcon_config_object *obj = fetchPhalconConfigObject(this_ptr TSRMLS_CC);

	if (likely(obj->obj.ce == phalcon_config_ce)) {
		zval *tmp;
		array_init_size(return_value, zend_hash_num_elements(obj->props));
		zend_hash_copy(Z_ARRVAL_P(return_value), obj->props, (copy_ctor_func_t)zval_add_ref, (void*)&tmp, sizeof(zval*));
	}
	else if (phalcon_method_exists_ex(this_ptr, SS("toarray") TSRMLS_CC) == SUCCESS) {
		phalcon_call_method_params(return_value, this_ptr, SL("toarray"), zend_inline_hash_func(SS("toarray")) TSRMLS_CC, 0);
	}
	else {
		phalcon_call_func_params(return_value, SL("get_object_vars") TSRMLS_CC, 1, this_ptr);
	}
}

/**
 * Phalcon\Config constructor
 *
 * @param array $arrayConfig
 */
PHP_METHOD(Phalcon_Config, __construct){

	zval *array_config = NULL;

	phalcon_fetch_params(0, 0, 1, &array_config);
	
	/** 
	 * Throw exceptions if bad parameters are passed
	 */
	if (array_config && Z_TYPE_P(array_config) != IS_ARRAY && Z_TYPE_P(array_config) != IS_NULL) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_config_exception_ce, "The configuration must be an Array");
		return;
	}

	phalcon_config_construct_internal(getThis(), array_config TSRMLS_CC);
}

/**
 * Allows to check whether an attribute is defined using the array-syntax
 *
 *<code>
 * var_dump(isset($config['database']));
 *</code>
 *
 * @param string $index
 * @return boolean
 */
PHP_METHOD(Phalcon_Config, offsetExists){

	zval *index;

	phalcon_fetch_params(0, 1, 0, &index);
	RETURN_BOOL(phalcon_config_has_internal(fetchPhalconConfigObject(getThis() TSRMLS_CC), index, 0 TSRMLS_CC));
}

/**
 * Gets an attribute from the configuration, if the attribute isn't defined returns null
 * If the value is exactly null or is not defined the default value will be used instead
 *
 *<code>
 * echo $config->get('controllersDir', '../app/controllers/');
 *</code>
 *
 * @param string $index
 * @param mixed $defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Config, get){

	zval *index, *default_value = NULL, *value;

	phalcon_fetch_params(0, 1, 1, &index, &default_value);

	value = phalcon_config_read_internal(fetchPhalconConfigObject(getThis() TSRMLS_CC), index, BP_VAR_NA TSRMLS_CC);
	if (!value || Z_TYPE_P(value) == IS_NULL) {
		if (default_value) {
			RETURN_ZVAL(default_value, 1, 0);
		}

		RETURN_NULL();
	}

	RETURN_ZVAL(value, 1, 0);
}

/**
 * Gets an attribute using the array-syntax
 *
 *<code>
 * print_r($config['database']);
 *</code>
 *
 * @param string $index
 * @return string
 */
PHP_METHOD(Phalcon_Config, offsetGet){

	zval *index;
	zval* retval;

	phalcon_fetch_params(0, 1, 0, &index);

	retval = phalcon_config_read_internal(fetchPhalconConfigObject(getThis() TSRMLS_CC), index, BP_VAR_R TSRMLS_CC);
	RETURN_ZVAL(retval, 1, 0);
}

/**
 * Sets an attribute using the array-syntax
 *
 *<code>
 * $config['database'] = array('type' => 'Sqlite');
 *</code>
 *
 * @param string $index
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Config, offsetSet){

	zval *index, *value;

	phalcon_fetch_params(0, 2, 0, &index, &value);
	phalcon_config_write_internal(fetchPhalconConfigObject(getThis() TSRMLS_CC), index, value TSRMLS_CC);
}

/**
 * Unsets an attribute using the array-syntax
 *
 *<code>
 * unset($config['database']);
 *</code>
 *
 * @param string $index
 */
PHP_METHOD(Phalcon_Config, offsetUnset){

	zval *index;

	phalcon_fetch_params(0, 1, 0, &index);
	phalcon_config_unset_internal(fetchPhalconConfigObject(getThis() TSRMLS_CC), index TSRMLS_CC);
}

/**
 * Merges a configuration into the current one
 *
 *<code>
 *	$appConfig = new Phalcon\Config(array('database' => array('host' => 'localhost')));
 *	$globalConfig->merge($config2);
 *</code>
 *
 * @param Phalcon\Config $config
 */
PHP_METHOD(Phalcon_Config, merge){

	zval *config, *array_config, key, *active_value = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	phalcon_config_object *obj;

	phalcon_fetch_params(0, 1, 0, &config);
	
	if (Z_TYPE_P(config) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_config_exception_ce, "Configuration must be an Object");
		return;
	}

	ALLOC_INIT_ZVAL(array_config);
	phalcon_config_toarray_internal(array_config, config TSRMLS_CC);
	
	phalcon_is_iterable(array_config, &ah0, &hp0, 0, 0);
	
	obj = fetchPhalconConfigObject(getThis() TSRMLS_CC);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		key = phalcon_get_current_key_w(ah0, &hp0);
	
		active_value = phalcon_config_read_internal(obj, &key, BP_VAR_NA TSRMLS_CC);

		/**
		 * The key is already defined in the object, we have to merge it
		 */
		if (active_value) {
			if (Z_TYPE_PP(hd) == IS_OBJECT && Z_TYPE_P(active_value) == IS_OBJECT) {
				if (phalcon_method_exists_ex(active_value, SS("merge") TSRMLS_CC) == SUCCESS) { /* Path AAA in the test */
					Z_ADDREF_PP(hd);
					phalcon_call_method_params(NULL, active_value, SL("merge"), zend_inline_hash_func(SS("merge")) TSRMLS_CC, 1, *hd);
					Z_DELREF_PP(hd);
				}
				else { /* Path AAB in the test */
					phalcon_config_write_internal(obj, &key, *hd TSRMLS_CC);
				}
			}
			else { /* Path AE in the test */
				phalcon_config_write_internal(obj, &key, *hd TSRMLS_CC);
			}
		}
		else { /* Path B in the test */
			/**
			 * The key is not defined in the object, add it
			 */
			phalcon_config_write_internal(obj, &key, *hd TSRMLS_CC);
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	zval_ptr_dtor(&array_config);
}

/**
 * Converts recursively the object to an array
 *
 *<code>
 *	print_r($config->toArray());
 *</code>
 *
 * @return array
 */
PHP_METHOD(Phalcon_Config, toArray){

	zval key, *array_value = NULL, *tmp;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	phalcon_config_object *obj;

	obj = fetchPhalconConfigObject(getThis() TSRMLS_CC);
	array_init_size(return_value, zend_hash_num_elements(obj->props));
	zend_hash_copy(Z_ARRVAL_P(return_value), obj->props, (copy_ctor_func_t)zval_add_ref, (void*)&tmp, sizeof(zval*));

	phalcon_is_iterable(return_value, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		key = phalcon_get_current_key_w(ah0, &hp0);
	
		if (Z_TYPE_PP(hd) == IS_OBJECT && phalcon_method_exists_ex(*hd, SS("toarray") TSRMLS_CC) == SUCCESS) {
			ALLOC_INIT_ZVAL(array_value);
			phalcon_call_method_params(array_value, *hd, SL("toarray"), zend_inline_hash_func(SS("toarray")) TSRMLS_CC, 0);
			phalcon_array_update_zval(&return_value, &key, &array_value, PH_SEPARATE);
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
}

PHP_METHOD(Phalcon_Config, count)
{
	long int cnt;

	phalcon_config_count_elements(getThis(), &cnt TSRMLS_CC);
	RETURN_LONG(cnt);
}

/**
 * Restores the state of a Phalcon\Config object
 *
 * @param array $data
 * @return Phalcon\Config
 */
PHP_METHOD(Phalcon_Config, __set_state){

	zval *data;

	phalcon_fetch_params(0, 1, 0, &data);

	object_init_ex(return_value, phalcon_config_ce);
	phalcon_config_construct_internal(return_value, data TSRMLS_CC);
}
