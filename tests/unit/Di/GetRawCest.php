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

use Exception;
use Phalcon\Di\Di;
use Phalcon\Html\Escaper;
use UnitTester;

/**
 * Class GetRawCest
 *
 * @package Phalcon\Tests\Unit\Di
 */
class GetRawCest
{
    /**
     * Tests Phalcon\Di\Di :: getRaw()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diGetRaw(UnitTester $I)
    {
        $I->wantToTest('Di - getRaw()');

        $container = new Di();

        // existing service
        $container->set('escaper', Escaper::class);

        $expected = Escaper::class;
        $actual   = $container->getRaw('escaper');

        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Di :: getRaw() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diGetRawException(UnitTester $I)
    {
        $I->wantToTest('Di - getRaw() - exception');

        $container = new Di();

        // nonexistent service
        $I->expectThrowable(
            new Exception(
                "Service 'nonexistent-service' was not found " .
                "in the dependency injection container"
            ),
            function () use ($container) {
                $container->getRaw('nonexistent-service');
            }
        );
    }
}
