
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

#include "forms/form.h"
#include "forms/elementinterface.h"
#include "forms/exception.h"
#include "di/injectable.h"
#include "diinterface.h"
#include "filterinterface.h"
#include "validation.h"
#include "validation/exception.h"
#include "validation/message/group.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/file.h"

#include "interned-strings.h"

/**
 * Phalcon\Forms\Form
 *
 * This component allows to build forms using an object-oriented interface
 */
zend_class_entry *phalcon_forms_form_ce;

PHP_METHOD(Phalcon_Forms_Form, __construct);
PHP_METHOD(Phalcon_Forms_Form, setAction);
PHP_METHOD(Phalcon_Forms_Form, getAction);
PHP_METHOD(Phalcon_Forms_Form, setUserOption);
PHP_METHOD(Phalcon_Forms_Form, getUserOption);
PHP_METHOD(Phalcon_Forms_Form, setUserOptions);
PHP_METHOD(Phalcon_Forms_Form, getUserOptions);
PHP_METHOD(Phalcon_Forms_Form, setEntity);
PHP_METHOD(Phalcon_Forms_Form, getEntity);
PHP_METHOD(Phalcon_Forms_Form, getElements);
PHP_METHOD(Phalcon_Forms_Form, bind);
PHP_METHOD(Phalcon_Forms_Form, isValid);
PHP_METHOD(Phalcon_Forms_Form, getMessages);
PHP_METHOD(Phalcon_Forms_Form, getMessagesFor);
PHP_METHOD(Phalcon_Forms_Form, hasMessagesFor);
PHP_METHOD(Phalcon_Forms_Form, add);
PHP_METHOD(Phalcon_Forms_Form, render);
PHP_METHOD(Phalcon_Forms_Form, get);
PHP_METHOD(Phalcon_Forms_Form, label);
PHP_METHOD(Phalcon_Forms_Form, getLabel);
PHP_METHOD(Phalcon_Forms_Form, getValue);
PHP_METHOD(Phalcon_Forms_Form, has);
PHP_METHOD(Phalcon_Forms_Form, remove);
PHP_METHOD(Phalcon_Forms_Form, clear);
PHP_METHOD(Phalcon_Forms_Form, count);
PHP_METHOD(Phalcon_Forms_Form, rewind);
PHP_METHOD(Phalcon_Forms_Form, current);
PHP_METHOD(Phalcon_Forms_Form, key);
PHP_METHOD(Phalcon_Forms_Form, next);
PHP_METHOD(Phalcon_Forms_Form, valid);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, entity)
	ZEND_ARG_INFO(0, userOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_setaction, 0, 0, 1)
	ZEND_ARG_INFO(0, action)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_setuseroption, 0, 0, 2)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_getuseroption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_setuseroptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_setentity, 0, 0, 1)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_bind, 0, 0, 2)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, entity)
	ZEND_ARG_INFO(0, whitelist)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_isvalid, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_getmessages, 0, 0, 0)
	ZEND_ARG_INFO(0, byItemName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_getmessagesfor, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_hasmessagesfor, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_add, 0, 0, 1)
	ZEND_ARG_INFO(0, element)
	ZEND_ARG_INFO(0, postion)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_render, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_label, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_getlabel, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_getvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_clear, 0, 0, 0)
	ZEND_ARG_INFO(0, fields)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_forms_form_method_entry[] = {
	PHP_ME(Phalcon_Forms_Form, __construct, arginfo_phalcon_forms_form___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Forms_Form, setAction, arginfo_phalcon_forms_form_setaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, setUserOption, arginfo_phalcon_forms_form_setuseroption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getUserOption, arginfo_phalcon_forms_form_getuseroption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, setUserOptions, arginfo_phalcon_forms_form_setuseroptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getUserOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, setEntity, arginfo_phalcon_forms_form_setentity, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getEntity, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getElements, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, bind, arginfo_phalcon_forms_form_bind, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, isValid, arginfo_phalcon_forms_form_isvalid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getMessages, arginfo_phalcon_forms_form_getmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getMessagesFor, arginfo_phalcon_forms_form_getmessagesfor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, hasMessagesFor, arginfo_phalcon_forms_form_hasmessagesfor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, add, arginfo_phalcon_forms_form_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, render, arginfo_phalcon_forms_form_render, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, get, arginfo_phalcon_forms_form_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, label, arginfo_phalcon_forms_form_label, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getLabel, arginfo_phalcon_forms_form_getlabel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getValue, arginfo_phalcon_forms_form_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, has, arginfo_phalcon_forms_form_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, remove, arginfo_phalcon_forms_form_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, clear, arginfo_phalcon_forms_form_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, current, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

static zend_object_handlers phalcon_forms_form_object_handlers;

static void phalcon_forms_form_dtor(zend_object_iterator *it TSRMLS_DC)
{
	zval_ptr_dtor((zval**)&it->data);
	efree(it);
}

static int phalcon_forms_form_valid(zend_object_iterator *it TSRMLS_DC)
{
	zval *position, *elements;

	position = phalcon_fetch_nproperty_this((zval*)it->data, SL("_position"), PH_NOISY TSRMLS_CC);
	elements = phalcon_fetch_nproperty_this((zval*)it->data, SL("_elementsIndexed"), PH_NOISY TSRMLS_CC);
	return (phalcon_array_isset(elements, position)) ? SUCCESS : FAILURE;
}

static void phalcon_forms_form_get_current_data(zend_object_iterator *it, zval ***data TSRMLS_DC)
{
	zval *position, *elements;

	position = phalcon_fetch_nproperty_this((zval*)it->data, SL("_position"), PH_NOISY TSRMLS_CC);
	elements = phalcon_fetch_nproperty_this((zval*)it->data, SL("_elementsIndexed"), PH_NOISY TSRMLS_CC);
	*data = phalcon_hash_get(Z_ARRVAL_P(elements), position, BP_VAR_NA);
}

#if ZEND_MODULE_API_NO >= 20121212
static void phalcon_forms_form_get_current_key(zend_object_iterator *it, zval *key TSRMLS_DC)
{
	zval *position;

	position = phalcon_fetch_nproperty_this((zval*)it->data, SL("_position"), PH_NOISY TSRMLS_CC);
	ZVAL_ZVAL(key, position, 1, 0);
}
#else
static int phalcon_forms_form_get_current_key(zend_object_iterator *it, char **str_key, uint *str_key_len, ulong *int_key TSRMLS_DC)
{
	zval *position;

	position = phalcon_fetch_nproperty_this((zval*)it->data, SL("_position"), PH_NOISY TSRMLS_CC);
	*int_key = (IS_LONG == Z_TYPE_P(position)) ? Z_LVAL_P(position) : phalcon_get_intval(position);
	return HASH_KEY_IS_LONG;
}
#endif

static void phalcon_forms_form_move_forward(zend_object_iterator *it TSRMLS_DC)
{
	phalcon_property_incr((zval*)it->data, SL("_position") TSRMLS_CC);
}

static void phalcon_forms_form_rewind(zend_object_iterator *it TSRMLS_DC)
{
	zval *elements, *indexed;

	phalcon_update_property_long((zval*)it->data, SL("_position"), 0 TSRMLS_CC);

	elements = phalcon_fetch_nproperty_this((zval*)it->data, SL("_elements"), PH_NOISY TSRMLS_CC);

	PHALCON_ALLOC_GHOST_ZVAL(indexed);
	if (Z_TYPE_P(elements) == IS_ARRAY) {
		phalcon_array_values(indexed, elements);
	}
	else {
		array_init_size(indexed, 0);
	}

	phalcon_update_property_this((zval*)it->data, SL("_elementsIndexed"), indexed TSRMLS_CC);
}

static zend_object_iterator_funcs phalcon_forms_form_iterator_funcs = {
	phalcon_forms_form_dtor,
	phalcon_forms_form_valid,
	phalcon_forms_form_get_current_data,
	phalcon_forms_form_get_current_key,
	phalcon_forms_form_move_forward,
	phalcon_forms_form_rewind,
	NULL
};

static zend_object_iterator* phalcon_forms_form_get_iterator(zend_class_entry *ce, zval *object, int by_ref TSRMLS_DC)
{
	zend_object_iterator *result;

	if (by_ref) {
		zend_throw_exception_ex(phalcon_validation_exception_ce, 0 TSRMLS_CC, "Cannot iterate Phalcon\\Froms\\Form by reference");
		return NULL;
	}

	result = emalloc(sizeof(zend_object_iterator));

	Z_ADDREF_P(object);
	result->data  = object;
	result->funcs = &phalcon_forms_form_iterator_funcs;

	return result;
}

static int phalcon_forms_form_count_elements(zval *object, long int *count TSRMLS_DC)
{
	int res;
	zval *cnt = NULL;

	if (is_phalcon_class(Z_OBJCE_P(object))) {
		zval *elements = phalcon_fetch_nproperty_this(object, SL("_elements"), PH_NOISY TSRMLS_CC);
		*count = (Z_TYPE_P(elements) == IS_ARRAY) ? zend_hash_num_elements(Z_ARRVAL_P(elements)) : 0;
		return SUCCESS;
	}

	res = phalcon_call_method(&cnt, object, "count", 0, NULL TSRMLS_CC);
	if (res == SUCCESS) {
		*count = (Z_TYPE_P(cnt) == IS_LONG) ? Z_LVAL_P(cnt) : phalcon_get_intval(cnt);
		zval_ptr_dtor(&cnt);
	}

	return res;
}

/**
 * Phalcon\Forms\Form initializer
 */
PHALCON_INIT_CLASS(Phalcon_Forms_Form){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Forms, Form, forms_form, phalcon_di_injectable_ce, phalcon_forms_form_method_entry, 0);

	zend_declare_property_null(phalcon_forms_form_ce, SL("_position"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_entity"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_elements"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_elementsIndexed"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_forms_form_ce->get_iterator         = phalcon_forms_form_get_iterator;
	phalcon_forms_form_ce->iterator_funcs.funcs = &phalcon_forms_form_iterator_funcs;

	phalcon_forms_form_object_handlers = *zend_get_std_object_handlers();
	phalcon_forms_form_object_handlers.count_elements = phalcon_forms_form_count_elements;

	zend_class_implements(phalcon_forms_form_ce TSRMLS_CC, 2, spl_ce_Countable, zend_ce_iterator);

	return SUCCESS;
}

/**
 * Phalcon\Forms\Form constructor
 *
 * @param object $entity
 * @param array $userOptions
 */
PHP_METHOD(Phalcon_Forms_Form, __construct){

	zval *entity = NULL, *user_options = NULL;

	Z_OBJ_HT_P(getThis()) = &phalcon_forms_form_object_handlers;

	phalcon_fetch_params(0, 0, 2, &entity, &user_options);

	if (!entity) {
		entity = PHALCON_GLOBAL(z_null);
	}

	if (!user_options) {
		user_options = PHALCON_GLOBAL(z_null);
	}

	if (Z_TYPE_P(entity) != IS_NULL) {
		if (Z_TYPE_P(entity) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_forms_exception_ce, "The base entity is not valid");
			return;
		}

		phalcon_update_property_this(this_ptr, SL("_entity"), entity TSRMLS_CC);
	}

	/**
	 * Update the user options
	 */
	if (Z_TYPE_P(user_options) == IS_ARRAY) {
		phalcon_update_property_this(this_ptr, SL("_options"), user_options TSRMLS_CC);
	}

	/**
	 * Check for an 'initialize' method and call it
	 */
	if (phalcon_method_exists_ex(this_ptr, SS("initialize") TSRMLS_CC) == SUCCESS) {
		PHALCON_MM_GROW();
		PHALCON_CALL_METHOD(NULL, this_ptr, "initialize", entity, user_options);
		PHALCON_MM_RESTORE();
	}
}

/**
 * Sets the form's action
 *
 * @param string $action
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Form, setAction){

	zval *action;

	phalcon_fetch_params(0, 1, 0, &action);

	phalcon_update_property_this(this_ptr, SL("_action"), action TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the form's action
 *
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Form, getAction){


	RETURN_MEMBER(this_ptr, "_action");
}

/**
 * Sets an option for the form
 *
 * @param string $option
 * @param mixed $value
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Form, setUserOption){

	zval *option, *value;

	phalcon_fetch_params(0, 2, 0, &option, &value);

	phalcon_update_property_array(this_ptr, SL("_options"), option, value TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the value of an option if present
 *
 * @param string $option
 * @param mixed $defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Forms_Form, getUserOption){

	zval *option, *default_value = NULL, *options, *value;

	phalcon_fetch_params(0, 1, 1, &option, &default_value);

	if (!default_value) {
		default_value = PHALCON_GLOBAL(z_null);
	}

	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_fetch(&value, options, option)) {
		RETURN_ZVAL(value, 1, 0);
	}

	RETURN_ZVAL(default_value, 1, 0);
}

/**
 * Sets options for the element
 *
 * @param array $options
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Form, setUserOptions){

	zval *options;

	phalcon_fetch_params(0, 1, 0, &options);

	if (Z_TYPE_P(options) != IS_ARRAY) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_forms_exception_ce, "Parameter 'options' must be an array");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);

	RETURN_THISW();
}

/**
 * Returns the options for the element
 *
 * @return array
 */
PHP_METHOD(Phalcon_Forms_Form, getUserOptions){


	RETURN_MEMBER(this_ptr, "_options");
}

/**
 * Sets the entity related to the model
 *
 * @param object $entity
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Form, setEntity){

	zval *entity;

	phalcon_fetch_params(0, 1, 0, &entity);

	if (Z_TYPE_P(entity) != IS_NULL && Z_TYPE_P(entity) != IS_OBJECT) {
		zend_throw_exception_ex(phalcon_forms_exception_ce, 0 TSRMLS_CC, "'%s' must be an object or NULL", "entity");
		return;
	}

	phalcon_update_property_this(this_ptr, SL("_entity"), entity TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the entity related to the model
 *
 * @return object
 */
PHP_METHOD(Phalcon_Forms_Form, getEntity){


	RETURN_MEMBER(this_ptr, "_entity");
}

/**
 * Returns the form elements added to the form
 *
 * @return Phalcon\Forms\ElementInterface[]
 */
PHP_METHOD(Phalcon_Forms_Form, getElements){


	RETURN_MEMBER(this_ptr, "_elements");
}

/**
 * Binds data to the entity
 *
 * @param array $data
 * @param object $entity
 * @param array $whitelist
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Form, bind){

	zval *data, *entity, *whitelist = NULL, *elements, *filter = NULL;
	zval *value = NULL, *key = NULL, *element = NULL, *filters = NULL, *service_name = NULL;
	zval *dependency_injector = NULL, *filtered_value = NULL;
	zval *method = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &data, &entity, &whitelist);

	if (!whitelist) {
		whitelist = PHALCON_GLOBAL(z_null);
	}

	/**
	 * The data must be an array
	 */
	if (Z_TYPE_P(data) != IS_ARRAY) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_forms_exception_ce, "The data must be an array");
		return;
	}

	PHALCON_OBS_VAR(elements);
	phalcon_read_property_this(&elements, this_ptr, SL("_elements"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(elements) != IS_ARRAY) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_forms_exception_ce, "There are no elements in the form");
		return;
	}

	PHALCON_INIT_VAR(filter);

	phalcon_is_iterable(data, &ah0, &hp0, 0, 0);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(value);

		if (!phalcon_array_isset(elements, key)) {
			zend_hash_move_forward_ex(ah0, &hp0);
			continue;
		}

		/**
		 * Check if the item is in the whitelist
		 */
		if (Z_TYPE_P(whitelist) == IS_ARRAY) {
			if (!phalcon_fast_in_array(key, whitelist TSRMLS_CC)) {
				zend_hash_move_forward_ex(ah0, &hp0);
				continue;
			}
		}

		/**
		 * Get the element
		 */
		PHALCON_OBS_NVAR(element);
		phalcon_array_fetch(&element, elements, key, PH_NOISY);

		/**
		 * Check if the method has filters
		 */
		PHALCON_CALL_METHOD(&filters, element, "getfilters");
		if (zend_is_true(filters)) {

			if (Z_TYPE_P(filter) != IS_OBJECT) {

				PHALCON_INIT_NVAR(service_name);
				PHALCON_ZVAL_MAYBE_INTERNED_STRING(service_name, phalcon_interned_filter);

				PHALCON_CALL_METHOD(&dependency_injector, this_ptr, "getdi");
				PHALCON_VERIFY_INTERFACE(dependency_injector, phalcon_diinterface_ce);

				PHALCON_CALL_METHOD(&filter, dependency_injector, "getshared", service_name);
				PHALCON_VERIFY_INTERFACE(filter, phalcon_filterinterface_ce);
			}

			/**
			 * Sanitize the filters
			 */
			PHALCON_CALL_METHOD(&filtered_value, filter, "sanitize", value, filters);
		} else {
			PHALCON_CPY_WRT(filtered_value, value);
		}

		PHALCON_INIT_NVAR(method);
		PHALCON_CONCAT_SV(method, "set", key);
		zend_str_tolower(Z_STRVAL_P(method), Z_STRLEN_P(method));

		/**
		 * Use the setter if any available
		 */
		if (phalcon_method_exists(entity, method TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD(NULL, entity, Z_STRVAL_P(method), filtered_value);
			zend_hash_move_forward_ex(ah0, &hp0);
			continue;
		}

		/**
		 * Use the public property if it doesn't have a setter
		 */
		phalcon_update_property_zval_zval(entity, key, filtered_value TSRMLS_CC);

		zend_hash_move_forward_ex(ah0, &hp0);
	}

	phalcon_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Validates the form
 *
 * @param array $data
 * @param object $entity
 * @return boolean
 */
