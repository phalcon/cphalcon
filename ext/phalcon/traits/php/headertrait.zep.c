
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
 * Header based wrapper methods
 */
ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_HeaderTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Traits\\Php, HeaderTrait, phalcon, traits_php_headertrait, phalcon_traits_php_headertrait_method_entry);

	return SUCCESS;
}

/**
 * Checks if or where headers have been sent
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.headers-sent.php
 */
PHP_METHOD(Phalcon_Traits_Php_HeaderTrait, phpHeadersSent)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_RETURN_CALL_FUNCTION("headers_sent", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

