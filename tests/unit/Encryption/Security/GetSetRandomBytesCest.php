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

namespace Phalcon\Tests\Unit\Encryption\Security;

use Phalcon\Encryption\Security;
use UnitTester;

class GetSetRandomBytesCest
{
    /**
     * Tests Phalcon\Security :: getRandomBytes()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function encryptionSecurityGetRandomBytes(UnitTester $I)
    {
        $I->wantToTest('Encryption\Security - getRandomBytes()');

        $security = new Security();

        $I->assertSame(16, $security->getRandomBytes());

        $expected = 22;
        $security->setRandomBytes($expected);
        $I->assertSame($expected, $security->getRandomBytes());
    }
}
