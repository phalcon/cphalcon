
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
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Forms\Element\Radio
 *
 * Component INPUT[type=radio] for forms
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Radio) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, Radio, phalcon, forms_element_radio, phalcon_forms_element_abstractelement_ce, phalcon_forms_element_radio_method_entry, 0);

	return SUCCESS;

}

/**
 * Renders the element widget returning HTML
 */
PHP_METHOD(Phalcon_Forms_Element_Radio, render) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *attributes_param = NULL, _1, _2;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &attributes_param);

	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	ZVAL_BOOL(&_2, 1);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "prepareattributes", NULL, 0, &attributes, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_tag_ce, "radiofield", &_0, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

