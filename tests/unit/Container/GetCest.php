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

use Phalcon\Container;
use Phalcon\Escaper;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use UnitTester;

use function spl_object_hash;

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

        $escaper = new Escaper();
        $this->container->setShared('test', $escaper);
        $this->setDiService('escaper');

        $container        = new Container($this->container);
        $containerEscaper = $container->get('test');

        $I->assertInstanceOf(Escaper::class, $containerEscaper);

        $diEscaper = $this->container->getShared('test');

        $expected = spl_object_hash($escaper);
        $actual   = spl_object_hash($diEscaper);
        $I->assertEquals($expected, $actual);

        $expected = spl_object_hash($diEscaper);
        $actual   = spl_object_hash($containerEscaper);
        $I->assertEquals($expected, $actual);
    }
}
