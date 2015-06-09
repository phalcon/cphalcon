
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
#include "kernel/fcall.h"
#include "kernel/memory.h"


/**
 * Phalcon\Forms\Element\Check
 *
 * Component INPUT[type=check] for forms
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Check) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, Check, phalcon, forms_element_check, phalcon_forms_element_ce, phalcon_forms_element_check_method_entry, 0);

	zend_class_implements(phalcon_forms_element_check_ce TSRMLS_CC, 1, phalcon_forms_elementinterface_ce);
	return SUCCESS;

}

/**
 * Renders the element widget returning html
 *
 * @param array attributes
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element_Check, render) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *attributes = NULL, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &attributes);

	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_2);
	ZVAL_BOOL(_2, 1);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "prepareattributes", NULL, 0, attributes, _2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_tag_ce, "checkfield", &_0, 175, _1);
	zephir_check_call_status();
	RETURN_MM();

}

