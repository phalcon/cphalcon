<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Translate;

use Helper\Traits\FactoryTrait;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\Factory;
use UnitTester;

class FactoryCest
{
    use FactoryTrait;

    public function _before(UnitTester $I, $scenario)
    {
        if (!extension_loaded('gettext')) {
            $scenario->skip('Warning: gettext extension is not loaded');
        }

        $this->init();
    }

    /**
     * Test factory using Phalcon\Config
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testConfigFactory(UnitTester $I, $scenario)
    {
        $options = $this->config->translate;
        /** @var Gettext $translate */
        $translate = Factory::load($options);

        $class  = Gettext::class;
        $actual = $translate;
        $I->assertInstanceOf($class, $actual);

        $expected = $options->category;
        $actual   = $translate->getCategory();
        $I->assertEquals($expected, $actual);

        $expected = $options->locale;
        $actual   = $translate->getLocale();
        $I->assertEquals($expected, $actual);

        $expected = $options->defaultDomain;
        $actual   = $translate->getDefaultDomain();
        $I->assertEquals($expected, $actual);

        $expected = $options->directory;
        $actual   = $translate->getDirectory();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Test factory using array
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testArrayFactory(UnitTester $I)
    {
        $options = $this->arrayConfig["translate"];
        /** @var Gettext $translate */
        $translate = Factory::load($options);

        $class  = Gettext::class;
        $actual = $translate;
        $I->assertInstanceOf($class, $actual);

        $expected = $options['category'];
        $actual   = $translate->getCategory();
        $I->assertEquals($expected, $actual);

        $expected = $options['locale'];
        $actual   = $translate->getLocale();
        $I->assertEquals($expected, $actual);

        $expected = $options['defaultDomain'];
        $actual   = $translate->getDefaultDomain();
        $I->assertEquals($expected, $actual);

        $expected = $options['directory'];
        $actual   = $translate->getDirectory();
        $I->assertEquals($expected, $actual);
    }
}
