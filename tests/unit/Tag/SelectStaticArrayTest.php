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
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use ReflectionProperty;

/**
 * Covers Tag\Select::optionsFromArray - the PHP-array source for a SELECT,
 * reached through Tag::selectStatic().
 *
 * The option value is escaped as an attribute and the option text as HTML,
 * through two distinct escaper calls, so both are asserted separately. Nested
 * arrays render as an OPTGROUP and recurse.
 */
final class SelectStaticArrayTest extends AbstractUnitTestCase
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

    public function testEscapesOptionTextAsHtml(): void
    {
        $html = Tag::selectStatic('choices', ['a' => 'One & <Two>']);

        $this->assertStringContainsString('One &amp; &lt;Two&gt;', $html);
    }

    public function testEscapesOptionValueAsAttribute(): void
    {
        $html = Tag::selectStatic('choices', ['a"b' => 'Quoted']);

        $this->assertStringContainsString('value="a&quot;b"', $html);
    }

    public function testMarksTheMatchingOptionSelected(): void
    {
        $html = Tag::selectStatic(
            [
                'choices',
                ['a' => 'Apple', 'b' => 'Banana'],
                'value' => 'b',
            ]
        );

        $this->assertStringContainsString(
            '<option value="a">Apple</option>',
            $html
        );
        $this->assertStringContainsString(
            '<option selected="selected" value="b">Banana</option>',
            $html
        );
    }

    public function testRendersAnEmptyOptionWhenRequested(): void
    {
        $html = Tag::selectStatic(
            [
                'choices',
                ['a' => 'Apple'],
                'useEmpty'   => true,
                'emptyValue' => '0',
                'emptyText'  => 'Pick one',
            ]
        );

        $this->assertStringContainsString(
            '<option value="0">Pick one</option>',
            $html
        );
    }

    public function testRendersNestedArraysAsOptgroup(): void
    {
        $html = Tag::selectStatic(
            [
                'choices',
                [
                    'Fruit' => ['a' => 'Apple', 'b' => 'Banana'],
                    'c'     => 'Carrot',
                ],
            ]
        );

        $this->assertStringContainsString('<optgroup label="Fruit">', $html);
        $this->assertStringContainsString('<option value="a">Apple</option>', $html);
        $this->assertStringContainsString('<option value="b">Banana</option>', $html);
        $this->assertStringContainsString('</optgroup>', $html);
        $this->assertStringContainsString('<option value="c">Carrot</option>', $html);
    }

    public function testRendersOptionsFromAnArray(): void
    {
        $html = Tag::selectStatic('choices', ['a' => 'Apple', 'b' => 'Banana']);

        $this->assertStringContainsString('<select', $html);
        $this->assertStringContainsString('id="choices"', $html);
        $this->assertStringContainsString('<option value="a">Apple</option>', $html);
        $this->assertStringContainsString('<option value="b">Banana</option>', $html);
        $this->assertStringContainsString('</select>', $html);
    }
}
