
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
 * Phalcon\Acl\Exception
 *
 * Class for exceptions thrown by Phalcon\Acl
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Acl, Exception, phalcon, acl_exception, phalcon_exception_ce, NULL, 0);

	return SUCCESS;

}

