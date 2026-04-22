
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been heavily influenced by CapsulePHP.
 * Additionally, there are implementations from ioc-interop, service-interop
 * and resolver-interop. These have been copied and implemented here since
 * PHP extensions cannot have more than one namespace.
 *
 * @link    https://github.com/capsulephp/di
 * @license https://github.com/capsulephp/di/blob/3.x/LICENSE.md
 *
 * @link    https://github.com/ioc-interop/interface
 * @license https://github.com/ioc-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/service-interop/interface
 * @license https://github.com/service-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/resolver-interop/interface/tree/1.x
 * @license https://github.com/resolver-interop/interface/blob/1.x/LICENSE.md
 */

namespace Phalcon\Container\Provider;

use Phalcon\Container\Definition\ServiceDefinition;
use Phalcon\Container\Exception\Invalid;
use Phalcon\Container\Interop\Service\Collection;
use Phalcon\Container\Interop\Service\Provider;
use Phalcon\Container\Resolver\Lazy\LazyFactory;

class Web implements Provider
{
    public function provide(<Collection> services) -> void
    {
        services->bind(
            "Phalcon\\Http\\Response\\CookiesInterface",
            "Phalcon\\Http\\Response\\Cookies"
        );
        services->setAlias("Phalcon\\Http\\Response\\CookiesInterface", "cookies");

        services->bind(
            "Phalcon\\Encryption\\Crypt\\CryptInterface",
            "Phalcon\\Encryption\\Crypt"
        );
        services->setAlias("Phalcon\\Encryption\\Crypt\\CryptInterface", "crypt");

        services->bind(
            "Phalcon\\Mvc\\DispatcherInterface",
            "Phalcon\\Mvc\\Dispatcher"
        );
        services->setAlias("Phalcon\\Mvc\\DispatcherInterface", "dispatcher");

        services->bind(
            "Phalcon\\Html\\Escaper\\EscaperInterface",
            "Phalcon\\Html\\Escaper"
        );
        services->setAlias("Phalcon\\Html\\Escaper\\EscaperInterface", "escaper");

        services->bind(
            "Phalcon\\Events\\ManagerInterface",
            "Phalcon\\Events\\Manager"
        );
        services->setAlias("Phalcon\\Events\\ManagerInterface", "eventsManager");

        services->set(
            "Phalcon\\Filter\\FilterInterface",
            function (c) {
                return (new \Phalcon\Filter\FilterFactory())->newInstance();
            }
        );
        services->setAlias("Phalcon\\Filter\\FilterInterface", "filter");

        services->bind(
            "Phalcon\\Mvc\\Model\\ManagerInterface",
            "Phalcon\\Mvc\\Model\\Manager"
        );
        services->setAlias("Phalcon\\Mvc\\Model\\ManagerInterface", "modelsManager");

        services->bind(
            "Phalcon\\Mvc\\Model\\MetaDataInterface",
            "Phalcon\\Mvc\\Model\\MetaData\\Memory"
        );
        services->setAlias("Phalcon\\Mvc\\Model\\MetaDataInterface", "modelsMetadata");

        services->bind(
            "Phalcon\\Http\\RequestInterface",
            "Phalcon\\Http\\Request"
        );
        services->setAlias("Phalcon\\Http\\RequestInterface", "request");

        services->bind(
            "Phalcon\\Http\\ResponseInterface",
            "Phalcon\\Http\\Response"
        );
        services->setAlias("Phalcon\\Http\\ResponseInterface", "response");

        services->bind(
            "Phalcon\\Mvc\\RouterInterface",
            "Phalcon\\Mvc\\Router"
        );
        services->setAlias("Phalcon\\Mvc\\RouterInterface", "router");

        services->bind(
            "Phalcon\\Mvc\\Model\\Transaction\\ManagerInterface",
            "Phalcon\\Mvc\\Model\\Transaction\\Manager"
        );
        services->setAlias("Phalcon\\Mvc\\Model\\Transaction\\ManagerInterface", "transactionManager");

        services->bind(
            "Phalcon\\Mvc\\Url\\UrlInterface",
            "Phalcon\\Mvc\\Url"
        );
        services->setAlias("Phalcon\\Mvc\\Url\\UrlInterface", "url");

        services->set("Phalcon\\Annotations\\Annotations", "Phalcon\\Annotations\\Annotations")
            ->setArgument(0, LazyFactory::get("Phalcon\\Annotations\\Adapter\\Memory"));
        services->setAlias("Phalcon\\Annotations\\Annotations", "annotations");

        services->set("Phalcon\\Annotations\\Adapter\\Memory", "Phalcon\\Annotations\\Adapter\\Memory")
            ->setArgument(0, LazyFactory::get("Phalcon\\Storage\\SerializerFactory"));
        services->setAlias("Phalcon\\Annotations\\Adapter\\Memory", "annotationsMemory");

        services->set("Phalcon\\Assets\\Manager", "Phalcon\\Assets\\Manager")
            ->setArgument(0, LazyFactory::get("Phalcon\\Html\\TagFactory"));
        services->setAlias("Phalcon\\Assets\\Manager", "assets");

        services->set("Phalcon\\Db\\Event\\Factory", "Phalcon\\Db\\Event\\Factory");
        services->setAlias("Phalcon\\Db\\Event\\Factory", "modelsEventFactory");

        services->set("Phalcon\\Flash\\Direct", "Phalcon\\Flash\\Direct");
        services->setAlias("Phalcon\\Flash\\Direct", "flash");

        services->set("Phalcon\\Support\\HelperFactory", "Phalcon\\Support\\HelperFactory");
        services->setAlias("Phalcon\\Support\\HelperFactory", "helper");

        services->set("Phalcon\\Encryption\\Security", "Phalcon\\Encryption\\Security");
        services->setAlias("Phalcon\\Encryption\\Security", "security");

        services->set("Phalcon\\Storage\\SerializerFactory", "Phalcon\\Storage\\SerializerFactory");
        services->setAlias("Phalcon\\Storage\\SerializerFactory", "storageSerializer");

        services->set("Phalcon\\Flash\\Session", "Phalcon\\Flash\\Session");
        services->setAlias("Phalcon\\Flash\\Session", "flashSession");

        services->set("Phalcon\\Support\\Settings", "Phalcon\\Support\\Settings");
        services->setAlias("Phalcon\\Support\\Settings", "settings");

        services->set("Phalcon\\Html\\TagFactory", "Phalcon\\Html\\TagFactory")
            ->setArgument(0, LazyFactory::get("Phalcon\\Html\\Escaper\\EscaperInterface"));
        services->setAlias("Phalcon\\Html\\TagFactory", "tag");
    }
}
