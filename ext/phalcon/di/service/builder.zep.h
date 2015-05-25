
extern zend_class_entry *phalcon_di_service_builder_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_Service_Builder);

PHP_METHOD(Phalcon_Di_Service_Builder, _buildParameter);
PHP_METHOD(Phalcon_Di_Service_Builder, _buildParameters);
PHP_METHOD(Phalcon_Di_Service_Builder, build);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_builder__buildparameter, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
	ZEND_ARG_INFO(0, position)
	ZEND_ARG_ARRAY_INFO(0, argument, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_builder__buildparameters, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_builder_build, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_service_builder_method_entry) {
	PHP_ME(Phalcon_Di_Service_Builder, _buildParameter, arginfo_phalcon_di_service_builder__buildparameter, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Di_Service_Builder, _buildParameters, arginfo_phalcon_di_service_builder__buildparameters, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Di_Service_Builder, build, arginfo_phalcon_di_service_builder_build, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
