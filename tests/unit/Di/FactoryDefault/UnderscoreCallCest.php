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

namespace Phalcon\Test\Unit\Di\FactoryDefault;

use UnitTester;

class UnderscoreCallCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault :: __call()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function diFactorydefaultUnderscoreCall(UnitTester $I)
    {
        $I->wantToTest("Di\FactoryDefault - __call()");
        $I->skipTest('Need implementation');
    }
}
