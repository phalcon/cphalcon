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
use Phalcon\Di\FactoryDefault\Cli as Di;
use Phalcon\Html\Escaper;

class GetServicesCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: getServices()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliGetServices(CliTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - getServices()');

        $di = new Di();

        $numberOfFactoryServices = 11;

        $I->assertCount($numberOfFactoryServices, $di->getServices());

        $di->set('newservice', Escaper::class);

        $I->assertCount($numberOfFactoryServices + 1, $di->getServices());

        $di->remove('newservice');
        $I->assertFalse($di->has('newservice'));
        $I->assertCount($numberOfFactoryServices, $di->getServices());
    }
}
