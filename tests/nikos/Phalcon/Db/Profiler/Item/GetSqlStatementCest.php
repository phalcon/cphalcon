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

namespace Phalcon\Test\Unit\Db\Profiler\Item;

use UnitTester;

/**
 * Class GetSqlStatementCest
 */
class GetSqlStatementCest
{
    /**
     * Tests Phalcon\Db\Profiler\Item :: getSqlStatement()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function dbProfilerItemGetSqlStatement(UnitTester $I)
    {
        $I->wantToTest('Db\Profiler\Item - getSqlStatement()');
        $I->skipTest('Need implementation');
    }
}
