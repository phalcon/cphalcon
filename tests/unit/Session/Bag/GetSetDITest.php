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

namespace Phalcon\Tests\Unit\Session\Bag;

use Phalcon\Di\FactoryDefault;
use Phalcon\Session\Bag;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class GetSetDITest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSessionBagGetSetDI(): void
    {
        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
        $session   = $this->container->get('session');
        $container = $this->container;

        $bag    = new Bag($session, 'DiTest');
        $actual = $bag->getDI();
        $this->assertSame($container, $actual);

        $container = new FactoryDefault();
        $bag->setDI($container);

        $actual = $bag->getDI();
        $this->assertSame($container, $actual);
    }
}
