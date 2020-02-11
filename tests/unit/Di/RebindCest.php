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

namespace Phalcon\Test\Unit\Di;

use Phalcon\Di;
use Phalcon\Di\Exception;
use Phalcon\Di\Service;
use Phalcon\Escaper;
use UnitTester;

class RebindCest
{
    /**
     * Unit Tests Phalcon\Di :: rebind()
     *
     * @author Timur Flush <https://github.com/TimurFlush>
     * @since  2020-02-10
     */
    public function diRebind(UnitTester $I)
    {
        $I->wantToTest('Di - rebind()');

        $di = new Di();

        $di->set('request', 'definition');

        $expected = function (Di $di, $service) {

        };

        $actual = $di->rebind('request', $expected);

        $I->assertSame($expected, $actual);
    }

    /**
     * Unit Tests Phalcon\Di :: rebind()
     *
     * @author Timur Flush <https://github.com/TimurFlush>
     * @since  2020-02-11
     */
    public function diRebindThrowException(UnitTester $I)
    {
        $I->wantToTest('Di - rebind() with exception throwing');

        $di = new Di();

        $I->expectException(new Exception("Service 'nonExistingService' wasn't found in the dependency injection container"));

        $di->rebind('nonExistingService', function () {});
    }
}
