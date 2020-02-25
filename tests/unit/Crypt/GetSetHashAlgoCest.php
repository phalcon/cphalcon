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

namespace Phalcon\Test\Unit\Crypt;

use Phalcon\Crypt;
use UnitTester;

class GetSetHashAlgoCest
{
    /**
     * Tests Phalcon\Crypt :: getHashAlgo()/setHashAlgo()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-16
     */
    public function cryptGetSetHashAlgo(UnitTester $I)
    {
        $I->wantToTest('Crypt - getHashAlgo()/setHashAlgo()');

        $crypt = new Crypt();

        $I->assertEquals('sha256', $crypt->getHashAlgo());

        $crypt->setHashAlgo('sha512');

        $I->assertEquals(
            'sha512',
            $crypt->getHashAlgo()
        );
    }

    /**
     * Tests Phalcon\Crypt :: getHashAlgo()/setHashAlgo() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-16
     */
    public function cryptGetSetHashAlgoException(UnitTester $I)
    {
        $I->wantToTest('Crypt - getHashAlgo()/setHashAlgo() - exception');

        $I->expectThrowable(
            new Crypt\Exception(
                'The hash algorithm "hash" is not supported on this system.'
            ),
            function () {
                $crypt = new Crypt();
                $crypt->setHashAlgo('hash');
            }
        );
    }
}
