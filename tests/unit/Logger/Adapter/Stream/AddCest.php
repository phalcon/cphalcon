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

namespace Phalcon\Test\Unit\Logger\Adapter\Stream;

use UnitTester;

/**
 * Class AddCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class AddCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Stream :: add()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterStreamAdd(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Stream - add()');
        $I->skipTest('Need implementation');
    }
}
