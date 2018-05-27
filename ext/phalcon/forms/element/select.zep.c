
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * Phalcon\Forms\Element\Select
 *
 * Component SELECT (choice) for forms
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Select) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, Select, phalcon, forms_element_select, phalcon_forms_element_ce, phalcon_forms_element_select_method_entry, 0);

	zend_declare_property_null(phalcon_forms_element_select_ce, SL("_optionsValues"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Forms\Element constructor
 *
 * @param string name
 * @param object|array options
 * @param array attributes
 */
PHP_METHOD(Phalcon_Forms_Element_Select, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *name_param = NULL, *options = NULL, *attributes = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &name_param, &options, &attributes);

	zephir_get_strval(name, name_param);
	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}
	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(getThis(), SL("_optionsValues"), options TSRMLS_CC);
	ZEPHIR_CALL_PARENT(NULL, phalcon_forms_element_select_ce, getThis(), "__construct", &_0, 226, name, attributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Set the choice's options
 *
 * @param array|object options
 * @return \Phalcon\Forms\Element
 */
PHP_METHOD(Phalcon_Forms_Element_Select, setOptions) {

	zval *options;

	zephir_fetch_params(0, 1, 0, &options);



	zephir_update_property_this(getThis(), SL("_optionsValues"), options TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the choices' options
 *
 * @return array|object
 */
PHP_METHOD(Phalcon_Forms_Element_Select, getOptions) {

	

	RETURN_MEMBER(getThis(), "_optionsValues");

}

/**
 * Adds an option to the current options
 *
 * @param array option
 * @return this
 */
PHP_METHOD(Phalcon_Forms_Element_Select, addOption) {

	HashTable *_1$$3;
	HashPosition _0$$3;
	zval *option, *key = NULL, *value = NULL, **_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &option);



	if (Z_TYPE_P(option) == IS_ARRAY) {
		zephir_is_iterable(option, &_1$$3, &_0$$3, 0, 0, "phalcon/forms/element/select.zep", 84);
		for (
		  ; zend_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HMKEY(key, _1$$3, _0$$3);
			ZEPHIR_GET_HVALUE(value, _2$$3);
			zephir_update_property_array(this_ptr, SL("_optionsValues"), key, value TSRMLS_CC);
		}
	} else {
		zephir_update_property_array_append(this_ptr, SL("_optionsValues"), option TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Renders the element widget returning html
 *
 * @param array attributes
 */
PHP_METHOD(Phalcon_Forms_Element_Select, render) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *attributes = NULL, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &attributes);

	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&_1, this_ptr, "prepareattributes", NULL, 0, attributes);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_optionsValues"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_tag_select_ce, "selectfield", &_0, 227, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

