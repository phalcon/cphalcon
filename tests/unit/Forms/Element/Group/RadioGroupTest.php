<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Forms\Element\Group;

use Phalcon\Forms\Element\RadioGroup;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class RadioGroupTest extends AbstractUnitTestCase
{
    // -----------------------------------------------------------------------
    // Attributes
    // -----------------------------------------------------------------------

    public function testConstructorAcceptsAttributes(): void
    {
        $element = new RadioGroup('gender', [], ['class' => 'radio-group']);

        $this->assertSame(['class' => 'radio-group'], $element->getAttributes());
    }

    // -----------------------------------------------------------------------
    // Options
    // -----------------------------------------------------------------------

    public function testConstructorAcceptsOptions(): void
    {
        $options = ['m' => 'Male', 'f' => 'Female'];
        $element = new RadioGroup('gender', $options);

        $this->assertSame($options, $element->getOptions());
    }

    // -----------------------------------------------------------------------
    // Constructor - no bracket appending for radio
    // -----------------------------------------------------------------------

    public function testConstructorDoesNotAppendBrackets(): void
    {
        $element = new RadioGroup('gender');

        $this->assertSame('gender', $element->getName());
    }

    public function testRenderChecksDefaultValue(): void
    {
        $element = new RadioGroup('gender', ['m' => 'Male', 'f' => 'Female']);
        $element->setTagFactory($this->factory());
        $element->setDefault('m');

        $rendered = $element->render();
        $lines    = explode(PHP_EOL, $rendered);

        $this->assertStringContainsString('checked="checked"', $lines[0]);
        $this->assertStringNotContainsString('checked', $lines[1]);
    }

    // -----------------------------------------------------------------------
    // Rendering
    // -----------------------------------------------------------------------

    public function testRenderProducesRadioInputs(): void
    {
        $element = new RadioGroup('gender', ['m' => 'Male', 'f' => 'Female']);
        $element->setTagFactory($this->factory());

        $rendered = $element->render();

        $this->assertStringContainsString('type="radio"', $rendered);
        $this->assertStringContainsString('name="gender"', $rendered);
        $this->assertStringContainsString('value="m"', $rendered);
        $this->assertStringContainsString('value="f"', $rendered);
        $this->assertStringContainsString('>Male</label>', $rendered);
        $this->assertStringContainsString('>Female</label>', $rendered);
    }

    public function testRenderWithExtraAttributesMergesCorrectly(): void
    {
        $element = new RadioGroup('gender', ['m' => 'Male']);
        $element->setTagFactory($this->factory());

        $rendered = $element->render(['class' => 'my-radio']);

        $this->assertStringContainsString('class="my-radio"', $rendered);
    }

    public function testRenderWithNoDefaultHasNoChecked(): void
    {
        $element = new RadioGroup('gender', ['m' => 'Male', 'f' => 'Female']);
        $element->setTagFactory($this->factory());

        $this->assertStringNotContainsString('checked', $element->render());
    }

    public function testSetOptionsReplacesOptions(): void
    {
        $element = new RadioGroup('gender', ['m' => 'Male']);
        $element->setOptions(['m' => 'Male', 'f' => 'Female', 'o' => 'Other']);

        $this->assertCount(3, $element->getOptions());
    }

    public function testSetOptionsReturnsElementInterface(): void
    {
        $element = new RadioGroup('gender');
        $result  = $element->setOptions(['m' => 'Male']);

        $this->assertSame($element, $result);
    }

    public function testToStringEqualsRender(): void
    {
        $element = new RadioGroup('gender', ['m' => 'Male']);
        $element->setTagFactory($this->factory());

        $this->assertSame($element->render(), (string) $element);
    }
    private function factory(): TagFactory
    {
        return new TagFactory(new Escaper());
    }
}
