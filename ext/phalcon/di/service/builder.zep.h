
extern zend_class_entry *phalcon_di_service_builder_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_Service_Builder);

PHP_METHOD(Phalcon_Di_Service_Builder, build);
PHP_METHOD(Phalcon_Di_Service_Builder, buildParameter);
PHP_METHOD(Phalcon_Di_Service_Builder, buildParameters);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_builder_build, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_builder_buildparameter, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, argument, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_service_builder_buildparameters, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_service_builder_method_entry) {
	PHP_ME(Phalcon_Di_Service_Builder, build, arginfo_phalcon_di_service_builder_build, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Service_Builder, buildParameter, arginfo_phalcon_di_service_builder_buildparameter, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Di_Service_Builder, buildParameters, arginfo_phalcon_di_service_builder_buildparameters, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
