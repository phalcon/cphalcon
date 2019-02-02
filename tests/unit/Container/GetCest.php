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
use Phalcon\Di\Service;
use Phalcon\Escaper;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

/**
 * Class GetCest
 */
class GetCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Container :: get()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function containerGet(UnitTester $I)
    {
        $I->wantToTest('Container - get()');
        $this->newDi();
        $this->setDiEscaper();

        $container = new Container($this->container);

        /** @var Service $service */
        $service  = $container->get('escaper');
        $expected = Escaper::class;
        $actual   = $service->getDefinition();
        $I->assertEquals($expected, $actual);
    }
}
