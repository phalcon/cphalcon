
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

#include "psr/log/nulllogger.h"
#include "psr/log/abstractlogger.h"
#include "psr/log/loggerinterface.h"

zend_class_entry *psr_log_nulllogger_ce;

static PHP_METHOD(Psr_Log_NullLogger, log)
{
	zval *level, *message, *context = NULL;

	if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z!", &level, &message, &context)) {
		RETURN_NULL();
	}
}

static const zend_function_entry fe_psr_log_nulllogger[] = {
	PHP_ME(Psr_Log_NullLogger, log, arginfo_psr_log_loggerinterface_log, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

PHALCON_INIT_CLASS(Psr_Log_NullLogger)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "Psr\\Log\\NullLogger", fe_psr_log_nulllogger);

	psr_log_nulllogger_ce = zend_register_internal_class_ex(&ce, psr_log_abstractlogger_ce, NULL TSRMLS_CC);
	return (EXPECTED(psr_log_nulllogger_ce != NULL)) ? SUCCESS : FAILURE;
}
