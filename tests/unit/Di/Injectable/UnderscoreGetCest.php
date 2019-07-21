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

namespace Phalcon\Test\Unit\Di\Injectable;

use UnitTester;

class UnderscoreGetCest
{
    /**
     * Unit Tests Phalcon\Di\Injectable :: __get()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-06-13
     */
    public function diInjectableUnderscoreGet(UnitTester $I)
    {
        $I->wantToTest('Di\Injectable - __get()');

        $I->skipTest('Need implementation');
    }
}
