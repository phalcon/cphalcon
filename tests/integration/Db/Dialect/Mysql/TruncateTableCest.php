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

namespace Phalcon\Test\Integration\Db\Dialect\Mysql;

use IntegrationTester;

/**
 * Class TruncateTableCest
 */
class TruncateTableCest
{
    /**
     * Tests Phalcon\Db\Dialect\Mysql :: truncateTable()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbDialectMysqlTruncateTable(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Mysql - truncateTable()');
        $I->skipTest('Need implementation');
    }
}
