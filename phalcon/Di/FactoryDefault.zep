
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
 * This is a variant of the standard Phalcon\Di\Di. By default it automatically
 * registers all the services provided by the framework. Thanks to this, the
 * developer does not need to register each service individually providing a
 * full stack framework
 */
class FactoryDefault extends \Phalcon\Di\Di
{
    /**
     * Phalcon\Di\FactoryDefault constructor
     */
    public function __construct()
    {
        var filter;

        parent::__construct();

        let filter = new FilterFactory();

        let this->services = [
            "annotations"        : new Service("Phalcon\\Annotations\\Adapter\\Memory", true),
            "crypt"              : new Service("Phalcon\\Encryption\\Crypt", true),
            "cookies"            : new Service("Phalcon\\Http\\Response\\Cookies", true),
            "dispatcher"         : new Service("Phalcon\\Mvc\\Dispatcher", true),
            "escaper"            : new Service("Phalcon\\Html\\Escaper", true),
            "eventsManager"      : new Service("Phalcon\\Events\\Manager", true),
            "flash"              : new Service("Phalcon\\Flash\\Direct", true),
            "flashSession"       : new Service("Phalcon\\Flash\\Session", true),
            "filter"             : new Service(filter->newInstance(), true),
            "helper"             : new Service("Phalcon\\Support\\HelperFactory", true),
            "modelsManager"      : new Service("Phalcon\\Mvc\\Model\\Manager", true),
            "modelsMetadata"     : new Service("Phalcon\\Mvc\\Model\\MetaData\\Memory", true),
            "request"            : new Service("Phalcon\\Http\\Request", true),
            "response"           : new Service("Phalcon\\Http\\Response", true),
            "router"             : new Service("Phalcon\\Mvc\\Router", true),
            "security"           : new Service("Phalcon\\Encryption\\Security", true),
            "transactionManager" : new Service("Phalcon\\Mvc\\Model\\Transaction\\Manager", true),
            "url"                : new Service("Phalcon\\Mvc\\Url", true)
        ];

        this->set(
            "assets",
            [
                "className" : "Phalcon\\Assets\\Manager",
                "arguments" : [
                    [
                        "type" : "service",
                        "name" : "tag"
                    ]
                ]
            ]
        );

        this->set(
            "tag",
            [
                "className" : "Phalcon\\Html\\TagFactory",
                "arguments" : [
                    [
                        "type" : "service",
                        "name" : "escaper"
                    ]
                ]
            ]
        );
    }
}
