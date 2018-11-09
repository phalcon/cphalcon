<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Image;

use Phalcon\Image\Factory;
use Phalcon\Image\Adapter\Imagick;
use Phalcon\Test\Unit\Factory\Helper\FactoryBase;
use UnitTester;

class FactoryTest
{
    /**
     * executed before each test
     */
    protected function _before(UnitTester $I, $scenario)
    {
        if (!class_exists('imagick')) {
            $scenario->skip('Warning: imagick extension is not loaded');
        }
    }

    /**
     * Test factory using Phalcon\Config
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testConfigFactory(UnitTester $I)
    {
        $options = $this->config->image;
        /** @var Imagick $image */
        $image = Factory::load($options);
        expect($image)->isInstanceOf(Imagick::class);
        expect($image->getRealpath())->equals(realpath($options->file));
    }

    /**
     * Test factory using array
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
