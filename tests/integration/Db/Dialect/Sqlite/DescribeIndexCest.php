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

namespace Phalcon\Test\Integration\Db\Dialect\Sqlite;

use IntegrationTester;

/**
 * Class DescribeIndexCest
 */
class DescribeIndexCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: describeIndex()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbDialectSqliteDescribeIndex(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Sqlite - describeIndex()');
        $I->skipTest('Need implementation');
    }
}
