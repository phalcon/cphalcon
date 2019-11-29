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

namespace Phalcon\Test\Unit\Di\FactoryDefault;

use Phalcon\Di\FactoryDefault\Cli;
use Phalcon\Di\Service;
use Phalcon\Escaper;
use UnitTester;

class SetRawCest
{
    /**
     * Unit Tests Phalcon\Di\FactoryDefault :: setRaw()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diFactoryDefaultSetRaw(UnitTester $I)
    {
        $I->wantToTest('Di\FactoryDefault - setRaw()');


        $di = new Cli();

        $expected = new Service(Escaper::class);

        $actual = $di->setService('escaper', $expected);

        $I->assertSame($expected, $actual);
    }
}
