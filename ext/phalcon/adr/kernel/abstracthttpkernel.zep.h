
extern zend_class_entry *phalcon_adr_kernel_abstracthttpkernel_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Kernel_AbstractHttpKernel);

PHP_METHOD(Phalcon_ADR_Kernel_AbstractHttpKernel, __construct);
PHP_METHOD(Phalcon_ADR_Kernel_AbstractHttpKernel, run);
PHP_METHOD(Phalcon_ADR_Kernel_AbstractHttpKernel, buildContainer);
PHP_METHOD(Phalcon_ADR_Kernel_AbstractHttpKernel, handleBootError);
PHP_METHOD(Phalcon_ADR_Kernel_AbstractHttpKernel, loadEnvironment);
PHP_METHOD(Phalcon_ADR_Kernel_AbstractHttpKernel, registerProviders);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_kernel_abstracthttpkernel___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, projectRoot, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_kernel_abstracthttpkernel_run, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_adr_kernel_abstracthttpkernel_buildcontainer, 0, 0, Phalcon\\Container\\Container, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_kernel_abstracthttpkernel_handlebooterror, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, exception, Throwable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_kernel_abstracthttpkernel_loadenvironment, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Container\\Container, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_kernel_abstracthttpkernel_registerproviders, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Container\\Container, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_kernel_abstracthttpkernel_method_entry) {
	PHP_ME(Phalcon_ADR_Kernel_AbstractHttpKernel, __construct, arginfo_phalcon_adr_kernel_abstracthttpkernel___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ADR_Kernel_AbstractHttpKernel, run, arginfo_phalcon_adr_kernel_abstracthttpkernel_run, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Kernel_AbstractHttpKernel, buildContainer, arginfo_phalcon_adr_kernel_abstracthttpkernel_buildcontainer, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Kernel_AbstractHttpKernel, handleBootError, arginfo_phalcon_adr_kernel_abstracthttpkernel_handlebooterror, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Kernel_AbstractHttpKernel, loadEnvironment, arginfo_phalcon_adr_kernel_abstracthttpkernel_loadenvironment, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_ADR_Kernel_AbstractHttpKernel, registerProviders, arginfo_phalcon_adr_kernel_abstracthttpkernel_registerproviders, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
