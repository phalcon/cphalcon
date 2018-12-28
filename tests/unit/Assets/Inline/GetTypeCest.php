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
 * Class GetTypeCest
 */
class GetTypeCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Inline :: getType() - css
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineGetTypeCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - getType() - css');
        $content = 'p {color: #000099}';
        $asset   = new Inline('css', $content);

        $expected = 'css';
        $this->assetGetType($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Inline :: getType() - js
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineGetTypeJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - getType() - js');
        $content = '<script>alert("Hello");</script>';
        $asset   = new Inline('js', $content);

        $expected = 'js';
        $this->assetGetType($I, $asset, $expected);
    }
}
