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

namespace Phalcon\Test\Database\Db\Column;

use DatabaseTester;
use Phalcon\Db\Column;

class ConstantsCest
{
    /**
     * Tests Phalcon\Db\Column :: constants
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-10-26
     */
    public function checkClassConstants(DatabaseTester $I)
    {
        $I->wantToTest("Db\Column :: constants");

        $I->assertEquals(3, Column::BIND_PARAM_BLOB);
        $I->assertEquals(5, Column::BIND_PARAM_BOOL);
        $I->assertEquals(32, Column::BIND_PARAM_DECIMAL);
        $I->assertEquals(1, Column::BIND_PARAM_INT);
        $I->assertEquals(0, Column::BIND_PARAM_NULL);
        $I->assertEquals(2, Column::BIND_PARAM_STR);
        $I->assertEquals(1024, Column::BIND_SKIP);

        $I->assertEquals(14, Column::TYPE_BIGINTEGER);
        $I->assertEquals(19, Column::TYPE_BIT);
        $I->assertEquals(11, Column::TYPE_BLOB);
        $I->assertEquals(8, Column::TYPE_BOOLEAN);
        $I->assertEquals(5, Column::TYPE_CHAR);
        $I->assertEquals(1, Column::TYPE_DATE);
        $I->assertEquals(4, Column::TYPE_DATETIME);
        $I->assertEquals(3, Column::TYPE_DECIMAL);
        $I->assertEquals(9, Column::TYPE_DOUBLE);
        $I->assertEquals(18, Column::TYPE_ENUM);
        $I->assertEquals(7, Column::TYPE_FLOAT);
        $I->assertEquals(0, Column::TYPE_INTEGER);
        $I->assertEquals(15, Column::TYPE_JSON);
        $I->assertEquals(16, Column::TYPE_JSONB);
        $I->assertEquals(13, Column::TYPE_LONGBLOB);
        $I->assertEquals(24, Column::TYPE_LONGTEXT);
        $I->assertEquals(12, Column::TYPE_MEDIUMBLOB);
        $I->assertEquals(21, Column::TYPE_MEDIUMINTEGER);
        $I->assertEquals(23, Column::TYPE_MEDIUMTEXT);
        $I->assertEquals(22, Column::TYPE_SMALLINTEGER);
        $I->assertEquals(6, Column::TYPE_TEXT);
        $I->assertEquals(20, Column::TYPE_TIME);
        $I->assertEquals(17, Column::TYPE_TIMESTAMP);
        $I->assertEquals(10, Column::TYPE_TINYBLOB);
        $I->assertEquals(26, Column::TYPE_TINYINTEGER);
        $I->assertEquals(25, Column::TYPE_TINYTEXT);
        $I->assertEquals(2, Column::TYPE_VARCHAR);
    }
}
