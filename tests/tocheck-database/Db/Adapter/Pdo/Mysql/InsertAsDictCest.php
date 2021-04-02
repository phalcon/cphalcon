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

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Mysql;

use IntegrationTester;

class InsertAsDictCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: insertAsDict()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoMysqlInsertAsDict(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Mysql - insertAsDict()');
        $I->skipTest('Need implementation');
    }
}
