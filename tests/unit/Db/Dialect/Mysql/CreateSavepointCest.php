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

use Phalcon\Test\Fixtures\Traits\DialectTrait;
use UnitTester;

class CreateSavepointCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Mysql :: createSavepoint()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testCreateSavepoint(UnitTester $I)
    {
        $dialect  = $this->getDialectMysql();
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
