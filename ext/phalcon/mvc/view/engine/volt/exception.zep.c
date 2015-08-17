
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * Phalcon\Mvc\View\Exception
 *
 * Class for exceptions thrown by Phalcon\Mvc\View
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\View\\Engine\\Volt, Exception, phalcon, mvc_view_engine_volt_exception, phalcon_mvc_view_exception_ce, NULL, 0);

	return SUCCESS;

}

