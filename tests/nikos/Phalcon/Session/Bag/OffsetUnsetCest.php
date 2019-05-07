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

namespace Phalcon\Test\Unit\Session\Bag;

use UnitTester;

class OffsetUnsetCest
{
    /**
     * Tests Phalcon\Session\Bag :: offsetUnset()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function sessionBagOffsetUnset(UnitTester $I)
    {
        $I->wantToTest('Session\Bag - offsetUnset()');

        $I->skipTest('Need implementation');
    }
}
