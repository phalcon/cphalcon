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
use UnitTester;

class OffsetGetCest
{
    /**
     * Unit Tests Phalcon\Di :: offsetGet()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-06-13
     */
    public function diOffsetGet(UnitTester $I)
    {
        $I->wantToTest('Di - offsetGet()');

        $di = new Di();

        $I->expectThrowable(
            new Exception("Service 'non-exists' wasn't found in the dependency injection container"),
            function () use ($di) {
                $di['non-exists'];
            }
        );

        $I->expectThrowable(
            new Exception("Service 'non-exists' wasn't found in the dependency injection container"),
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
