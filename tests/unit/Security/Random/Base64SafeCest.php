<?php

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

class Base64SafeCest
{
    /**
     * Tests Phalcon\Security\Random :: base64Safe()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function securityRandomBase64Safe(UnitTester $I)
    {
        $I->wantToTest("Security\Random - base64Safe()");
        $I->skipTest("Need implementation");
    }
}
