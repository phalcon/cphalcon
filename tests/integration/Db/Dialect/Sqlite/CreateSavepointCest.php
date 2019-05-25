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
use Phalcon\Db\Dialect\Sqlite;

class CreateSavepointCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: createSavepoint()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function dbDialectSqliteCreateSavepoint(IntegrationTester $I)
    {
        $I->wantToTest("Db\Dialect\Sqlite - createSavepoint()");

        $dialect = new Sqlite();

        $I->assertEquals(
            'SAVEPOINT PH_SAVEPOINT_1',
            $dialect->createSavepoint('PH_SAVEPOINT_1')
        );
    }
}
