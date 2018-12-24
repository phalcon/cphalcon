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

namespace Phalcon\Test\Unit\Assets\Manager;

use UnitTester;

/**
 * Class AddAssetByTypeCest
 */
class AddAssetByTypeCest
{
    /**
     * Tests Phalcon\Assets\Manager :: addAssetByType()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsManagerAddAssetByType(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - addAssetByType()');
        $I->skipTest('Need implementation');
    }
}
