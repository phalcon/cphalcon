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
 * Class GetPathCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class GetPathCest
{
    /**
     * Tests Phalcon\Logger\Adapter\File :: getPath()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterFileGetPath(UnitTester $I)
    {
        $I->wantToTest("Logger\Adapter\File - getPath()");
        $I->skipTest("Need implementation");
    }
}
