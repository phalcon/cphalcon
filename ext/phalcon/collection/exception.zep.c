
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Collection\Exception
 *
 * Exceptions for the Collection object
 */
ZEPHIR_INIT_CLASS(Phalcon_Collection_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Collection, Exception, phalcon, collection_exception, zend_exception_get_default(TSRMLS_C), NULL, 0);

	zend_class_implements(phalcon_collection_exception_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("throwable")));
	return SUCCESS;

}

