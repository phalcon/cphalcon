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

class SetHashAlgoCest
{
    /**
     * Tests Phalcon\Crypt :: setHashAlgo()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-16
     */
    public function cryptSetHashAlgo(UnitTester $I)
    {
        $I->wantToTest('Crypt - setHashAlgo()');

        $I->skipTest('Need implementation');
    }
}
