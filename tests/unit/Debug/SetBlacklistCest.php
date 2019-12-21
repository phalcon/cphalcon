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

class SetBlacklistCest
{
    /**
     * Unit Tests Phalcon\Debug :: setBlacklist()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-25
     */
    public function debugSetBlacklist(UnitTester $I)
    {
        $I->wantToTest('Debug - setBlacklist()');

        $I->skipTest('Need implementation');
    }
}
