
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"


/**
 * Loads Annotations Adapter class using 'adapter' option
 *
 *<code>
 * use Phalcon\Annotations\Factory;
 *
 * $options = [
 *     "prefix"   => "annotations",
 *     "lifetime" => "3600",
 *     "adapter"  => "apc",
 * ];
 * $annotations = Factory::load($options);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Factory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Annotations, Factory, phalcon, annotations_factory, phalcon_factory_ce, phalcon_annotations_factory_method_entry, 0);

	return SUCCESS;

}

/**
 * @param \Phalcon\Config|array config
 */
PHP_METHOD(Phalcon_Annotations_Factory, load) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Phalcon\\Annotations\\Adapter", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("loadclass", NULL, 0, _0, config);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

