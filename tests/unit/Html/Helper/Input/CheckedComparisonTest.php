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
use Phalcon\Html\Helper\Input\Checkbox;
use Phalcon\Html\Helper\Input\Radio;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

/**
 * Covers loose vs strict matching between the `checked` and `value`
 * attributes for `Checkbox` and `Radio`.
 *
 * Loose is the default and lets mixed int/string form data round-trip
 * (regression coverage for cphalcon issues #16416 and #16374).
 */
final class CheckedComparisonTest extends AbstractUnitTestCase
{
    public static function getLooseMatchExamples(): array
    {
        return [
            // value, checked, should render checked attr
            'int 0 vs string "0"' => [0, '0', true],
            'string "0" vs int 0' => ['0', 0, true],
            'int 1 vs string "1"' => [1, '1', true],
            'string "1" vs int 1' => ['1', 1, true],
            'matching strings'    => ['yes', 'yes', true],
            'mismatched values'   => ['yes', 'no', false],
        ];
    }

    public static function getStrictMatchExamples(): array
    {
        return [
            // value, checked, should render checked attr (strict)
            'int 0 vs string "0" - strict' => [0, '0', false],
            'string "0" vs int 0 - strict' => ['0', 0, false],
            'matching strings - strict'    => ['yes', 'yes', true],
            'matching ints - strict'       => [1, 1, true],
        ];
    }

    public static function getUnconditionalCheckedExamples(): array
    {
        return [
            'literal "checked"'         => ['checked', true],
            'literal "CHECKED"'         => ['CHECKED', true],
            'literal "Checked"'         => ['Checked', true],
            'boolean true'              => [true, true],
            'mismatched non-bool value' => ['nope', false],
        ];
    }

    #[DataProvider('getLooseMatchExamples')]
    public function testCheckboxLooseMatch(
        mixed $value,
        mixed $checked,
        bool $shouldBeChecked
    ): void {
        $helper = new Checkbox(new Escaper(), new Doctype());
        $result = $helper(
            'x',
            null,
            [
                'value'   => $value,
                'checked' => $checked,
            ]
        );

        $rendered = (string) $result;

        if ($shouldBeChecked) {
            $this->assertStringContainsString('checked="checked"', $rendered);
        } else {
            $this->assertStringNotContainsString('checked="checked"', $rendered);
        }
    }

    #[DataProvider('getLooseMatchExamples')]
    public function testRadioLooseMatch(
        mixed $value,
        mixed $checked,
        bool $shouldBeChecked
    ): void {
        $helper = new Radio(new Escaper(), new Doctype());
        $result = $helper(
            'x',
            null,
            [
                'value'   => $value,
                'checked' => $checked,
            ]
        );

        $rendered = (string) $result;

        if ($shouldBeChecked) {
            $this->assertStringContainsString('checked="checked"', $rendered);
        } else {
            $this->assertStringNotContainsString('checked="checked"', $rendered);
        }
    }

    #[DataProvider('getStrictMatchExamples')]
    public function testCheckboxStrictMatch(
        mixed $value,
        mixed $checked,
        bool $shouldBeChecked
    ): void {
        $helper = new Checkbox(new Escaper(), new Doctype());
        $helper->strict();
        $result = $helper(
            'x',
            null,
            [
                'value'   => $value,
                'checked' => $checked,
            ]
        );

        $rendered = (string) $result;

        if ($shouldBeChecked) {
            $this->assertStringContainsString('checked="checked"', $rendered);
        } else {
            $this->assertStringNotContainsString('checked="checked"', $rendered);
        }
    }

    /**
     * `["checked" => "checked"]` (any case) and `["checked" => true]` are
     * unconditional opt-ins - they render `checked="checked"` regardless of
     * what `value` is set to and regardless of strict mode.
     */
    #[DataProvider('getUnconditionalCheckedExamples')]
    public function testCheckboxUnconditionalCheckedAttribute(
        mixed $checked,
        bool $shouldBeChecked
    ): void {
        $helper = new Checkbox(new Escaper(), new Doctype());
        $result = $helper(
            'x',
            '1',
            [
                'checked' => $checked,
            ]
        );

        $rendered = (string) $result;

        if ($shouldBeChecked) {
            $this->assertStringContainsString('checked="checked"', $rendered);
        } else {
            $this->assertStringNotContainsString('checked="checked"', $rendered);
        }
    }

    #[DataProvider('getUnconditionalCheckedExamples')]
    public function testRadioUnconditionalCheckedAttribute(
        mixed $checked,
        bool $shouldBeChecked
    ): void {
        $helper = new Radio(new Escaper(), new Doctype());
        $result = $helper(
            'x',
            '1',
            [
                'checked' => $checked,
            ]
        );

        $rendered = (string) $result;

        if ($shouldBeChecked) {
            $this->assertStringContainsString('checked="checked"', $rendered);
        } else {
            $this->assertStringNotContainsString('checked="checked"', $rendered);
        }
    }

    /**
     * Same opt-ins must hold under `strict(true)`: the unconditional path
     * does not consult `value`.
     */
    #[DataProvider('getUnconditionalCheckedExamples')]
    public function testCheckboxUnconditionalCheckedAttributeUnderStrict(
        mixed $checked,
        bool $shouldBeChecked
    ): void {
        $helper = new Checkbox(new Escaper(), new Doctype());
        $helper->strict();
        $result = $helper(
            'x',
            '1',
            [
                'checked' => $checked,
            ]
        );

        $rendered = (string) $result;

        if ($shouldBeChecked) {
            $this->assertStringContainsString('checked="checked"', $rendered);
        } else {
            $this->assertStringNotContainsString('checked="checked"', $rendered);
        }
    }
}
