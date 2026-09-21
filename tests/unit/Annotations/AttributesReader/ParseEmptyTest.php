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

namespace Phalcon\Tests\Unit\Annotations\AttributesReader;

use Phalcon\Annotations\AttributesReader;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use ReflectionException;

final class ParseEmptyTest extends AbstractUnitTestCase
{
    public function setUp(): void
    {
        $includeFile = Talon::settings()
                            ->supportPath('assets/Annotations/TestClassAttributes.php')
        ;

        require_once $includeFile;
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-20
     */
    public function testAClassWithoutAttributesGivesAnEmptyArray(): void
    {
        $reader = new AttributesReader();

        $this->assertSame([], $reader->parse('TestClassNoAttributes'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-20
     */
    public function testAnUnknownClassThrows(): void
    {
        $this->expectException(ReflectionException::class);

        $reader = new AttributesReader();
        $reader->parse('ThisClassDoesNotExist');
    }
}
