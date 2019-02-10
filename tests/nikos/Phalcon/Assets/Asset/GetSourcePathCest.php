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

namespace Phalcon\Test\Unit\Assets\Asset;

use UnitTester;

/**
 * Class GetSourcePathCest
 */
class GetSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getSourcePath()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function assetsAssetGetSourcePath(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getSourcePath()');
        $I->skipTest('Need implementation');
    }
}
