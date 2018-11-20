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

use Phalcon\Test\Fixtures\Traits\DialectTrait;
use UnitTester;

class CreateSavepointCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: createSavepoint()
     *
     * @param UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testCreateSavepoint(UnitTester $I)
    {
        $dialect  = $this->getDialectSqlite();
        $expected = $this->getCreateSavepointSql();
        $actual   = $dialect->createSavepoint('PH_SAVEPOINT_1');

        $I->assertEquals($expected, $actual);
    }

    /**
     * @return string
     */
    protected function getCreateSavepointSql(): string
    {
        return 'SAVEPOINT PH_SAVEPOINT_1';
    }
}
