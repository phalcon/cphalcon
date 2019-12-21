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

class SetKeyCest
{
    /**
     * Tests Phalcon\Crypt :: setKey()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-16
     */
    public function cryptSetKey(UnitTester $I)
    {
        $I->wantToTest('Crypt - setKey()');

        $I->skipTest('Need implementation');
    }
}
