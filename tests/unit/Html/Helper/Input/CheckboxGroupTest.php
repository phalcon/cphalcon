<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Input;

use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Doctype;
use Phalcon\Html\Helper\Input\CheckboxGroup;
use Phalcon\Tests\AbstractUnitTestCase;

use const PHP_EOL;

final class CheckboxGroupTest extends AbstractUnitTestCase
{
    private function helper(): CheckboxGroup
    {
        return new CheckboxGroup(new Escaper(), new Doctype());
    }

    // -----------------------------------------------------------------------
    // Basic rendering
    // -----------------------------------------------------------------------

    public function testRendersStringLabelOptions(): void
    {
        $helper = $this->helper();
        $result = $helper(
            'color',
            ['red' => 'Red', 'blue' => 'Blue'],
        );

        $rendered = (string) $result;

        $this->assertStringContainsString('type="checkbox"', $rendered);
        $this->assertStringContainsString('name="color"', $rendered);
        $this->assertStringContainsString('value="red"', $rendered);
        $this->assertStringContainsString('value="blue"', $rendered);
        $this->assertStringContainsString('>Red</label>', $rendered);
        $this->assertStringContainsString('>Blue</label>', $rendered);
    }

    public function testRendersRichDefinitionOptions(): void
    {
        $helper = $this->helper();
        $result = $helper(
            'color',
            ['red' => ['label' => 'Red Color']],
        );

        $rendered = (string) $result;

        $this->assertStringContainsString('>Red Color</label>', $rendered);
    }

    public function testAutoGeneratesIdFromNameAndValue(): void
    {
        $helper = $this->helper();
        $result = $helper('my_field', ['opt1' => 'Option 1']);

        $rendered = (string) $result;

        $this->assertStringContainsString('id="my_field_opt1"', $rendered);
        $this->assertStringContainsString('for="my_field_opt1"', $rendered);
    }

    public function testAutoGeneratesIdForArrayName(): void
    {
        $helper = $this->helper();
        $result = $helper('tags[]', ['php' => 'PHP']);

        $rendered = (string) $result;

        $this->assertStringContainsString('id="tags_php"', $rendered);
        $this->assertStringContainsString('for="tags_php"', $rendered);
    }

    // -----------------------------------------------------------------------
    // Checked state
    // -----------------------------------------------------------------------

    public function testMarksCheckedWhenValueInArray(): void
    {
        $helper = $this->helper();
        $result = $helper(
            'colors',
            ['red' => 'Red', 'blue' => 'Blue', 'green' => 'Green'],
            ['red', 'green'],
        );

        $rendered = (string) $result;

        // Parse lines to verify per-item state
        $lines = explode(PHP_EOL, $rendered);

        $this->assertStringContainsString('value="red"', $lines[0]);
        $this->assertStringContainsString('checked="checked"', $lines[0]);

        $this->assertStringContainsString('value="blue"', $lines[1]);
        $this->assertStringNotContainsString('checked', $lines[1]);

        $this->assertStringContainsString('value="green"', $lines[2]);
        $this->assertStringContainsString('checked="checked"', $lines[2]);
    }

    public function testSingleScalarCheckedTreatedAsOneElementArray(): void
    {
        $helper = $this->helper();
        $result = $helper(
            'colors',
            ['red' => 'Red', 'blue' => 'Blue'],
            'red',
        );

        $rendered = (string) $result;
        $lines    = explode(PHP_EOL, $rendered);

        $this->assertStringContainsString('checked="checked"', $lines[0]);
        $this->assertStringNotContainsString('checked', $lines[1]);
    }

    public function testNullCheckedRendersNoCheckedAttr(): void
    {
        $helper = $this->helper();
        $result = $helper('colors', ['red' => 'Red']);

        $rendered = (string) $result;

        $this->assertStringNotContainsString('checked', $rendered);
    }

    public function testEmptyArrayCheckedRendersNoCheckedAttr(): void
    {
        $helper = $this->helper();
        $result = $helper('colors', ['red' => 'Red'], []);

        $rendered = (string) $result;

        $this->assertStringNotContainsString('checked', $rendered);
    }

    // -----------------------------------------------------------------------
    // Shared attributes
    // -----------------------------------------------------------------------

    public function testSharedAttributesAppliedToAllInputs(): void
    {
        $helper = $this->helper();
        $result = $helper(
            'colors',
            ['red' => 'Red', 'blue' => 'Blue'],
            null,
            ['class' => 'chk'],
        );

        $rendered = (string) $result;
        $lines    = explode(PHP_EOL, $rendered);

        foreach ($lines as $line) {
            if (str_contains($line, '<input')) {
                $this->assertStringContainsString('class="chk"', $line);
            }
        }
    }

    // -----------------------------------------------------------------------
    // Per-item attributes
    // -----------------------------------------------------------------------

    public function testPerItemAttributesOverrideShared(): void
    {
        $helper = $this->helper();
        $result = $helper(
            'colors',
            ['red' => ['label' => 'Red', 'class' => 'item-red', 'disabled' => 'disabled']],
            null,
            ['class' => 'shared'],
        );

        $rendered = (string) $result;

        $this->assertStringContainsString('disabled="disabled"', $rendered);
    }

    public function testPerItemExplicitIdIsRespected(): void
    {
        $helper = $this->helper();
        $result = $helper(
            'colors',
            ['red' => ['label' => 'Red', 'id' => 'my-red']],
        );

        $rendered = (string) $result;

        $this->assertStringContainsString('id="my-red"', $rendered);
        $this->assertStringContainsString('for="my-red"', $rendered);
    }

    // -----------------------------------------------------------------------
    // State reset between invocations
    // -----------------------------------------------------------------------

    public function testStateIsResetBetweenCasts(): void
    {
        $helper = $this->helper();

        $helper('colors', ['red' => 'Red'], ['red']);
        $rendered1 = (string) $helper;

        // Second cast on the same object: options were cleared
        $helper('sizes', ['small' => 'Small']);
        $rendered2 = (string) $helper;

        $this->assertStringContainsString('name="sizes"', $rendered2);
        $this->assertStringNotContainsString('name="colors"', $rendered2);
        $this->assertStringNotContainsString('checked', $rendered2);
    }

    // -----------------------------------------------------------------------
    // Output structure: items separated by PHP_EOL
    // -----------------------------------------------------------------------

    public function testItemsSeparatedByNewline(): void
    {
        $helper = $this->helper();
        $result = $helper('x', ['a' => 'A', 'b' => 'B', 'c' => 'C']);

        $rendered = (string) $result;
        $lines    = explode(PHP_EOL, $rendered);

        $this->assertCount(3, $lines);
    }

    // -----------------------------------------------------------------------
    // Empty options
    // -----------------------------------------------------------------------

    public function testEmptyOptionsRendersEmptyString(): void
    {
        $helper = $this->helper();
        $result = $helper('x', []);

        $this->assertSame('', (string) $result);
    }

    // -----------------------------------------------------------------------
    // HTML escaping
    // -----------------------------------------------------------------------

    public function testLabelTextIsEscaped(): void
    {
        $helper = $this->helper();
        $result = $helper('x', ['val' => '<b>Bold</b>']);

        $rendered = (string) $result;

        $this->assertStringNotContainsString('<b>', $rendered);
        $this->assertStringContainsString('&lt;b&gt;', $rendered);
    }
}
