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
 * Class DestructCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class DestructCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Stream :: __destruct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterStreamDestruct(UnitTester $I)
    {
        $I->wantToTest("Logger\Adapter\Stream - __destruct()");
        $I->skipTest("Need implementation");
    }
}
