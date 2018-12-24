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

namespace Phalcon\Test\Unit\Assets\Inline;

use Phalcon\Assets\Inline;
use Phalcon\Test\Fixtures\Traits\AssetsTrait;
use UnitTester;

/**
 * Class GetAssetKeyCest
 */
class GetAssetKeyCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Inline :: getAssetKey() - css
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineGetAssetKeyCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - getAssetKey() - css');
        $content = 'p {color: #000099}';
        $asset   = new Inline('css', $content);

        $expected = md5('css:' . $content);
        $this->assetGetAssetKey($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Inline :: getAssetKey() - js
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineGetAssetKeyJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - getAssetKey() - js');
        $content = '<script>alert("Hello");</script>';
        $asset   = new Inline('js', $content);

        $expected = md5('js:' . $content);
        $this->assetGetAssetKey($I, $asset, $expected);
    }
}
