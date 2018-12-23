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

/**
 * Class GetAttributesCest
 */
class GetAttributesCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Inline :: getAttributes()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineGetAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - getAttributes()');
        $attributes = ['data-key' => 'phalcon'];
        $content    = '<script>alert("Hello");</script>';
        $asset      = new Js($content, true, $attributes);

        $expected = $attributes;
        $this->assetGetAttributes($I, $asset, $expected);
    }
}
