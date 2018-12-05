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

namespace Phalcon\Test\Unit\Logger;

use UnitTester;

/**
 * Class RemoveAdapterCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class RemoveAdapterCest
{
    /**
     * Tests Phalcon\Logger :: removeAdapter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerRemoveAdapter(UnitTester $I)
    {
        $I->wantToTest("Logger - removeAdapter()");
        $I->skipTest("Need implementation");
    }
}
