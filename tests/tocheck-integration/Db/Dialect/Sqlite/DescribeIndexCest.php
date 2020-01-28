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

namespace Phalcon\Test\Integration\Db\Dialect\Sqlite;

use IntegrationTester;

class DescribeIndexCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: describeIndex()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbDialectSqliteDescribeIndex(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Sqlite - describeIndex()');
        $I->skipTest('Need implementation');
    }
}
