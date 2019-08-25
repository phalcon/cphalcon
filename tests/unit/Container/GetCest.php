<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
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

class GetCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Container :: get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function containerGet(UnitTester $I)
    {
        $I->wantToTest('Container - get()');

        $this->newDi();
        $this->setDiEscaper();

        $container = new Container($this->container);

        /** @var Service $service */
        $service = $container->get('escaper');

        $I->assertEquals(
            Escaper::class,
            $service->getDefinition()
        );
    }
}
