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

namespace Phalcon\Test\Unit\Di\FactoryDefault;

use Phalcon\Di\FactoryDefault;
use Phalcon\Di\Service;
use Phalcon\Escaper;
use UnitTester;

class SetServiceCest
{
    /**
     * Unit Tests Phalcon\Di\FactoryDefault :: setService()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diFactoryDefaultSetRaw(UnitTester $I)
    {
        $I->wantToTest('Di\FactoryDefault - setService()');

        $di = new FactoryDefault();

        $expected = new Service(Escaper::class);

        $actual = $di->setService('escaper', $expected);

        $I->assertSame($expected, $actual);
    }
}
