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
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

/**
 * Class HasCest
 */
class HasCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Container :: has()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function containerHas(UnitTester $I)
    {
        $I->wantToTest('Container - has()');
        $this->newDi();
        $this->setDiFilter();

        $container = new Container($this->container);

        $actual = $container->has('filter');
        $I->assertTrue($actual);
    }
}
