<?php

namespace Phalcon\Test\Unit\Config;

use Phalcon\Config\Factory;
use Phalcon\Config\Adapter\Ini;
use Phalcon\Test\Unit\Factory\Helper\FactoryBase;

/**
 * \Phalcon\Test\Unit\Config\FactoryTest
 * Tests for \Phalcon\Config\Factory component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Annotations
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
                $options = $this->config->config;
                /** @var Ini $ini */
                $ini = Factory::load($options);
                expect($ini)->isInstanceOf(Ini::class);
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
                $options = $this->arrayConfig["config"];
                /** @var Ini $ini */
                $ini = Factory::load($options);
                expect($ini)->isInstanceOf(Ini::class);
            }
        );
    }

    /**
     * Test factory using array
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-11-24
     */
    public function testStringFactory()
    {
        $this->specify(
            "Factory using string doesn't work properly",
            function () {
                $filePath = $this->arrayConfig['config']['filePathExtension'];
                /** @var Ini $ini */
                $ini = Factory::load($filePath);
                expect($ini)->isInstanceOf(Ini::class);
            }
        );
    }
}
