
extern zend_class_entry *phalcon_adr_responder_redirect_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Responder_Redirect);

PHP_METHOD(Phalcon_ADR_Responder_Redirect, __construct);
PHP_METHOD(Phalcon_ADR_Responder_Redirect, external);
PHP_METHOD(Phalcon_ADR_Responder_Redirect, permanent);
PHP_METHOD(Phalcon_ADR_Responder_Redirect, seeOther);
PHP_METHOD(Phalcon_ADR_Responder_Redirect, temporary);
PHP_METHOD(Phalcon_ADR_Responder_Redirect, status);
PHP_METHOD(Phalcon_ADR_Responder_Redirect, url);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_responder_redirect___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, status, IS_LONG, 0, "302")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, external, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_responder_redirect_external, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_responder_redirect_permanent, 0, 1, Phalcon\\ADR\\Responder\\Redirect, 0)
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_responder_redirect_seeother, 0, 1, Phalcon\\ADR\\Responder\\Redirect, 0)
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_responder_redirect_temporary, 0, 1, Phalcon\\ADR\\Responder\\Redirect, 0)
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_responder_redirect_status, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_responder_redirect_url, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_responder_redirect_method_entry) {
	PHP_ME(Phalcon_ADR_Responder_Redirect, __construct, arginfo_phalcon_adr_responder_redirect___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ADR_Responder_Redirect, external, arginfo_phalcon_adr_responder_redirect_external, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Responder_Redirect, permanent, arginfo_phalcon_adr_responder_redirect_permanent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Responder_Redirect, seeOther, arginfo_phalcon_adr_responder_redirect_seeother, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Responder_Redirect, temporary, arginfo_phalcon_adr_responder_redirect_temporary, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Responder_Redirect, status, arginfo_phalcon_adr_responder_redirect_status, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Responder_Redirect, url, arginfo_phalcon_adr_responder_redirect_url, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
