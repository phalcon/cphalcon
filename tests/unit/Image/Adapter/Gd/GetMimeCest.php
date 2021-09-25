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

class GetMimeCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: getMime()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdGetMimeImageJpeg(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - getMime() - image/jpg');

        $this->checkJpegSupport($I);

        $gd = new Gd(dataDir('assets/images/phalconphp.jpg'));

        $I->assertSame(
            'image/jpeg',
            $gd->getMime()
        );
    }

    /**
     * Tests Phalcon\Image\Adapter\Gd :: getMime()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdGetMimeImagePng(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - getMime() - image/png');

        $gd = new Gd(dataDir('assets/images/logo.png'));

        $I->assertSame(
            'image/png',
            $gd->getMime()
        );
    }
}
