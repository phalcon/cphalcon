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

namespace Phalcon\Test\Database\Db\Profiler\Item;

use DatabaseTester;
use Phalcon\Db\Profiler\Item;

class GetSetSqlStatementCest
{
    /**
     * Tests Phalcon\Db\Profiler\Item :: getSqlStatement()/setSqlStatement()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
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
