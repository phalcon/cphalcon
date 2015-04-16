
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
 * Phalcon\Assets\Exception
 *
 * Exceptions thrown in Phalcon\Assets will use this class
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Assets, Exception, phalcon, assets_exception, phalcon_exception_ce, NULL, 0);

	return SUCCESS;

}

