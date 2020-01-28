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

namespace Phalcon\Test\Unit\Di\Injectable;

use UnitTester;

class SetDICest
{
    /**
     * Unit Tests Phalcon\Di\Injectable :: setDI()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diInjectableSetDI(UnitTester $I)
    {
        $I->wantToTest('Di\Injectable - setDI()');

        $I->skipTest('Need implementation');
    }
}
