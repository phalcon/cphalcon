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

use Phalcon\Assets\Asset;
use UnitTester;

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
    public function assetsAssetGetContentCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getContent()');
        $asset = new Asset('css', 'assets/assets/1198.css');

        $expected = file_get_contents(dataFolder('assets/assets/1198.css'));
        $actual   = $asset->getContent(dataFolder());
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getContent()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetContentJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getContent()');
        $asset = new Asset('js', 'assets/assets/signup.js');

        $expected = file_get_contents(dataFolder('assets/assets/signup.js'));
        $actual   = $asset->getContent(dataFolder());
        $I->assertEquals($expected, $actual);
    }
}
