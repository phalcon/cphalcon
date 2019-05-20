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
use UnitTester;

class GetContentCest
{
    /**
     * Tests Phalcon\Assets\Inline :: getContent() - css
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineGetContentCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - getContent() - css');

        $content = 'p {color: #000099}';

        $asset = new Inline('css', $content);

        $I->assertEquals(
            $content,
            $asset->getContent()
        );
    }

    /**
     * Tests Phalcon\Assets\Inline :: getContent() - js
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineGetContentJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - getContent() - js');

        $content = '<script>alert("Hello");</script>';

        $asset = new Inline('js', $content);

        $I->assertEquals(
            $content,
            $asset->getContent()
        );
    }
}
