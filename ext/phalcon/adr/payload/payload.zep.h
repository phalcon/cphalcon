
extern zend_class_entry *phalcon_adr_payload_payload_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Payload_Payload);

PHP_METHOD(Phalcon_ADR_Payload_Payload, accepted);
PHP_METHOD(Phalcon_ADR_Payload_Payload, authenticated);
PHP_METHOD(Phalcon_ADR_Payload_Payload, authorized);
PHP_METHOD(Phalcon_ADR_Payload_Payload, created);
PHP_METHOD(Phalcon_ADR_Payload_Payload, deleted);
PHP_METHOD(Phalcon_ADR_Payload_Payload, error);
PHP_METHOD(Phalcon_ADR_Payload_Payload, forbidden);
PHP_METHOD(Phalcon_ADR_Payload_Payload, found);
PHP_METHOD(Phalcon_ADR_Payload_Payload, invalid);
PHP_METHOD(Phalcon_ADR_Payload_Payload, notAccepted);
PHP_METHOD(Phalcon_ADR_Payload_Payload, notCreated);
PHP_METHOD(Phalcon_ADR_Payload_Payload, notDeleted);
PHP_METHOD(Phalcon_ADR_Payload_Payload, notFound);
PHP_METHOD(Phalcon_ADR_Payload_Payload, notUpdated);
PHP_METHOD(Phalcon_ADR_Payload_Payload, processing);
PHP_METHOD(Phalcon_ADR_Payload_Payload, success);
PHP_METHOD(Phalcon_ADR_Payload_Payload, unauthenticated);
PHP_METHOD(Phalcon_ADR_Payload_Payload, updated);
PHP_METHOD(Phalcon_ADR_Payload_Payload, valid);
PHP_METHOD(Phalcon_ADR_Payload_Payload, getException);
PHP_METHOD(Phalcon_ADR_Payload_Payload, getExtras);
PHP_METHOD(Phalcon_ADR_Payload_Payload, getInput);
PHP_METHOD(Phalcon_ADR_Payload_Payload, getMessages);
PHP_METHOD(Phalcon_ADR_Payload_Payload, getResult);
PHP_METHOD(Phalcon_ADR_Payload_Payload, getStatus);
PHP_METHOD(Phalcon_ADR_Payload_Payload, withException);
PHP_METHOD(Phalcon_ADR_Payload_Payload, withExtras);
PHP_METHOD(Phalcon_ADR_Payload_Payload, withInput);
PHP_METHOD(Phalcon_ADR_Payload_Payload, withMessages);
PHP_METHOD(Phalcon_ADR_Payload_Payload, withResult);
PHP_METHOD(Phalcon_ADR_Payload_Payload, withStatus);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_accepted, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_authenticated, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_authorized, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_created, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_deleted, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_error, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_forbidden, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_found, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_invalid, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_notaccepted, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_notcreated, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_notdeleted, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_notfound, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_notupdated, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_processing, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_success, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_unauthenticated, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_updated, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_valid, 0, 0, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_getexception, 0, 0, Throwable, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_payload_payload_getextras, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_payload_payload_getinput, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_payload_payload_getmessages, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_payload_payload_getresult, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_payload_payload_getstatus, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_withexception, 0, 1, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_OBJ_INFO(0, exception, Throwable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_withextras, 0, 1, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, extras)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_withinput, 0, 1, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_withmessages, 0, 1, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_withresult, 0, 1, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_payload_payload_withstatus, 0, 1, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, status)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_payload_payload_method_entry) {
	PHP_ME(Phalcon_ADR_Payload_Payload, accepted, arginfo_phalcon_adr_payload_payload_accepted, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, authenticated, arginfo_phalcon_adr_payload_payload_authenticated, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, authorized, arginfo_phalcon_adr_payload_payload_authorized, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, created, arginfo_phalcon_adr_payload_payload_created, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, deleted, arginfo_phalcon_adr_payload_payload_deleted, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, error, arginfo_phalcon_adr_payload_payload_error, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, forbidden, arginfo_phalcon_adr_payload_payload_forbidden, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, found, arginfo_phalcon_adr_payload_payload_found, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, invalid, arginfo_phalcon_adr_payload_payload_invalid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, notAccepted, arginfo_phalcon_adr_payload_payload_notaccepted, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, notCreated, arginfo_phalcon_adr_payload_payload_notcreated, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, notDeleted, arginfo_phalcon_adr_payload_payload_notdeleted, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, notFound, arginfo_phalcon_adr_payload_payload_notfound, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, notUpdated, arginfo_phalcon_adr_payload_payload_notupdated, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, processing, arginfo_phalcon_adr_payload_payload_processing, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, success, arginfo_phalcon_adr_payload_payload_success, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, unauthenticated, arginfo_phalcon_adr_payload_payload_unauthenticated, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, updated, arginfo_phalcon_adr_payload_payload_updated, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, valid, arginfo_phalcon_adr_payload_payload_valid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, getException, arginfo_phalcon_adr_payload_payload_getexception, ZEND_ACC_PUBLIC)
PHP_ME(Phalcon_ADR_Payload_Payload, getExtras, arginfo_phalcon_adr_payload_payload_getextras, ZEND_ACC_PUBLIC)
PHP_ME(Phalcon_ADR_Payload_Payload, getInput, arginfo_phalcon_adr_payload_payload_getinput, ZEND_ACC_PUBLIC)
PHP_ME(Phalcon_ADR_Payload_Payload, getMessages, arginfo_phalcon_adr_payload_payload_getmessages, ZEND_ACC_PUBLIC)
PHP_ME(Phalcon_ADR_Payload_Payload, getResult, arginfo_phalcon_adr_payload_payload_getresult, ZEND_ACC_PUBLIC)
PHP_ME(Phalcon_ADR_Payload_Payload, getStatus, arginfo_phalcon_adr_payload_payload_getstatus, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, withException, arginfo_phalcon_adr_payload_payload_withexception, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, withExtras, arginfo_phalcon_adr_payload_payload_withextras, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, withInput, arginfo_phalcon_adr_payload_payload_withinput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, withMessages, arginfo_phalcon_adr_payload_payload_withmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, withResult, arginfo_phalcon_adr_payload_payload_withresult, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Payload_Payload, withStatus, arginfo_phalcon_adr_payload_payload_withstatus, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
