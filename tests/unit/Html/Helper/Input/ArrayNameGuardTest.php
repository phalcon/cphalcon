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
use Phalcon\Html\Helper\Input\Generic;
use Phalcon\Html\Helper\Input\Radio;
use Phalcon\Tests\AbstractUnitTestCase;

/**
 * Covers the id-guard added to AbstractInput.__invoke():
 * when the name contains '[', the id attribute must NOT be auto-assigned.
 * An explicit id in the $attributes array must always be respected.
 */
final class ArrayNameGuardTest extends AbstractUnitTestCase
{
    public function testArrayNameSkipsAutoId(): void
    {
        $helper = new Generic(new Escaper(), new Doctype(), 'text');
        $result = $helper('tags[]');

        $rendered = (string) $result;

        $this->assertStringNotContainsString('id=', $rendered);
        $this->assertStringContainsString('name="tags[]"', $rendered);
    }

    public function testArrayNameWithBracketsAndIndexSkipsAutoId(): void
    {
        $helper = new Generic(new Escaper(), new Doctype(), 'checkbox');
        $result = $helper('roles[0]');

        $rendered = (string) $result;

        $this->assertStringNotContainsString('id=', $rendered);
        $this->assertStringContainsString('name="roles[0]"', $rendered);
    }

    public function testExplicitIdIsAlwaysRespected(): void
    {
        $helper = new Generic(new Escaper(), new Doctype(), 'text');
        $result = $helper('tags[]', null, ['id' => 'my-id']);

        $rendered = (string) $result;

        $this->assertStringContainsString('id="my-id"', $rendered);
        $this->assertStringContainsString('name="tags[]"', $rendered);
    }

    public function testPlainNameAutoAssignsId(): void
    {
        $helper = new Generic(new Escaper(), new Doctype(), 'text');
        $result = $helper('username');

        $rendered = (string) $result;

        $this->assertStringContainsString('id="username"', $rendered);
        $this->assertStringContainsString('name="username"', $rendered);
    }

    public function testCheckboxArrayNameSkipsAutoId(): void
    {
        $helper = new Checkbox(new Escaper(), new Doctype());
        $result = $helper('options[]', '1');

        $rendered = (string) $result;

        $this->assertStringNotContainsString('id=', $rendered);
        $this->assertStringContainsString('name="options[]"', $rendered);
        $this->assertStringContainsString('value="1"', $rendered);
    }

    public function testRadioArrayNameSkipsAutoId(): void
    {
        $helper = new Radio(new Escaper(), new Doctype());
        $result = $helper('choice[]', 'a');

        $rendered = (string) $result;

        $this->assertStringNotContainsString('id=', $rendered);
        $this->assertStringContainsString('name="choice[]"', $rendered);
    }

    public function testArrayNameExplicitIdOverridesGuard(): void
    {
        $helper = new Checkbox(new Escaper(), new Doctype());
        $result = $helper('options[]', '1', ['id' => 'opt-1']);

        $rendered = (string) $result;

        $this->assertStringContainsString('id="opt-1"', $rendered);
    }
}
