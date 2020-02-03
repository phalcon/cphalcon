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

namespace Phalcon\Test\Unit\Container;

use Phalcon\Container;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class HasCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Container :: has()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function containerHas(UnitTester $I)
    {
        $I->wantToTest('Container - has()');

        $this->newDi();
        $this->setDiService('filter');

        $container = new Container($this->container);

        $I->assertTrue(
            $container->has('filter')
        );
    }
}
