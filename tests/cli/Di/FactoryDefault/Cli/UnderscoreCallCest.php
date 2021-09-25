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
use Phalcon\Escaper;

class UnderscoreCallCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: __call()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliUnderscoreCall(CliTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - __call()');

        $di = new Di();

        $actual = $di->setEscaper(Escaper::class);

        $I->assertNull($actual);

        $actual = $di->getEscaper();

        $I->assertInstanceOf(Escaper::class, $actual);
    }

    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: __call() - unknown method
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-28
     */
    public function testUnderscoreCallUnknownMethod(CliTester $I)
    {
        $I->wantToTest('Phalcon\Di :: __call() - unknown method');

        $di = new Di();

        $I->expectThrowable(
            new Exception(
                "Call to undefined method or service 'notARealMethod'"
            ),
            function () use ($di) {
                $di->notARealMethod();
            }
        );
    }
}
