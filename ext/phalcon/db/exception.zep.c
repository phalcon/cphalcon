
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
 * Phalcon\Db\Exception
 *
 * Exceptions thrown in Phalcon\Db will use this class
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db, Exception, phalcon, db_exception, phalcon_exception_ce, NULL, 0);

	return SUCCESS;

}

