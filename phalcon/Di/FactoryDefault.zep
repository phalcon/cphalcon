
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di;

use Phalcon\Filter\FilterFactory;

/**
 * This is a variant of the standard Phalcon\Di. By default it automatically
 * registers all the services provided by the framework. Thanks to this, the
 * developer does not need to register each service individually providing a
 * full stack framework
 */
class FactoryDefault extends \Phalcon\Di
{
    /**
     * Phalcon\Di\FactoryDefault constructor
     */
    public function __construct(<AutowireInterface> autowire = null, bool addBinds = false)
    {
        var filter;

        parent::__construct(autowire);

        let filter = new FilterFactory();

        let this->services = [
            "annotations":        new Service("Phalcon\\Annotations\\Adapter\\Memory", true),
            "assets":             new Service("Phalcon\\Assets\\Manager", true),
            "crypt":              new Service("Phalcon\\Crypt", true),
            "cookies":            new Service("Phalcon\\Http\\Response\\Cookies", true),
            "dispatcher":         new Service("Phalcon\\Mvc\\Dispatcher", true),
            "escaper":            new Service("Phalcon\\Escaper", true),
            "eventsManager":      new Service("Phalcon\\Events\\Manager", true),
            "flash":              new Service("Phalcon\\Flash\\Direct", true),
            "flashSession":       new Service("Phalcon\\Flash\\Session", true),
            "filter":             new Service(filter->newInstance(), true),
            "modelsManager":      new Service("Phalcon\\Mvc\\Model\\Manager", true),
            "modelsMetadata":     new Service("Phalcon\\Mvc\\Model\\MetaData\\Memory", true),
            "request":            new Service("Phalcon\\Http\\Request", true),
            "response":           new Service("Phalcon\\Http\\Response", true),
            "router":             new Service("Phalcon\\Mvc\\Router", true),
            "security":           new Service("Phalcon\\Security", true),
            "tag":                new Service("Phalcon\\Tag", true),
            "transactionManager": new Service("Phalcon\\Mvc\\Model\\Transaction\\Manager", true),
            "url":                new Service("Phalcon\\Url", true)
        ];

        if autowire != null && addBinds {
            autowire->addBinds([
                "Phalcon\\Annotations\\Adapter\\Memory": "annotations",
                "Phalcon\\Assets\\Manager": "assets",
                "Phalcon\\Crypt": "crypt",
                "Phalcon\\Http\\Response\\Cookies": "cookies",
                "Phalcon\\Mvc\\Dispatcher": "dispatcher",
                "Phalcon\\Escaper": "escaper",
                "Phalcon\\Events\\Manager": "eventsManager",
                "Phalcon\\Flash\\Direct": "flash",
                "Phalcon\\Flash\\Session": "flashSession",
                "Phalcon\\Mvc\\Model\\Manager": "modelsManager",
                "Phalcon\\Mvc\\Model\\MetaData\\Memory": "modelsMetadata",
                "Phalcon\\Http\\Request": "request",
                "Phalcon\\Http\\Response": "response",
                "Phalcon\\Mvc\\Router": "router",
                "Phalcon\\Security": "security",
                "Phalcon\\Tag": "tag",
                "Phalcon\\Mvc\\Model\\Transaction\\Manager": "transactionManager",
                "Phalcon\\Url": "url",
                "Phalcon\\Filter": "filter"
            ]);
        }
    }
}
