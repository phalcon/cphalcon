
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

#include "psr/log/loggerawareinterface.h"

zend_class_entry *psr_log_loggerawareinterface_ce;

static const zend_function_entry fe_psr_log_loggerawareinterface[] = {
	PHP_ABSTRACT_ME(Psr_Log_LoggerAwareInterface, setLogger, arginfo_psr_log_loggerawareinterface_setlogger)
	PHP_FE_END
};

PHALCON_INIT_CLASS(Psr_Log_LoggerAwareInterface)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "Psr\\Log\\LoggerAwareInterface", fe_psr_log_loggerawareinterface);

	psr_log_loggerawareinterface_ce = zend_register_internal_interface(&ce TSRMLS_CC);
	return (EXPECTED(psr_log_loggerawareinterface_ce != NULL)) ? SUCCESS : FAILURE;
}