PHP_METHOD(Phalcon_Forms_Form, isValid){

	zval *data = NULL, *entity = NULL, *elements, *status = NULL, *not_failed = NULL;
	zval *messages, *element = NULL, *validators = NULL, *name = NULL, *prepared_validators = NULL;
	zval *validator = NULL, *scope = NULL, *validation = NULL, *filters = NULL;
	zval *element_messages = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &data, &entity);

	if (!data) {
		data = PHALCON_GLOBAL(z_null);
	}

	if (!entity) {
		entity = PHALCON_GLOBAL(z_null);
	}

	elements = phalcon_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(elements) != IS_ARRAY) {
		RETURN_MM_TRUE;
	}

	/**
	 * If the user doesn't pass an entity we use the one in this_ptr->_entity
	 */
	if (Z_TYPE_P(entity) == IS_OBJECT) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "bind", data, entity);
	}

	/**
	 * If the data is not an array use the one passed previously
	 */
	if (Z_TYPE_P(data) != IS_ARRAY) {
		data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY TSRMLS_CC);
	}

	/**
	 * Check if there is a method 'beforeValidation'
	 */
	if (phalcon_method_exists_ex(this_ptr, SS("beforevalidation") TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD(&status, this_ptr, "beforevalidation", data, entity);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_CTOR(status);
		}
	}

	not_failed = PHALCON_GLOBAL(z_true);

	PHALCON_INIT_VAR(messages);
	array_init(messages);

	phalcon_is_iterable(elements, &ah0, &hp0, 0, 0);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

		PHALCON_GET_HVALUE(element);

		PHALCON_CALL_METHOD(&validators, element, "getvalidators");
		if (Z_TYPE_P(validators) == IS_ARRAY) {
			if (phalcon_fast_count_ev(validators TSRMLS_CC)) {

				/**
				 * Element's name
				 */
				PHALCON_CALL_METHOD(&name, element, "getname");

				/**
				 * Prepare the validators
				 */
				PHALCON_INIT_NVAR(prepared_validators);
				array_init(prepared_validators);

				phalcon_is_iterable(validators, &ah1, &hp1, 0, 0);

				while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {

					PHALCON_GET_HVALUE(validator);

					PHALCON_INIT_NVAR(scope);
					array_init_size(scope, 2);
					phalcon_array_append(&scope, name, 0);
					phalcon_array_append(&scope, validator, 0);
					phalcon_array_append(&prepared_validators, scope, PH_SEPARATE);

					zend_hash_move_forward_ex(ah1, &hp1);
				}

				/**
				 * Create an implicit validation
				 */
				PHALCON_INIT_NVAR(validation);
				object_init_ex(validation, phalcon_validation_ce);
				PHALCON_CALL_METHOD(NULL, validation, "__construct", prepared_validators);

				/**
				 * Get filters in the element
				 */
				PHALCON_CALL_METHOD(&filters, element, "getfilters");

				/**
				 * Assign the filters to the validation
				 */
				if (Z_TYPE_P(filters) == IS_ARRAY) {
					PHALCON_CALL_METHOD(&name, element, "getname");
					PHALCON_CALL_METHOD(NULL, validation, "setfilters", name, filters);
				}

				/**
				 * Perform the validation
				 */
				PHALCON_CALL_METHOD(&element_messages, validation, "validate", data, entity);
				if (phalcon_fast_count_ev(element_messages TSRMLS_CC)) {
					PHALCON_CALL_METHOD(&name, element, "getname");
					phalcon_array_update_zval(&messages, name, element_messages, PH_COPY | PH_SEPARATE);

					not_failed = PHALCON_GLOBAL(z_false);
				}
			}
		}

		zend_hash_move_forward_ex(ah0, &hp0);
	}

	/**
	 * If the validation fails update the messages
	 */
	if (!zend_is_true(not_failed)) {
		phalcon_update_property_this(this_ptr, SL("_messages"), messages TSRMLS_CC);
	}

	/**
	 * Check if there is a method 'afterValidation'
	 */
	if (phalcon_method_exists_ex(this_ptr, SS("aftervalidation") TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "aftervalidation", messages);
	}

	/**
	 * Return the validation status
	 */

	RETURN_NCTOR(not_failed);
}

