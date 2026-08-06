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

namespace Phalcon\Tests\Unit\Translate\TranslateFactory;

use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\FactoryTrait;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\Exceptions\TranslatorNotRegistered;
use Phalcon\Translate\InterpolatorFactory;
use Phalcon\Translate\TranslateFactory;
use PHPUnit\Framework\Attributes\RequiresPhpExtension;

use function strtolower;

use const PHP_OS;

#[RequiresPhpExtension('gettext')]
final class LoadTest extends AbstractUnitTestCase
{
    use FactoryTrait;

    public function setUp(): void
    {
        $this->init();
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testTranslateFactoryLoadArray(): void
    {

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

            $this->assertInstanceOf(Gettext::class, $adapter);
            $this->assertSame($options['options']['category'], $adapter->getCategory());
            $this->assertSame($locale, $adapter->getLocale());
            $this->assertSame($options['options']['defaultDomain'], $adapter->getDefaultDomain());
            $this->assertSame($options['options']['directory'], $adapter->getDirectory());
        }
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testTranslateFactoryLoadConfig(): void
    {

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

            $this->assertInstanceOf(Gettext::class, $adapter);
            $this->assertSame($options->options->category, $adapter->getCategory());
            $this->assertSame($locale, $adapter->getLocale());
            $this->assertSame($options->options->defaultDomain, $adapter->getDefaultDomain());
            $this->assertSame($options->options->directory, $adapter->getDirectory());
        }
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-05
     */
    public function testTranslateFactoryLoadException(): void
    {
        $factory = new TranslateFactory(new InterpolatorFactory());

        $this->expectException(TranslatorNotRegistered::class);
        $this->expectExceptionMessage(
            "You must provide the 'adapter' option in the factory config parameter."
        );

        $factory->load([]);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-05
     */
    public function testTranslateFactoryLoadExceptionInvalidConfig(): void
    {
        $factory = new TranslateFactory(new InterpolatorFactory());

        $this->expectException(TranslatorNotRegistered::class);
        $this->expectExceptionMessage(
            'Config must be array or Phalcon\Config\Config object'
        );

        $factory->load(1234);
    }
}
