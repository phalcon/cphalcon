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
use Phalcon\Html\Escaper;

class OffsetGetCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: offsetGet()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliOffsetGet(CliTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - offsetGet()');


        $di = new Di();

        $I->expectThrowable(
            new Exception(
                "Service 'non-exists' wasn't found in the dependency injection container"
            ),
            function () use ($di) {
                $di['non-exists'];
            }
        );

        $I->expectThrowable(
            new Exception(
                "Service 'non-exists' wasn't found in the dependency injection container"
            ),
            function () use ($di) {
                $di->offsetGet('non-exists');
            }
        );

        $di->set('escaper', Escaper::class);

        $I->assertInstanceOf(
            Escaper::class,
            $di->offsetGet('escaper')
        );

        $I->assertInstanceOf(
            Escaper::class,
            $di['escaper']
        );
    }
}
