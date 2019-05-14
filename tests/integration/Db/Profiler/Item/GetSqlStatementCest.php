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

namespace Phalcon\Test\Integration\Db\Profiler\Item;

use IntegrationTester;

/**
 * Class GetSqlStatementCest
 */
class GetSqlStatementCest
{
    /**
     * Tests Phalcon\Db\Profiler\Item :: getSqlStatement()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbProfilerItemGetSqlStatement(IntegrationTester $I)
    {
        $I->wantToTest('Db\Profiler\Item - getSqlStatement()');
        $I->skipTest('Need implementation');
    }
}
