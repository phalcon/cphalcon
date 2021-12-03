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

namespace Phalcon\Tests\Unit\Di;

use Phalcon\Di;
use Phalcon\Di\Exception;
use Phalcon\Html\Escaper;
use UnitTester;

/**
 * Class UnderscoreCallCest
 *
 * @package Phalcon\Tests\Unit\Di
 */
class UnderscoreCallCest
{
    /**
     * Tests Phalcon\Di :: __call()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testUnderscoreCall(UnitTester $I)
    {
        $I->wantToTest('Phalcon\Di :: __call() - set and get service');

        $container = new Di();

        $actual = $container->setEscaper(Escaper::class);
        $I->assertNull($actual);

        $actual = $container->getEscaper();
        $I->assertInstanceOf(Escaper::class, $actual);
    }

    /**
     * Tests Phalcon\Di :: __call() - unknown method
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testUnderscoreCallUnknownMethod(UnitTester $I)
    {
        $I->wantToTest('Phalcon\Di :: __call() - unknown method');

        $container = new Di();

        $I->expectThrowable(
            new Exception(
                "Call to undefined method or service 'notARealMethod'"
            ),
            function () use ($container) {
                $container->notARealMethod();
            }
        );
    }
}
