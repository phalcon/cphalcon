
extern zend_class_entry *phalcon_mvc_application_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Application);

PHP_METHOD(Phalcon_Mvc_Application, handle);
PHP_METHOD(Phalcon_Mvc_Application, sendCookiesOnHandleRequest);
PHP_METHOD(Phalcon_Mvc_Application, sendHeadersOnHandleRequest);
PHP_METHOD(Phalcon_Mvc_Application, useImplicitView);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_application_handle, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_application_sendcookiesonhandlerequest, 0, 1, Phalcon\\Mvc\\Application, 0)
	ZEND_ARG_TYPE_INFO(0, sendCookies, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_application_sendheadersonhandlerequest, 0, 1, Phalcon\\Mvc\\Application, 0)
	ZEND_ARG_TYPE_INFO(0, sendHeaders, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_application_useimplicitview, 0, 1, Phalcon\\Mvc\\Application, 0)
	ZEND_ARG_TYPE_INFO(0, implicitView, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_application_method_entry) {
	PHP_ME(Phalcon_Mvc_Application, handle, arginfo_phalcon_mvc_application_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Application, sendCookiesOnHandleRequest, arginfo_phalcon_mvc_application_sendcookiesonhandlerequest, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Application, sendHeadersOnHandleRequest, arginfo_phalcon_mvc_application_sendheadersonhandlerequest, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Application, useImplicitView, arginfo_phalcon_mvc_application_useimplicitview, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
