
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * The contract for sanitizers registered in Phalcon\Filter\Filter.
 *
 * A sanitizer is an invokable object: it must expose a public `__invoke()`
 * method that receives the value to sanitize as its first parameter and
 * returns the sanitized value. Additional parameters, when a sanitizer
 * needs them (e.g. `regex`, `replace`), must be declared after the value
 * parameter; Phalcon\Filter\Filter::sanitize() forwards them in order.
 *
 * `__invoke()` is intentionally not declared here: implementations type
 * their value parameter differently (`string` for text-only sanitizers,
 * untyped for coercing ones), and PHP parameter variance does not allow an
 * implementation to narrow a parameter declared by an interface.
 *
 * A sanitizer operates on a single value. Array handling (one level of
 * recursion by default) is the responsibility of
 * Phalcon\Filter\Filter::sanitize(), not of the sanitizer.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Filter_Sanitizer)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Filter, Sanitizer, phalcon, contracts_filter_sanitizer, NULL);

	return SUCCESS;
}

