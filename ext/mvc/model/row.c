
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
#include "kernel/hash.h"
#include "kernel/object.h"
#include "kernel/exception.h"

/**
 * Phalcon\Mvc\Model\Row
 *
 * This component allows Phalcon\Mvc\Model to return rows without an associated entity.
 * This objects implements the ArrayAccess interface to allow access the object as object->x or array[x].
 */

static zend_object_handlers phalcon_mvc_model_row_object_handlers;

typedef struct _phalcon_mvc_model_row_object {
	zend_object obj;  /**< Zend object data */
	HashTable* props; /**< Properties */
} phalcon_mvc_model_row_object;

/**
 * @brief Fetches @c phalcon_mvc_model_row_object
 * @see phalcon_mvc_model_row_object
 * @param zobj @c \Phalcon\Mvc\Row instance
 * @return phalcon_mvc_model_row_object associated with @a zobj
 */
static inline phalcon_mvc_model_row_object* phalcon_mvc_model_row_get_object(zval* zobj TSRMLS_DC)
{
	return (phalcon_mvc_model_row_object*)zend_objects_get_address(zobj TSRMLS_CC);
}

static int phalcon_mvc_model_row_count_elements(zval *object, long int *count TSRMLS_DC)
{
	phalcon_mvc_model_row_object* obj = phalcon_mvc_model_row_get_object(object TSRMLS_CC);
	*count = zend_hash_num_elements(obj->props);
	return SUCCESS;
}

/**
 * @brief @c read_dimension handler, used instead of @c offsetGet() method
 */
static zval* phalcon_mvc_model_row_read_dimension(zval *object, zval *offset, int type TSRMLS_DC)
{
	phalcon_mvc_model_row_object* obj = phalcon_mvc_model_row_get_object(object TSRMLS_CC);
	zval **ret;

	if (UNEXPECTED(obj->obj.ce->type != ZEND_INTERNAL_CLASS)) {
		return zend_get_std_object_handlers()->read_dimension(object, offset, type TSRMLS_CC);
	}

	if (UNEXPECTED(!offset)) {
		return EG(uninitialized_zval_ptr);
	}

	ret = phalcon_hash_get(obj->props, offset, type);
	if (ret) {
		return *ret;
	}

	zend_throw_exception_ex(phalcon_mvc_model_exception_ce, 0 TSRMLS_CC, "The index does not exist in the row");
	return NULL;
}

/**
 * @brief @c write_dimension handler, used instead of @c offsetSet() method
 */
static void phalcon_mvc_model_row_write_dimension(zval *object, zval *offset, zval *value TSRMLS_DC)
{
	phalcon_mvc_model_row_object* obj = phalcon_mvc_model_row_get_object(object TSRMLS_CC);

	if (UNEXPECTED(obj->obj.ce->type != ZEND_INTERNAL_CLASS)) {
		return zend_get_std_object_handlers()->write_dimension(object, offset, value TSRMLS_CC);
	}

	zend_throw_exception_ex(phalcon_mvc_model_exception_ce, 0 TSRMLS_CC, "Phalcon\\Mvc\\Row is an immutable ArrayAccess object");
}

