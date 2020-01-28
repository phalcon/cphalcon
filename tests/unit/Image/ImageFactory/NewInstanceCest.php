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

namespace Phalcon\Test\Unit\Image\ImageFactory;

use Phalcon\Image\Adapter\Imagick;
use Phalcon\Image\ImageFactory;
use UnitTester;

use function dataDir;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Image\ImageFactory :: newInstance()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-18
     */
    public function imageImageFactoryNewInstance(UnitTester $I)
    {
        $I->wantToTest('Image\ImageFactory - newInstance()');

        $factory = new ImageFactory();
        $file    = dataDir('assets/images/phalconphp.jpg');
        $file    = str_replace("/", DIRECTORY_SEPARATOR, $file);
        $name    = 'imagick';

        $image = $factory->newInstance($name, $file);

        $I->assertInstanceOf(
            Imagick::class,
            $image
        );

        $I->assertEquals(
            $file,
            $image->getRealpath()
        );
    }
}
