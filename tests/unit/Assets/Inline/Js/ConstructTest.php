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

namespace Phalcon\Tests\Unit\Assets\Inline\Js;

use Phalcon\Assets\Inline\Js;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\Test;

final class ConstructTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsInlineJsConstruct(): void
    {
        $asset = new Js('<script>alert("Hello");</script>');

        $expected = 'js';
        $actual   = $asset->getType();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsInlineJsConstructAttributes(): void
    {
        $asset = new Js('<script>alert("Hello");</script>');

        $expected = [
            'type' => 'application/javascript',
        ];
        $actual   = $asset->getAttributes();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsInlineJsConstructAttributesSet(): void
    {
        $attributes = [
            'data' => 'phalcon',
        ];

        $asset  = new Js(
            '<script>alert("Hello");</script>',
            true,
            $attributes
        );
        $actual = $asset->getAttributes();
        $this->assertSame($attributes, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsInlineJsConstructFilter(): void
    {
        $asset  = new Js('<script>alert("Hello");</script>');
        $actual = $asset->getFilter();
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsInlineJsConstructFilterSet(): void
    {
        $asset  = new Js('<script>alert("Hello");</script>', false);
        $actual = $asset->getFilter();
        $this->assertFalse($actual);
    }
}
