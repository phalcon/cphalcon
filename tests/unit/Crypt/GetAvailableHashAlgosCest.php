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

use Phalcon\Crypt;
use UnitTester;

class GetAvailableHashAlgosCest
{
    /**
     * Tests Phalcon\Crypt :: getAvailableHashAlgos()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cryptGetAvailableHashAlgos(UnitTester $I)
    {
        $I->wantToTest('Crypt - getAvailableHashAlgos()');

        $crypt = new Crypt();

        $I->assertTrue(is_array($crypt->getAvailableHashAlgos()));
    }
}
