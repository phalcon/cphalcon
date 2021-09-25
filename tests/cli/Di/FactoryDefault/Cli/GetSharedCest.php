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

namespace Phalcon\Tests\Cli\Di\FactoryDefault\Cli;

use CliTester;
use Phalcon\Crypt;
use Phalcon\Di\FactoryDefault\Cli as Di;
use Phalcon\Escaper;

class GetSharedCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: getShared()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliGetShared(CliTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - getShared()');

        $di = new Di();

        // check non shared service
        $di->set('escaper', Escaper::class);
        $actual = $di->getShared('escaper');

        $I->assertInstanceOf(Escaper::class, $actual);

        $expected = new Escaper();
        $I->assertEquals($expected, $actual);

        // check shared service
        $di->set('crypt', Crypt::class, true);
        $actual = $di->getShared('crypt');

        $I->assertInstanceOf(Crypt::class, $actual);

        $actual   = $di->getShared('crypt');
        $expected = new Crypt();

        $I->assertEquals($expected, $actual);
    }
}
