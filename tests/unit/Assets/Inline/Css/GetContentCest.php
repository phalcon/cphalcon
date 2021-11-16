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

namespace Phalcon\Tests\Unit\Assets\Inline\Css;

use Phalcon\Assets\Inline\Css;
use UnitTester;

/**
 * Class GetContentCest
 *
 * @package Phalcon\Tests\Unit\Assets\Inline\Css
 */
class GetContentCest
{
    /**
     * Tests Phalcon\Assets\Inline\Css :: getContent()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineCssGetContent(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Css - getContent()');

        $content = 'p {color: #000099}';
        $asset   = new Css($content);

        $actual = $asset->getContent();
        $I->assertEquals($content, $actual);
    }
}
