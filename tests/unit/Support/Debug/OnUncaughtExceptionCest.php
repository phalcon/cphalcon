<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Debug;

use UnitTester;

class OnUncaughtExceptionCest
{
    /**
     * Tests Phalcon\Debug :: onUncaughtException()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function supportDebugOnUncaughtException(UnitTester $I)
    {
        $I->wantToTest('Debug - onUncaughtException()');

        $I->skipTest('Need implementation');
    }
}
