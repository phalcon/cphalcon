
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
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */
/**
 * Class Img
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Img)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Img, phalcon, html_helper_img, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_img_method_entry, 0);

	return SUCCESS;
}

/**
 * Produce a <img> tag.
 *
 * @param string $src
 * @param array  $attributes
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_Img, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval src_zv, *attributes_param = NULL, _0, _1;
	zend_string *src = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&src_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&attributes);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(src)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		attributes_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&src_zv);
	ZVAL_STR_COPY(&src_zv, src);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "src");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "injectattribute", NULL, 0, &_1, &src_zv, &attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "img");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "selfclose", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

