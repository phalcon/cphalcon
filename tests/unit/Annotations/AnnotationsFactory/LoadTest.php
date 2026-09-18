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

namespace Phalcon\Tests\Unit\Annotations\AnnotationsFactory;

use Phalcon\Annotations\Adapter\Apcu;
use Phalcon\Annotations\AnnotationsFactory;
use Phalcon\Annotations\Exception;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\FactoryTrait;

final class LoadTest extends AbstractUnitTestCase
{
    use FactoryTrait;

    protected function setUp(): void
    {
        parent::setUp();

        $this->init();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-18
     */
    public function testAnnotationsFactoryLoad(): void
    {
        $options = $this->config->annotations;
        $this->runFactoryTests($options);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-18
     */
    public function testAnnotationsFactoryLoadArray(): void
    {
        $options = $this->arrayConfig['annotations'];
        $this->runFactoryTests($options);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-05
     */
    public function testAnnotationsFactoryLoadException(): void
    {
        $factory = new AnnotationsFactory();

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "You must provide the 'adapter' option in the factory config parameter."
        );

        $factory->load([]);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-05
     */
    public function testAnnotationsFactoryLoadExceptionInvalidConfig(): void
    {
        $factory = new AnnotationsFactory();

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Config must be array or Phalcon\Config\Config object'
        );

        $factory->load(1234);
    }

    private function runFactoryTests(mixed $options): void
    {
        $factory = new AnnotationsFactory();
        $adapter = $factory->load($options);

        $this->assertInstanceOf(Apcu::class, $adapter);
    }
}
