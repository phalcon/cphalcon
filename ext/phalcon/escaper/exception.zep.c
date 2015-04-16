
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
 * Phalcon\Escaper\Exception
 *
 * Exceptions thrown in Phalcon\Escaper will use this class
 */
ZEPHIR_INIT_CLASS(Phalcon_Escaper_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Escaper, Exception, phalcon, escaper_exception, phalcon_exception_ce, NULL, 0);

	return SUCCESS;

}

