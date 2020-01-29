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

/**
 * Class AddPrimaryKeyCest
 */
class AddPrimaryKeyCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: addPrimaryKey()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoMysqlAddPrimaryKey(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Mysql - addPrimaryKey()');
        $I->skipTest('Need implementation');
    }
}
