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
 * Class SetTypeCest
 */
class SetTypeCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Inline :: setType() - css
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineSetTypeCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - setType() - css');
        $content = 'p {color: #000099}';
        $asset   = new Inline('css', $content);

        $expected = 'js';
        $asset->setType($expected);
        $this->assetGetType($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Inline :: setType() - js
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineSetTypeJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - setType() - js');
        $content = '<script>alert("Hello");</script>';
        $asset   = new Inline('js', $content);

        $expected = 'css';
        $asset->setType($expected);
        $this->assetGetType($I, $asset, $expected);
    }
}
