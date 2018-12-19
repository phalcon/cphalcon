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

namespace Phalcon\Test\Unit\Session\Manager;

use UnitTester;

/**
 * Class __unsetCest
 *
 * @package Phalcon\Test\Unit\Session\Manager
 */
class UnderscoreUnsetCest
{
    /**
     * Tests Phalcon\Session\Manager :: __unset()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionManagerUnderscoreUnset(UnitTester $I)
    {
        $I->wantToTest('Session\Manager - __unset()');
        $I->skipTest('Need implementation');
    }
}
