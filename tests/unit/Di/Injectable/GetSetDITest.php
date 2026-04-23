<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Di\Injectable;

use Phalcon\Di\Di;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Di\InjectableComponent;

final class GetSetDITest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiInjectableGetDI(): void
    {
        Di::reset();
        $container = new Di();
        $component = new InjectableComponent();
        $component->setDI($container);

        $actual = $component->getDI();
        $this->assertSame($container, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiInjectableGetDIConstructor(): void
    {
        Di::reset();
        $container = new Di();
        $container->set('component', InjectableComponent::class);
        $component = $container->get('component');
        $actual    = $component->getDI();
        $this->assertSame($container, $actual);
    }
}
