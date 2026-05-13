
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */
/**
 * Generic input helper. The HTML5 `type` attribute is supplied via the
 * constructor, which means the `TagFactory` can register a single class
 * for all type-string-only inputs (color, date, email, hidden, number, ...)
 * and differentiate them through the recipe map. The type can also be
 * changed after construction via `setType()`.
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_Generic)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper\\Input, Generic, phalcon, html_helper_input_generic, phalcon_html_helper_input_abstractinput_ce, phalcon_html_helper_input_generic_method_entry, 0);

	return SUCCESS;
}

/**
 * @param EscaperInterface $escaper
 * @param Doctype          $doctype
 * @param string           $type
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Generic, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *type = NULL;
	zval *escaper, escaper_sub, *doctype = NULL, doctype_sub, type_zv, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZVAL_UNDEF(&doctype_sub);
	ZVAL_UNDEF(&type_zv);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_OBJECT_OF_CLASS(escaper, phalcon_html_escaper_escaperinterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(doctype, phalcon_html_helper_doctype_ce)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	escaper = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 1) {
		doctype = ZEND_CALL_ARG(execute_data, 2);
	}
	if (!doctype) {
		doctype = &doctype_sub;
		doctype = &__$null;
	}
	if (!type) {
		type = zend_string_init(ZEND_STRL("text"), 0);
		zephir_memory_observe(&type_zv);
		ZVAL_STR(&type_zv, type);
	} else {
		zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_html_helper_input_generic_ce, getThis(), "__construct", NULL, 0, escaper, doctype);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type_zv);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the type of the input.
 *
 * @param string $type
 *
 * @return AbstractInput
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Generic, setType)
{
	zval type_zv;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&type_zv, type);
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type_zv);
	RETURN_THISW();
}

