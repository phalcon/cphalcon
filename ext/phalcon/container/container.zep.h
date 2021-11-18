
extern zend_class_entry *phalcon_container_container_ce;

ZEPHIR_INIT_CLASS(Phalcon_Container_Container);

PHP_METHOD(Phalcon_Container_Container, __construct);
PHP_METHOD(Phalcon_Container_Container, get);
PHP_METHOD(Phalcon_Container_Container, has);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_container_container___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_container_container_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_container_container_method_entry) {
	PHP_ME(Phalcon_Container_Container, __construct, arginfo_phalcon_container_container___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Container_Container, get, arginfo_phalcon_container_container_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, has, arginfo_phalcon_container_container_has, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
