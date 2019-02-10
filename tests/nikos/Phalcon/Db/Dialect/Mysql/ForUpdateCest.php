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

namespace Phalcon\Test\Unit\Db\Dialect\Mysql;

use UnitTester;

/**
 * Class ForUpdateCest
 */
class ForUpdateCest
{
    /**
     * Tests Phalcon\Db\Dialect\Mysql :: forUpdate()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function dbDialectMysqlForUpdate(UnitTester $I)
    {
        $I->wantToTest('Db\Dialect\Mysql - forUpdate()');
        $I->skipTest('Need implementation');
    }
}
