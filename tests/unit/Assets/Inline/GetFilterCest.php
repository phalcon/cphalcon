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
 * Class GetFilterCest
 */
class GetFilterCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Inline :: getFilter() - css
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineGetFilterCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - getFilter() - css');
        $content = 'p {color: #000099}';
        $asset   = new Inline('css', $content);

        $expected = true;
        $this->assetGetFilter($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Inline :: getFilter() - js
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineGetFilterJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - getFilter() - js');
        $content = '<script>alert("Hello");</script>';
        $asset   = new Inline('js', $content);

        $expected = true;
        $this->assetGetFilter($I, $asset, $expected);
    }
}