static int phalcon_mvc_model_row_has_dimension(zval *object, zval *offset, int check_empty TSRMLS_DC)
{
	phalcon_mvc_model_row_object* obj = phalcon_mvc_model_row_get_object(object TSRMLS_CC);
	zval **tmp;

	if (UNEXPECTED(obj->obj.ce->type != ZEND_INTERNAL_CLASS)) {
		return zend_get_std_object_handlers()->has_dimension(object, offset, check_empty TSRMLS_CC);
	}

	tmp = phalcon_hash_get(obj->props, offset, BP_VAR_NA);
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

static void phalcon_mvc_model_row_unset_dimension(zval *object, zval *offset TSRMLS_DC)
{
	phalcon_mvc_model_row_object* obj = phalcon_mvc_model_row_get_object(object TSRMLS_CC);

	if (UNEXPECTED(obj->obj.ce->type != ZEND_INTERNAL_CLASS)) {
		zend_get_std_object_handlers()->unset_dimension(object, offset TSRMLS_CC);
		return;
	}

	zend_throw_exception_ex(phalcon_mvc_model_exception_ce, 0 TSRMLS_CC, "Phalcon\\Mvc\\Row is an immutable ArrayAccess object");
}

/**
 * @brief Returns the list of all internal properties. Used by @c print_r() and other functions
 */
static HashTable* phalcon_mvc_model_row_get_properties(zval* object TSRMLS_DC)
{
	HashTable* props = zend_std_get_properties(object TSRMLS_CC);

	if (!GC_G(gc_active)) {
		phalcon_mvc_model_row_object* obj = phalcon_mvc_model_row_get_object(object TSRMLS_CC);
		zend_hash_copy(props, obj->props, (copy_ctor_func_t)zval_add_ref, NULL, sizeof(zval*));
	}

	return props;
}

/**
 * @brief Fast object compare function
 */
static int phalcon_mvc_model_row_compare_objects(zval *object1, zval *object2 TSRMLS_DC)
{
	phalcon_mvc_model_row_object *zobj1, *zobj2;
	zval result;

	zobj1 = phalcon_mvc_model_row_get_object(object1 TSRMLS_CC);
	zobj2 = phalcon_mvc_model_row_get_object(object2 TSRMLS_CC);

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
 * @brief Frees all memory associated with @c phalcon_mvc_model_row_object
 */
static void phalcon_mvc_model_row_object_dtor(void* v TSRMLS_DC)
{
	phalcon_mvc_model_row_object* obj = v;

	zend_hash_destroy(obj->props);
	FREE_HASHTABLE(obj->props);
	zend_object_std_dtor(&(obj->obj) TSRMLS_CC);
	efree(obj);
}

/**
 * @brief Constructs @c phalcon_mvc_model_row_object
 */
static zend_object_value phalcon_mvc_model_row_object_ctor(zend_class_entry* ce TSRMLS_DC)
{
	phalcon_mvc_model_row_object *obj = ecalloc(1, sizeof(phalcon_mvc_model_row_object));
	zend_object_value retval;

	zend_object_std_init(&obj->obj, ce TSRMLS_CC);
#if PHP_VERSION_ID >= 50400
	object_properties_init(&obj->obj, ce);
#endif

	ALLOC_HASHTABLE(obj->props);
	zend_hash_init(obj->props, 0, NULL, ZVAL_PTR_DTOR, 0);

	retval.handle = zend_objects_store_put(
		obj,
		(zend_objects_store_dtor_t)zend_objects_destroy_object,
		phalcon_mvc_model_row_object_dtor,
		NULL
		TSRMLS_CC
	);

	retval.handlers = &phalcon_mvc_model_row_object_handlers;
	return retval;
}

static zend_object_value phalcon_mvc_model_row_clone_obj(zval *object TSRMLS_DC)
{
	phalcon_mvc_model_row_object *orig  = phalcon_mvc_model_row_get_object(object TSRMLS_CC);
	zend_object_value result            = phalcon_mvc_model_row_object_ctor(Z_OBJCE_P(object) TSRMLS_CC);
	phalcon_mvc_model_row_object *clone = zend_object_store_get_object_by_handle(result.handle TSRMLS_CC);

	zend_objects_clone_members(&clone->obj, result, &orig->obj, Z_OBJ_HANDLE_P(object) TSRMLS_CC);
	zend_hash_copy(clone->props, orig->props, (copy_ctor_func_t)zval_add_ref, NULL, sizeof(zval*));

	return result;
}

/**
 * Phalcon\Mvc\Model\Row initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Row){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, Row, mvc_model_row, phalcon_mvc_model_row_method_entry, 0);

	phalcon_mvc_model_row_ce->create_object = phalcon_mvc_model_row_object_ctor;

	phalcon_mvc_model_row_object_handlers = *zend_get_std_object_handlers();
	phalcon_mvc_model_row_object_handlers.count_elements  = phalcon_mvc_model_row_count_elements;
	phalcon_mvc_model_row_object_handlers.read_dimension  = phalcon_mvc_model_row_read_dimension;
	phalcon_mvc_model_row_object_handlers.write_dimension = phalcon_mvc_model_row_write_dimension;
	phalcon_mvc_model_row_object_handlers.unset_dimension = phalcon_mvc_model_row_unset_dimension;
	phalcon_mvc_model_row_object_handlers.has_dimension   = phalcon_mvc_model_row_has_dimension;
	phalcon_mvc_model_row_object_handlers.get_properties  = phalcon_mvc_model_row_get_properties;
	phalcon_mvc_model_row_object_handlers.compare_objects = phalcon_mvc_model_row_compare_objects;
	phalcon_mvc_model_row_object_handlers.clone_obj       = phalcon_mvc_model_row_clone_obj;

	zend_class_implements(phalcon_mvc_model_row_ce TSRMLS_CC, 3, zend_ce_arrayaccess, spl_ce_Countable, phalcon_mvc_model_resultinterface_ce);

	return SUCCESS;
}

/**
 * Set the current object's state
 *
 * @param int $dirtyState
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, setDirtyState){

	zval **dirty_state;

	phalcon_fetch_params_ex(1, 0, &dirty_state);

	RETURN_FALSE;
}

/**
 * Checks whether offset exists in the row
 *
 * @param int $index
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetExists){

	zval **index;

	phalcon_fetch_params_ex(1, 0, &index);
	
	RETURN_BOOL(phalcon_mvc_model_row_has_dimension(getThis(), *index, 0 TSRMLS_CC));
}

/**
 * Gets a record in a specific position of the row
 *
 * @param int $index
 * @return string|\Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetGet){

	zval **index, *ret;

	phalcon_fetch_params_ex(1, 0, &index);
	ret = phalcon_mvc_model_row_read_dimension(getThis(), *index, BP_VAR_R TSRMLS_CC);
	RETURN_ZVAL(ret, 1, 0);
}

/**
 * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param int $index
 * @param Phalcon\Mvc\ModelInterface $value
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetSet){

	zval **index, **value;

	phalcon_fetch_params_ex(2, 0, &index, &value);
	phalcon_mvc_model_row_write_dimension(getThis(), *index, *value TSRMLS_CC);
}

/**
 * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param int $offset
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetUnset){

	zval **offset;

	phalcon_fetch_params_ex(1, 0, &offset);
	phalcon_mvc_model_row_unset_dimension(getThis(), *offset TSRMLS_CC);
}

/**
 * Returns the instance as an array representation
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, toArray){

	HashTable *properties = phalcon_mvc_model_row_get_properties(getThis() TSRMLS_CC);

	array_init_size(return_value, zend_hash_num_elements(properties));
	zend_hash_copy(Z_ARRVAL_P(return_value), properties, (copy_ctor_func_t)zval_add_ref, NULL, sizeof(zval*));
}

PHP_METHOD(Phalcon_Mvc_Model_Row, count){
	long int cnt;

	phalcon_mvc_model_row_count_elements(getThis(), &cnt TSRMLS_CC);
	RETURN_LONG(cnt);
}

PHP_METHOD(Phalcon_Mvc_Model_Row, __wakeup)
{
	HashTable *props;
	phalcon_mvc_model_row_object *obj;

	obj   = phalcon_mvc_model_row_get_object(getThis() TSRMLS_CC);
	props = zend_std_get_properties(getThis() TSRMLS_CC);
	zend_hash_copy(obj->props, props, (copy_ctor_func_t)zval_add_ref, NULL, sizeof(zval*));
}
