
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Di\InjectionAwareInterface
 *
 * This interface must be implemented in those classes that uses internally the Phalcon\Di that creates them
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_InjectionAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Di, InjectionAwareInterface, phalcon, di_injectionawareinterface, phalcon_di_injectionawareinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the dependency injector
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_InjectionAwareInterface, setDI);

/**
 * Returns the internal dependency injector
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_InjectionAwareInterface, getDI);

