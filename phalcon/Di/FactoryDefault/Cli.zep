
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di\FactoryDefault;

use Phalcon\Annotations\Adapter\Memory as AnnotationsMemory;
use Phalcon\Cli\Dispatcher;
use Phalcon\Cli\Router;
use Phalcon\Di\FactoryDefault;
use Phalcon\Di\Service;
use Phalcon\Encryption\Security;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Filter\FilterFactory;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Mvc\Model\Manager as ModelManager;
use Phalcon\Mvc\Model\MetaData\Memory as ModelMetaDataMemory;
use Phalcon\Mvc\Model\Transaction\Manager as TransactionManager;
use Phalcon\Queue\QueueFactory;
use Phalcon\Support\HelperFactory;
use Phalcon\Support\Settings;

 /**
 * Phalcon\Di\FactoryDefault\Cli
 *
 * This is a variant of the standard Phalcon\Di. By default it automatically
 * registers all the services provided by the framework.
 * Thanks to this, the developer does not need to register each service individually.
 * This class is specially suitable for CLI applications
 */
class Cli extends FactoryDefault
{
    /**
     * Phalcon\Di\FactoryDefault\Cli constructor
     */
    public function __construct()
    {
        var filter;

        parent::__construct();

        let filter = new FilterFactory();

        let this->services = [
            "annotations":        new Service(AnnotationsMemory::class, true),
            "dispatcher":         new Service(Dispatcher::class, true),
            "escaper":            new Service(Escaper::class, true),
            "eventsManager":      new Service(EventsManager::class, true),
            "filter":             new Service(filter->newInstance(), true),
            "helper":             new Service(HelperFactory::class, true),
            "settings":           new Service(Settings::class, true),
            "modelsManager":      new Service(ModelManager::class, true),
            "modelsMetadata":     new Service(ModelMetaDataMemory::class, true),
            "queueFactory":       new Service(QueueFactory::class, true),
            "router":             new Service(Router::class, true),
            "security":           new Service(Security::class, true),
            "tag"                : new Service(
                [
                    "className" : TagFactory::class,
                    "arguments" : [
                        [
                            "type" : "service",
                            "name" : "escaper"
                        ]
                    ]
                ],
                true
            ),
            "transactionManager": new Service(TransactionManager::class, true)
        ];
    }
}
