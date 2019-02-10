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

namespace Phalcon\Test\Unit\Db\Adapter;

use UnitTester;

/**
 * Class GetDialectCest
 */
class GetDialectCest
{
    /**
     * Tests Phalcon\Db\Adapter :: getDialect()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function dbAdapterGetDialect(UnitTester $I)
    {
        $I->wantToTest('Db\Adapter - getDialect()');
        $I->skipTest('Need implementation');
    }
}
