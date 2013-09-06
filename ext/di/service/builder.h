
extern zend_class_entry *phalcon_di_service_builder_ce;

ZEPHIR_INIT_CLASS(Phalcon_DI_Service_Builder);

PHP_METHOD(Phalcon_DI_Service_Builder, _buildParameter);
PHP_METHOD(Phalcon_DI_Service_Builder, _buildParameters);
PHP_METHOD(Phalcon_DI_Service_Builder, build);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_builder__buildParameter, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
	ZEND_ARG_INFO(0, position)
	ZEND_ARG_INFO(0, argument)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_builder__buildParameters, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_builder_build, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_service_builder_method_entry) {
	PHP_ME(Phalcon_DI_Service_Builder, _buildParameter, arginfo_phalcon_di_service_builder__buildParameter, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_DI_Service_Builder, _buildParameters, arginfo_phalcon_di_service_builder__buildParameters, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_DI_Service_Builder, build, arginfo_phalcon_di_service_builder_build, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
