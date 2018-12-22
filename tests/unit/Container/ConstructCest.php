<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Container;

use Phalcon\Container;
use Phalcon\Di;
use Psr\Container\ContainerInterface;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Container :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function containerConstruct(UnitTester $I)
    {
        $I->wantToTest('Container - __construct()');

        $container = new Di();
        $class     = ContainerInterface::class;
        $actual    = new Container($container);
        $I->assertInstanceOf($class, $actual);
    }
}
