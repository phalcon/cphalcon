<?php

namespace Phalcon\Test\Unit\Translate;

use Phalcon\Translate\Factory;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Test\Unit\Factory\Helper\FactoryBase;

/**
 * \Phalcon\Test\Unit\Translate\FactoryTest
 * Tests for \Phalcon\Translate\Factory component
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
        if (!extension_loaded('gettext')) {
            $this->markTestSkipped('Warning: gettext extension is not loaded');
        }

        $this->specify(
            "Factory using Phalcon\\Config doesn't work properly",
            function () {
                $options = $this->config->translate;
                /** @var Gettext $translate */
                $translate = Factory::load($options);
                expect($translate)->isInstanceOf(Gettext::class);
                expect($translate->getCategory())->equals($options->category);
                expect($translate->getLocale())->equals($options->locale);
                expect($translate->getDefaultDomain())->equals($options->defaultDomain);
                expect($translate->getDirectory())->equals($options->directory);
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
        if (!extension_loaded('gettext')) {
            $this->markTestSkipped('Warning: gettext extension is not loaded');
        }

        $this->specify(
            "Factory using array doesn't work properly",
            function () {
                $options = $this->arrayConfig["translate"];
                /** @var Gettext $translate */
                $translate = Factory::load($options);
                expect($translate)->isInstanceOf(Gettext::class);
                expect($translate->getCategory())->equals($options["category"]);
                expect($translate->getLocale())->equals($options["locale"]);
                expect($translate->getDefaultDomain())->equals($options["defaultDomain"]);
                expect($translate->getDirectory())->equals($options["directory"]);
            }
        );
    }
}
