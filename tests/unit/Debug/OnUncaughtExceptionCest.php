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

namespace Phalcon\Test\Unit\Debug;

use UnitTester;

class OnUncaughtExceptionCest
{
    /**
     * Tests Phalcon\Debug :: onUncaughtException()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function debugOnUncaughtException(UnitTester $I)
    {
        $I->wantToTest('Debug - onUncaughtException()');

        $I->skipTest('Need implementation');
    }
}
