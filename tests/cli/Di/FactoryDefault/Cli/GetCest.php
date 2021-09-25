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
use Phalcon\Di\Exception;
use Phalcon\Di\FactoryDefault\Cli as Di;
use Phalcon\Di\Service;
use Phalcon\Escaper;

class GetCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliGet(CliTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - get()');

        // setup
        $di = new Di();

        // set a service and get it to check
        $actual = $di->set('escaper', Escaper::class);

        $I->assertInstanceOf(Service::class, $actual);
        $I->assertFalse($actual->isShared());

        // get escaper service
        $actual   = $di->get('escaper');
        $expected = new Escaper();

        $I->assertInstanceOf(Escaper::class, $actual);
        $I->assertEquals($expected, $actual);

        // non exists service
        $I->expectThrowable(
            new Exception("Service 'non-exists' wasn't found in the dependency injection container"),
            function () use ($di) {
                $di->get('non-exists');
            }
        );
    }
}