/**
 * Returns the messages generated in the validation
 *
 * @param boolean $byItemName
 * @return Phalcon\Validation\Message\Group
 */
PHP_METHOD(Phalcon_Forms_Form, getMessages){

	zval **by_item_name = NULL, *messages;

	phalcon_fetch_params_ex(0, 1, &by_item_name);

	messages = phalcon_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY TSRMLS_CC);
	if (by_item_name && zend_is_true(*by_item_name)) {
		if (Z_TYPE_P(messages) != IS_ARRAY) {
			object_init_ex(return_value, phalcon_validation_message_group_ce);
			phalcon_validation_group_construct_helper(return_value, NULL TSRMLS_CC);
		}
		else {
			RETURN_ZVAL(messages, 1, 0);
		}
	}
	else {
		object_init_ex(return_value, phalcon_validation_message_group_ce);
		phalcon_validation_group_construct_helper(return_value, NULL TSRMLS_CC);

		if (Z_TYPE_P(messages) == IS_ARRAY) {
			HashPosition hp;
			zval **v;

			for (
				zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(messages), &hp);
				zend_hash_get_current_data_ex(Z_ARRVAL_P(messages), (void**)&v, &hp) == SUCCESS;
				zend_hash_move_forward_ex(Z_ARRVAL_P(messages), &hp)
			) {
				PHALCON_CALL_METHODW(NULL, return_value, "appendmessages", *v);
			}
		}
	}
}

