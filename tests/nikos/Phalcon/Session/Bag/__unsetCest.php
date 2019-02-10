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

/**
 * Class __unsetCest
 */
class __unsetCest
{
    /**
     * Tests Phalcon\Session\Bag :: __unset()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function sessionBag__unset(UnitTester $I)
    {
        $I->wantToTest('Session\Bag - __unset()');
        $I->skipTest('Need implementation');
    }
}
