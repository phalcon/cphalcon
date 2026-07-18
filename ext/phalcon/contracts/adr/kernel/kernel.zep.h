
extern zend_class_entry *phalcon_contracts_adr_kernel_kernel_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Kernel_Kernel);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_adr_kernel_kernel_run, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_adr_kernel_kernel_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Kernel_Kernel, run, arginfo_phalcon_contracts_adr_kernel_kernel_run)
	PHP_FE_END
};
