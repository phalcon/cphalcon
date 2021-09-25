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

class GetRealpathCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: getRealpath()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdGetRealpath(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - getRealpath()');

        $this->checkJpegSupport($I);

        foreach ($this->getImages() as $image) {
            $image = str_replace("/", DIRECTORY_SEPARATOR, $image);
            $gd    = new Gd($image);

            $I->assertSame(
                $image,
                $gd->getRealpath()
            );
        }
    }
}
