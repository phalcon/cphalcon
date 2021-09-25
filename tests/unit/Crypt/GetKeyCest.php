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

use UnitTester;

class GetKeyCest
{
    /**
     * Tests Phalcon\Crypt :: getKey()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-16
     */
    public function cryptGetKey(UnitTester $I)
    {
        $I->wantToTest('Crypt - getKey()');

        $I->skipTest('Need implementation');
    }
}