/**
 * Returns the messages generated for a specific element
 *
 * @return Phalcon\Validation\Message\Group[]
 */
PHP_METHOD(Phalcon_Forms_Form, getMessagesFor){

	zval **name, *messages, *element_messages;

	phalcon_fetch_params_ex(1, 0, &name);

	messages = phalcon_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_fetch(&element_messages, messages, *name)) {
		RETURN_ZVAL(element_messages, 1, 0);
	}

	object_init_ex(return_value, phalcon_validation_message_group_ce);
	phalcon_validation_group_construct_helper(return_value, NULL TSRMLS_CC);
}

/**
 * Check if messages were generated for a specific element
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Forms_Form, hasMessagesFor){

	zval **name, *messages;

	phalcon_fetch_params_ex(1, 0, &name);

	messages = phalcon_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY TSRMLS_CC);
	RETURN_BOOL(phalcon_array_isset(messages, *name));
}

/**
 * Adds an element to the form
 *
 * @param Phalcon\Forms\ElementInterface $element
 * @param string $postion
 * @param bool $type If $type is TRUE, the element wile add before $postion, else is after
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Form, add){

	zval *element, *pos = NULL, *type = NULL, *name = NULL, *values, *elements;
	zval *tmp0 = NULL, *tmp1 = NULL, *length, *offset, *preserve_keys;
	int found = 0, i = 0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &element, &pos, &type);

	PHALCON_VERIFY_INTERFACE_EX(element, phalcon_forms_elementinterface_ce, phalcon_forms_exception_ce, 1);

	/**
	 * Gets the element's name
	 */
	PHALCON_CALL_METHOD(&name, element, "getname");

	/**
	 * Link the element to the form
	 */
	PHALCON_CALL_METHOD(NULL, element, "setform", this_ptr);

	if (!pos || Z_TYPE_P(pos) == IS_NULL) {
		/* Append the element by its name */
		phalcon_update_property_array(this_ptr, SL("_elements"), name, element TSRMLS_CC);
	} else {
		if (type && zend_is_true(type)) {
			i = -1;
		}

		PHALCON_INIT_VAR(values);
		array_init_size(values, 1);

		phalcon_array_update_zval(&values, name, element, PH_COPY);

		elements = phalcon_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY TSRMLS_CC);

		if (Z_TYPE_P(elements) == IS_ARRAY) {
			HashPosition hp;

			for (
				zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(elements), &hp);
				zend_hash_get_current_key_type_ex(Z_ARRVAL_P(elements), &hp) != HASH_KEY_NON_EXISTANT;
				zend_hash_move_forward_ex(Z_ARRVAL_P(elements), &hp)
			) {
				zval key = phalcon_get_current_key_w(Z_ARRVAL_P(elements), &hp);

				++i;
				if (phalcon_is_equal(&key, pos TSRMLS_CC)) {
					found = 1;
					break;
				}
			}
		}

		if (!found) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_forms_exception_ce, "Array position does not exist");
			return;
		}

		PHALCON_INIT_VAR(offset);
		ZVAL_LONG(offset, i);

		length        = PHALCON_GLOBAL(z_zero);
		preserve_keys = PHALCON_GLOBAL(z_true);

		PHALCON_CALL_FUNCTION(&tmp0, "array_slice", elements, length, offset, preserve_keys);

		length = PHALCON_GLOBAL(z_null);

		PHALCON_CALL_FUNCTION(&tmp1, "array_slice", elements, offset, length, preserve_keys);

		PHALCON_INIT_NVAR(elements);
		array_init(elements);

		phalcon_array_merge_recursive_n(&elements, tmp0);
		phalcon_array_merge_recursive_n(&elements, values);
		phalcon_array_merge_recursive_n(&elements, tmp1);

		phalcon_update_property_this(this_ptr, SL("_elements"), elements TSRMLS_CC);
	}

	RETURN_THIS();
}

