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

namespace Phalcon\Test\Unit\Security\Random;

use UnitTester;

/**
 * Class Base62Cest
 *
 * @package Phalcon\Test\Unit\Security\Random
 */
class Base62Cest
{
    /**
     * Tests Phalcon\Security\Random :: base62()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function securityRandomBase62(UnitTester $I)
    {
        $I->wantToTest("Security\Random - base62()");
        $I->skipTest("Need implementation");
    }
}
