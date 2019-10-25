
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Exceptions thrown in Phalcon\Cache will use this class
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Exception_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Exception, Exception, phalcon, cache_exception_exception, phalcon_exception_ce, NULL, 0);

	zend_class_implements(phalcon_cache_exception_exception_ce, 1, zephir_get_internal_ce(SL("psr\\simplecache\\cacheexception")));
	return SUCCESS;

}

