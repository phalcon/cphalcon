
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

namespace Phalcon\Container;

use Phalcon\Container\Container;
use Phalcon\Container\Interop\Ioc\IocContainerFactory;
use Phalcon\Container\Interop\Service\Provider;

class ContainerFactory implements IocContainerFactory
{
    /**
     * @var array
     */
    protected providers = [];

    public function addProvider(<Provider> provider) -> <ContainerFactory>
    {
        let this->providers[] = provider;

        return this;
    }

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
