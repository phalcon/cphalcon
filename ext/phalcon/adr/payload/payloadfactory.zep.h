
extern zend_class_entry *phalcon_adr_payload_payloadfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Payload_PayloadFactory);

PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, accepted);
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, authenticated);
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, authorized);
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, created);
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, deleted);
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, error);
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, forbidden);
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, found);
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, invalid);
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, notAccepted);
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, notCreated);
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, notDeleted);
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, notFound);
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, notUpdated);
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, processing);
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, success);
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, unauthenticated);
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, updated);
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, valid);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payloadfactory_accepted, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payloadfactory_authenticated, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payloadfactory_authorized, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payloadfactory_created, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payloadfactory_deleted, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payloadfactory_error, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payloadfactory_forbidden, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payloadfactory_found, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payloadfactory_invalid, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payloadfactory_notaccepted, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payloadfactory_notcreated, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payloadfactory_notdeleted, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payloadfactory_notfound, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payloadfactory_notupdated, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payloadfactory_processing, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payloadfactory_success, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payloadfactory_unauthenticated, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payloadfactory_updated, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payloadfactory_valid, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_payload_payloadfactory_method_entry) {
	PHP_ME(Phalcon_ADR_Payload_PayloadFactory, accepted, arginfo_phalcon_adr_payload_payloadfactory_accepted, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_PayloadFactory, authenticated, arginfo_phalcon_adr_payload_payloadfactory_authenticated, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_PayloadFactory, authorized, arginfo_phalcon_adr_payload_payloadfactory_authorized, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_PayloadFactory, created, arginfo_phalcon_adr_payload_payloadfactory_created, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_PayloadFactory, deleted, arginfo_phalcon_adr_payload_payloadfactory_deleted, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_PayloadFactory, error, arginfo_phalcon_adr_payload_payloadfactory_error, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_PayloadFactory, forbidden, arginfo_phalcon_adr_payload_payloadfactory_forbidden, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_PayloadFactory, found, arginfo_phalcon_adr_payload_payloadfactory_found, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_PayloadFactory, invalid, arginfo_phalcon_adr_payload_payloadfactory_invalid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_PayloadFactory, notAccepted, arginfo_phalcon_adr_payload_payloadfactory_notaccepted, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_PayloadFactory, notCreated, arginfo_phalcon_adr_payload_payloadfactory_notcreated, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_PayloadFactory, notDeleted, arginfo_phalcon_adr_payload_payloadfactory_notdeleted, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_PayloadFactory, notFound, arginfo_phalcon_adr_payload_payloadfactory_notfound, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_PayloadFactory, notUpdated, arginfo_phalcon_adr_payload_payloadfactory_notupdated, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_PayloadFactory, processing, arginfo_phalcon_adr_payload_payloadfactory_processing, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_PayloadFactory, success, arginfo_phalcon_adr_payload_payloadfactory_success, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_PayloadFactory, unauthenticated, arginfo_phalcon_adr_payload_payloadfactory_unauthenticated, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_PayloadFactory, updated, arginfo_phalcon_adr_payload_payloadfactory_updated, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_PayloadFactory, valid, arginfo_phalcon_adr_payload_payloadfactory_valid, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
