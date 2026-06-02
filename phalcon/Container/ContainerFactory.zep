
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been heavily influenced by CapsulePHP.
 * Additionally, there are implementations from ioc-interop, which is a
 * Composer dependency, and from service-interop and resolver-interop. The
 * latter two are copied and re-implemented here: service-interop is not yet
 * published on Packagist, and resolver-interop requires PHP 8.4 (this project
 * targets PHP 8.1). Once both packages become available and compatible, the
 * copies will be replaced with the actual Composer dependencies.
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

namespace Phalcon\Container;

use Phalcon\Contracts\Container\Ioc\IocContainerFactory;
use Phalcon\Contracts\Container\Service\Provider;

class ContainerFactory implements IocContainerFactory
{
    /**
     * @var array<array-key, Provider>
     */
    protected providers = [];

    /**
     * Adds a provider
     *
     * @param Provider $provider
     *
     * @return static
     */
    public function addProvider(<Provider> provider) -> <static>
    {
        let this->providers[] = provider;

        return this;
    }

    /**
     * Returns a new container
     *
     * @return Container
     */
    public function newContainer() -> <Container>
    {
        var container, provider;

        let container = new Container();

        for provider in this->providers {
            provider->provide(container);
        }

        return container;
    }
}
