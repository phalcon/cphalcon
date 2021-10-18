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

use Phalcon\Crypt\Crypt;
use Phalcon\Crypt\Exception\Exception;
use UnitTester;

/**
 * Class GetSetHashAlgoCest
 *
 * @package Phalcon\Tests\Unit\Crypt
 */
class GetSetHashAlgorithmCest
{
    /**
     * Tests Phalcon\Crypt\Crypt :: getHashAlgorithm() / setHashAlgorithm()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function cryptGetSetHashAlgo(UnitTester $I)
    {
        $I->wantToTest('Crypt - getHashAlgorithm() / setHashAlgorithm()');

        $cipher = 'blowfish';
        $crypt  = new Crypt();
        $crypt->setHashAlgorithm($cipher);

        $expected = $cipher;
        $actual   = $crypt->getHashAlgorithm();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Crypt\Crypt :: setHashAlgo() - unknown
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function cryptGetSetHashAlgoUnknown(UnitTester $I)
    {
        $I->wantToTest('Crypt - setHashAlgorithm() - unknown');
        $I->expectThrowable(
            new Exception(
                "The hash algorithm 'xxx-yyy-zzz' is not supported on this system."
            ),
            function () {
                $crypt = new Crypt();

                $crypt->setHashAlgorithm('xxx-yyy-zzz');
            }
        );
    }
}
