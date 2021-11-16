<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Assets\Inline\Js;

use Phalcon\Assets\Inline\Js;
use UnitTester;

/**
 * Class GetContentCest
 *
 * @package Phalcon\Tests\Unit\Assets\Inline\Js
 */
class GetContentCest
{
    /**
     * Tests Phalcon\Assets\Inline\Js :: getContent()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineJsGetContent(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Js - getContent()');

        $content = '<script>alert("Hello");</script>';
        $asset   = new Js($content);

        $actual = $asset->getContent();
        $I->assertEquals($content, $actual);
    }
}
