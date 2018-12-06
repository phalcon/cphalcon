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

namespace Phalcon\Test\Unit\Logger\Adapter\File;

use UnitTester;

/**
 * Class InTransactionCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class InTransactionCest
{
    /**
     * Tests Phalcon\Logger\Adapter\File :: inTransaction()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterFileInTransaction(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\File - inTransaction()');
        $I->skipTest('Need implementation');
    }
}
