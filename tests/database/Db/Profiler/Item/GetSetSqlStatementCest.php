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

namespace Phalcon\Tests\Database\Db\Profiler\Item;

use DatabaseTester;
use Phalcon\Db\Profiler\Item;

class GetSetSqlStatementCest
{
    /**
     * Tests Phalcon\Db\Profiler\Item :: getSqlStatement()/setSqlStatement()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  common
     */
    public function dbProfilerItemGetSetSqlStatement(DatabaseTester $I)
    {
        $I->wantToTest('Db\Profiler\Item - getSqlStatement()/setSqlStatement()');

        $item = new Item();
        $item->setSqlStatement('select * from co_invoices');
        $I->assertEquals(
            'select * from co_invoices',
            $item->getSqlStatement()
        );
    }
}
