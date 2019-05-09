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

namespace Phalcon\Test\Unit\Assets\Collection;

use UnitTester;

class GetAssetsCest
{
    /**
     * Tests Phalcon\Assets\Collection :: getAssets()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsCollectionGetAssets(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - getAssets()');
        $I->skipTest('Need implementation');
    }
}
