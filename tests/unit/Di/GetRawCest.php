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
use Phalcon\Escaper;
use UnitTester;

class GetRawCest
{
    /**
     * Tests Phalcon\Di :: getRaw()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function diGetRaw(UnitTester $I)
    {
        $I->wantToTest('Di - getRaw()');

        $di = new Di();

        // nonexistent service
        $expected = new \Exception("Service 'nonexistent-service' wasn't found in the dependency injection container");
        $actual = function () use ($di) {
            $di->getRaw('nonexistent-service');
        };

        $I->expectThrowable(
            $expected,
            $actual
        );

        // existing service
        $di->set('escaper', Escaper::class);

        $expected = Escaper::class;
        $actual = $di->getRaw('escaper');

        $I->assertSame($expected, $actual);
    }
}
