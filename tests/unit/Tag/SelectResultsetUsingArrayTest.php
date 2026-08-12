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

namespace Phalcon\Tests\Unit\Tag;

use Phalcon\Di\Di;
use Phalcon\Html\Escaper;
use Phalcon\Tag;
use Phalcon\Tag\Select;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Html\Helper\Input\Select\Fake\FakeResultset;
use ReflectionProperty;

/**
 * Covers the resultset + array `using` branch of Tag\Select::selectField,
 * which names the value and text attributes to read off each row.
 *
 * A row is read one of three ways, and each is a separate code path:
 *
 *  - an object exposing `readAttribute()` (a model), read through that method
 *  - any other object, read as a dynamic property
 *  - a plain array, read as an offset
 *
 * The dynamic-property path is the reason this file exists: it previously
 * read the literal property names `usingZero`/`usingOne` instead of resolving
 * them through the `using` values, so it returned nothing for every row.
 */
final class SelectResultsetUsingArrayTest extends AbstractUnitTestCase
{
    public function setUp(): void
    {
        $container = new Di();
        $container->setShared('escaper', new Escaper());

        Tag::setDI($container);
        Tag::setAutoescape(false);
    }

    public function tearDown(): void
    {
        Tag::setAutoescape(true);

        (new ReflectionProperty(Tag::class, 'container'))->setValue(null, null);
    }

    public function testEscapesValueAndText(): void
    {
        $resultset = new FakeResultset(
            [
                ['id' => 'a"b', 'name' => 'One & <Two>'],
            ]
        );

        $html = Select::selectField(
            [
                'choices',
                $resultset,
                'using' => ['id', 'name'],
            ]
        );

        $this->assertStringContainsString('value="a&quot;b"', $html);
        $this->assertStringContainsString('One &amp; &lt;Two&gt;', $html);
    }

    public function testMarksTheMatchingOptionSelected(): void
    {
        $resultset = new FakeResultset(
            [
                ['id' => 1, 'name' => 'One'],
                ['id' => 2, 'name' => 'Two'],
            ]
        );

        $html = Select::selectField(
            [
                'choices',
                $resultset,
                'value' => 2,
                'using' => ['id', 'name'],
            ]
        );

        $this->assertStringContainsString(
            '<option value="1">One</option>',
            $html
        );
        $this->assertStringContainsString(
            '<option selected="selected" value="2">Two</option>',
            $html
        );
    }

    public function testReadsArrayRowsByOffset(): void
    {
        $resultset = new FakeResultset(
            [
                ['id' => 1, 'name' => 'One'],
                ['id' => 2, 'name' => 'Two'],
            ]
        );

        $html = Select::selectField(
            [
                'choices',
                $resultset,
                'using' => ['id', 'name'],
            ]
        );

        $this->assertStringContainsString('<select', $html);
        $this->assertStringContainsString('id="choices"', $html);
        $this->assertStringContainsString('<option value="1">One</option>', $html);
        $this->assertStringContainsString('<option value="2">Two</option>', $html);
        $this->assertStringContainsString('</select>', $html);
    }

    public function testReadsObjectRowsByDynamicProperty(): void
    {
        $resultset = new FakeResultset(
            [
                new class {
                    public int $id      = 1;
                    public string $name = 'One';
                },
                new class {
                    public int $id      = 2;
                    public string $name = 'Two';
                },
            ]
        );

        $html = Select::selectField(
            [
                'choices',
                $resultset,
                'using' => ['id', 'name'],
            ]
        );

        $this->assertStringContainsString('<option value="1">One</option>', $html);
        $this->assertStringContainsString('<option value="2">Two</option>', $html);
    }

    public function testReadsObjectRowsThroughReadAttribute(): void
    {
        $resultset = new FakeResultset(
            [
                new class {
                    /**
                     * @var array<string, mixed>
                     */
                    private array $data = ['id' => 1, 'name' => 'One'];

                    public function readAttribute(string $name): mixed
                    {
                        return $this->data[$name] ?? null;
                    }
                },
            ]
        );

        $html = Select::selectField(
            [
                'choices',
                $resultset,
                'using' => ['id', 'name'],
            ]
        );

        $this->assertStringContainsString('<option value="1">One</option>', $html);
    }

    public function testRejectsUsingWithWrongArity(): void
    {
        $resultset = new FakeResultset([['id' => 1, 'name' => 'One']]);

        $this->expectException(\Phalcon\Tag\Exception::class);
        $this->expectExceptionMessage("Parameter 'using' requires two values");

        Select::selectField(
            [
                'choices',
                $resultset,
                'using' => ['id'],
            ]
        );
    }
}
