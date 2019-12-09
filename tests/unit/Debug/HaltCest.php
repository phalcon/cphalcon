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

class HaltCest
{
    /**
     * Tests Phalcon\Debug :: halt()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function debugHalt(UnitTester $I)
    {
        $I->wantToTest('Debug - halt()');

        $I->skipTest('Need implementation');
    }
}
