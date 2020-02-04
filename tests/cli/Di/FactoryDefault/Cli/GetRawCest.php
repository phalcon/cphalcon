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
use Phalcon\Di\Exception;
use Phalcon\Di\FactoryDefault\Cli as Di;
use Phalcon\Escaper;

class GetRawCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: getRaw()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliGetRaw(CliTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - getRaw()');

        $di = new Di();

        // nonexistent service
        $expected = new Exception("Service 'nonexistent-service' wasn't found in the dependency injection container");
        $actual   = function () use ($di) {
            $di->getRaw('nonexistent-service');
        };

        $I->expectThrowable(
            $expected,
            $actual
        );

        // existing service
        $di->set('escaper', Escaper::class);

        $expected = Escaper::class;
        $actual   = $di->getRaw('escaper');

        $I->assertSame($expected, $actual);
    }
}
