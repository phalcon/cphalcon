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
 * Class Base64Cest
 */
class Base64Cest
{
    /**
     * Tests Phalcon\Security\Random :: base64()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function securityRandomBase64(UnitTester $I)
    {
        $I->wantToTest('Security\Random - base64()');
        $I->skipTest('Need implementation');
    }
}
