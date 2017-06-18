<?php

namespace Phalcon\Test\Unit\Cache\Backend;

use Phalcon\Cache\Backend\Apc;
use Phalcon\Cache\Backend\Factory;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Test\Unit\Factory\Helper\FactoryBase;

/**
 * \Phalcon\Test\Unit\Cache\Backend\FactoryTest
 * Tests for \Phalcon\Cache\Backend\Factory component
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
                $options = $this->config->cache_backend;
                /** @var Apc $cache */
                $cache = Factory::load($options);
                expect($cache)->isInstanceOf(Apc::class);
                expect(array_intersect_assoc($cache->getOptions(), $options->toArray()))->equals($cache->getOptions());
                expect($cache->getFrontend())->isInstanceOf(Data::class);
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
                $options = $this->arrayConfig["cache_backend"];
                /** @var Apc $cache */
                $cache = Factory::load($options);
                expect($cache)->isInstanceOf(Apc::class);
                expect(array_intersect_assoc($cache->getOptions(), $options))->equals($cache->getOptions());
                expect($cache->getFrontend())->isInstanceOf(Data::class);
            }
        );
    }
}
