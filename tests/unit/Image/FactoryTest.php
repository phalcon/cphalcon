<?php

namespace Phalcon\Test\Unit\Image;

use Phalcon\Image\Factory;
use Phalcon\Image\Adapter\Imagick;
use Phalcon\Test\Unit\Factory\Helper\FactoryBase;

/**
 * \Phalcon\Test\Unit\Image\FactoryTest
 * Tests for \Phalcon\Image\Factory component
 *
 * @copyright (c) 2011-present Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Image
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FactoryTest extends FactoryBase
{
    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        if (!class_exists('imagick')) {
            $this->markTestSkipped('Warning: imagick extension is not loaded');
        }
    }

    /**
     * Test factory using Phalcon\Config
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testConfigFactory()
    {
        $this->specify(
            "Factory using Phalcon\\Config doesn't work properly",
            function () {
                $options = $this->config->image;
                /** @var Imagick $image */
                $image = Factory::load($options);
                expect($image)->isInstanceOf(Imagick::class);
                expect($image->getRealpath())->equals(realpath($options->file));
            }
        );
    }

    /**
     * Test factory using array
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testArrayFactory()
    {
        $this->specify(
            "Factory using array doesn't work properly",
            function () {
                $options = $this->arrayConfig["image"];
                /** @var Imagick $image */
                $image = Factory::load($options);
                expect($image)->isInstanceOf(Imagick::class);
                expect($image->getRealpath())->equals(realpath($options["file"]));
            }
        );
    }
}
