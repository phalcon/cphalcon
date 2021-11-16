<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Assets\Asset\Js;

use Phalcon\Assets\Asset\Js;
use UnitTester;

use function dataDir;

/**
 * Class GetRealSourcePathCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset\Js
 */
class GetRealSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getRealSourcePath() - js local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsAssetJsGetRealSourcePathLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealSourcePath() - local');

        if (PHP_OS_FAMILY === 'Windows') {
            $I->markTestSkipped('Need to fix Windows new lines...');
        }

        $file  = dataDir('assets/assets/jquery.js');
        $asset = new Js($file);

        $expected = $file;
        $actual   = $asset->getRealSourcePath();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: getRealSourcePath() - js local -
     * does not exist
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsAssetJsGetRealSourcePathLocalDoesNotExist(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealSourcePath() - local - does not exist');

        $asset  = new Js('js/jquery.js');
        $actual = $asset->getRealSourcePath();
        $I->assertEmpty($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: getRealSourcePath() - remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsAssetJsGetRealSourcePathRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealSourcePath() - remote');

        $path  = 'https://phalcon.ld/js/jquery.js';
        $asset = new Js($path, false);

        $expected = $path;
        $actual   = $asset->getRealSourcePath();
        $I->assertEquals($expected, $actual);
    }
}
