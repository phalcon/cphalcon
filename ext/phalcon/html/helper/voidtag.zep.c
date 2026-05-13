
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


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
 * Generic void-tag escape hatch. Renders a self-closing tag for any name
 * without a dedicated helper. The trailing `/` is emitted only for XHTML
 * doctypes, matching the `Input/AbstractInput::__toString` convention.
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_VoidTag)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, VoidTag, phalcon, html_helper_voidtag, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_voidtag_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $name
 * @param array  $attributes
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_VoidTag, __invoke)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval name_zv, *attributes_param = NULL, closeTag, _0, _2, _3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&closeTag);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&attributes);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		attributes_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	ZEPHIR_INIT_VAR(&closeTag);
	ZVAL_STRING(&closeTag, "");
	zephir_read_property(&_0, this_ptr, ZEND_STRL("doctype"), PH_NOISY_CC | PH_READONLY);
	_1 = Z_TYPE_P(&_0) != IS_NULL;
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("doctype"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_3, &_2, "gettype", NULL, 0);
		zephir_check_call_status();
		_1 = ZEPHIR_GT_LONG(&_3, 5);
	}
	if (_1) {
		ZEPHIR_INIT_NVAR(&closeTag);
		ZVAL_STRING(&closeTag, "/");
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "rendertag", NULL, 0, &name_zv, &attributes, &closeTag);
	zephir_check_call_status();
	RETURN_MM();
}

