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

class SetTypeCest
{
    /**
     * Tests Phalcon\Assets\Inline :: setType() - css
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineSetTypeCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - setType() - css');

        $asset = new Inline(
            'css',
            'p {color: #000099}'
        );

        $newType = 'js';

        $asset->setType($newType);

        $I->assertEquals(
            $newType,
            $asset->getType()
        );
    }

    /**
     * Tests Phalcon\Assets\Inline :: setType() - js
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineSetTypeJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - setType() - js');

        $asset = new Inline(
            'js',
            '<script>alert("Hello");</script>'
        );

        $newType = 'css';

        $asset->setType($newType);

        $I->assertEquals(
            $newType,
            $asset->getType()
        );
    }
}