/**
 * Renders a specific item in the form
 *
 * @param string $name
 * @param array $attributes
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Form, render){

	zval **name, **attributes = NULL, *elements, *element;

	phalcon_fetch_params_ex(1, 1, &name, &attributes);

	PHALCON_ENSURE_IS_STRING(name);
	if (!attributes) {
		attributes = &PHALCON_GLOBAL(z_null);
	}

	elements = phalcon_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset_fetch(&element, elements, *name)) {
		zend_throw_exception_ex(phalcon_forms_exception_ce, 0 TSRMLS_CC, "Element with ID=%s is not a part of the form", Z_STRVAL_P(*name));
		return;
	}

	PHALCON_RETURN_CALL_METHODW(element, "render", *attributes);
}

/**
 * Returns an element added to the form by its name
 *
 * @param string $name
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Form, get){

	zval **name, *elements, *element;

	phalcon_fetch_params_ex(1, 0, &name);

	elements = phalcon_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset_fetch(&element, elements, *name)) {
		PHALCON_ENSURE_IS_STRING(name);
		zend_throw_exception_ex(phalcon_forms_exception_ce, 0 TSRMLS_CC, "Element with ID=%s is not a part of the form", Z_STRVAL_P(*name));
		return;
	}

	RETURN_ZVAL(element, 1, 0);
}

/**
 * Generate the label of a element added to the form including HTML
 *
 * @param string $name
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Form, label){

	zval **name, **attributes = NULL, *elements, *element;

	phalcon_fetch_params_ex(1, 1, &name, &attributes);

	if (!attributes) {
		attributes = &PHALCON_GLOBAL(z_null);
	}

	elements = phalcon_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset_fetch(&element, elements, *name)) {
		PHALCON_ENSURE_IS_STRING(name);
		zend_throw_exception_ex(phalcon_forms_exception_ce, 0 TSRMLS_CC, "Element with ID=%s is not a part of the form", Z_STRVAL_P(*name));
		return;
	}

	PHALCON_RETURN_CALL_METHODW(element, "label", *attributes);
}

/**
 * Returns a label for an element
 *
 * @param string $name
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Form, getLabel){

	zval **name, *elements, *element, *label = NULL;

	phalcon_fetch_params_ex(1, 0, &name);

	elements = phalcon_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset_fetch(&element, elements, *name)) {
		PHALCON_ENSURE_IS_STRING(name);
		zend_throw_exception_ex(phalcon_forms_exception_ce, 0 TSRMLS_CC, "Element with ID=%s is not a part of the form", Z_STRVAL_P(*name));
		return;
	}

	PHALCON_MM_GROW();
	PHALCON_CALL_METHOD(&label, element, "getlabel");

	/* Use the element's name as label if the label is not available */
	if (!zend_is_true(label)) {
		RETURN_CTOR(*name);
	}

	RETURN_CTOR(label);
}

