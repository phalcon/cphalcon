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
use Phalcon\Di\Service;
use Phalcon\Escaper;

class GetServiceCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: getService()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliGetService(CliTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - getService()');

        // setup
        $di = new Di();

        // set a service and get it to check
        $actual = $di->set('escaper', Escaper::class);

        $I->assertInstanceOf(Service::class, $actual);

        // get escaper service
        $actual = $di->getService('escaper');

        $I->assertInstanceOf(Service::class, $actual);
        $I->assertFalse($actual->isShared());

        // non exists service
        $I->expectThrowable(
            new Exception(
                "Service 'non-exists' wasn't found in the dependency injection container"
            ),
            function () use ($di) {
                $di->getService('non-exists');
            }
        );
    }
}
