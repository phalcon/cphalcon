<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Db\Dialect\Sqlite;

use UnitTester;

class ListTablesCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: listTables()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbDialectSqliteListTables(UnitTester $I)
    {
        $I->wantToTest("Db\Dialect\Sqlite - listTables()");
        $I->skipTest("Need implementation");
    }
}
