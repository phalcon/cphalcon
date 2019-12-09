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

namespace Phalcon\Test\Unit\Assets\Collection;

use UnitTester;

class GetRealTargetPathCest
{
    /**
     * Tests Phalcon\Assets\Collection :: getRealTargetPath()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsCollectionGetRealTargetPath(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - getRealTargetPath()');

        $I->skipTest('Need implementation');
    }
}
