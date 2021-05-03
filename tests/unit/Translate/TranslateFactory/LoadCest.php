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

namespace Phalcon\Test\Unit\Translate\TranslateFactory;

use Phalcon\Test\Fixtures\Traits\FactoryTrait;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\InterpolatorFactory;
use Phalcon\Translate\TranslateFactory;
use UnitTester;

use function strtolower;

use const PHP_OS;

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

        /**
         * This test will run only on Linux - unless we figure out how to
         * properly set locales on windows/macos
         */
        if ('linux' === strtolower(PHP_OS)) {
            $options      = $this->config->translate;
            $interpolator = new InterpolatorFactory();
            $factory      = new TranslateFactory($interpolator);
            $adapter      = $factory->load($options);
            $locale       = $options->options->locale[0];

            $I->assertInstanceOf(Gettext::class, $adapter);
            $I->assertEquals($options->options->category, $adapter->getCategory());
            $I->assertEquals($locale, $adapter->getLocale());
            $I->assertEquals($options->options->defaultDomain, $adapter->getDefaultDomain());
            $I->assertEquals($options->options->directory, $adapter->getDirectory());
        }
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

        /**
         * This test will run only on Linux - unless we figure out how to
         * properly set locales on windows/macos
         */
        if ('linux' === strtolower(PHP_OS)) {
            $options      = $this->arrayConfig['translate'];
            $interpolator = new InterpolatorFactory();
            $factory      = new TranslateFactory($interpolator);
            $adapter      = $factory->load($options);
            $locale       = $options['options']['locale'][0];

            $I->assertInstanceOf(Gettext::class, $adapter);
            $I->assertEquals($options['options']['category'], $adapter->getCategory());
            $I->assertEquals($locale, $adapter->getLocale());
            $I->assertEquals($options['options']['defaultDomain'], $adapter->getDefaultDomain());
            $I->assertEquals($options['options']['directory'], $adapter->getDirectory());
        }
    }
}
