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

namespace Phalcon\Tests\Integration\Db\Dialect\Mysql;

use IntegrationTester;
use Phalcon\Db\Dialect\Mysql;

class RollbackSavepointCest
{
    /**
     * Tests Phalcon\Db\Dialect\Mysql :: rollbackSavepoint()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-02-26
     */
    public function dbDialectMysqlRollbackSavepoint(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Mysql - rollbackSavepoint()');

        $dialect = new Mysql();

        $I->assertEquals(
            'ROLLBACK TO SAVEPOINT PH_SAVEPOINT_1',
            $dialect->rollbackSavepoint('PH_SAVEPOINT_1')
        );
    }
}
