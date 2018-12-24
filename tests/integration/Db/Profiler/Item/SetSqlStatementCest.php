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
 * Class SetSqlStatementCest
 */
class SetSqlStatementCest
{
    /**
     * Tests Phalcon\Db\Profiler\Item :: setSqlStatement()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbProfilerItemSetSqlStatement(IntegrationTester $I)
    {
        $I->wantToTest('Db\Profiler\Item - setSqlStatement()');
        $I->skipTest('Need implementation');
    }
}
