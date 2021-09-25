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

namespace Phalcon\Tests\Unit\Image\Adapter\Gd;

use Phalcon\Image\Adapter\Gd;
use Phalcon\Tests\Fixtures\Traits\GdTrait;
use UnitTester;

class GetWidthCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: getWidth()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdGetWidthJpg(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - getWidth() - from jpg image');

        $this->checkJpegSupport($I);

        $gd = new Gd(dataDir('assets/images/phalconphp.jpg'));

        $I->assertSame(
            1820,
            $gd->getWidth()
        );
    }

    /**
     * Tests Phalcon\Image\Adapter\Gd :: getWidth()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdGetWidthPng(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - getWidth() - from png image');

        $gd = new Gd(dataDir('assets/images/logo.png'));

        $I->assertSame(
            82,
            $gd->getWidth()
        );
    }
}
