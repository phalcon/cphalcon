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

class LoadCest
{
    use FactoryTrait;

    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('gettext');

        $this->init();
    }

    /**
     * Tests Phalcon\Translate\Factory :: load() - Phalcon\Config
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

        $I->assertInstanceOf(
            Gettext::class,
            $translate
        );

        $I->assertEquals(
            $options->category,
            $translate->getCategory()
        );

        $I->assertEquals(
            $options->locale,
            $translate->getLocale()
        );

        $I->assertEquals(
            $options->defaultDomain,
            $translate->getDefaultDomain()
        );

        $I->assertEquals(
            $options->directory,
            $translate->getDirectory()
        );
    }

    /**
     * Tests Phalcon\Translate\Factory :: load() - array
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

        $I->assertInstanceOf(
            Gettext::class,
            $translate
        );

        $I->assertEquals(
            $options['category'],
            $translate->getCategory()
        );

        $I->assertEquals(
            $options['locale'],
            $translate->getLocale()
        );

        $I->assertEquals(
            $options['defaultDomain'],
            $translate->getDefaultDomain()
        );

        $I->assertEquals(
            $options['directory'],
            $translate->getDirectory()
        );
    }
}
