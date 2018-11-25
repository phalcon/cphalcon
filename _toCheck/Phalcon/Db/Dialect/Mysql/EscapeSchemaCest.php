<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Db\Dialect\Mysql;

use UnitTester;

class EscapeSchemaCest
{
    /**
     * Tests Phalcon\Db\Dialect\Mysql :: escapeSchema()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbDialectMysqlEscapeSchema(UnitTester $I)
    {
        $I->wantToTest("Db\Dialect\Mysql - escapeSchema()");
        $I->skipTest("Need implementation");
    }
}
