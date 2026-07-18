
extern zend_class_entry *phalcon_adr_pipeline_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Pipeline);

PHP_METHOD(Phalcon_ADR_Pipeline, __construct);
PHP_METHOD(Phalcon_ADR_Pipeline, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_pipeline___construct, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, middleware, 0)
	ZEND_ARG_OBJ_INFO(0, terminal, Phalcon\\Contracts\\ADR\\Handler, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, index, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_pipeline___invoke, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Contracts\\Http\\AttributeRequestInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_pipeline_method_entry) {
	PHP_ME(Phalcon_ADR_Pipeline, __construct, arginfo_phalcon_adr_pipeline___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ADR_Pipeline, __invoke, arginfo_phalcon_adr_pipeline___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
