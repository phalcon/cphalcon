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
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class CreateSavepointCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Mysql :: createSavepoint()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function dbDialectMysqlCreateSavepoint(IntegrationTester $I)
    {
        $I->wantToTest("Db\Dialect\Mysql - createSavepoint()");
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
