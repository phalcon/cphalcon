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

namespace Phalcon\Test\Unit\Crypt;

use UnitTester;
use Phalcon\Crypt;

/**
 * Class GetCipherCest
 */
class GetCipherCest
{
    /**
     * Tests Phalcon\Crypt :: getCipher()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cryptGetCipher(UnitTester $I)
    {
        $I->wantToTest('Crypt - getCipher()');

        $cipher = "aes-256-cfb";
        $crypt = new Crypt($cipher);
        $I->assertEquals($cipher, $crypt->getCipher());
    }
}
