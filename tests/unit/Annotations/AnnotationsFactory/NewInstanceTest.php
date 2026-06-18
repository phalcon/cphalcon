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
use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Annotations\Adapter\Stream;
use Phalcon\Annotations\AnnotationsFactory;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class NewInstanceTest extends AbstractUnitTestCase
{
    /**
     * @return array<array<string>>
     */
    public static function getExamples(): array
    {
        return [
            ['apcu', Apcu::class],
            ['memory', Memory::class],
            ['stream', Stream::class],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-19
     */
    #[DataProvider('getExamples')]
    public function testAnnotationsFactoryNewInstance(string $name, string $class): void
    {
        $factory  = new AnnotationsFactory();
        $instance = $factory->newInstance($name);

        $this->assertInstanceOf($class, $instance);
    }
}
