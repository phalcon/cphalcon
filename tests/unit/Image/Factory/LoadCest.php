<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Image\Factory;

use Phalcon\Test\Fixtures\Traits\FactoryTrait;
use Phalcon\Image\Adapter\Imagick;
use Phalcon\Image\Factory;
use UnitTester;

class LoadCest
{
    use FactoryTrait;

    /**
     * @param UnitTester $I
     * @param            $scenario
     */
    public function _before(UnitTester $I, $scenario)
    {
        if (!extension_loaded('imagick')) {
            $scenario->skip('Warning: imagick extension is not loaded');
        }

        $this->init();
    }

    /**
     * Tests Phalcon\Image\Factory :: load() - Phalcon\Config
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testConfigFactory(UnitTester $I)
    {
        $options = $this->config->image;
        /** @var Imagick $image */
        $image  = Factory::load($options);
        $class  = Imagick::class;
        $actual = $image;
        $I->assertInstanceOf($class, $actual);

        $expected = realpath($options->file);
        $actual   = $image->getRealpath();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Image\Factory :: load() - array
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testArrayFactory(UnitTester $I)
    {
        $options = $this->arrayConfig["image"];
        /** @var Imagick $image */
        $image  = Factory::load($options);
        $class  = Imagick::class;
        $actual = $image;
        $I->assertInstanceOf($class, $actual);

        $expected = realpath($options["file"]);
        $actual   = $image->getRealpath();
        $I->assertEquals($expected, $actual);
    }
}
