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
use Phalcon\Crypt;
use Phalcon\Di\FactoryDefault\Cli as Di;
use Phalcon\Escaper;

class OffsetSetCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: offsetSet()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliOffsetSet(CliTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - offsetSet()');

        $di = new Di();

        $di->offsetSet('escaper', Escaper::class);

        $actual = $di->offsetGet('escaper');

        $I->assertInstanceOf(Escaper::class, $actual);

        $di['crypt'] = new Crypt();

        $actual = $di->offsetGet('crypt');

        $I->assertInstanceOf(Crypt::class, $actual);
    }
}
