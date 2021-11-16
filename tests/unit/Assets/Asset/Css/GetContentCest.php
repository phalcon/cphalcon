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

namespace Phalcon\Tests\Unit\Assets\Asset\Css;

use Phalcon\Assets\Asset\Css;
use UnitTester;

use function dataDir;
use function file_get_contents;

/**
 * Class GetContentCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset\Css
 */
class GetContentCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: getContent()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsAssetCssGetContent(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Css - getContent()');

        if (PHP_OS_FAMILY === 'Windows') {
            $I->markTestSkipped('Need to fix Windows new lines...');
        }

        $asset = new Css('assets/assets/1198.css');

        $expected = file_get_contents(dataDir('assets/assets/1198.css'));
        $actual   = $asset->getContent(dataDir());
        $I->assertEquals($expected, $actual);
    }
}
