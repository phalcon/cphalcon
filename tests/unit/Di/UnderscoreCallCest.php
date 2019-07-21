<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Di;

use Phalcon\Di;
use Phalcon\Di\Exception;
use Phalcon\Escaper;
use UnitTester;

class UnderscoreCallCest
{
    /**
     * Tests Phalcon\Di :: __call()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testUnderscoreCall(UnitTester $I)
    {
        $I->wantToTest('Phalcon\Di :: __call() - set and get service');

        $di = new Di();

        $actual = $di->setEscaper(Escaper::class);

        $I->assertNull($actual);

        $actual = $di->getEscaper();

        $I->assertInstanceOf(Escaper::class, $actual);
    }

    /**
     * Tests Phalcon\Di :: __call() - unknown method
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-28
     */
    public function testUnderscoreCallUnknownMethod(UnitTester $I)
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
