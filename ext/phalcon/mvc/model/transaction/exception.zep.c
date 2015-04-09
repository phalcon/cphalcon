
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * Phalcon\Mvc\Model\Transaction\Exception
 *
 * Exceptions thrown in Phalcon\Mvc\Model\Transaction will use this class
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Transaction, Exception, phalcon, mvc_model_transaction_exception, phalcon_mvc_model_exception_ce, NULL, 0);

	return SUCCESS;

}

