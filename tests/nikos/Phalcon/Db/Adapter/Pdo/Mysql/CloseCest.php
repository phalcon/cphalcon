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

namespace Phalcon\Test\Unit\Db\Adapter\Pdo\Mysql;

use UnitTester;

class CloseCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: close()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function dbAdapterPdoMysqlClose(UnitTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Mysql - close()');

        $I->skipTest('Need implementation');
    }
}
