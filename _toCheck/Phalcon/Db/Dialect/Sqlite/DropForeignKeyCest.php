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

class DropForeignKeyCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: dropForeignKey()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbDialectSqliteDropForeignKey(UnitTester $I)
    {
        $I->wantToTest("Db\Dialect\Sqlite - dropForeignKey()");
        $I->skipTest("Need implementation");
    }
}
