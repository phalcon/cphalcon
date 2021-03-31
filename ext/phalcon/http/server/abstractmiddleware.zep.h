
extern zend_class_entry *phalcon_http_server_abstractmiddleware_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Server_AbstractMiddleware);

PHP_METHOD(Phalcon_Http_Server_AbstractMiddleware, process);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_server_abstractmiddleware_process, 0, 2, Psr\\Http\\Message\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, request, Psr\\Http\\Message\\ServerRequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, handler, Psr\\Http\\Server\\RequestHandlerInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_server_abstractmiddleware_method_entry) {
	PHP_ME(Phalcon_Http_Server_AbstractMiddleware, process, arginfo_phalcon_http_server_abstractmiddleware_process, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
