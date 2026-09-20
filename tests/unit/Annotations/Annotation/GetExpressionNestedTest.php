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

namespace Phalcon\Tests\Unit\Annotations\Annotation;

use Phalcon\Annotations\Annotation;
use Phalcon\Annotations\Reader;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class GetExpressionNestedTest extends AbstractUnitTestCase
{
    /**
     * An annotation in an argument becomes an Annotation object, and an
     * annotation in an array item becomes one as well.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-19
     */
    public function testAnnotationsAnnotationGetExpressionNested(): void
    {
        $docBlock = '/** @Outer(@Inner("first"), {"key": @Deep("second")}) */';

        $parsed = Reader::parseDocBlock($docBlock);

        $this->assertIsArray($parsed);

        $annotation = new Annotation($parsed[0]);

        $inner = $annotation->getArgument(0);
        $this->assertInstanceOf(Annotation::class, $inner);
        $this->assertSame('Inner', $inner->getName());
        $this->assertSame('first', $inner->getArgument(0));

        $hash = $annotation->getArgument(1);
        $this->assertIsArray($hash);

        $deep = $hash['key'];
        $this->assertInstanceOf(Annotation::class, $deep);
        $this->assertSame('Deep', $deep->getName());
        $this->assertSame('second', $deep->getArgument(0));
    }
}
