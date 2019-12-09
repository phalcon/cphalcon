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

namespace Phalcon\Test\Cli\Di\FactoryDefault\Cli;

use CliTester;
use Phalcon\Di\FactoryDefault\Cli;
use Phalcon\Di\Service;
use Phalcon\Escaper;

class SetServiceCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: setService()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliSetRaw(CliTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - setService()');

        $di = new Cli();

        $expected = new Service(Escaper::class);

        $actual = $di->setService('escaper', $expected);

        $I->assertSame($expected, $actual);
    }
}
