
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Router;

use Phalcon\Config\ConfigInterface;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\Router\Exceptions\InvalidRouterFactoryConfig;
use Phalcon\Mvc\RouterInterface;

/**
 * Phalcon\Mvc\Router\RouterFactory
 *
 * Builds a Router from an array or ConfigInterface and loads routes via
 * Router::loadFromConfig.
 *
 *```php
 * use Phalcon\Mvc\Router\RouterFactory;
 *
 * $router = (new RouterFactory())->load(
 *     [
 *         "defaultRoutes" : false,
 *         "routes" : [
 *             ["method" : "get", "pattern" : "/users", "paths" : "Users::index"]
 *         ]
 *     ]
 * );
 *```
 */
class RouterFactory
{
    /**
     * Builds a Router from a config array or ConfigInterface and loads routes.
     *
     * @param array|\Phalcon\Config\ConfigInterface config
     *
     * @return RouterInterface
     */
    public function load(var config) -> <RouterInterface>
    {
        var defaultRoutes, router;

        if typeof config === "object" {
            if !(config instanceof ConfigInterface) {
                throw new InvalidRouterFactoryConfig();
            }
            let config = config->toArray();
        }

        if typeof config !== "array" {
            throw new InvalidRouterFactoryConfig();
        }

        let defaultRoutes = true;
        if isset config["defaultRoutes"] {
            let defaultRoutes = (bool) config["defaultRoutes"];
        }

        let router = this->newInstance(defaultRoutes);
        router->loadFromConfig(config);

        return router;
    }

    /**
     * Returns a bare Router instance.
     *
     * @param bool defaultRoutes
     *
     * @return RouterInterface
     */
    public function newInstance(bool defaultRoutes = true) -> <RouterInterface>
    {
        return new Router(defaultRoutes);
    }
}
