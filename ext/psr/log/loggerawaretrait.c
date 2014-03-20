
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#include "psr/log/loggerawaretrait.h"
#include "psr/log/loggerawareinterface.h"

zend_class_entry *psr_log_loggerawaretrait_ce;

#if PHP_VERSION_ID >= 50400

static PHP_METHOD(Psr_Log_LoggerAwareTrait, setLogger)
{
	zval **logger;

	if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "Z", &logger)) {
		RETURN_NULL();
	}

	zend_update_property(psr_log_loggerawaretrait_ce, getThis(), ZEND_STRL("logger"), *logger TSRMLS_CC);
}

static const zend_function_entry fe_psr_log_loggerawaretrait[] = {
	PHP_ME(Psr_Log_LoggerAwareTrait, setLogger, arginfo_psr_log_loggerawareinterface_setlogger, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

PHALCON_INIT_CLASS(Psr_Log_LoggerAwareTrait)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "Psr\\Log\\LoggerAwareTrait", fe_psr_log_loggerawaretrait);

	psr_log_loggerawaretrait_ce = zend_register_internal_class(&ce TSRMLS_CC);
	if (EXPECTED(psr_log_loggerawaretrait_ce != NULL)) {
		psr_log_loggerawaretrait_ce->ce_flags |= ZEND_ACC_TRAIT;

		zend_declare_property_null(psr_log_loggerawaretrait_ce, ZEND_STRL("logger"), ZEND_ACC_PROTECTED TSRMLS_CC);
		return SUCCESS;
	}

	return FAILURE;
}

#else

PHALCON_INIT_CLASS(Psr_Log_LoggerAwareTrait)
{
	psr_log_loggerawaretrait_ce = NULL;
	return SUCCESS;
}

#endif
