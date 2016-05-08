
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
 * Phalcon\Queue\Beanstalk\Exception
 *
 * Exceptions thrown in Phalcon\Queue\Beanstalk will use this class
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Beanstalk_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Queue\\Beanstalk, Exception, phalcon, queue_beanstalk_exception, phalcon_exception_ce, NULL, 0);

	return SUCCESS;

}

