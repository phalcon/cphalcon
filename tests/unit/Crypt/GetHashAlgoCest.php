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

use UnitTester;

class GetHashAlgoCest
{
    /**
     * Tests Phalcon\Crypt :: getHashAlgo()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-16
     */
    public function cryptGetHashAlgo(UnitTester $I)
    {
        $I->wantToTest('Crypt - getHashAlgo()');

        $I->skipTest('Need implementation');
    }
}
