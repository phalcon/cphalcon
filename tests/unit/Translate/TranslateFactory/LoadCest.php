<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Translate\Factory;

use Phalcon\Test\Fixtures\Traits\FactoryTrait;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\InterpolatorFactory;
use Phalcon\Translate\TranslateFactory;
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

        $options      = $this->config->translate;
        $interpolator = new InterpolatorFactory();
        $factory      = new TranslateFactory($interpolator);
        $adapter      = $factory->load($options);

        $I->assertInstanceOf(
            Gettext::class,
            $adapter
        );

        $I->assertEquals(
            $options->options->category,
            $adapter->getCategory()
        );

        $I->assertEquals(
            $options->options->locale,
            $adapter->getLocale()
        );

        $I->assertEquals(
            $options->options->defaultDomain,
            $adapter->getDefaultDomain()
        );

        $I->assertEquals(
            $options->options->directory,
            $adapter->getDirectory()
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

        $options      = $this->arrayConfig['translate'];
        $interpolator = new InterpolatorFactory();
        $factory      = new TranslateFactory($interpolator);
        $adapter      = $factory->load($options);

        $I->assertInstanceOf(
            Gettext::class,
            $adapter
        );

        $I->assertEquals(
            $options['options']['category'],
            $adapter->getCategory()
        );

        $I->assertEquals(
            $options['options']['locale'],
            $adapter->getLocale()
        );

        $I->assertEquals(
            $options['options']['defaultDomain'],
            $adapter->getDefaultDomain()
        );

        $I->assertEquals(
            $options['options']['directory'],
            $adapter->getDirectory()
        );
    }
}
