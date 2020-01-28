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

namespace Phalcon\Test\Unit\Image\Adapter\Gd;

use Phalcon\Image\Adapter\Gd;
use Phalcon\Test\Fixtures\Traits\GdTrait;
use UnitTester;

class GetTypeCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: getType()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdGetTypeJpg(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - getType() - from jpg image');

        $gd = new Gd(dataDir('assets/images/phalconphp.jpg'));

        $I->assertSame(
            2,
            $gd->getType()
        );
    }

    /**
     * Tests Phalcon\Image\Adapter\Gd :: getType()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdGetTypePng(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - getType() - from png image');

        $gd = new Gd(dataDir('assets/images/logo.png'));

        $I->assertSame(
            3,
            $gd->getType()
        );
    }
}