/**
 * Gets a value from the internal related entity or from the default value
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Phalcon_Forms_Form, getValue){

	zval *name, *entity, *method, *value = NULL, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);

	entity = phalcon_fetch_nproperty_this(this_ptr, SL("_entity"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(entity) == IS_OBJECT) {
		/**
		 * Check if the entity has a getter
		 */
		PHALCON_INIT_VAR(method);
		PHALCON_CONCAT_SV(method, "get", name);
		zend_str_tolower(Z_STRVAL_P(method), Z_STRLEN_P(method));
		if (phalcon_method_exists_ex(entity, Z_STRVAL_P(method), Z_STRLEN_P(method)+1 TSRMLS_CC) == SUCCESS) {
			PHALCON_RETURN_CALL_METHOD(entity, Z_STRVAL_P(method));
			RETURN_MM();
		}

		/**
		 * Check if the entity has a public property
		 */
		if (phalcon_isset_property_zval(entity, name TSRMLS_CC)) {
			PHALCON_OBS_VAR(value);
			phalcon_read_property_zval(&value, entity, name, PH_NOISY TSRMLS_CC);
			RETURN_CTOR(value);
		}
	}

	data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(data) == IS_ARRAY) {

		/**
		 * Check if the data is in the data array
		 */
		if (phalcon_array_isset_fetch(&value, data, name)) {
			RETURN_CTOR(value);
		}
	}

	RETURN_MM_NULL();
}

