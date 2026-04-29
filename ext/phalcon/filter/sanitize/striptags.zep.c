
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
#include "kernel/object.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Filter\Sanitize\Striptags
 *
 * Sanitizes a value striptags
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_Striptags)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter\\Sanitize, Striptags, phalcon, filter_sanitize_striptags, phalcon_filter_sanitize_striptags_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $input The text to sanitize
 *
 * @return string
 */
PHP_METHOD(Phalcon_Filter_Sanitize_Striptags, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv;
	zend_string *input = NULL;

	ZVAL_UNDEF(&input_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&input_zv, input);
	ZEPHIR_RETURN_CALL_FUNCTION("strip_tags", NULL, 290, &input_zv);
	zephir_check_call_status();
	RETURN_MM();
}

