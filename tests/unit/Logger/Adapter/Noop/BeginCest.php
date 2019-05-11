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

namespace Phalcon\Test\Unit\Logger\Adapter\Noop;

use Phalcon\Logger\Adapter\Noop;
use UnitTester;

/**
 * @package Phalcon\Test\Unit\Logger
 */
class BeginCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Noop :: begin()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterNoopBegin(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Noop - begin()');

        $adapter = new Noop();

        $I->assertFalse(
            $adapter->inTransaction()
        );

        $adapter->begin();

        $I->assertTrue(
            $adapter->inTransaction()
        );

        $adapter->commit();

        $I->assertFalse(
            $adapter->inTransaction()
        );
    }
}
