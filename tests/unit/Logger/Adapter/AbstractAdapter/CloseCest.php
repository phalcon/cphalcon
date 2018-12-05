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

namespace Phalcon\Test\Unit\Logger\Adapter\AbstractAdapter;

use UnitTester;

/**
 * Class CloseCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class CloseCest
{
    /**
     * Tests Phalcon\Logger\Adapter\AbstractAdapter :: close()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterAbstractadapterClose(UnitTester $I)
    {
        $I->wantToTest("Logger\Adapter\AbstractAdapter - close()");
        $I->skipTest("Need implementation");
    }
}
