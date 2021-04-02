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

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Sqlite;

use IntegrationTester;

class ViewExistsCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: viewExists()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoSqliteViewExists(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Sqlite - viewExists()');
        $I->skipTest('Need implementation');
    }
}
