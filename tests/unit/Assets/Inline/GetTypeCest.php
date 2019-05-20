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

class GetTypeCest
{
    /**
     * Tests Phalcon\Assets\Inline :: getType() - css
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineGetTypeCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - getType() - css');

        $type    = 'css';
        $content = 'p {color: #000099}';

        $asset = new Inline($type, $content);

        $I->assertEquals(
            $type,
            $asset->getType()
        );
    }

    /**
     * Tests Phalcon\Assets\Inline :: getType() - js
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineGetTypeJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - getType() - js');

        $type    = 'js';
        $content = '<script>alert("Hello");</script>';

        $asset = new Inline($type, $content);

        $I->assertEquals(
            $type,
            $asset->getType()
        );
    }
}
