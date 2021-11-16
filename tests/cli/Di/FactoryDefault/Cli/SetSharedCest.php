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

class SetSharedCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: setShared()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliSetShared(CliTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - setShared()');
        $di = new Di();

        $di->setShared('escaper', Escaper::class);

        // check shared service
        $actual = $di->getService('escaper');
        $I->assertTrue($actual->isShared());

        $actual = $di->getShared('escaper');
        $I->assertInstanceOf(Escaper::class, $actual);
    }
}
