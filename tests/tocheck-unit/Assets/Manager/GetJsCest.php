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

namespace Phalcon\Test\Unit\Assets\Manager;

use UnitTester;

class GetJsCest
{
    /**
     * Tests Phalcon\Assets\Manager :: getJs()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsManagerGetJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - getJs()');

        $I->skipTest('Need implementation');
    }
}
