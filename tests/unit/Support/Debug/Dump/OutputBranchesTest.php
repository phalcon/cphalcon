<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Support\Debug\Dump;

use Phalcon\Di\Di;
use Phalcon\Support\Debug\Dump;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Support\Dump\ClassProperties;
use Phalcon\Tests\Support\Support\Dump\ClassUninitialized;
use Phalcon\Tests\Support\Support\Dump\SampleMethods;

final class OutputBranchesTest extends AbstractUnitTestCase
{
    public function testAlreadyListedMethods(): void
    {
        $dump   = new Dump();
        $actual = $dump->variables(new SampleMethods(), new SampleMethods());

        $this->assertStringContainsString('[already listed]', $actual);
    }

    public function testArraySelfReferenceKeyIsSkipped(): void
    {
        $key    = uniqid('var-');
        $value  = uniqid('val-');
        $dump   = new Dump();
        $actual = $dump->variable([$key => $value], $key);

        $this->assertStringContainsString($key, $actual);
        $this->assertStringNotContainsString($value, $actual);
    }

    public function testBoolean(): void
    {
        $dump = new Dump();

        $this->assertStringContainsString('TRUE', $dump->variable(true));
        $this->assertStringContainsString('FALSE', $dump->variable(false));
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/17735
     */
    public function testDetailedObjectUninitializedProperties(): void
    {
        $dump   = new Dump([], true);
        $actual = $dump->variable(new ClassUninitialized());

        $expected = '-><span style="color:purple">count</span> '
            . '(<span style="color:purple">public</span>) = [uninitialized]';
        $this->assertStringContainsString($expected, $actual);

        $expected = '-><span style="color:purple">name</span> '
            . '(<span style="color:purple">protected</span>) = [uninitialized]';
        $this->assertStringContainsString($expected, $actual);

        $expected = '-><span style="color:purple">data</span> '
            . '(<span style="color:purple">private</span>) = [uninitialized]';
        $this->assertStringContainsString($expected, $actual);

        $expected = '-><span style="color:purple">total</span> '
            . '(<span style="color:purple">public</span>) = '
            . '<b style="color:blue">Integer</b> (<span style="color:blue">5</span>)';
        $this->assertStringContainsString($expected, $actual);
    }

    public function testDetailedObjectUsesReflection(): void
    {
        $dump   = new Dump([], true);
        $actual = $dump->variable(new ClassProperties());

        $this->assertStringContainsString('protected', $actual);
        $this->assertStringContainsString('private', $actual);
    }

    public function testFloat(): void
    {
        $this->assertStringContainsString('Float', (new Dump())->variable(3.14));
    }

    public function testNull(): void
    {
        $this->assertStringContainsString('NULL', (new Dump())->variable(null));
    }

    public function testNumericString(): void
    {
        $this->assertStringContainsString('Numeric String', (new Dump())->variable('12345'));
    }

    public function testResolvesParentClassAndMethodNames(): void
    {
        $actual = (new Dump())->variable(new SampleMethods());

        $this->assertStringContainsString('extends', $actual);
        $this->assertStringContainsString('ClassProperties', $actual);
        $this->assertStringContainsString('sample', $actual);
        $this->assertStringNotContainsString('{parent}', $actual);
        $this->assertStringNotContainsString(':method', $actual);
    }

    public function testResourceFallback(): void
    {
        $resource = fopen('php://memory', 'r');
        $actual   = (new Dump())->variable($resource);
        fclose($resource);

        $this->assertStringContainsString('Resource', $actual);
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/17746
     */
    public function testSkippedKeyEndsItsLine(): void
    {
        $actual = (new Dump())->variable(['config' => 1, 'other' => 2], 'config');

        $this->assertStringContainsString("=> \n  [", $actual);
    }

    public function testSkipsDiInterface(): void
    {
        $actual = (new Dump())->variable(new Di());

        $this->assertStringContainsString('[skipped]', $actual);
    }
}
