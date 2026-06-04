<?php

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

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container;

use Phalcon\Container\Container;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Container\Fake\InjectionAwareComponent;
use stdClass;

final class ContainerAutoInjectTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-19
     */
    public function testResolveCallsSetDiOnInjectionAwareInstances(): void
    {
        $this->markTestSkipped('Enable after setDI is addressed');

        $container = new Container();
        $container->set(InjectionAwareComponent::class, InjectionAwareComponent::class);

        $component = $container->get(InjectionAwareComponent::class);

        // Container must have injected itself - no Di involved
        $this->assertSame($container, $component->getDI());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-19
     */
    public function testNonInjectionAwareInstancesAreUnaffected(): void
    {
        $container = new Container();
        $container->set('stdClass', stdClass::class);

        // Must not throw - stdClass does not implement InjectionAwareInterface
        $obj = $container->get('stdClass');
        $this->assertInstanceOf(stdClass::class, $obj);
    }
}
