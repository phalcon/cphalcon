
extern zend_class_entry *phalcon_http_server_middleware_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Server_Middleware);

PHP_METHOD(Phalcon_Http_Server_Middleware, process);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_server_middleware_process, 0, 2, Psr\\Http\\Message\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_server_middleware_process, 0, 2, IS_OBJECT, "Psr\\Http\\Message\\ResponseInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, request, Psr\\Http\\Message\\ServerRequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, handler, Phalcon\\Http\\Server\\RequestHandlerInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_server_middleware_method_entry) {
	PHP_ME(Phalcon_Http_Server_Middleware, process, arginfo_phalcon_http_server_middleware_process, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