/**
 * Check if the form contains an element
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Forms_Form, has){

	zval **name, *elements;

	phalcon_fetch_params_ex(1, 0, &name);

	elements = phalcon_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY TSRMLS_CC);
	RETURN_BOOL(phalcon_array_isset(elements, *name));
}

/**
 * Removes an element from the form
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Forms_Form, remove){

	zval *name, *elements;

	phalcon_fetch_params(0, 1, 0, &name);

	elements = phalcon_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY TSRMLS_CC);

	if (phalcon_array_isset(elements, name)) {
		phalcon_unset_property_array(this_ptr, SL("_elements"), name TSRMLS_CC);

		/* Clean the iterator index */
		phalcon_update_property_null(this_ptr, SL("_elementsIndexed") TSRMLS_CC);

		RETURN_TRUE;
	}

	RETURN_FALSE;
}

/**
 * Clears every element in the form to its default value
 *
 * @param array $fields
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Form, clear){

	zval *fields = NULL, *elements, *element = NULL, *name = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &fields);

	if (!fields) {
		fields = PHALCON_GLOBAL(z_null);
	}

	elements = phalcon_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(elements) == IS_ARRAY) {

		phalcon_is_iterable(elements, &ah0, &hp0, 0, 0);

		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

			PHALCON_GET_HVALUE(element);

			if (Z_TYPE_P(fields) != IS_ARRAY) {
				PHALCON_CALL_METHOD(NULL, element, "clear");
			} else {
				PHALCON_CALL_METHOD(&name, element, "getname");
				if (phalcon_fast_in_array(name, fields TSRMLS_CC)) {
					PHALCON_CALL_METHOD(NULL, element, "clear");
				}
			}

			zend_hash_move_forward_ex(ah0, &hp0);
		}

	}

	RETURN_THIS();
}

/**
 * Returns the number of elements in the form
 *
 * @return int
 */
