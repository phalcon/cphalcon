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

namespace Phalcon\Test\Unit\Translate\Factory;

use Phalcon\Test\Fixtures\Traits\FactoryTrait;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\Factory;
use UnitTester;

/**
 * Class LoadCest
 */
class LoadCest
{
    use FactoryTrait;

    /**
     * @param UnitTester $I
     */
    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('gettext');

        $this->init();
    }

    /**
     * Tests Phalcon\Translate\Factory :: load() - Phalcon\Config
     *
     * @param UnitTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function translateFactoryLoadConfig(UnitTester $I)
    {
        $I->wantToTest('Translate\Factory - load() - Config');
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
     * Tests Phalcon\Translate\Factory :: load() - array
     *
     * @param UnitTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function translateFactoryLoadArray(UnitTester $I)
    {
        $I->wantToTest('Translate\Factory - load() - array');
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
