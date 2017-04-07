<?php

namespace Phalcon\Test\Unit\Session;

use Phalcon\Di;
use Phalcon\Session\Factory;
use Phalcon\Session\Adapter\Memcache;
use Phalcon\Test\Unit\Factory\Helper\FactoryBase;

/**
 * \Phalcon\Test\Unit\Session\FactoryTest
 * Tests for \Phalcon\Session\Factory component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Annotations
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
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
                $options = $this->config->session;
                /** @var Memcache $session */
                $session = Factory::load($options);
                expect($session)->isInstanceOf(Memcache::class);
                expect(array_intersect_assoc($session->getOptions(), $options->toArray()))->equals(
                    $session->getOptions()
                );
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
                $options = $this->arrayConfig['session'];
                /** @var Memcache $session */
                $session = Factory::load($options);
                expect($session)->isInstanceOf(Memcache::class);
                expect(array_intersect_assoc($session->getOptions(), $options))->equals($session->getOptions());
            }
        );
    }

    /**
     * Test factory for di using Phalcon\Config
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-04-07
     */
    public function testDiConfigFactory()
    {
        $this->specify(
            "Factory for di using Phalcon\\Config doesn't work properly",
            function () {
                $di = new Di();
                $options = $this->config->session;
                /** @var Memcache $session */
                $di->set('session', Factory::loadForDi($options));
                $session = $di->get('session');
                expect($session)->isInstanceOf(Memcache::class);
                expect(array_intersect_assoc($session->getOptions(), $options->toArray()))->equals(
                    $session->getOptions()
                );
            }
        );
    }

    /**
     * Test factory for di using array
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-04-07
     */
    public function testDiArrayFactory()
    {
        $this->specify(
            "Factory for di using array doesn't work properly",
            function () {
                $di = new Di();
                $options = $this->arrayConfig['session'];
                /** @var Memcache $session */
                $di->set('session', Factory::loadForDi($options));
                $session = $di->get('session');
                expect($session)->isInstanceOf(Memcache::class);
            }
        );
    }
}
