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

namespace Phalcon\Test\Integration\Image\ImageFactory;

use IntegrationTester;
use Phalcon\Image\Adapter\Imagick;
use Phalcon\Image\ImageFactory;
use Phalcon\Test\Fixtures\Traits\FactoryTrait;

class LoadCest
{
    use FactoryTrait;

    public function _before(IntegrationTester $I)
    {
        $I->checkExtensionIsLoaded('imagick');

        $this->init();
    }

    /**
     * Tests Phalcon\Image\ImageFactory :: load()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-18
     */
    public function imageImageFactoryLoad(IntegrationTester $I)
    {
        $I->wantToTest('Image\ImageFactory - load()');

        $options = $this->config->image;
        $factory = new ImageFactory();

        /** @var Imagick $image */
        $image = $factory->load($options);

        $I->assertInstanceOf(
            Imagick::class,
            $image
        );


        $expected = realpath(
            $options->file
        );

        $I->assertEquals(
            $expected,
            $image->getRealpath()
        );
    }

    /**
     * Tests Phalcon\Image\ImageFactory :: load()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-18
     */
    public function imageImageFactoryLoadArray(IntegrationTester $I)
    {
        $I->wantToTest('Image\ImageFactory - load()');

        $options = $this->arrayConfig['image'];
        $factory = new ImageFactory();

        /** @var Imagick $image */
        $image = $factory->load($options);

        $I->assertInstanceOf(
            Imagick::class,
            $image
        );


        $expected = realpath(
            $options['file']
        );

        $I->assertEquals(
            $expected,
            $image->getRealpath()
        );
    }
}
