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

use Phalcon\Crypt\Crypt;
use UnitTester;

class GetAvailableHashAlgosCest
{
    /**
     * Tests Phalcon\Crypt\Crypt :: getAvailableHashAlgos()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cryptGetAvailableHashAlgos(UnitTester $I)
    {
        $I->wantToTest('Crypt - getAvailableHashAlgos()');

        $crypt = new Crypt();

        $I->assertInternalType(
            'array',
            $crypt->getAvailableHashAlgos()
        );
    }
}
