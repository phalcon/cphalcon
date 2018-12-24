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

namespace Phalcon\Test\Unit\Mvc\Application;

use UnitTester;

/**
 * Class UnderscoreGetCest
 */
class UnderscoreGetCest
{
    /**
     * Tests Phalcon\Mvc\Application :: __get()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcApplicationUnderscoreGet(UnitTester $I)
    {
        $I->wantToTest('Mvc\Application - __get()');
        $I->skipTest('Need implementation');
    }
}
