
extern zend_class_entry *phalcon_adr_front_abstracthttpfront_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Front_AbstractHttpFront);

PHP_METHOD(Phalcon_ADR_Front_AbstractHttpFront, __construct);
PHP_METHOD(Phalcon_ADR_Front_AbstractHttpFront, boot);
PHP_METHOD(Phalcon_ADR_Front_AbstractHttpFront, run);
PHP_METHOD(Phalcon_ADR_Front_AbstractHttpFront, buildContainer);
PHP_METHOD(Phalcon_ADR_Front_AbstractHttpFront, getApplication);
PHP_METHOD(Phalcon_ADR_Front_AbstractHttpFront, handleBootError);
PHP_METHOD(Phalcon_ADR_Front_AbstractHttpFront, loadEnvironment);
PHP_METHOD(Phalcon_ADR_Front_AbstractHttpFront, registerProviders);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_front_abstracthttpfront___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, projectRoot, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_front_abstracthttpfront_boot, 0, 0, Phalcon\\Container\\Container, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_front_abstracthttpfront_run, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_front_abstracthttpfront_buildcontainer, 0, 0, Phalcon\\Container\\Container, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_front_abstracthttpfront_getapplication, 0, 1, Phalcon\\Contracts\\ADR\\Application, 0)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Container\\Container, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_front_abstracthttpfront_handlebooterror, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, exception, Throwable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_front_abstracthttpfront_loadenvironment, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Container\\Container, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_front_abstracthttpfront_registerproviders, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Container\\Container, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_front_abstracthttpfront_method_entry) {
	PHP_ME(Phalcon_ADR_Front_AbstractHttpFront, __construct, arginfo_phalcon_adr_front_abstracthttpfront___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ADR_Front_AbstractHttpFront, boot, arginfo_phalcon_adr_front_abstracthttpfront_boot, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Front_AbstractHttpFront, run, arginfo_phalcon_adr_front_abstracthttpfront_run, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Front_AbstractHttpFront, buildContainer, arginfo_phalcon_adr_front_abstracthttpfront_buildcontainer, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Front_AbstractHttpFront, getApplication, arginfo_phalcon_adr_front_abstracthttpfront_getapplication, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Front_AbstractHttpFront, handleBootError, arginfo_phalcon_adr_front_abstracthttpfront_handlebooterror, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Front_AbstractHttpFront, loadEnvironment, arginfo_phalcon_adr_front_abstracthttpfront_loadenvironment, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Front_AbstractHttpFront, registerProviders, arginfo_phalcon_adr_front_abstracthttpfront_registerproviders, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
