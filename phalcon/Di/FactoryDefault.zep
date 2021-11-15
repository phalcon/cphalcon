
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di;

use Phalcon\Assets\Manager as AssetManager;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
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
    public function __construct()
    {
        var assets, escaper, filter, tagFactory;

        parent::__construct();

        let escaper    = new Escaper(),
            filter     = new FilterFactory(),
            tagFactory = new TagFactory(escaper),
            assets     = new AssetManager(tagFactory);

        let this->services = [
            "annotations":        new Service("Phalcon\\Annotations\\Adapter\\Memory", true),
            "assets":             new Service(assets, true),
            "crypt":              new Service("Phalcon\\Encryption\\Crypt", true),
            "cookies":            new Service("Phalcon\\Http\\Response\\Cookies", true),
            "dispatcher":         new Service("Phalcon\\Mvc\\Dispatcher", true),
            "escaper":            new Service(escaper, true),
            "eventsManager":      new Service("Phalcon\\Events\\Manager", true),
            "flash":              new Service("Phalcon\\Flash\\Direct", true),
            "flashSession":       new Service("Phalcon\\Flash\\Session", true),
            "filter":             new Service(filter->newInstance(), true),
            "helper":             new Service("Phalcon\\Support\\HelperFactory", true),
            "modelsManager":      new Service("Phalcon\\Mvc\\Model\\Manager", true),
            "modelsMetadata":     new Service("Phalcon\\Mvc\\Model\\MetaData\\Memory", true),
            "request":            new Service("Phalcon\\Http\\Request", true),
            "response":           new Service("Phalcon\\Http\\Response", true),
            "router":             new Service("Phalcon\\Mvc\\Router", true),
            "security":           new Service("Phalcon\\Encryption\\Security", true),
            "tag":                new Service("Phalcon\\Tag", true),
            "transactionManager": new Service("Phalcon\\Mvc\\Model\\Transaction\\Manager", true),
            "url":                new Service("Phalcon\\Url", true)
        ];
    }
}
