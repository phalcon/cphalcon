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

class GetImageCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: getImage()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdGetImage(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - getImage()');

        foreach ($this->getImages() as $image) {
            $gd = new Gd($image);

            if (version_compare(PHP_VERSION, '8.0.0', '>=')) {
                $expected = is_object($gd->getImage());
            } else {
                $expected = is_resource($gd->getImage());
            }

            $I->assertTrue(
                $expected
            );
        }
    }
}
