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

namespace Phalcon\Tests\Unit\Container;

use Phalcon\Container\Container;
use Phalcon\Di\Di;
use Psr\Container\ContainerInterface;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Container :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function containerConstruct(UnitTester $I)
    {
        $I->wantToTest('Container - __construct()');

        $container = new Di();
        $actual    = new Container($container);

        $I->assertInstanceOf(ContainerInterface::class, $actual);
    }
}
