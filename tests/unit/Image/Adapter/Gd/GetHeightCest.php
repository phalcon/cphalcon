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

class GetHeightCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: getHeight()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdGetHeightJpg(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - getHeight() - from jpg image');

        $this->checkJpegSupport($I);

        $gd = new Gd(dataDir('assets/images/phalconphp.jpg'));

        $I->assertSame(
            694,
            $gd->getHeight()
        );
    }

    /**
     * Tests Phalcon\Image\Adapter\Gd :: getHeight()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdGetHeightPng(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - getHeight() - from png image');

        $gd = new Gd(dataDir('assets/images/logo.png'));

        $I->assertSame(
            82,
            $gd->getHeight()
        );
    }
}
