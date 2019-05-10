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

namespace Phalcon\Test\Unit\Assets\Inline\Js;

use Phalcon\Assets\Inline\Js;
use Phalcon\Test\Fixtures\Traits\AssetsTrait;
use UnitTester;

class SetAttributesCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Inline :: setAttributes()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineSetAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - setAttributes()');
        $content = '<script>alert("Hello");</script>';
        $asset   = new Js($content);

        $expected = ['data-key' => 'phalcon'];
        $asset->setAttributes($expected);
        $this->assetGetAttributes($I, $asset, $expected);
    }
}
