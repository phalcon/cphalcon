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

namespace Phalcon\Tests\Unit\Crypt;

use Codeception\Util\Stub;
use Phalcon\Crypt\Crypt;
use UnitTester;

use function function_exists;
use function hash_hmac_algos;

/**
 * Class GetAvailableHashAlgorithmsCest
 *
 * @package Phalcon\Tests\Unit\Crypt
 */
class GetAvailableHashAlgorithmsCest
{
    /**
     * Tests Phalcon\Crypt\Crypt :: getAvailableHashAlgorithms()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function cryptGetAvailableHashAlgorithms(UnitTester $I)
    {
        $I->wantToTest('Crypt - getAvailableHashAlgorithms()');

        $crypt = new Crypt();

        $expected = hash_hmac_algos();
        $actual   = $crypt->getAvailableHashAlgorithms();
        $I->assertEquals($expected, $actual);
    }
}
