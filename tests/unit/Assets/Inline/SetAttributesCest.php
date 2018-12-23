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
 * Class SetAttributesCest
 */
class SetAttributesCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Inline :: setAttributes() - css
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineSetAttributesCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - setAttributes() - css');
        $content = 'p {color: #000099}';
        $asset   = new Inline('css', $content);

        $expected = ['data-key' => 'phalcon'];
        $asset->setAttributes($expected);
        $this->assetGetAttributes($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Inline :: setAttributes() - js
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineSetAttributesJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - setAttributes() - js');
        $content = '<script>alert("Hello");</script>';
        $asset   = new Inline('js', $content);

        $expected = ['data-key' => 'phalcon'];
        $asset->setAttributes($expected);
        $this->assetGetAttributes($I, $asset, $expected);
    }
}
