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

namespace Phalcon\Tests\Unit\Image\ImageFactory;

use Phalcon\Image\Adapter\Imagick;
use Phalcon\Image\Exception;
use Phalcon\Image\ImageFactory;
use UnitTester;

use function dataDir;
use function uniqid;

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
        $I->checkExtensionIsLoaded('imagick');
        $I->wantToTest('Image\ImageFactory - newInstance()');

        $factory = new ImageFactory();
        $file    = dataDir('assets/images/example-jpg.jpg');
        $file    = str_replace("/", DIRECTORY_SEPARATOR, $file);
        $name    = 'imagick';

        $image = $factory->newInstance($name, $file);

        $class = Imagick::class;
        $I->assertInstanceOf($class, $image);

        $expected = $file;
        $actual   = $image->getRealPath();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Image\ImageFactory :: newInstance() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-08-02
     */
    public function imageImageFactoryNewInstanceException(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('imagick');
        $I->wantToTest('Image\ImageFactory - newInstance() - exception');

        $name = uniqid('service-');
        $I->expectThrowable(
            new Exception('Service ' . $name . ' is not registered'),
            function () use ($name) {
                $factory = new ImageFactory();
                $factory->newInstance($name, uniqid('file-'));
            }
        );
    }
}
