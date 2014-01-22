#include "psr/log/invalidargumentexception.h"

#include <Zend/zend_exceptions.h>
#include <ext/spl/spl_exceptions.h>

zend_class_entry *psr_log_invalidargumentexception_ce;

PHALCON_INIT_CLASS(Psr_Log_InvalidArgumentException)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "Psr\\Log\\InvalidArgumentException", NULL);

	psr_log_invalidargumentexception_ce = zend_register_internal_class_ex(&ce, spl_ce_InvalidArgumentException, NULL TSRMLS_CC);
	return (EXPECTED(psr_log_invalidargumentexception_ce != NULL)) ? SUCCESS : FAILURE;
}