PHP_METHOD(Phalcon_Forms_Form, count){

	long int count;

	if (SUCCESS == phalcon_forms_form_count_elements(getThis(), &count TSRMLS_CC)) {
		RETURN_LONG(count);
	}

	RETURN_NULL();
}

/**
 * Rewinds the internal iterator
 */
PHP_METHOD(Phalcon_Forms_Form, rewind){

	zend_object_iterator it;
	it.data = getThis();
	phalcon_forms_form_iterator_funcs.rewind(&it TSRMLS_CC);
}

/**
 * Returns the current element in the iterator
 *
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Form, current){

	zval **ret;
	zend_object_iterator it;
	it.data = getThis();

	phalcon_forms_form_iterator_funcs.get_current_data(&it, &ret TSRMLS_CC);
	if (ret) {
		RETURN_ZVAL(*ret, 1, 0);
	}

	RETURN_NULL();
}

/**
 * Returns the current position/key in the iterator
 *
 * @return int
 */
PHP_METHOD(Phalcon_Forms_Form, key){

	zend_object_iterator it;
	it.data = getThis();
#if ZEND_MODULE_API_NO >= 20121212
	phalcon_forms_form_iterator_funcs.get_current_key(&it, return_value TSRMLS_CC);
#else
	{
		char *str_key;
		uint str_key_len;
		ulong int_key;
		if (HASH_KEY_IS_STRING == phalcon_forms_form_iterator_funcs.get_current_key(&it, &str_key, &str_key_len, &int_key TSRMLS_CC)) {
			RETURN_STRINGL(str_key, str_key_len-1, 1);
		}

		RETURN_LONG(int_key);
	}
#endif
}

/**
 * Moves the internal iteration pointer to the next position
 *
 */
PHP_METHOD(Phalcon_Forms_Form, next){

	zend_object_iterator it;
	it.data = getThis();
	phalcon_forms_form_iterator_funcs.move_forward(&it TSRMLS_CC);
}

/**
 * Check if the current element in the iterator is valid
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Forms_Form, valid){

	zend_object_iterator it;
	it.data = getThis();
	RETURN_BOOL(phalcon_forms_form_iterator_funcs.valid(&it TSRMLS_CC) == SUCCESS);
}
