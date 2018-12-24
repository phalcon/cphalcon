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
 * Class SetFilterCest
 */
class SetFilterCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Inline :: setFilter() - css
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineSetFilterCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - setFilter() - css');
        $content = 'p {color: #000099}';
        $asset   = new Inline('css', $content);

        $expected = true;
        $this->assetGetFilter($I, $asset, $expected);

        $expected = false;
        $asset->setFilter($expected);
        $this->assetGetFilter($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Inline :: setFilter() - js
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineSetFilterJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - setFilter() - js');
        $content = '<script>alert("Hello");</script>';
        $asset   = new Inline('js', $content);

        $expected = true;
        $this->assetGetFilter($I, $asset, $expected);

        $expected = false;
        $asset->setFilter($expected);
        $this->assetGetFilter($I, $asset, $expected);
    }
}
