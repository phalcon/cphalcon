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

namespace Phalcon\Test\Integration\Db\Dialect\Mysql;

use IntegrationTester;
use Phalcon\Db\Dialect\Mysql;

class SharedLockCest
{
    /**
     * Tests Phalcon\Db\Dialect\Mysql :: sharedLock()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-26
     */
    public function dbDialectMysqlSharedLock(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Mysql - sharedLock()');

        $dialect = new Mysql();

        $I->assertEquals(
            'SELECT * FROM robots LOCK IN SHARE MODE',
            $dialect->sharedLock('SELECT * FROM robots')
        );
    }
}
