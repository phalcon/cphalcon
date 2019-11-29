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

namespace Phalcon\Test\Cli\Di\FactoryDefault\Cli;

use CliTester;
use Phalcon\Di;
use Phalcon\Di\Service;
use Phalcon\Escaper;

class SetRawCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: setRaw()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliSetRaw(CliTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - setRaw()');

        $di = new Di();

        $expected = new Service(Escaper::class);

        $actual = $di->setService('escaper', $expected);

        $I->assertSame($expected, $actual);
    }
}
