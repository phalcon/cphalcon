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
use Phalcon\Di\Service;
use Phalcon\Escaper;

class AttemptCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: attempt()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliAttempt(CliTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - attempt()');

        $di = new Di();

        $actual = $di->attempt('nonexistingservice', Escaper::class);

        $I->assertInstanceOf(Service::class, $actual);

        $actual = $di->attempt('nonexistingservice', Escaper::class);

        $I->assertFalse($actual);
    }
}
