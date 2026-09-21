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

use Phalcon\Annotations\Annotation;
use Phalcon\Annotations\AttributesReader;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;

final class ParseTest extends AbstractUnitTestCase
{
    public function setUp(): void
    {
        $includeFile = Talon::settings()
                            ->supportPath('assets/Annotations/TestClassAttributes.php')
        ;

        $this->assertFileExists($includeFile);

        require_once $includeFile;
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-20
     */
    public function testParseReadsTheClassAttributes(): void
    {
        $reader  = new AttributesReader();
        $parsing = $reader->parse('TestClassAttributes');

        $this->assertArrayHasKey('class', $parsing);
        $this->assertCount(2, $parsing['class']);
        $this->assertSame('RoutePrefix', $parsing['class'][0]['name']);
        $this->assertSame(
            '/test',
            $parsing['class'][0]['arguments'][0]['expr']['value']
        );
        $this->assertSame(
            Annotation::T_RESOLVED,
            $parsing['class'][0]['arguments'][0]['expr']['type']
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-20
     */
    public function testParseReadsTheConstantAttributes(): void
    {
        $reader  = new AttributesReader();
        $parsing = $reader->parse('TestClassAttributes');

        $this->assertArrayHasKey('constants', $parsing);
        $this->assertArrayHasKey('STATUS', $parsing['constants']);
        $this->assertSame('Primary', $parsing['constants']['STATUS'][0]['name']);
        $this->assertArrayNotHasKey(
            'arguments',
            $parsing['constants']['STATUS'][0]
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-20
     */
    public function testParseReadsTheMethodAttributesAndSkipsPlainMethods(): void
    {
        $reader  = new AttributesReader();
        $parsing = $reader->parse('TestClassAttributes');

        $this->assertArrayHasKey('methods', $parsing);
        $this->assertArrayHasKey('indexAction', $parsing['methods']);
        $this->assertArrayNotHasKey('plainAction', $parsing['methods']);

        $node = $parsing['methods']['indexAction'][0];

        $this->assertSame('Get', $node['name']);
        $this->assertArrayNotHasKey('name', $node['arguments'][0]);
        $this->assertSame('/test/index', $node['arguments'][0]['expr']['value']);
        $this->assertSame('name', $node['arguments'][1]['name']);
        $this->assertSame('test-index', $node['arguments'][1]['expr']['value']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-20
     */
    public function testParseReadsThePropertyAttributes(): void
    {
        $reader  = new AttributesReader();
        $parsing = $reader->parse('TestClassAttributes');

        $this->assertArrayHasKey('properties', $parsing);
        $this->assertArrayHasKey('name', $parsing['properties']);

        $node = $parsing['properties']['name'][0];

        $this->assertSame('Column', $node['name']);
        $this->assertSame('type', $node['arguments'][0]['name']);
        $this->assertSame('varchar', $node['arguments'][0]['expr']['value']);
        $this->assertSame('length', $node['arguments'][1]['name']);
        $this->assertSame(70, $node['arguments'][1]['expr']['value']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-20
     */
    public function testParseSetsTheFileAndTheLine(): void
    {
        $reader  = new AttributesReader();
        $parsing = $reader->parse('TestClassAttributes');

        $this->assertStringEndsWith(
            'TestClassAttributes.php',
            $parsing['class'][0]['file']
        );
        $this->assertIsInt($parsing['class'][0]['line']);
        $this->assertSame(1, $parsing['constants']['STATUS'][0]['line']);
        $this->assertSame(1, $parsing['properties']['name'][0]['line']);
        $this->assertGreaterThan(1, $parsing['methods']['indexAction'][0]['line']);
    }
}
