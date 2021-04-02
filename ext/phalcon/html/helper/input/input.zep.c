
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Class Input
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_Input) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper\\Input, Input, phalcon, html_helper_input_input, phalcon_html_helper_input_abstractinput_ce, phalcon_html_helper_input_input_method_entry, 0);

	return SUCCESS;

}

/**
 * Sets the type of the input
 *
 * @param string $type
 *
 * @return AbstractInput
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Input, setType) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_strval(&type, type_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type);
	RETURN_THIS();

}

