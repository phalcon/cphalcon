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
 * Class ListTablesCest
 */
class ListTablesCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: listTables()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbDialectSqliteListTables(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Sqlite - listTables()');
        $I->skipTest('Need implementation');
    }
}
