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
use Phalcon\Html\Helper\Input\RadioGroup;
use Phalcon\Tests\AbstractUnitTestCase;

use const PHP_EOL;

final class RadioGroupTest extends AbstractUnitTestCase
{
    private function helper(): RadioGroup
    {
        return new RadioGroup(new Escaper(), new Doctype());
    }

    // -----------------------------------------------------------------------
    // Basic rendering
    // -----------------------------------------------------------------------

    public function testRendersStringLabelOptions(): void
    {
        $helper = $this->helper();
        $result = $helper(
            'gender',
            ['m' => 'Male', 'f' => 'Female'],
        );

        $rendered = (string) $result;

        $this->assertStringContainsString('type="radio"', $rendered);
        $this->assertStringContainsString('name="gender"', $rendered);
        $this->assertStringContainsString('value="m"', $rendered);
        $this->assertStringContainsString('value="f"', $rendered);
        $this->assertStringContainsString('>Male</label>', $rendered);
        $this->assertStringContainsString('>Female</label>', $rendered);
    }

    public function testRendersRichDefinitionOptions(): void
    {
        $helper = $this->helper();
        $result = $helper(
            'gender',
            ['m' => ['label' => 'Male (M)']],
        );

        $rendered = (string) $result;

        $this->assertStringContainsString('>Male (M)</label>', $rendered);
    }

    public function testAutoGeneratesIdFromNameAndValue(): void
    {
        $helper = $this->helper();
        $result = $helper('size', ['lg' => 'Large']);

        $rendered = (string) $result;

        $this->assertStringContainsString('id="size_lg"', $rendered);
        $this->assertStringContainsString('for="size_lg"', $rendered);
    }

    // -----------------------------------------------------------------------
    // Checked state - single scalar
    // -----------------------------------------------------------------------

    public function testMarksCheckedWhenValueMatchesScalar(): void
    {
        $helper = $this->helper();
        $result = $helper(
            'gender',
            ['m' => 'Male', 'f' => 'Female'],
            'm',
        );

        $rendered = (string) $result;
        $lines    = explode(PHP_EOL, $rendered);

        $this->assertStringContainsString('value="m"', $lines[0]);
        $this->assertStringContainsString('checked="checked"', $lines[0]);

        $this->assertStringContainsString('value="f"', $lines[1]);
        $this->assertStringNotContainsString('checked', $lines[1]);
    }

    public function testNullCheckedRendersNoCheckedAttr(): void
    {
        $helper = $this->helper();
        $result = $helper('gender', ['m' => 'Male', 'f' => 'Female']);

        $this->assertStringNotContainsString('checked', (string) $result);
    }

    public function testNonMatchingValueRendersNoCheckedAttr(): void
    {
        $helper = $this->helper();
        $result = $helper('gender', ['m' => 'Male', 'f' => 'Female'], 'x');

        $this->assertStringNotContainsString('checked', (string) $result);
    }

    // -----------------------------------------------------------------------
    // Shared attributes
    // -----------------------------------------------------------------------

    public function testSharedAttributesAppliedToAllInputs(): void
    {
        $helper = $this->helper();
        $result = $helper(
            'gender',
            ['m' => 'Male', 'f' => 'Female'],
            null,
            ['class' => 'radio-btn'],
        );

        $rendered = (string) $result;
        $lines    = explode(PHP_EOL, $rendered);

        foreach ($lines as $line) {
            if (str_contains($line, '<input')) {
                $this->assertStringContainsString('class="radio-btn"', $line);
            }
        }
    }

    // -----------------------------------------------------------------------
    // Per-item attributes
    // -----------------------------------------------------------------------

    public function testPerItemExplicitIdIsRespected(): void
    {
        $helper = $this->helper();
        $result = $helper(
            'size',
            ['lg' => ['label' => 'Large', 'id' => 'size-large']],
        );

        $rendered = (string) $result;

        $this->assertStringContainsString('id="size-large"', $rendered);
        $this->assertStringContainsString('for="size-large"', $rendered);
    }

    public function testDisabledAttributeRendered(): void
    {
        $helper = $this->helper();
        $result = $helper(
            'size',
            ['xs' => ['label' => 'Extra Small', 'disabled' => 'disabled']],
        );

        $this->assertStringContainsString('disabled="disabled"', (string) $result);
    }

    // -----------------------------------------------------------------------
    // State reset between invocations
    // -----------------------------------------------------------------------

    public function testStateIsResetBetweenCasts(): void
    {
        $helper = $this->helper();

        $helper('gender', ['m' => 'Male'], 'm');
        (string) $helper;

        $helper('size', ['sm' => 'Small']);
        $rendered = (string) $helper;

        $this->assertStringContainsString('name="size"', $rendered);
        $this->assertStringNotContainsString('name="gender"', $rendered);
        $this->assertStringNotContainsString('checked', $rendered);
    }

    // -----------------------------------------------------------------------
    // Output structure
    // -----------------------------------------------------------------------

    public function testItemsSeparatedByNewline(): void
    {
        $helper = $this->helper();
        $result = $helper('x', ['a' => 'A', 'b' => 'B', 'c' => 'C']);

        $lines = explode(PHP_EOL, (string) $result);
        $this->assertCount(3, $lines);
    }

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
        $result = $helper('x', ['val' => '<script>alert(1)</script>']);

        $rendered = (string) $result;

        $this->assertStringNotContainsString('<script>', $rendered);
        $this->assertStringContainsString('&lt;script&gt;', $rendered);
    }
}
