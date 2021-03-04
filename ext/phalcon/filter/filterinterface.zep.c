
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

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
 * Lazy loads, stores and exposes sanitizer objects
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_FilterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Filter, FilterInterface, phalcon, filter_filterinterface, phalcon_filter_filterinterface_method_entry);

	return SUCCESS;

}

/**
 * Sanitizes a value with a specified single or set of sanitizers
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_FilterInterface, sanitize);
