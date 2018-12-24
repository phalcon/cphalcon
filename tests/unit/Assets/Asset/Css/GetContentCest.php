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

namespace Phalcon\Test\Unit\Assets\Asset\Css;

use Phalcon\Assets\Asset\Css;
use UnitTester;
use function dataFolder;

/**
 * Class GetContentCest
 */
class GetContentCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getContent()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetContent(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getContent()');
        $asset = new Css('assets/assets/1198.css');

        $expected = file_get_contents(dataFolder('assets/assets/1198.css'));
        $actual   = $asset->getContent(dataFolder());
        $I->assertEquals($expected, $actual);
    }
}
