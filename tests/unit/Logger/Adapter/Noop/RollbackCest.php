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

namespace Phalcon\Tests\Unit\Logger\Adapter\Noop;

use Phalcon\Logger\Adapter\Noop;
use UnitTester;

class RollbackCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Noop :: rollback()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function loggerAdapterNoopRollback(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Noop - rollback()');

        $adapter = new Noop();

        $adapter->begin();

        $I->assertTrue(
            $adapter->inTransaction()
        );

        $adapter->rollback();

        $I->assertFalse(
            $adapter->inTransaction()
        );
    }
}
