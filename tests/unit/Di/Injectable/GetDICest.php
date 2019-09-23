<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Di\Injectable;

use UnitTester;

class GetDICest
{
    /**
     * Unit Tests Phalcon\Di\Injectable :: getDI()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diInjectableGetDI(UnitTester $I)
    {
        $I->wantToTest('Di\Injectable - getDI()');

        $I->skipTest('Need implementation');
    }
}
