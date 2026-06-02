
extern zend_class_entry *phalcon_container_provider_cli_ce;

ZEPHIR_INIT_CLASS(Phalcon_Container_Provider_Cli);

PHP_METHOD(Phalcon_Container_Provider_Cli, provide);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_provider_cli_provide, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, services, Phalcon\\Contracts\\Container\\Service\\Collection, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_container_provider_cli_method_entry) {
	PHP_ME(Phalcon_Container_Provider_Cli, provide, arginfo_phalcon_container_provider_cli_provide, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
